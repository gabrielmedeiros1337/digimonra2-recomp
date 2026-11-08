#ifndef HLE_CALLBACKS_H
#define HLE_CALLBACKS_H
#include "cpu/cpu.h"
bool hle_callbacks_has_space(void);
bool hle_callbacks_busy(void);
bool hle_callbacks_enqueue(u32 callback, u32 result, u32 argument);
void hle_callbacks_pump(CPUState* cpu);
bool hle_callbacks_return(CPUState* cpu, u32 address);
#endif
