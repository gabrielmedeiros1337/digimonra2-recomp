#include "paired_skinning.h"
#include "cpu/ps_fast.h"
static u64 s_accumulated;
static u64 s_transformed;
static bool s_wide_domain=true;
void paired_skinning_set_wide_domain(bool enabled){s_wide_domain=enabled;}
bool paired_skinning_wide_domain(void){return s_wide_domain;}
u64 paired_skinning_accumulated(void){return s_accumulated;}
u64 paired_skinning_transformed(void){return s_transformed;}
bool paired_skinning_accumulate_available(void) {
#if defined(_MSC_VER) && defined(_M_X64)
    return host_fma_available();
#else
    return false;
#endif
}

#if defined(_MSC_VER) && defined(_M_X64)
static __forceinline __m128 pair_from_cpu(const CPUState* c,u32 r) {
    return _mm_cvtpd_ps(_mm_set_pd(c->ps1[r],c->fpr[r]));
}
static __forceinline void pair_to_cpu(CPUState* c,u32 r,__m128 v) {
    __m128d d=_mm_cvtps_pd(v);c->fpr[r]=_mm_cvtsd_f64(d);
    c->ps1[r]=_mm_cvtsd_f64(_mm_unpackhi_pd(d,d));
}
static bool bounded_pair_range(const CPUState* c,u32 r,f64 minimum,f64 maximum) {
    f64 a=c->fpr[r],b=c->ps1[r];
    if(!exact_normal_single(a) || !exact_normal_single(b))return false;
    a=a<0 ? -a:a;b=b<0 ? -b:b;
    return (a==0 || (a>=minimum && a<=maximum)) && (b==0 || (b>=minimum && b<=maximum));
}
static bool bounded_pair(const CPUState* c,u32 r,f64 maximum) {return bounded_pair_range(c,r,0x1p-16,maximum);}
static bool bounded_matrix(const CPUState* c,u32 r) {return bounded_pair_range(c,r,s_wide_domain ? 0x1p-48:0x1p-16,0x1p16);}
static bool bounded_pending(const CPUState* c,u32 r,f64 maximum) {return bounded_pair_range(c,r,s_wide_domain ? 0x1p-126:0x1p-16,maximum);}
static __forceinline __m128 load_s16_pair(const u8* p,bool w,f32 factor) {
    f32 a=(f32)(s16)psq_read_be(p,2)*factor;
    f32 b=w ? 1.0f:(f32)(s16)psq_read_be(p+2,2)*factor;
    return _mm_setr_ps(a,b,0,0);
}
static __forceinline void store_s16_vertex(u8* p,__m128 a,__m128 b,__m128 n,__m128 z,f32 factor) {
    __m128 scale=_mm_set1_ps(factor),lo=_mm_set1_ps(-32768.0f),hi=_mm_set1_ps(32767.0f);
    __m128 first=_mm_mul_ps(_mm_movelh_ps(a,b),scale);
    __m128 second=_mm_mul_ps(_mm_movelh_ps(n,z),scale);
    first=_mm_min_ps(_mm_max_ps(first,lo),hi);second=_mm_min_ps(_mm_max_ps(second,lo),hi);
    __m128i packed=_mm_packs_epi32(_mm_cvttps_epi32(first),_mm_cvttps_epi32(second));
    packed=_mm_or_si128(_mm_slli_epi16(packed,8),_mm_srli_epi16(packed,8));
    u8 bytes[16];_mm_storeu_si128((__m128i*)bytes,packed);
    ppc_mark_host_write(p,12);memcpy(p,bytes,6);memcpy(p+6,bytes+8,6);
}
static int signed_scale(u32 bits) {int n=(int)(bits&63u);return (n&32) ? n-64:n;}
static f32 scale_factor(int scale) {u32 bits=(u32)(127-scale)<<23;f32 result;memcpy(&result,&bits,4);return result;}
#endif
/* 8024C244..8024C2D0: indexed S16 accumulation, same fused operation order.
 * Conservative bounds prove intermediates stay finite and normal (or zero):
 * matrix exponents -48..16, input -16..31 and quantization scales -16..16
 * imply at least 2^-126 resolution and at most roughly 2^74 magnitude.
 * Binary32 matrices are multiples of 2^-71; initial positions of 2^-39;
 * U8/S16 values scaled by powers <=16 are multiples of 2^-16. Rounding
 * preserves this dyadic grid, so every nonzero arithmetic result is normal.
 * Pending stores may be tiny: scaling below FLT_MIN still truncates to zero
 * in both quantizers and does not update the architectural FPSCR.
 * Thus this is exactly the runtime's binary32 SIMD path without per-op
 * classification and double/single conversion. All other states fall back. */
