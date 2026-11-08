#ifndef DIGIMON_CPU_NATIVE_ADAPTER_H
#define DIGIMON_CPU_NATIVE_ADAPTER_H
#include "cpu/cpu.h"
#include <string.h>
#if defined(_MSC_VER) && defined(_M_X64)
#include <intrin.h>
#define NATIVE_RAM_INLINE static __forceinline
#else
#define NATIVE_RAM_INLINE static inline
#endif

extern bool g_native_ram_inline_enabled;

NATIVE_RAM_INLINE u8* native_ram_pointer(CPUState* cpu,u32 address) {
    // Physical addresses belong to external_read/external_write in this
    // runtime; preserve those callbacks instead of treating them as RAM here.
    u32 offset=(address&~0x40000000u)-GC_RAM_BASE;
    return cpu->ram && cpu->ram_size>=4 && offset<=cpu->ram_size-4 ? cpu->ram+offset:NULL;
}
NATIVE_RAM_INLINE u32 native_mem_read32(CPUState* cpu,u32 address) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(g_native_ram_inline_enabled) {
        u8* p=native_ram_pointer(cpu,address);
        if(p){u32 value;memcpy(&value,p,4);return _byteswap_ulong(value);}
    }
#endif
    return mem_read32(cpu,address);
}
NATIVE_RAM_INLINE void native_mem_write32(CPUState* cpu,u32 address,u32 value) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(g_native_ram_inline_enabled && !cpu->reserve_valid && !g_mem_write_journal) {
        u8* p=native_ram_pointer(cpu,address);
        if(p){value=_byteswap_ulong(value);memcpy(p,&value,4);return;}
    }
#endif
    mem_write32(cpu,address,value);
}

// The original declarations/fallback calls above are parsed before redirecting
// generated call sites. CPUState, guest addresses and the runtime ABI stay intact.
#ifndef NATIVE_RAM_NO_REDIRECT
#define mem_read32 native_mem_read32
#define mem_write32 native_mem_write32
#endif
#undef NATIVE_RAM_INLINE
#endif
