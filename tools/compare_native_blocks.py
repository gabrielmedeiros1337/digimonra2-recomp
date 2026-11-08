"""Compare one supported host CPU/GX setting in a live fight, restoring its file."""
import argparse
import json
from pathlib import Path
import statistics
import time
from compare_native_ram import rows
from capture_frame_cost import enrich


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--feature", choices=("blocks", "completion", "pump", "quantum", "domain", "m44", "attrs", "workers", "fbits", "gpu_xf", "vram_only", "geometry_cache"), default="blocks")
    p.add_argument("--log", type=Path, required=True)
    p.add_argument("--config", type=Path, default=Path("build_test/runtime_tuning.cfg"))
    p.add_argument("--seconds", type=float, default=5)
    p.add_argument("--rounds", type=int, default=2)
    p.add_argument("--output", type=Path, default=Path("build_test/native_blocks_comparison.json"))
    args = p.parse_args()
    if not 2 <= args.seconds <= 10 or not 1 <= args.rounds <= 3:
        p.error("Use 2..10 seconds and 1..3 rounds")
    field = {"blocks": 5, "completion": 6, "pump": 7, "quantum": 0, "domain": 8, "m44": 9, "attrs": 10, "workers": 1, "fbits": 11, "gpu_xf": 12, "vram_only": 13, "geometry_cache": 14}[args.feature]
    key = {"blocks": "blocks_enabled", "completion": "completion_enabled", "pump": "pump_enabled", "quantum": "quantum", "domain": "domain_enabled", "m44": "mtx44_enabled", "attrs": "attrs_enabled", "workers": "workers_enabled", "fbits": "fbits_enabled", "gpu_xf": "gpu_xf_observed", "vram_only": "vram_only_enabled", "geometry_cache": "geometry_cache_enabled"}[args.feature]
    text = args.log.read_text(errors="replace")
    initial = enrich(rows(text)) if args.feature in ("workers", "gpu_xf") else rows(text)
    if (not initial or initial[-1]["scene"] != 4 or key not in initial[-1]
            or time.time() - args.log.stat().st_mtime > 5
            or text.rfind("[Exit]") > text.rfind("[Runtime Stats]")):
        raise RuntimeError("A live build with block-entry logging must be in combat")
    original = args.config.read_bytes()
    fields = original.decode().split()
    defaults = ["1024", "1", "1", "1", "0", "1", "0", "0", "1", "1", "1", "0", "1", "1", "1"]
    while len(fields) < 15:
        fields.append(defaults[len(fields)])
    values = list(map(int, fields[:15]))
    if not 64 <= values[0] <= 4096 or any(v not in (0, 1) for v in values[1:]):
        raise ValueError("Unsupported host config")
    captures = []
    try:
        for enabled in [0, 1, 1, 0] * args.rounds:
            selected = (4096 if enabled else 1024) if args.feature == "quantum" else enabled
            fields[field] = str(selected)
            args.config.write_text(" ".join(fields) + "\n", encoding="utf-8")
            time.sleep(2.2)
            prior = rows(args.log.read_text(errors="replace"))[-1]
            start = args.log.stat().st_size
            time.sleep(args.seconds)
            text = args.log.read_bytes()[start:].decode(errors="replace")
            samples = [r for r in enrich([prior] + rows(text)) if r["scene"] == 4 and r.get(key) == selected]
            for row in samples:
                row["estimated_cpu_ms"] = row["total_ms"] - row["render_ms"] - row["copy_ms"] - row["vertices_ms"]
            complete = len(samples) >= max(1, int(args.seconds) - 1) and "[Exit]" not in text
            captures.append(dict(enabled=enabled, samples=samples, complete=complete))
            print(json.dumps(dict(enabled=enabled, samples=len(samples), complete=complete,
                fps_median=statistics.median(r["fps"] for r in samples) if samples else None)), flush=True)
            if not complete:
                break
    finally:
        args.config.write_bytes(original)
    summary = {}
    for enabled in (0, 1):
        data = [r for c in captures if c["enabled"] == enabled and c["complete"] for r in c["samples"]]
        result = summary[str(enabled)] = dict(samples=len(data))
        for key in ("fps", "total_ms", "vertices_ms", "render_ms", "copy_ms", "dispatches", "estimated_cpu_ns_per_dispatch", "estimated_cpu_ms", "pump_ms", "pump_calls", "blend_per_frame", "transform_per_frame", "accumulate_per_frame", "envmap_per_frame", "perop_per_frame", "block_entries_per_frame", "mtx44_per_frame", "parallel_batches_per_frame", "gpu_xf_per_frame", "driver_draws_per_frame", "driver_geometry_hashes_per_frame", "driver_dynamic_streams_per_frame", "driver_vram_only_copies_per_frame", "driver_vram_materializations_per_frame", "texture_readbacks_per_frame"):
            values = [r[key] for r in data if key in r]
            if values:
                result[key] = dict(median=statistics.median(values), mean=statistics.mean(values))
    args.output.write_text(json.dumps(dict(feature=args.feature, summary=summary, captures=captures,
        complete=len(captures) == args.rounds * 4 and all(c["complete"] for c in captures),
        note="Same live fight with variable load; normalized CPU cost is an estimate. No input or guest writes."), indent=2))
    print(json.dumps(summary), flush=True)


if __name__ == "__main__":
    main()
