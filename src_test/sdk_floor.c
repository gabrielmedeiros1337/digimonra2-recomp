#include "sdk_floor.h"
#include "cpu/ps_fast.h"
#include <string.h>
extern bool g_native_blocks_enabled;
static u64 calls;
u64 sdk_floor_calls(void){return calls;}
static void cmp(CPUState* c,s32 a,s32 b){u32 v=(a<b ? 8u:a>b ? 4u:2u)|((c->xer>>31)&1u);c->cr=(c->cr&0x0FFFFFFFu)|(v<<28);}
static void rc(CPUState* c,u32 v){cmp(c,(s32)v,0);}
bool sdk_floor(CPUState* c,bool prologue){
    if((!prologue && c->pc!=0x8029D888u) || (prologue && c->pc!=0x8029D88Cu) ||
       !g_native_blocks_enabled || !g_fast_float_enabled || c->exception || !(c->msr&0x2000u) ||
       c->reserve_valid || g_mem_write_journal || c->cache_control || (c->fpscr&3u) || c->downcount+(prologue ? 11:0)<64)return false;
    u64 bits;memcpy(&bits,&c->fpr[1],8);u32 hi=(u32)(bits>>32),lo=(u32)bits,exp=(hi>>20)&2047u;int j=(int)exp-1023;
    if(exp==2047 || (j>=20 && j<=51))return false;
    u32 oldsp=prologue ? c->gpr[1]+16:c->gpr[1],sp=oldsp-16;
    u8* stack=psq_direct_pointer(c,sp,16);if(!stack)return false;
    double huge=0,zero=0;
    if(j<20){
        const u8* a=psq_direct_pointer(c,c->gpr[13]-29304u,8);const u8* b=psq_direct_pointer(c,c->gpr[13]-29296u,8);
        if(!a || !b || ((uintptr_t)stack<(uintptr_t)a+16 && (uintptr_t)a<(uintptr_t)stack+16))return false;
        u64 ah=((u64)psq_read_be(a,4)<<32)|psq_read_be(a+4,4),bh=((u64)psq_read_be(b,4)<<32)|psq_read_be(b+4,4);
        if(((ah>>52)&2047)==2047 || ((bh>>52)&2047)==2047)return false;
        memcpy(&huge,&ah,8);memcpy(&zero,&bh,8);
    }
    mem_write32(c,sp,oldsp);mem_write64(c,sp+8,bits);c->gpr[1]=sp;c->fpr[0]=c->fpr[1];
    c->gpr[9]=exp;c->gpr[10]=hi;c->gpr[6]=lo;c->gpr[11]=(u32)j;cmp(c,j,19);s64 charge=11;bool pack=false;
    if(j>51){charge+=4;cmp(c,j,1024);}
    else{
        charge+=2;cmp(c,j,0);
        if(j<0){
            charge+=5;c->fpr[0]=c->fpr[1]+huge;c->fpr[13]=zero;ppc_fcmp(c,0,c->fpr[0],zero,false);pack=true;
            if(c->cr&0x40000000u){
                charge+=2;cmp(c,(s32)hi,0);
                if((s32)hi>=0){charge+=3;c->gpr[6]=0;c->gpr[10]=0;}
                else{charge+=3;c->gpr[0]=hi&0x7FFFFFFFu;c->gpr[9]=c->gpr[0]|lo;rc(c,c->gpr[9]);
                    if(c->gpr[9]){charge+=3;c->gpr[10]=0xBFF00000u;c->gpr[6]=0;}}
            }
        }else{
            charge+=6;c->gpr[5]=0xFFFFFu>>j;c->xer&=~0x20000000u;c->gpr[9]=hi&c->gpr[5];c->gpr[0]=c->gpr[9]|lo;rc(c,c->gpr[0]);
            if(c->gpr[0]){
                charge+=5;c->fpr[0]=c->fpr[1]+huge;c->fpr[13]=zero;ppc_fcmp(c,0,c->fpr[0],zero,false);pack=true;
                if(c->cr&0x40000000u){
                    charge+=2;cmp(c,(s32)hi,0);
                    if((s32)hi<0){charge+=3;c->gpr[0]=0x100000u>>j;c->gpr[10]+=c->gpr[0];}
                    charge+=3;c->gpr[10]&=~c->gpr[5];c->gpr[6]=0;
                }
            }
        }
    }
    if(pack){
        charge+=6;c->gpr[7]=c->gpr[10];c->gpr[8]=c->gpr[6];
        bits=((u64)c->gpr[7]<<32)|c->gpr[8];mem_write64(c,sp+8,bits);memcpy(&c->fpr[0],&bits,8);c->fpr[1]=c->fpr[0];
    }
    charge+=2;c->downcount-=charge-(prologue ? 11:0);c->gpr[1]=oldsp;c->pc=c->lr&~3u;calls++;return true;
}
