"""Four fixed-config live-fight captures. Host config only; no button injection."""
import json
from pathlib import Path
import re
import subprocess
import sys
import time

config = Path("build_test/runtime_tuning.cfg")
log = Path("runtime_vram.log")
text = log.read_text(errors="replace")
frames = [line for line in text.splitlines() if line.startswith("[Frame60]")]
if not frames or "scene=4" not in frames[-1] or time.time()-log.stat().st_mtime > 5 or text.rfind("[Exit]") > text.rfind("[Frame60]"):
    raise RuntimeError("Live combat required; confirm the four-player/evolved workload physically first")
original = config.read_bytes()
fields = original.decode().split()
if len(fields) < 19 or fields[:17] != "1024 1 1 1 0 1 0 1 1 1 1 0 1 1 1 1 1".split():
    raise RuntimeError("Unexpected base config; inspect before comparing")
results = []
try:
    for fast, dirty in [(0,0), (0,1), (1,0), (1,1)]:
        fields[17:19] = [str(fast), str(dirty)]
        config.write_text(" ".join(fields)+"\n")
        output = Path(f"build_test/float_dirty_{fast}{dirty}_960.json")
        print(f"Capturing fast_float={fast} dirty_tracking={dirty}", flush=True)
        subprocess.run([sys.executable, "tools/capture_frame60.py", "--log", str(log),
                        "--windows", "16", "--fast-float", str(fast), "--dirty-tracking", str(dirty),
                        "--timeout", "90", "--output", str(output)], check=True)
        result = json.loads(output.read_text())
        result["file"] = str(output); results.append(result)
finally:
    config.write_bytes(original)
    Path("build_test/float_dirty_comparison.json").write_text(json.dumps(dict(
        complete=len(results)==4, captures=results,
        note="Same user-confirmed live fight; variable animation/effects can change load. Two warmup windows discarded per mode. Original host config restored; no input/guest writes."), indent=2))
