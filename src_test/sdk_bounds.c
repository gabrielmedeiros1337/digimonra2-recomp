#include "sdk_bounds.h"
#include "cpu/ps_fast.h"
#include <string.h>
static bool s_enabled=true;
static u64 s_calls;
void sdk_bounds_set_enabled(bool enabled){s_enabled=enabled;}
u64 sdk_bounds_calls(void){return s_calls;}
static float unpack(const u8* p){u32 u=psq_read_be(p,4);float f;memcpy(&f,&u,4);return f;}
static void store(CPUState* c,u32 p,float f){u32 u;memcpy(&u,&f,4);mem_write32(c,p,u);}
static void pair(CPUState* c,u32 r,float f){c->fpr[r]=c->ps1[r]=(f64)f;}
static void compare_int(CPUState* c,s32 a,s32 b){
    u32 bits=(a<b ? 8u:a>b ? 4u:2u)|((c->xer>>31)&1u);
    c->cr=(c->cr&0x0FFFFFFFu)|(bits<<28);
}
static bool regular(const u8* p,u32 count){
    for(u32 i=0;i<count;i++){u32 x=psq_read_be(p+i*4,4)&0x7FFFFFFFu;
        if(x && (x<0x00800000u || x>=0x7F800000u))return false;}
    return true;
}
bool sdk_bounds_test(CPUState* c){
#if defined(_MSC_VER) && defined(_M_X64)
    bool upper=c->pc==0x80278EF4u || c->pc==0x80278F10u;
    bool continuation=c->pc==0x80278E30u || c->pc==0x80278F10u;
    if((c->pc!=0x80278E10u && c->pc!=0x80278EF4u && !continuation) || !s_enabled || !g_fast_float_enabled ||
       !host_fma_available() || c->exception || !(c->msr&0x2000u) || (c->fpscr&3u) ||
       c->reserve_valid || g_mem_write_journal || c->cache_control)return false;
    u32 frame=upper ? 72u:40u,sp=continuation ? c->gpr[1]:c->gpr[1]-frame;
    u32 old_sp=sp+frame,planes=c->gpr[3],box=c->gpr[4],prior=continuation ? (upper ? 15u:9u):0;
    const u8* object=psq_direct_pointer(c,planes,260);const u8* bounds=psq_direct_pointer(c,box,24);
    u8* stack=psq_direct_pointer(c,sp,frame);
    u32 zero_address=upper ? 0x8030F204u:0x8030F200u;
    const u8* constant=psq_direct_pointer(c,zero_address,4);
    if(!object || !bounds || !stack || !constant)return false;
    s32 count=(s32)psq_read_be(object+256,4);
    if(count>16 || c->downcount+(s64)prior<(s64)(count>0 ? (upper ? 44*count+18:40*count+12):(upper ? 8:9)))return false;
    if(!regular(bounds,6) || !regular(constant,1) || (count>0 && !regular(object,(u32)count*4)))return false;
    // Stack stores must not overwrite input planes/bounds or their aliases.
    uintptr_t a=(uintptr_t)stack,b=(uintptr_t)object,d=(uintptr_t)bounds;
    if((a<b+260 && b<a+frame) || (a<d+24 && d<a+frame))return false;
    float lo[3],hi[3];for(u32 i=0;i<3;i++){lo[i]=unpack(bounds+i*4);hi[i]=unpack(bounds+12+i*4);}
    float zero=unpack(constant);s64 charge=upper ? 5:6;
    mem_write32(c,sp,old_sp);c->gpr[1]=sp;c->gpr[0]=(u32)count;c->gpr[upper ? 8:7]=0;
    if(!upper)c->gpr[8]=box+12;
    compare_int(c,0,count);
    bool rejected=false;
    if(count>0){
        charge+=upper ? 10:3;pair(c,7,zero);c->gpr[10]=sp+8;
        if(upper){c->gpr[11]=box+12;pair(c,1,hi[2]);pair(c,2,hi[1]);pair(c,5,hi[0]);pair(c,6,lo[0]);pair(c,3,lo[1]);pair(c,4,lo[2]);}
        for(s32 n=0;n<count;n++){
            float normal[3],chosen[3];const u8* row=object+n*16;
            for(u32 j=0;j<3;j++)normal[j]=unpack(row+j*4);
            charge+=upper ? 9:3;
            for(u32 j=0;j<3;j++){
                ppc_fcmp(c,0,normal[j],zero,false);
                bool select_low=upper ? normal[j]>zero:normal[j]<zero;
                chosen[j]=select_low ? lo[j]:hi[j];charge+=select_low ? 2:1;
                if(j==0)charge+=upper ? 3:5;
                if(j==1)charge+=upper ? 4:5;
            }
            for(u32 j=0;j<3;j++){
                store(c,sp+8+j*4,chosen[j]);store(c,sp+(upper ? 56:24)+j*4,normal[j]);
                if(upper){store(c,sp+24+j*4,lo[j]);store(c,sp+40+j*4,hi[j]);}
            }
            c->gpr[9]=upper ? sp+8:sp+12;if(!upper)c->gpr[11]=sp+16;
            // Exact operation order of the native-float reference: y product,
            // fused x and z additions, then the plane offset.
            __m128 y=_mm_mul_ss(_mm_set_ss(normal[1]),_mm_set_ss(chosen[1]));
            __m128 x=_mm_fmadd_ss(_mm_set_ss(normal[0]),_mm_set_ss(chosen[0]),y);
            __m128 z=_mm_fmadd_ss(_mm_set_ss(normal[2]),_mm_set_ss(chosen[2]),x);
            float offset=unpack(row+12),sum=_mm_cvtss_f32(_mm_add_ss(z,_mm_set_ss(offset)));
            pair(c,0,chosen[1]);pair(c,8,chosen[0]);pair(c,9,chosen[2]);pair(c,10,_mm_cvtss_f32(x));
            pair(c,11,offset);pair(c,12,_mm_cvtss_f32(y));pair(c,13,sum);
            ppc_fcmp(c,0,sum,zero,false);charge+=upper ? 18:17;
            if(sum<zero){charge+=2;rejected=true;break;}
            c->gpr[upper ? 8:7]++;c->gpr[3]+=16;charge+=4;
            compare_int(c,(s32)c->gpr[upper ? 8:7],count);
        }
    }
    if(!rejected)charge++;
    charge+=2;c->downcount-=charge-prior;c->gpr[3]=rejected ? 0u:1u;c->gpr[1]=old_sp;
    c->pc=c->lr&~3u;s_calls++;return true;
#else
    (void)c;return false;
#endif
}

