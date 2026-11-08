"""Verify the exact validated runtime/codec snapshot before building a clean clone."""
import hashlib
import json
from pathlib import Path

root = Path(__file__).resolve().parents[1] / "third_party/recomp-deps"
manifest = json.loads((root / "dependency_manifest.json").read_text(encoding="utf-8"))
failures = []
for name, expected in manifest["files"].items():
    path = root / name
    if not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != expected:
        failures.append(name)
if failures:
    raise SystemExit("Dependency snapshot mismatch:\n" + "\n".join(failures))
print(f"Verified {len(manifest['files'])} runtime/codec files against the validated snapshot.")
