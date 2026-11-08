"""Read-only local SDK name candidates; never patches generated/guest code.
Checksum follows Dolphin HashSignatureDB::ComputeCodeChecksum (GPL-2.0-or-later),
in the pinned vendor checkout. Hash+size matches need semantic inspection.
"""
import argparse
import bisect
import json
from pathlib import Path
import struct

MASK = 0xFFFFFFFF

def rol(value, shift):
    shift &= 31
    return ((value << shift) | (value >> ((32-shift)&31))) & MASK


def opcode_key(word):
    op = word & 0xFC000000
    aux = word >> 26
    if aux == 4:
        low = word & 63
        return op | low | (word & 0x7C0 if low in (0,8,16,21,22) else 0)
    if aux in (7,8,10,11,12,13,14,15) or 32 <= aux < 56:
        return op | (word & 0x03FF0000)
    if aux in (19,31,63):
        return op | (word & 0x7FF)
    if aux == 59:
        low = word & 63
        return op | low | (word & 0x7C0 if low < 16 else 0)
    return op


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--dol", type=Path, default=Path("extracted/sys/main.dol"))
    p.add_argument("--db", type=Path, default=Path("third_party/recomp-deps/dolphin/Data/Sys/totaldb.dsy"))
    p.add_argument("--output", type=Path, default=Path("build_test/sdk_signature_candidates.json"))
    args = p.parse_args()
    data = args.db.read_bytes()
    count, = struct.unpack_from("<I", data)
    if len(data) != 4 + count*136:
        raise ValueError("Unexpected DSY layout")
    known = {}
    for i in range(count):
        checksum, size, raw = struct.unpack_from("<II128s", data, 4+i*136)
        if size >= 16 and not size%4:
            known.setdefault((size,checksum), []).append(raw.split(b"\0",1)[0].decode(errors="replace"))
    sizes = sorted({k[0] for k in known})
    dol = args.dol.read_bytes()
    offsets = struct.unpack_from(">18I",dol)
    addresses = struct.unpack_from(">18I",dol,0x48)
    lengths = struct.unpack_from(">18I",dol,0x90)
    sections = []
    for i in range(7):
        off, addr, size = offsets[i], addresses[i], lengths[i]
        if size:
            if off > len(dol) or size > len(dol)-off or size%4:raise ValueError("Invalid DOL text")
            words = struct.unpack_from(">"+str(size//4)+"I",dol,off)
            prefix = [0]
            for word in words:prefix.append(rol(prefix[-1],17)^opcode_key(word))
            sections.append((addr, size, words, prefix))
    def in_text(addr):return not addr%4 and any(base <= addr < base+size for base,size,_,_ in sections)
    entry, = struct.unpack_from(">I",dol,0xE0)
    starts = {entry} | {s[0] for s in sections}
    for base,size,words,prefix in sections:
        for i,word in enumerate(words):
            if word&1 and word>>26 in (16,18):
                bits = 16 if word>>26 == 16 else 26
                disp = word & ((1<<bits)-4)
                if disp & (1<<(bits-1)):disp -= 1<<bits
                dest = (disp if word&2 else base+i*4+disp)&MASK
                if in_text(dest):starts.add(dest)
        # Verify range-hash identity against the direct recurrence.
        if len(words)>32:
            direct = 0
            for word in words[3:29]:direct=rol(direct,17)^opcode_key(word)
            assert direct == prefix[29]^rol(prefix[3],17*26)
    for i in range(7,18):
        off, size = offsets[i], lengths[i]
        if off <= len(dol) and size <= len(dol)-off:
            for (addr,) in struct.iter_unpack(">I",dol[off:off+size-size%4]):
                if in_text(addr):starts.add(addr)
    matches = []
    for addr in sorted(starts):
        section = next((s for s in sections if s[0] <= addr < s[0]+s[1]),None)
        if not section:continue
        base,length,words,prefix = section
        begin = (addr-base)//4
        for size in sizes:
            if addr+size>base+length:break
            n = size//4
            checksum = prefix[begin+n]^rol(prefix[begin],17*n)
            names = known.get((size,checksum))
            if names:
                matches.append(dict(address=f"{addr:08X}", size=size, checksum=f"{checksum:08X}", names=sorted(set(names))))
    result = dict(dol=str(args.dol),database=str(args.db),starts=len(starts),records=count,matches=matches,
        note="Relocation-insensitive opcode checksum + size candidates. Not a semantic proof; no code or memory was modified.")
    args.output.write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(f"SDK signature candidates: {len(matches)} matches from {len(starts)} starts / {count} records")
    for match in matches:
        if 0x802B0000 <= int(match["address"],16) < 0x802B6000:
            print(match["address"],match["size"]," | ".join(match["names"]))

if __name__ == "__main__":
    main()
