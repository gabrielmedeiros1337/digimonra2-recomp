#ifndef CPU_XF_ADAPTER_H
#define CPU_XF_ADAPTER_H
#include "cpu/cpu.h"
#include "sdk_transfers.h"
extern void platform_continue_cpu_slice(void);
static __forceinline bool xf_fp_available(CPUState* c,u32 cia){
    if((cia==0x802D4F14u || cia==0x802D4F4Cu) && sdk_xf_load(c)){
        platform_continue_cpu_slice();return false;
    }
    return ppc_fp_available_inline(c,cia);
}
#define ppc_fp_available_inline xf_fp_available
#endif
