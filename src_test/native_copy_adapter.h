#ifndef NATIVE_COPY_ADAPTER_H
#define NATIVE_COPY_ADAPTER_H
#include "primary_ram.h"
#include "native_copy.h"
#ifdef _MSC_VER
#define COPY_INLINE static __forceinline
#else
#define COPY_INLINE static inline
#endif
COPY_INLINE void copy_matrix_store(CPUState* c,u32 address,u32 value,u32 cia){
    primary_write32(c,address,value);
    // cia is the constant PC immediately before each generated store. Other
    // stores retain only primary_write32 after constant folding.
    if(cia==0x8023DA80u || cia==0x8023DB24u || cia==0x8024D49Cu)native_copy_tail(c,11,9,10);
    else if(cia==0x8023DCF8u || cia==0x8023DE48u)native_copy_tail(c,8,9,11);
    else if(cia==0x8023DD60u || cia==0x8023DEB4u)native_copy_tail(c,10,11,7);
    else if(cia==0x8024B16Cu || cia==0x8024B26Cu)native_copy_tail(c,9,11,10);
    else if(cia==0x8024D960u)native_copy_tail(c,6,9,10);
}
#undef mem_write32
#define mem_write32(cpu,address,value) copy_matrix_store(cpu,address,value,(cpu)->pc)
#undef COPY_INLINE
#endif
