#ifndef DVD_VFS_H
#define DVD_VFS_H

#include <stdbool.h>
#include "cpu/cpu.h"

// Initializes the DVD Virtual File System with the disc image
bool dvd_vfs_init(const char* ciso_path, CPUState* cpu);

// Loads the File System Table (FST) into guest RAM
bool dvd_vfs_load_fst(CPUState* cpu, u32 fst_ram_target);

// Direct byte read from virtual DVD image (handles CISO block translation)
bool dvd_vfs_read_bytes(u64 virtual_dvd_offset, void* dst, u32 length);

// DVD MMIO register read/write
u32 dvd_vfs_read_reg(CPUState* cpu, u32 reg_offset);
void dvd_vfs_write_reg(CPUState* cpu, u32 reg_offset, u32 value);

void dvd_vfs_shutdown(void);

#endif // DVD_VFS_H
