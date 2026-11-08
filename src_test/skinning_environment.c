#include "paired_skinning.h"
#include "cpu/ps_fast.h"
extern void platform_continue_cpu_slice(void);
extern void func_8024B4C0(CPUState*);
static u64 s_environment_vertices,s_environment_batches;
u64 paired_skinning_environment_vertices(void){return s_environment_vertices;}
u64 paired_skinning_environment_batches(void){return s_environment_batches;}
#if defined(_MSC_VER) && defined(_M_X64)
static __forceinline __m128 env_pair(const CPUState* c,u32 r){return _mm_cvtpd_ps(_mm_set_pd(c->ps1[r],c->fpr[r]));}
static __forceinline void env_write(CPUState* c,u32 r,__m128 v){__m128d d=_mm_cvtps_pd(v);c->fpr[r]=_mm_cvtsd_f64(d);c->ps1[r]=_mm_cvtsd_f64(_mm_unpackhi_pd(d,d));}
static __forceinline bool env_regular(__m128 v) {
    __m128i bits=_mm_castps_si128(v),zero=_mm_setzero_si128(),mask=_mm_set1_epi32(0x7F800000);
    __m128i exp=_mm_and_si128(bits,mask),frac=_mm_and_si128(bits,_mm_set1_epi32(0x7FFFFF));
    __m128i bad=_mm_or_si128(_mm_cmpeq_epi32(exp,mask),_mm_andnot_si128(_mm_cmpeq_epi32(frac,zero),_mm_cmpeq_epi32(exp,zero)));
    return (_mm_movemask_ps(_mm_castsi128_ps(bad))&3)==0;
}
static __forceinline __m128 env_sum_xy(__m128 a,__m128 b) {
    __m128 x=_mm_add_ss(a,_mm_shuffle_ps(a,a,85)),y=_mm_add_ss(b,_mm_shuffle_ps(b,b,85));
    return _mm_unpacklo_ps(x,y);
}
static __forceinline f64 env_rsqrt(f32 value) {
    // Preserve Gekko's estimate table and 25-bit multiplier rounding. A
    // binary32 reciprocal square root would lose these extra mantissa bits.
    f64 estimate=ppc_approx_rsqrt((f64)value);
    if(g_fast_float_enabled)return estimate;
    u64 bits;memcpy(&bits,&estimate,8);
    bits=(bits&0xFFFFFFFFF8000000ull)+(bits&0x8000000ull);memcpy(&estimate,&bits,8);return estimate;
}
static __forceinline __m128 env_normalize(__m128 value,f64 a,f64 b) {
    // The fast paired-single runtime first narrows the rsqrt multiplier to
    // binary32. The strict path multiplies by the 25-bit Gekko operand.
    if(g_fast_float_enabled)return _mm_mul_ps(value,_mm_setr_ps((f32)a,(f32)b,0,0));
    return _mm_cvtpd_ps(_mm_mul_pd(_mm_cvtps_pd(value),_mm_set_pd(b,a)));
}
static __forceinline __m128 env_load_s16(const u8* p,bool w,f32 factor) {
    return _mm_setr_ps((f32)(s16)psq_read_be(p,2)*factor,w ? 1.0f:(f32)(s16)psq_read_be(p+2,2)*factor,0,0);
}
static __forceinline bool environment_math(__m128 v[22]) {
#define L0(x) _mm_shuffle_ps(x,x,0)
#define L1(x) _mm_shuffle_ps(x,x,85)
    v[10]=_mm_mul_ps(v[0],v[0]);v[12]=_mm_mul_ps(v[2],v[2]);v[11]=_mm_mul_ps(v[1],v[1]);
    v[13]=_mm_mul_ps(v[3],v[3]);v[15]=_mm_mul_ps(v[5],v[5]);v[14]=_mm_mul_ps(v[4],v[4]);
    for(u32 r=10;r<16;r++)if(!env_regular(v[r]))return false;
    v[6]=_mm_add_ps(env_sum_xy(v[10],v[12]),v[11]);
    v[7]=_mm_add_ps(env_sum_xy(v[13],v[15]),v[14]);
    if((!env_regular(v[6]) || !env_regular(v[7])))return false;
    f32 len_p[4],len_n[4];_mm_storeu_ps(len_p,v[6]);_mm_storeu_ps(len_n,v[7]);
    if(!(len_p[0]>0 && len_p[1]>0 && len_n[0]>0 && len_n[1]>0))return false;
    f64 p0=env_rsqrt(len_p[0]),p1=env_rsqrt(len_p[1]),n0=env_rsqrt(len_n[0]),n1=env_rsqrt(len_n[1]);
    v[0]=env_normalize(v[0],p0,p0);v[1]=env_normalize(v[1],p0,p1);v[2]=env_normalize(v[2],p1,p1);
    v[3]=env_normalize(v[3],n0,n0);v[4]=env_normalize(v[4],n0,n1);v[5]=env_normalize(v[5],n1,n1);
    for(u32 r=0;r<6;r++)if(!env_regular(v[r]))return false;
    v[10]=_mm_mul_ps(v[0],v[3]);v[12]=_mm_mul_ps(v[1],v[4]);v[11]=_mm_mul_ps(v[2],v[5]);
    for(u32 r=10;r<13;r++)if(!env_regular(v[r]))return false;
    __m128 xy=env_sum_xy(v[10],v[11]);if(!env_regular(xy))return false;
    v[6]=_mm_add_ps(xy,v[12]);if(!env_regular(v[6]))return false;
    v[13]=_mm_mul_ps(v[21],L0(v[6]));v[15]=_mm_mul_ps(v[21],L1(v[6]));v[14]=_mm_mul_ps(v[21],v[6]);
    for(u32 r=13;r<16;r++)if(!env_regular(v[r]))return false;
    __m128 sign=_mm_set1_ps(-0.0f);
    v[3]=_mm_xor_ps(_mm_fmadd_ps(v[3],v[13],_mm_xor_ps(v[0],sign)),sign);
    v[5]=_mm_xor_ps(_mm_fmadd_ps(v[5],v[15],_mm_xor_ps(v[2],sign)),sign);
    v[4]=_mm_xor_ps(_mm_fmadd_ps(v[4],v[14],_mm_xor_ps(v[1],sign)),sign);
    for(u32 r=3;r<6;r++)if(!env_regular(v[r]))return false;
    v[16]=_mm_mul_ps(v[18],L0(v[3]));v[17]=_mm_mul_ps(v[18],L0(v[5]));
    if((!env_regular(v[16]) || !env_regular(v[17])))return false;
    v[16]=_mm_fmadd_ps(v[19],L1(v[3]),v[16]);v[17]=_mm_fmadd_ps(v[19],L1(v[5]),v[17]);
    if((!env_regular(v[16]) || !env_regular(v[17])))return false;
    v[16]=_mm_fmadd_ps(v[20],L0(v[4]),v[16]);v[17]=_mm_fmadd_ps(v[20],L1(v[4]),v[17]);
    if((!env_regular(v[16]) || !env_regular(v[17])))return false;
#undef L0
#undef L1
    return true;
}
#endif
/* Exact environment-map body 8024C518..8024C5D8. Generated code still
 * performs stores, camera subtraction, prefetch hints and the epilogue. */
