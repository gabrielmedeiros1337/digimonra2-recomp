#ifdef DIGIMON_FLOAT_BITS_REFERENCE
#include "float_bits_reference.h"
#else
#include "generated.h"
#endif
#ifdef _MSC_VER
#define COLD_NOINLINE __declspec(noinline)
#else
#define COLD_NOINLINE __attribute__((noinline))
#endif
// Cold exceptional mappings retain every payload/sign bit; no native cast of
// signaling NaNs or denormals, and no FPSCR or host FP side effects.
COLD_NOINLINE f64 hot_f32_special(u32 bits){return dolrecomp_f32_from_bits(bits);}
COLD_NOINLINE u32 hot_f32_denormal(f64 value){return dolrecomp_f32_to_bits(value);}
