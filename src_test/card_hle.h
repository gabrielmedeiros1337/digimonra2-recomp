#ifndef CARD_HLE_H
#define CARD_HLE_H
#include "cpu/cpu.h"
int card_hle_dispatch(CPUState* cpu,u32 address);
void card_hle_reset(void);
#endif
