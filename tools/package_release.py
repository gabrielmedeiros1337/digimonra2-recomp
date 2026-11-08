"""Allowlisted portable package. Never copies dumps, user saves or build diagnostics."""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess


def package(source: Path, binary: Path, output: Path) -> dict:
    source, binary, output = source.resolve(), binary.resolve(), output.resolve()
    if output in (source, binary) or output == output.parent:
        raise ValueError("Output must be a separate package directory")
    vendor = source / "third_party/recomp-deps/dolphin"
    external = vendor / "Externals"
    files = {
        "DigimonRA2.exe": binary / "DigimonRA2.exe",
        "digimon_test.exe": binary / "digimon_test.exe",
        "SDL2.dll": binary / "SDL2.dll",
        "dsp_coef.bin": binary / "dsp_coef.bin",
        "README.pt-BR.txt": source / "distribution/README.pt-BR.txt",
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
    if output.exists():
        if not (output / "build_manifest.json").is_file():
            raise ValueError("Refusing to replace an unknown directory")
        permitted = set(files) | {"build_manifest.json", "THIRD_PARTY_NOTICES.txt", "saves/.keep"}
        for path in output.rglob("*"):
            relative = path.relative_to(output).as_posix()
            if path.is_symlink():
                raise ValueError(f"Symlink in destination: {relative}")
            if path.is_file() and relative not in permitted and not relative.startswith(("saves/", "config/")):
                raise ValueError(f"Unexpected file in package: {relative}")
    output.mkdir(parents=True, exist_ok=True)
    hashes = {}
    for relative, path in files.items():
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        # Repackaging preserves the user's path, bindings, tuning and saves.
        if not (relative.startswith("config/") and target.exists()):
            temporary = target.with_name(target.name + ".packaging")
            shutil.copy2(path, temporary)
            temporary.replace(target)
        hashes[relative] = hashlib.sha256(target.read_bytes()).hexdigest()
    (output / "saves").mkdir(exist_ok=True)
    (output / "saves/.keep").touch(exist_ok=True)
    notices = """Third-party components
SDL2: zlib license. picojson: BSD-2-Clause. bzip2: bzip2 license.
liblzma library: public domain (see upstream licensing summary).
Zstandard: BSD license, chosen from its dual license.
DolRecomp and Dolphin-derived code/docs retain their upstream licenses.
Freely generated DSP coefficients: pinned Dolphin Data/Sys/GC/dsp_coef.bin.
See LICENSES/ for the complete bundled license texts.
Project source: https://github.com/gabrielmedeiros1337/digimonra2-recomp
No disc dump, DOL, extracted game assets, music or user save is included.
Launcher credit illustration: Agumon image supplied by the user, embedded in the launcher.
Microsoft Visual C++ x64 Redistributable is a prerequisite, not bundled.
"""
    (output / "THIRD_PARTY_NOTICES.txt").write_text(notices, encoding="utf-8")
    commit = subprocess.run(["git", "rev-parse", "HEAD"], cwd=source, capture_output=True, text=True, check=True).stdout.strip()
    dirty = bool(subprocess.run(["git", "status", "--porcelain", "--untracked-files=normal"], cwd=source, capture_output=True, text=True, check=True).stdout)
    manifest = {"base_tag": "v1.0-stable-60fps", "source_commit": commit, "working_tree_modified": dirty, "files_sha256": hashes, "format": 1}
    (output / "build_manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--binary-dir", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = package(args.source, args.binary_dir, args.output)
    print(f"Portable package: {args.output.resolve()} ({len(result['files_sha256'])} catalogued files)")


if __name__ == "__main__":
    main()
