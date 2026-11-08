#include "sdk_mtx44.h"
#include "locked_cache.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if defined(_MSC_VER) && defined(_M_X64)
#include <xmmintrin.h>
#endif
extern void test_mtx44_original(CPUState*);
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static u64 read_lc(CPUState* c,u32 a,u8 n){(void)c;return locked_cache_read(a,n);}
static void write_lc(CPUState* c,u32 a,u64 v,u8 n){(void)c;locked_cache_write(a,v,n);}
static void* pointer_lc(CPUState* c,u32 a,u32 n){(void)c;return locked_cache_pointer(a,n);}
static void journal(u32 a,u32 n,void* user){(void)a;(void)n;(void)user;}
static void cache(CPUState* c,u8 op,u32 a,u32 pc){(void)c;(void)op;(void)a;(void)pc;}
static u32 bits(f32 value){u32 result;memcpy(&result,&value,4);return result;}
int main(void) {
    u8 memory[2048],reference[2048],initial_lc[16384],expected_lc[16384];u32 cases=0,seed_random=0x13245678;
    const s64 budgets[]={-255,0,768,4096};bool available=sdk_mtx44_available();
    for(u32 pattern=0;pattern<8;pattern++)for(u32 ni=0;ni<2;ni++)for(u32 rounding=0;rounding<4;rounding++)
    for(u32 locations=0;locations<8;locations++)for(u32 alias=0;alias<2;alias++)for(u32 bi=0;bi<4;bi++) {
        memset(memory,0xA5,sizeof(memory));locked_cache_reset();CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);
        seed.pc=0x802B4D08u;seed.lr=0x81800003u;seed.msr=0x2000;seed.hid2=0xA0000000u;seed.downcount=budgets[bi];
        seed.fpscr=0x82060000u|rounding|(ni ? 4u:0u);seed.ctr=0x3179u;seed.cr=0x13579BDFu;seed.xer=0x2468ACE0u;
        seed.external_read=read_lc;seed.external_write=write_lc;seed.external_pointer=pointer_lc;
        for(u32 r=0;r<32;r++){seed.gpr[r]=r*37u;seed.fpr[r]=r+0.125;seed.ps1[r]=-(r+0.25);}
        for(u32 i=0;i<3;i++)seed.gpr[3+i]=((locations&(1u<<i)) ? 0xE0000000u:alias ? 0xC0000000u:0x80000000u)+(i+1)*0x100u+(alias ? 4u:0u);
        f32 a[16]={0},b[16]={0};
        for(u32 i=0;i<16;i++) {
            if(pattern==0)a[i]=b[i]=i%5==0 ? 1.0f:0.0f;
            if(pattern==1){seed_random=seed_random*1664525u+1013904223u;a[i]=((int)(seed_random>>24)-128)/16.0f;seed_random=seed_random*1664525u+1013904223u;b[i]=((int)(seed_random>>24)-128)/16.0f;}
            if(pattern==2){a[i]=(i&1 ? -1:1)*0x1.000002p-40f;b[i]=(i&2 ? -1:1)*0x1.000004p-40f;}
            if(pattern==3){a[i]=(i&1 ? -1:1)*65536.0f;b[i]=(i&2 ? -1:1)*65536.0f;}
            if(pattern==4){a[i]=i&1 ? -0.0f:0.0f;b[i]=i&2 ? -0.0f:0.0f;}
        }
        if(pattern==5){a[0]=b[0]=b[4]=0x1.000002p-40f;a[1]=-0x1.000002p-40f;}
        if(pattern==6)for(u32 i=0;i<16;i++){a[i]=(i&1 ? -1:1)*0x1.000002p-70f;b[i]=i%5==0 ? 1.0f:0.0f;}
        if(pattern==7)for(u32 i=0;i<16;i++){a[i]=0x1p-126f;b[i]=0.5f;}
        // One pattern also covers read-only A==B; output never aliases input.
        if(pattern==4)seed.gpr[4]=seed.gpr[3];
        for(u32 i=0;i<16;i++){mem_write32(&seed,seed.gpr[3]+i*4,bits(a[i]));if(pattern!=4)mem_write32(&seed,seed.gpr[4]+i*4,bits(b[i]));}
        memcpy(initial_lc,locked_cache_pointer(0xE0000000u,sizeof(initial_lc)),sizeof(initial_lc));
        memcpy(reference,memory,sizeof(memory));CPUState expected=seed;expected.ram=reference;
        ppc_fpscr_control_updated(&expected);test_mtx44_original(&expected);
        CHECK(!expected.exception && expected.pc==0x81800000u);
        memcpy(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc));
        locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(initial_lc)),initial_lc,sizeof(initial_lc));
        CPUState actual=seed;ppc_fpscr_control_updated(&actual);u64 before=sdk_mtx44_calls();
        if(!sdk_mtx44_concat(&actual))test_mtx44_original(&actual);
        CHECK(sdk_mtx44_calls()==before+(available && (pattern!=7 || ni) ? 1u:0u));
        CHECK(!memcmp(memory,reference,sizeof(memory)));
        CHECK(!memcmp(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc)));
        expected.ram=actual.ram;
        if(memcmp(&actual,&expected,sizeof(actual))){fprintf(stderr,"MTX44 mismatch pattern=%u ni=%u rn=%u loc=%u alias=%u budget=%lld\n",pattern,ni,rounding,locations,alias,(long long)budgets[bi]);for(u32 r=0;r<14;r++)if(actual.fpr[r]!=expected.fpr[r] || actual.ps1[r]!=expected.ps1[r])fprintf(stderr,"f%u %.17g/%.17g ps1 %.17g/%.17g\n",r,actual.fpr[r],expected.fpr[r],actual.ps1[r],expected.ps1[r]);}
        CHECK(!memcmp(&actual,&expected,sizeof(actual)));
        if(pattern==5 && rounding==0)CHECK(mem_read32(&actual,actual.gpr[5])==0x80800000u);cases++;
    }
    // Reject unusual states without changing any guest byte or CPU field.
    for(u32 mode=0;mode<18;mode++) {
        memset(memory,0,sizeof(memory));CPUState c={0};c.ram=memory;c.ram_size=sizeof(memory);c.pc=0x802B4D08u;c.lr=0x81800000u;
        c.msr=0x2000;c.hid2=0xA0000000;c.gpr[3]=0x80000100u;c.gpr[4]=0x80000200u;c.gpr[5]=0x80000300u;
        for(u32 i=0;i<16;i++){mem_write32(&c,c.gpr[3]+i*4,bits(1.0f));mem_write32(&c,c.gpr[4]+i*4,bits(1.0f));}
        if(mode==0)c.gpr[5]=c.gpr[3];if(mode==1)c.gpr[5]=c.gpr[4]+4;
        if(mode==2)c.gpr[3]+=2;if(mode==3)c.gpr[5]=0x800007E0u;
        if(mode==4)mem_write32(&c,c.gpr[3],1u);if(mode==5)mem_write32(&c,c.gpr[3],bits(0x1p17f));
        if(mode==6)mem_write32(&c,c.gpr[3],0x7FC01234u);if(mode==7)mem_write32(&c,c.gpr[3],0x7F800000u);
        if(mode==8)c.gqr[0]=7;if(mode==9)c.msr=0;if(mode==10)c.reserve_valid=true;if(mode==11)c.cache_control=cache;
        if(mode==12)c.exception=1;if(mode==13)c.hid2=0;if(mode==14)c.fpscr=8;
        if(mode==15)ppc_set_mem_write_journal(journal,NULL);if(mode==16)sdk_mtx44_set_enabled(false);
        if(mode==17){mem_write32(&c,c.gpr[3],bits(0x1p-126f));mem_write32(&c,c.gpr[4],bits(0.5f));}
        ppc_fpscr_control_updated(&c);
#if defined(_MSC_VER) && defined(_M_X64)
        u32 csr=_mm_getcsr();
#endif
        CPUState before=c;memcpy(reference,memory,sizeof(memory));CHECK(!sdk_mtx44_concat(&c));
#if defined(_MSC_VER) && defined(_M_X64)
        CHECK(_mm_getcsr()==csr);
#endif
        CHECK(!memcmp(&before,&c,sizeof(c)) && !memcmp(reference,memory,sizeof(memory)));
        ppc_set_mem_write_journal(NULL,NULL);sdk_mtx44_set_enabled(true);
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[PSMTX44Concat] %u full CPU/RAM/LC/budget cases, minimum-normal cancellation, alias/IEEE guards + 18 declines passed; FMA=%u\n",cases,available);return 0;
}
