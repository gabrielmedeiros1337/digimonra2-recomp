#include "sdk_bounds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool g_bounds_oracle_stop;
void ref_bounds_min(CPUState* c);
void ref_bounds_max(CPUState* c);
#define CHECK(x) do{if(!(x)){fprintf(stderr,"bounds FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static void write_float(CPUState* c,u32 a,float f){u32 bits;memcpy(&bits,&f,4);mem_write32(c,a,bits);}
void ref_aabb_expand(CPUState* c);
void ref_aabb_union(CPUState* c);
static int aabb_contracts(void);
int main(void){
    CHECK(!aabb_contracts());
    const u32 size=0x310100u;u8* a=calloc(1,size);u8* b=calloc(1,size);CHECK(a && b);
    u32 cases=0,counts[]={0,1,2,6,16,0xFFFFFFFFu};g_fast_float_enabled=true;
    for(u32 sample=0;sample<96;sample++)for(u32 ci=0;ci<6;ci++)for(u32 upper=0;upper<2;upper++)for(u32 route=0;route<2;route++){
        s32 count=(s32)counts[ci];if(route && count<=0)continue;
        CPUState seed={0};seed.ram=a;seed.ram_size=size;seed.pc=upper ? 0x80278EF4u:0x80278E10u;
        seed.lr=0x81800000u;seed.downcount=4096;seed.msr=0x2000u;seed.fpscr=0x1F000u;
        seed.xer=(sample&1u)<<31;seed.cr=0x13579BDFu;
        for(u32 r=0;r<32;r++){seed.gpr[r]=0xA5500000u+r*19;seed.fpr[r]=r/8.0;seed.ps1[r]=-(double)r/16.0;}
        seed.gpr[1]=0x80003F00u;seed.gpr[3]=0x80001000u;seed.gpr[4]=0x80001400u;
        memset(a+0x1000,0,0x3000);mem_write32(&seed,0x80001100u,(u32)count);
        for(u32 j=0;j<3;j++){float low=((int)((sample+j)%13)-6)/8.0f;write_float(&seed,0x80001400u+j*4,low);write_float(&seed,0x8000140Cu+j*4,low+1.5f);}
        for(s32 n=0;n<count;n++)for(u32 j=0;j<4;j++){
            float v=j==3 ? ((int)(sample%7)-3)*2.0f:((int)((sample+n*3+j)%11)-5)/4.0f;
            write_float(&seed,0x80001000u+n*16+j*4,v);
        }
        memcpy(b,a,size);CPUState expected=seed,actual=seed;expected.ram=b;
        g_bounds_oracle_stop=false;if(upper)ref_bounds_max(&expected);else ref_bounds_min(&expected);
        if(route){g_bounds_oracle_stop=true;if(upper)ref_bounds_max(&actual);else ref_bounds_min(&actual);g_bounds_oracle_stop=false;}
        CHECK(sdk_bounds_test(&actual));expected.ram=a;
        if(memcmp(&actual,&expected,sizeof(actual)) || memcmp(a,b,size)){
            fprintf(stderr,"sample=%u count=%d upper=%u route=%u charge=%lld/%lld cr=%08X/%08X fpscr=%08X/%08X\n",sample,count,upper,route,actual.downcount,expected.downcount,actual.cr,expected.cr,actual.fpscr,expected.fpscr);
            for(u32 r=0;r<32;r++)if(actual.gpr[r]!=expected.gpr[r])fprintf(stderr,"r%u %08X/%08X\n",r,actual.gpr[r],expected.gpr[r]);
            CHECK(0);
        }cases++;
    }
    free(a);free(b);g_fast_float_enabled=false;
    printf("[Bounds HLE] %u full CPU/RAM comparisons; two plane/AABB functions, entry + original prologue continuation, all exits passed\n",cases);return 0;
}

static int aabb_contracts(void){
    CPUState seed={0};u8 a[8192]={0},b[8192]={0};u32 cases=0;
    const u32 values[]={0,0x80000000u,0x3F800000u,0xBF800000u,0x40800000u,0xC1000000u};
    const u32 dests[]={0x80001000u,0x80001100u,0x80001104u,0x80001200u,0x80001204u};
    g_fast_float_enabled=true;
    for(u32 sample=0;sample<128;sample++)for(u32 unite=0;unite<2;unite++)for(u32 route=0;route<2;route++)for(u32 alias=0;alias<5;alias++){
        seed.ram=a;seed.ram_size=sizeof(a);seed.msr=0x2000u;seed.lr=0x81800000u;seed.pc=unite ? 0x80276D6Cu:0x80276CC0u;
        seed.downcount=100;seed.cr=0x13579BDFu;seed.fpscr=0x1F000u;
        for(u32 r=0;r<32;r++){seed.gpr[r]=0x80000000u+r*4;seed.fpr[r]=r/4.;seed.ps1[r]=-(double)r/8.;}
        seed.gpr[3]=dests[alias];seed.gpr[4]=0x80001100u;seed.gpr[5]=0x80001200u;
        for(u32 i=0;i<160;i++)mem_write32(&seed,0x80001000u+i*4,values[(sample+i*7)%6]);
        memcpy(b,a,sizeof(a));CPUState actual=seed,expected=seed;expected.ram=b;
        if(unite)ref_aabb_union(&expected);else ref_aabb_expand(&expected);
        if(route)actual.downcount-=5;
        CHECK(sdk_aabb_update(&actual,route!=0));expected.ram=a;
        if(memcmp(&actual,&expected,sizeof(actual)) || memcmp(a,b,sizeof(a))){
            fprintf(stderr,"aabb sample=%u union=%u route=%u alias=%u budget=%lld/%lld cr=%08X/%08X\n",sample,unite,route,alias,actual.downcount,expected.downcount,actual.cr,expected.cr);CHECK(0);
        }cases++;
    }
    g_fast_float_enabled=false;printf("[AABB HLE] %u full CPU/RAM comparisons, signed zeros, overlapping inputs, entry/intrachunk budgets passed\n",cases);return 0;
}
