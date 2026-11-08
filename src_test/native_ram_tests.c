#define PRIMARY_RAM_NO_REDIRECT
#include "primary_ram.h"
#define NATIVE_RAM_NO_REDIRECT
#include "cpu_native_adapter.h"
#include <stdio.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"FAIL native RAM line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static u32 s_ram_probe_calls,s_ram_probe_address,s_ram_probe_bytes;
static u64 ram_probe_read(CPUState* c,u32 address,u8 bytes) {
    s_ram_probe_calls++;s_ram_probe_address=address;s_ram_probe_bytes=bytes;c->gpr[7]^=address;
    return 0xC0DE0000u^address;
}
static void ram_probe_write(CPUState* c,u32 address,u64 value,u8 bytes) {
    s_ram_probe_calls++;s_ram_probe_address=address;s_ram_probe_bytes=bytes;c->gpr[9]^=(u32)value;
}
static void ram_probe_journal(u32 address,u32 bytes,void* user) {
    (void)user;s_ram_probe_calls++;s_ram_probe_address=address;s_ram_probe_bytes=bytes;
}
static int native_ram_contracts(void) {
    const u32 addresses[]={0,1,28,29,31,32,0x80000000u,0x80000001u,0x8000001Cu,0x8000001Du,0x8000001Fu,
        0xC0000000u,0xC0000001u,0xC000001Cu,0xC000001Du,0xC000001Fu,0x40000000u,0x4000001Cu,
        0x90000000u,0x90000001u,0x9000001Cu,0x9000001Du,0xD0000000u,0xD000001Cu,0xD000001Du,
        0xCC008000u,0xE0000000u,0xFFFFFFFCu,0xFFFFFFFFu};
    const u32 sizes[]={0,1,2,3,4,31,32};
    u8 a[32],b[32],ma[32],mb[32];bool saved=g_native_ram_inline_enabled;u32 cases=0;
    for(u32 enabled=0;enabled<3;enabled++)for(u32 reserve=0;reserve<2;reserve++)for(u32 journal=0;journal<2;journal++)
    for(u32 n=0;n<7;n++)for(u32 k=0;k<sizeof(addresses)/sizeof(addresses[0]);k++) {
        CPUState actual={0};actual.ram=a;actual.ram_size=sizes[n];actual.mem2=ma;actual.mem2_size=32;
        actual.reserve_valid=reserve!=0;actual.reserve_addr=0xC0000010u;actual.external_read=ram_probe_read;actual.external_write=ram_probe_write;
        CPUState expected=actual;expected.ram=b;expected.mem2=mb;
        for(u32 i=0;i<32;i++){a[i]=b[i]=(u8)(i*37u+k*19u);ma[i]=mb[i]=(u8)(i*53u+k*11u);}
        g_native_ram_inline_enabled=enabled!=0;
        s_ram_probe_calls=0;u32 ref=mem_read32(&expected,addresses[k]);
        u32 calls=s_ram_probe_calls,at=s_ram_probe_address,bytes=s_ram_probe_bytes;
        s_ram_probe_calls=0;u32 value=enabled==2 ? primary_read32(&actual,addresses[k]):native_mem_read32(&actual,addresses[k]);
        CHECK(ref==value && calls==s_ram_probe_calls && at==s_ram_probe_address && bytes==s_ram_probe_bytes);
        ppc_set_mem_write_journal(journal ? ram_probe_journal:NULL,NULL);
        s_ram_probe_calls=0;mem_write32(&expected,addresses[k],0x12345678u^k);
        calls=s_ram_probe_calls;at=s_ram_probe_address;bytes=s_ram_probe_bytes;
        s_ram_probe_calls=0;if(enabled==2)primary_write32(&actual,addresses[k],0x12345678u^k);else native_mem_write32(&actual,addresses[k],0x12345678u^k);
        ppc_set_mem_write_journal(NULL,NULL);
        CHECK(calls==s_ram_probe_calls && at==s_ram_probe_address && bytes==s_ram_probe_bytes);
        CHECK(!memcmp(a,b,32) && !memcmp(ma,mb,32));expected.ram=a;expected.mem2=ma;
        CHECK(!memcmp(&actual,&expected,sizeof(actual)));cases++;
    }
    g_native_ram_inline_enabled=saved;printf("[Native RAM] %u cases: aliases, boundaries, MMIO, reservation and journal equal\n",cases);return 0;
}

