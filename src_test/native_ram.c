#include "cpu/cpu.h"
// Only the CPU/main thread changes or reads this diagnostic switch.
bool g_native_ram_inline_enabled=false;
