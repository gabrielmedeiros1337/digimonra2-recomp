#include "sdk_transfers.h"
#include "cpu/ps_fast.h"
#include <string.h>
extern bool g_native_blocks_enabled;
extern void gx_pipe_write_fifo_bytes(CPUState*,const u8*,u32,u32);
static u64 s_xf,s_lc;
u64 sdk_xf_calls(void){return s_xf;}
u64 sdk_lc_calls(void){return s_lc;}
static void compare(CPUState* c,s32 a,s32 b){
    c->cr=(c->cr&0x0FFFFFFFu)|(((a<b ? 8u:a>b ? 4u:2u)|((c->xer>>31)&1u))<<28);
}
bool sdk_xf_load(CPUState* c){
    bool entry=c->pc==0x802D4EBCu,continuation=c->pc==0x802D4F14u || c->pc==0x802D4F4Cu;
    if((!entry && !continuation) || !g_native_blocks_enabled || c->gpr[5]>1 ||
       c->exception || (c->gpr[3]&3u) || !(c->msr&0x2000u) || !psq_direct_enabled(c,false) ||
       (c->gqr[0]&0x70007u) || c->cache_control || c->reserve_valid || g_mem_write_journal)return false;
    if(continuation && c->pc!=(c->gpr[5] ? 0x802D4F4Cu:0x802D4F14u))return false;
    u32 words=c->gpr[5] ? 8:12;const u8* source=psq_direct_pointer(c,c->gpr[3],words*4);
    if(!source)return false;
    for(u32 i=0;i<words;i++){u32 x=psq_read_be(source+i*4,4)&0x7FFFFFFFu;if(x && (x<0x00800000u || x>=0x7F800000u))return false;}
    if(entry){
        u32 id=c->gpr[4];c->gpr[7]=id<64 ? id*4:(id-64)*4+0x500;
        c->gpr[6]=(words-1)<<16;c->gpr[0]=c->gpr[7]|c->gpr[6];
        c->gpr[4]=0xCC010000u;compare(c,(s32)c->gpr[5],0);
        c->downcount-=2+(id<64 ? 1:4)+2+(c->gpr[5] ? 2:1)+9+(c->gpr[5] ? 10:14);
        u8 header[5]={0x10};psq_write_be(header+1,c->gpr[0],4);
        c->pc=0x802D4F08u;gx_pipe_write_fifo_bytes(c,header,5,2);
        // The original loads its source after emitting the header. This
        // preserves ordering if completing a gather line consumes older GX.
    }
    u8 payload[48];memcpy(payload,source,words*4);
    for(u32 i=0;i<words/2;i++){
        u32 reg=words/2-1-i,bits=psq_read_be(payload+i*8,4);float value;memcpy(&value,&bits,4);c->fpr[reg]=(double)value;
        bits=psq_read_be(payload+i*8+4,4);memcpy(&value,&bits,4);c->ps1[reg]=(double)value;
    }
    c->gpr[4]=0xCC008000u;c->pc=c->gpr[5] ? 0x802D4F68u:0x802D4F40u;
    gx_pipe_write_fifo_bytes(c,payload,words*4,words);
    c->pc=c->lr&~3u;s_xf++;return true;
}
bool sdk_lc_transfer(CPUState* c){
    bool entry=c->pc==0x802BF5DCu || c->pc==0x802BF600u;
    bool load=c->pc==0x802BF5DCu || c->pc==0x802BF5E8u,store=c->pc==0x802BF600u || c->pc==0x802BF60Cu;
    if((!load && !store) || !g_native_blocks_enabled || c->exception || (c->msr&0x4000u) || !c->spr_write)return false;
    // Collapse the complete SDK block-transfer leaf. The native DMA backend
    // still owns RAM bounds, LC wrap, status, and bulk memcpy semantics.
    u32 count=c->gpr[5],memory=(load ? c->gpr[4]:c->gpr[3])&0x0FFFFFFFu;
    if(entry){c->gpr[load ? 4:3]=memory;c->gpr[6]=((count>>2)&31u)|memory;}
    // Generated fallback SPR instructions are uncharged; preserve its 7-cycle
    // budget, or the remaining 4 when entered at the upper-SPR fallback.
    c->downcount-=entry ? 7:4;
    c->pc=load ? 0x802BF5E8u:0x802BF60Cu;ppc_mtspr(c,922,c->gpr[6],c->pc);
    c->gpr[6]=((count<<2)&12u)|(load ? c->gpr[3]:c->gpr[4])|(load ? 0x12u:2u);
    c->pc=load ? 0x802BF5F8u:0x802BF61Cu;ppc_mtspr(c,923,c->gpr[6],c->pc);
    c->pc=c->lr&~3u;s_lc++;return true;
}