bool paired_skinning_accumulate_step(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if((c->pc!=0x8024C244u && c->pc!=0x8024C2CCu) || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal ||
       (c->gqr[7]&0x70007u)!=0x70007u || ((c->gqr[6]>>16)&7u)!=4 ||
       !c->ctr || c->ctr>65536 || c->downcount>4096 || c->downcount< -256)return false;
    int load_scale=signed_scale(c->gqr[7]>>24),store_scale=signed_scale(c->gqr[7]>>8);
    int weight_scale=signed_scale(c->gqr[6]>>24);
    if(load_scale< -16 || load_scale>16 || store_scale< -16 || store_scale>16 ||
       weight_scale< -16 || weight_scale>16)return false;
    for(u32 i=0;i<8;i++)if(!bounded_matrix(c,i))return false;
    for(u32 i=8;i<11;i++)if(!bounded_pair(c,i,0x1p31))return false;
    // The real FIFO/skinning path normally yields at dcbst, before these
    // two integer instructions. Resume them before entering the vector loop.
    bool resumed=c->pc==0x8024C2CCu;
    if(resumed) {
        c->downcount-=2;c->gpr[21]=c->gpr[20]+c->gpr[6];c->ctr--;
        if(!c->ctr){c->pc=0x8024C2D4u;return true;}
        if(c->downcount<=-256){c->pc=0x8024C244u;return true;}
    }
    __m128 v[24];for(u32 i=0;i<11;i++)v[i]=pair_from_cpu(c,i);
    f32 factor=scale_factor(load_scale),wf=scale_factor(weight_scale),sf=scale_factor(-store_scale);
    bool executed=false;
    for(;;) {
        // Validate before this iteration changes any architectural state.
        u64 ia=(u64)c->gpr[5]+4,wa=(u64)c->gpr[8]+1,xa=(u64)c->gpr[7]+2;
        u8* input=ia<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)ia,12):NULL;
        u8* weight=wa<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)wa,1):NULL;
        u8* index=xa<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)xa,2):NULL;
        u8* output=psq_direct_pointer(c,c->gpr[21],12);
        if(!input || !weight || !index || !output) {
            if(!executed) {
                if(resumed){c->pc=0x8024C244u;return true;}
                return false;
            }
            c->pc=0x8024C244u;break;
        }
#define L0(x) _mm_shuffle_ps(x,x,0)
#define L1(x) _mm_shuffle_ps(x,x,85)
        c->downcount-=33;
        v[11]=_mm_fmadd_ps(v[0],L0(v[8]),v[6]);
        f32 w=(f32)*weight*wf;v[23]=_mm_setr_ps(w,1,0,0);
        v[12]=_mm_fmadd_ps(v[1],L0(v[8]),v[7]);
        v[13]=_mm_mul_ps(v[0],L1(v[9]));
        v[19]=load_s16_pair(output,false,factor);
        v[14]=_mm_mul_ps(v[1],L1(v[9]));
        v[11]=_mm_fmadd_ps(v[2],L1(v[8]),v[11]);
        v[12]=_mm_fmadd_ps(v[3],L1(v[8]),v[12]);
        v[20]=load_s16_pair(output+4,true,factor);
        v[13]=_mm_fmadd_ps(v[2],L0(v[10]),v[13]);
        v[14]=_mm_fmadd_ps(v[3],L0(v[10]),v[14]);
        v[21]=load_s16_pair(output+6,false,factor);
        v[15]=_mm_fmadd_ps(v[4],L0(v[9]),v[11]);
        v[16]=_mm_fmadd_ps(v[5],L0(v[9]),v[12]);
        u32 next=psq_read_be(index,2);
        v[17]=_mm_fmadd_ps(v[4],L1(v[10]),v[13]);
        v[18]=_mm_fmadd_ps(v[5],L1(v[10]),v[14]);
        v[22]=load_s16_pair(output+10,true,factor);
        v[19]=_mm_fmadd_ps(v[15],_mm_set1_ps(w),v[19]);
        v[8]=load_s16_pair(input,false,factor);
        v[20]=_mm_fmadd_ps(v[16],_mm_set1_ps(w),v[20]);
        v[9]=load_s16_pair(input+4,false,factor);
        v[21]=_mm_fmadd_ps(v[17],_mm_set1_ps(w),v[21]);
        v[10]=load_s16_pair(input+8,false,factor);
        v[22]=_mm_fmadd_ps(v[18],_mm_set1_ps(w),v[22]);
