#include "frame_timing.h"
#define SDL_MAIN_HANDLED
#define DOLRECOMP_ENABLE_REPLACEMENTS
#include "generated.h"
#include "video_audio.h"
#include "gx_pipe.h"
#include "gx_gl.h"
#include "dvd_vfs.h"
#include "dol_loader.h"
#include "hle_callbacks.h"
#include "ax_hle.h"
#include "os_context.h"
#include "locked_cache.h"
#include "input.h"
#include "paired_skinning.h"
#include "sdk_mtx44.h"
#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

extern bool g_native_blocks_enabled;
extern bool g_float_bits_enabled;
extern const bool g_float_bits_available;
extern u64 platform_native_block_entries(void);
extern bool handle_guest_exception(CPUState*);
extern void handle_instruction_fallback(CPUState*,u32,u32);
extern u64 handle_external_read(CPUState*, u32, u8);
extern void handle_external_write(CPUState*, u32, u64, u8);
extern void* handle_external_pointer(CPUState*,u32,u32);
extern int platform_execute_cpu_slice(CPUState*);
extern void platform_set_cpu_quantum(u32);
#define CHECK(x) do { if (!(x)) { fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #x); return 1; } } while (0)
static void fifo(CPUState* cpu, u32 value, u8 size) { handle_external_write(cpu, 0xCC008000u, value, size); }
static void bp(CPUState* cpu, u8 reg, u32 value) { fifo(cpu, 0x61, 1); fifo(cpu, ((u32)reg << 24) | value, 4); }
static void cp(CPUState* cpu, u8 reg, u32 value) { fifo(cpu, 8, 1); fifo(cpu, reg, 1); fifo(cpu, value, 4); }
static void xf(CPUState* cpu,u16 reg,u32 value) {fifo(cpu,0x10,1);fifo(cpu,0,2);fifo(cpu,reg,2);fifo(cpu,value,4);}
static void cache_reference_mode(CPUState* cpu,u8 operation,u32 address,u32 cia) {(void)cpu;(void)operation;(void)address;(void)cia;}
static int keyboard_multiplayer_contracts(void) {
    Uint8 keys[SDL_NUM_SCANCODES]={0};NativePadState pads[4]={0};
    pads[0].connected=true;pads[0].button=PAD_BUTTON_Y;pads[0].stick_x=-42;pads[0].stick_y=100;
    NativePadState first=pads[0];
    const SDL_Scancode numbers[]={SDL_SCANCODE_7,SDL_SCANCODE_8,SDL_SCANCODE_9,SDL_SCANCODE_KP_7,SDL_SCANCODE_KP_8,SDL_SCANCODE_KP_9};
    for(u32 k=0;k<6;k++)for(u32 shift=0;shift<3;shift++) {
        memset(keys,0,sizeof(keys));keys[numbers[k]]=1;
        if(shift)keys[shift==1 ? SDL_SCANCODE_LSHIFT:SDL_SCANCODE_RSHIFT]=1;
        CHECK(input_map_extra_keys(keys,true,pads)==(shift!=0));
        CHECK(!memcmp(&pads[0],&first,sizeof(first)));
        for(u32 port=1;port<4;port++) {
            CHECK(pads[port].connected);
            CHECK(pads[port].button==(port==k%3+1 ? (shift ? PAD_BUTTON_START:PAD_BUTTON_A):0));
        }
        memset(keys,0,sizeof(keys));CHECK(!input_map_extra_keys(keys,true,pads));
        for(u32 port=1;port<4;port++)CHECK(!pads[port].button);
    }
    keys[SDL_SCANCODE_7]=keys[SDL_SCANCODE_8]=keys[SDL_SCANCODE_9]=1;
    CHECK(!input_map_extra_keys(keys,true,pads));
    for(u32 port=1;port<4;port++)CHECK(pads[port].button==PAD_BUTTON_A);
    CHECK(!input_map_extra_keys(NULL,false,pads));
    for(u32 port=1;port<4;port++)CHECK(!pads[port].button);
    u8 memory[80],before[80];CPUState cpu={0};cpu.ram=memory;cpu.ram_size=sizeof(memory);
    memset(memory,0xCD,sizeof(memory));pads[1].button=PAD_BUTTON_A;pads[2].button=PAD_BUTTON_START;
    CHECK(input_store_pad_status(&cpu,0x80000010u,pads)==0xF0000000u);
    CHECK(mem_read16(&cpu,0x80000010u)==PAD_BUTTON_Y);
    CHECK(memory[18]==(u8)-42 && memory[19]==100);
    CHECK(mem_read16(&cpu,0x8000001Cu)==PAD_BUTTON_A && memory[36]==255);
    CHECK(mem_read16(&cpu,0x80000028u)==PAD_BUTTON_START && memory[48]==0);
    for(u32 i=0;i<16;i++)CHECK(memory[i]==0xCD && memory[64+i]==0xCD);
    pads[2].connected=false;
    CHECK(input_store_pad_status(&cpu,0x80000010u,pads)==0xD0000000u);
    for(u32 i=40;i<52;i++)CHECK(memory[i]==(i==50 ? 255:0));
    memcpy(before,memory,sizeof(memory));
    CHECK(input_store_pad_status(&cpu,0xFFFFFFFCu,pads)==0xD0000000u);
    CHECK(input_store_pad_status(&cpu,0x80000021u,pads)==0xD0000000u);
    CHECK(!memcmp(before,memory,sizeof(memory)));
    printf("[Keyboard multiplayer] 7/8/9 and keypad: independent A/Start, release/focus, four guest statuses and bounds equal\n");return 0;
}
static int generated_float_contracts(void) {
    if(!g_float_bits_available){printf("[Generated float mappings] experimental adapter compiled out\n");return 0;}
    u8 memory[1024],reference[1024],lc_expected[1024],lc_initial[1024];u32 cases=0;
    const u32 patterns[]={0,0x80000000u,1,0x007FFFFFu,0x00800000u,0x3F800000u,0xBF800001u,0x7F7FFFFFu,
        0x7F800000u,0xFF800000u,0x7FC12345u,0x7F812345u,0xFFC12345u,0xFF812345u,0x00800001u,0x80800001u};
    const u32 bases[]={0x80000000u,0xC0000000u,0xE0000000u};const s64 budgets[]={-255,768};
    for(u32 p=0;p<16;p++)for(u32 loc=0;loc<3;loc++)for(u32 ni=0;ni<2;ni++)for(u32 rn=0;rn<4;rn++)for(u32 bi=0;bi<2;bi++) {
        memset(memory,0xA5,sizeof(memory));locked_cache_reset();CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);
        seed.pc=0x80278CC4u;seed.lr=0x81800000u;seed.msr=0x2000u;seed.hid2=0xA0000000u;
        seed.fpscr=0x82060000u|rn|(ni ? 4u:0u);seed.fpr[1]=1.125;seed.ps1[1]=-2.25;seed.downcount=budgets[bi];
        seed.external_read=handle_external_read;seed.external_write=handle_external_write;seed.external_pointer=handle_external_pointer;
        seed.gpr[3]=bases[loc]+0x100u;
        for(u32 i=0;i<6;i++)mem_write32(&seed,seed.gpr[3]+i*4,patterns[(p+i)%16]);
        memcpy(reference,memory,sizeof(memory));memcpy(lc_initial,locked_cache_pointer(0xE0000000u,sizeof(lc_initial)),sizeof(lc_initial));
        CPUState expected=seed;expected.ram=reference;g_float_bits_enabled=false;ppc_fpscr_control_updated(&expected);func_802774C0(&expected);
        CHECK(expected.pc==expected.lr && !expected.exception);
        memcpy(lc_expected,locked_cache_pointer(0xE0000000u,sizeof(lc_expected)),sizeof(lc_expected));
        locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(lc_initial)),lc_initial,sizeof(lc_initial));
        CPUState actual=seed;g_float_bits_enabled=true;ppc_fpscr_control_updated(&actual);func_802774C0(&actual);
        expected.ram=actual.ram;CHECK(!memcmp(&actual,&expected,sizeof(actual)));CHECK(!memcmp(memory,reference,sizeof(memory)));
        CHECK(!memcmp(lc_expected,locked_cache_pointer(0xE0000000u,sizeof(lc_expected)),sizeof(lc_expected)));cases++;
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[Generated float mappings] %u original/compact chunk CPU/RAM/LC/budget comparisons passed\n",cases);return 0;
}
static int sdk_matrix_entry_contracts(void) {
    u8 memory[2048],reference[2048],initial_lc[16384],expected_lc[16384];u32 cases=0;
    const s64 budgets[]={-255,768};
    for(u32 lc=0;lc<2;lc++)for(u32 ni=0;ni<2;ni++)for(u32 rn=0;rn<4;rn++)for(u32 bi=0;bi<2;bi++) {
        memset(memory,0xA5,sizeof(memory));locked_cache_reset();CPUState seed={0};
        seed.ram=memory;seed.ram_size=sizeof(memory);seed.pc=0x802B4D08u;seed.lr=0x81800003u;
        seed.msr=0x2000u;seed.hid2=0xA0000000u;seed.downcount=budgets[bi];seed.fpscr=0x82060000u|rn|(ni ? 4u:0u);
        seed.external_read=handle_external_read;seed.external_write=handle_external_write;seed.external_pointer=handle_external_pointer;
        for(u32 r=0;r<32;r++){seed.gpr[r]=r*37u;seed.fpr[r]=r+0.125;seed.ps1[r]=-(r+0.25);}
        for(u32 i=0;i<3;i++)seed.gpr[3+i]=(lc ? 0xE0000000u:0x80000000u)+(i+1)*0x100u;
        for(u32 i=0;i<16;i++) {
            float a=((int)i-7)*0.125f,b=((int)i-5)*0.25f;u32 ab,bb;memcpy(&ab,&a,4);memcpy(&bb,&b,4);
            mem_write32(&seed,seed.gpr[3]+i*4,ab);mem_write32(&seed,seed.gpr[4]+i*4,bb);
        }
        memcpy(initial_lc,locked_cache_pointer(0xE0000000u,sizeof(initial_lc)),sizeof(initial_lc));
        memcpy(reference,memory,sizeof(memory));CPUState expected=seed;expected.ram=reference;
        g_native_blocks_enabled=false;ppc_fpscr_control_updated(&expected);func_802B34C0(&expected);
        CHECK(expected.pc==0x81800000u && !expected.exception);
        memcpy(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc));
        locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(initial_lc)),initial_lc,sizeof(initial_lc));
        CPUState actual=seed;u64 before=sdk_mtx44_calls(),entries=platform_native_block_entries();
        g_native_blocks_enabled=true;ppc_fpscr_control_updated(&actual);func_802B34C0(&actual);g_native_blocks_enabled=false;
        CHECK(sdk_mtx44_calls()==before+(sdk_mtx44_available() ? 1u:0u));
        CHECK(platform_native_block_entries()==entries+(sdk_mtx44_available() ? 1u:0u));
        expected.ram=actual.ram;CHECK(!memcmp(&actual,&expected,sizeof(actual)));
        CHECK(!memcmp(memory,reference,sizeof(memory)));
        CHECK(!memcmp(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc)));cases++;
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[SDK matrix entry] %u original/automatic CPU/RAM/LC/budget comparisons passed\n",cases);return 0;
}
static int paired_skinning_contracts(void) {
    u8 ram_a[8192],ram_b[8192];
    const s64 budgets[]={-255,0,200,768};const u32 counts[]={1,2,9,40};
    const u32 loops[]={0x8024BC48u};
    const u32 tails[]={0x8024BCECu};
    for(u32 loop=0;loop<1;loop++)for(u32 mode=0;mode<4;mode++)for(u32 bi=0;bi<4;bi++)for(u32 ci=0;ci<4;ci++) {
        CPUState fast={0};fast.ram=ram_a;fast.ram_size=sizeof(ram_a);
        fast.pc=loops[loop];fast.msr=0x2000u;fast.hid2=0xA0000000u;
        fast.gpr[1]=0x80001C00u;fast.gpr[5]=0x80000800u;
        fast.gpr[6]=0x80000100u;fast.gpr[7]=0x80001000u;
        fast.lr=0x81800000u;fast.ctr=counts[ci];fast.downcount=budgets[bi];fast.fpscr=mode;
        fast.gqr[7]=(8u<<24)|(7u<<16)|(8u<<8)|7u;
        fast.gqr[6]=(8u<<24)|((4u+ci)<<16);
        for(u32 i=0;i<sizeof(ram_a);i++)ram_a[i]=(u8)(i*37u+ci*19u);
        for(u32 i=0;i<32;i++){fast.fpr[i]=((s32)i-15)*0.125;fast.ps1[i]=((s32)i-12)*0.25;}
        memcpy(ram_b,ram_a,sizeof(ram_a));CPUState original=fast;original.ram=ram_b;
        ppc_fpscr_control_updated(&fast);
        func_8024B4C0(&original);
        ppc_fpscr_control_updated(&fast);
        CHECK(paired_skinning_step(&fast));
        if(fast.pc==tails[loop])func_8024B4C0(&fast);
        CHECK(memcmp(ram_a,ram_b,sizeof(ram_a))==0);
        original.ram=fast.ram;
        CHECK(memcmp(&fast,&original,sizeof(fast))==0);
    }
    CPUState invalid={0};invalid.pc=0x8024BC48u;CPUState before=invalid;
    CHECK(!paired_skinning_step(&invalid) && memcmp(&invalid,&before,sizeof(invalid))==0);
    return 0;
}
static u32 s_memory_probe_address,s_memory_probe_size;
static u64 memory_probe_read(CPUState* cpu,u32 address,u8 size) {
    (void)cpu;s_memory_probe_address=address;s_memory_probe_size=size;
    return 0x1122334455667788ull;
}
static int skinning_accumulate_benchmark(CPUState seed,const u8* initial) {
    if(!paired_skinning_accumulate_available()){printf("[Skinning benchmark] native FMA unavailable; original path retained\n");return 0;}
    u8 ram[8192];u64 ticks[2];u32 sums[2]={2166136261u,2166136261u};const u32 repeats=5000;
    seed.gqr[7]=(seed.gqr[7]&~0x3F00u)|(8u<<8);
    for(u32 mode=0;mode<2;mode++) {
        u64 start=SDL_GetPerformanceCounter();
        for(u32 n=0;n<repeats;n++) {
            memcpy(ram,initial,sizeof(ram));CPUState work=seed;work.ram=ram;work.downcount=4096;
            u32 steps=0;
            while(work.pc!=work.lr && steps++<1000) {
                if(mode && work.pc==0x8024C244u && paired_skinning_accumulate_step(&work))continue;
                func_8024B4C0(&work);
            }
            CHECK(work.pc==work.lr);
            for(u32 k=0;k<seed.ctr*12;k++)sums[mode]=(sums[mode]^ram[0x1000+k])*16777619u;
            u64 result;memcpy(&result,&work.fpr[11],8);sums[mode]^=(u32)result^(u32)(result>>32)^work.fpscr;
        }
        ticks[mode]=SDL_GetPerformanceCounter()-start;
    }
    CHECK(sums[0]==sums[1]);
    double unit=1000.0/(double)SDL_GetPerformanceFrequency();
    printf("[Skinning benchmark] %u vertices: original=%.3f ms native=%.3f ms speedup=%.2fx checksum=%08X\n",repeats*seed.ctr,ticks[0]*unit,ticks[1]*unit,(double)ticks[0]/ticks[1],sums[0]);
    return 0;
}
static int coherent_skinning_contracts(void) {
    u8 ram_a[8192],ram_b[8192];
    const u32 counts[]={2,9,37};
    u32 slow_total=0,fast_total=0;
    u64 accumulated_before=paired_skinning_accumulated();
    const f64 observed_matrix[16]={0x1.51e5a40000000p-11,-0x1.521c600000000p-2,-0x1.ffdb700000000p-1,0x1.69a0d00000000p-6,0x1.82ce7e0000000p-6,0x1.e327180000000p-1,-0x1.607bb00000000p-3,-0x1.326d000000000p-7,0x1.e348e40000000p-1,0x1.0000000000000p+0,0x1.135d980000000p-7,0x1.0000000000000p+0,0x1.5200820000000p-2,0x1.0000000000000p+0,-0x1.a5c7320000000p-2,0x1.0000000000000p+0};
    for(u32 lc=0;lc<2;lc++)
    for(u32 entry=0;entry<2;entry++)
    for(u32 pattern=0;pattern<3;pattern++)
    for(u32 ni=0;ni<2;ni++)for(int qs=-16;qs<=16;qs+=8)
    for(u32 rounding=0;rounding<4;rounding++)for(u32 ci=0;ci<3;ci++) {
        CPUState fast={0};fast.ram=ram_a;fast.ram_size=sizeof(ram_a);
        fast.pc=entry ? 0x8024C2CCu:0x8024C244u;fast.msr=0x2000u;fast.hid2=0xA0000000u;
        fast.fpscr=rounding|(ni ? 4u:0u);fast.ctr=counts[ci];fast.lr=0x81800000u;
        fast.instruction_fallback=handle_instruction_fallback;
        fast.gpr[1]=0x80001B00u;fast.gpr[5]=0x80000108u;
        fast.gpr[6]=0x80001000u;fast.gpr[7]=0x80000C00u;
        fast.gpr[8]=0x800007FFu;fast.gpr[21]=fast.gpr[6];
        fast.gqr[7]=((u32)(qs&63)<<24)|(7u<<16)|((u32)((-qs)&63)<<8)|7u;
        fast.gqr[6]=((u32)(qs&63)<<24)|(4u<<16);
        memset(ram_a,0,sizeof(ram_a));
        for(u32 i=0;i<1024;i++)ram_a[0x100+i]=(u8)(i*37u);
        for(u32 i=0;i<=counts[ci];i++) {
            u32 index=pattern==0 ? i:pattern==1 ? 0:counts[ci]-i;
            ram_a[0xC00+i*2]=(u8)(index>>8);ram_a[0xC01+i*2]=(u8)index;
            ram_a[0x800+i]=(u8)(i*17u);
        }
        for(u32 i=0;i<32;i++){fast.fpr[i]=((s32)i-15)*0.125;fast.ps1[i]=((s32)i-12)*0.25;}
        if(qs==-16)for(u32 i=0;i<8;i++){fast.fpr[i]=(i&1) ? -65536.0:65536.0;fast.ps1[i]=(i&2) ? -0x1p-16:0x1p-16;}
        if(qs==16)for(u32 i=0;i<8;i++){fast.fpr[i]=(i&1) ? -0.0:0.0;fast.ps1[i]=0x1p-16;}
        if(pattern==2 && qs==8) {
            fast.gqr[6]=0x08040804u;fast.gqr[7]=0x0C070C07u;
            for(u32 i=0;i<8;i++){fast.fpr[i]=observed_matrix[i];fast.ps1[i]=observed_matrix[8+i];}
        }
        if(lc) {
            locked_cache_reset();
            memcpy(locked_cache_pointer(0xE0000000u,sizeof(ram_a)),ram_a,sizeof(ram_a));
            fast.external_read=handle_external_read;fast.external_write=handle_external_write;
            fast.external_pointer=handle_external_pointer;
            fast.gpr[5]=0xE0000108u;fast.gpr[7]=0xE0000C00u;fast.gpr[8]=0xE00007FFu;
        }
        if(getenv("SKINNING_BENCH") && !lc && !entry && !pattern && !ni && qs==8 && !rounding && ci==2) {
            ppc_fpscr_control_updated(&fast);CHECK(skinning_accumulate_benchmark(fast,ram_a)==0);
        }
        memcpy(ram_b,ram_a,sizeof(ram_a));CPUState original=fast;original.ram=ram_b;
        original.cache_control=cache_reference_mode;
        u32 slow_calls=0,fast_calls=0;
        u64 native_before_case=paired_skinning_accumulated();
        ppc_fpscr_control_updated(&original);
        while(original.pc!=original.lr && slow_calls<1000){CHECK(platform_execute_cpu_slice(&original));slow_calls++;}
        ppc_fpscr_control_updated(&fast);
        while(fast.pc!=fast.lr && fast_calls<1000){CHECK(platform_execute_cpu_slice(&fast));fast_calls++;}
                // A two-vertex batch entered after dcbst can need the same two
        // dispatches (loop + original epilogue). Larger batches must improve
        // the aggregate; every case must preserve the architectural result.
        CHECK(fast.pc==fast.lr && original.pc==original.lr && fast_calls<=slow_calls);
        slow_total+=slow_calls;fast_total+=fast_calls;
        CHECK(!paired_skinning_accumulate_available() || paired_skinning_accumulated()>native_before_case);
        CHECK(memcmp(ram_a,ram_b,sizeof(ram_a))==0);
        original.ram=fast.ram;original.cache_control=fast.cache_control;
        original.downcount=fast.downcount; // Same arithmetic; fewer slice-budget resets.
        CHECK(memcmp(&fast,&original,sizeof(fast))==0);
    }
    CHECK(fast_total<slow_total);
    CHECK(!paired_skinning_accumulate_available() || paired_skinning_accumulated()>accumulated_before);
    CPUState seed={0};seed.ram=ram_a;seed.ram_size=sizeof(ram_a);seed.pc=0x8024C244u;
    seed.msr=0x2000u;seed.hid2=0xA0000000u;seed.ctr=2;seed.downcount=768;
    seed.gqr[7]=(7u<<16)|7u;seed.gqr[6]=4u<<16;
    seed.gpr[5]=0x80000100u;seed.gpr[7]=0x80000200u;seed.gpr[8]=0x80000300u;seed.gpr[21]=0x80001000u;
    for(u32 i=0;i<32;i++){seed.fpr[i]=1;seed.ps1[i]=1;}
    for(u32 test=0;test<6;test++) {
        CPUState rejected=seed;
        if(test==0)rejected.fpr[0]=NAN;
        if(test==1)rejected.fpr[0]=DBL_MIN;
        if(test==2)rejected.gqr[7]=0;
        if(test==3)rejected.gpr[21]=0x80000000u+sizeof(ram_a)-6;
        if(test==4)rejected.reserve_valid=true;
        if(test==5)rejected.cache_control=cache_reference_mode;
        CPUState before=rejected;memcpy(ram_b,ram_a,sizeof(ram_a));
        CHECK(!paired_skinning_accumulate_step(&rejected));
        CHECK(memcmp(&before,&rejected,sizeof(before))==0 && memcmp(ram_a,ram_b,sizeof(ram_a))==0);
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[CPU cache boundaries] original=%u grouped=%u: CPU/RAM equal\n",slow_total,fast_total);
    return 0;
}
static int transform_skinning_benchmark(CPUState seed,const u8* initial) {
    if(!paired_skinning_accumulate_available())return 0;
    u8 ram[8192];u64 ticks[2];u32 sums[2]={2166136261u,2166136261u};const u32 repeats=5000;
    for(u32 mode=0;mode<2;mode++) {
        u64 start=SDL_GetPerformanceCounter();
        for(u32 n=0;n<repeats;n++) {
            memcpy(ram,initial,sizeof(ram));CPUState work=seed;work.ram=ram;work.downcount=4096;u32 steps=0;
            while(work.pc!=work.lr && steps++<1000) {
                if(mode && (paired_skinning_transform_entry(&work) || paired_skinning_transform_step(&work)))continue;
                func_8024B4C0(&work);
            }
            CHECK(work.pc==work.lr);
            for(u32 k=0;k<(seed.ctr+1)*12;k++)sums[mode]=(sums[mode]^ram[0x1000+k])*16777619u;
            sums[mode]^=work.fpscr^(u32)work.downcount;
        }
        ticks[mode]=SDL_GetPerformanceCounter()-start;
    }
    CHECK(sums[0]==sums[1]);double unit=1000.0/(double)SDL_GetPerformanceFrequency();
    printf("[Rigid transform benchmark] entry=%08X %u loop vertices: original=%.3f ms native=%.3f ms speedup=%.2fx checksum=%08X\n",seed.pc,repeats*seed.ctr,ticks[0]*unit,ticks[1]*unit,(double)ticks[0]/ticks[1],sums[0]);return 0;
}
static int transform_skinning_contracts(bool automatic) {
    u8 memory[8192],reference[8192],lc_result[8192];u32 cases=0;u64 native=paired_skinning_transformed();
    const u32 counts[]={1,2,37,101};const s64 budgets[]={-255,0,768};
    for(u32 entry=0;entry<2;entry++)for(u32 lc=0;lc<2;lc++)for(u32 alias=0;alias<4;alias++)
    for(u32 ni=0;ni<2;ni++)for(u32 rounding=0;rounding<4;rounding++)
    for(int scale=-16;scale<=16;scale+=8)for(u32 ci=0;ci<4;ci++)for(u32 bi=0;bi<3;bi++) {
        CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);seed.pc=0x8024C014u;
        seed.lr=0x81800000u;seed.msr=0x2000u;seed.hid2=0xA0000000u;seed.fpscr=rounding|(ni ? 4u:0u);
        seed.ctr=counts[ci];seed.downcount=budgets[bi];seed.gpr[1]=0x80001B00u;
        seed.gqr[7]=((u32)(scale&63)<<24)|(7u<<16)|((u32)((-scale)&63)<<8)|7u;
        seed.gpr[4]=0x800001FCu;seed.gpr[5]=alias==0 ? 0x80000FFEu:0x800001FEu+(alias-2)*12u;
        if(entry){seed.pc=0x8024BF84u;seed.gpr[3]=0x80000080u;seed.gpr[6]=counts[ci]+1;seed.gpr[5]+=2;}
        for(u32 r=0;r<32;r++){seed.fpr[r]=((s32)r-13)*0.125;seed.ps1[r]=((s32)r-11)*0.25;}
        for(u32 i=0;i<sizeof(memory);i++)memory[i]=(u8)(i*37u+ci*53u);
        if(entry)for(u32 i=0;i<12;i++) {
            float value=((int)i-5)*0.125f;u32 bits;memcpy(&bits,&value,4);
            for(u32 b=0;b<4;b++)memory[0x80+i*4+b]=(u8)(bits>>(24-b*8));
        }
        if(getenv("SKINNING_BENCH") && !lc && !alias && !ni && !rounding && scale==8 && ci==3 && bi==2) {
            ppc_fpscr_control_updated(&seed);CHECK(transform_skinning_benchmark(seed,memory)==0);
        }
        if(lc) {
            seed.external_read=handle_external_read;seed.external_write=handle_external_write;seed.external_pointer=handle_external_pointer;
            seed.gpr[4]+=0x60000000u;seed.gpr[5]+=0x60000000u;
        }
        memcpy(reference,memory,sizeof(memory));CPUState expected=seed;expected.ram=reference;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        g_native_blocks_enabled=false;
        ppc_fpscr_control_updated(&expected);u32 steps=0;
        while(expected.pc!=expected.lr && steps++<1000)func_8024B4C0(&expected);
        CHECK(expected.pc==expected.lr);
        if(lc)memcpy(lc_result,locked_cache_pointer(0xE0000000u,sizeof(memory)),sizeof(memory));
        CPUState actual=seed;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        g_native_blocks_enabled=automatic;
        ppc_fpscr_control_updated(&actual);steps=0;u64 before=paired_skinning_transformed();
        while(actual.pc!=actual.lr && steps++<1000) {
            if(!automatic && (paired_skinning_transform_entry(&actual) || paired_skinning_transform_step(&actual)))continue;
            func_8024B4C0(&actual);
        }
        g_native_blocks_enabled=false;
        CHECK(actual.pc==actual.lr);
        CHECK(!paired_skinning_accumulate_available() || (entry && budgets[bi]<0) || paired_skinning_transformed()>before);
        CHECK(!memcmp(memory,reference,sizeof(memory)));
        if(lc)CHECK(!memcmp(lc_result,locked_cache_pointer(0xE0000000u,sizeof(memory)),sizeof(memory)));
        expected.ram=actual.ram;
        CHECK(!memcmp(&actual,&expected,sizeof(actual)));cases++;
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    CHECK(!paired_skinning_accumulate_available() || paired_skinning_transformed()>native);
    CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);seed.pc=0x8024C014u;
    seed.msr=0x2000u;seed.hid2=0xA0000000u;seed.ctr=2;seed.downcount=768;
    seed.gqr[7]=(7u<<16)|7u;seed.gpr[4]=0x80000200u;seed.gpr[5]=0x80001000u;
    for(u32 r=0;r<32;r++){seed.fpr[r]=1;seed.ps1[r]=1;}
    for(u32 i=0;i<8;i++) {
        CPUState rejected=seed;
        if(i==0)rejected.fpr[0]=NAN;
        if(i==1)rejected.ps1[8]=DBL_MIN;
        if(i==2)rejected.gqr[7]=0;
        if(i==3)rejected.gpr[4]=0x80000000u+sizeof(memory)-8;
        if(i==4)rejected.gpr[5]=0x80000000u+sizeof(memory)-8;
        if(i==5)rejected.reserve_valid=true;
        if(i==6)rejected.cache_control=cache_reference_mode;
        if(i==7)rejected.downcount=-300;
        CPUState before=rejected;memcpy(reference,memory,sizeof(memory));
        CHECK(!paired_skinning_transform_step(&rejected));
        CHECK(!memcmp(&before,&rejected,sizeof(before)) && !memcmp(memory,reference,sizeof(memory)));
    }
    printf("[Rigid transform] %u cases including overlapping RAM/LC: CPU/RAM/budget equal\n",cases);return 0;
}
static int blend_skinning_contracts(bool automatic) {
    u8 memory[8192],reference[8192],lc_result[8192];u32 cases=0;u64 used=paired_skinning_blended();
    const u32 counts[]={1,2,37,101};const s64 budgets[]={-255,0,768};
    for(u32 entry=0;entry<2;entry++)for(u32 lc=0;lc<2;lc++)for(u32 alias=0;alias<4;alias++)
    for(u32 ni=0;ni<2;ni++)for(u32 rounding=0;rounding<4;rounding++)
    for(int scale=-16;scale<=16;scale+=8)for(u32 ci=0;ci<4;ci++)for(u32 bi=0;bi<3;bi++) {
        CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);seed.pc=0x8024BC48u;
        seed.lr=0x81800000u;seed.msr=0x2000u;seed.hid2=0xA0000000u;
        seed.fpscr=0x82060000u|rounding|(ni ? 4u:0u);seed.ctr=counts[ci];seed.downcount=budgets[bi];
        seed.gpr[1]=0x80001B00u;seed.gpr[3]=0x80000080u;seed.gpr[4]=0x800000C0u;
        seed.gpr[5]=0x800007FEu;seed.gpr[6]=0x800001FCu;
        seed.gpr[7]=alias==0 ? 0x80000FFEu:0x800001FEu+(alias-2)*12u;
        seed.gqr[7]=((u32)(scale&63)<<24)|(7u<<16)|((u32)((-scale)&63)<<8)|7u;
        seed.gqr[6]=((u32)((-scale)&63)<<24)|(4u<<16);
        if(entry){seed.pc=0x8024BB18u;seed.gpr[8]=counts[ci]+1;seed.gpr[5]+=2;seed.gpr[6]+=4;seed.gpr[7]+=2;}
        for(u32 r=0;r<32;r++){seed.fpr[r]=((s32)r-13)*0.125;seed.ps1[r]=((s32)r-11)*0.25;}
        for(u32 i=0;i<sizeof(memory);i++)memory[i]=(u8)(i*37u+ci*53u);
        for(u32 m=0;m<2;m++)for(u32 i=0;i<12;i++) {
            float value=((int)i-5+(int)m)*0.125f;u32 bits;memcpy(&bits,&value,4);
            for(u32 b=0;b<4;b++)memory[0x80+m*64+i*4+b]=(u8)(bits>>(24-b*8));
        }
        if(lc) {
            seed.external_read=handle_external_read;seed.external_write=handle_external_write;seed.external_pointer=handle_external_pointer;
            seed.gpr[5]+=0x60000000u;seed.gpr[6]+=0x60000000u;seed.gpr[7]+=0x60000000u;
        }
        memcpy(reference,memory,sizeof(memory));CPUState expected=seed;expected.ram=reference;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        g_native_blocks_enabled=false;
        ppc_fpscr_control_updated(&expected);u32 steps=0;
        while(expected.pc!=expected.lr && steps++<1000)func_8024B4C0(&expected);
        CHECK(expected.pc==expected.lr);
        if(lc)memcpy(lc_result,locked_cache_pointer(0xE0000000u,sizeof(memory)),sizeof(memory));
        CPUState actual=seed;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        g_native_blocks_enabled=automatic;
        ppc_fpscr_control_updated(&actual);steps=0;
        while(actual.pc!=actual.lr && steps++<1000) {
            if(!automatic && (paired_skinning_blend_entry(&actual) || paired_skinning_step(&actual)))continue;
            func_8024B4C0(&actual);
        }
        g_native_blocks_enabled=false;
        CHECK(actual.pc==actual.lr);
        if(memcmp(memory,reference,sizeof(memory))) {
            fprintf(stderr,"[Blend mismatch] entry=%u lc=%u alias=%u ni=%u round=%u scale=%d count=%u budget=%lld\n",entry,lc,alias,ni,rounding,scale,counts[ci],(long long)budgets[bi]);
            for(u32 k=0;k<sizeof(memory);k++)if(memory[k]!=reference[k]){fprintf(stderr,"byte %u actual=%02X expected=%02X\n",k,memory[k],reference[k]);break;}
        }
        CHECK(!memcmp(memory,reference,sizeof(memory)));
        if(lc)CHECK(!memcmp(lc_result,locked_cache_pointer(0xE0000000u,sizeof(memory)),sizeof(memory)));
        expected.ram=actual.ram;
        if(memcmp(&actual,&expected,sizeof(actual)))fprintf(stderr,"[Blend CPU mismatch] entry=%u lc=%u alias=%u ni=%u round=%u scale=%d count=%u budget=%lld pc=%08X/%08X\n",entry,lc,alias,ni,rounding,scale,counts[ci],(long long)budgets[bi],actual.pc,expected.pc);
        CHECK(!memcmp(&actual,&expected,sizeof(actual)));cases++;
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    CHECK(!paired_skinning_accumulate_available() || paired_skinning_blended()>used);
    printf("[Two-matrix blend] %u entry/backedge cases: full CPU/RAM/LC/budget equal\n",cases);return 0;
}
static int small_matrix_contracts(void) {
    const f64 observed[]={2.7624369067780208e-06,1.0892075806623325e-05};
    const u32 loops[]={0x8024BC48u,0x8024C014u,0x8024C244u};const u32 counts[]={1,37};const s64 budgets[]={-255,768};
    u8 memory[8192],reference[8192],expected_lc[16384];u32 cases=0;bool saved=paired_skinning_wide_domain();
    for(u32 core=0;core<3;core++)for(u32 sample=0;sample<3;sample++)for(u32 lc=0;lc<2;lc++)
    for(u32 ni=0;ni<2;ni++)for(u32 rounding=0;rounding<4;rounding++)for(u32 ci=0;ci<2;ci++)for(u32 bi=0;bi<2;bi++) {
        CPUState seed={0};seed.ram=memory;seed.ram_size=sizeof(memory);seed.pc=loops[core];seed.ctr=counts[ci];seed.downcount=budgets[bi];
        seed.instruction_fallback=handle_instruction_fallback;seed.lr=0x81800000u;seed.msr=0x2000u;seed.hid2=0xA0000000u;seed.fpscr=0x82060000u|rounding|(ni ? 4u:0u);
        seed.gpr[1]=0x80001B00u;seed.gqr[7]=(16u<<24)|(7u<<16)|7u;seed.gqr[6]=(16u<<24)|(4u<<16);
        seed.fpr[8]=seed.ps1[8]=0x1.000002p-16;
        for(u32 r=11;r<19;r++)seed.fpr[r]=seed.ps1[r]=0x1p-100;
        if(sample) {
            for(u32 r=0;r<8;r++){seed.fpr[r]=0.125;seed.ps1[r]=0.25;}
            if(!core)for(u32 r=19;r<27;r++){seed.fpr[r]=0.125;seed.ps1[r]=0.25;}
            seed.fpr[core ? 2:22]=observed[sample-1];
        } else {seed.fpr[0]=0x1.000002p-48;seed.fpr[2]=-0x1.000002p-48;}
        memset(memory,0,sizeof(memory));
        for(u32 i=0;i<(counts[ci]+1)*6;i++)mem_write16(&seed,0x80000200u+i*2u,(u16)(i+1));
        memset(memory+0x800,1,128);
        if(core==0){seed.gpr[5]=0x800007FEu;seed.gpr[6]=0x800001FCu;seed.gpr[7]=0x80000FFEu;}
        if(core==1){seed.gpr[4]=0x800001FCu;seed.gpr[5]=0x80000FFEu;}
        if(core==2){seed.gpr[5]=0x800001FCu;seed.gpr[6]=0x80001000u;seed.gpr[7]=0x800009FEu;seed.gpr[8]=0x800007FFu;seed.gpr[21]=0x80001000u;}
        if(lc) {
            seed.external_read=handle_external_read;seed.external_write=handle_external_write;seed.external_pointer=handle_external_pointer;
            const u32 indices[3][5]={{5,6,7,0,0},{4,5,0,0,0},{5,6,7,8,21}};const u32 n[]={3,2,5};
            for(u32 i=0;i<n[core];i++)seed.gpr[indices[core][i]]+=0x60000000u;
        }
        memcpy(reference,memory,sizeof(memory));CPUState expected=seed;expected.ram=reference;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        g_native_blocks_enabled=false;ppc_fpscr_control_updated(&expected);u32 steps=0;
        while(expected.pc!=expected.lr && steps++<1000)func_8024B4C0(&expected);
        CHECK(expected.pc==expected.lr);
        if(lc)memcpy(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc));
        CPUState actual=seed;
        if(lc){locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(memory)),memory,sizeof(memory));}
        paired_skinning_set_wide_domain(false);CPUState unchanged=actual;
        bool accepted=core==0 ? paired_skinning_blend_step(&actual):core==1 ? paired_skinning_transform_step(&actual):paired_skinning_accumulate_step(&actual);
        CHECK(!accepted && !memcmp(&actual,&unchanged,sizeof(actual)));
        paired_skinning_set_wide_domain(true);ppc_fpscr_control_updated(&actual);steps=0;
        u64 used=core==0 ? paired_skinning_blended():core==1 ? paired_skinning_transformed():paired_skinning_accumulated();
        while(actual.pc!=actual.lr && steps++<1000) {
            accepted=core==0 ? paired_skinning_blend_step(&actual):core==1 ? paired_skinning_transform_step(&actual):paired_skinning_accumulate_step(&actual);
            if(!accepted)func_8024B4C0(&actual);
        }
        CHECK(actual.pc==actual.lr);
        u64 after=core==0 ? paired_skinning_blended():core==1 ? paired_skinning_transformed():paired_skinning_accumulated();
        CHECK(!paired_skinning_accumulate_available() || after>used);
        CHECK(!memcmp(memory,reference,sizeof(memory)));
        if(lc)CHECK(!memcmp(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(expected_lc)),sizeof(expected_lc)));
        expected.ram=actual.ram;CHECK(!memcmp(&actual,&expected,sizeof(actual)));
        if(!core && !sample && !rounding && !ci)CHECK(actual.fpr[11]==-0x1p-126);
        actual=seed;actual.fpr[0]=0x1p-49;unchanged=actual;
        accepted=core==0 ? paired_skinning_blend_step(&actual):core==1 ? paired_skinning_transform_step(&actual):paired_skinning_accumulate_step(&actual);
        CHECK(!accepted && !memcmp(&actual,&unchanged,sizeof(actual)));cases++;
    }
    paired_skinning_set_wide_domain(saved);CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[Small matrices] %u CPU/RAM/LC/budget comparisons, captured coefficients, FLT_MIN cancellation and conservative declines passed\n",cases);return 0;
}

