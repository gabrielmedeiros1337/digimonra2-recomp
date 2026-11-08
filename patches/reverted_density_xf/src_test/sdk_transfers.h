#ifndef SDK_TRANSFERS_H
#define SDK_TRANSFERS_H
#include "cpu/cpu.h"
bool sdk_xf_load(CPUState* cpu);
bool sdk_lc_transfer(CPUState* cpu);
u64 sdk_xf_calls(void);
u64 sdk_lc_calls(void);
#endif
