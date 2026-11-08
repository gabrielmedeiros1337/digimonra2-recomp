#include "native_copy_adapter.h"
#include "sdk_floor.h"
#include "sdk_vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool g_native_blocks_enabled=true;
bool g_floor_oracle_stop;
void ref_floor(CPUState*);
void ref_copy_0(CPUState*);void ref_copy_1(CPUState*);void ref_copy_2(CPUState*);void ref_copy_3(CPUState*);
#define CHECK(x) do{if(!(x)){fprintf(stderr,"native top FAIL line%d: %s\n",__LINE__,#x);return 1;}}while(0)
static int floor_contracts(void){
    u8 a[65536]={0},b[65536]={0};CPUState seed={0};u32 cases=0;
    seed.ram=a;seed.ram_size=sizeof(a);seed.msr=0x2000u;seed.lr=0x81800000u;seed.gpr[13]=0x80008000u;
    double huge=1e300;u64 bits;memcpy(&bits,&huge,8);mem_write64(&seed,seed.gpr[13]-29304u,bits);mem_write64(&seed,seed.gpr[13]-29296u,0);
    const u32 exps[]={0,1,1000,1022,1023,1024,1030,1042,1075,1100,2046};g_fast_float_enabled=true;
    for(u32 sample=0;sample<128;sample++)for(u32 sign=0;sign<2;sign++)for(u32 e=0;e<11;e++)for(u32 route=0;route<2;route++){
        for(u32 r=0;r<32;r++){seed.gpr[r]=0xA5000000u+r*29+sample;seed.fpr[r]=r/8.;seed.ps1[r]=-(double)r/16.;}
        seed.pc=0x8029D888u;seed.gpr[1]=0x8000F000u;seed.gpr[13]=0x80008000u;seed.downcount=4096;seed.cr=0x13579BDFu;seed.xer=(sample&3u)<<29;seed.fpscr=0x1F000u;
        bits=((u64)sign<<63)|((u64)exps[e]<<52)|(sample%4 ? (0x123456789ABCDull*sample)&0xFFFFFFFFFFFFFull:0);memcpy(&seed.fpr[1],&bits,8);
        memcpy(b,a,sizeof(a));CPUState expected=seed,actual=seed;expected.ram=b;g_floor_oracle_stop=false;ref_floor(&expected);
        if(route){g_floor_oracle_stop=true;ref_floor(&actual);g_floor_oracle_stop=false;}
        CHECK(sdk_floor(&actual,route!=0));expected.ram=a;
        if(memcmp(&actual,&expected,sizeof(actual)) || memcmp(a,b,sizeof(a))){
            fprintf(stderr,"floor sample%u sign%u exp%u route%u budget%lld/%lld CR%08X/%08X XER%08X/%08X\n",sample,sign,exps[e],route,actual.downcount,expected.downcount,actual.cr,expected.cr,actual.xer,expected.xer);
            for(u32 r=0;r<32;r++)if(actual.gpr[r]!=expected.gpr[r])fprintf(stderr,"r%u=%08X/%08X\n",r,actual.gpr[r],expected.gpr[r]);CHECK(0);
        }cases++;
    }
    printf("[Floor HLE] %u complete CPU/RAM comparisons, signed zeros/subnormals, integer/fractional, entry/prologue passed\n",cases);return 0;
}
static int copy_contracts(void){
    void(*refs[])(CPUState*)={ref_copy_0,ref_copy_1,ref_copy_2,ref_copy_3};
    u32 pcs[]={0x8023DA4C,0x8023DCC4,0x8024B138,0x8024D468};u32 tails[]={0x8023DA80,0x8023DCF8,0x8024B16C,0x8024D49C};
    u32 sources[]={11,8,9,11},dests[]={9,9,11,9},counters[]={10,11,10,10};
    s64 budgets[]={-260,-240,-1,0,768};u8 a[8192],b[8192];u32 cases=0;
    for(u32 k=0;k<4;k++)for(u32 n=2;n<18;n++)for(u32 budget=0;budget<5;budget++){
        CPUState seed={0};for(u32 i=0;i<sizeof(a);i++)a[i]=(u8)(i*37+n*11);memcpy(b,a,sizeof(a));
        seed.ram=a;seed.ram_size=sizeof(a);seed.downcount=budgets[budget];seed.pc=pcs[k];seed.cr=0x12345678;seed.xer=0x80000000u;
        seed.gpr[sources[k]]=0x80000100u;seed.gpr[dests[k]]=0x80001000u;seed.gpr[counters[k]]=n*24;
        CPUState actual=seed,expected=seed;expected.ram=b;refs[k](&expected);
        // Execute the original first iteration, intercepting its last store.
        actual.downcount-=16;actual.gpr[counters[k]]-=24;actual.xer|=0x20000000u;
        actual.cr=(actual.cr&0x0FFFFFFFu)|(((actual.gpr[counters[k]] ? 4u:2u)|1u)<<28);
        u32 source=actual.gpr[sources[k]],dest=actual.gpr[dests[k]];
        for(u32 i=0;i<5;i++){actual.gpr[0]=mem_read32(&actual,source+i*4);primary_write32(&actual,dest+i*4,actual.gpr[0]);}
        actual.gpr[0]=mem_read32(&actual,source+20);actual.gpr[sources[k]]+=24;actual.pc=tails[k];
        copy_matrix_store(&actual,dest+20,actual.gpr[0],tails[k]);actual.gpr[dests[k]]+=24;
        actual.pc=actual.gpr[counters[k]] ? pcs[k]:pcs[k]+64;
        // With an exhausted budget the same original backedge returns here.
        if(memcmp(&actual,&expected,sizeof(actual)) || memcmp(a,b,sizeof(a))){expected.ram=a; // normalize before detailed compare below
            if(memcmp(&actual,&expected,sizeof(actual)) || memcmp(a,b,sizeof(a))){fprintf(stderr,"copy k%u n%u budget%lld pc%08X/%08X down%lld/%lld\n",k,n,budgets[budget],actual.pc,expected.pc,actual.downcount,expected.downcount);CHECK(0);}}
        cases++;
    }
    printf("[Matrix copy HLE] %u complete CPU/RAM cases, four register layouts and budget exits passed\n",cases);return 0;
}
void ref_vec_0(CPUState*);void ref_vec_1(CPUState*);
static int vec_contracts(void){
    u8 a[4096]={0},b[4096];u32 cases=0;g_fast_float_enabled=true;
    for(u32 sample=0;sample<256;sample++)for(u32 variant=0;variant<2;variant++)for(u32 route=0;route<2;route++)for(u32 alias=0;alias<3;alias++){
        CPUState seed={0};seed.ram=a;seed.ram_size=sizeof(a);seed.pc=variant ? 0x8028BF58:0x8028BEDC;seed.msr=0x2000u;seed.downcount=1024;seed.lr=0x81800000u;
        for(u32 r=0;r<32;r++){seed.fpr[r]=r/16.;seed.ps1[r]=-(double)r/8.;seed.gpr[r]=0xA5000000u+r;}
        seed.gpr[3]=0x80000100;seed.gpr[4]=0x80000200;seed.gpr[5]=alias==0 ? 0x80000300:alias==1 ? 0x80000200:0x80000104;
        for(u32 i=0;i<16;i++){float v=((int)((sample*17+i*11)%157)-78)/16.f;u32 bits;memcpy(&bits,&v,4);primary_write32(&seed,seed.gpr[3]+i*4,bits);}
        for(u32 i=0;i<3;i++){float v=((int)((sample*7+i*31)%91)-45)/8.f;u32 bits;memcpy(&bits,&v,4);primary_write32(&seed,seed.gpr[4]+i*4,bits);}
        memcpy(b,a,sizeof(a));CPUState expected=seed,actual=seed;expected.ram=b;if(variant)ref_vec_1(&expected);else ref_vec_0(&expected);
        if(route)actual.downcount-=31;CHECK(sdk_vec_transform(&actual,route!=0));expected.ram=a;
        CHECK(!memcmp(&actual,&expected,sizeof(actual)) && !memcmp(a,b,sizeof(a)));cases++;
    }
    printf("[Vector HLE] %u full CPU/RAM comparisons: two entries, overlaps, FPR/PS1 and budgets passed\n",cases);return 0;
}
int main(void){return floor_contracts() || copy_contracts() || vec_contracts();}
