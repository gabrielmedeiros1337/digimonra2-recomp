#include "sdk_mtx44.h"
#include "cpu/ps_fast.h"
#include <stdint.h>
static bool s_enabled=true;
static u64 s_calls;
void sdk_mtx44_set_enabled(bool enabled){s_enabled=enabled;}
bool sdk_mtx44_enabled(void){return s_enabled;}
u64 sdk_mtx44_calls(void){return s_calls;}
bool sdk_mtx44_available(void) {
#if defined(_MSC_VER) && defined(_M_X64)
    return host_fma_available();
#else
    return false;
#endif
}
#if defined(_MSC_VER) && defined(_M_X64)
static bool overlaps(const u8* a,const u8* b){return (uintptr_t)a-(uintptr_t)b<64u || (uintptr_t)b-(uintptr_t)a<64u;}
static bool load_matrix(const u8* p,f32 values[16]) {
    for(u32 i=0;i<16;i++) {
        u32 bits=psq_read_be(p+i*4u,4),magnitude=bits&0x7FFFFFFFu;
        // Inputs are zero or normal float32, bounded to avoid overflow.
        // Each arithmetic stage is preflighted below before guest writes.
        if(magnitude && (magnitude<0x00800000u || magnitude>0x47800000u))return false;
        memcpy(values+i,&bits,4);
    }
    return true;
}
static __forceinline bool regular(__m128 v) {
    __m128i magnitude=_mm_and_si128(_mm_castps_si128(v),_mm_set1_epi32(0x7FFFFFFF));
    __m128i zero=_mm_cmpeq_epi32(magnitude,_mm_setzero_si128());
    __m128i small=_mm_cmplt_epi32(magnitude,_mm_set1_epi32(0x00800000));
    return _mm_movemask_ps(_mm_castsi128_ps(_mm_andnot_si128(zero,small)))==0;
}
static __forceinline void pair(CPUState* c,u32 r,__m128 value) {
    __m128d d=_mm_cvtps_pd(value);c->fpr[r]=_mm_cvtsd_f64(d);c->ps1[r]=_mm_cvtsd_f64(_mm_unpackhi_pd(d,d));
}
static __forceinline __m128 high(__m128 value){return _mm_shuffle_ps(value,value,_MM_SHUFFLE(3,2,3,2));}
#endif
bool sdk_mtx44_concat(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(!s_enabled || c->pc!=0x802B4D08u || !host_fma_available() || c->exception || !(c->msr&0x2000u) ||
       !psq_direct_enabled(c,false) || (c->gqr[0]&0x70007u) || (c->fpscr&0xF8u) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal || ((c->gpr[3]|c->gpr[4]|c->gpr[5])&3u))return false;
    u8* a=psq_direct_pointer(c,c->gpr[3],64);u8* b=psq_direct_pointer(c,c->gpr[4],64);u8* out=psq_direct_pointer(c,c->gpr[5],64);
    if(!a || !b || !out || overlaps(out,a) || overlaps(out,b))return false;
    f32 av[16],bv[16];if(!load_matrix(a,av) || !load_matrix(b,bv))return false;
    __m128 rows[4],right[4];for(u32 i=0;i<4;i++)right[i]=_mm_loadu_ps(bv+i*4);
    u32 saved_csr=_mm_getcsr();
    for(u32 i=0;i<4;i++) {
        __m128 value=_mm_mul_ps(right[0],_mm_set1_ps(av[i*4]));
        if(!regular(value))goto declined;
        value=_mm_fmadd_ps(right[1],_mm_set1_ps(av[i*4+1]),value);
        if(!regular(value))goto declined;
        value=_mm_fmadd_ps(right[2],_mm_set1_ps(av[i*4+2]),value);
        if(!regular(value))goto declined;
        rows[i]=_mm_fmadd_ps(right[3],_mm_set1_ps(av[i*4+3]),value);
        if(!regular(rows[i]))goto declined;
    }
    c->downcount-=65;
    for(u32 i=0;i<4;i++) {
        u32 bits[4];_mm_storeu_si128((__m128i*)bits,_mm_castps_si128(rows[i]));
        for(u32 j=0;j<4;j++)psq_write_be(out+(i*4+j)*4,bits[j],4);
    }
    // Exact volatile FPR/PS1 values left by the SDK, not only its output RAM.
    __m128 last_left=_mm_loadu_ps(av+12);pair(c,0,last_left);pair(c,1,high(last_left));
    for(u32 i=0;i<4;i++){pair(c,2+i,high(right[i]));pair(c,6+i*2,rows[i]);pair(c,7+i*2,high(rows[i]));}
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(high(rows[3]))<<12);
    c->pc=c->lr&~3u;s_calls++;return true;
declined:
    // Subnormal accumulators can select the runtime's generic FP path.
    // Restore host status too: the original resumes without preflight effects.
    _mm_setcsr(saved_csr);return false;
#else
    (void)c;return false;
#endif
}
