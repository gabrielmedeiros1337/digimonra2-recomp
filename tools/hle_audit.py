#!/usr/bin/env python3
"""Read-only audit of every generated chunk and the HLE boundary.
Run from the repository root: python tools/hle_audit.py
"""
from collections import Counter
from pathlib import Path
import json
import re

ROOT = Path(__file__).resolve().parents[1]
RANGES = {
    "sdk_fpu_load": (0x802BFCD8, 0x802BFDFC),
    "sdk_fpu_save": (0x802BFDFC, 0x802BFF24),
    "sdk_load_context": (0x802C001C, 0x802C00F4),
    "lua_reference": (0x80256B08, 0x80256C20),
    "lua_throw": (0x8026270C, 0x80262750),
    "lua_field_wrapper": (0x801D012C, 0x801D01C0),
    "title_update": (0x8015ED34, 0x8015EF9C),
    "title_readiness": (0x8015EF9C, 0x8015F060),
    "animation_busy": (0x80143B78, 0x80143C40),
    "audio_voice_playing": (0x8021B210, 0x8021B280),
    "scene_update": (0x801AC614, 0x801ACB04),
    "scene_load_predicate": (0x801B1510, 0x801B1594),
    "engine_gpu_completion": (0x80248B60, 0x80248B7C),
    "engine_gpu_wait": (0x80248E84, 0x80248EA0),
    "dvd_file_callback": (0x802B6C5C, 0x802B6C8C),
    "dvd_read_abs": (0x802B92B0, 0x802B938C),
    "gx_finish": (0x802CEFB8, 0x802CF11C),
    "gx_finish_interrupt": (0x802CF444, 0x802CF4C8),
    "gx_copy_display": (0x802D06BC, 0x802D0818),
    "vi_interrupt": (0x802DCED8, 0x802DD108),
}

def main():
    counts = Counter()
    calls = Counter()
    assembly = {name: [] for name in RANGES}
    for path in sorted((ROOT / "recompiled_code/generated/chunks").glob("*.c")):
        source = path.read_text(encoding="utf-8")
        counts["chunks"] += 1
        counts["lines"] += source.count("\n")
        counts.update(re.findall(r"\bmem_(?:read|write)\d+", source))
        for match in re.finditer(r"^    // ([0-9A-F]{8}): (.*)", source, re.M):
            address = int(match[1], 16)
            instruction = match[2]
            if instruction.startswith("bl "):
                target = re.search(r"0x([0-9A-F]{8})", instruction)
                if target:
                    calls[target[1]] += 1
            for name, (start, end) in RANGES.items():
                if start <= address < end:
                    assembly[name].append({"pc": match[1], "instruction": instruction,
                                           "file": path.name})
    for name, entries in assembly.items():
        assembly[name] = sorted({item["pc"]: item for item in entries}.values(), key=lambda x: x["pc"])
    output = ROOT / "build_test/hle_audit.json"
    output.parent.mkdir(exist_ok=True)
    output.write_text(json.dumps({"counts": dict(counts), "direct_call_targets": dict(sorted(calls.items())),
                                  "assembly": assembly}, indent=2), encoding="utf-8")
    print(json.dumps(dict(counts), indent=2))
    print(f"Direct call targets: {len(calls)}; report: {output}")

if __name__ == "__main__":
    main()
