#ifndef DIGIMON_CPU_BLOCK_ADAPTER_H
#define DIGIMON_CPU_BLOCK_ADAPTER_H
#ifdef DIGIMON_NATIVE_RAM_IN_BLOCK
#include "cpu_native_adapter.h"
#else
#include "cpu/cpu.h"
#endif
extern bool g_native_blocks_enabled;
bool platform_native_block(CPUState* cpu,u32 address,u32 charged);
#if defined(_MSC_VER)
#define BLOCK_INLINE static __forceinline
#else
#define BLOCK_INLINE static inline
#endif
BLOCK_INLINE bool block_fp_available(CPUState* cpu,u32 cia) {
    // cia is constant at each generated call site. All other sites retain
    // their original FP guard without an extra runtime branch.
    if(cia==0x8024BC48u || cia==0x8024C014u || cia==0x8024C244u || cia==0x8024C500u || cia==0x8024C508u || cia==0x8024C518u || cia==0x802B4D08u) {
        u32 charge=cia==0x8024BC48u ? 41u:cia==0x8024C014u ? 20u:cia==0x8024C244u ? 33u:cia==0x8024C500u ? 2u:cia==0x8024C508u ? 56u:cia==0x8024C518u ? 0u:65u;
        if(g_native_blocks_enabled && platform_native_block(cpu,cia,charge))return false;
    }
    return ppc_fp_available_inline(cpu,cia);
}
#define ppc_fp_available_inline block_fp_available
#undef BLOCK_INLINE
#endif
