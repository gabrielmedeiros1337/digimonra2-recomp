#ifndef DOLRECOMP_RAM_DIRTY_H
#define DOLRECOMP_RAM_DIRTY_H
#include <stdint.h>
extern u8* g_ram_dirty_base;
extern u32 g_ram_dirty_size;
extern u64* g_ram_page_gen;
#ifdef _MSC_VER
#define DIRTY_INLINE static __forceinline
#else
#define DIRTY_INLINE static inline
#endif
/* Called by all managed scalar/PSQ/bulk writers, before their first store.
 * Private temporaries, locked cache and non-active RAM allocations are ignored;
 * the latter cannot use the generation cache. CPUState ABI is unchanged. */
DIRTY_INLINE void ppc_mark_host_write(const void* host,u32 bytes){
    uintptr_t offset=(uintptr_t)host-(uintptr_t)g_ram_dirty_base;
    if(bytes && offset<g_ram_dirty_size && bytes<=g_ram_dirty_size-offset){
        u32 first=(u32)offset>>12,last=((u32)offset+bytes-1u)>>12;
        for(u32 p=first;p<=last;p++)g_ram_page_gen[p]++;
    }
}
#undef DIRTY_INLINE
#endif