static int environment_skinning_benchmark(CPUState seed,const u8* initial) {
    if(!paired_skinning_accumulate_available())return 0;
    u8 ram[8192];u64 ticks[2];u32 sums[2]={2166136261u,2166136261u};const u32 repeats=5000;
    for(u32 mode=0;mode<2;mode++) {
        u64 start=SDL_GetPerformanceCounter();
        for(u32 n=0;n<repeats;n++) {
            memcpy(ram,initial,sizeof(ram));CPUState work=seed;work.ram=ram;work.downcount=4096;
            u32 steps=0;
            while(work.pc!=work.lr && steps++<1000) {
                if(mode && paired_skinning_environment_step(&work))continue;
                func_8024B4C0(&work);
            }
            CHECK(work.pc==work.lr);
            for(u32 k=0;k<seed.ctr*16;k++)sums[mode]=(sums[mode]^ram[0x1000+k])*16777619u;
            u64 result;memcpy(&result,&work.fpr[11],8);sums[mode]^=(u32)result^(u32)(result>>32)^work.fpscr;
        }
        ticks[mode]=SDL_GetPerformanceCounter()-start;
    }
    CHECK(sums[0]==sums[1]);double unit=1000.0/(double)SDL_GetPerformanceFrequency();
    printf("[Environment benchmark] %u vertices: original=%.3f ms native=%.3f ms speedup=%.2fx checksum=%08X\n",repeats*seed.ctr*2,ticks[0]*unit,ticks[1]*unit,(double)ticks[0]/ticks[1],sums[0]);
    return 0;
}
static int environment_skinning_contracts(void) {
    u8 ram_a[8192],ram_b[8192],expected_lc[8192];
    const u32 entries[]={0x8024C500u,0x8024C508u,0x8024C518u};
    const u32 counts[]={2,9,37};
    u64 before=paired_skinning_environment_vertices();u32 cases=0;
    const u32 quanta[]={64,256,1024,4096};
    for(u32 qi=0;qi<4;qi++)for(u32 alias=0;alias<3;alias++)
    for(u32 lc=0;lc<2;lc++)for(u32 entry=0;entry<3;entry++)
    for(u32 ni=0;ni<2;ni++)for(u32 rounding=0;rounding<4;rounding++)for(u32 ci=0;ci<3;ci++) {
        CPUState fast={0};fast.ram=ram_a;fast.ram_size=sizeof(ram_a);
        fast.pc=entries[entry];fast.msr=0x2000;fast.hid2=0xA0000000u;
        fast.fpscr=rounding|(ni ? 4u:0)|(alias ? 0x82060000u:0);fast.ctr=counts[ci];fast.lr=0x81800000u;
        fast.instruction_fallback=handle_instruction_fallback;
        fast.gpr[1]=0x80001B00u;fast.gpr[4]=0x80000100u;fast.gpr[5]=0x80000FF8u;fast.gpr[14]=32;
        fast.gqr[7]=0x0C070C07u;
        memset(ram_a,0,sizeof(ram_a));
        for(u32 j=0;j<(counts[ci]+1)*12;j++) {
            s16 value=(s16)((j*97u)%1021u-490u);
            mem_write16(&fast,0x80000100u+j*2,(u16)value);
        }
        for(u32 r=0;r<32;r++){fast.fpr[r]=((s32)r+1)*0.125;fast.ps1[r]=((s32)r+2)*0.25;}
        fast.fpr[8]=0.5;fast.ps1[8]=0.75;fast.fpr[9]=fast.ps1[9]=2.0;
        fast.fpr[18]=-3.499999761581421;fast.ps1[18]=-2.086162567138672e-7;
        fast.fpr[19]=-4.1723248500602494e-7;fast.ps1[19]=-2.4868995751603507e-14;
        fast.fpr[20]=0;fast.ps1[20]=3.499999761581421;fast.fpr[21]=fast.ps1[21]=2;
        if(lc) {
            locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(ram_a)),ram_a,sizeof(ram_a));
            fast.external_read=handle_external_read;fast.external_write=handle_external_write;fast.external_pointer=handle_external_pointer;
            fast.gpr[4]=0xE0000100u;
        }
        if(alias)fast.gpr[5]=alias==1 ? fast.gpr[4]+16:fast.gpr[4]-8;
        if(getenv("SKINNING_BENCH") && !qi && !alias && !lc && entry==1 && !ni && !rounding && ci==2) {
            ppc_fpscr_control_updated(&fast);CHECK(environment_skinning_benchmark(fast,ram_a)==0);
        }
        memcpy(ram_b,ram_a,sizeof(ram_a));CPUState original=fast;original.ram=ram_b;
        original.cache_control=cache_reference_mode;
        u64 native_before_case=paired_skinning_environment_vertices();
        u64 batches_before_case=paired_skinning_environment_batches();
        platform_set_cpu_quantum(quanta[qi]);
        ppc_fpscr_control_updated(&original);u32 calls=0;
        while(original.pc!=original.lr && calls++<1000)CHECK(platform_execute_cpu_slice(&original));
        if(lc) {
            memcpy(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(ram_a)),sizeof(ram_a));
            locked_cache_reset();memcpy(locked_cache_pointer(0xE0000000u,sizeof(ram_a)),ram_a,sizeof(ram_a));
        }
        ppc_fpscr_control_updated(&fast);calls=0;
        while(fast.pc!=fast.lr && calls++<1000)CHECK(platform_execute_cpu_slice(&fast));
        CHECK(fast.pc==fast.lr && original.pc==original.lr);
        CHECK(!paired_skinning_accumulate_available() || paired_skinning_environment_vertices()>native_before_case);
        CHECK(!paired_skinning_accumulate_available() || paired_skinning_environment_batches()>batches_before_case);
        CHECK(memcmp(ram_a,ram_b,sizeof(ram_a))==0);
        if(lc)CHECK(!memcmp(expected_lc,locked_cache_pointer(0xE0000000u,sizeof(ram_a)),sizeof(ram_a)));
        original.ram=fast.ram;original.cache_control=fast.cache_control;
        CHECK(memcmp(&fast,&original,sizeof(fast))==0);cases++;
    }
    platform_set_cpu_quantum(1024);
    CHECK(!paired_skinning_accumulate_available() || paired_skinning_environment_vertices()>before);
    CPUState seed={0};seed.ram=ram_a;seed.ram_size=sizeof(ram_a);seed.pc=0x8024C518u;
    seed.msr=0x2000;seed.hid2=0xA0000000u;seed.ctr=2;seed.gqr[7]=0x0C070C07u;seed.gpr[4]=0x80000100u;
    for(u32 r=0;r<32;r++){seed.fpr[r]=1;seed.ps1[r]=1;}
    for(u32 test=0;test<7;test++) {
        CPUState rejected=seed;
        if(test==0)rejected.fpr[0]=NAN;
        if(test==1)for(u32 r=3;r<6;r++)rejected.fpr[r]=rejected.ps1[r]=0;
        if(test==2)rejected.gqr[0]=4;
        if(test==3)rejected.gpr[4]=0x80000000u+sizeof(ram_a)-12;
        if(test==4)rejected.reserve_valid=true;
        if(test==5)rejected.cache_control=cache_reference_mode;
        if(test==6)rejected.fpr[18]=0.1; // Wider than binary32.
        CPUState old=rejected;memcpy(ram_b,ram_a,sizeof(ram_a));
        CHECK(!paired_skinning_environment_step(&rejected));
        CHECK(memcmp(&old,&rejected,sizeof(old))==0 && memcmp(ram_a,ram_b,sizeof(ram_a))==0);
    }
    CPUState reset={0};ppc_fpscr_control_updated(&reset);
    printf("[Environment skinning] %u cases: CPU/RAM equal; native vertices=%llu\n",cases,paired_skinning_environment_vertices()-before);
    return 0;
}
static int fp_guard_contracts(void) {
    const u32 modes[]={0,0x2000u,0xB032u,0x9032u};
    for(u32 i=0;i<4;i++) {
        CPUState fast={0};fast.msr=modes[i];fast.pc=0x8024BC48u;fast.fpscr=0x12345678u;
        CPUState original=fast;
        bool expected=ppc_fp_available(&original,0x8024BC48u);
        CHECK(ppc_fp_available_inline(&fast,0x8024BC48u)==expected);
        CHECK(memcmp(&fast,&original,sizeof(fast))==0);
    }
    return 0;
}
static int scalar_memory_contracts(void) {
    u8 main_ram[32]={0},secondary_ram[32]={0};CPUState cpu={0};
    cpu.ram=main_ram;cpu.ram_size=sizeof(main_ram);
    cpu.mem2=secondary_ram;cpu.mem2_size=sizeof(secondary_ram);cpu.external_read=memory_probe_read;
    const u32 aliases[]={0x80000000u,0xC0000000u,0x90000000u,0xD0000000u};
    for(u32 i=0;i<4;i++) {
        u32 base=aliases[i];u8* backing=i<2 ? main_ram : secondary_ram;
        mem_write64(&cpu,base+24,0x0123456789ABCDEFull);
        CHECK(backing[24]==1 && backing[31]==0xEF);
        CHECK(mem_read64(&cpu,base+24)==0x0123456789ABCDEFull);
        CHECK(mem_read32(&cpu,base+28)==0x89ABCDEFu);
        CHECK(mem_read16(&cpu,base+30)==0xCDEF && mem_read8(&cpu,base+31)==0xEF);
        CHECK(mem_read32(&cpu,base+29)==0x55667788u);
        CHECK(s_memory_probe_address==base+29 && s_memory_probe_size==4);
        CHECK(mem_read64(&cpu,base+25)==0x1122334455667788ull);
        CHECK(s_memory_probe_size==8);
        CHECK(mem_read16(&cpu,base+31)==0x7788 && s_memory_probe_size==2);
        CHECK(mem_read8(&cpu,base+32)==0x88 && s_memory_probe_size==1);
        CHECK(mem_read32(&cpu,base-1)==0x55667788u && s_memory_probe_address==base-1);
        for(u32 offset=1;offset<=7;offset++) {
            mem_write64(&cpu,base+offset,0x13579BDF2468ACE0ull);
            CHECK(mem_read64(&cpu,base+offset)==0x13579BDF2468ACE0ull);
            CHECK(mem_read32(&cpu,base+offset)==0x13579BDFu);
            CHECK(mem_read16(&cpu,base+offset+1)==0x579B);
            CHECK(backing[offset]==0x13 && backing[offset+7]==0xE0);
            mem_write32(&cpu,base+offset,0xFEDCBA98u);
            CHECK(mem_read32(&cpu,base+offset)==0xFEDCBA98u && backing[offset]==0xFE);
            mem_write16(&cpu,base+offset,0xABCD);
            CHECK(mem_read16(&cpu,base+offset)==0xABCD && backing[offset+1]==0xCD);
        }
    }
    CHECK(mem_read32(&cpu,0xCC005000u)==0x55667788u && s_memory_probe_address==0xCC005000u);
    CHECK(mem_read32(&cpu,0xE0000000u)==0x55667788u && s_memory_probe_address==0xE0000000u);
    return 0;
}
static void count_psq_journal(u32 offset,u32 size,void* user){(void)offset;*(u32*)user+=size;}
static void vertex(CPUState* cpu, float x, float y) {
    u32 bits; memcpy(&bits, &x, 4); fifo(cpu, bits, 4);
    memcpy(&bits, &y, 4); handle_external_write(cpu, 0xCC008004u, bits, 4); fifo(cpu, 0xFF0000FFu, 4);
}
static int native_gl_contracts(SDL_Renderer* renderer) {
    CHECK(gx_gl_available(renderer)); // A fallback must not make the GL test pass.
    SDL_Texture* target=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,640,528);
    SDL_Texture* texture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,1,1);
    CHECK(target && texture); const u8 green[4]={0,128,0,255};
    CHECK(SDL_UpdateTexture(texture,NULL,green,4)==0);
    SDL_Texture* old=SDL_GetRenderTarget(renderer); CHECK(SDL_SetRenderTarget(renderer,target)==0);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);SDL_RenderClear(renderer);
    GXGLMaterial m={0};m.tev_valid=true;m.bp[0x28]=64;m.bp[0xC0]=0x88FF2;m.bp[0xC1]=0x8FFC0;
    m.colors[2]=64; m.bp[0x40]=19; // LESS and depth update
    SDL_Texture* images[8]={texture};GXGLVertex quad[4]={0};
    const float xy[8]={10,10,50,10,50,50,10,50};
    for (u32 i=0;i<4;i++) {
        quad[i].x=xy[i*2];quad[i].y=xy[i*2+1];quad[i].w=1;quad[i].z=0.8f;quad[i].clip_z=-0.5f;
        memset(quad[i].color,255,4);
        for(u32 j=0;j<8;j++){quad[i].texcoord[j][0]=(i==1 || i==2) ? 1.0f : 0;quad[i].texcoord[j][1]=i>=2 ? 1.0f : 0;quad[i].texcoord[j][2]=1;}
    }
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    u8 pixel[4];SDL_Rect at={20,20,1,1};
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0);
    CHECK(pixel[0]==64 && pixel[1]==128 && pixel[2]==0); // texture + register, not modulation
    m.tev_valid=false;
    for(u32 i=0;i<4;i++){quad[i].z=0.2f;quad[i].color[0]=quad[i].color[1]=0;quad[i].color[2]=255;}
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    for(u32 i=0;i<4;i++){quad[i].z=0.8f;quad[i].color[0]=255;quad[i].color[2]=0;}
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0 && pixel[2]==255 && pixel[0]==0);
    m.alpha_valid=true;m.bp[0xF3]=128|(4u<<16)|(7u<<19);
    for(u32 i=0;i<4;i++){quad[i].z=0.1f;quad[i].color[3]=64;}
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0 && pixel[2]==255);
    m.alpha_valid=false;
    for(u32 i=0;i<4;i++){quad[i].w=-1;quad[i].color[3]=255;}
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0 && pixel[2]==255);
    gx_gl_clear_depth(renderer,0,0,640,528,0xFFFFFF);
    for(u32 i=0;i<4;i++){quad[i].w=1;quad[i].z=0.8f;quad[i].clip_z=-0.5f;}
    CHECK(gx_gl_draw(renderer,&m,images,quad,sizeof(quad[0]),4,0x80));
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0 && pixel[0]==255 && pixel[2]==0);
    // EFB target Y convention maps GX front-facing polygons to GL CCW.
    gx_gl_clear_depth(renderer,0,0,640,528,0xFFFFFF);
    m.bp[0]=1u<<14; // cull back
    GXGLVertex clockwise[4]={quad[0],quad[1],quad[2],quad[3]};
    for(u32 i=0;i<4;i++){clockwise[i].z=0.1f;clockwise[i].color[0]=0;clockwise[i].color[1]=255;}
    CHECK(gx_gl_draw(renderer,&m,images,clockwise,sizeof(clockwise[0]),4,0x80));
    CHECK(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)==0 && pixel[1]==255);
    SDL_SetRenderTarget(renderer,old);SDL_DestroyTexture(texture);SDL_DestroyTexture(target);
    return 0;
}
int platform_self_test(void) {
    CHECK(frame_timing_contracts()==0);
    CHECK(ppc_scalar_fast_contracts()==0);
    g_native_blocks_enabled=false;
    CHECK(generated_float_contracts()==0);
    CHECK(keyboard_multiplayer_contracts()==0);
    CHECK(coherent_skinning_contracts()==0);
    CHECK(environment_skinning_contracts()==0);
    CHECK(transform_skinning_contracts(false)==0);
    CHECK(blend_skinning_contracts(false)==0);
    CHECK(small_matrix_contracts()==0);
#ifdef DIGIMON_TEST_BLOCK_ADAPTER
    CHECK(sdk_matrix_entry_contracts()==0);
    u64 block_before=platform_native_block_entries();
    CHECK(transform_skinning_contracts(true)==0);
    CHECK(blend_skinning_contracts(true)==0);
    g_native_blocks_enabled=true;
    CHECK(coherent_skinning_contracts()==0);
    CHECK(environment_skinning_contracts()==0);
    g_fast_float_enabled=true;
    CHECK(environment_skinning_contracts()==0);
    g_fast_float_enabled=false;
    g_native_blocks_enabled=false;
    CHECK(platform_native_block_entries()>block_before);
    printf("[Native block entries] %llu accepted; reference runs disabled the adapter\n",platform_native_block_entries()-block_before);
#endif
    CHECK(fp_guard_contracts()==0);
    CHECK(scalar_memory_contracts()==0);
    CHECK(paired_skinning_contracts()==0);
    SDL_setenv("GX_VALIDATE_WORKERS","1",1);
    SDL_setenv("GX_VALIDATE_COPY","1",1);
    SDL_SetMainReady();
    CHECK(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0);
    SDL_Window* window = SDL_CreateWindow("Platform contracts", 0, 0, 640, 480, SDL_WINDOW_HIDDEN);
    CHECK(window);
    bool use_gl = getenv("TEST_OPENGL") != NULL;
    if (use_gl) SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, (use_gl ? SDL_RENDERER_ACCELERATED : SDL_RENDERER_SOFTWARE) | SDL_RENDERER_TARGETTEXTURE);
    CHECK(renderer);
    CPUState cpu = {0}; CHECK(cpu_init(&cpu));
    cpu.external_read = handle_external_read; cpu.external_write = handle_external_write;
    cpu.instruction_fallback=handle_instruction_fallback;locked_cache_reset();
    cpu.external_pointer=handle_external_pointer;
    CHECK(video_audio_init(renderer)); CHECK(gx_pipe_init(&cpu)); gx_pipe_set_renderer(renderer);CHECK(gx_pipe_set_vram_only(&cpu,false));
    CHECK(gx_pipe_transform_contracts()==0);
    CHECK(gx_pipe_attribute_contracts(&cpu)==0);
    CHECK(gx_pipe_worker_contracts(&cpu)==0);
    CHECK(gx_pipe_texture_contracts(&cpu,renderer)==0);
    CHECK(gx_pipe_xfb_contracts(&cpu,renderer)==0);
    if(use_gl)CHECK(gx_pipe_gpu_xf_contracts(&cpu,renderer)==0);

    mem_write32(&cpu, 0x80000100u, 0x12345678u);
    CHECK(cpu.ram[0x100] == 0x12 && cpu.ram[0x103] == 0x78);
    CHECK(mem_read32(&cpu, 0xC0000100u) == 0x12345678u);
    CHECK(mem_read32(&cpu, 0x100u) == 0x12345678u);

    cpu.msr = 0x8032u; cpu.pc = 0x800034C0u;
    CHECK(!ppc_fp_available(&cpu, cpu.pc));
    CHECK((cpu.msr & 0x8000u) == 0);
    CHECK(handle_guest_exception(&cpu));
    CHECK(cpu.msr == 0xA032u && cpu.pc == 0x800034C0u && cpu.exception == 0);

    // Compare the HLE FPU image against the actual SDK __OSSaveFPUContext.
    const u32 fa=0x80009000u,fb=0x8000A000u;
    for(u32 i=0;i<32;i++){cpu.fpr[i]=1000.25+i;cpu.ps1[i]=-50.5-i;}
    cpu.gqr[0]=0;cpu.hid2=PPC_HID2_PSE|PPC_HID2_LSQE;
    cpu.pc=0x802BFF2Cu;cpu.lr=0x81800000u;cpu.gpr[3]=fa;cpu.msr=0xA032;
    for(u32 i=0;i<1000 && cpu.pc!=0x81800000u;i++)CHECK(dolrecomp_run_blocks(&cpu,1));
    CHECK(cpu.pc==0x81800000u && (mem_read16(&cpu,fa+0x1A2)&1));
    hle_os_save_fpu(&cpu,fb);
    CHECK(memcmp(cpu.ram+(fa-GC_RAM_BASE)+0x90,cpu.ram+(fb-GC_RAM_BASE)+0x90,256)==0);
    CHECK(memcmp(cpu.ram+(fa-GC_RAM_BASE)+0x1C8,cpu.ram+(fb-GC_RAM_BASE)+0x1C8,256)==0);
    CHECK(mem_read32(&cpu,fb+0x1C8)==0x447A1000u && mem_read32(&cpu,fb+0x1CC)==0xC24A0000u);
    // Lazy FPU ownership must preserve both scalar and PS1 across contexts.
    cpu.fpr[0]=2000.75;cpu.ps1[0]=70.5;hle_os_save_fpu(&cpu,fb);hle_os_load_fpu(&cpu,fa);
    mem_write32(&cpu,0x800000D8u,fa);mem_write32(&cpu,0x800000D4u,fb);
    cpu.msr=0x8032;cpu.pc=0x800034C0;
    CHECK(!ppc_fp_available(&cpu,cpu.pc));CHECK(handle_guest_exception(&cpu));
    CHECK(cpu.fpr[0]==2000.75 && cpu.ps1[0]==70.5 && cpu.msr==0xA032);
    CHECK(mem_read32(&cpu,0x800000D8u)==fb);
    mem_write32(&cpu,0x800000D4u,fa);cpu.msr&=~0x2000u;
    CHECK(!ppc_fp_available(&cpu,cpu.pc));CHECK(handle_guest_exception(&cpu));
    CHECK(cpu.fpr[0]==1000.25 && cpu.ps1[0]==-50.5);
    mem_write32(&cpu,0x800000D4u,0);mem_write32(&cpu,0x800000D8u,0);

    // Execute the actual LCLoadBlocks/LCStoreBlocks SDK code through DMA SPR fallbacks.
    for(u32 i=0;i<64;i++)mem_write8(&cpu,0x80006000u+i,(u8)i);
    cpu.gpr[3]=0xE0003FE0u;cpu.gpr[4]=0x80006000u;cpu.gpr[5]=2;
    cpu.pc=0x802BF5DCu;cpu.lr=0x81800000u;
    for(u32 i=0;i<100 && cpu.pc!=0x81800000u;i++)CHECK(dolrecomp_run_blocks(&cpu,1));
    CHECK(cpu.pc==0x81800000u && mem_read32(&cpu,0xE0003FE0u)==0x00010203u);
    CHECK(mem_read32(&cpu,0xE0000000u)==0x20212223u); // DMA wraps at 16 KiB
    mem_write64(&cpu,0xE0000000u,0x123456789ABCDEF0ull);
    CHECK(mem_read16(&cpu,0xE0000002u)==0x5678 && mem_read64(&cpu,0xE0000000u)==0x123456789ABCDEF0ull);
    cpu.gpr[3]=0x80007000u;cpu.gpr[4]=0xE0000000u;cpu.gpr[5]=1;
    cpu.pc=0x802BF600u;cpu.lr=0x81800000u;
    for(u32 i=0;i<100 && cpu.pc!=0x81800000u;i++)CHECK(dolrecomp_run_blocks(&cpu,1));
    CHECK(cpu.pc==0x81800000u && mem_read64(&cpu,0x80007000u)==0x123456789ABCDEF0ull);
    u32 dma_status;CHECK(locked_cache_spr_read(923,&dma_status) && !(dma_status&2));
    cpu.fpr[2]=-0.5;cpu.ps1[2]=0.75;cpu.gqr[1]=(12u<<8)|7u;
    CHECK(ppc_psq_store(&cpu,2,0xE0000000u,false,1,false,0x800034C0u));
    CHECK(mem_read32(&cpu,0xE0000000u)==0xF8000C00u);
    cpu.gqr[1]=0;

    // Quantized PSQ fast scaling must match the previous ldexp/trunc path
    // over every signed GQR scale, all integer formats and rounding modes.
    const f64 quantized_values[]={-INFINITY,-DBL_MAX,-65536.75,-32768.75,-128.75,-1.75,-0.0,0.0,
                                 DBL_MIN,0.75,1.75,127.75,255.75,32767.75,65535.75,DBL_MAX,INFINITY,NAN};
    u32 saved_fpscr=cpu.fpscr;
    for(u32 rounding=0;rounding<4;rounding++) {
      cpu.fpscr=rounding;ppc_fpscr_control_updated(&cpu);
      for(u32 type=4;type<=7;type++)for(s32 scale=-32;scale<=31;scale++) {
        u32 size=(type==4 || type==6) ? 1 : 2;
        s64 minimum=type==6 ? -128 : type==7 ? -32768 : 0;
        s64 maximum=type==4 ? 255 : type==5 ? 65535 : type==6 ? 127 : 32767;
        cpu.gqr[2]=(type<<16)|((u32)(scale&63)<<24)|type|((u32)(scale&63)<<8);
        for(u32 sample=0;sample<4;sample++) {
          s64 integer=sample==0 ? minimum : sample==1 ? maximum : sample==2 ? 0 : 1;
          if(size==1)mem_write8(&cpu,0x80008000u,(u8)integer);else mem_write16(&cpu,0x80008000u,(u16)integer);
          CHECK(ppc_psq_load_inline(&cpu,2,0x80008000u,true,2,false,0x800034C0u));
          CHECK(cpu.fpr[2]==(f64)(f32)ldexp((f64)integer,-scale));
        }
        for(u32 sample=0;sample<sizeof(quantized_values)/sizeof(quantized_values[0]);sample++) {
          f64 value=quantized_values[sample];s64 expected;
          if(isnan(value))expected=maximum;
          else if(isinf(value))expected=value<0 ? minimum : maximum;
          else {f64 old=trunc(ldexp(value,scale));expected=old<=minimum ? minimum : old>=maximum ? maximum : (s64)old;}
          cpu.fpr[2]=value;
          CHECK(ppc_psq_store_inline(&cpu,2,0x80008000u,true,2,false,0x800034C0u));
          u32 encoded=size==1 ? mem_read8(&cpu,0x80008000u) : mem_read16(&cpu,0x80008000u);
          CHECK(encoded==((u32)expected & (size==1 ? 255u : 65535u)));
        }
      }
    }
    cpu.fpscr=saved_fpscr;ppc_fpscr_control_updated(&cpu);cpu.gqr[2]=0;
    // Type-0 special values must retain the scalar extension's exact payload;
    // test both RAM aliases and the explicitly mapped locked cache.
    const u32 psq_float_bits[]={0,0x80000000u,0x3F800001u,1,0x80000001u,0x7F800000u,0xFF800000u,0x7FC12345u,0x7F812345u};
    const u32 psq_regions[]={0x80008000u,0xC0008000u,0xE0000100u};
    for(u32 region=0;region<3;region++)for(u32 sample=0;sample<sizeof(psq_float_bits)/sizeof(psq_float_bits[0]);sample++) {
        u32 address=psq_regions[region];mem_write32(&cpu,address,psq_float_bits[sample]);mem_write32(&cpu,address+4,0x3F800000u);
        CPUState reference=cpu;reference.gqr[2]=cpu.gqr[2]=0;
        CHECK(ppc_psq_load(&reference,2,address,false,2,false,0x800034C0u));
        CHECK(ppc_psq_load_inline(&cpu,2,address,false,2,false,0x800034C0u));
        CHECK(!memcmp(&cpu.fpr[2],&reference.fpr[2],8) && !memcmp(&cpu.ps1[2],&reference.ps1[2],8));
        CHECK(ppc_psq_store(&reference,2,address,false,2,false,0x800034C0u));
        u64 expected=mem_read64(&reference,address);
        CHECK(ppc_psq_store_inline(&cpu,2,address,false,2,false,0x800034C0u));
        CHECK(mem_read64(&cpu,address)==expected);
    }
    CPUState psq_exception_seed=cpu;
    for(u32 mode=0;mode<2;mode++) {
        CPUState reference=psq_exception_seed;cpu=psq_exception_seed;
        if(mode)reference.hid2=cpu.hid2=0;
        u32 address=mode ? 0x80008000u : 0x80008001u;
        CHECK(!ppc_psq_load(&reference,2,address,false,2,false,0x800034C0u));
        CHECK(!ppc_psq_load_inline(&cpu,2,address,false,2,false,0x800034C0u));
        CHECK(cpu.exception==reference.exception && cpu.srr0==reference.srr0 && cpu.msr==reference.msr);
    }
    cpu=psq_exception_seed;
    cpu.fpr[2]=1.0;cpu.ps1[2]=2.0;cpu.gqr[2]=0;
    u32 journal_bytes=0;ppc_set_mem_write_journal(count_psq_journal,&journal_bytes);
    CHECK(ppc_psq_store_inline(&cpu,2,0x80008000u,false,2,false,0x800034C0u));
    ppc_set_mem_write_journal(NULL,NULL);CHECK(journal_bytes==8);
    cpu.reserve_valid=true;cpu.reserve_addr=0x80008000u;
    CHECK(ppc_psq_store_inline(&cpu,2,0x80008000u,false,2,false,0x800034C0u));
    CHECK(!cpu.reserve_valid);

    // Packed FMA is allowed only when it exactly matches the scalar guest
    // operation. Compare both lanes, signed zero, FPRF, rounding and NI modes.
    u32 fma_random=0x12345678u;
    for(u32 control=0;control<8;control++) {
      cpu.fpscr=control;ppc_fpscr_control_updated(&cpu);
      for(u32 sample=0;sample<512;sample++) {
        f64 operands[6];
        for(u32 k=0;k<6;k++) {
          fma_random=fma_random*1664525u+1013904223u;
          u32 bits=(fma_random&0x807FFFFFu)|((50u+(fma_random>>24)%151u)<<23);
          float value;memcpy(&value,&bits,4);operands[k]=value;
        }
        if(sample==0){operands[0]=0.0;operands[1]=-0.0;operands[2]=-1.0;operands[3]=1.0;operands[4]=-0.0;operands[5]=0.0;}
        if(sample==1){operands[0]=FLT_MAX;operands[1]=-FLT_MAX;operands[2]=2.0;operands[3]=2.0;operands[4]=-1.0;operands[5]=1.0;}
        for(int scalar=-1;scalar<=1;scalar++)for(u32 flags=0;flags<(scalar<0 ? 4u : 1u);flags++) {
          cpu.fpr[2]=operands[0];cpu.ps1[2]=operands[1];cpu.fpr[3]=operands[2];cpu.ps1[3]=operands[3];
          cpu.fpr[4]=operands[4];cpu.ps1[4]=operands[5];cpu.fpscr=control;
          CPUState scalar_reference=cpu;f64 expected[2];
          f64 c0=scalar==1 ? operands[3] : operands[2],c1=scalar==0 ? operands[2] : operands[3];
          CHECK(ppc_fma(&scalar_reference,operands[0],c0,operands[4],true,(flags&1)!=0,(flags&2)!=0,&expected[0]));
          u32 expected_fpscr=scalar_reference.fpscr;
          scalar_reference.fpscr=control;
          CHECK(ppc_fma(&scalar_reference,operands[1],c1,operands[5],true,(flags&1)!=0,(flags&2)!=0,&expected[1]));
          u8 destination=(sample&1) ? 2 : 20;
          if(scalar<0)ppc_ps_madd_op(&cpu,destination,2,3,4,(flags&1)!=0,(flags&2)!=0);
          else if(scalar==0)ppc_ps_madds0(&cpu,destination,2,3,4);
          else ppc_ps_madds1(&cpu,destination,2,3,4);
          CHECK(!memcmp(&cpu.fpr[destination],&expected[0],8) && !memcmp(&cpu.ps1[destination],&expected[1],8));
          CHECK(cpu.fpscr==expected_fpscr);
        }
        for(u32 operation=0;operation<7;operation++) {
          cpu.fpr[2]=operands[0];cpu.ps1[2]=operands[1];cpu.fpr[3]=operands[2];cpu.ps1[3]=operands[3];
          cpu.fpr[4]=operands[4];cpu.ps1[4]=operands[5];cpu.fpscr=control;
          CPUState scalar_reference=cpu;f64 expected[2];u32 expected_class=0;
          if(operation<5) {
            for(u32 lane=0;lane<2;lane++) {
              scalar_reference.fpscr=control;scalar_reference.fpr[2]=operands[lane];
              scalar_reference.fpr[4]=operation<2 ? operands[4+lane] : operation==3 ? operands[2] : operation==4 ? operands[3] : operands[2+lane];
              if(operation==0)ppc_fadds(&scalar_reference,20,2,4);
              else if(operation==1)ppc_fsubs(&scalar_reference,20,2,4);
              else ppc_fmuls(&scalar_reference,20,2,4);
              expected[lane]=scalar_reference.fpr[20];if(!lane)expected_class=scalar_reference.fpscr&0x1F000u;
            }
            if(operation==0)ppc_ps_add_op(&cpu,20,2,4);
            else if(operation==1)ppc_ps_sub_op(&cpu,20,2,4);
            else if(operation==2)ppc_ps_mul_op(&cpu,20,2,3);
            else if(operation==3)ppc_ps_muls0(&cpu,20,2,3);
            else ppc_ps_muls1(&cpu,20,2,3);
            CHECK((cpu.fpscr&0x1F000u)==expected_class);
          } else {
            f64 sum=(f64)(f32)(operands[0]+operands[5]);
            expected[0]=operation==5 ? sum : operands[2];expected[1]=operation==5 ? operands[3] : sum;
            if(operation==5)ppc_ps_sum0(&cpu,20,2,3,4);else ppc_ps_sum1(&cpu,20,2,3,4);
          }
          CHECK(!memcmp(&cpu.fpr[20],&expected[0],8) && !memcmp(&cpu.ps1[20],&expected[1],8));
        }
      }
    }
    cpu.fpscr=saved_fpscr;ppc_fpscr_control_updated(&cpu);

    // Compare batched coherent-cache loops with the original SDK instruction
    // path, including unaligned ranges, integer clobbers and SC restoration.
    const u32 cache_functions[]={0x802BF280u,0x802BF2ACu,0x802BF2DCu,0x802BF30Cu,0x802BF338u};
    CPUState cache_seed=cpu;
    for(u32 routine=0;routine<5;routine++) {
        CPUState reference={0};u32 dispatches[2]={0};
        for(u32 mode=0;mode<2;mode++) {
            cpu=cache_seed;cpu.cache_control=mode ? NULL : cache_reference_mode;
            cpu.pc=cache_functions[routine];cpu.lr=0x81800000u;cpu.gpr[3]=0x80010003u;cpu.gpr[4]=40000;
            while(cpu.pc!=0x81800000u && dispatches[mode]++<10000)
                if(!dolrecomp_run_blocks(&cpu,1))CHECK(handle_guest_exception(&cpu));
            CHECK(cpu.pc==0x81800000u);
            if(!mode)reference=cpu;
            else {
                CHECK(!memcmp(cpu.gpr,reference.gpr,sizeof(cpu.gpr)));
                CHECK(cpu.ctr==reference.ctr && cpu.cr==reference.cr && cpu.msr==reference.msr);
                CHECK(dispatches[1]<dispatches[0]/4);
            }
        }
    }
    cpu=cache_seed;

    // Renewing the generated dispatch budget preserves the exact SDK memset
    // result and integer state while avoiding one host return per backedge.
    CPUState scheduler_seed=cpu,scheduler_reference={0};u32 scheduler_dispatches[2]={0};
    u8 scheduler_memory[4096];
    for(u32 mode=0;mode<3;mode++) {
        cpu=scheduler_seed;cpu.pc=0x80297F28u;cpu.lr=0x81800000u;cpu.gpr[3]=0x80020000u;cpu.gpr[4]=0xA5;cpu.gpr[5]=4096;
        cpu.downcount=-100000;memset(cpu.ram+0x20000,0xCD,4096);
        u32 calls=0;platform_set_cpu_quantum(mode==2 ? 1024 : 256);
        while(cpu.pc!=0x81800000u && calls++<10000)
            CHECK(mode ? platform_execute_cpu_slice(&cpu) : dolrecomp_run_blocks(&cpu,1));
        CHECK(cpu.pc==0x81800000u);
        if(!mode){scheduler_dispatches[0]=calls;scheduler_reference=cpu;memcpy(scheduler_memory,cpu.ram+0x20000,4096);}
        else {
            CHECK(!memcmp(cpu.ram+0x20000,scheduler_memory,4096));
            CHECK(!memcmp(cpu.gpr,scheduler_reference.gpr,sizeof(cpu.gpr)) && cpu.cr==scheduler_reference.cr && cpu.ctr==scheduler_reference.ctr);
            CHECK(calls<scheduler_dispatches[0]/4);
        }
    }
    cpu=scheduler_seed;
    platform_set_cpu_quantum(256);
    // A coherent prefetch hint can continue within the same bounded slice.
    cpu.pc=0x802BF258u;cpu.lr=0x81800000u;cpu.gpr[3]=0x80020000u;cpu.cache_control=NULL;
    u32 hint_cr=cpu.cr,hint_r3=cpu.gpr[3];
    CHECK(platform_execute_cpu_slice(&cpu));
    CHECK(cpu.pc==0x81800000u && cpu.gpr[3]==hint_r3 && cpu.cr==hint_cr);
    cpu=scheduler_seed;

    // Sample counter must advance during AIInit calibration, without a VBlank.
    mem_write32(&cpu, 0xCC006C00u, 0x23); // reset, play, 48 kHz
    cpu.timebase += 40500;
    CHECK(mem_read32(&cpu, 0xCC006C08u) == 48);
    mem_write32(&cpu, 0xCC006C00u, 0);

    // Reprogramming enabled audio DMA must preserve the active downcounter.
    mem_write32(&cpu,0xCC006C00u,0x40); // 32 kHz DMA clock
    audio_tick(&cpu);
    mem_write16(&cpu,0xCC00500Au,0x18); // enable/ack AID
    mem_write32(&cpu,0xCC005030u,0x8000);
    mem_write16(&cpu,0xCC005036u,0x8004);
    cpu.timebase+=10125;audio_tick(&cpu); // eight samples, one 32-byte block
    CHECK(mem_read16(&cpu,0xCC00503Au)==2);
    mem_write32(&cpu,0xCC005030u,0x9000);
    mem_write16(&cpu,0xCC005036u,0x8008);
    cpu.timebase+=10125;audio_tick(&cpu);
    CHECK(mem_read16(&cpu,0xCC00503Au)==1);
    CHECK(!(mem_read16(&cpu,0xCC00500Au)&8));
    cpu.timebase+=20250;audio_tick(&cpu);
    CHECK(mem_read16(&cpu,0xCC00503Au)==7);
    CHECK(mem_read16(&cpu,0xCC00500Au)&8);
    mem_write16(&cpu,0xCC005036u,0);
    mem_write16(&cpu,0xCC00500Au,8);

    // Real MRAM -> ARAM -> MRAM round trip via halfword DSP register writes.
    mem_write16(&cpu, 0xCC00500Au, 0x40);
    mem_write32(&cpu, 0xCC005020u, 0x100);
    mem_write32(&cpu, 0xCC005024u, 0x1000);
    mem_write32(&cpu, 0xCC005028u, 32);
    CHECK((video_read_pi(&cpu, 0, 4) & 0x40u) != 0);
    mem_write16(&cpu, 0xCC00500Au, 0x60);
    CHECK((video_read_pi(&cpu, 0, 4) & 0x40u) == 0);
    mem_write16(&cpu, 0xCC005020u, 0);
    mem_write16(&cpu, 0xCC005022u, 0x200);
    mem_write16(&cpu, 0xCC005028u, 0x8000);
    mem_write16(&cpu, 0xCC00502Au, 32);
    CHECK(mem_read32(&cpu, 0x80000200u) == 0x12345678u);

    // Callback uses the real SDK file-read trampoline, then a real guest callback.
    cpu.pc = 0x800034C0u; cpu.lr = 0x80003500u;
    cpu.gpr[1] = 0x817FF000u; cpu.gpr[13] = 0x803C6020u;
    cpu.msr = 0xA000u; cpu.ps1[17] = 123.5; cpu.gqr[3] = 0x1234;
    u32 info = 0x80001000u;
    mem_write32(&cpu, info + 56, 0x80248B60u);
    mem_write32(&cpu, cpu.gpr[13] - 29800, 1);
    CPUState saved = cpu;
    CHECK(hle_callbacks_enqueue(0x802B6C5Cu, 64, info));
    hle_callbacks_pump(&cpu);
    CHECK(cpu.gpr[3] == 64 && cpu.gpr[4] == info && cpu.pc == 0x802B6C5Cu);
    CHECK((cpu.msr&0xA000u)==0 && cpu.gpr[1]<saved.gpr[1]-0x2C8);
    CHECK(mem_read32(&cpu,0x800000D4u)!=mem_read32(&cpu,0x800000E4u));
    for (int j = 0; j < 100 && cpu.pc != saved.pc; j++) CHECK(dolrecomp_run_blocks(&cpu, 1));
    CHECK(cpu.pc == saved.pc && cpu.lr == saved.lr && cpu.gpr[1] == saved.gpr[1]);
    CHECK(cpu.ps1[17] == 123.5 && cpu.gqr[3] == 0x1234);
    CHECK(mem_read32(&cpu, cpu.gpr[13] - 29800) == 0);

    // Fragmented GX packet: frame boundaries must not consume incomplete vertices.
    cp(&cpu, 0x50, (1u << 9) | (1u << 13)); cp(&cpu, 0x60, 0);
    cp(&cpu, 0x70, (4u << 1) | (5u << 14));
    fifo(&cpu, 0x80, 1); fifo(&cpu, 4, 2); vertex(&cpu, 10, 10);
    gx_pipe_process_frame(&cpu); CHECK(gx_pipe_get_draw_calls() == 0);
    vertex(&cpu, 40, 10); vertex(&cpu, 40, 40); vertex(&cpu, 10, 40);
    bp(&cpu, 0x49, 0); bp(&cpu, 0x4A, 63u | (63u << 10));
    bp(&cpu, 0x4B, 0x00500000u >> 5); bp(&cpu, 0x4D, 4); bp(&cpu, 0x4E, 256);
    gx_pipe_process_frame(&cpu);
    CHECK(cpu.ram[0x500000] == 0); // address register alone must not perform a copy
    bp(&cpu, 0x52, 0x4000); gx_pipe_process_frame(&cpu);
    CHECK(gx_pipe_get_draw_calls() == 1);
    u8* pixel = cpu.ram + 0x500000 + 20 * 128 + 20 * 2;
    CHECK(pixel[0] >= 80 && pixel[0] <= 84 && pixel[1] >= 88 && pixel[1] <= 92 && pixel[3] >= 238);
    CHECK(cpu.ram[0x500000] == 16 && cpu.ram[0x500001] == 128);
    u8 snapshot[4]; memcpy(snapshot, pixel, 4);
    video_write_vi(&cpu, 0x1C, 0x00500000u, 4); video_trigger_vblank(&cpu);
    CHECK(video_get_xfb_addr() == 0x80500000u);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); SDL_RenderClear(renderer);
    video_present_frame(renderer, &cpu, 640, 480);
    CHECK(memcmp(snapshot, pixel, 4) == 0); // presenting never mutates guest YUY2
    u8 rgba[4]; SDL_Rect sample = { 200, 150, 1, 1 };
    CHECK(SDL_RenderReadPixels(renderer, &sample, SDL_PIXELFORMAT_RGBA32, rgba, 4) == 0);
    CHECK(rgba[0] > 220 && rgba[1] < 40 && rgba[2] < 40);
    // Compare packed GPU copies with the CPU reference for cropped sources,
    // non-integral scaling and inverse Y scaling.
    bp(&cpu,0x49,8u|(5u<<10));bp(&cpu,0x4A,31u|(29u<<10));bp(&cpu,0x4D,2);
    bp(&cpu,0x4E,384);bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);
    bp(&cpu,0x52,0x4400);gx_pipe_process_frame(&cpu);
    bp(&cpu,0x49,0);bp(&cpu,0x4A,63u|(63u<<10));bp(&cpu,0x4D,4);bp(&cpu,0x4E,256);
    bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);

    // GXCopyTex writes tiled RGB565 to RAM and clears only after taking the copy.
    bp(&cpu,0x49,16u|(16u<<10));bp(&cpu,0x4A,7u|(7u<<10));
    bp(&cpu,0x4B,0x600000u>>5);bp(&cpu,0x4D,2);
    bp(&cpu,0x4F,0xFF00);bp(&cpu,0x50,0xFF);bp(&cpu,0x51,0xFFFFFF);
    bp(&cpu,0x52,0x840);gx_pipe_process_frame(&cpu); // format RGB565 + clear
    CHECK(mem_read16(&cpu,0x80600000u)==0xF800);
    CHECK(mem_read16(&cpu,0x80600000u+32)==0xF800); // second 4x4 tile
    bp(&cpu,0x49,0);bp(&cpu,0x4A,63u|(63u<<10));bp(&cpu,0x4B,0x500000u>>5);bp(&cpu,0x4D,4);
    bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);
    CHECK(pixel[0]>=40 && pixel[0]<=43 && pixel[1]>=238); // cleared EFB is blue

    // CI4 palette lives in TMEM and TEV chooses unit 0 even when unit 1 was loaded last.
    memset(cpu.ram+0x8000,0,32); memset(cpu.ram+0x9000,0,32);
    mem_write16(&cpu,0x8000A000u,0xF800); mem_write16(&cpu,0x8000B000u,0x07E0);
    bp(&cpu,0x64,0xA000>>5); bp(&cpu,0x65,1u<<10);
    bp(&cpu,0x64,0xB000>>5); bp(&cpu,0x65,(1u<<10)|1u);
    bp(&cpu,0x98,1u<<10); // RGB565, TMEM offset 0
    bp(&cpu,0x88,7u|(7u<<10)|(8u<<20)); bp(&cpu,0x94,0x8000>>5);
    bp(&cpu,0x89,7u|(7u<<10)); bp(&cpu,0x95,0x9000>>5);
    bp(&cpu,0x28,64); bp(&cpu,0xC0,0xFFF8); bp(&cpu,0xC1,0xFFC0); bp(&cpu,0x41,0);
    cp(&cpu,0x60,1); cp(&cpu,0x70,(4u<<1)|(5u<<14)|(1u<<21)|(4u<<22));
    for (u32 pass=0;pass<2;pass++) {
        if (pass) { bp(&cpu,0x64,0xB000>>5); bp(&cpu,0x65,1u<<10); }
        fifo(&cpu,0x80,1); fifo(&cpu,4,2);
        const float xy[8]={10,10,40,10,40,40,10,40};
        for (u32 j=0;j<4;j++) { vertex(&cpu,xy[j*2],xy[j*2+1]); fifo(&cpu,(j==1 || j==2) ? 0x3F800000u : 0,4); fifo(&cpu,j>=2 ? 0x3F800000u : 0,4); }
        bp(&cpu,0x52,0x4000); gx_pipe_process_frame(&cpu);
        if (!pass) CHECK(pixel[0]>=80 && pixel[0]<=84 && pixel[3]>=238);
        else CHECK(pixel[0]>=142 && pixel[0]<=146 && pixel[3]<40);
    }

    // A shared CI4 image with two palettes needs two persistent cache entries,
    // rather than destroying/re-uploading its texture on every palette switch.
    u64 uploads_before=gx_pipe_get_texture_uploads(),palette_warm=0;
    bp(&cpu,0x64,0xA000>>5);bp(&cpu,0x65,1u<<10);
    for(u32 pass=0;pass<4;pass++) {
        bp(&cpu,0x98,(1u<<10)|(pass&1u));fifo(&cpu,0x80,1);fifo(&cpu,4,2);
        const float xy[8]={10,10,40,10,40,40,10,40};
        for(u32 j=0;j<4;j++){vertex(&cpu,xy[j*2],xy[j*2+1]);fifo(&cpu,(j==1 || j==2) ? 0x3F800000u : 0,4);fifo(&cpu,j>=2 ? 0x3F800000u : 0,4);}
        bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);
        if(pass&1)CHECK(pixel[0]>=142 && pixel[0]<=146 && pixel[3]<40);
        else CHECK(pixel[0]>=80 && pixel[0]<=84 && pixel[3]>=238);
        if(pass==1)palette_warm=gx_pipe_get_texture_uploads();
        if(pass>=2)CHECK(gx_pipe_get_texture_uploads()==palette_warm);
    }
    CHECK(gx_pipe_get_texture_uploads()<=uploads_before+2);
    bp(&cpu,0x98,1u<<10);

    // Two queued CI4 draws must retain both source pixels and palette even
    // when the CPU reuses both buffers and the same TLUT slot before GXCopyDisp.
    if(gx_pipe_image_versions()){
        mem_write16(&cpu,0x8000A000u,0xF800);mem_write16(&cpu,0x8000B002u,0x07E0);
        for(u32 i=0;i<32;i++)mem_write8(&cpu,0x80008000u+i,0);
        bp(&cpu,0x64,0xA000>>5);bp(&cpu,0x65,1u<<10);bp(&cpu,0x98,1u<<10);
        for(u32 side=0;side<2;side++){
            if(side){for(u32 i=0;i<32;i++)mem_write8(&cpu,0x80008000u+i,0x11);bp(&cpu,0x64,0xB000>>5);bp(&cpu,0x65,1u<<10);}
            float left=side ? 30.f:10.f,right=side ? 45.f:25.f;float xy[]={left,10,right,10,right,40,left,40};
            fifo(&cpu,0x80,1);fifo(&cpu,4,2);
            for(u32 j=0;j<4;j++){vertex(&cpu,xy[j*2],xy[j*2+1]);fifo(&cpu,(j==1 || j==2) ? 0x3F800000u:0,4);fifo(&cpu,j>=2 ? 0x3F800000u:0,4);}
            gx_pipe_process_frame(&cpu);
        }
        for(u32 i=0;i<32;i++)mem_write8(&cpu,0x80008000u+i,0x22);
        mem_write16(&cpu,0x8000B002u,0xFFFF);bp(&cpu,0x64,0xB000>>5);bp(&cpu,0x65,1u<<10);
        bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);
        u8* left=cpu.ram+0x500000+20*128+16*2;u8* right=cpu.ram+0x500000+20*128+34*2;
        CHECK(left[0]>=80 && left[0]<=84 && left[3]>=238);
        CHECK(right[0]>=142 && right[0]<=146 && right[3]<40);
        for(u32 i=0;i<32;i++)mem_write8(&cpu,0x80008000u+i,0);
        puts("[GX immutable TLUT] two deferred draws preserved red/green despite CPU source and palette reuse before copy");
    }

    // TEV stage 0 writes C0, stage 1 modulates its texture with CPREV.
    // Uploading konst K0 must not overwrite the separate C0 register bank.
    mem_write16(&cpu,0x8000B000u,0xFFFF);
    bp(&cpu,0x64,0xB000>>5); bp(&cpu,0x65,1u<<10);
    bp(&cpu,0xE2,255); bp(&cpu,0xE3,0);
    bp(&cpu,0xE2,0x800000); bp(&cpu,0xE3,0x800000|0xFF000);
    bp(&cpu,0,1u<<10); bp(&cpu,0x28,64u<<12);
    bp(&cpu,0xC0,0xFFF2); bp(&cpu,0xC1,0xFFE0);
    bp(&cpu,0xC2,0xF08F); bp(&cpu,0xC3,0xFFC0);
    fifo(&cpu,0x80,1); fifo(&cpu,4,2);
    const float corners[8]={10,10,40,10,40,40,10,40};
    for (u32 j=0;j<4;j++) {
        vertex(&cpu,corners[j*2],corners[j*2+1]);
        fifo(&cpu,(j==1 || j==2) ? 0x3F800000u : 0,4); fifo(&cpu,j>=2 ? 0x3F800000u : 0,4);
    }
    bp(&cpu,0x52,0x4000); gx_pipe_process_frame(&cpu);
    CHECK(pixel[0]>=80 && pixel[0]<=84 && pixel[3]>=238);
    bp(&cpu,0,0);

    // XF material source must override an unrelated vertex color when selected.
    xf(&cpu,0x100C,0x00FF00FF);xf(&cpu,0x100E,0);xf(&cpu,0x1010,0);
    bp(&cpu,0x28,0);bp(&cpu,0xC0,0xFFFau);bp(&cpu,0xC1,0xFFD0u);
    fifo(&cpu,0x80,1);fifo(&cpu,4,2);
    for(u32 j=0;j<4;j++){vertex(&cpu,corners[j*2],corners[j*2+1]);fifo(&cpu,0,4);fifo(&cpu,0,4);}
    bp(&cpu,0x52,0x4000);gx_pipe_process_frame(&cpu);
    CHECK(pixel[0]>=142 && pixel[0]<=146 && pixel[3]<40);

    // Empty host frames are not PE completions. Finish/token latch and acknowledge.
    video_ack_pe(true, true); video_set_pe_enable(3);
    gx_pipe_process_frame(&cpu); CHECK((video_read_pi(&cpu, 0, 4) & 0x600u) == 0);
    bp(&cpu, 0x45, 2); bp(&cpu, 0x48, 0x1234); gx_pipe_process_frame(&cpu);
    CHECK((video_read_pi(&cpu, 0, 4) & 0x600u) == 0x600u);
    CHECK(gx_pipe_read_pe(&cpu, 0x0E) == 0x1234);
    gx_pipe_write_pe(&cpu, 0x0A, 15); CHECK((video_read_pi(&cpu, 0, 4) & 0x600u) == 0);

    // CPU and GP FIFOs may be unlinked. A selected RAM FIFO must still execute.
    video_ack_pe(true, true);
    gx_pipe_write_cp(&cpu, 2, 0);
    video_write_pi(&cpu, 0x0C, 0x700000, 4);
    video_write_pi(&cpu, 0x10, 0x700020, 4);
    video_write_pi(&cpu, 0x14, 0x700000, 4);
    bp(&cpu, 0x45, 2);
    for (int j=0; j<27; j++) fifo(&cpu,0,1);
    CHECK(cpu.ram[0x700000] == 0x61 && cpu.ram[0x700001] == 0x45);
    CHECK(video_read_pi(&cpu,0x14,4) == 0x700020u);
    gx_pipe_process_frame(&cpu); CHECK((video_read_pi(&cpu,0,4)&0x400u) == 0);
    gx_pipe_write_cp(&cpu,0x20,0); gx_pipe_write_cp(&cpu,0x22,0x70);
    gx_pipe_write_cp(&cpu,0x24,0x20); gx_pipe_write_cp(&cpu,0x26,0x70);
    gx_pipe_write_cp(&cpu,0x38,0); gx_pipe_write_cp(&cpu,0x3A,0x70);
    gx_pipe_write_cp(&cpu,0x30,32); gx_pipe_write_cp(&cpu,0x32,0);
    CHECK(gx_pipe_read_cp(&cpu,0x22) == 0x70 && gx_pipe_read_cp(&cpu,0x20) == 0);
    gx_pipe_write_cp(&cpu,2,1);
    CHECK(gx_pipe_read_cp(&cpu,0x30)==0); // enabling the selected RAM FIFO executes it immediately
    gx_pipe_process_frame(&cpu);
    CHECK((video_read_pi(&cpu,0,4)&0x400u) != 0 && gx_pipe_read_cp(&cpu,0x30) == 0);
    CHECK(gx_pipe_read_cp(&cpu,0x38) == 0x20);
    video_ack_pe(true,true);
    gx_pipe_write_cp(&cpu,2,0x11);
    bp(&cpu,0x48,0x6789); for (int j=0;j<27;j++) fifo(&cpu,0,1);
    CHECK(video_read_pi(&cpu,0x14,4) == 0x700000u); // ring wrap
    CHECK(gx_pipe_read_cp(&cpu,0x30) == 0); // linked GP consumed this gather immediately
    gx_pipe_process_frame(&cpu);
    CHECK(gx_pipe_read_pe(&cpu,0x0E) == 0x6789 && gx_pipe_read_cp(&cpu,0x38) == 0);
    CHECK((video_read_pi(&cpu,0,4)&0x200u) != 0);
    // Snapshot indexed positions while their linked FIFO draw is submitted.
    // Reusing the CPU workspace afterward must not change the queued geometry.
    cp(&cpu,0x50,(3u<<9)|(1u<<13));cp(&cpu,0x60,0);
    cp(&cpu,0x70,(4u<<1)|(5u<<14));cp(&cpu,0xA0,0x50000);cp(&cpu,0xB0,8);
    xf(&cpu,0x100E,1);xf(&cpu,0x1010,1);
    for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    float points[8]={50,50,60,50,60,60,50,60};
    for(u32 i=0;i<8;i++){u32 bits;memcpy(&bits,&points[i],4);mem_write32(&cpu,0x80050000u+i*4,bits);}
    u32 previous_draws=gx_pipe_get_draw_calls();
    fifo(&cpu,0x80,1);fifo(&cpu,4,2);
    for(u32 i=0;i<4;i++){fifo(&cpu,i,2);fifo(&cpu,0xFF0000FFu,4);}
    for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    CHECK(gx_pipe_get_draw_calls()==previous_draws+1);
    memset(cpu.ram+0x50000,0,sizeof(points));
    bp(&cpu,0x52,0x4000);for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    u8* transient=cpu.ram+0x500000+55*128+54*2;
    CHECK(transient[0]>=80 && transient[0]<=84 && transient[3]>=238);
    // A large indexed draw exercises worker decode, cache reuse, the real
    // parser and raster output. GX_VALIDATE_WORKERS compares every decoded
    // vertex byte against the serial path before submitting it to GL/SDL.
    for(u32 i=0;i<8;i++){u32 bits;memcpy(&bits,&points[i],4);mem_write32(&cpu,0x80050000u+i*4,bits);}
    bp(&cpu,0x4F,0);bp(&cpu,0x50,0);bp(&cpu,0x51,0xFFFFFF);bp(&cpu,0x52,0x4800);
    for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    u64 stores0,lines0,deferred0,parses0,stores1,lines1,deferred1,parses1;
    gx_pipe_fifo_diagnostics(&stores0,&lines0,&deferred0,&parses0);
    fifo(&cpu,0x90,1);fifo(&cpu,3072,2);
    for(u32 i=0;i<3072;i++){fifo(&cpu,i%3,2);fifo(&cpu,0xFF0000FFu,4);}
    for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    bp(&cpu,0x52,0x4000);for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    gx_pipe_fifo_diagnostics(&stores1,&lines1,&deferred1,&parses1);
    CHECK(deferred1-deferred0>=500 && parses1-parses0<30);
    CHECK(gx_pipe_read_cp(&cpu,0x30)==0); // no delayed hardware ring consumption
    printf("[FIFO packets] %llu lines: %llu incomplete parses avoided, %llu actual parser calls\n",lines1-lines0,deferred1-deferred0,parses1-parses0);
    u8* parallel_pixel=cpu.ram+0x500000+52*128+56*2;
    CHECK(parallel_pixel[0]>=80 && parallel_pixel[0]<=84 && parallel_pixel[3]>=238);
    if(SDL_GetCPUCount()>1 && !getenv("GX_SINGLE_THREADED"))CHECK(gx_pipe_get_parallel_batches()>0);
    // Nested display-list buffers are reused without replaying stale tails.
    const u8 inner_token[]={0x61,0x47,0,0x11,0x22};
    memcpy(cpu.ram+0x90020,inner_token,sizeof(inner_token));
    mem_write8(&cpu,0x80090000u,0x40);mem_write32(&cpu,0x80090001u,0x90020);mem_write32(&cpu,0x80090005u,5);
    mem_write8(&cpu,0x80090009u,0x61);mem_write32(&cpu,0x8009000Au,0x47004455);
    fifo(&cpu,0x40,1);fifo(&cpu,0x90000,4);fifo(&cpu,14,4);for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    CHECK(gx_pipe_read_pe(&cpu,0x0E)==0x4455);
    mem_write32(&cpu,0x80090021u,0x47006677);
    fifo(&cpu,0x40,1);fifo(&cpu,0x90000,4);fifo(&cpu,9,4);for(u32 i=0;i<32;i++)fifo(&cpu,0,1);
    CHECK(gx_pipe_read_pe(&cpu,0x0E)==0x6677);
    gx_pipe_write_cp(&cpu,2,0);

    // Execute an actual AX command list: decode, mix, write PCM and retire voices.
    static u8 aram[1024];
    static const u16 commands[] = {0,0,0,2,0x8000,0x6100,3,14,0x8000,0x6700,0x8000,0x6400,15};
    for (u32 i=0;i<sizeof(commands)/sizeof(commands[0]);i++) mem_write16(&cpu,0x80006000u+i*2,commands[i]);
    memset(cpu.ram+0x6100,0,244);
    mem_write16(&cpu,0x80006100u+4*2,2); // direct/nearest source
    mem_write16(&cpu,0x80006100u+7*2,1); // running
    mem_write16(&cpu,0x80006100u+6*2,3); // main L/R
    mem_write16(&cpu,0x80006100u+9*2,32767); mem_write16(&cpu,0x80006100u+11*2,32767);
    mem_write16(&cpu,0x80006100u+50*2,32767);
    mem_write16(&cpu,0x80006100u+56*2,0xA); // PCM16, addresses in 16-bit sample units
    mem_write32(&cpu,0x80006100u+59*2,103); mem_write32(&cpu,0x80006100u+61*2,100);
    mem_write32(&cpu,0x80006100u+83*2,0x10000);
    const s16 samples[4]={1000,-2000,3000,-4000};
    for (u32 i=0;i<4;i++) { aram[200+i*2]=(u8)((u16)samples[i]>>8); aram[201+i*2]=(u8)samples[i]; }
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK(mem_read16(&cpu,0x80006100u+7*2)==0);
    CHECK((s16)mem_read16(&cpu,0x80006400u)==998 && (s16)mem_read16(&cpu,0x80006404u)<-1900);
    CHECK(mem_read32(&cpu,0x80006100u+61*2)==104);
    // DSP ADPCM: header exponent 12 and nibble +1 produce samples of +4096.
    memset(aram,0,sizeof(aram)); aram[0]=12; for (u32 i=1;i<8;i++) aram[i]=0x11;
    mem_write16(&cpu,0x80006100u+7*2,1); mem_write16(&cpu,0x80006100u+56*2,0);
    mem_write32(&cpu,0x80006100u+59*2,15); mem_write32(&cpu,0x80006100u+61*2,0);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK(mem_read16(&cpu,0x80006100u+7*2)==0 && (s16)mem_read16(&cpu,0x80006400u)==4094);
    // A looping sample continues instead of being falsely retired.
    mem_write16(&cpu,0x80006100u+7*2,1); mem_write16(&cpu,0x80006100u+55*2,1);
    mem_write16(&cpu,0x80006100u+90*2,12); mem_write32(&cpu,0x80006100u+57*2,2);
    mem_write32(&cpu,0x80006100u+61*2,0);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK(mem_read16(&cpu,0x80006100u+7*2)==1 && mem_read32(&cpu,0x80006100u+61*2)<=16);

    // Older GC AX PBs are 236 bytes: loop counter moves before the absent LPF.
    memset(cpu.ram+0x61EC,0,244);
    mem_write32(&cpu,0x80006100u,0x800061ECu);
    mem_write16(&cpu,0x80006100u+6*2,0); // old mixer always enables main L/R
    mem_write16(&cpu,0x80006100u+8*2,1); // stream: DSP reports loop count to CPU
    mem_write16(&cpu,0x80006100u+93*2,0);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK(mem_read16(&cpu,0x80006100u+93*2)>0 && (s16)mem_read16(&cpu,0x80006400u)>4000);

    // Linear SRC retains fractional phase instead of repeating the newest sample.
    mem_write32(&cpu,0x80006100u,0);
    memset(cpu.ram+0x6100+93*2,0,8); // switch fixture from old loop counter to new LPF layout
    mem_write16(&cpu,0x80006100u+4*2,1); mem_write16(&cpu,0x80006100u+6*2,3);
    mem_write32(&cpu,0x80006100u+83*2,0); mem_write16(&cpu,0x80006100u+85*2,32768);
    mem_write16(&cpu,0x80006100u+86*2,6000); mem_write16(&cpu,0x80006100u+87*2,10000);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK((s16)mem_read16(&cpu,0x80006400u)==7998);

    // Four-tap SRC must use the selected coefficient bank and history samples.
    FILE* coefficients=fopen("platform_coefficients.bin","wb");CHECK(coefficients);
    for(u32 i=0;i<2048;i++) {u16 c=(i%4==1 || i%4==2) ? 16384 : 0;fputc(c>>8,coefficients);fputc(c&255,coefficients);}
    fclose(coefficients);CHECK(ax_hle_load_coefficients("platform_coefficients.bin"));remove("platform_coefficients.bin");
    mem_write16(&cpu,0x80006100u+4*2,0);mem_write16(&cpu,0x80006100u+5*2,2);
    for(u32 i=0;i<4;i++)mem_write16(&cpu,0x80006100u+(86+i)*2,(u16)(6000+i*4000));
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK((s16)mem_read16(&cpu,0x80006400u)==11998);
    mem_write16(&cpu,0x80006100u+93*2,1);mem_write16(&cpu,0x80006100u+95*2,16384);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(commands)/sizeof(commands[0])));
    CHECK((s16)mem_read16(&cpu,0x80006400u)==5998);

    // AX SETUP includes de-pop ramps; download volume must reach all AUX buses.
    const u16 bus_commands[]={0,0x8000,0x7000,1,0x8000,0x7100,32768,16384,8192,
                              4,0x8000,0x7900,0x8000,0x8100,
                              14,0x8000,0x6700,0x8000,0x6400,15};
    memset(cpu.ram+0x7000,0,54); memset(cpu.ram+0x7100,0,1920); memset(cpu.ram+0x8100,0,1920);
    mem_write32(&cpu,0x80007000u,1000); mem_write16(&cpu,0x80007004u,1);
    mem_write32(&cpu,0x80007100u,2000);
    for (u32 i=0;i<sizeof(bus_commands)/2;i++) mem_write16(&cpu,0x80006000u+i*2,bus_commands[i]);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(bus_commands)/2));
    CHECK((s16)mem_read16(&cpu,0x80006402u)==3000);
    CHECK((s32)mem_read32(&cpu,0x80007900u)==1000); // AUX A downloaded at half volume

    // Compressor attack and release use the guest gain table, before clipping.
    const u16 compressor_commands[]={0,0x8000,0x7000,18,500,1,0x8000,0x9000,
                                    14,0x8000,0x6700,0x8000,0x6400,15};
    for(u32 i=0;i<sizeof(compressor_commands)/2;i++)mem_write16(&cpu,0x80006000u+i*2,compressor_commands[i]);
    memset(cpu.ram+0x7000,0,54);mem_write32(&cpu,0x80007000u,1000);
    for(u32 i=0;i<160;i++){mem_write16(&cpu,0x80009000u+i*2,16384);mem_write16(&cpu,0x80009000u+11*320+i*2,8192);}
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(compressor_commands)/2));
    CHECK((s16)mem_read16(&cpu,0x80006402u)==500);
    mem_write32(&cpu,0x80007000u,100);
    CHECK(ax_hle_execute(&cpu,aram,sizeof(aram),0x80006000u,sizeof(compressor_commands)/2));
    CHECK((s16)mem_read16(&cpu,0x80006402u)==25);

    // Sparse CISO with a present first block and an absent second block.
    u8 header[0x8000] = {0}, block[2048] = {0}, readback[32];
    memcpy(header, "CISO", 4); header[5] = 8; header[8] = 1;
    block[0x425] = 0; block[0x426] = 6; block[0x427] = 0; // FST offset 0x600
    block[0x42B] = 1; // FST length 1
    for (u32 j=0; j<16; j++) block[2032+j] = (u8)(j+1);
    FILE* disc = fopen("platform_fixture.ciso", "wb"); CHECK(disc);
    CHECK(fwrite(header, 1, sizeof(header), disc) == sizeof(header));
    CHECK(fwrite(block, 1, sizeof(block), disc) == sizeof(block)); fclose(disc);
    CHECK(dvd_vfs_init("platform_fixture.ciso", &cpu));
    CHECK(dvd_vfs_read_bytes(2032, readback, 32));
    CHECK(readback[0] == 1 && readback[15] == 16 && readback[16] == 0);
    memset(cpu.ram + 0x3000, 0xCD, 96);
    mem_write32(&cpu, 0x80003038u, 0x80248B60u); // caller-owned user callback
    cpu.gpr[3] = 0x80003000u; cpu.gpr[4] = 0x80004000u; cpu.gpr[5] = 32;
    cpu.gpr[6] = 2032; cpu.gpr[7] = 0x802B6C5Cu; cpu.lr = 0x80003500u;
    CHECK(dolrecomp_dispatch_replacement(&cpu, 0x802B92B0u));
    CHECK(cpu.gpr[3]==1 && mem_read32(&cpu,0x80003020u)==0 && mem_read32(&cpu,0x8000300Cu)==1);
    u32 dvd_deadline=SDL_GetTicks()+2000;
    while(dvd_vfs_pending_reads() && (s32)(dvd_deadline-SDL_GetTicks())>0){dvd_vfs_pump(&cpu);SDL_Delay(1);}
    CHECK(!dvd_vfs_pending_reads() && mem_read32(&cpu,0x80003020u)==32 && mem_read32(&cpu,0x8000300Cu)==0);
    CHECK(mem_read32(&cpu, 0x80003038u) == 0x80248B60u);
    CHECK(mem_read32(&cpu, 0x80003054u) == 0xCDCDCDCDu); // no fabricated engine flags
    CHECK(memcmp(cpu.ram + 0x4000, readback, 32) == 0);
    // Execute the callback chain and verify it returns to the saved PC.
    cpu.pc = 0x80003500u; cpu.msr |= 0x8000u; hle_callbacks_pump(&cpu);
    CHECK(cpu.gpr[3] == 32 && cpu.gpr[4] == 0x80003000u);
    for (int j=0; j<100 && cpu.pc != 0x80003500u; j++) CHECK(dolrecomp_run_blocks(&cpu, 1));
    CHECK(cpu.pc == 0x80003500u);
    // Hardware DMA also remains busy until main-thread publication.
    memset(cpu.ram+0x5000,0xEE,32);dvd_vfs_write_reg(&cpu,8,0xA8000000u);dvd_vfs_write_reg(&cpu,12,2032/4);
    dvd_vfs_write_reg(&cpu,0x14,0x5000);dvd_vfs_write_reg(&cpu,0x18,32);dvd_vfs_write_reg(&cpu,0x1C,1);
    CHECK((dvd_vfs_read_reg(&cpu,0x1C)&1)!=0 && cpu.ram[0x5000]==0xEE);
    dvd_deadline=SDL_GetTicks()+2000;while(dvd_vfs_pending_reads() && (s32)(dvd_deadline-SDL_GetTicks())>0){dvd_vfs_pump(&cpu);SDL_Delay(1);}
    CHECK(!dvd_vfs_pending_reads() && !(dvd_vfs_read_reg(&cpu,0x1C)&1) && (dvd_vfs_read_reg(&cpu,0)&0x10));
    CHECK(!memcmp(cpu.ram+0x5000,readback,32));
    memset(cpu.ram+0x5000,0xCC,16);
    for(u32 i=0;i<16;i++)CHECK(dvd_vfs_read_async(0x80003000u,0x80005000u+i,1,2032+i,0));
    CHECK(!dvd_vfs_read_async(0x80003000u,0x80005000u,32,2032,0));
    CHECK(dvd_vfs_read_bytes(2032,readback,32));
    dvd_deadline=SDL_GetTicks()+2000;while(dvd_vfs_pending_reads() && (s32)(dvd_deadline-SDL_GetTicks())>0){dvd_vfs_pump(&cpu);SDL_Delay(1);}
    CHECK(!dvd_vfs_pending_reads());for(u32 i=0;i<16;i++)CHECK(cpu.ram[0x5000+i]==i+1);
    dvd_vfs_shutdown(); remove("platform_fixture.ciso");
    // A present block with truncated backing data must report failure.
    header[9] = 1;
    disc = fopen("platform_fixture.ciso", "wb"); CHECK(disc);
    fwrite(header, 1, sizeof(header), disc); fwrite(block, 1, sizeof(block), disc); fclose(disc);
    CHECK(dvd_vfs_init("platform_fixture.ciso", &cpu));
    CHECK(!dvd_vfs_read_bytes(2032, readback, 32));
    memset(cpu.ram+0x5000,0xEE,32);CHECK(dvd_vfs_read_async(0x80003000u,0x80005000u,32,2032,0));
    dvd_deadline=SDL_GetTicks()+2000;while(dvd_vfs_pending_reads() && (s32)(dvd_deadline-SDL_GetTicks())>0){dvd_vfs_pump(&cpu);SDL_Delay(1);}
    CHECK(!dvd_vfs_pending_reads() && mem_read32(&cpu,0x8000300Cu)==0xFFFFFFFFu && mem_read32(&cpu,0x80003020u)==0);
    for(u32 i=0;i<32;i++)CHECK(cpu.ram[0x5000+i]==0xEE);
    puts("[DVD async] SDK callback, hardware DMA, sparse/truncated reads, queue capacity, serialized seeks and host-only worker passed");
    dvd_vfs_shutdown(); remove("platform_fixture.ciso");

    // Truncated DOL must fail, not boot with partially initialized sections.
    const char* path = "platform_truncated.dol";
    FILE* file = fopen(path, "wb"); CHECK(file); fputs("bad", file); fclose(file);
    CHECK(!dol_load(path, &cpu, NULL)); remove(path);

    if (use_gl) CHECK(native_gl_contracts(renderer)==0);
    gx_pipe_shutdown(); video_audio_shutdown(); cpu_free(&cpu);
    SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_Quit();
    puts("PASS: endian/aliases, ARAM DMA/IRQ, guest callback ABI/context, fragmented GX, EFB->YUY2->SDL, PE events, truncated DOL");
    return 0;
}

