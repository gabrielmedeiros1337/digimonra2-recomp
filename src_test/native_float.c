#include "cpu/cpu.h"
// Only the CPU/main thread reads or changes this host diagnostic flag.
bool g_float_bits_enabled=false;
#ifdef DIGIMON_FLOAT_BITS_COMPILED
const bool g_float_bits_available=true;
#else
const bool g_float_bits_available=false;
#endif
