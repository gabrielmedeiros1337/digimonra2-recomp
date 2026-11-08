#ifndef DIGIMON_PRIMARY_RAM_H
#define DIGIMON_PRIMARY_RAM_H
#include "cpu/cpu.h"
#include <string.h>
#ifdef _MSC_VER
#include <intrin.h>
#define PRIMARY_INLINE static __forceinline
#else
#define PRIMARY_INLINE static inline
#endif
PRIMARY_INLINE u16 primary_read16(CPUState* cpu,u32 address){
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+2<=cpu->ram_size){
        u16 value;memcpy(&value,cpu->ram+offset,2);
#ifdef _MSC_VER
        return _byteswap_ushort(value);
#else
        return __builtin_bswap16(value);
#endif
    }return mem_read16(cpu,address);
}
PRIMARY_INLINE u8 primary_read8(CPUState* cpu,u32 address){
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+1<=cpu->ram_size)return cpu->ram[offset];
    return mem_read8(cpu,address);
}
PRIMARY_INLINE void primary_write16(CPUState* cpu,u32 address,u16 value){
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+2<=cpu->ram_size && !cpu->reserve_valid && !g_mem_write_journal){
#ifdef _MSC_VER
        value=_byteswap_ushort(value);
#else
        value=__builtin_bswap16(value);
#endif
        ppc_mark_host_write(cpu->ram+offset,2);memcpy(cpu->ram+offset,&value,2);return;
    }mem_write16(cpu,address,value);
}
PRIMARY_INLINE void primary_write8(CPUState* cpu,u32 address,u8 value){
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+1<=cpu->ram_size && !cpu->reserve_valid && !g_mem_write_journal){
        ppc_mark_host_write(cpu->ram+offset,1);cpu->ram[offset]=value;return;
    }mem_write8(cpu,address,value);
}
/* Only the bounded cached main-RAM window. MMIO, physical aliases, MEM2,
 * locked cache and boundary crossings retain the complete runtime callback. */
PRIMARY_INLINE u32 primary_read32(CPUState* cpu,u32 address) {
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+4<=cpu->ram_size){
        u32 value;memcpy(&value,cpu->ram+offset,4);
#ifdef _MSC_VER
        return _byteswap_ulong(value);
#else
        return __builtin_bswap32(value);
#endif
    }
    return mem_read32(cpu,address);
}
PRIMARY_INLINE void primary_write32(CPUState* cpu,u32 address,u32 value) {
    u32 offset=address-GC_RAM_BASE;
    if((u64)offset+4<=cpu->ram_size && !cpu->reserve_valid && !g_mem_write_journal){
#ifdef _MSC_VER
        value=_byteswap_ulong(value);
#else
        value=__builtin_bswap32(value);
#endif
        ppc_mark_host_write(cpu->ram+offset,4);
        memcpy(cpu->ram+offset,&value,4);return;
    }
    mem_write32(cpu,address,value);
}
#ifndef PRIMARY_RAM_NO_REDIRECT
#define mem_read32 primary_read32
#define mem_write32 primary_write32
#define mem_read16 primary_read16
#define mem_write16 primary_write16
#define mem_read8 primary_read8
#define mem_write8 primary_write8
#endif
#undef PRIMARY_INLINE
#endif
