"""Read-only Windows guest RAM snapshot for the locally running test executable."""
import ctypes
from ctypes import wintypes as w
from pathlib import Path
import struct
import subprocess
import argparse

class MBI(ctypes.Structure):
    _fields_ = [("base",ctypes.c_void_p),("allocation",ctypes.c_void_p),("protect",w.DWORD),
                ("partition",w.WORD),("size",ctypes.c_size_t),("state",w.DWORD),("access",w.DWORD),("type",w.DWORD)]

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--pid", type=int)
    args = parser.parse_args()
    pid = args.pid
    if not pid:
        value = subprocess.check_output(["powershell", "-NoProfile", "-Command",
            "(Get-Process digimon_test -ErrorAction SilentlyContinue | Select-Object -First 1).Id"]).strip()
        if not value:
            raise SystemExit("No digimon_test process is running; snapshot not updated")
        pid = int(value)
    k = ctypes.WinDLL("kernel32", use_last_error=True)
    k.OpenProcess.restype = w.HANDLE
    k.OpenProcess.argtypes = [w.DWORD,w.BOOL,w.DWORD]
    k.VirtualQueryEx.argtypes = [w.HANDLE,ctypes.c_void_p,ctypes.POINTER(MBI),ctypes.c_size_t]
    k.VirtualQueryEx.restype = ctypes.c_size_t
    k.ReadProcessMemory.argtypes = [w.HANDLE,ctypes.c_void_p,ctypes.c_void_p,ctypes.c_size_t,ctypes.POINTER(ctypes.c_size_t)]
    k.CloseHandle.argtypes = [w.HANDLE]
    process = k.OpenProcess(0x410,False,pid)
    if not process:
        raise OSError(ctypes.get_last_error(), "OpenProcess")
    def read(address,length):
        data=ctypes.create_string_buffer(length); count=ctypes.c_size_t()
        if not k.ReadProcessMemory(process,address,data,length,ctypes.byref(count)):
            return b""
        return data.raw[:count.value]
    address = 0
    ram = None
    try:
        while address < 0x7fffffffffff:
            region=MBI()
            if not k.VirtualQueryEx(process,address,ctypes.byref(region),ctypes.sizeof(region)):
                break
            if region.state==0x1000 and region.access&255 in (4,8,0x40,0x80) and region.size>=0x1800000:
                data=read(region.base,65536)
                index=data.find(bytes.fromhex("0d15ea5e"))
                if index>=32 and data[index+8:index+12]==bytes.fromhex("01800000"):
                    ram=read(region.base+index-32,0x1800000)
                    break
            address=(region.base or 0)+region.size
    finally:
        k.CloseHandle(process)
    if ram is None or len(ram)!=0x1800000:
        raise RuntimeError("Could not locate the initialized guest RAM")
    output=Path(__file__).resolve().parents[1]/"build_test"
    output.mkdir(exist_ok=True)
    (output/"guest_ram.bin").write_bytes(ram)
    def word(address): return struct.unpack_from(">I",ram,address-0x80000000)[0]
    scene=0x80682D48
    title=word(scene+56)
    print(f"pid={pid} scene={word(scene+8)} behavior={title:08X}")
    if 0x80000000<=title<=0x81800000-696:
        for offset in (36,40,388,392,644,648,652,656,660,664,668,672,676,680,684,688):
            print(f"behavior+{offset}: {word(title+offset):08X}")
    framebuffer=ram[0x4f26a0:0x4f26a0+640*480*2]
    pixels=bytearray(640*480*3)
    for index in range(0,len(framebuffer),4):
        y0,u,y1,v=framebuffer[index:index+4]; d=u-128; e=v-128
        for n,y in enumerate((y0,y1)):
            c=y-16
            color=((298*c+516*d+128)>>8,(298*c-100*d-208*e+128)>>8,(298*c+409*e+128)>>8)
            row,col=divmod(index//2+n,640); offset=((479-row)*640+col)*3
            pixels[offset:offset+3]=bytes(max(0,min(255,value)) for value in color)
    header=struct.pack("<2sIHHI",b"BM",54+len(pixels),0,0,54)+struct.pack("<IiiHHIIiiII",40,640,480,1,24,0,len(pixels),2835,2835,0,0)
    (output/"xfb_latest.bmp").write_bytes(header+pixels)
    print(output/"xfb_latest.bmp")

if __name__=="__main__": main()
