#include "os_context.h"
#include <string.h>

static bool context_valid(CPUState* cpu,u32 address) {
    return address>=GC_RAM_BASE && address-GC_RAM_BASE<=cpu->ram_size-0x2C8;
}
void hle_os_save_fpu(CPUState* cpu,u32 context) {
    if(!context_valid(cpu,context))return;
    for(u32 i=0;i<32;i++) {
        u64 scalar;memcpy(&scalar,&cpu->fpr[i],8);
        mem_write64(cpu,context+0x90+i*8,scalar);
        /* psq_st with GQR0=0 writes two binary32 values, not a binary64 PS1. */
        float first=(float)cpu->fpr[i],second=(float)cpu->ps1[i];u32 a,b;
        memcpy(&a,&first,4);memcpy(&b,&second,4);
        mem_write32(cpu,context+0x1C8+i*8,a);
        mem_write32(cpu,context+0x1CC+i*8,b);
    }
    mem_write32(cpu,context+0x194,cpu->fpscr);
    mem_write16(cpu,context+0x1A2,(u16)(mem_read16(cpu,context+0x1A2)|1u));
}
void hle_os_load_fpu(CPUState* cpu,u32 context) {
    if(!context_valid(cpu,context) || !(mem_read16(cpu,context+0x1A2)&1u))return;
    for(u32 i=0;i<32;i++) {
        u64 scalar=mem_read64(cpu,context+0x90+i*8);memcpy(&cpu->fpr[i],&scalar,8);
        u32 bits=mem_read32(cpu,context+0x1CC+i*8);float second;memcpy(&second,&bits,4);cpu->ps1[i]=(double)second;
    }
    cpu->fpscr=mem_read32(cpu,context+0x194);ppc_fpscr_control_updated(cpu);
}
bool hle_os_fp_unavailable(CPUState* cpu) {
    if(!(cpu->exception&PPC_EXC_FP_UNAVAILABLE) && cpu->pc!=0x800u && cpu->pc!=0x80000800u)return false;
    u32 current=mem_read32(cpu,0x800000D4u),owner=mem_read32(cpu,0x800000D8u);
    if(context_valid(cpu,current)) {
        if(current!=owner) {
            if(context_valid(cpu,owner))hle_os_save_fpu(cpu,owner);
            hle_os_load_fpu(cpu,current);
            mem_write32(cpu,0x800000D8u,current);
        }
        mem_write32(cpu,current+0x19C,mem_read32(cpu,current+0x19C)|0x2000u);
    }
    cpu->exception&=~PPC_EXC_FP_UNAVAILABLE;
    cpu->msr=cpu->srr1|0x2000u;cpu->pc=cpu->srr0;
    return true;
}
