#ifndef SDK_MTX44_H
#define SDK_MTX44_H
#include "cpu/cpu.h"
bool sdk_mtx44_concat(CPUState* cpu);
bool sdk_mtx44_available(void);
void sdk_mtx44_set_enabled(bool enabled);
bool sdk_mtx44_enabled(void);
u64 sdk_mtx44_calls(void);
#endif