static int write_watch_contracts(void){
    CPUState cpu={0};CHECK(cpu_init(&cpu));u64 before[4],after[4],queries,dirty,queries_after;u32 count=0;
#if defined(_WIN32) && DOLRECOMP_RAM_TRACKING
    ppc_ram_watch_frame(&cpu);ppc_ram_watch_stats(&queries,&dirty);
    CHECK(ppc_ram_page_versions(&cpu,0,12288,before,4,&count) && count==4);
    mem_write32(&cpu,0x80000FFEu,0x11223344u);
    CHECK(ppc_ram_page_versions(&cpu,0,12288,after,4,&count));
    CHECK(before[0]==after[0] && before[1]!=after[1] && before[2]!=after[2] && before[3]==after[3]);memcpy(before,after,sizeof(before));
    for(u32 i=0;i<128;i++)CHECK(ppc_ram_page_versions(&cpu,0,12288,after,4,&count) && !memcmp(before,after,sizeof(before)));
    ppc_ram_watch_stats(&queries_after,&dirty);CHECK(queries==queries_after); // no syscall from draws
    cpu.ram[0]^=1;ppc_ram_watch_frame(&cpu);
    CHECK(ppc_ram_page_versions(&cpu,0,4096,after,4,&count) && after[1]!=before[1]);
    CHECK(ppc_ram_page_versions(&cpu,4096,8192,before,4,&count));
    u8 bytes[16]={1,2,3,4};ppc_mark_host_write(cpu.ram+8188,16);memcpy(cpu.ram+8188,bytes,16);
    CHECK(ppc_ram_page_versions(&cpu,4096,8192,after,4,&count) && before[1]!=after[1] && before[2]!=after[2]);
    CHECK(ppc_ram_page_versions(&cpu,0,4096,before,4,&count));
    mem_write32(&cpu,0xC0000000u,0x12345678);
    CHECK(ppc_ram_page_versions(&cpu,0,4096,after,4,&count) && before[1]!=after[1]);
    cpu.hid2=PPC_HID2_PSE|PPC_HID2_LSQE;cpu.fpr[2]=1.5;cpu.ps1[2]=-2.0;before[1]=after[1];
    CHECK(ppc_psq_store_inline(&cpu,2,0x80000020u,false,0,false,0x80001000u));
    CHECK(ppc_ram_page_versions(&cpu,0,4096,after,4,&count) && before[1]!=after[1]);
    CHECK(!ppc_ram_page_versions(&cpu,cpu.ram_size-2,4,after,4,&count));
    printf("[RAM write watch] inline primary/runtime/PSQ and bulk generations; zero syscalls in128 draw queries; raw-write frame barrier passed\n");
#endif
    cpu_free(&cpu);return 0;
}
static int approximate_float_contracts(void){
    bool saved=g_fast_float_enabled;u32 cases=0;CPUState seed={0};
    seed.fpscr=0x1F000u;ppc_fpscr_control_updated(&seed);
    for(u32 i=0;i<512;i++)for(u32 op=0;op<10;op++){
        seed.fpr[2]=((int)(i%31)-15)/8.0;seed.ps1[2]=((int)(i%19)-9)/4.0;
        seed.fpr[3]=((int)(i%13)-6)/16.0;seed.ps1[3]=((int)(i%17)-8)/8.0;
        seed.fpr[4]=((int)(i%7)-3)/4.0;seed.ps1[4]=((int)(i%11)-5)/16.0;
        CPUState reference=seed,fast=seed;
        for(u32 route=0;route<2;route++){
            CPUState* c=route ? &fast:&reference;g_fast_float_enabled=route!=0;
            switch(op){
            case 0:ppc_fadds(c,20,2,3);break;case 1:ppc_fsubs(c,20,2,3);break;case 2:ppc_fmuls(c,20,2,3);break;
            case 3:ppc_ps_add_op(c,20,2,3);break;case 4:ppc_ps_sub_op(c,20,2,3);break;case 5:ppc_ps_mul_op(c,20,2,3);break;
            case 6:ppc_ps_madd_op(c,20,2,3,4,false,false);break;case 7:ppc_ps_madds0(c,20,2,3,4);break;
            case 8:ppc_ps_sum0(c,20,2,3,4);break;
            case 9:{f64 value;CHECK(ppc_fma(c,c->fpr[2],c->fpr[3],c->fpr[4],true,false,false,&value));c->fpr[20]=value;break;}
            }
        }
        CHECK(!memcmp(reference.fpr,fast.fpr,sizeof(fast.fpr)) && !memcmp(reference.ps1,fast.ps1,sizeof(fast.ps1)));
        CHECK(fast.fpscr==seed.fpscr);cases++;
    }
    CPUState a=seed,b=seed;g_fast_float_enabled=false;ppc_fcmp(&a,3,1.0,2.0,false);
    g_fast_float_enabled=true;ppc_fcmp(&b,3,1.0,2.0,false);CHECK(a.cr==b.cr && a.fpscr==b.fpscr);
    g_fast_float_enabled=saved;printf("[Approximate float] %u finite-domain numeric cases, arithmetic FPSCR unchanged, fcmp exact; no claim for exceptional inputs\n",cases);return 0;
}
int main(void){if(ppc_scalar_fast_contracts() || write_watch_contracts() || approximate_float_contracts())return 1;return native_ram_contracts();}
