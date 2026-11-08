"""Read-only per-frame costs for a user-controlled workload; no input/guest writes."""
import argparse
import json
from pathlib import Path
import statistics
import time
from compare_native_ram import rows


def enrich(data):
    result = []
    previous = None
    for item in data:
        row = item.copy()
        if row.get("scene") == 4 and previous and previous.get("scene") == 4:
            frames = row.get("vbl", 0) - previous.get("vbl", 0)
            if frames > 0:
                for key in ("draws", "fifo_kib") + tuple(k for k in row if k.startswith("counter_")):
                    if key in row and key in previous and row[key] >= previous[key]:
                        row[key.removeprefix("counter_") + "_per_frame"] = (row[key] - previous[key]) / frames
                if "gpu_xf_per_frame" in row:
                    row["gpu_xf_observed"] = int(row["gpu_xf_per_frame"] > 0)
                if "parallel_batches_per_frame" in row:
                    row["workers_enabled"] = int(row["parallel_batches_per_frame"] > 0)
                row["estimated_cpu_ms"] = row["total_ms"] - row["vertices_ms"] - row["render_ms"] - row["copy_ms"]
                result.append(row)
        previous = item
    return result


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--log", type=Path, required=True)
    p.add_argument("--label", default="unclassified")
    p.add_argument("--seconds", type=float, default=15, help="0 analyzes the existing log")
    p.add_argument("--output", type=Path, required=True)
    args = p.parse_args()
    if not 0 <= args.seconds <= 45:
        p.error("Use 0..45 seconds")
    before = args.log.read_text(errors="replace")
    if args.seconds:
        last = rows(before)
        if not last or last[-1]["scene"] != 4 or time.time() - args.log.stat().st_mtime > 5:
            raise RuntimeError("Live combat log required")
        start = args.log.stat().st_size
        time.sleep(args.seconds)
        raw = args.log.read_bytes()[start:].decode(errors="replace")
        data = [last[-1]] + rows(raw)
    else:
        raw = before
        data = rows(before)
    samples = enrich(data)
    keys = ["fps", "total_ms", "estimated_cpu_ms", "vertices_ms", "render_ms", "copy_ms",
        "dispatches", "pump_ms", "pump_calls", "draws_per_frame", "fifo_kib_per_frame", "accumulate_per_frame", "envmap_per_frame",
        "transform_per_frame", "blend_per_frame", "block_entries_per_frame", "perop_per_frame", "mtx44_per_frame", "parallel_batches_per_frame", "gpu_xf_per_frame", "driver_draws_per_frame", "driver_stream_bytes_per_frame", "driver_orphans_per_frame",
        "driver_shader_compiles_per_frame", "driver_uniform_queries_per_frame", "driver_vram_copies_per_frame", "driver_geometry_hits_per_frame",
        "driver_geometry_uploads_per_frame", "driver_xf_uniform_blocks_per_frame", "texture_uploads_per_frame", "texture_hash_bytes_per_frame", "texture_readbacks_per_frame", "driver_merged_packets_per_frame", "driver_geometry_hashes_per_frame", "driver_dynamic_streams_per_frame", "driver_vram_only_copies_per_frame", "driver_vram_materializations_per_frame", "dvd_pending", "vram_pending"]
    summary = {}
    for key in keys:
        values = [r[key] for r in samples if key in r]
        if values:
            summary[key] = dict(median=statistics.median(values), min=min(values), max=max(values))
    result = dict(label=args.label, samples=samples, summary=summary,
        physical_button_events=raw.count("[INPUT] Botao pressionado!"),
        note="Skinning counts are operations, not unique models. Workload labels require user confirmation. GPU timers nested; CPU residual is estimated.")
    args.output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(dict(label=args.label, samples=len(samples), summary=summary)))


if __name__ == "__main__":
    main()