#undef L0
#undef L1
        c->gpr[5]+=12;c->gpr[7]+=2;c->gpr[8]++;
        c->gpr[22]=next*2;c->gpr[20]=next*12;
        store_s16_vertex(output,v[19],v[20],v[21],v[22],sf);
        executed=true;s_accumulated++;
        // dcbst is neutral only because the installed cache callback is NULL.
        // Preserve both original budget checks, including the split at dcbst.
        if(c->downcount<=-256){c->pc=0x8024C2CCu;break;}
        c->downcount-=2;c->gpr[21]=c->gpr[20]+c->gpr[6];c->ctr--;
        if(!c->ctr){c->pc=0x8024C2D4u;break;}
        if(c->downcount<=-256){c->pc=0x8024C244u;break;}
    }
    for(u32 i=8;i<24;i++)pair_to_cpu(c,i,v[i]);
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(v[22])<<12);
    return true;
#else
    (void)c;return false;
#endif
}

/* Pipelined rigid transform 8024C014..8024C060. The stores belong to the
 * preceding vertex; preserve their ordering before loading the next input,
 * including when input/output overlap in locked cache. */
bool paired_skinning_transform_step(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(c->pc!=0x8024C014u || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal ||
       (c->gqr[7]&0x70007u)!=0x70007u || !c->ctr || c->ctr>65536 ||
       c->downcount>4096 || c->downcount< -256)return false;
    int ls=signed_scale(c->gqr[7]>>24),ss=signed_scale(c->gqr[7]>>8);
    if(ls< -16 || ls>16 || ss< -16 || ss>16)return false;
    for(u32 r=0;r<8;r++)if(!bounded_matrix(c,r))return false;
    for(u32 r=8;r<11;r++)if(!bounded_pair(c,r,0x1p31))return false;
    for(u32 r=15;r<19;r++)if(!bounded_pending(c,r,0x1p80))return false;
    __m128 v[19];for(u32 r=0;r<19;r++)if(r<11 || r>=15)v[r]=pair_from_cpu(c,r);
    f32 lf=scale_factor(ls),sf=scale_factor(-ss);bool executed=false;
    for(;;) {
        u64 ia=(u64)c->gpr[4]+4,oa=(u64)c->gpr[5]+2;
        u8* input=ia<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)ia,12):NULL;
        u8* output=oa<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)oa,12):NULL;
        if(!input || !output){if(!executed)return false;break;}
#define T0(x) _mm_shuffle_ps(x,x,0)
#define T1(x) _mm_shuffle_ps(x,x,85)
        c->downcount-=20;
        v[11]=_mm_fmadd_ps(v[0],T0(v[8]),v[6]);
        v[12]=_mm_fmadd_ps(v[1],T0(v[8]),v[7]);
        store_s16_vertex(output,v[15],v[16],v[17],v[18],sf);
        v[13]=_mm_mul_ps(v[0],T1(v[9]));v[14]=_mm_mul_ps(v[1],T1(v[9]));
        v[11]=_mm_fmadd_ps(v[2],T1(v[8]),v[11]);v[12]=_mm_fmadd_ps(v[3],T1(v[8]),v[12]);
        v[8]=load_s16_pair(input,false,lf);
        v[13]=_mm_fmadd_ps(v[2],T0(v[10]),v[13]);v[14]=_mm_fmadd_ps(v[3],T0(v[10]),v[14]);
        v[15]=_mm_fmadd_ps(v[4],T0(v[9]),v[11]);v[16]=_mm_fmadd_ps(v[5],T0(v[9]),v[12]);
        v[9]=load_s16_pair(input+4,false,lf);
        v[17]=_mm_fmadd_ps(v[4],T1(v[10]),v[13]);v[18]=_mm_fmadd_ps(v[5],T1(v[10]),v[14]);
        v[10]=load_s16_pair(input+8,false,lf);
#undef T0
#undef T1
        c->gpr[4]+=12;c->gpr[5]+=12;c->ctr--;s_transformed++;executed=true;
        if(!c->ctr || c->downcount<=-256)break;
    }
    for(u32 r=8;r<19;r++)pair_to_cpu(c,r,v[r]);
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(v[18])<<12);
    c->pc=c->ctr ? 0x8024C014u:0x8024C064u;return true;
