#ifndef PAIRED_SKINNING_H
#define PAIRED_SKINNING_H
#include "cpu/cpu.h"
bool paired_skinning_step(CPUState* cpu);
bool paired_skinning_blend_step(CPUState* cpu);
bool paired_skinning_blend_entry(CPUState* cpu);
u64 paired_skinning_blended(void);
bool paired_skinning_accumulate_step(CPUState* cpu);
bool paired_skinning_transform_step(CPUState* cpu);
bool paired_skinning_transform_entry(CPUState* cpu);
u64 paired_skinning_transformed(void);
bool paired_skinning_enabled(void);
u64 paired_skinning_accumulated(void);
bool paired_skinning_accumulate_available(void);
bool paired_skinning_environment_step(CPUState* cpu);
bool paired_skinning_environment_direct_step(CPUState* cpu);
u64 paired_skinning_environment_vertices(void);
u64 paired_skinning_environment_batches(void);
u64 paired_skinning_vertices(void);
void paired_skinning_set_enabled(bool enabled);
void paired_skinning_set_wide_domain(bool enabled);
bool paired_skinning_wide_domain(void);
#endif
