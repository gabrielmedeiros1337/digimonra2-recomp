#ifndef CPU_BOUNDS_ADAPTER_H
#define CPU_BOUNDS_ADAPTER_H
#ifdef DIGIMON_NATIVE_RAM_IN_BOUNDS
#include "cpu_native_adapter.h"
#else
#include "cpu/cpu.h"
#endif
#include "sdk_bounds.h"
extern void platform_continue_cpu_slice(void);
#ifdef _MSC_VER
static __forceinline
#else
static inline
#endif
bool bounds_fp_available(CPUState* cpu,u32 cia){
    if((cia==0x80278E30u || cia==0x80278F10u) && sdk_bounds_test(cpu)){platform_continue_cpu_slice();return false;}
    if((cia==0x80276CC0u || cia==0x80276D6Cu) && sdk_aabb_update(cpu,true)){platform_continue_cpu_slice();return false;}
    return ppc_fp_available_inline(cpu,cia);
}
#define ppc_fp_available_inline bounds_fp_available
#endif
