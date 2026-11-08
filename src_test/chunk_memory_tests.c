#include "chunk_memory.h"
#include <stdio.h>
typedef struct {u32 calls,pc,address,width;u64 value;} Trace;
static u64 probe_read(CPUState* c,u32 a,u8 n){Trace* t=c->external_user_data;*t=(Trace){t->calls+1,c->pc,a,n,0};c->gpr[7]^=a;return 0x123456789ABCDEF0ull;}
static void probe_write(CPUState* c,u32 a,u64 v,u8 n){Trace* t=c->external_user_data;*t=(Trace){t->calls+1,c->pc,a,n,v};c->gpr[7]^=(u32)v;}
static void journal(u32 offset,u32 width,void* p){Trace* t=p;*t=(Trace){t->calls+1,0,offset,width,0};}
static u64 old_read(CPUState* c,u32 a,u32 n){switch(n){case 1:return mem_read8(c,a);case 2:return mem_read16(c,a);case 4:return mem_read32(c,a);default:return mem_read64(c,a);}}
static u64 new_read(CPUState* c,u32 a,u32 n,u32 cia){switch(n){case 1:return chunk_read8(c,c->ram,c->ram_size,a,cia);case 2:return chunk_read16(c,c->ram,c->ram_size,a,cia);case 4:return chunk_read32(c,c->ram,c->ram_size,a,cia);default:return chunk_read64(c,c->ram,c->ram_size,a,cia);}}
static void old_write(CPUState* c,u32 a,u64 v,u32 n){switch(n){case 1:mem_write8(c,a,(u8)v);break;case 2:mem_write16(c,a,(u16)v);break;case 4:mem_write32(c,a,(u32)v);break;default:mem_write64(c,a,v);}}
static void new_write(CPUState* c,u32 a,u64 v,u32 n,u32 cia){switch(n){case 1:chunk_write8(c,c->ram,c->ram_size,a,(u8)v,cia);break;case 2:chunk_write16(c,c->ram,c->ram_size,a,(u16)v,cia);break;case 4:chunk_write32(c,c->ram,c->ram_size,a,(u32)v,cia);break;default:chunk_write64(c,c->ram,c->ram_size,a,v,cia);}}
int main(void){
    const u32 bases[]={0x80000000u,0xC0000000u,0x90000000u,0xD0000000u,0xCC008000u,0};
    const u32 offsets[]={0,1,2,3,7,16,120,121,124,127,128,0xFFFFFFFFu};u32 cases=0,fast=0;
    for(u32 j=0;j<2;j++)for(u32 r=0;r<2;r++)for(u32 write=0;write<2;write++)for(u32 n=1;n<=8;n*=2)for(u32 bi=0;bi<6;bi++)for(u32 oi=0;oi<12;oi++){
        u8 ra[128],rb[128],ma[64],mb[64];for(u32 i=0;i<128;i++)ra[i]=(u8)(i*37u);memcpy(rb,ra,128);memset(ma,0xB7,64);memcpy(mb,ma,64);
        Trace ta={0},tb={0},ja={0},jb={0};CPUState a={0},b;
        a.ram=ra;a.ram_size=128;a.mem2=ma;a.mem2_size=64;a.external_read=probe_read;a.external_write=probe_write;a.external_user_data=&ta;
        a.reserve_valid=r!=0;a.reserve_addr=GC_RAM_BASE;a.pc=0x80001234u;b=a;b.ram=rb;b.mem2=mb;b.external_user_data=&tb;b.pc=0x81234560u;
        u32 address=bases[bi]+offsets[oi];u64 va=0,vb=0,value=0xAABBCCDDEEFF1234ull;
        ppc_set_mem_write_journal(j ? journal:NULL,&ja);if(write)old_write(&a,address,value,n);else va=old_read(&a,address,n);
        ppc_set_mem_write_journal(j ? journal:NULL,&jb);if(write)new_write(&b,address,value,n,0x80001234u);else vb=new_read(&b,address,n,0x80001234u);
        bool is_fast=(u64)(address-GC_RAM_BASE)+n<=128 && (!write || (!j && !r));
        if(is_fast){if(b.pc!=0x81234560u)return 1;fast++;}else if(b.pc!=a.pc)return 2;
        // Observe at the next explicit PC boundary, as in the transformed chunks.
        a.pc=b.pc=0x81800000u;b.ram=ra;b.mem2=ma;b.external_user_data=&ta;
        if(va!=vb || memcmp(&a,&b,sizeof(a)) || memcmp(ra,rb,128) || memcmp(ma,mb,64) || memcmp(&ta,&tb,sizeof(ta)) || memcmp(&ja,&jb,sizeof(ja))){fprintf(stderr,"chunk memory mismatch write=%u width=%u addr=%08X reserve=%u journal=%u\n",write,n,address,r,j);return 3;}
        cases++;
    }
    ppc_set_mem_write_journal(NULL,NULL);printf("[Chunk RAM] %u complete state/RAM/MMIO-CIA/reservation/journal comparisons; %u fast accesses skipped PC stores\n",cases,fast);return 0;
}