#else
    (void)c;return false;
#endif
}

/* Preserve the original prologue, then reach the vector loop immediately.
 * Otherwise small meshes finish entirely inside the generated chunk before
 * the dispatcher ever observes the C014 backedge. */
bool paired_skinning_transform_entry(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    extern void func_8024B4C0(CPUState*);
    if(c->pc!=0x8024BF84u || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal || (c->fpscr&0xF8u) ||
       (c->gqr[0]&0x70007u) || (c->gqr[7]&0x70007u)!=0x70007u ||
       c->gpr[6]<2 || c->gpr[6]>65536 || c->gpr[1]<64 || (c->gpr[1]&7u) ||
       (c->gpr[3]&3u) || ((c->gpr[4]|c->gpr[5])&1u))return false;
    u32 count=c->gpr[6];
    if(!psq_direct_pointer(c,c->gpr[1]-64,64) || !psq_direct_pointer(c,c->gpr[3],48) ||
       !psq_direct_pointer(c,c->gpr[4],(count+1u)*12u) || !psq_direct_pointer(c,c->gpr[5],count*12u))return false;
    c->downcount-=37;
    c->pc=0x8024BF84u;u32 stack=c->gpr[1]-64;mem_write32(c,stack,c->gpr[1]);c->gpr[1]=stack;
#define SAVE(r,off,at) do {u64 bits;memcpy(&bits,&c->fpr[r],8);c->pc=(at);mem_write64(c,stack+(off),bits);}while(0)
#define LOAD(r,off,w,at) do {c->pc=(at);if(!ppc_psq_load_inline(c,r,c->gpr[3]+(off),w,0,false,at))return true;}while(0)
#define NEXT(r,at) do {c->pc=(at);u32 ea=c->gpr[4]+4;if(!ppc_psq_load_inline(c,r,ea,false,7,false,at))return true;c->gpr[4]=ea;}while(0)
#define MATH(at,op) do {c->pc=(at);op;}while(0)
    SAVE(14,8,0x8024BF88u);SAVE(15,16,0x8024BF8Cu);c->gpr[6]--;
    SAVE(16,24,0x8024BF94u);SAVE(17,32,0x8024BF98u);SAVE(18,40,0x8024BF9Cu);c->ctr=c->gpr[6];
    LOAD(0,0,false,0x8024BFA4u);c->gpr[4]-=4;
    LOAD(1,8,true,0x8024BFACu);c->gpr[5]-=2;
    LOAD(6,36,false,0x8024BFB4u);NEXT(8,0x8024BFB8u);LOAD(7,44,true,0x8024BFBCu);NEXT(9,0x8024BFC0u);
    MATH(0x8024BFC4u,ppc_ps_madds0(c,11,0,8,6));LOAD(2,12,false,0x8024BFC8u);
    MATH(0x8024BFCCu,ppc_ps_madds0(c,12,1,8,7));LOAD(3,20,true,0x8024BFD0u);
    MATH(0x8024BFD4u,ppc_ps_muls1(c,13,0,9));NEXT(10,0x8024BFD8u);
    MATH(0x8024BFDCu,ppc_ps_muls1(c,14,1,9));LOAD(5,32,true,0x8024BFE0u);
    MATH(0x8024BFE4u,ppc_ps_madds1(c,11,2,8,11));MATH(0x8024BFE8u,ppc_ps_madds1(c,12,3,8,12));
    LOAD(4,24,false,0x8024BFECu);MATH(0x8024BFF0u,ppc_ps_madds0(c,13,2,10,13));NEXT(8,0x8024BFF4u);
    MATH(0x8024BFF8u,ppc_ps_madds0(c,14,3,10,14));MATH(0x8024BFFCu,ppc_ps_madds0(c,15,4,9,11));
    MATH(0x8024C000u,ppc_ps_madds0(c,16,5,9,12));NEXT(9,0x8024C004u);
    MATH(0x8024C008u,ppc_ps_madds1(c,17,4,10,13));MATH(0x8024C00Cu,ppc_ps_madds1(c,18,5,10,14));NEXT(10,0x8024C010u);
#undef SAVE
#undef LOAD
#undef NEXT
#undef MATH
    c->pc=0x8024C014u;
    if(!paired_skinning_transform_step(c))func_8024B4C0(c);
    else if(c->pc==0x8024C064u)func_8024B4C0(c);
    return true;
#else
    (void)c;return false;
#endif
}


/* Two-matrix blend, same pipelined memory order as BC48. The old per-op
 * implementation remains the fallback for values outside this narrow domain. */
