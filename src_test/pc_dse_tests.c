#include "full_bits_reference.h"
#include <stdio.h>
#include <fenv.h>
#include <xmmintrin.h>
typedef void (*PCSnippet)(CPUState*);
extern PCSnippet pc_original[],pc_compact[];
extern unsigned pc_case_count;
static u64 probe_read(CPUState* cpu,u32 address,u8 size){cpu->srr0=cpu->pc;return (((u64)cpu->pc<<32)|address)^size;}
static void probe_write(CPUState* cpu,u32 address,u64 value,u8 size){cpu->srr0=cpu->pc^address;cpu->srr1=(u32)value^size;}
int main(void){
    u64 seed=0x123456789ABCDEF0ull,cases=0;
    u8 ram_a[4096],ram_b[4096];
    for(u32 fast=0;fast<2;fast++)for(u32 fp=0;fp<2;fp++)for(u32 mode=0;mode<4;mode++)for(u32 sample=0;sample<16;sample++)for(u32 i=0;i<pc_case_count;i++){
        CPUState a={0},b;g_fast_float_enabled=fast!=0;
        a.pc=0x81234560u;a.lr=0x81800000u;a.downcount=100000;a.msr=fp ? 0xA032u:0x8032u;
        a.ram=ram_a;a.ram_size=sizeof(ram_a);a.external_read=probe_read;a.external_write=probe_write;
        a.reserve_valid=(sample&1)!=0;a.reserve_addr=GC_RAM_BASE+512;
        memset(ram_a,0x5A,sizeof(ram_a));memcpy(ram_b,ram_a,sizeof(ram_a));
        a.fpscr=mode;
        for(u32 j=0;j<32;j++){
            seed=seed*6364136223846793005ull+1;a.gpr[j]=(u32)(seed>>32);
            if(sample<8)a.gpr[j]=GC_RAM_BASE+512+((j*67+sample*17)&511);
            a.fpr[j]=(s32)seed/127.0;a.ps1[j]=(s32)(seed>>32)/31.0;
        }
        b=a;b.ram=ram_b;ppc_fpscr_control_updated(&a);b.fpscr=a.fpscr;
        int rounding=fegetround();u32 csr=_mm_getcsr();feclearexcept(FE_ALL_EXCEPT);
        pc_original[i](&a);int flags=fetestexcept(FE_ALL_EXCEPT);
        fesetround(rounding);_mm_setcsr(csr);feclearexcept(FE_ALL_EXCEPT);pc_compact[i](&b);
        b.ram=ram_a;
        if(memcmp(&a,&b,sizeof(a)) || memcmp(ram_a,ram_b,sizeof(ram_a)) || flags!=fetestexcept(FE_ALL_EXCEPT)){
            fprintf(stderr,"PC DSE mismatch case=%u fp=%u fast=%u mode=%u sample=%u pc=%08X/%08X\n",i,fp,fast,mode,sample,a.pc,b.pc);return 1;
        }cases++;
    }
    printf("[PC DSE] %llu complete CPU/FPSCR/PC/exception comparisons across %u real generated snippets passed\n",cases,pc_case_count);return 0;
}
