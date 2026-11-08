#include "sdk_transfers.h"
#include "locked_cache.h"
#include <stdio.h>
#include <string.h>
bool g_native_blocks_enabled=true,transfer_oracle_stop;
void ref_transfer_xf(CPUState*);void ref_transfer_load(CPUState*);void ref_transfer_store(CPUState*);
static u8 fifo[2][128];static u32 sizes[2],stores[2],sink;
#define CHECK(x) do{if(!(x)){fprintf(stderr,"transfer FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
void gx_pipe_write_fifo_bytes(CPUState* c,const u8* bytes,u32 size,u32 count){(void)c;memcpy(fifo[sink]+sizes[sink],bytes,size);sizes[sink]+=size;stores[sink]+=count;}
static void port(CPUState* c,u32 address,u64 value,u8 size){
    (void)address;u8 bytes[8];for(u32 i=0;i<size;i++)bytes[size-1-i]=(u8)(value>>(i*8));gx_pipe_write_fifo_bytes(c,bytes,size,1);
}
static void spr_write(CPUState* c,u16 reg,u32 value,u32 cia){(void)cia;locked_cache_spr_write(c,reg,value);}
static u64 read_lc(CPUState* c,u32 address,u8 bytes){(void)c;return locked_cache_read(address,bytes);}
static void fallback(CPUState* c,u32 raw,u32 cia){
    u16 spr=(u16)(((raw>>16)&31u)|(((raw>>11)&31u)<<5));
    spr_write(c,spr,c->gpr[(raw>>21)&31u],cia);c->pc=cia+4;
}
static u8* pointer(CPUState* c,u32 address,u32 bytes){(void)c;return locked_cache_pointer(address,bytes);}
static int equal(CPUState* a,CPUState* b){
    b->ram=a->ram;if(!memcmp(a,b,sizeof(*a)))return 1;
    fprintf(stderr,"PC %08X/%08X budget %lld/%lld CR %08X/%08X\n",a->pc,b->pc,a->downcount,b->downcount,a->cr,b->cr);
    for(u32 i=0;i<32;i++)if(a->gpr[i]!=b->gpr[i])fprintf(stderr,"r%u %08X/%08X\n",i,a->gpr[i],b->gpr[i]);
    return 0;
}
int main(void){
    u8 a[8192]={0},b[8192];u32 cases=0;const u32 ids[]={0,1,63,64,127,0xFFFFFFF0u};
    for(u32 sample=0;sample<64;sample++)for(u32 type=0;type<2;type++)for(u32 id=0;id<6;id++)for(u32 route=0;route<2;route++)for(u32 lc=0;lc<2;lc++){
        CPUState c={0};c.ram=a;c.ram_size=sizeof(a);c.pc=0x802D4EBC;c.lr=0x81800000;c.downcount=sample&1 ? -240:1024;
        c.msr=0x2000;c.hid2=PPC_HID2_PSE|PPC_HID2_LSQE;c.gpr[3]=lc ? 0xE0001000u:0x80001000u;c.gpr[4]=ids[id];c.gpr[5]=type;c.cr=0x13579BDF;c.xer=(sample&3u)<<29;c.fpscr=0x1F000;
        c.external_write=port;c.external_read=read_lc;c.external_pointer=pointer;
        for(u32 r=0;r<32;r++){c.fpr[r]=r/8.;c.ps1[r]=-(double)r/16.;}
        u8* memory=lc ? locked_cache_pointer(c.gpr[3],48):a+4096;
        for(u32 i=0;i<12;i++){float x=((int)((i*31+sample*17)%257)-128)/16.f;u32 bits;memcpy(&bits,&x,4);if((i+sample)%5==0)bits=(sample&1)<<31;memory[i*4]=(u8)(bits>>24);memory[i*4+1]=(u8)(bits>>16);memory[i*4+2]=(u8)(bits>>8);memory[i*4+3]=(u8)bits;}
        memcpy(b,a,sizeof(a));CPUState expected=c;expected.ram=b;sizes[0]=sizes[1]=stores[0]=stores[1]=0;sink=0;transfer_oracle_stop=false;ref_transfer_xf(&expected);
        sink=1;if(route){transfer_oracle_stop=true;ref_transfer_xf(&c);transfer_oracle_stop=false;}
        CHECK(sdk_xf_load(&c));CHECK(equal(&c,&expected));CHECK(!memcmp(a,b,sizeof(a)) && sizes[0]==sizes[1] && stores[0]==stores[1] && !memcmp(fifo[0],fifo[1],sizes[0]));cases++;
    }
    u8 cache[16384],expected_cache[16384];const u32 offsets[]={0,32,8192,16352};
    for(u32 direction=0;direction<2;direction++)for(u32 blocks=0;blocks<128;blocks++)for(u32 at=0;at<4;at++)for(u32 route=0;route<2;route++){
        for(u32 i=0;i<8192;i++)a[i]=b[i]=(u8)(i*37+blocks*11);
        for(u32 i=0;i<16384;i++)cache[i]=(u8)(i*53+blocks*7);
        CPUState c={0};c.ram=a;c.ram_size=sizeof(a);c.pc=direction ? 0x802BF600:0x802BF5DC;c.lr=0x81800000;c.downcount=256;c.cr=0x13579BDF;c.spr_write=spr_write;c.instruction_fallback=fallback;
        c.gpr[direction ? 3:4]=0x80001000;c.gpr[direction ? 4:3]=0xE0000000+offsets[at];c.gpr[5]=blocks;
        CPUState expected=c;expected.ram=b;locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000,16384),cache,16384);
        while(expected.pc!=expected.lr){if(direction)ref_transfer_store(&expected);else ref_transfer_load(&expected);}
        memcpy(expected_cache,locked_cache_pointer(0xE0000000,16384),16384);u32 upper,lower;locked_cache_spr_read(922,&upper);locked_cache_spr_read(923,&lower);
        locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000,16384),cache,16384);
        if(route){transfer_oracle_stop=true;if(direction)ref_transfer_store(&c);else ref_transfer_load(&c);transfer_oracle_stop=false;}
        CHECK(sdk_lc_transfer(&c));CHECK(equal(&c,&expected));
        u32 x,y;locked_cache_spr_read(922,&x);locked_cache_spr_read(923,&y);
        CHECK(x==upper && y==lower && !memcmp(a,b,sizeof(a)) && !memcmp(expected_cache,locked_cache_pointer(0xE0000000,16384),16384));cases++;
    }
    for(u32 bad=0;bad<5;bad++){
        CPUState c={0};c.ram=a;c.ram_size=sizeof(a);c.pc=0x802D4EBC;c.gpr[3]=0x80001000;c.msr=0x2000;c.hid2=PPC_HID2_PSE|PPC_HID2_LSQE;
        for(u32 j=0;j<12;j++)mem_write32(&c,0x80001000+j*4,0x3F800000u);
        if(bad==0)c.msr=0;if(bad==1)c.hid2=0;if(bad==2)c.gqr[0]=7;if(bad==3)c.gpr[3]++;if(bad==4)mem_write32(&c,0x80001000,0x7FC12345u);
        CPUState unchanged=c;CHECK(!sdk_xf_load(&c) && !memcmp(&c,&unchanged,sizeof(c)));
    }
    printf("[SDK transfers] %u full CPU/FIFO/RAM/LC comparisons: XF8/12, IDs, charged continuations, LC wrap/zero128 passed\n",cases);return 0;
}