int platform_lua_probe(const char* path) {
    CPUState cpu={0};if(!cpu_init(&cpu))return 1;
    FILE* file=fopen(path,"rb");if(!file){cpu_free(&cpu);return 1;}
    bool ok=fread(cpu.ram,1,cpu.ram_size,file)==cpu.ram_size;fclose(file);if(!ok){cpu_free(&cpu);return 1;}
    cpu.gpr[13]=0x803C6020u;
    u32 state=mem_read32(&cpu,cpu.gpr[13]-26944),global=mem_read32(&cpu,state+16),table=mem_read32(&cpu,global+48);
    const u32 refs[]={0,12,1355,1356,1357,45156};
    for(u32 i=0;i<sizeof(refs)/sizeof(refs[0]);i++) {
        cpu.gpr[1]=0x817F0000u;cpu.gpr[3]=table;cpu.gpr[4]=refs[i];cpu.pc=0x8026C678u;cpu.lr=0x81800000u;cpu.msr=0x2032u;
        u32 steps=0;while(cpu.pc!=0x81800000u && steps++<10000)if(!dolrecomp_run_blocks(&cpu,1) && !handle_guest_exception(&cpu))break;
        printf("[Lua probe] ref=%u pc=%08X result=%08X tag=%u value=%08X steps=%u\n",refs[i],cpu.pc,cpu.gpr[3],mem_read32(&cpu,cpu.gpr[3]),mem_read32(&cpu,cpu.gpr[3]+4),steps);
        printf("  f0=%g f13=%g f12=%g cr=%08X bias=%016llX stack=%016llX\n",cpu.fpr[0],cpu.fpr[13],cpu.fpr[12],cpu.cr,mem_read64(&cpu,0x8030E690u),mem_read64(&cpu,0x817EFFF8u));
    }
    cpu_free(&cpu);return 0;
}