static u64 s_blended;
u64 paired_skinning_blended(void){return s_blended;}
bool paired_skinning_blend_step(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(c->pc!=0x8024BC48u || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal || (c->fpscr&0xF8u) ||
       (c->gqr[7]&0x70007u)!=0x70007u || ((c->gqr[6]>>16)&7u)!=4 ||
       !c->ctr || c->ctr>65536 || c->downcount>4096 || c->downcount< -256)return false;
    int ls=signed_scale(c->gqr[7]>>24),ss=signed_scale(c->gqr[7]>>8),ws=signed_scale(c->gqr[6]>>24);
    if(ls< -16 || ls>16 || ss< -16 || ss>16 || ws< -16 || ws>16)return false;
    for(u32 r=0;r<27;r++)if(r<15 || r>=19) {
        f64 bound=r<8 || r>=19 ? 0x1p16:r<11 ? 0x1p31:0x1p100;
        bool valid=r<8 || r>=19 ? bounded_matrix(c,r):r<11 ? bounded_pair(c,r,bound):bounded_pending(c,r,bound);
        if(!valid)return false;
    }
    s64 budget=c->downcount+256;u32 n=budget>0 ? (u32)((budget+40)/41):1;if(n>c->ctr)n=c->ctr;
    u64 ia=(u64)c->gpr[6]+4,wa=(u64)c->gpr[5]+2,oa=(u64)c->gpr[7]+2;
    u8* input=ia<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)ia,n*12u):NULL;
    u8* weights=wa<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)wa,n*2u):NULL;
    u8* output=oa<=0xFFFFFFFFu ? psq_direct_pointer(c,(u32)oa,n*12u):NULL;
    if(!input || !weights || !output)return false;
    __m128 v[28];for(u32 r=0;r<27;r++)if(r<15 || r>=19)v[r]=pair_from_cpu(c,r);
    f32 lf=scale_factor(ls),sf=scale_factor(-ss),wf=scale_factor(ws);
#define B0(x) _mm_shuffle_ps(x,x,0)
#define B1(x) _mm_shuffle_ps(x,x,85)
    for(u32 k=0;k<n;k++) {
        c->downcount-=41;
        v[15]=_mm_fmadd_ps(v[0],B0(v[8]),v[6]);
        v[16]=_mm_fmadd_ps(v[1],B0(v[8]),v[7]);
        v[17]=_mm_mul_ps(v[0],B1(v[9]));v[18]=_mm_mul_ps(v[1],B1(v[9]));
        store_s16_vertex(output,v[11],v[12],v[13],v[14],sf);
        v[15]=_mm_fmadd_ps(v[2],B1(v[8]),v[15]);v[16]=_mm_fmadd_ps(v[3],B1(v[8]),v[16]);
        v[17]=_mm_fmadd_ps(v[2],B0(v[10]),v[17]);v[18]=_mm_fmadd_ps(v[3],B0(v[10]),v[18]);
        v[15]=_mm_fmadd_ps(v[4],B0(v[9]),v[15]);v[16]=_mm_fmadd_ps(v[5],B0(v[9]),v[16]);
        v[27]=_mm_setr_ps((f32)weights[0]*wf,(f32)weights[1]*wf,0,0);
        v[17]=_mm_fmadd_ps(v[4],B1(v[10]),v[17]);v[18]=_mm_fmadd_ps(v[5],B1(v[10]),v[18]);
        for(u32 r=15;r<19;r++)v[r]=_mm_mul_ps(v[r],B0(v[27]));
        v[11]=_mm_fmadd_ps(v[19],B0(v[8]),v[25]);v[12]=_mm_fmadd_ps(v[20],B0(v[8]),v[26]);
        v[13]=_mm_mul_ps(v[19],B1(v[9]));v[14]=_mm_mul_ps(v[20],B1(v[9]));
        v[11]=_mm_fmadd_ps(v[21],B1(v[8]),v[11]);v[12]=_mm_fmadd_ps(v[22],B1(v[8]),v[12]);
        v[13]=_mm_fmadd_ps(v[21],B0(v[10]),v[13]);
        v[8]=load_s16_pair(input,false,lf);
        v[14]=_mm_fmadd_ps(v[22],B0(v[10]),v[14]);
        v[11]=_mm_fmadd_ps(v[23],B0(v[9]),v[11]);v[12]=_mm_fmadd_ps(v[24],B0(v[9]),v[12]);
        v[13]=_mm_fmadd_ps(v[23],B1(v[10]),v[13]);v[14]=_mm_fmadd_ps(v[24],B1(v[10]),v[14]);
        v[9]=load_s16_pair(input+4,false,lf);
        v[11]=_mm_fmadd_ps(v[11],B1(v[27]),v[15]);v[12]=_mm_fmadd_ps(v[12],B1(v[27]),v[16]);
        v[13]=_mm_fmadd_ps(v[13],B1(v[27]),v[17]);v[10]=load_s16_pair(input+8,false,lf);
        v[14]=_mm_fmadd_ps(v[14],B1(v[27]),v[18]);
        input+=12;output+=12;weights+=2;c->gpr[6]+=12;c->gpr[7]+=12;c->gpr[5]+=2;c->ctr--;s_blended++;
    }
