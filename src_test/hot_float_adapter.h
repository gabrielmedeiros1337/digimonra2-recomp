#ifndef HOT_FLOAT_ADAPTER_H
#define HOT_FLOAT_ADAPTER_H
#ifdef DIGIMON_FLOAT_BITS_REFERENCE
#include "float_bits_reference.h"
#else
#include "generated.h"
#endif
#include <math.h>
f64 hot_f32_special(u32 bits);
u32 hot_f32_denormal(f64 value);
#ifdef _MSC_VER
#define HOT_INLINE static __forceinline
#else
#define HOT_INLINE static inline
#endif
HOT_INLINE f64 hot_f32_from_bits(u32 bits){
    u32 magnitude=bits&0x7FFFFFFFu;u64 wide=(u64)(bits&0x80000000u)<<32;
    if(magnitude){u32 exponent=magnitude&0x7F800000u;
        if(!exponent || exponent==0x7F800000u)return hot_f32_special(bits);
        wide|=((u64)magnitude+(896ull<<23))<<29;}
    f64 value;memcpy(&value,&wide,8);return value;
}
HOT_INLINE u32 hot_f32_to_bits(f64 value){
    u64 bits;memcpy(&bits,&value,8);u32 exp=(u32)((bits>>52)&2047u);
    if(exp>=874 && exp<=896 && (bits&0x7FFFFFFFFFFFFFFFull))return hot_f32_denormal(value);
    return (u32)(((bits>>32)&0xC0000000u)|((bits>>29)&0x3FFFFFFFu));
}
HOT_INLINE f64 hot_f64_from_bits(u64 bits){f64 value;memcpy(&value,&bits,8);return value;}
HOT_INLINE u64 hot_f64_to_bits(f64 value){u64 bits;memcpy(&bits,&value,8);return bits;}
#define HOT_SCALAR(name,op,single) \
HOT_INLINE void hot_##name(CPUState* c,u8 d,u8 a,u8 b){ \
    if(!g_fast_float_enabled){name(c,d,a,b);return;} \
    f64 v=c->fpr[a] op c->fpr[b]; \
    if(single)c->fpr[d]=c->ps1[d]=(f64)(f32)v;else c->fpr[d]=v; \
}
HOT_SCALAR(ppc_fadds,+,1)
HOT_SCALAR(ppc_fsubs,-,1)
HOT_SCALAR(ppc_fmuls,*,1)
HOT_SCALAR(ppc_fdivs,/,1)
HOT_SCALAR(ppc_fadd,+,0)
HOT_SCALAR(ppc_fsub,-,0)
HOT_SCALAR(ppc_fmul,*,0)
HOT_SCALAR(ppc_fdiv,/,0)
#undef HOT_SCALAR
HOT_INLINE void hot_frsp(CPUState* c,u8 d,u8 b){
    if(!g_fast_float_enabled){ppc_frsp(c,d,b);return;}c->fpr[d]=c->ps1[d]=(f64)(f32)c->fpr[b];
}
HOT_INLINE bool hot_fma(CPUState* c,f64 a,f64 x,f64 b,bool single,bool subtract,bool negative,f64* output){
    if(!g_fast_float_enabled)return ppc_fma(c,a,x,b,single,subtract,negative,output);
    f64 value=single ? (f64)fmaf((f32)a,(f32)x,subtract ? -(f32)b:(f32)b):fma(a,x,subtract ? -b:b);
    *output=negative ? -value:value;return true;
}
HOT_INLINE bool hot_psq_load(CPUState* c,u8 d,u32 ea,bool w,u8 gqr,bool indexed,u32 cia){
    u32 offset=ea&0x3FFFFFFFu,bytes=w ? 4:8;
    if((ea&0x80000000u) && !(ea&3u) && offset<=c->ram_size && bytes<=c->ram_size-offset &&
       !((c->gqr[gqr&7u]>>16)&7u) && psq_direct_enabled(c,indexed)){
        u32 first=psq_read_be(c->ram+offset,4),second=w ? 0:psq_read_be(c->ram+offset+4,4);
        u32 a=first&0x7FFFFFFFu,b=second&0x7FFFFFFFu;
        if((!a || (a>=0x00800000u && a<0x7F800000u)) && (!b || (b>=0x00800000u && b<0x7F800000u))){
            c->fpr[d]=hot_f32_from_bits(first);c->ps1[d]=w ? 1.:hot_f32_from_bits(second);return true;
        }
    }
    return ppc_psq_load_inline(c,d,ea,w,gqr,indexed,cia);
}
#ifndef HOT_FLOAT_NO_REDIRECT
#define dolrecomp_f32_from_bits hot_f32_from_bits
#define dolrecomp_f32_to_bits hot_f32_to_bits
#define dolrecomp_f64_from_bits hot_f64_from_bits
#define dolrecomp_f64_to_bits hot_f64_to_bits
#define dolrecomp_ps_from_bits hot_f32_from_bits
#define dolrecomp_ps_to_bits hot_f32_to_bits
#define ppc_fadds hot_ppc_fadds
#define ppc_fsubs hot_ppc_fsubs
#define ppc_fmuls hot_ppc_fmuls
#define ppc_fdivs hot_ppc_fdivs
#define ppc_fadd hot_ppc_fadd
#define ppc_fsub hot_ppc_fsub
#define ppc_fmul hot_ppc_fmul
#define ppc_fdiv hot_ppc_fdiv
#define ppc_frsp hot_frsp
#define ppc_fma hot_fma
#define ppc_psq_load_inline hot_psq_load
#endif
#undef HOT_INLINE
#endif
