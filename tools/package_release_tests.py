"""Packaging contracts: allowlist, no dump leakage, preserve portable user state."""
import importlib.util
import json
from pathlib import Path
import tempfile
from unittest.mock import patch
from types import SimpleNamespace

root = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("package_release", root / "tools/package_release.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
required = [
    "distribution/README.pt-BR.txt", "distribution/config/launcher_config.json",
    "distribution/config/runtime_tuning.cfg", "distribution/config/dispatch_chain.cfg",
    "third_party/SDL2/LICENSE.txt", "ModernGekko-Template/lib/DolRecomp/LICENSE",
    "ModernGekko-Template/lib/ModernGekko/vendor/dolphin/COPYING",
]
external = "ModernGekko-Template/lib/ModernGekko/vendor/dolphin/Externals/"
required += [external + p for p in ("picojson/LICENSE", "bzip2/bzip2/LICENSE", "liblzma/COPYING", "zstd/zstd/LICENSE")]
scratch_root = (root / "build_test").resolve()
with tempfile.TemporaryDirectory(prefix="package_contract_", dir=scratch_root) as temporary:
    temp = Path(temporary).resolve()
    assert temp.is_relative_to(scratch_root)
    source, binaries, output = temp / "source", temp / "binaries", temp / "portable"
    for name in required:
        p = source / name
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text("license or default fixture", encoding="utf-8")
    binaries.mkdir()
    for name in ("DigimonRA2.exe", "digimon_test.exe", "SDL2.dll", "dsp_coef.bin", "secret.iso", "main.dol", "large.log", "digimon_test.map", "digimon_test.pdb"):
        (binaries / name).write_bytes(b"fixture")
    def git(arguments, **kwargs):
        return SimpleNamespace(stdout="a" * 40 + "\n" if arguments[1] == "rev-parse" else "", returncode=0)
    with patch.object(module.subprocess, "run", side_effect=git):
        manifest = module.package(source, binaries, output)
        assert len(manifest["files_sha256"]) == 15
        assert not any(p.suffix in (".iso", ".dol", ".map", ".pdb", ".log") for p in output.rglob("*"))
        (output / "saves/MemoryCardA.card").write_bytes(b"user progress")
        (output / "config/launcher_config.json").write_text('{"user":"settings"}')
        module.package(source, binaries, output)
        assert (output / "saves/MemoryCardA.card").read_bytes() == b"user progress"
        assert json.loads((output / "config/launcher_config.json").read_text()) == {"user": "settings"}
        (output / "unexpected.map").write_text("developer data")
        try:
            module.package(source, binaries, output)
        except ValueError:
            pass
        else:
            raise AssertionError("Unexpected developer artifact accepted")
print("PASS: clean allowlist and preservation of existing portable saves/config")
