#ifndef NATIVE_COPY_H
#define NATIVE_COPY_H
#include "cpu/cpu.h"
void native_copy_tail(CPUState* cpu,u32 source,u32 dest,u32 counter);
u64 native_copy_bytes(void);
#endif