static bool environment_body(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(c->pc!=0x8024C518u || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal ||
       (c->gqr[0]&0x70007u) || ((c->gqr[7]>>16)&7u)!=7 ||
       !c->ctr || c->ctr>65536)return false;
    int scale=(int)((c->gqr[7]>>24)&63u);if(scale&32)scale-=64;
    if(scale< -16 || scale>16)return false;
    for(u32 r=0;r<22;r++)if(r<6 || r==8 || r==9 || r>=18) {
        if(!exact_normal_single(c->fpr[r]) || !exact_normal_single(c->ps1[r]))return false;
        f64 limit=r<6 ? 0x1p32:0x1p16;
        if(c->fpr[r]>limit || c->fpr[r]<-limit || c->ps1[r]>limit || c->ps1[r]<-limit)return false;
    }
    u64 next=(u64)c->gpr[4]+24;
    const u8* input=next<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)next,24):NULL;
    if(!input)return false;
    __m128 v[22]={0};
    for(u32 r=0;r<22;r++)if(r<6 || r==8 || r==9 || r>=18)v[r]=env_pair(c,r);
    if(!environment_math(v))return false;
    u32 factor_bits=(u32)(127-scale)<<23;f32 factor;memcpy(&factor,&factor_bits,4);
    v[0]=env_load_s16(input,false,factor);v[1]=env_load_s16(input+4,true,factor);
    v[3]=env_load_s16(input+6,false,factor);v[4]=env_load_s16(input+10,true,factor);
    v[2]=env_load_s16(input+12,false,factor);v[6]=env_load_s16(input+16,true,factor);
    v[5]=env_load_s16(input+18,false,factor);v[7]=env_load_s16(input+22,true,factor);
    v[1]=_mm_unpacklo_ps(v[1],v[6]);v[4]=_mm_unpacklo_ps(v[4],v[7]);
    for(u32 r=0;r<18;r++)env_write(c,r,v[r]);
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(v[17])<<12);
    c->gpr[4]+=24;c->ctr--;s_environment_vertices+=2;
    if(!c->ctr) {
        c->pc=0x8024C5DCu;func_8024B4C0(c); // Original stores and epilogue.
    } else {
        c->pc=0x8024C500u;
        if(c->downcount> -256)platform_continue_cpu_slice();
    }
    return true;
