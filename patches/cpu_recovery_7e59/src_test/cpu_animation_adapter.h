#ifndef CPU_ANIMATION_ADAPTER_H
#define CPU_ANIMATION_ADAPTER_H
#include "cpu/cpu.h"
#include "native_animation.h"
extern void platform_continue_cpu_slice(void);
static __forceinline bool animation_fp_available(CPUState* c,u32 cia){
    if((cia==0x80283A70u && native_quaternion(c,true)) ||
       ((cia==0x802524E4u || cia==0x80252848u || cia==0x802528CCu) && native_animation_channels(c))){
        platform_continue_cpu_slice();return false;
    }
    return ppc_fp_available_inline(c,cia);
}
#define ppc_fp_available_inline animation_fp_available
#endif
