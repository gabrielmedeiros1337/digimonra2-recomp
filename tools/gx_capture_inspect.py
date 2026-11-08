"""Inspect host-only GX frame recordings without executing the guest or injecting input."""
import argparse
import json
import math
import struct
from pathlib import Path


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("capture", type=Path)
    parser.add_argument("--output", type=Path, default=Path("build_test/gx_capture_audit.json"))
    parser.add_argument("--min-count", type=int, default=100)
    args = parser.parse_args()
    data = args.capture.read_bytes()
    magic, vertex_size, draw_size, ram_size = struct.unpack_from("<4I", data)
    if magic != 0x47584331 or vertex_size not in (140, 156, 168) or draw_size not in (1124, 3224) or ram_size != 0x1800000:
        raise SystemExit("Unsupported capture layout")
    at = 16 + ram_size + 640 * 528 * 4
    report = {"capture": str(args.capture), "vertex_size": vertex_size, "draw_size": draw_size, "draws": []}
    batch = 0
    while at + 8 <= len(data):
        draws, vertices = struct.unpack_from("<2I", data, at)
        at += 8
        if not draws:
            if not vertices:
                break
            if vertices != 1:
                raise SystemExit("Unknown capture event")
            event = struct.unpack_from("<10I", data, at)
            at += 40 + event[1]
            continue
        batch += 1
        at += 512 * 1024
        draw_at = at
        at += draws * draw_size
        vertex_at = at
        at += vertices * vertex_size
        if at > len(data):
            raise SystemExit("Truncated capture")
        for index in range(draws):
            offset = draw_at + index * draw_size
            start, count = struct.unpack_from("<HH", data, offset + 2)
            if count < args.min_count or draw_size < 3224:
                continue
            if start + count > vertices:
                raise SystemExit("Vertex range outside batch")
            cp = struct.unpack_from("<256I", data, offset + 1124)
            xf = struct.unpack_from("<256f", data, offset + 2148)
            transform = struct.unpack_from("<13f", data, offset + 3172)
            vat = cp[255] & 7
            item = {"batch": batch, "draw": index, "vertices": count, "vat": vat,
                    "vat_a": hex(cp[0x70 + vat]), "position_format": (cp[0x70 + vat] >> 1) & 7,
                    "position_fraction": (cp[0x70 + vat] >> 4) & 31,
                    "vcd": hex(cp[0x50]), "array": hex(cp[0xA0]), "stride": cp[0xB0],
                    "viewport_projection": transform, "samples": []}
            if vertex_size >= 156:
                for sample in sorted({0, count // 2, count - 1}):
                    ptr = vertex_at + (start + sample) * vertex_size
                    x, y, z, matrix = struct.unpack_from("<3fI", data, ptr + 140)
                    entry = {"object": (x, y, z), "matrix_index": matrix,
                             "matrix": xf[matrix * 4:matrix * 4 + 12], "screen": struct.unpack_from("<2f", data, ptr)}
                    if vertex_size >= 168:
                        raw = data[ptr + 156:ptr + 168]
                        entry["position_bytes"] = raw.hex()
                        values = struct.unpack(">3f", raw)
                        entry["same_bytes_as_float"] = [v if math.isfinite(v) else str(v) for v in values]
                    item["samples"].append(entry)
            report["draws"].append(item)
    args.output.parent.mkdir(exist_ok=True, parents=True)
    args.output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(f"{batch} batches; {len(report['draws'])} draws selected; {args.output}")


if __name__ == "__main__":
    main()