typedef struct {CPUState* cpu;u32 watch;} ProbeJournal;
static void probe_journal(u32 offset,u32 size,void* user) {
    ProbeJournal* p=(ProbeJournal*)user;CPUState* cpu=p->cpu;
    if(cpu->pc==0x8018E844u){p->watch=offset+104;printf("[Probe watch] %08X\n",p->watch|GC_RAM_BASE);}
    if(p->watch && offset<p->watch+8 && (u64)offset+size>p->watch) {
        u32 instruction=mem_read32(cpu,cpu->pc),rs=(instruction>>21)&31;
        printf("[Probe write] PC=%08X LR=%08X addr=%08X size=%u old=%08X r%u=%08X f%u=%g ctx=%08X\n",cpu->pc,cpu->lr,offset|GC_RAM_BASE,size,mem_read32(cpu,p->watch|GC_RAM_BASE),rs,cpu->gpr[rs],rs,cpu->fpr[rs],mem_read32(cpu,0x800000D4u));
    }
}
int platform_guest_call(const char* path,u32 pc,u32 a,u32 b,u32 c) {
    CPUState cpu={0};if(!cpu_init(&cpu))return 1;
    FILE* file=fopen(path,"rb");if(!file){cpu_free(&cpu);return 1;}
    bool ok=fread(cpu.ram,1,cpu.ram_size,file)==cpu.ram_size;fclose(file);if(!ok){cpu_free(&cpu);return 1;}
    cpu.external_read=handle_external_read;cpu.external_write=handle_external_write;
    cpu.gpr[1]=0x817F0000;cpu.gpr[13]=0x803C6020;cpu.gpr[2]=mem_read32(&cpu,0x803B3058);
    cpu.gpr[3]=a;cpu.gpr[4]=b;cpu.gpr[5]=c;cpu.pc=pc;cpu.lr=0x81800000;cpu.msr=0x2032;
    ProbeJournal journal={&cpu,0};ppc_set_mem_write_journal(probe_journal,&journal);
    u32 steps=0;
    while(cpu.pc!=0x81800000 && steps++<1000000) {
        if(cpu.pc==0x80296A50 && cpu.lr==cpu.pc)break;
        if(!dolrecomp_run_blocks(&cpu,1) && !handle_guest_exception(&cpu))break;
    }
    ppc_set_mem_write_journal(NULL,NULL);
    printf("[Probe result] steps=%u PC=%08X LR=%08X r3=%08X ref=%08X\n",steps,cpu.pc,cpu.lr,cpu.gpr[3],journal.watch ? mem_read32(&cpu,journal.watch|GC_RAM_BASE) : 0);
    u32 state=mem_read32(&cpu,cpu.gpr[13]-26944),top=mem_read32(&cpu,state+8),obj=mem_read32(&cpu,top-4);
    if(mem_read32(&cpu,top-8)==4 && obj>=GC_RAM_BASE && obj-GC_RAM_BASE<cpu.ram_size-1040)printf("[Probe Lua] %.1023s\n",cpu.ram+obj-GC_RAM_BASE+16);
    file=fopen("build_test/probe_ram.bin","wb");if(file){fwrite(cpu.ram,1,cpu.ram_size,file);fclose(file);}
    cpu_free(&cpu);return cpu.pc==0x81800000 ? 0 : 1;
}
