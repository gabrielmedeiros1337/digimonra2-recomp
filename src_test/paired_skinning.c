#include "paired_skinning.h"
#include "cpu/ps_fast.h"

static u64 s_vertices;
static bool s_enabled=true;
bool paired_skinning_enabled(void){return s_enabled;}
void paired_skinning_set_enabled(bool enabled){s_enabled=enabled;}
u64 paired_skinning_vertices(void){return s_vertices;}

/* Exact loop 8024BC48..8024BCE8. Keep the original prologue/epilogue,
 * operation order, PSQ quantization and dispatch budget. Only bounded S16
 * skinning arrays are accepted; all other states use the generated path. */
static bool coherent_range(CPUState* c,u64 address,u32 bytes) {
    return address<=0xFFFFFFFFu && psq_direct_pointer(c,(u32)address,bytes)!=NULL;
}
static inline void sk_madds0(CPUState* c,u8 d,u8 a,u8 x,u8 b) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(paired_fma_fast(c,d,a,x,b,false,false,0))return;
#endif
    ppc_ps_madds0(c,d,a,x,b);
}
static inline void sk_madds1(CPUState* c,u8 d,u8 a,u8 x,u8 b) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(paired_fma_fast(c,d,a,x,b,false,false,1))return;
#endif
    ppc_ps_madds1(c,d,a,x,b);
}
static inline void sk_muls0(CPUState* c,u8 d,u8 a,u8 x) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(paired_binary_fast(c,d,a,x,2,0))return;
#endif
    ppc_ps_muls0(c,d,a,x);
}
static inline void sk_muls1(CPUState* c,u8 d,u8 a,u8 x) {
#if defined(_MSC_VER) && defined(_M_X64)
    if(paired_binary_fast(c,d,a,x,2,1))return;
#endif
    ppc_ps_muls1(c,d,a,x);
}
bool paired_skinning_step(CPUState* c) {
    if(paired_skinning_blend_step(c))return true;
    if(!s_enabled || c->pc!=0x8024BC48u || c->exception || !(c->msr&0x2000u) ||
       !psq_direct_enabled(c,false) || c->reserve_valid || g_mem_write_journal ||
       (c->gqr[7]&0x00070007u)!=0x00070007u || ((c->gqr[6]>>16)&7u)<4 ||
       !c->ctr || c->ctr>65536 || c->downcount>4096 || c->downcount< -256)return false;
    s64 budget=c->downcount+256;
    u32 iterations=budget>0 ? (u32)((budget+40)/41) : 1;
    if(iterations>c->ctr)iterations=c->ctr;
    if(!coherent_range(c,(u64)c->gpr[6]+4,iterations*12u) ||
       !coherent_range(c,(u64)c->gpr[5]+2,iterations*2u+2) ||
       !coherent_range(c,(u64)c->gpr[7]+2,iterations*12u))return false;
    s_vertices+=iterations;
    for(;;) {
        c->downcount-=41;
        // 8024BC48: ps_madds0 f15, f0, f8, f6
        sk_madds0(c,15,0,8,6);
        // 8024BC4C: psq_stu f11, 2(r7), 0, 7
        c->pc=0x8024BC4Cu;
        {u32 ea=c->gpr[7]+2;if(!ppc_psq_store_inline(c,11,ea,false,7,false,0x8024BC4Cu))return true;c->gpr[7]=ea;}
        // 8024BC50: ps_madds0 f16, f1, f8, f7
        sk_madds0(c,16,1,8,7);
        // 8024BC54: psq_stu f12, 4(r7), 1, 7
        c->pc=0x8024BC54u;
        {u32 ea=c->gpr[7]+4;if(!ppc_psq_store_inline(c,12,ea,true,7,false,0x8024BC54u))return true;c->gpr[7]=ea;}
        // 8024BC58: ps_muls1 f17, f0, f9
        sk_muls1(c,17,0,9);
        // 8024BC5C: psq_stu f13, 2(r7), 0, 7
        c->pc=0x8024BC5Cu;
        {u32 ea=c->gpr[7]+2;if(!ppc_psq_store_inline(c,13,ea,false,7,false,0x8024BC5Cu))return true;c->gpr[7]=ea;}
        // 8024BC60: ps_muls1 f18, f1, f9
        sk_muls1(c,18,1,9);
        // 8024BC64: psq_stu f14, 4(r7), 1, 7
        c->pc=0x8024BC64u;
        {u32 ea=c->gpr[7]+4;if(!ppc_psq_store_inline(c,14,ea,true,7,false,0x8024BC64u))return true;c->gpr[7]=ea;}
        // 8024BC68: ps_madds1 f15, f2, f8, f15
        sk_madds1(c,15,2,8,15);
        // 8024BC6C: ps_madds1 f16, f3, f8, f16
        sk_madds1(c,16,3,8,16);
        // 8024BC70: ps_madds0 f17, f2, f10, f17
        sk_madds0(c,17,2,10,17);
        // 8024BC74: ps_madds0 f18, f3, f10, f18
        sk_madds0(c,18,3,10,18);
        // 8024BC78: ps_madds0 f15, f4, f9, f15
        sk_madds0(c,15,4,9,15);
        // 8024BC7C: ps_madds0 f16, f5, f9, f16
        sk_madds0(c,16,5,9,16);
        // 8024BC80: psq_lu f27, 2(r5), 0, 6
        c->pc=0x8024BC80u;
        {u32 ea=c->gpr[5]+2;if(!ppc_psq_load_inline(c,27,ea,false,6,false,0x8024BC80u))return true;c->gpr[5]=ea;}
        // 8024BC84: ps_madds1 f17, f4, f10, f17
        sk_madds1(c,17,4,10,17);
        // 8024BC88: ps_madds1 f18, f5, f10, f18
        sk_madds1(c,18,5,10,18);
        // 8024BC8C: ps_muls0 f15, f15, f27
        sk_muls0(c,15,15,27);
        // 8024BC90: ps_muls0 f16, f16, f27
        sk_muls0(c,16,16,27);
        // 8024BC94: ps_muls0 f17, f17, f27
        sk_muls0(c,17,17,27);
        // 8024BC98: ps_muls0 f18, f18, f27
        sk_muls0(c,18,18,27);
        // 8024BC9C: ps_madds0 f11, f19, f8, f25
        sk_madds0(c,11,19,8,25);
        // 8024BCA0: ps_madds0 f12, f20, f8, f26
        sk_madds0(c,12,20,8,26);
        // 8024BCA4: ps_muls1 f13, f19, f9
        sk_muls1(c,13,19,9);
        // 8024BCA8: ps_muls1 f14, f20, f9
        sk_muls1(c,14,20,9);
        // 8024BCAC: ps_madds1 f11, f21, f8, f11
        sk_madds1(c,11,21,8,11);
        // 8024BCB0: ps_madds1 f12, f22, f8, f12
        sk_madds1(c,12,22,8,12);
        // 8024BCB4: ps_madds0 f13, f21, f10, f13
        sk_madds0(c,13,21,10,13);
        // 8024BCB8: psq_lu f8, 4(r6), 0, 7
        c->pc=0x8024BCB8u;
        {u32 ea=c->gpr[6]+4;if(!ppc_psq_load_inline(c,8,ea,false,7,false,0x8024BCB8u))return true;c->gpr[6]=ea;}
        // 8024BCBC: ps_madds0 f14, f22, f10, f14
        sk_madds0(c,14,22,10,14);
        // 8024BCC0: ps_madds0 f11, f23, f9, f11
        sk_madds0(c,11,23,9,11);
        // 8024BCC4: ps_madds0 f12, f24, f9, f12
        sk_madds0(c,12,24,9,12);
        // 8024BCC8: ps_madds1 f13, f23, f10, f13
        sk_madds1(c,13,23,10,13);
        // 8024BCCC: ps_madds1 f14, f24, f10, f14
        sk_madds1(c,14,24,10,14);
        // 8024BCD0: psq_lu f9, 4(r6), 0, 7
        c->pc=0x8024BCD0u;
        {u32 ea=c->gpr[6]+4;if(!ppc_psq_load_inline(c,9,ea,false,7,false,0x8024BCD0u))return true;c->gpr[6]=ea;}
        // 8024BCD4: ps_madds1 f11, f11, f27, f15
        sk_madds1(c,11,11,27,15);
        // 8024BCD8: ps_madds1 f12, f12, f27, f16
        sk_madds1(c,12,12,27,16);
        // 8024BCDC: ps_madds1 f13, f13, f27, f17
        sk_madds1(c,13,13,27,17);
        // 8024BCE0: psq_lu f10, 4(r6), 0, 7
        c->pc=0x8024BCE0u;
        {u32 ea=c->gpr[6]+4;if(!ppc_psq_load_inline(c,10,ea,false,7,false,0x8024BCE0u))return true;c->gpr[6]=ea;}
        // 8024BCE4: ps_madds1 f14, f14, f27, f18
        sk_madds1(c,14,14,27,18);
        c->ctr--;
        if(!c->ctr){c->pc=0x8024BCECu;return true;}
        if(c->downcount<=-256){c->pc=0x8024BC48u;return true;}
    }
}
