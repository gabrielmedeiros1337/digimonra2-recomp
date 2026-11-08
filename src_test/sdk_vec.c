#include "sdk_vec.h"
#include "cpu/ps_fast.h"
#include <string.h>
extern bool g_native_blocks_enabled;
static u64 calls;
u64 sdk_vec_calls(void){return calls;}
static float value(const u8* p){u32 bits=psq_read_be(p,4);float x;memcpy(&x,&bits,4);return x;}
static void pair(CPUState* c,u32 r,float f){c->fpr[r]=c->ps1[r]=(f64)f;}
bool sdk_vec_transform(CPUState* c,bool charged){
#if defined(_MSC_VER) && defined(_M_X64)
    if((c->pc!=0x8028BEDCu && c->pc!=0x8028BF58u) || !g_native_blocks_enabled || !g_fast_float_enabled ||
       !host_fma_available() || c->exception || !(c->msr&0x2000u) || c->reserve_valid || g_mem_write_journal ||
       c->cache_control || (c->fpscr&3u) || c->downcount+(charged ? 31:0)<31)return false;
    const u8* matrix=psq_direct_pointer(c,c->gpr[3],60);const u8* vector=psq_direct_pointer(c,c->gpr[4],12);
    u8* out=psq_direct_pointer(c,c->gpr[5],12);if(!matrix || !vector || !out)return false;
    float m[4][3],v[3];
    for(u32 j=0;j<3;j++){u32 b=psq_read_be(vector+j*4,4)&0x7FFFFFFFu;if(b && (b<0x00800000u || b>=0x7F800000u))return false;v[j]=value(vector+j*4);}
    for(u32 r=0;r<4;r++)for(u32 j=0;j<3;j++){u32 b=psq_read_be(matrix+r*16+j*4,4)&0x7FFFFFFFu;if(b && (b<0x00800000u || b>=0x7F800000u))return false;m[r][j]=value(matrix+r*16+j*4);}
    __m128 row0=_mm_set_ps(0,m[0][2],m[0][1],m[0][0]),row1=_mm_set_ps(0,m[1][2],m[1][1],m[1][0]);
    __m128 row2=_mm_set_ps(0,m[2][2],m[2][1],m[2][0]),translation=_mm_set_ps(0,m[3][2],m[3][1],m[3][0]);
    __m128 xy=_mm_fmadd_ps(_mm_set1_ps(v[0]),row0,_mm_mul_ps(_mm_set1_ps(v[1]),row1));
    __m128 result=_mm_add_ps(_mm_fmadd_ps(_mm_set1_ps(v[2]),row2,xy),translation);
    float middle[4],final[4];_mm_storeu_ps(middle,xy);_mm_storeu_ps(final,result);
    pair(c,0,final[2]);pair(c,5,m[3][2]);pair(c,6,m[2][2]);pair(c,7,middle[2]);pair(c,8,middle[1]);pair(c,9,middle[0]);
    pair(c,10,m[3][1]);pair(c,11,m[3][0]);pair(c,12,final[0]);pair(c,13,final[1]);
    // Preserve the original store order for aliases: Z, X, Y. All sources were
    // loaded before the first store, just as in both guest implementations.
    u32 bits;memcpy(&bits,final+2,4);mem_write32(c,c->gpr[5]+8,bits);
    memcpy(&bits,final,4);mem_write32(c,c->gpr[5],bits);memcpy(&bits,final+1,4);mem_write32(c,c->gpr[5]+4,bits);
    c->downcount-=charged ? 0:31;c->pc=c->lr&~3u;calls++;return true;
#else
    (void)c;(void)charged;return false;
#endif
}