#else
    (void)c;return false;
#endif
}

#if defined(_MSC_VER) && defined(_M_X64)
static bool environment_loop(CPUState* c,bool continue_original) {
    u32 phase=c->pc;
    if((phase!=0x8024C500u && phase!=0x8024C508u && phase!=0x8024C518u) ||
       !paired_skinning_enabled() || !host_fma_available() || c->exception ||
       !(c->msr&0x2000u) || (c->fpscr&0xF8u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal ||
       (c->gqr[0]&0x70007u) || ((c->gqr[7]>>16)&7u)!=7 || !c->ctr || c->ctr>65536)return false;
    int scale=(int)((c->gqr[7]>>24)&63u);if(scale&32)scale-=64;
    if(scale< -16 || scale>16)return false;
    for(u32 r=0;r<22;r++)if(r<6 || r==8 || r==9 || r>=18 || (phase==0x8024C500u && (r==16 || r==17))) {
        if(!exact_normal_single(c->fpr[r]) || !exact_normal_single(c->ps1[r]))return false;
        if(r!=16 && r!=17) {
            f64 bound=r<6 ? 0x1p32:0x1p16;
            if(c->fpr[r]>bound || c->fpr[r]<-bound || c->ps1[r]>bound || c->ps1[r]<-bound)return false;
        }
    }
    __m128 storage[2][22];__m128* v=storage[0];__m128* next=storage[1];
    for(u32 r=0;r<22;r++)if(r<6 || r==8 || r==9 || r>=18 || r==16 || r==17)v[r]=env_pair(c,r);
    u32 bits=(u32)(127-scale)<<23;f32 factor;memcpy(&factor,&bits,4);bool executed=false;
    for(;;) {
        u64 ia=(u64)c->gpr[4]+24,oa=(u64)c->gpr[5]+8;
        const u8* input=ia<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)ia,24):NULL;
        u8* output=phase==0x8024C500u && oa<=0xFFFFFFFFu && !(oa&3u) ? psq_direct_pointer(c,(u32)oa,16):NULL;
        if(!input || (phase==0x8024C500u && !output))break;
        for(u32 r=0;r<6;r++)next[r]=v[r];next[8]=v[8];next[9]=v[9];
        for(u32 r=18;r<22;r++)next[r]=v[r];
        if(phase!=0x8024C518u) {
            next[0]=_mm_sub_ps(v[0],v[8]);next[2]=_mm_sub_ps(v[2],v[8]);next[1]=_mm_sub_ps(v[1],v[9]);
            if(!env_regular(next[0]) || !env_regular(next[1]) || !env_regular(next[2]))break;
        }
        // Preflight on local values. A declined iteration has not changed
        // guest memory or registers, so the original can resume at its start.
        if(!environment_math(next))break;
        c->downcount-=phase==0x8024C500u ? 58:phase==0x8024C508u ? 56:0;
        if(output) {
            u32 words[4];_mm_storeu_si128((__m128i*)words,_mm_castps_si128(_mm_movelh_ps(v[16],v[17])));
            for(u32 i=0;i<4;i++)psq_write_be(output+i*4,words[i],4);
            c->gpr[5]+=16;
        }
        // Loads follow the pending stores, even for overlapping RAM/LC arrays.
        next[0]=env_load_s16(input,false,factor);next[1]=env_load_s16(input+4,true,factor);
        next[3]=env_load_s16(input+6,false,factor);next[4]=env_load_s16(input+10,true,factor);
        next[2]=env_load_s16(input+12,false,factor);next[6]=env_load_s16(input+16,true,factor);
        next[5]=env_load_s16(input+18,false,factor);next[7]=env_load_s16(input+22,true,factor);
        next[1]=_mm_unpacklo_ps(next[1],next[6]);next[4]=_mm_unpacklo_ps(next[4],next[7]);
        __m128* swap=v;v=next;next=swap;
        c->gpr[4]+=24;c->ctr--;s_environment_vertices+=2;executed=true;phase=0x8024C500u;
        if(!c->ctr || c->downcount<=-256)break;
    }
    if(!executed)return false;
    for(u32 r=0;r<18;r++)env_write(c,r,v[r]);
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(v[17])<<12);
    c->pc=c->ctr ? phase:0x8024C5DCu;s_environment_batches++;
    if(continue_original && (!c->ctr || c->downcount> -256))func_8024B4C0(c);
    return true;
}
#endif

