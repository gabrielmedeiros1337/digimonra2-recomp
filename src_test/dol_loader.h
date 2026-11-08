#ifndef DOL_LOADER_H
#define DOL_LOADER_H

#include <stdbool.h>
#include <stddef.h>
#include "cpu/cpu.h"

typedef struct {
    u32 entry_point;
    u32 bss_addr;
    u32 bss_size;
    u32 sda_base;   // r13
    u32 sda2_base;  // r2
    u32 arena_lo;
    u32 arena_hi;
} DolMetadata;

bool dol_load(const char* dol_path, CPUState* cpu, DolMetadata* meta_out);

bool dol_load_memory(const void* data,size_t size,CPUState* cpu,DolMetadata* meta_out);

#endif // DOL_LOADER_H
