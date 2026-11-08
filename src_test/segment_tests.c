#include "cpu/cpu.h"
#include <stdio.h>
#include <string.h>
typedef void (*SegmentCase)(CPUState*);
extern SegmentCase segment_cases[2][4];
static void observe(CPUState* cpu,u32 address,u64 value,u8 size){
    cpu->gpr[24]^=cpu->pc;cpu->gpr[25]+=(u32)value;cpu->gpr[26]+=address+size;
}
#define CHECK(x) do{if(!(x)){fprintf(stderr,"segment FAIL line%d seed%u kind%u mode%u: %s\n",__LINE__,seed,kind,mode,#x);return 1;}}while(0)
int main(void){
    const u32 entries[]={0x80001000u,0x80001080u,0x80001100u,0x80001180u,0x80001200u,0x80001280u,0x80001004u,0x81800000u};
    const s64 budgets[]={-512,-256,-255,0,768,4096};u32 random=1,cases=0;
    for(u32 seed=0;seed<2048;seed++)for(u32 kind=0;kind<2;kind++){
        CPUState input={0};u8 initial[256];
        for(u32 r=0;r<32;r++){random=random*1664525u+1013904223u;input.gpr[r]=random;input.fpr[r]=(s32)random*0.125;input.ps1[r]=(s32)random*0.25;}
        for(u32 r=0;r<sizeof(initial);r++)initial[r]=(u8)(r*17u+seed);
        input.pc=entries[seed%8];input.lr=0x81800000u;input.ctr=seed%4;input.downcount=budgets[seed%6];
        input.msr=(seed&1 ? 0x2000u:0u)|(seed&2 ? 0x8000u:0u);input.fpscr=seed&3u;input.timebase=seed*1000u;
        input.reserve_valid=(seed&8)!=0;input.external_write=observe;
        CPUState reference={0};u8 reference_ram[256];
        for(u32 mode=0;mode<4;mode++){
            u8 ram[256];memcpy(ram,initial,sizeof(ram));CPUState cpu=input;cpu.ram=ram;cpu.ram_size=sizeof(ram);
            ppc_fpscr_control_updated(&cpu);segment_cases[kind][mode](&cpu);
            if(!mode){reference=cpu;memcpy(reference_ram,ram,sizeof(ram));}
            else{reference.ram=cpu.ram;CHECK(!memcmp(&cpu,&reference,sizeof(cpu)));CHECK(!memcmp(ram,reference_ram,sizeof(ram)));cases++;}
        }
    }
    printf("[Segments] %u exact CPU/RAM comparisons: entry/invalid PC, no-entry helper, live PC observer, forward/backward/fallthrough, dispatch budget, FP exception, reservation and three region sizes passed\n",cases);
    return 0;
}
