#ifndef AX_HLE_H
#define AX_HLE_H
#include "cpu/cpu.h"
typedef struct { u64 lists, voices, ended; u32 peak; } AXHleStats;
const AXHleStats* ax_hle_stats(void);
bool ax_hle_load_coefficients(const char* path);
/* GameCube AX command lists and parameter blocks use big-endian 16-bit words. */
bool ax_hle_execute(CPUState* cpu, const u8* aram, u32 aram_size, u32 address, u32 words);
#endif