// Complete expand-by-point / union routines, including observable volatile
// registers, ordered stores for overlapping inputs, CR/FPSCR and guest budget.
static u64 s_aabb_calls;
u64 sdk_aabb_calls(void){return s_aabb_calls;}
bool sdk_aabb_update(CPUState* c,bool entry_charged){
    bool unite=c->pc==0x80276D6Cu;
    if((!unite && c->pc!=0x80276CC0u) || !s_enabled || !g_fast_float_enabled ||
       c->exception || !(c->msr&0x2000u) || c->reserve_valid ||
       g_mem_write_journal || c->cache_control || (c->fpscr&3u))return false;
    u32 out=c->gpr[3],a=c->gpr[4],b=unite ? c->gpr[5]:out;
    const u8* pa=psq_direct_pointer(c,a,unite ? 24:12);
    const u8* pb=psq_direct_pointer(c,b,24);
    u8* dst=psq_direct_pointer(c,out,24);
    if(!pa || !pb || !dst || !regular(pa,unite ? 6:3) || !regular(pb,6) ||
       c->downcount+(entry_charged ? 5:0)<(unite ? 45:43))return false;
    s64 charge=unite ? 39:37;
    for(u32 i=0;i<6;i++){
        // Preserve instruction ordering: input/output ranges may overlap.
        float other=unpack(pb+i*4),candidate=unpack(pa+(unite ? i:i%3)*4);
        pair(c,13,other);pair(c,0,candidate);
        ppc_fcmp(c,0,candidate,other,false);
        bool select=i<3 ? candidate<=other:candidate>=other;
        c->cr=(c->cr&~0x10000000u)|(select ? 0x10000000u:0u);
        if(!select){c->fpr[0]=c->fpr[13];charge++;}
        // fmr copies only ps0; stfs does not modify ps1.
        store(c,out+i*4,(float)c->fpr[0]);
    }
    if(unite){c->gpr[11]=a+12;c->gpr[9]=b+12;}
    c->downcount-=charge-(entry_charged ? 5:0);c->pc=c->lr&~3u;s_aabb_calls++;return true;
}
