"""Allowlisted Linux portable package generator. Never copies dumps, saves or build logs."""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tarfile
import zipfile


def package_linux(source: Path, binary: Path, output: Path, make_tar: bool = True) -> dict:
    source, binary, output = source.resolve(), binary.resolve(), output.resolve()
    if output in (source, binary) or output == output.parent:
        raise ValueError("Output must be a separate package directory")
    vendor = source / "third_party/recomp-deps/dolphin"
    external = vendor / "Externals"

    game_binary = binary / "digimon_test"
    with game_binary.open("rb") as stream:
        header = stream.read(20)
    if len(header) != 20 or header[:6] != b"\x7fELF\x02\x01" or header[18:20] != b"\x3e\x00":
        raise ValueError("Linux release requires a native x86-64 ELF binary")

    dsp_coef = binary / "dsp_coef.bin"
    if not dsp_coef.is_file():
        dsp_coef = vendor / "Data/Sys/GC/dsp_coef.bin"

    files = {
        "digimon_test": game_binary,
        "DigimonRA2": source / "distribution/DigimonRA2",
        "tools/linux_launcher.py": source / "tools/linux_launcher.py",
        "dsp_coef.bin": dsp_coef,
        "README.pt-BR.txt": source / "distribution/README.pt-BR.txt",
        "LICENSE": source / "LICENSE",
        "config/launcher_config.json": source / "distribution/config/launcher_config.json",
        "config/runtime_tuning.cfg": source / "distribution/config/runtime_tuning.cfg",
        "config/dispatch_chain.cfg": source / "distribution/config/dispatch_chain.cfg",
        "LICENSES/SDL2.txt": source / "third_party/SDL2/LICENSE.txt",
        "LICENSES/DolRecomp.txt": source / "third_party/recomp-deps/DolRecomp/LICENSE",
        "LICENSES/Dolphin.txt": vendor / "COPYING",
        "LICENSES/picojson.txt": external / "picojson/LICENSE",
        "LICENSES/bzip2.txt": external / "bzip2/bzip2/LICENSE",
        "LICENSES/liblzma.txt": external / "liblzma/COPYING",
        "LICENSES/Zstandard.txt": external / "zstd/zstd/LICENSE",
    }

    for name, path in files.items():
        if not path.is_file():
            raise FileNotFoundError(f"Missing required artifact: {name}: {path}")

    if output.exists() and not (output / "build_manifest.json").is_file():
        raise ValueError("Refusing to replace an unknown directory")

    output.mkdir(parents=True, exist_ok=True)
    hashes = {}
    for relative, path in files.items():
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        if not (relative.startswith("config/") and target.exists()):
            temporary = target.with_name(target.name + ".packaging")
            shutil.copy2(path, temporary)
            temporary.replace(target)
        if relative in ("digimon_test", "DigimonRA2"):
            try:
                target.chmod(0o755)
            except Exception:
                pass
        hashes[relative] = hashlib.sha256(target.read_bytes()).hexdigest()

    (output / "games").mkdir(exist_ok=True)
    (output / "games/.keep").touch(exist_ok=True)
    (output / "saves").mkdir(exist_ok=True)
    (output / "saves/.keep").touch(exist_ok=True)

    notices = """Third-party components (Linux x86_64 build)
SDL2: zlib license. picojson: BSD-2-Clause. bzip2: bzip2 license.
liblzma library: public domain (see upstream licensing summary).
Zstandard: BSD license, chosen from its dual license.
DolRecomp and Dolphin-derived code/docs retain their upstream licenses.
Freely generated DSP coefficients: pinned Dolphin Data/Sys/GC/dsp_coef.bin.
See LICENSES/ for the complete bundled license texts.
Project source: https://github.com/gabrielmedeiros1337/digimonra2-recomp
No disc dump, DOL, extracted game assets, music or user save is included.
Ubuntu 22.04 prerequisites: libsdl2-2.0-0, libgl1, libssl3, python3-tk.
"""
    (output / "THIRD_PARTY_NOTICES.txt").write_text(notices, encoding="utf-8")

    try:
        commit = subprocess.run(["git", "rev-parse", "HEAD"], cwd=source, capture_output=True, text=True, check=True).stdout.strip()
        dirty = bool(subprocess.run(["git", "status", "--porcelain", "--untracked-files=normal"], cwd=source, capture_output=True, text=True, check=True).stdout)
    except Exception:
        commit = "v1.0-stable-60fps"
        dirty = False

    manifest = {
        "platform": "linux-x86_64",
        "base_tag": "v1.0-stable-60fps",
        "source_commit": commit,
        "working_tree_modified": dirty,
        "files_sha256": hashes,
        "format": 1
    }
    (output / "build_manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")

    # Archive only the files supplied by this build. Use distribution config
    # defaults even when repackaging an installation with local settings.
    archive_files = {name: files[name] if name.startswith("config/") else output / name
                     for name in files}
    for name in ("saves/.keep", "games/.keep", "build_manifest.json", "THIRD_PARTY_NOTICES.txt"):
        archive_files[name] = output / name
    archive_manifest = dict(manifest, files_sha256={
        name: hashlib.sha256(archive_files[name].read_bytes()).hexdigest() for name in files
    })
    manifest_bytes = (json.dumps(archive_manifest, indent=2) + "\n").encode()
    manifest_name = "DigimonRA2_PC_Linux/build_manifest.json"
    zip_path = output.parent / "DigimonRA2_PC_Linux_x64.zip"
    with zipfile.ZipFile(zip_path, "w", compression=zipfile.ZIP_DEFLATED, compresslevel=6) as archive:
        for name, path in sorted(archive_files.items()):
            if name != "build_manifest.json":
                archive.write(path, "DigimonRA2_PC_Linux/" + name)
        archive.writestr(manifest_name, manifest_bytes)
    print(f"ZIP created: {zip_path} ({zip_path.stat().st_size} bytes)")
    if make_tar:
        from io import BytesIO
        tar_path = output.parent / "DigimonRA2_PC_Linux_x64.tar.gz"
        with tarfile.open(tar_path, "w:gz") as archive:
            for name, path in sorted(archive_files.items()):
                if name != "build_manifest.json":
                    archive.add(path, arcname="DigimonRA2_PC_Linux/" + name, recursive=False)
            info = tarfile.TarInfo(manifest_name)
            info.size = len(manifest_bytes)
            info.mode = 0o644
            archive.addfile(info, BytesIO(manifest_bytes))
        print(f"Tarball created: {tar_path} ({tar_path.stat().st_size} bytes)")

    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--binary-dir", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--no-tar", action="store_true", default=False)
    args = parser.parse_args()
    result = package_linux(args.source, args.binary_dir, args.output, make_tar=not args.no_tar)
    print("Linux packaging complete.")


if __name__ == "__main__":
    main()
