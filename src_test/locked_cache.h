#ifndef HLE_LOCKED_CACHE_H
#define HLE_LOCKED_CACHE_H
#include "cpu/cpu.h"
bool locked_cache_address(u32 address,u8 size);
u64 locked_cache_read(u32 address,u8 size);
void locked_cache_write(u32 address,u64 value,u8 size);
bool locked_cache_spr_read(u16 spr,u32* value);
bool locked_cache_spr_write(CPUState* cpu,u16 spr,u32 value);
void locked_cache_reset(void);
void* locked_cache_pointer(u32 address,u32 size);
#endif
