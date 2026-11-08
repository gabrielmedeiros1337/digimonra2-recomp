"""Capture complete 60-frame timing windows; read-only, no PAD or guest writes."""
import argparse
import json
from pathlib import Path
import re
import statistics
import time


def values(line):
    return {k: float(v) for k, v in re.findall(r"(\w+)=([0-9.]+)", line)}


def collect(lines):
    detail, modes, keys, asynchronous, pipeline, budget, dispatch = {}, {}, {}, {}, {}, {}, {}
    for line in lines:
        if line.startswith("[GX60]"): detail = values(line)
        elif line.startswith("[GX key60]"): keys = values(line)
        elif line.startswith("[Fast modes]"): modes = values(line)
        elif line.startswith("[GX async60]"): asynchronous = values(line)
        elif line.startswith("[GX async reuse60]"): asynchronous.update(values(line))
        elif line.startswith("[GX image60]"): asynchronous.update(values(line))
        elif line.startswith("[Render pipeline60]"): pipeline = values(line)
        elif line.startswith("[Render sync60]"): pipeline.update(values(line))
        elif line.startswith("[Render snapshot60]"): pipeline.update(values(line))
        elif line.startswith("[Guest budget60]"): budget={"guest_"+k:v for k,v in values(line).items()}
        elif line.startswith("[Guest boundary60]"): budget.update({"guest_"+k:v for k,v in values(line).items()})
        elif line.startswith("[Guest dispatch60]"): budget.update({"guest_window_"+k:v for k,v in values(line).items()})
        elif line.startswith("[Dispatch60]"): dispatch={"dispatch_"+k:v for k,v in values(line).items()}
        elif line.startswith("[Frame60]"):
            row = values(line)
            row.update(detail); row.update(keys); row.update(modes); row.update(asynchronous)
            row.update(pipeline)
            row.update(budget)
            row.update(dispatch)
            yield row
            pipeline = {}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--log", type=Path, default=Path("runtime_vram.log"))
    p.add_argument("--output", type=Path, required=True)
    p.add_argument("--windows", type=int, default=16)
    p.add_argument("--existing", action="store_true")
    p.add_argument("--timeout", type=float, default=60)
    p.add_argument("--fast-float", type=int, choices=[0, 1])
    p.add_argument("--dirty-tracking", type=int, choices=[0, 1])
    p.add_argument("--async-mode",type=int,choices=[0,1])
    p.add_argument("--images-mode",type=int,choices=[0,1])
    p.add_argument("--chain-mode",type=int,choices=[0,1])
    p.add_argument("--min-draws",type=float,default=0,help="Minimum mean raw draws/frame across the complete consecutive window")
    p.add_argument("--max-draws",type=float,default=float('inf'))
    a = p.parse_args()
    if not 1 <= a.windows <= 120 or not 1 <= a.timeout <= 300: p.error("Unsupported window count/timeout")
    beginning = a.log.stat().st_size
    deadline = time.monotonic() + a.timeout
    while True:
        # Read only the capture tail. Re-reading a long-running game's entire
        # log every250ms evicts cache and can perturb the very wall time measured.
        with a.log.open("rb") as stream:
            if not a.existing:
                if a.log.stat().st_size<beginning:raise RuntimeError("Runtime log was replaced during capture")
                stream.seek(beginning)
            raw=stream.read()
        text = raw.decode(errors="replace")
        if not a.existing and "[Exit]" in text: raise RuntimeError("Game exited during capture")
        candidates = list(collect(text.splitlines()))
        rows = [r for r in candidates if r.get("scene") == 4
                and (a.fast_float is None or r.get("fast_float") == a.fast_float)
                and (a.dirty_tracking is None or r.get("dirty_tracking") == a.dirty_tracking)
                and (a.async_mode is None or r.get("async_enabled")==a.async_mode)
                and (a.images_mode is None or r.get("immutable_images")==a.images_mode)]
        if a.chain_mode is not None:rows=[r for r in rows if r.get('dispatch_enabled')==a.chain_mode]
        # Drop two transition windows in live mode. Never mix timings from a sampler/build.
        if not a.existing: rows = rows[2:]
        if a.min_draws or a.max_draws!=float('inf'):
            selected=[]
            for end in range(a.windows,len(rows)+1):
                window=rows[end-a.windows:end]
                mean=statistics.mean(r.get('raw_draws_per_frame',0) for r in window)
                if a.min_draws<=mean<=a.max_draws:
                    selected=window
                    if not a.existing:break
            rows=selected
        if len(rows) >= a.windows: break
        if a.existing or time.monotonic() >= deadline:
            raise RuntimeError(f"Need {a.windows} matching combat windows; got {len(rows)}")
        time.sleep(0.25)
    rows = rows[-a.windows:] if a.existing else rows[:a.windows]
    metrics = sorted({k for r in rows for k in r if k.endswith("_ms")})
    summary = {k: dict(mean=statistics.mean(r[k] for r in rows if k in r),
                       min=min(r[k] for r in rows if k in r), max=max(r[k] for r in rows if k in r)) for k in metrics}
    counts = {}
    frames = sum(r["frames"] for r in rows)
    for k in ["decoded_hits", "decoded_misses"]:
        if all(k in r for r in rows): counts[k + "_per_frame"] = sum(r[k] for r in rows) / frames
    completed=sum(r.get('guest_window_completed',0) for r in rows)
    if completed:
        counts['guest_dispatches_per_completed_frame']=sum(r.get('guest_window_dispatches',0) for r in rows)/completed
        counts['guest_peak_dispatches']=max(r.get('guest_window_peak_dispatches',0) for r in rows)
    counts['guest_watchdog_jobs']=sum(r.get('guest_watchdog_jobs',0) for r in rows)
    counts['guest_idle_jumps']=sum(r.get('guest_idle_jumps',0) for r in rows)
    for key in sorted({k for r in rows for k in r if k.startswith('dispatch_') and k!='dispatch_enabled' and 'peak' not in k}):
        counts[key+'_per_frame']=sum(r.get(key,0) for r in rows)/frames
    for key in ('dispatch_direct_stack_peak_bytes','dispatch_direct_depth_peak'):
        if any(key in r for r in rows):counts[key]=max(r.get(key,0) for r in rows)
    result = dict(log=str(a.log), frames=frames, windows=len(rows), summary=summary,
                  counts=counts, requested_modes=dict(fast_float=a.fast_float, dirty_tracking=a.dirty_tracking),
                  reports=rows,min_draws=a.min_draws,max_draws=None if a.max_draws==float('inf') else a.max_draws,note="Exclusive QPC wall times. Draw threshold applies to the entire consecutive window; workload needs physical confirmation; evolution names are not logged.")
    a.output.write_text(json.dumps(result, indent=2))
    print(json.dumps({k: v for k, v in result.items() if k != "reports"}, indent=2))


if __name__ == "__main__": main()
