#ifndef DIGIMON_GENERATED_FLOAT_ADAPTER_H
#define DIGIMON_GENERATED_FLOAT_ADAPTER_H
// Included before selected generated chunks. The original header supplies
// the exact exceptional mappings; only subsequent calls use these wrappers.
#ifdef DIGIMON_FLOAT_BITS_REFERENCE
#include "float_bits_reference.h"
#else
#include "generated.h"
#endif
extern bool g_float_bits_enabled;
#if defined(_MSC_VER)
#define FLOAT_BITS_INLINE static __forceinline
#else
#define FLOAT_BITS_INLINE static inline
#endif
FLOAT_BITS_INLINE f64 platform_f32_from_bits(u32 bits) {
    u32 magnitude=bits&0x7FFFFFFFu;
    if(!g_float_bits_enabled || (magnitude && (magnitude<0x00800000u || magnitude>=0x7F800000u)))
        return dolrecomp_f32_from_bits(bits);
    u64 result=(u64)(bits&0x80000000u)<<32;
    if(magnitude)result|=((u64)magnitude+(896ull<<23))<<29;
    f64 value;memcpy(&value,&result,8);return value;
}
FLOAT_BITS_INLINE u32 platform_f32_to_bits(f64 value) {
    u64 bits;memcpy(&bits,&value,8);u32 exponent=(u32)((bits>>52)&0x7FFu);
    // This is the SDK store's bit extraction, not a host floating cast.
    // Its denormal window must keep the original shift-based mapping.
    if(!g_float_bits_enabled || (exponent>=874u && exponent<=896u && (bits&0x7FFFFFFFFFFFFFFFull)))
        return dolrecomp_f32_to_bits(value);
    return (u32)(((bits>>32)&0xC0000000u)|((bits>>29)&0x3FFFFFFFu));
}
#define dolrecomp_f32_from_bits platform_f32_from_bits
#define dolrecomp_f32_to_bits platform_f32_to_bits
#undef FLOAT_BITS_INLINE
#endif
