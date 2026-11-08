/* Windows x64 read-only sampler. Suspend only to copy context/stack;
 * unwind the copy after resuming. Never opens the process for writing. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dbghelp.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned char snapshot[65536];
static DWORD64 stack_start,region_start,region_end;
static SIZE_T stack_bytes;
static BOOL CALLBACK read_snapshot(HANDLE process,DWORD64 address,PVOID target,DWORD count,LPDWORD read) {
    *read=0;
    if(address>=stack_start && address-stack_start<=stack_bytes && count<=stack_bytes-(SIZE_T)(address-stack_start)) {
        memcpy(target,snapshot+(SIZE_T)(address-stack_start),count);*read=count;return TRUE;
    }
    if(address>=region_start && address<region_end)return FALSE;
    SIZE_T got=0;BOOL ok=ReadProcessMemory(process,(LPCVOID)(ULONG_PTR)address,target,count,&got);*read=(DWORD)got;return ok;
}
int main(int argc,char** argv) {
    if(argc!=5 && argc!=6 && argc!=7){fprintf(stderr,"usage: sample_stacks PID TID output duration_ms [TimingState_stage_address] [stage0..6]\n");return 2;}
    unsigned wanted_stage=argc==7 ? strtoul(argv[6],NULL,10):1;
    if(wanted_stage>6)return 2;
    DWORD64 stage_address=argc>=6 ? _strtoui64(argv[5],NULL,0):0;
    DWORD pid=strtoul(argv[1],NULL,10),tid=strtoul(argv[2],NULL,10),ms=strtoul(argv[4],NULL,10);
    if(ms<200 || ms>6000)return 2;
    HANDLE process=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,pid);
    HANDLE thread=OpenThread(THREAD_GET_CONTEXT|THREAD_SUSPEND_RESUME|THREAD_QUERY_INFORMATION,FALSE,tid);
    if(!process || !thread){fprintf(stderr,"open failed: %lu\n",GetLastError());if(thread)CloseHandle(thread);if(process)CloseHandle(process);return 1;}
    FILE* out=fopen(argv[3],"w");if(!out){CloseHandle(thread);CloseHandle(process);return 1;}
    SymSetOptions(SYMOPT_DEFERRED_LOADS|SYMOPT_FAIL_CRITICAL_ERRORS|SYMOPT_NO_PROMPTS|SYMOPT_IGNORE_NT_SYMPATH);
    if(!SymInitialize(process,"",TRUE)){fprintf(stderr,"SymInitialize failed\n");fclose(out);CloseHandle(thread);CloseHandle(process);return 1;}
    HMODULE modules[1024];DWORD needed=0;
    if(EnumProcessModulesEx(process,modules,sizeof(modules),&needed,LIST_MODULES_64BIT)) {
        DWORD count=needed/sizeof(HMODULE);if(count>1024)count=1024;
        for(DWORD i=0;i<count;i++){MODULEINFO info;char path[2048];if(GetModuleInformation(process,modules[i],&info,sizeof(info)) && GetModuleFileNameExA(process,modules[i],path,sizeof(path)))fprintf(out,"M %llX %lX %s\n",(unsigned long long)(ULONG_PTR)info.lpBaseOfDll,info.SizeOfImage,path);}
    }
    if(stage_address)fprintf(out,"F exclusive_stage=%s address=%llX\n",wanted_stage==1 ? "GAME":wanted_stage==2 ? "GX_DECODE":"OTHER",(unsigned long long)stage_address);
    ULONGLONG end=GetTickCount64()+ms;unsigned samples=0;
    while(GetTickCount64()<end) {
        CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_FULL;
        BOOL captured=FALSE;
        if(SuspendThread(thread)==(DWORD)-1)break;
        if(GetThreadContext(thread,&context)) {
            MEMORY_BASIC_INFORMATION info;
            if(VirtualQueryEx(process,(LPCVOID)(ULONG_PTR)context.Rsp,&info,sizeof(info))) {
                region_start=(DWORD64)(ULONG_PTR)info.BaseAddress;region_end=region_start+info.RegionSize;
                stack_start=context.Rsp;stack_bytes=(SIZE_T)(region_end-stack_start);if(stack_bytes>sizeof(snapshot))stack_bytes=sizeof(snapshot);
                SIZE_T got=0;captured=ReadProcessMemory(process,(LPCVOID)(ULONG_PTR)stack_start,snapshot,stack_bytes,&got) && got==stack_bytes;
            }
        }
        if(captured && stage_address){
            unsigned char state[8];SIZE_T got=0;
            if(!ReadProcessMemory(process,(LPCVOID)(ULONG_PTR)stage_address,state,8,&got) || got!=8 || state[0]!=wanted_stage || state[1] || state[2] || state[3] || !state[4])captured=FALSE;
        }
        // No symbol lookup or unwinding is done while the game is suspended.
        if(ResumeThread(thread)==(DWORD)-1){fprintf(stderr,"ResumeThread failed: %lu\n",GetLastError());break;}
        if(captured) {
            STACKFRAME64 frame;memset(&frame,0,sizeof(frame));frame.AddrPC.Offset=context.Rip;frame.AddrPC.Mode=AddrModeFlat;
            frame.AddrFrame.Offset=context.Rbp;frame.AddrFrame.Mode=AddrModeFlat;frame.AddrStack.Offset=context.Rsp;frame.AddrStack.Mode=AddrModeFlat;
            fprintf(out,"S %llX",(unsigned long long)context.Rip);DWORD64 last=context.Rip;
            for(unsigned depth=0;depth<64;depth++) {
                if(!StackWalk64(IMAGE_FILE_MACHINE_AMD64,process,thread,&frame,&context,read_snapshot,SymFunctionTableAccess64,SymGetModuleBase64,NULL) || !frame.AddrPC.Offset)break;
                if(frame.AddrPC.Offset!=last){fprintf(out," %llX",(unsigned long long)frame.AddrPC.Offset);last=frame.AddrPC.Offset;}
            }
            fprintf(out,"\n");samples++;
        }
        Sleep(3);
    }
    SymCleanup(process);fclose(out);CloseHandle(thread);CloseHandle(process);printf("Read-only stack snapshots: %u; game resumed before every unwind\n",samples);return samples ? 0:1;
}