#undef B0
#undef B1
    for(u32 r=8;r<19;r++)pair_to_cpu(c,r,v[r]);pair_to_cpu(c,27,v[27]);
    if(!g_fast_float_enabled)c->fpscr=(c->fpscr&~0x1F000u)|(ps_fast_classify(v[14])<<12);
    c->pc=c->ctr ? 0x8024BC48u:0x8024BCECu;return true;
#else
    (void)c;return false;
#endif
}


/* Reach BC48 for small meshes as well as those which yield in the generated
 * chunk. The 77-instruction prologue uses the original runtime operations. */
bool paired_skinning_blend_entry(CPUState* c) {
#if defined(_MSC_VER) && defined(_M_X64)
    extern void func_8024B4C0(CPUState*);
    if(c->pc!=0x8024BB18u || !paired_skinning_enabled() || !host_fma_available() ||
       c->exception || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       c->cache_control || c->reserve_valid || g_mem_write_journal || (c->fpscr&0xF8u) ||
       (c->gqr[0]&0x70007u) || (c->gqr[7]&0x70007u)!=0x70007u ||
       ((c->gqr[6]>>16)&7u)!=4 || c->gpr[8]<2 || c->gpr[8]>65536 ||
       c->gpr[1]<160 || (c->gpr[1]&7u) || ((c->gpr[3]|c->gpr[4])&3u) ||
       ((c->gpr[6]|c->gpr[7])&1u))return false;
    u32 count=c->gpr[8];
    if(!psq_direct_pointer(c,c->gpr[1]-160,160) || !psq_direct_pointer(c,c->gpr[3],48) ||
       !psq_direct_pointer(c,c->gpr[4],48) || !psq_direct_pointer(c,c->gpr[5],count*2u) ||
       !psq_direct_pointer(c,c->gpr[6],(count+1u)*12u) || !psq_direct_pointer(c,c->gpr[7],count*12u))return false;
    c->downcount-=77;
    c->pc=0x8024BB18u;u32 stack=c->gpr[1]-160;mem_write32(c,stack,c->gpr[1]);c->gpr[1]=stack;
    c->pc=0x8024BB1Cu;{u64 bits;memcpy(&bits,&c->fpr[14],8);mem_write64(c,c->gpr[1]+8u,bits);}
    c->pc=0x8024BB20u;{u64 bits;memcpy(&bits,&c->fpr[15],8);mem_write64(c,c->gpr[1]+16u,bits);}
    c->pc=0x8024BB24u;{u64 bits;memcpy(&bits,&c->fpr[16],8);mem_write64(c,c->gpr[1]+24u,bits);}
    c->pc=0x8024BB28u;{u64 bits;memcpy(&bits,&c->fpr[17],8);mem_write64(c,c->gpr[1]+32u,bits);}
    c->pc=0x8024BB2Cu;{u64 bits;memcpy(&bits,&c->fpr[18],8);mem_write64(c,c->gpr[1]+40u,bits);}
    c->pc=0x8024BB30u;{u64 bits;memcpy(&bits,&c->fpr[19],8);mem_write64(c,c->gpr[1]+48u,bits);}
    c->pc=0x8024BB34u;{u64 bits;memcpy(&bits,&c->fpr[20],8);mem_write64(c,c->gpr[1]+56u,bits);}
    c->pc=0x8024BB38u;{u64 bits;memcpy(&bits,&c->fpr[21],8);mem_write64(c,c->gpr[1]+64u,bits);}
    c->pc=0x8024BB3Cu;{u64 bits;memcpy(&bits,&c->fpr[22],8);mem_write64(c,c->gpr[1]+72u,bits);}
    c->pc=0x8024BB40u;{u64 bits;memcpy(&bits,&c->fpr[23],8);mem_write64(c,c->gpr[1]+80u,bits);}
    c->pc=0x8024BB44u;{u64 bits;memcpy(&bits,&c->fpr[24],8);mem_write64(c,c->gpr[1]+88u,bits);}
    c->pc=0x8024BB48u;{u64 bits;memcpy(&bits,&c->fpr[25],8);mem_write64(c,c->gpr[1]+96u,bits);}
    c->pc=0x8024BB4Cu;{u64 bits;memcpy(&bits,&c->fpr[26],8);mem_write64(c,c->gpr[1]+104u,bits);}
    c->pc=0x8024BB50u;{u64 bits;memcpy(&bits,&c->fpr[27],8);mem_write64(c,c->gpr[1]+112u,bits);}
    c->pc=0x8024BB54u;mem_write32(c,c->gpr[1]+120u,c->gpr[25]);
    c->pc=0x8024BB58u;c->gpr[25]=c->gpr[8]+(u32)(s32)(-1);
    c->pc=0x8024BB5Cu;c->ctr=c->gpr[25];
    c->pc=0x8024BB60u;{u32 ea=c->gpr[3]+0u;if(!ppc_psq_load_inline(c,0,ea,false,0,false,0x8024BB60u))return true;}
    c->pc=0x8024BB64u;c->gpr[6]=c->gpr[6]+(u32)(s32)(-4);
    c->pc=0x8024BB68u;{u32 ea=c->gpr[3]+8u;if(!ppc_psq_load_inline(c,1,ea,true,0,false,0x8024BB68u))return true;}
    c->pc=0x8024BB6Cu;c->gpr[7]=c->gpr[7]+(u32)(s32)(-2);
    c->pc=0x8024BB70u;{u32 ea=c->gpr[3]+36u;if(!ppc_psq_load_inline(c,6,ea,false,0,false,0x8024BB70u))return true;}
    c->pc=0x8024BB74u;c->gpr[5]=c->gpr[5]+(u32)(s32)(-2);
    c->pc=0x8024BB78u;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,8,ea,false,7,false,0x8024BB78u))return true;c->gpr[6]=ea;}
    c->pc=0x8024BB7Cu;{u32 ea=c->gpr[3]+44u;if(!ppc_psq_load_inline(c,7,ea,true,0,false,0x8024BB7Cu))return true;}
    c->pc=0x8024BB80u;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,9,ea,false,7,false,0x8024BB80u))return true;c->gpr[6]=ea;}
    c->pc=0x8024BB84u;{u32 ea=c->gpr[5]+2u;if(!ppc_psq_load_inline(c,27,ea,false,6,false,0x8024BB84u))return true;c->gpr[5]=ea;}
    c->pc=0x8024BB88u;ppc_ps_madds0(c,15,0,8,6);
    c->pc=0x8024BB8Cu;{u32 ea=c->gpr[3]+12u;if(!ppc_psq_load_inline(c,2,ea,false,0,false,0x8024BB8Cu))return true;}
    c->pc=0x8024BB90u;ppc_ps_madds0(c,16,1,8,7);
    c->pc=0x8024BB94u;{u32 ea=c->gpr[3]+20u;if(!ppc_psq_load_inline(c,3,ea,true,0,false,0x8024BB94u))return true;}
    c->pc=0x8024BB98u;ppc_ps_muls1(c,17,0,9);
    c->pc=0x8024BB9Cu;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,10,ea,false,7,false,0x8024BB9Cu))return true;c->gpr[6]=ea;}
    c->pc=0x8024BBA0u;ppc_ps_muls1(c,18,1,9);
    c->pc=0x8024BBA4u;{u32 ea=c->gpr[3]+32u;if(!ppc_psq_load_inline(c,5,ea,true,0,false,0x8024BBA4u))return true;}
    c->pc=0x8024BBA8u;ppc_ps_madds1(c,15,2,8,15);
    c->pc=0x8024BBACu;{u32 ea=c->gpr[4]+0u;if(!ppc_psq_load_inline(c,19,ea,false,0,false,0x8024BBACu))return true;}
    c->pc=0x8024BBB0u;ppc_ps_madds1(c,16,3,8,16);
    c->pc=0x8024BBB4u;{u32 ea=c->gpr[3]+24u;if(!ppc_psq_load_inline(c,4,ea,false,0,false,0x8024BBB4u))return true;}
    c->pc=0x8024BBB8u;ppc_ps_madds0(c,17,2,10,17);
    c->pc=0x8024BBBCu;{u32 ea=c->gpr[4]+8u;if(!ppc_psq_load_inline(c,20,ea,true,0,false,0x8024BBBCu))return true;}
    c->pc=0x8024BBC0u;ppc_ps_madds0(c,18,3,10,18);
    c->pc=0x8024BBC4u;{u32 ea=c->gpr[4]+12u;if(!ppc_psq_load_inline(c,21,ea,false,0,false,0x8024BBC4u))return true;}
    c->pc=0x8024BBC8u;ppc_ps_madds0(c,15,4,9,15);
    c->pc=0x8024BBCCu;{u32 ea=c->gpr[4]+20u;if(!ppc_psq_load_inline(c,22,ea,true,0,false,0x8024BBCCu))return true;}
    c->pc=0x8024BBD0u;ppc_ps_madds0(c,16,5,9,16);
    c->pc=0x8024BBD4u;{u32 ea=c->gpr[4]+24u;if(!ppc_psq_load_inline(c,23,ea,false,0,false,0x8024BBD4u))return true;}
    c->pc=0x8024BBD8u;ppc_ps_madds1(c,17,4,10,17);
    c->pc=0x8024BBDCu;{u32 ea=c->gpr[4]+32u;if(!ppc_psq_load_inline(c,24,ea,true,0,false,0x8024BBDCu))return true;}
    c->pc=0x8024BBE0u;ppc_ps_madds1(c,18,5,10,18);
    c->pc=0x8024BBE4u;{u32 ea=c->gpr[4]+36u;if(!ppc_psq_load_inline(c,25,ea,false,0,false,0x8024BBE4u))return true;}
    c->pc=0x8024BBE8u;ppc_ps_muls0(c,15,15,27);
    c->pc=0x8024BBECu;{u32 ea=c->gpr[4]+44u;if(!ppc_psq_load_inline(c,26,ea,true,0,false,0x8024BBECu))return true;}
    c->pc=0x8024BBF0u;ppc_ps_muls0(c,16,16,27);
    c->pc=0x8024BBF4u;ppc_ps_muls0(c,17,17,27);
    c->pc=0x8024BBF8u;ppc_ps_muls0(c,18,18,27);
    c->pc=0x8024BBFCu;ppc_ps_madds0(c,11,19,8,25);
    c->pc=0x8024BC00u;ppc_ps_madds0(c,12,20,8,26);
    c->pc=0x8024BC04u;ppc_ps_muls1(c,13,19,9);
    c->pc=0x8024BC08u;ppc_ps_muls1(c,14,20,9);
    c->pc=0x8024BC0Cu;ppc_ps_madds1(c,11,21,8,11);
    c->pc=0x8024BC10u;ppc_ps_madds1(c,12,22,8,12);
    c->pc=0x8024BC14u;ppc_ps_madds0(c,13,21,10,13);
    c->pc=0x8024BC18u;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,8,ea,false,7,false,0x8024BC18u))return true;c->gpr[6]=ea;}
    c->pc=0x8024BC1Cu;ppc_ps_madds0(c,14,22,10,14);
    c->pc=0x8024BC20u;ppc_ps_madds0(c,11,23,9,11);
    c->pc=0x8024BC24u;ppc_ps_madds0(c,12,24,9,12);
    c->pc=0x8024BC28u;ppc_ps_madds1(c,13,23,10,13);
    c->pc=0x8024BC2Cu;ppc_ps_madds1(c,14,24,10,14);
    c->pc=0x8024BC30u;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,9,ea,false,7,false,0x8024BC30u))return true;c->gpr[6]=ea;}
    c->pc=0x8024BC34u;ppc_ps_madds1(c,11,11,27,15);
    c->pc=0x8024BC38u;ppc_ps_madds1(c,12,12,27,16);
    c->pc=0x8024BC3Cu;ppc_ps_madds1(c,13,13,27,17);
    c->pc=0x8024BC40u;{u32 ea=c->gpr[6]+4u;if(!ppc_psq_load_inline(c,10,ea,false,7,false,0x8024BC40u))return true;c->gpr[6]=ea;}
    c->pc=0x8024BC44u;ppc_ps_madds1(c,14,14,27,18);
    c->pc=0x8024BC48u;
    if(!paired_skinning_step(c))func_8024B4C0(c);
    else if(c->pc==0x8024BCECu)func_8024B4C0(c);
    return true;
#else
    (void)c;return false;
#endif
}
