#ifndef HLE_OS_CONTEXT_H
#define HLE_OS_CONTEXT_H
#include "cpu/cpu.h"
void hle_os_save_fpu(CPUState* cpu,u32 context);
void hle_os_load_fpu(CPUState* cpu,u32 context);
bool hle_os_fp_unavailable(CPUState* cpu);
#endif
