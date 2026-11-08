"""Brief Windows x64 instruction-pointer sampling; no guest writes or input.

Each suspension is paired with ResumeThread in finally. Symbols are local
module/export symbols; no symbol server or network is configured.
"""
import argparse
import collections
import ctypes as C
from ctypes import wintypes as W
import json
from pathlib import Path
import time
import re
import bisect
import struct


def main():
    args = argparse.ArgumentParser()
    args.add_argument("pid", type=int)
    args.add_argument("tid", type=int)
    args.add_argument("--seconds", type=float, default=3)
    args.add_argument("--output", type=Path, default=Path("build_test/native_profile.json"))
    args.add_argument("--map", type=Path)
    args.add_argument("--frame-stage",action="store_true",help="Read exclusive timing stage from matching frame_timing.obj state")
    args.add_argument("--guest-pc", action="store_true", help="Read CPU PC while the main thread is suspended; requires matching --map")
    args.add_argument("--guest-stack",action="store_true",help="Read guest backchains for approximate inclusive GAME attribution; no writes")
    args.add_argument("--capture-guest-range",nargs=2,type=lambda v:int(v,0),metavar=("LOW","HIGH"),help="Capture at most 16 register snapshots in this PPC range; implies --guest-pc")
    args.add_argument("--capture-symbol", help="Restrict register snapshots to this executable function; requires --capture-guest-range")
    options = args.parse_args()
    if options.guest_stack:options.frame_stage=True;options.guest_pc=True
    if options.capture_symbol and not options.capture_guest_range:args.error("--capture-symbol requires --capture-guest-range")
    if options.capture_guest_range or options.frame_stage:options.guest_pc=True
    kernel = C.WinDLL("kernel32", use_last_error=True)
    psapi = C.WinDLL("psapi", use_last_error=True)
    dbg = C.WinDLL("dbghelp", use_last_error=True)
    kernel.OpenProcess.argtypes = [W.DWORD, W.BOOL, W.DWORD]
    kernel.OpenProcess.restype = W.HANDLE
    kernel.OpenThread.argtypes = [W.DWORD, W.BOOL, W.DWORD]
    kernel.OpenThread.restype = W.HANDLE
    kernel.SuspendThread.argtypes = kernel.ResumeThread.argtypes = [W.HANDLE]
    kernel.SuspendThread.restype = kernel.ResumeThread.restype = W.DWORD
    kernel.ReadProcessMemory.argtypes = [W.HANDLE,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(C.c_size_t)]
    kernel.GetThreadContext.argtypes = [W.HANDLE, C.c_void_p]
    kernel.CloseHandle.argtypes = [W.HANDLE]
    psapi.EnumProcessModulesEx.argtypes = [W.HANDLE, C.POINTER(W.HMODULE), W.DWORD, C.POINTER(W.DWORD), W.DWORD]
    psapi.GetModuleInformation.argtypes = [W.HANDLE, W.HMODULE, C.c_void_p, W.DWORD]
    psapi.GetModuleFileNameExW.argtypes = [W.HANDLE, W.HMODULE, W.LPWSTR, W.DWORD]
    dbg.SymInitialize.argtypes = [W.HANDLE, W.LPCSTR, W.BOOL]
    dbg.SymFromAddr.argtypes = [W.HANDLE, C.c_ulonglong, C.POINTER(C.c_ulonglong), C.c_void_p]
    dbg.SymCleanup.argtypes = [W.HANDLE]
    process = kernel.OpenProcess(0x410, False, options.pid)
    thread = kernel.OpenThread(0x4A, False, options.tid)
    if not process or not thread:
        raise C.WinError(C.get_last_error())
    try:
        modules = (W.HMODULE * 1024)()
        needed = W.DWORD()
        if not psapi.EnumProcessModulesEx(process, modules, C.sizeof(modules), C.byref(needed), 3):
            raise C.WinError(C.get_last_error())
        ranges = []
        for module in list(modules)[:needed.value // C.sizeof(W.HMODULE)]:
            info = C.create_string_buffer(24)
            name = C.create_unicode_buffer(1024)
            if psapi.GetModuleInformation(process, module, info, 24):
                base = C.c_ulonglong.from_buffer(info).value
                size = W.DWORD.from_buffer(info, 8).value
                psapi.GetModuleFileNameExW(process, module, name, 1024)
                ranges.append((base, base + size, Path(name.value).name))
        cpu_address=None;stage_address=None
        guest_counts=collections.Counter()
        guest_states=[]
        guest_chains=collections.Counter();ram_host=None
        if options.guest_pc:
            if not options.map:raise ValueError("--guest-pc requires the matching link map")
            map_text=options.map.read_text(errors="replace")
            preferred=int(re.search(r'Preferred load address is\s+([0-9A-Fa-f]+)',map_text)[1],16)
            symbol=re.search(r'^\s+\S+\s+s_crash_cpu\s+([0-9A-Fa-f]+)\s',map_text,re.M)
            if not symbol:raise ValueError("s_crash_cpu not present in this link map")
            executable=next(r for r in ranges if r[2].lower()=="digimon_test.exe")
            pointer=C.c_uint64();received=C.c_size_t()
            if not kernel.ReadProcessMemory(process,executable[0]+int(symbol[1],16)-preferred,C.byref(pointer),8,C.byref(received)):
                raise C.WinError(C.get_last_error())
            cpu_address=pointer.value
            ram_size=C.c_uint32()
            if not cpu_address or not kernel.ReadProcessMemory(process,cpu_address+0xD88,C.byref(ram_size),4,C.byref(received)) or ram_size.value!=0x1800000:
                raise ValueError("CPUState layout/map validation failed; refusing to sample")
            if options.guest_stack:
                ram_pointer=C.c_uint64()
                if not kernel.ReadProcessMemory(process,cpu_address+0xD80,C.byref(ram_pointer),8,C.byref(received)) or not ram_pointer.value:
                    raise ValueError("Missing guest RAM pointer")
                ram_host=ram_pointer.value
            if options.frame_stage:
                stage_symbol=re.search(r'^\s+\S+\s+s\s+([0-9A-Fa-f]+)\s+frame_timing\.obj\s*$',map_text,re.M)
                if not stage_symbol:raise ValueError("TimingState symbol missing; refusing guessed stage address")
                stage_address=executable[0]+int(stage_symbol[1],16)-preferred+92
            print(f"Read-only CPUState at 0x{cpu_address:X}")
            if stage_address:print(f"TimingState stage at 0x{stage_address:X}")
        capture_host_range=None
        if options.capture_symbol:
            entries=sorted((int(m[2],16)-preferred,m[1]) for m in re.finditer(r'^\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{16})\s+f\s',map_text,re.M))
            index=next((i for i,e in enumerate(entries) if e[1]==options.capture_symbol),None)
            if index is None or index+1>=len(entries):raise ValueError("Capture symbol/range missing")
            capture_host_range=(executable[0]+entries[index][0],executable[0]+entries[index+1][0])
        stage_state=C.create_string_buffer(8)
        guest_state=(C.c_uint32*7)()
        received=C.c_size_t()
        stack_copy=C.create_string_buffer(65536);guest_sp=C.c_uint32()
        storage = C.create_string_buffer(1248)
        context = (C.addressof(storage) + 15) & ~15
        counts = collections.Counter()
        deadline = time.perf_counter() + min(max(options.seconds, 0.1), 10)
        while time.perf_counter() < deadline:
            C.c_uint32.from_address(context + 48).value = 0x100001
            if kernel.SuspendThread(thread) == 0xFFFFFFFF:
                break
            try:
                if kernel.GetThreadContext(thread, context):
                    rip=C.c_uint64.from_address(context + 248).value
                    counts[rip] += 1
                    if cpu_address and kernel.ReadProcessMemory(process,cpu_address+0x280,guest_state,28,C.byref(received)) and received.value==28:
                        stage=-1;active=False
                        if stage_address and kernel.ReadProcessMemory(process,stage_address,stage_state,8,C.byref(received)) and received.value==8:
                            stage=struct.unpack_from("<I",stage_state.raw)[0];active=bool(stage_state.raw[4])
                            if stage>6:raise ValueError("TimingState layout validation failed")
                        guest_counts[(rip,guest_state[0],stage,active)]+=1
                        if options.guest_stack and active and stage==1:
                            chain=[guest_state[0]];truncated=True
                            # Current LR covers a leaf without its own stack frame.
                            lr=guest_state[1]
                            if 0x800034C0<=lr-4<0x802E1340 and not (lr&3):chain.append(lr-4)
                            if kernel.ReadProcessMemory(process,cpu_address+4,C.byref(guest_sp),4,C.byref(received)):
                                sp=guest_sp.value;offset=sp-0x80000000
                                if 0<=offset<0x1800000 and not (sp&7):
                                    length=min(65536,0x1800000-offset)
                                    if kernel.ReadProcessMemory(process,ram_host+offset,stack_copy,length,C.byref(received)) and received.value==length:
                                        data=stack_copy.raw[:length];at=0
                                        for depth in range(64):
                                            if at+4>length:break
                                            previous=struct.unpack_from(">I",data,at)[0]
                                            if not previous:truncated=False;break
                                            next_at=previous-sp
                                            if previous&7 or next_at<=at or next_at+8>length:break
                                            saved=struct.unpack_from(">I",data,next_at+4)[0]
                                            if 0x800034C0<=saved-4<0x802E1340 and not(saved&3):chain.append(saved-4)
                                            at=next_at
                            guest_chains[(rip,tuple(chain),truncated)]+=1
                        if options.capture_guest_range and len(guest_states)<16 and options.capture_guest_range[0]<=guest_state[0]<options.capture_guest_range[1] and (not capture_host_range or capture_host_range[0]<=rip<capture_host_range[1]):
                            snapshot=C.create_string_buffer(0xDD0)
                            if kernel.ReadProcessMemory(process,cpu_address,snapshot,0xDD0,C.byref(received)) and received.value==0xDD0:
                                b=snapshot.raw
                                guest_states.append({"rip":hex(rip),"pc":hex(guest_state[0]),"gpr":list(struct.unpack_from("<32I",b)),"fpr":list(struct.unpack_from("<32d",b,0x80)),"ps1":list(struct.unpack_from("<32d",b,0x180)),"gqr":list(struct.unpack_from("<8I",b,0x300)),"msr":struct.unpack_from("<I",b,0x298)[0],"hid2":struct.unpack_from("<I",b,0x2B0)[0],"exception":struct.unpack_from("<I",b,0x320)[0],"reserve_valid":bool(b[0x344]),"downcount":struct.unpack_from("<q",b,0xD98)[0],"cache_control":hex(struct.unpack_from("<Q",b,0xDC8)[0]),"external_pointer":hex(struct.unpack_from("<Q",b,0xD90)[0]),"ctr":struct.unpack_from("<I",b,0x288)[0]})
            finally:
                kernel.ResumeThread(thread)
            time.sleep(0.001)
        # SYMBOL_INFO has a flexible ANSI name at offset 84 on Windows x64.
        symbols = bool(dbg.SymInitialize(process, b"", True))
        grouped = collections.Counter()
        labels={}
        raw = []
        map_entries=[]
        if options.map:
            map_text=options.map.read_text(errors="replace")
            preferred=re.search(r'Preferred load address is\s+([0-9A-Fa-f]+)',map_text)
            if not preferred:raise ValueError("Invalid linker map")
            preferred=int(preferred[1],16)
            seen=set()
            for match in re.finditer(r'^\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{16})\s+f\s+([^\r\n]+)',map_text,re.M):
                rva=int(match[2],16)-preferred
                if rva not in seen:map_entries.append((rva,match[1]));seen.add(rva)
            map_entries.sort()
        map_offsets=[x[0] for x in map_entries]
        for address, count in counts.items():
            module = next((x for x in ranges if x[0] <= address < x[1]), (0, 0, "unknown"))
            symbol = C.create_string_buffer(4096)
            C.c_uint32.from_buffer(symbol).value = 88
            C.c_uint32.from_buffer(symbol, 80).value = 4000
            displacement = C.c_ulonglong()
            label = f"{module[2]}+0x{address-module[0]:X}"
            if symbols and dbg.SymFromAddr(process, address, C.byref(displacement), symbol):
                name = C.string_at(C.addressof(symbol)+84).decode(errors="replace")
                label = f"{module[2]}!{name}+0x{displacement.value:X}"
                if displacement.value>4096:
                    label=f"{module[2]}+0x{address-module[0]:X} (nearest export {name}+0x{displacement.value:X})"
            if module[2].lower()=="digimon_test.exe" and map_entries:
                index=bisect.bisect_right(map_offsets,address-module[0])-1
                if index>=0:label=f"digimon_test.exe!{map_entries[index][1]}"
            labels[address]=label
            grouped[label] += count
            raw.append({"address": hex(address), "rva": hex(address-module[0]), "module": module[2], "count": count, "symbol": label})
        if symbols:
            dbg.SymCleanup(process)
        guest_rows=[{"pc":hex(pc),"rip":hex(rip),"count":count,"symbol":labels[rip],"frame_stage":stage,"frame_active":active} for (rip,pc,stage,active),count in guest_counts.items()]
        guest_pcs=collections.Counter()
        for row in guest_rows:
            if row["symbol"].startswith("digimon_test.exe!"):
                guest_pcs[row["pc"]]+=row["count"]
        chain_rows=[{"rip":hex(rip),"symbol":labels[rip],"pcs":[hex(pc) for pc in chain],"truncated":truncated,"count":count} for (rip,chain,truncated),count in guest_chains.items()]
        options.output.write_text(json.dumps({"samples": sum(counts.values()), "groups": grouped.most_common(), "raw": raw,"guest_pcs":guest_pcs.most_common(),"guest_samples":guest_rows,"guest_states":guest_states,"guest_chains":chain_rows,"inclusive_note":"Guest backchain plus LR approximation; leaf/prologue/tail-call ambiguity and truncated chains remain; not exact call instrumentation."}, indent=2))
        for label, count in grouped.most_common(25):
            print(f"{count:5} {label}")
        if cpu_address:
            print("Guest PPC PC (executable samples, includes HLE cost at its caller):")
            for pc,count in guest_pcs.most_common(30):print(f"{count:5} {pc}")
    finally:
        kernel.CloseHandle(thread)
        kernel.CloseHandle(process)


if __name__ == "__main__":
    main()
