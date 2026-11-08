"""Compare the host RAM adapter in one live fight; never sends input/guest writes."""
import argparse
import json
from pathlib import Path
import re
import statistics
import time


def rows(text):
    current = {}
    result = []
    for line in text.splitlines():
        m = re.search(r"\[Timing\] CPU\+GX=([\d.]+).*render=([\d.]+).*YUY2=([\d.]+)", line)
        if m:
            current = dict(zip(("total_ms", "render_ms", "copy_ms"), map(float, m.groups())))
        host = re.search(r"\[Host input\] pump=([\d.]+).*calls=([\d.]+)", line)
        if host:
            current["pump_ms"], current["pump_calls"] = map(float, host.groups())
        m = re.search(r"\[GX cost\] vertices=([\d.]+)", line)
        if m:
            current["vertices_ms"] = float(m[1])
        parallel = re.search(r"parallel batches=(\d+)", line)
        if parallel:
            current["counter_parallel_batches"] = int(parallel[1])
        if "[GL driver]" in line:
            for name,value in re.findall(r"(\w+)=(\d+)",line):
                current[name.lower() if name.endswith("_pending") else "counter_driver_"+name]=int(value)
        if "[Texture cache]" in line:
            for name,value in re.findall(r"(hits|hash_bytes|uploads|EFB_readbacks)=(\d+)",line):
                current["counter_texture_"+("readbacks" if name=="EFB_readbacks" else name)]=int(value)
        m = re.search(r"active dispatches=(\d+)/frame", line)
        if m:
            current["dispatches"] = int(m[1])
        quantum = re.search(r"\[Progress\].*quantum=(\d+)", line)
        if quantum:
            current["quantum"] = int(quantum[1])
        if "[Skinning]" in line:
            perop = re.search(r"native loop vertices=(\d+)", line)
            if perop:
                current["counter_perop"] = int(perop[1])
            for name, value in re.findall(r"(accumulate|envmap|transform|blend|block_entries)=(\d+)", line):
                current["counter_" + name] = int(value)
        if "[Runtime Stats]" in line:
            for pattern, key, cast in ((r"VBL: (\d+)", "vbl", int),
                    (r"GX: ([\d.]+) KB", "fifo_kib", float),
                    (r"\((\d+) draws\)", "draws", int)):
                extra = re.search(pattern, line)
                if extra:
                    current[key] = cast(extra[1])
        m = re.search(r"\[Native RAM\] inline=(\d)", line)
        if m:
            current["enabled"] = int(m[1])
        block = re.search(r"\[Native RAM\].*blocks=(\d)", line)
        if block:
            current["blocks_enabled"] = int(block[1])
        completion = re.search(r"\[Native RAM\].*completion=(\d)", line)
        if completion:
            current["completion_enabled"] = int(completion[1])
        pump = re.search(r"\[Native RAM\].*pump=(\d)", line)
        if pump:
            current["pump_enabled"] = int(pump[1])
        domain = re.search(r"\[Native RAM\].*domain=(\d)", line)
        if domain:
            current["domain_enabled"] = int(domain[1])
        matrix = re.search(r"\[Native RAM\].*m44=(\d)", line)
        if matrix:
            current["mtx44_enabled"] = int(matrix[1])
        for name in ("vram_only","geometry_cache"):
            feature = re.search(r"\[Native RAM\].*"+name+r"=(\d)",line)
            if feature:current[name+"_enabled"]=int(feature[1])
        gpu_xf = re.search(r"\[Native RAM\].*gpu_xf=(\d)", line)
        if gpu_xf:
            current["gpu_xf_enabled"] = int(gpu_xf[1])
        gpu_batches = re.search(r"gpu_xf_batches=(\d+)", line)
        if gpu_batches:
            current["counter_gpu_xf"] = int(gpu_batches[1])
        fbits = re.search(r"\[Native RAM\].*fbits=(\d)", line)
        if fbits:
            current["fbits_enabled"] = int(fbits[1])
        attrs = re.search(r"\[Native RAM\].*attrs=(\d)", line)
        if attrs:
            current["attrs_enabled"] = int(attrs[1])
        matrix = re.search(r"\[SDK matrices\] concat44=(\d+)", line)
        if matrix:
            current["counter_mtx44"] = int(matrix[1])
        m = re.search(r"\[Runtime Stats\] ([\d.]+) FPS", line)
        if m:
            current["fps"] = float(m[1])
        m = re.search(r"\[FIFO regs\].*scene=(\d+)", line)
        required = {"total_ms", "render_ms", "copy_ms", "vertices_ms", "dispatches", "enabled", "fps"}
        if m and required <= current.keys():
            current["scene"] = int(m[1])
            if current["dispatches"]:
                current["estimated_cpu_ns_per_dispatch"] = 1e6 * (
                    current["total_ms"] - current["render_ms"] - current["copy_ms"] - current["vertices_ms"]
                ) / current["dispatches"]
            result.append(current.copy())
            current = {}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--log", type=Path, required=True)
    parser.add_argument("--config", type=Path, default=Path("build_test/runtime_tuning.cfg"))
    parser.add_argument("--seconds", type=float, default=5)
    parser.add_argument("--rounds", type=int, default=2)
    parser.add_argument("--output", type=Path, default=Path("build_test/native_ram_comparison.json"))
    args = parser.parse_args()
    if not 2 <= args.seconds <= 15 or not 1 <= args.rounds <= 4:
        parser.error("Use 2..15 seconds and 1..4 rounds")
    initial = args.log.read_text(encoding="utf-8", errors="replace")
    existing = rows(initial)
    if not existing or existing[-1]["scene"] != 4:
        raise RuntimeError("A build with [Native RAM] must already be in combat (scene=4)")
    original = args.config.read_bytes()
    fields = original.decode().split()
    while len(fields) < 4:
        fields.append("1")
    values = list(map(int, fields[:4]))
    if not 64 <= values[0] <= 4096 or any(v not in (0, 1) for v in values[1:]):
        raise ValueError("Unsupported original host configuration")
    captures = []
    try:
        for enabled in [0, 1, 1, 0] * args.rounds:
            args.config.write_text(" ".join(fields[:4] + [str(enabled)] + fields[5:]) + "\n", encoding="utf-8")
            time.sleep(2.2)  # Allow the once-per-second host setting/report to settle.
            start = args.log.stat().st_size
            time.sleep(args.seconds)
            raw = args.log.read_bytes()[start:].decode("utf-8", errors="replace")
            samples = [r for r in rows(raw) if r["enabled"] == enabled and r["scene"] == 4]
            captures.append({"enabled": enabled, "samples": samples})
            print(json.dumps({"enabled": enabled, "samples": len(samples),
                "fps_median": statistics.median(r["fps"] for r in samples) if samples else None}), flush=True)
    finally:
        args.config.write_bytes(original)
    summary = {}
    for enabled in (0, 1):
        samples = [r for c in captures if c["enabled"] == enabled for r in c["samples"]]
        summary[str(enabled)] = {"samples": len(samples)}
        for key in ("fps", "total_ms", "vertices_ms", "render_ms", "copy_ms", "estimated_cpu_ns_per_dispatch"):
            data = [r[key] for r in samples if key in r]
            if data:
                summary[str(enabled)][key] = {"median": statistics.median(data), "mean": statistics.mean(data)}
    args.output.write_text(json.dumps({"summary": summary, "captures": captures,
        "note": "GPU timers are nested in total; normalized CPU cost is an estimate, not a cycle counter."}, indent=2), encoding="utf-8")
    print(json.dumps(summary), flush=True)


if __name__ == "__main__":
    main()
