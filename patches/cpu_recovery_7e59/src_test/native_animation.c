#include "native_animation.h"
#include "cpu/ps_fast.h"
#include <math.h>
#include <string.h>
extern bool g_native_blocks_enabled;
static u64 s_quaternions,s_components;
u64 native_quaternion_calls(void){return s_quaternions;}
u64 native_animation_components(void){return s_components;}
static bool enabled(const CPUState* c){
    return g_native_blocks_enabled && g_fast_float_enabled && host_fma_available() &&
        !c->exception && (c->msr&0x2000u) && !(c->fpscr&0xFBu) &&
        !c->reserve_valid && !g_mem_write_journal && !c->cache_control;
}
static float load(const u8* p){u32 bits=psq_read_be(p,4);float f;memcpy(&f,&bits,4);return f;}
static __forceinline float fused(float a,float b,float d){
#if defined(_MSC_VER) && defined(_M_X64)
    return _mm_cvtss_f32(_mm_fmadd_ss(_mm_set_ss(a),_mm_set_ss(b),_mm_set_ss(d)));
#else
    return fmaf(a,b,d);
#endif
}
static bool bounded(double f){return exact_normal_single(f) && f>=-65536. && f<=65536.;}
static void pair(CPUState* c,u32 r,float f){c->fpr[r]=c->ps1[r]=(double)f;}
static void store(u8* p,float f){u32 bits;memcpy(&bits,&f,4);psq_write_be(p,bits,4);}
bool native_quaternion(CPUState* c,bool charged){
    if(c->pc!=0x80283A70u || !enabled(c))return false;
    const u8* a=psq_direct_pointer(c,c->gpr[4],16);const u8* b=psq_direct_pointer(c,c->gpr[5],16);
    u8* out=psq_direct_pointer(c,c->gpr[3],16);if(!a || !b || !out)return false;
    float x[4],y[4];for(u32 i=0;i<4;i++){x[i]=load(a+i*4);y[i]=load(b+i*4);if(!bounded(x[i]) || !bounded(y[i]))return false;}
    // Preserve the original fused order and all observable volatile FPR/PS1.
    // All input loads precede the first output store, including alias cases.
    float f2=x[1]*y[3],f0=x[1]*y[2],f10=x[1]*y[1],f13=x[1]*y[0];
    float f11=-x[0],f12=x[0],f8=x[2],f9=x[3];
    f10=fused(f11,y[0],-f10);f13=fused(f12,y[1],-f13);
    f12=fused(f12,y[3],f0);f11=fused(f11,y[2],f2);
    f0=f8*y[1];float f3=f8*y[2];f11=fused(f8,y[0],f11);f8=fused(f8,y[3],f13);
    f12=f12-f0;f10=f10-f3;
    float f7=fused(f9,y[3],f10),f5=fused(f9,y[0],f12);
    float f6=fused(f9,y[1],f11);f9=fused(f9,y[2],f8);
    pair(c,0,f0);pair(c,2,f2);pair(c,3,f3);pair(c,4,y[2]);pair(c,5,f5);pair(c,6,f6);
    pair(c,7,f7);pair(c,8,f8);pair(c,9,f9);pair(c,10,f10);pair(c,11,f11);pair(c,12,f12);pair(c,13,f13);
    c->gpr[9]=c->gpr[3];store(out+12,f7);store(out,f5);store(out+4,f6);store(out+8,f9);
    if(!charged)c->downcount-=33;c->pc=c->lr&~3u;s_quaternions++;return true;
}
static bool overlap(const u8* a,u32 an,const u8* b,u32 bn){return (uintptr_t)a<(uintptr_t)b+bn && (uintptr_t)b<(uintptr_t)a+an;}
static s32 decoded(u32 bits){return (s32)(bits^0x80000000u);}
bool native_animation_channels(CPUState* c){
    if(!enabled(c) || !bounded(c->fpr[2]))return false;
    bool constant=c->pc==0x802524E4u,weighted=c->pc==0x80252848u;
    if(!constant && !weighted && c->pc!=0x802528CCu)return false;
    u8* stack=psq_direct_pointer(c,c->gpr[1]+16,8);if(!stack)return false;
    const double bias=4503601774854144.;
    if((constant ? c->gpr[11]:c->gpr[12])!=0x43300000u || (constant ? c->fpr[13]:c->fpr[11])!=bias || psq_read_be(stack,4)!=0x43300000u)return false;
    u32 count=constant ? c->ctr:c->gpr[30]-c->gpr[31];
    if(!count || count>16)return false;
    u8* output=psq_direct_pointer(c,c->gpr[5],count*4);if(!output || overlap(output,count*4,stack,8))return false;
    const u8* source=NULL;const u8* header=NULL;const u8* constants=NULL;
    if(constant){
        source=psq_direct_pointer(c,c->gpr[3],(count-1)*2);
        if(!source || overlap(output,count*4,source,(count-1)*2) || overlap(stack,8,source,(count-1)*2))return false;
    }else{
        for(u32 i=0;i<4;i++){u32 r=i==0 ? 1:i==1 ? 7:i==2 ? 8:9;if(!bounded(c->fpr[r]))return false;}
        if(c->gpr[25]>96 || c->gpr[27]>32 || c->gpr[28]>64 || c->gpr[29]>16 || c->gpr[31]>=16)return false;
        header=psq_direct_pointer(c,c->gpr[3],8);constants=psq_direct_pointer(c,c->gpr[26],192);
        source=psq_direct_pointer(c,c->gpr[4],128);
        if(!header || !constants || !source)return false;
        const u8* inputs[]={header,constants,source};u32 sizes[]={8,192,128};
        for(u32 i=0;i<3;i++)if(overlap(output,count*4,inputs[i],sizes[i]) || overlap(stack,8,inputs[i],sizes[i]))return false;
        if(psq_read_be(header+4,2)>64)return false;
    }
    u32 initial_source=c->gpr[4];
    bool first=true;
    for(u32 i=0;i<count;i++){
        if(!first){
            if(constant){
                c->downcount-=12;c->gpr[0]=(u32)(s32)(s16)psq_read_be(source+(i-1)*2,2)^0x80000000u;
                c->gpr[3]+=2;psq_write_be(stack+4,c->gpr[0],4);psq_write_be(stack,c->gpr[11],4);
            }else{
                c->downcount-=4;c->gpr[0]=psq_read_be(header+6,2)>>(c->gpr[31]&31u);
                c->xer&=~0x20000000u;c->gpr[9]=c->gpr[0]&1u;weighted=c->gpr[9]!=0;
                if(weighted){
                    const u8* p=source+(c->gpr[4]-initial_source);
                    c->downcount-=37;c->gpr[0]=(u32)(s32)(s16)psq_read_be(p,2)^0x80000000u;
                    c->gpr[11]=(u32)(s32)(s16)psq_read_be(p+c->gpr[27],2)^0x80000000u;
                    c->gpr[10]=(u32)(s32)(s16)psq_read_be(p+c->gpr[28],2)^0x80000000u;
                    c->gpr[6]=c->gpr[7]=c->gpr[8]=1;
                    psq_write_be(stack+4,c->gpr[0],4);psq_write_be(stack,c->gpr[12],4);
                    c->gpr[0]=(u32)(s32)(s16)psq_read_be(p+c->gpr[25],2);
                }else{
                    c->downcount-=11;c->gpr[9]=(psq_read_be(header+4,2)+c->gpr[29])*2;c->gpr[29]++;
                    c->gpr[0]=(u32)(s32)(s16)psq_read_be(constants+c->gpr[9],2)^0x80000000u;
                    psq_write_be(stack+4,c->gpr[0],4);psq_write_be(stack,c->gpr[12],4);
                }
            }
        }
        float result;
        if(constant || !weighted)result=(float)decoded(psq_read_be(stack+4,4));
        else{
            float a=(float)decoded(psq_read_be(stack+4,4)),b=(float)decoded(c->gpr[11]),d=(float)(s32)c->gpr[0];
            float v=(float)decoded(c->gpr[10]);c->gpr[4]+=2;c->gpr[0]^=0x80000000u;
            pair(c,12,fused((float)c->fpr[8],a,(float)(c->fpr[9]*(double)b)));
            pair(c,13,fused((float)c->fpr[7],v,(float)c->fpr[12]));
            result=fused((float)c->fpr[1],d,(float)c->fpr[13]);
            psq_write_be(stack+4,c->gpr[0],4);psq_write_be(stack,c->gpr[12],4);
        }
        result=(float)((double)result*c->fpr[2]);pair(c,0,result);store(output+i*4,result);c->gpr[5]+=4;s_components++;
        if(constant)c->ctr--;else{
            c->downcount-=6;c->gpr[31]++;s32 x=(s32)c->gpr[31],y=(s32)c->gpr[30];
            c->cr=(c->cr&0x0FFFFFFFu)|(((x<y ? 8u:x>y ? 4u:2u)|((c->xer>>31)&1u))<<28);
        }
        if(i+1<count && c->downcount<=-256){c->pc=constant ? 0x802524D0u:0x80252808u;return true;}
        first=false;
    }
    c->pc=constant ? 0x80252500u:0x802528F0u;return true;
}
