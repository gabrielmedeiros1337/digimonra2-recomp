#ifndef SDK_BOUNDS_H
#define SDK_BOUNDS_H
#include "cpu/cpu.h"
bool sdk_bounds_test(CPUState* cpu);
bool sdk_aabb_update(CPUState* cpu,bool entry_charged);
u64 sdk_aabb_calls(void);
void sdk_bounds_set_enabled(bool enabled);
u64 sdk_bounds_calls(void);
#endif
