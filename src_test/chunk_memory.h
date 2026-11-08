#ifndef DIGIMON_CHUNK_MEMORY_H
#define DIGIMON_CHUNK_MEMORY_H
#include "cpu/cpu.h"
#include <string.h>
#ifdef _MSC_VER
#include <intrin.h>
#define CHUNK_RESTRICT __restrict
#define CHUNK_INLINE static __forceinline
#define CHUNK_SWAP16 _byteswap_ushort
#define CHUNK_SWAP32 _byteswap_ulong
#define CHUNK_SWAP64 _byteswap_uint64
#else
#define CHUNK_RESTRICT __restrict__
#define CHUNK_INLINE static inline
#define CHUNK_SWAP16 __builtin_bswap16
#define CHUNK_SWAP32 __builtin_bswap32
#define CHUNK_SWAP64 __builtin_bswap64
#endif
#define CHUNK_SWAP8(x) (x)
/* RAM and CPUState allocations are disjoint. Restrict on the RAM base is
 * scoped to these leaf invocations, not across arbitrary guest/HLE calls.
 * The slow arm never accesses RAM through this base; callbacks may legally
 * access it through CPUState. Only that arm materializes the exact CIA. */
#define CHUNK_MEMORY(bits,type) \
type chunk_read##bits##_slow(CPUState* cpu,u32 address,u32 cia); \
void chunk_write##bits##_slow(CPUState* cpu,u32 address,type value,u32 cia); \
CHUNK_INLINE type chunk_read##bits(CPUState* CHUNK_RESTRICT cpu,const u8* CHUNK_RESTRICT ram_base,u32 ram_size,u32 address,u32 cia){ \
    u32 offset=address-GC_RAM_BASE; \
    if((u64)offset+sizeof(type)<=ram_size){type value;memcpy(&value,ram_base+offset,sizeof(value));return CHUNK_SWAP##bits(value);} \
    return chunk_read##bits##_slow(cpu,address,cia); \
} \
CHUNK_INLINE void chunk_write##bits(CPUState* CHUNK_RESTRICT cpu,u8* CHUNK_RESTRICT ram_base,u32 ram_size,u32 address,type value,u32 cia){ \
    u32 offset=address-GC_RAM_BASE; \
    if(!DOLRECOMP_RAM_TRACKING && (u64)offset+sizeof(type)<=ram_size && !cpu->reserve_valid && !g_mem_write_journal){ \
        value=CHUNK_SWAP##bits(value);memcpy(ram_base+offset,&value,sizeof(value));return; \
    } \
    chunk_write##bits##_slow(cpu,address,value,cia); \
}
CHUNK_MEMORY(8,u8)
CHUNK_MEMORY(16,u16)
CHUNK_MEMORY(32,u32)
CHUNK_MEMORY(64,u64)
#undef CHUNK_MEMORY
#undef CHUNK_INLINE
#endif