bool paired_skinning_environment_direct_step(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    return environment_loop(c,false);
#else
    (void)c;return false;
#endif
}

/* dcbt is already emitted as a no-op in this generated chunk. Therefore
 * real budget resumes normally enter at C500, not at the hint successor.
 * Execute the exact pending stores/subtractions before the optimized body. */
bool paired_skinning_environment_step(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(environment_loop(c,true))return true;
#endif
    if(c->pc==0x8024C518u)return environment_body(c);
#if defined(_MSC_VER) && defined(_M_X64)
    if((c->pc!=0x8024C500u && c->pc!=0x8024C508u) || !paired_skinning_enabled() ||
       !host_fma_available() || c->exception || !(c->msr&0x2000u) ||
       !psq_direct_enabled(c,false) || c->cache_control || c->reserve_valid ||
       g_mem_write_journal || (c->gqr[0]&0x70007u) || !c->ctr || c->ctr>65536)return false;
    if(c->pc==0x8024C500u) {
        u64 output=(u64)c->gpr[5]+8;
        if(output>0xFFFFFFFFu || (output&3u) || !psq_direct_pointer(c,(u32)output,16))return false;
        c->downcount-=2;
        if(!ppc_psq_store_inline(c,16,(u32)output,false,0,false,0x8024C500u))return true;
        c->gpr[5]+=8;c->pc=0x8024C504u;
        if(!ppc_psq_store_inline(c,17,c->gpr[5]+8,false,0,false,0x8024C504u))return true;
        c->gpr[5]+=8;
    }
    c->downcount-=56;c->pc=0x8024C508u;ppc_ps_sub_op(c,0,0,8);
    c->pc=0x8024C50Cu;ppc_ps_sub_op(c,2,2,8);
    c->pc=0x8024C510u;ppc_ps_sub_op(c,1,1,9);
    c->pc=0x8024C518u;
    if(!environment_body(c))func_8024B4C0(c);
    return true;
#else
    return false;
#endif
}
