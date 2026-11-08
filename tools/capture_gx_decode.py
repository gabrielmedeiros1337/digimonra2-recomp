"""Read-only snapshot of an in-flight indexed GX worker for decoder regression."""
import argparse,ctypes as C,struct,re,time,json
from ctypes import wintypes as W
from pathlib import Path

def main():
 a=argparse.ArgumentParser();a.add_argument('pid',type=int);a.add_argument('tid',type=int);a.add_argument('--map',type=Path,required=True);a.add_argument('--output',type=Path,required=True);o=a.parse_args()
 k=C.WinDLL('kernel32',use_last_error=True);ps=C.WinDLL('psapi',use_last_error=True)
 k.OpenProcess.argtypes=[W.DWORD,W.BOOL,W.DWORD];k.OpenProcess.restype=W.HANDLE
 k.OpenThread.argtypes=[W.DWORD,W.BOOL,W.DWORD];k.OpenThread.restype=W.HANDLE
 k.SuspendThread.argtypes=k.ResumeThread.argtypes=[W.HANDLE];k.SuspendThread.restype=k.ResumeThread.restype=W.DWORD
 k.CloseHandle.argtypes=[W.HANDLE];k.ReadProcessMemory.argtypes=[W.HANDLE,C.c_void_p,C.c_void_p,C.c_size_t,C.POINTER(C.c_size_t)]
 ps.EnumProcessModulesEx.argtypes=[W.HANDLE,C.POINTER(W.HMODULE),W.DWORD,C.POINTER(W.DWORD),W.DWORD]
 h=k.OpenProcess(0x410,False,o.pid);t=k.OpenThread(0x42,False,o.tid)
 if not h or not t:
  error=C.WinError(C.get_last_error())
  if t:k.CloseHandle(t)
  if h:k.CloseHandle(h)
  raise error
 def read(addr,n):
  b=C.create_string_buffer(n);got=C.c_size_t()
  if not k.ReadProcessMemory(h,addr,b,n,C.byref(got)) or got.value!=n:raise C.WinError(C.get_last_error())
  return b.raw
 try:
  modules=(W.HMODULE*1024)();needed=W.DWORD()
  if not ps.EnumProcessModulesEx(h,modules,C.sizeof(modules),C.byref(needed),3):raise C.WinError(C.get_last_error())
  base=int(modules[0]);m=o.map.read_text(errors='replace');preferred=int(re.search(r'Preferred load address is\s+([0-9A-Fa-f]+)',m)[1],16)
  def symbol(name):
   match=re.search(r'^\s+\S+\s+'+re.escape(name)+r'\s+([0-9A-Fa-f]{16})\s',m,re.M)
   if not match:raise ValueError('Missing symbol '+name)
   return base+int(match[1],16)-preferred
  cpu=struct.unpack('<Q',read(symbol('s_crash_cpu'),8))[0]
  ram=struct.unpack('<Q',read(cpu+0xD80,8))[0];ram_size=struct.unpack('<I',read(cpu+0xD88,4))[0]
  if ram_size!=0x1800000:raise ValueError('CPU/map validation failed')
  workers=symbol('s_vertex_workers');vertices=symbol('s_queued_vertices');deadline=time.monotonic()+15
  while time.monotonic()<deadline:
   time.sleep(0.001)
   if k.SuspendThread(t)==0xFFFFFFFF:raise C.WinError(C.get_last_error())
   try:
    job=read(workers,160 if 'gx_gl_draw_raw' in m else 144);owner=struct.unpack_from('<Q',job)[0];stride=struct.unpack_from('<I',job,8)[0]
    output=struct.unpack_from('<Q',job,72)[0];cursor,count,chosen,mxcsr=struct.unpack_from('<4I',job,88)
    rounding=struct.unpack_from('<i',job,108)[0];hits,misses=struct.unpack_from('<2Q',job,112)
    eligible=(len(job)==144 or struct.unpack_from('<Q',job,144)[0]==0) and owner==cpu and 0<count<=16384 and 0<stride<=64 and job[16]>=2 and job[104]==0 and hits+misses<count and vertices<=output and output+count*168<=vertices+65536*168
    if not eligible:continue
    end=time.perf_counter()+0.015
    while time.perf_counter()<end:
     state=read(workers+112,16)
     if sum(struct.unpack('<2Q',state))==count:break
     time.sleep(0.001)
    else:continue
    # The worker has finished; allow its last stores/semaphore publication.
    time.sleep(0.002)
    fifo=struct.unpack('<Q',read(symbol('s_fifo_buf'),8))[0]
    projection=read(symbol('s_projection_loaded'),1)[0];lighting=read(symbol('s_lighting_loaded'),1)[0]
    header=b'GXVD0001'+struct.pack('<10I',168,count,cursor,chosen,rounding,mxcsr,ram_size,1<<20,projection,lighting)
    data=header+job[8:68]+read(symbol('s_cp'),256*4)+read(symbol('s_xf'),0x1058*4)+read(fifo,1<<20)+read(ram,ram_size)+read(output,count*168)
    # Counters legitimately changed during completion; core job identity must stay.
    if read(workers,112)!=job[:112]:raise ValueError('Job changed while main thread suspended')
    o.output.write_bytes(data)
    print(json.dumps({'vertices':count,'stride':stride,'chosen':chosen,'bytes':len(data),'output':str(o.output)}));return
   finally:k.ResumeThread(t)
  raise TimeoutError('No active bounded indexed worker captured')
 finally:k.CloseHandle(t);k.CloseHandle(h)
if __name__=='__main__':main()
