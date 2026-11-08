#ifndef NATIVE_ANIMATION_H
#define NATIVE_ANIMATION_H
#include "cpu/cpu.h"
bool native_quaternion(CPUState* cpu,bool charged);
bool native_animation_channels(CPUState* cpu);
u64 native_quaternion_calls(void);
u64 native_animation_components(void);
#endif
