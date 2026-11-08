#ifndef CPU_MATH_ADAPTER_H
#define CPU_MATH_ADAPTER_H
#include "cpu/cpu.h"
#include "sdk_floor.h"
#include "sdk_vec.h"
extern void platform_continue_cpu_slice(void);
#ifdef _MSC_VER
static __forceinline
#else
static inline
#endif
bool math_fp_available(CPUState* c,u32 cia){
    if(cia==0x8029D88Cu && sdk_floor(c,true)){platform_continue_cpu_slice();return false;}
    if((cia==0x8028BEDCu || cia==0x8028BF58u) && sdk_vec_transform(c,true)){platform_continue_cpu_slice();return false;}
    return ppc_fp_available_inline(c,cia);
}
#define ppc_fp_available_inline math_fp_available
#endif
