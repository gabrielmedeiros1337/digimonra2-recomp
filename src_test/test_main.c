#include "frame_timing.h"
#include "cpu_frame.h"
#include "guest_frame.h"
#include "gx_frame.h"
#include <fenv.h>
#include <xmmintrin.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOLRECOMP_ENABLE_REPLACEMENTS
#include "generated.h"
#include "dol_loader.h"
#include "portable_config.h"
#include "disc_image.h"
#include "card_hle.h"
#include "card_store.h"
#include "dvd_vfs.h"
#include "video_audio.h"
#include "input.h"
#include "display_mode.h"
#include "gx_pipe.h"
#include "gx_gl.h"
#include "hle_callbacks.h"
#include "os_context.h"
#include "locked_cache.h"
#include "paired_skinning.h"
#include "sdk_mtx44.h"
#include "sdk_floor.h"
#include "sdk_vec.h"
#include "native_copy.h"
#include "ax_hle.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>
static CPUState* s_crash_cpu;
static LONG WINAPI log_host_exception(EXCEPTION_POINTERS* exception) {
    FILE* log=fopen("runtime_crash.log","a");
    if (log) {
        fprintf(log,"Host exception %08lX at %p\n",exception->ExceptionRecord->ExceptionCode,exception->ExceptionRecord->ExceptionAddress);
        if (s_crash_cpu) {
            fprintf(log,"Guest PC=%08X LR=%08X MSR=%08X SP=%08X TB=%llu\n",s_crash_cpu->pc,s_crash_cpu->lr,s_crash_cpu->msr,s_crash_cpu->gpr[1],s_crash_cpu->timebase);
            for (u32 i=0;i<32;i++) fprintf(log,"r%u=%08X%c",i,s_crash_cpu->gpr[i],i%4==3 ? '\n' : ' ');
        }
        fclose(log);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}
#endif

static void diagnose_lua_error(CPUState* cpu) {
    if(cpu->pc<0x8026270Cu || cpu->pc>0x80262718u)return;
    u32 state=cpu->gpr[3];if(state<GC_RAM_BASE || state-GC_RAM_BASE>cpu->ram_size-88)return;
    u32 top=mem_read32(cpu,state+8);if(top<GC_RAM_BASE+8 || top-GC_RAM_BASE>cpu->ram_size)return;
    static u32 previous_top,previous_state,previous_status;
    if(previous_top==top && previous_state==state && previous_status==cpu->gpr[4])return;
    previous_top=top;previous_state=state;previous_status=cpu->gpr[4];
    u32 type=mem_read32(cpu,top-8),object=mem_read32(cpu,top-4);
    printf("[Lua error] state=%08X status=%u top=%08X type=%u value=%08X caller=%08X\n",state,cpu->gpr[4],top,type,object,cpu->lr);
    if(type==4 && object>=GC_RAM_BASE && object-GC_RAM_BASE<cpu->ram_size-16) {
        u32 at=object-GC_RAM_BASE+16,available=cpu->ram_size-at;if(available>1023)available=1023;
        char message[1024]={0};memcpy(message,cpu->ram+at,available);printf("[Lua message] %s\n",message);
    }
    u32 sp=cpu->gpr[1];
    for(u32 i=0;i<12 && sp>=GC_RAM_BASE && sp-GC_RAM_BASE<=cpu->ram_size-8;i++) {
        u32 next=mem_read32(cpu,sp);printf("[Lua stack] SP=%08X LR=%08X\n",sp,mem_read32(cpu,sp+4));if(next<=sp)break;sp=next;
    }
    FILE* ram=fopen("build_test/lua_error_ram.bin","wb");if(ram){fwrite(cpu->ram,1,cpu->ram_size,ram);fclose(ram);}
}

static u32 s_spr_hid0 = 0x0011C064u;
static bool s_hint_fallback;
void platform_continue_cpu_slice(void){s_hint_fallback=true;}
static u32 s_cpu_quantum=1024;
#ifdef _MSC_VER
static __declspec(thread) bool s_dispatch_fence;
#else
static _Thread_local bool s_dispatch_fence;
#endif
static bool s_chain_requested=true;
static bool (*s_dispatch_continue)(CPUState*,void*);
static void* s_dispatch_context;
static struct {u64 hosts,calls,links,budget_stops,fence_stops;} s_dispatch_stats;
static bool s_paced_event_pump=false;
static int s_aspect_ratio=0;
void platform_set_cpu_quantum(u32 quantum){if(quantum>=64 && quantum<=4096)s_cpu_quantum=quantum;}
void* handle_external_pointer(CPUState* cpu,u32 address,u32 size){(void)cpu;return locked_cache_pointer(address,size);}

typedef struct {u64 ticks;u32 samples;} CPUProfileEntry;
static CPUProfileEntry s_cpu_profile[0x300000/4];
static void dump_cpu_profile(u64 frequency) {
    u32 top[20]={0};u64 total=0;
    for(u32 i=0;i<0x300000/4;i++) {
        total+=s_cpu_profile[i].ticks;
        if(s_cpu_profile[i].ticks<=s_cpu_profile[top[19]].ticks)continue;
        u32 at=19;while(at && s_cpu_profile[i].ticks>s_cpu_profile[top[at-1]].ticks){top[at]=top[at-1];at--;}
        top[at]=i;
    }
    FILE* report=fopen("build_test/cpu_profile.csv","w");
    if(report)fputs("pc,samples,milliseconds,percent\n",report);
    for(u32 j=0;j<20;j++) {
        CPUProfileEntry* e=&s_cpu_profile[top[j]];
        double percent=total ? 100.0*e->ticks/total : 0;
        printf("[CPU profile] %08X samples=%u time=%.3f ms share=%.1f%%\n",GC_RAM_BASE+top[j]*4,e->samples,1000.0*e->ticks/frequency,percent);
        if(report)fprintf(report,"%08X,%u,%.3f,%.2f\n",GC_RAM_BASE+top[j]*4,e->samples,1000.0*e->ticks/frequency,percent);
    }
    if(report)fclose(report);
}

static inline u32 f32_to_u32_bits(float f) {
    union { float f; u32 u; } v;
    v.f = f;
    return v.u;
}

// Helper to find a file across candidate root directories
static bool find_existing_file(const char* rel_path, char* out_buf, size_t out_size) {
    const char* prefixes[] = {
        "",
        "../../",
        "../",
        NULL
    };

    char* base = SDL_GetBasePath();

    for (int i = 0; prefixes[i] != NULL; i++) {
        snprintf(out_buf, out_size, "%s%s", prefixes[i], rel_path);
        FILE* f = fopen(out_buf, "rb");
        if (f) {
            fclose(f);
            if (base) SDL_free(base);
            return true;
        }
    }

    if (base) {
        snprintf(out_buf, out_size, "%s%s", base, rel_path);
        FILE* f = fopen(out_buf, "rb");
        if (f) {
            fclose(f);
            SDL_free(base);
            return true;
        }

        snprintf(out_buf, out_size, "%s../../%s", base, rel_path);
        f = fopen(out_buf, "rb");
        if (f) {
            fclose(f);
            SDL_free(base);
            return true;
        }
        SDL_free(base);
    }

    return false;
}

static u64 s_total_frames = 0;

// Physical memory and MMIO handler
u64 handle_external_read(CPUState* cpu, u32 ea, u8 size) {
    s_dispatch_fence=true;
    if (ea <= cpu->ram_size && size <= cpu->ram_size - ea) {
        u8* ptr = cpu->ram + ea;
        switch (size) {
            case 1: return *ptr;
            case 2: { u16 v; memcpy(&v, ptr, 2); return _byteswap_ushort(v); }
            case 4: { u32 v; memcpy(&v, ptr, 4); return _byteswap_ulong(v); }
            case 8: { u64 v; memcpy(&v, ptr, 8); return _byteswap_uint64(v); }
        }
    }

    if(locked_cache_address(ea,size))return locked_cache_read(ea,size);
    if ((ea & 0xFF000000u) == 0x0C000000u) ea |= 0xC0000000u;
    u32 reg = ea & ~3u;
    if ((reg & 0xFFFFFF00) == 0xCC000000) return gx_pipe_read_cp(cpu, ea & 0xFF);
    if ((reg & 0xFFFFFF00) == 0xCC001000) return gx_pipe_read_pe(cpu, ea & 0xFF);
    // Video Interface (VI) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC002000) return video_read_vi(cpu, ea & 0x7F, size);
    // Processor Interface (PI) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC003000) return video_read_pi(cpu, ea & 0x3F, size);
    if ((reg & 0xFFFFFF00) == 0xCC005000) return audio_read_ai(cpu, ea & 0xFF, size);
    // Serial Interface (SI / Controller) MMIO (0xCC006400)
    if ((reg & 0xFFFFFF00) == 0xCC006400) return input_read_si(cpu, ea & 0xFF);
    if ((reg & 0xFFFFFF00u) == 0xCC006C00u) return audio_read_interface(cpu, ea & 0x1F, size);
    // External Interface (EXI) MMIO (0xCC006800)
    if ((reg & 0xFFFFFF00) == 0xCC006800) {
        static u32 s_exi_counter = 0;
        u32 offset = ea & 0xFF;
        if (offset == 0x08 || offset == 0x1C || offset == 0x30) {
            return ++s_exi_counter;
        }
        return 0;
    }

    // DVD Interface MMIO (0xCC006000)
    if ((reg & 0xFFFFFF00) == 0xCC006000) {
        return dvd_vfs_read_reg(cpu, ea & 0xFF);
    }

    return 0;
}

void handle_external_write(CPUState* cpu, u32 ea, u64 value, u8 size) {
    // Gather-pipe writes are ordered producer commands, not CPU safepoints.
    // PE/CP interrupt assertion remains observable by dispatch_continue().
    if((ea&0xFFFFFFE0u)==0xCC008000u || (ea&0xFFFFFFE0u)==0x0C008000u){
        gx_pipe_write_fifo(cpu,ea|0xC0000000u,value,size);return;
    }
    s_dispatch_fence=true;
    if (ea <= cpu->ram_size && size <= cpu->ram_size - ea) {
        u8* ptr = cpu->ram + ea;
        ppc_mark_host_write(ptr,size);
        switch (size) {
            case 1: *ptr = (u8)value; break;
            case 2: { u16 v = _byteswap_ushort((u16)value); memcpy(ptr, &v, 2); break; }
            case 4: { u32 v = _byteswap_ulong((u32)value); memcpy(ptr, &v, 4); break; }
            case 8: { u64 v = _byteswap_uint64(value); memcpy(ptr, &v, 8); break; }
        }
        return;
    }

    // Hot FIFO writes bypass unrelated LC/device register dispatch.
    if(locked_cache_address(ea,size)){locked_cache_write(ea,value,size);return;}
    if ((ea & 0xFF000000u) == 0x0C000000u) ea |= 0xC0000000u;
    u32 reg = ea & ~3u;
    // Command Processor (CP) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC000000) {
        gx_pipe_write_cp(cpu, ea & 0xFF, (u32)value);
        return;
    }
    // Pixel Engine (PE) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC001000) {
        gx_pipe_write_pe(cpu, ea & 0xFF, (u32)value);
        return;
    }
    // Video Interface (VI) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC002000) {
        video_write_vi(cpu, ea & 0x7F, value, size);
        return;
    }
    // Processor Interface (PI) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC003000) {
        video_write_pi(cpu, ea & 0x3F, value, size);
        return;
    }
    // Audio Interface (AI) MMIO
    if ((reg & 0xFFFFFF00) == 0xCC005000) {
        audio_write_ai(cpu, ea & 0xFF, value, size);
        return;
    }
    // Serial Interface (SI / Controller) MMIO (0xCC006400)
    if ((reg & 0xFFFFFF00) == 0xCC006400) {
        input_write_si(cpu, ea & 0xFF, (u32)value);
        return;
    }
    if ((reg & 0xFFFFFF00u) == 0xCC006C00u) { audio_write_interface(cpu, ea & 0x1F, value, size); return; }
    // External Interface (EXI) MMIO (0xCC006800)
    if ((reg & 0xFFFFFF00) == 0xCC006800) {
        return;
    }
    // DVD Interface MMIO (0xCC006000)
    if ((reg & 0xFFFFFF00) == 0xCC006000) {
        dvd_vfs_write_reg(cpu, ea & 0xFF, (u32)value);
        return;
    }
}

static u32 platform_spr_read(CPUState* cpu,u16 spr,u32 cia) {
    (void)cpu;(void)cia;u32 value;
    if(locked_cache_spr_read(spr,&value))return value;
    if(spr==1008)return s_spr_hid0;
    if(spr==287)return PPC_GEKKO_PVR;
    return 0;
}
static void platform_spr_write(CPUState* cpu,u16 spr,u32 value,u32 cia) {
    (void)cia;if(locked_cache_spr_write(cpu,spr,value))return;
    if(spr==1008)s_spr_hid0=value;
}

void handle_instruction_fallback(CPUState* cpu, u32 raw, u32 cia) {
    s_dispatch_fence=true;
    u32 opcode = (raw >> 26) & 0x3F;
    u32 sub_op = (raw >> 1) & 0x3FF;
    // Coherent cache stores/flushes need no host event boundary per vertex.
    // Keep installed cache callbacks and all architectural instructions intact.
    if(opcode==31 && (sub_op==278 || sub_op==246 || sub_op==54 || sub_op==86) && !cpu->cache_control)s_hint_fallback=true;

    // SDK cache-range loops on coherent host RAM have no data side effects.
    // Collapse their remaining iterations, preserving the exact integer state
    // and resuming at the original sync/return instruction. Never batch when
    // a runtime cache callback is installed.
    if(opcode==31 && !cpu->cache_control && cpu->ctr && cpu->ctr<=0x80000u) {
        u32 end=0;
        if(cia==0x802BF29Cu && sub_op==470)end=0x802BF2A8u;
        if(cia==0x802BF2C8u && sub_op==86)end=0x802BF2D4u;
        if(cia==0x802BF2F8u && sub_op==54)end=0x802BF304u;
        if(cia==0x802BF328u && sub_op==86)end=0x802BF334u;
        if(cia==0x802BF354u && sub_op==54)end=0x802BF360u;
        if(end) {
            cpu->gpr[3]+=cpu->ctr*32u;
            cpu->downcount-=(s64)cpu->ctr*2;
            cpu->ctr=0;cpu->pc=end;return;
        }
    }

    if (opcode == 31 && sub_op == 339) { // mfspr
        u32 rd = (raw >> 21) & 0x1F;
        u32 spr = ((raw >> 16) & 0x1F) | (((raw >> 11) & 0x1F) << 5);
        cpu->gpr[rd] = platform_spr_read(cpu,(u16)spr,cia);
        cpu->pc = cia + 4;
        return;
    }
    if (opcode == 31 && sub_op == 467) { // mtspr
        u32 rs = (raw >> 21) & 0x1F;
        u32 spr = ((raw >> 16) & 0x1F) | (((raw >> 11) & 0x1F) << 5);
        platform_spr_write(cpu,(u16)spr,cpu->gpr[rs],cia);
        cpu->pc = cia + 4;
        return;
    }

    cpu->pc = cia + 4;
}

static SDL_Window* s_main_window = NULL;
static SDL_Renderer* s_main_renderer = NULL;
static u32 s_current_frame_num = 0;
static bool s_unblack_called = false;
static u32 s_dvd_read_count = 0;
static u32 s_scene_address;

static void save_thread_context(CPUState* cpu, u32 thread_addr) {
    if (thread_addr < GC_RAM_BASE || (thread_addr - GC_RAM_BASE + 0x2C8) > cpu->ram_size) return;
    for (int i = 0; i < 32; i++) {
        mem_write32(cpu, thread_addr + (u32)i * 4u, cpu->gpr[i]);
    }
    mem_write32(cpu, thread_addr + 0x080u, cpu->cr);
    mem_write32(cpu, thread_addr + 0x084u, cpu->lr);
    mem_write32(cpu, thread_addr + 0x088u, cpu->ctr);
    mem_write32(cpu, thread_addr + 0x08Cu, cpu->xer);
    if(mem_read32(cpu,0x800000D8u)==thread_addr) hle_os_save_fpu(cpu,thread_addr);
    mem_write32(cpu, thread_addr + 0x198u, cpu->pc);
    mem_write32(cpu, thread_addr + 0x19Cu, cpu->msr);
    for (int i = 0; i < 8; i++) {
        mem_write32(cpu, thread_addr + 0x1A4u + (u32)i * 4u, cpu->gqr[i]);
    }
}

static void restore_thread_context(CPUState* cpu, u32 thread_addr) {
    if (thread_addr < GC_RAM_BASE || (thread_addr - GC_RAM_BASE + 0x2C8) > cpu->ram_size) return;
    for (int i = 0; i < 32; i++) {
        cpu->gpr[i] = mem_read32(cpu, thread_addr + (u32)i * 4u);
    }
    cpu->cr  = mem_read32(cpu, thread_addr + 0x080u);
    cpu->lr  = mem_read32(cpu, thread_addr + 0x084u);
    cpu->ctr = mem_read32(cpu, thread_addr + 0x088u);
    cpu->xer = mem_read32(cpu, thread_addr + 0x08Cu);
    u32 saved_pc = mem_read32(cpu, thread_addr + 0x198u);
    if (saved_pc >= GC_RAM_BASE && saved_pc < GC_RAM_BASE + cpu->ram_size) {
        cpu->pc = saved_pc;
    }
    cpu->msr = mem_read32(cpu, thread_addr + 0x19Cu) | 0x8000u;
    if(mem_read32(cpu,0x800000D8u)!=thread_addr)cpu->msr&=~0x2000u;
    for (int i = 0; i < 8; i++) {
        cpu->gqr[i] = mem_read32(cpu, thread_addr + 0x1A4u + (u32)i * 4u);
    }
    mem_write32(cpu, 0x800000D4u, thread_addr);
    mem_write32(cpu, 0x800000E4u, thread_addr);
    mem_write16(cpu, thread_addr + 0x2C8u, 2); // OS_THREAD_STATE_RUNNING
}

// Replacement dispatcher: hooks and NULL guard
static int platform_dispatch_replacement(CPUState* ctx, u32 address) {
    // Exact PC selection avoids walking every HLE comparison on ordinary calls.
    // Each case retains the existing handler; unhandled PCs execute the guest.
    switch(address) {
    /* Portable Slot A SDK services, outside the rendering/CPU pipeline. */
    case 0x802A8A70u:
    case 0x802A8B4Cu:
    case 0x802A8D30u:
    case 0x802A8D60u:
    case 0x802A8F38u:
    case 0x802A8FBCu:
    case 0x802A9040u:
    case 0x802AA114u:
    case 0x802AA6A4u:
    case 0x802AA6CCu:
    case 0x802AA728u:
    case 0x802AA89Cu:
    case 0x802AA8D4u:
    case 0x802AAF98u:
    case 0x802AB138u:
    case 0x802AB21Cu:
    case 0x802ABAF4u:
    case 0x802ABDC8u:
    case 0x802ABF28u:
    case 0x802AC0A0u:
    case 0x802AC22Cu:
    case 0x802AC44Cu:
    case 0x802AC77Cu:
    case 0x802AC8C4u:
    case 0x802ACBB8u:
    case 0x802ACCCCu:
    case 0x802ACDB8u:
    case 0x802ACEE4u:
    case 0x802ACF2Cu:
    case 0x802AD03Cu:
    case 0x802AD27Cu:
    case 0x802AD3A8u:
    case 0x802AD51Cu:
        return card_hle_dispatch(ctx,address);

    case 0x80249858u: {
        if (s_aspect_ratio == 1) {
            // Expand horizontal camera frustum bounds (f1 = left, f2 = right) by 4/3
            // so CPU Frustum Culling planes match the 16:9 widescreen Hor+ field of view:
            ctx->fpr[1] *= (4.0f / 3.0f);
            ctx->fpr[2] *= (4.0f / 3.0f);
            ctx->ps1[1] = ctx->fpr[1];
            ctx->ps1[2] = ctx->fpr[2];
        }
        return 0; // Fall through to execute guest 0x80249858 with expanded frustum
    }
    case 0x8028BEDCu:
    case 0x8028BF58u:
        if(sdk_vec_transform(ctx,false)){platform_continue_cpu_slice();return 1;}return 0;
    case 0x8029D888u:
        if(sdk_floor(ctx,false)){platform_continue_cpu_slice();return 1;}return 0;
    case 0x802B4D08u:
        return sdk_mtx44_concat(ctx) ? 1 : 0;
    case 0x8024BB18u:
        return paired_skinning_blend_entry(ctx) ? 1 : 0;
    case 0x8024BC48u:
        return paired_skinning_step(ctx) ? 1 : 0;
    case 0x8024C244u:
    case 0x8024C2CCu:
        return paired_skinning_accumulate_step(ctx) ? 1 : 0;
    case 0x8024C014u:
        return paired_skinning_transform_step(ctx) ? 1 : 0;
    case 0x8024BF84u:
        return paired_skinning_transform_entry(ctx) ? 1 : 0;
    case 0x8024C500u:
    case 0x8024C508u:
    case 0x8024C518u:
        return paired_skinning_environment_step(ctx) ? 1 : 0;
    case 0x81800000u:
        return hle_callbacks_return(ctx,address) ? 1 : 0;
    case 0:
    case 0x80000000u:
    {
        static int s_zero_count = 0;
        if (s_zero_count < 5) {
            s_zero_count++;
            printf("[DISPATCH 0 #%d] Address 0 jumped to! LR=0x%08X r1=0x%08X r12=0x%08X r31=0x%08X\n",
                   s_zero_count, ctx->lr, ctx->gpr[1], ctx->gpr[12], ctx->gpr[31]);
            printf("  Stack at r1 (0x%08X):", ctx->gpr[1]);
            for (u32 o = 0; o < 32; o += 4) {
                printf(" +%d: 0x%08X", o, mem_read32(ctx, ctx->gpr[1] + o));
            }
            printf("\n");
            if (ctx->gpr[31] >= 0x80000000u && ctx->gpr[31] < (0x80000000u + ctx->ram_size)) {
                printf("  Memory at r31 (0x%08X):", ctx->gpr[31]);
                for (s32 o = -8; o <= 16; o += 4) {
                    printf(" [%+d]: 0x%08X", o, mem_read32(ctx, ctx->gpr[31] + o));
                }
                printf("\n");
            }
            fflush(stdout);
        }
        if (ctx->lr == 0) {
            // If LR is 0, attempt to restore from caller's stack frame (r1)
            u32 caller_sp = mem_read32(ctx, ctx->gpr[1]);
            u32 caller_lr = (caller_sp != 0) ? mem_read32(ctx, caller_sp + 4) : 0;
            printf("  [DISPATCH 0] Attempting stack unwind: caller_sp=0x%08X caller_lr=0x%08X\n", caller_sp, caller_lr);
            fflush(stdout);
            if (caller_lr != 0) {
                ctx->gpr[1] = caller_sp;
                ctx->pc = caller_lr;
                return 1;
            }
            return 0; // stop execution so we don't spin in place
        }
        if (ctx->lr == 0x8002FCACu || (ctx->lr >= 0x8002FBD0u && ctx->lr <= 0x8002FD00u)) {
            static u32 s_zero_fcac_cnt = 0;
            if (s_zero_fcac_cnt++ < 10) {
                printf("[DISPATCH 0 -> LR=0x%08X #%u] Evitando salto nulo em std::vector::reserve! Retornando para LR\n",
                       ctx->lr, s_zero_fcac_cnt);
                fflush(stdout);
            }
            ctx->pc = ctx->lr;
            return 1;
        }
        if (ctx->lr == 0x801CE024u) {
            static u32 s_zero_skip_cnt = 0;
            if (s_zero_skip_cnt++ < 10) {
                printf("[DISPATCH 0 -> 0x801CE05C #%u] Callback NULL em 0x801CE020! Finalizando lista de nos e pulando para 0x801CE05C\n",
                       s_zero_skip_cnt);
                fflush(stdout);
            }
            ctx->pc = 0x801CE05Cu;
            return 1;
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // Scene Object circular list initialization guard (0x801CDFAC):
    // In chunk_0115, func_801CDFAC iterates scene nodes for container r3.
    // If the list head 0(r3) is 0 (uninitialized circular list), point it to itself (empty list)
    // so cmpw r9, r23 matches immediately and avoids looping on NULL.
    case 0x801CDFACu:
    {
        u32 r3 = ctx->gpr[3];
        if (r3 >= GC_RAM_BASE && (r3 - GC_RAM_BASE + 4) <= ctx->ram_size) {
            u32 head = mem_read32(ctx, r3);
            if (head == 0) {
                mem_write32(ctx, r3, r3);
                static u32 s_init_list_cnt = 0;
                if (s_init_list_cnt++ < 10) {
                    printf("[Scene List Init 0x801CDFAC #%u] Lista circular vazia detectada em 0x%08X; definindo head=self!\n",
                           s_init_list_cnt, r3);
                    fflush(stdout);
                }
            }
        }
        return 0; // Let native 0x801CDFAC run
        break;
    }
    // Scene Object Node circular list unblock (0x801CDFE4):
    // In chunk_0115, when iterating the circular scene node chain from r23,
    // if 8(r1) is 0 or outside valid RAM, cmpw r9, r23 fails to match (0 != r23), looping forever.
    // Cleanly advance PC to 0x801CE05C to exit the node loop.
    case 0x801CDFE4u:
    {
        u32 node = (ctx->gpr[1] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[1] + 8) : 0;
        if (node == 0 || node < GC_RAM_BASE || node == ctx->gpr[23]) {
            static u32 s_node_exit_cnt = 0;
            if (s_node_exit_cnt++ < 10 || (s_node_exit_cnt % 60 == 0)) {
                printf("[Scene Node Break 0x801CDFE4 #%u] Fim da lista alcancado (node=0x%08X, sentinel=0x%08X). Avancando para 0x801CE05C!\n",
                       s_node_exit_cnt, node, ctx->gpr[23]);
                fflush(stdout);
            }
            ctx->pc = 0x801CE05Cu;
            return 1;
        }
        break;
    }
    // BSS / Data pointer jump guard: Prevent jumping into non-code RAM structures (e.g. 0x803BFD58)
    // Audio Voice Allocation Guard (0x80212490):
    // If r30 (event) is -1 (0xFFFFFFFF), there is no pending event (already consumed).
    // Jump directly to epilogue (0x802124D0) to prevent infinite allocation loop.
    case 0x80212490u:
    case 0x80212494u:
    {
        u32 ev340 = ctx->gpr[30];
        if (ev340 == 0xFFFFFFFFu) {
            static u32 s_ev_skip_cnt = 0;
            if (s_ev_skip_cnt++ < 5 || (s_ev_skip_cnt % 300 == 0)) {
                printf("[Audio Alloc 0x80212490 #%u] r30=0xFFFFFFFF (sem evento). Pulando para epilogo 0x802124D0!\n",
                       s_ev_skip_cnt);
                fflush(stdout);
            }
            ctx->pc = 0x802124D0u;
            return 1;
        }
        return 0;
    }
    // DSPInit (0x802BEF68) and DSP sync routines:
    // Real hardware DSP is simulated HLE on PC host; return immediately or advance to epilogue
    case 0x802BEF68u:
    {
        ctx->pc = ctx->lr;
        return 1;
    }
    // OSResetSystem (0x802C50DC): Console reset stub - return immediately to continue PC runtime
    case 0x802C50DCu:
    {
        printf("[HLE OSResetSystem 0x802C50DC] Console reset evitado; avancando para proxima cena! (caller=0x%08X)\n", ctx->lr);
        fflush(stdout);
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADInit (0x802D76D0): Initialize PAD subsystem and return success
    case 0x802D76D0u:
    {
        printf("[HLE PADInit 0x802D76D0] PAD Subsystem inicializado com sucesso (caller=0x%08X)\n", ctx->lr);
        fflush(stdout);
        ctx->gpr[3] = 1;
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADRead (0x802D78E8 & 0x802D7CB4): Populate all four PADStatus slots from physical host input
    case 0x802D78E8u:
    case 0x802D7CB4u:
    {
        u32 out = ctx->gpr[3];
        NativePadState pads[4];u16 buttons=0;
        for(int i=0;i<4;i++){pads[i]=*input_get_pad(i);buttons|=pads[i].button;}
        u32 mask=input_store_pad_status(ctx,out,pads);
        static u32 s_padread_cnt=0;
        if(s_padread_cnt++<3 || (buttons && s_padread_cnt%60==0)) {
            printf("[HLE PADRead 0x%08X #%u] mask=%08X buttons=%04X/%04X/%04X/%04X caller=%08X\n",
                   address,s_padread_cnt,mask,pads[0].button,pads[1].button,pads[2].button,pads[3].button,ctx->lr);
        }
        ctx->gpr[3]=mask;
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADClamp (0x802D68E4): Stick normalization & deadzone
    case 0x802D68E4u:
    {
        ctx->gpr[3] = 1;
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADControlMotor (0x802D7D6C): Rumble motor control
    case 0x802D7D6Cu:
    {
        ctx->pc = ctx->lr;
        return 1;
    }
    // Game File Read (0x80222EA8)
    case 0x80222EA8u:
    {
        static u32 s_read_cnt = 0;
        if (s_read_cnt++ < 15) {
            printf("[Game Read 0x80222EA8 #%u] handle=0x%08X dst=0x%08X len=%u (caller=0x%08X)\n",
                   s_read_cnt, ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->lr);
            fflush(stdout);
        }
        return 0; // Let native logic run to prepare request
    }
    // DVDReadAsync (0x802B6BA4)
    case 0x802B6BA4u:
    {
        printf("[DVDReadAsync 0x802B6BA4] info=0x%08X dst=0x%08X len=%u off=%u (caller=0x%08X)\n",
               ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->gpr[6], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // DVDReadAbsAsyncPrio: r7 is DVDCallback(result, DVDCommandBlock*).
    case 0x802B92B0u:
    {
        u32 info = ctx->gpr[3], dst = ctx->gpr[4], len = ctx->gpr[5];
        u32 off = ctx->gpr[6], cb = ctx->gpr[7];
        if (info < GC_RAM_BASE || info - GC_RAM_BASE > ctx->ram_size - 48 ||
            dst < GC_RAM_BASE || dst - GC_RAM_BASE > ctx->ram_size ||
            len > ctx->ram_size - (dst - GC_RAM_BASE) ||
            !hle_callbacks_has_space()) {
            ctx->gpr[3] = 0;
        } else {
            if(!dvd_vfs_read_async(info,dst,len,off,cb)){ctx->gpr[3]=0;ctx->pc=ctx->lr;return 1;}
            mem_write32(ctx,info+8,1);mem_write32(ctx,info+12,1);
            mem_write32(ctx,info+16,off);mem_write32(ctx,info+20,len);mem_write32(ctx,info+24,dst);
            mem_write32(ctx,info+28,0);mem_write32(ctx,info+32,0);mem_write32(ctx,info+40,cb);
            s_dvd_read_count++;
            if(s_dvd_read_count<=8)printf("[DVD queued #%u] off=%08X len=%u callback=%08X\n",s_dvd_read_count,off,len,cb);
            ctx->gpr[3]=1;

        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // OSReport (0x802C06BC)
    case 0x802C06BCu:
    {
        u32 fmt_ptr = ctx->gpr[3];
        if (fmt_ptr >= GC_RAM_BASE && (fmt_ptr - GC_RAM_BASE) < ctx->ram_size) {
            char fmt_buf[256];
            strncpy(fmt_buf, (const char*)(ctx->ram + (fmt_ptr - GC_RAM_BASE)), sizeof(fmt_buf) - 1);
            fmt_buf[sizeof(fmt_buf) - 1] = '\0';
            printf("[OSReport 0x802C06BC] %s\n", fmt_buf);
            fflush(stdout);
        }
        return 0; // Let native OSReport run
        break;
    }
    // OSPanic (0x802C075C): Intercept and diagnose panics with callstack
    case 0x802C075Cu:
    {
        u32 file_ptr = ctx->gpr[3];
        u32 line     = ctx->gpr[4];
        u32 msg_ptr  = ctx->gpr[5];
        char file_str[128] = {0};
        char msg_str[128] = {0};
        if (file_ptr >= GC_RAM_BASE && (file_ptr - GC_RAM_BASE) < ctx->ram_size) {
            strncpy(file_str, (const char*)(ctx->ram + (file_ptr - GC_RAM_BASE)), sizeof(file_str) - 1);
        }
        if (msg_ptr >= GC_RAM_BASE && (msg_ptr - GC_RAM_BASE) < ctx->ram_size) {
            strncpy(msg_str, (const char*)(ctx->ram + (msg_ptr - GC_RAM_BASE)), sizeof(msg_str) - 1);
        }
        printf("\n====================================================================\n");
        printf("OSPanic interceptado: %s (linha %u)\n", msg_str, line);
        printf("[OSPanic 0x802C075C] File: '%s' | Line: %u | Msg: '%s' (caller=0x%08X)\n",
               file_str, line, msg_str, ctx->lr);
        printf("--- CALLSTACK TRACE ---\n");
        u32 cur_sp = ctx->gpr[1];
        for (int frame = 0; frame < 12 && cur_sp >= GC_RAM_BASE && (cur_sp - GC_RAM_BASE) < ctx->ram_size; frame++) {
            u32 next_sp = mem_read32(ctx, cur_sp);
            u32 saved_lr = mem_read32(ctx, cur_sp + 4);
            printf("  Frame #%d: SP=0x%08X LR=0x%08X\n", frame, cur_sp, saved_lr);
            if (next_sp <= cur_sp || next_sp < GC_RAM_BASE || (next_sp - GC_RAM_BASE) >= ctx->ram_size) break;
            cur_sp = next_sp;
        }
        printf("====================================================================\n\n");
        fflush(stdout);
        return 0; // Let native logic handle or halt
        break;
    }
    // Panic / Error Handler (0x802C1534)
    case 0x802C1534u:
    {
        printf("[Panic/Error 0x802C1534] r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X (caller=0x%08X)\n",
               ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->gpr[6], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // PPCHalt (0x802D6458): Game spin/halt loop
    case 0x802D6458u:
    {
        static u32 s_halt_cnt = 0;
        if (s_halt_cnt++ == 0) {
            printf("[PPCHalt 0x802D6458] System entered PPCHalt spin loop (caller=0x%08X)!\n", ctx->lr);
            fflush(stdout);
        }
        return 0;
    }
    // DVDLowCommand (0x802BC754)
    case 0x802BC754u:
    {
        printf("[DVDLowCommand 0x802BC754] cmd=0x%08X (caller=0x%08X)\n", ctx->gpr[3], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // Scene UI Start (0x8014B4B4)
    case 0x8014B4B4u:
    {
        static u32 s_ui_cnt = 0;
        if (s_ui_cnt++ < 3 || (s_ui_cnt % 60 == 0)) {
            printf(">>> [Scene UI Start 0x8014B4B4] obj=0x%08X (caller=0x%08X) <<<\n",
                   ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        return 0;
    }
    // Scene transitions, resource readiness, faders and VI black requests execute
    // the original guest logic. Never infer resource completion from read counts.
    case 0x801AC614u:
    {
        s_scene_address = ctx->gpr[3];
        static u32 previous = 0xFFFFFFFFu;
        if (s_scene_address >= GC_RAM_BASE && s_scene_address - GC_RAM_BASE <= ctx->ram_size - 152) {
            u32 state = mem_read32(ctx, s_scene_address + 8);
            if (state != previous) {
                previous = state;
                printf("[Scene] obj=%08X state=%u front=%08X back=%08X load=%u pending=%u\n", s_scene_address, state,
                       mem_read32(ctx,s_scene_address+60),mem_read32(ctx,s_scene_address+64),
                       mem_read32(ctx,s_scene_address+144),mem_read32(ctx,s_scene_address+148));
            }
        }
        break;
    }
    case 0x801AD410u:
    {
        printf("[SceneSetState] scene=0x%08X requested=%u caller=0x%08X\n",
               ctx->gpr[3], ctx->gpr[4], ctx->lr);
        break;
    }
    // Engine I/O queue and drive status run natively; DVD completion below
    // supplies actual data and the SDK callback instead of fabricated flags.
    // getenv hook (0x80296AB0)
    case 0x80296AB0u:
    {
        ctx->gpr[3] = 0;
        ctx->pc = ctx->lr;
        return 1;
    }
    // GXCopyDisp is 0x802D06BC, not 0x802D06A0 (copy gamma).
    // Execute original: BP 0x4B sets destination; BP 0x52 performs the copy.
    // Caller probe for 0x802D78C8 / 0x802D7A4C / 0x80248F18
    case 0x802D78C8u:
    case 0x802D7A4Cu:
    case 0x80248F18u:
    {
        static u32 s_probe_count = 0;
        if (s_probe_count++ < 10) {
            u32 b0 = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x674C) : 0;
            u32 b1 = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x6750) : 0;
            u32 idx = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x6748) : 0;
            u32 px0 = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x6784) : 0;
            u32 px1 = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x6780) : 0;
            printf("[Display Probe 0x%08X #%u] desc0=0x%08X desc1=0x%08X px0=0x%08X px1=0x%08X idx=%u\n",
                   address, s_probe_count, b0, b1, px0, px1, idx);
            if (b0 >= GC_RAM_BASE && (b0 - GC_RAM_BASE + 32) <= ctx->ram_size) {
                printf("  [desc0 0x%08X]: [0]=0x%08X [4]=0x%08X [8]=0x%08X [12]=0x%08X [16]=0x%08X\n",
                       b0,
                       mem_read32(ctx, b0),
                       mem_read32(ctx, b0 + 4),
                       mem_read32(ctx, b0 + 8),
                       mem_read32(ctx, b0 + 12),
                       mem_read32(ctx, b0 + 16));
            }
            fflush(stdout);
        }
        break;
    }
    // GPU completion and VI callbacks execute through the original SDK handlers.
    default:
        break;
    }
    if (address >= 0x80359200u && address < 0x80400000u) {
        static u32 s_guard_data_cnt = 0;
        if (s_guard_data_cnt++ < 10) {
            printf("[GUARD BSS Call #%u] Evitando salto para dados em 0x%08X! Retornando para LR=0x%08X\n",
                   s_guard_data_cnt, address, ctx->lr);
            fflush(stdout);
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    return 0;
}

int dolrecomp_dispatch_replacement(CPUState* ctx,u32 address){
    int handled=platform_dispatch_replacement(ctx,address);
    if(handled)s_dispatch_fence=true;
    return handled;
}
bool handle_guest_exception(CPUState* cpu) {
    if (cpu->exception & PPC_EXC_SYSTEM_CALL) {
        cpu->exception &= ~PPC_EXC_SYSTEM_CALL;
        cpu->msr = cpu->srr1; cpu->pc = cpu->srr0;
        return true;
    }
    if(hle_os_fp_unavailable(cpu))return true;
    return false;
}

int platform_self_test(void);
extern bool g_native_ram_inline_enabled;
extern bool g_native_blocks_enabled;
extern bool g_float_bits_enabled;
extern const bool g_float_bits_available;
extern u64 platform_native_block_entries(void);
static bool dispatch_test_continue(CPUState* cpu,void* ignored){(void)ignored;return cpu->pc!=cpu->lr;}
void platform_test_chaining(bool enabled){s_dispatch_continue=enabled ? dispatch_test_continue:NULL;s_dispatch_context=NULL;s_dispatch_fence=false;}
int platform_execute_cpu_slice(CPUState* cpu) {
    // The generated backedge/dispatch guards consume this budget. A negative
    // value from an earlier slice must never make every later loop yield.
    cpu->downcount=(s64)s_cpu_quantum-DOLRECOMP_C_LOOP_CYCLE_BUDGET;
    if(s_dispatch_continue)s_dispatch_stats.hosts++;
    s_dispatch_fence=false;
    int result;
    do {
        s_hint_fallback=false;
        result=dolrecomp_run_blocks(cpu,1);
        if(s_dispatch_continue)s_dispatch_stats.calls++;
        if(!result || cpu->exception)break;
        if(cpu->downcount<=-(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET){if(s_dispatch_continue)s_dispatch_stats.budget_stops++;break;}
        if(s_hint_fallback)continue; // Existing cache/prefetch continuation contract.
        if(!s_dispatch_continue || !s_chain_requested)break;
        if(s_dispatch_fence){s_dispatch_stats.fence_stops++;break;}
        if(!s_dispatch_continue(cpu,s_dispatch_context))break;
        s_dispatch_stats.links++;
    } while(true);
    return result;
}
int platform_lua_probe(const char* path);
int platform_guest_call(const char*,u32,u32,u32,u32);

typedef struct {
    CPUState* cpu;NativePadState pads[4];
    u64 total_blocks,active_blocks,cpu_ticks,pump_ticks,pacing_frequency;u32 pump_calls,profile_random;
    bool profile_cpu,threaded;GuestFrameBudget* budget;
} CPUFrameJob;
typedef struct {CPUFrameJob* job;u32* slice;u32 limit;u64 event;bool* force_devices;} DispatchContinuation;
static bool dispatch_continue(CPUState* cpu,void* opaque){
    DispatchContinuation* c=opaque;u32 next=*c->slice+1u,pc=cpu->pc;
    // Keep all original host safepoints. No recursion, instruction reordering,
    // budget reset, frame merge, or delay beyond the original128-position poll.
    if(c->job->profile_cpu || next>=c->limit || !(next&127u) || !(cpu->msr&0x8000u) || cpu->timebase>=c->event || video_interrupt_pending() || hle_callbacks_busy() || dvd_vfs_pending_reads())return false;
    if((pc>=0x802C0000u && pc<0x802CC000u) || (pc>=0x802DC000u && pc<0x802E0000u) ||
       (pc>=0x801CDFE4u && pc<=0x801CE058u) || (pc>=0x8026270Cu && pc<=0x80262718u) ||
       pc==0x80212490u || pc==0x80212494u || pc==0x8022BD44u)return false;
    // Account exactly the same logical host positions/TB steps as the old loop.
    // Hardware event delivery stays in the outer pump, forced at its deadline.
    GuestFrameBudget* b=c->job->budget;
    u64 step=(b->phase+9u)>>2;
    if(cpu->timebase+step>=c->event){*c->force_devices=true;return false;}
    *c->slice=next;cpu->timebase=guest_frame_step(b,cpu->timebase);
    b->dispatches++;c->job->active_blocks++;c->job->total_blocks++;
    return true;
}
static bool scheduler_idle(CPUState* cpu){
    u32 offset=cpu->gpr[13]-25512u-GC_RAM_BASE;
    return cpu->pc==0x802C7A44u && !cpu->exception && (cpu->msr&0x8000u) && offset<=cpu->ram_size-4 && mem_read32(cpu,cpu->gpr[13]-25512u)==0;
}
static bool scheduler_waiting_retrace(CPUState* cpu){
    u32 queue=cpu->gpr[13]-25188u,offset=queue-GC_RAM_BASE;
    if(offset>cpu->ram_size-8)return false;u32 thread=mem_read32(cpu,queue);
    if(thread<GC_RAM_BASE || thread-GC_RAM_BASE>cpu->ram_size-0x2E8)return false;
    return mem_read16(cpu,thread+0x2C8)==4 && mem_read32(cpu,thread+0x2DC)==queue;
}
static void run_guest_frame(void* opaque){
    CPUFrameJob* job=opaque;CPUState* cpu=job->cpu;
    input_bind_frame(job->pads);
    static const int rounds[4]={FE_TONEAREST,FE_TOWARDZERO,FE_UPWARD,FE_DOWNWARD};
    fesetround(rounds[cpu->fpscr&3u]);u32 csr=_mm_getcsr();csr&=~0x8040u;if(cpu->fpscr&4u)csr|=0x8040u;_mm_setcsr(csr);
        FrameStage game_stage=frame_timing_enter(FRAME_GAME);
        u64 cpu_start=SDL_GetPerformanceCounter(),last_pump_tick=cpu_start;
        GuestFrameBudget* budget=job->budget;bool force_devices=true,cancelled=false;
        // Non-combat boot/menu keeps the recovered scheduler. Combat gets 3x
        // execution quota with the same 675000-TB interval, then resumes that
        // same interval if a watchdog job ends while guest work is still live.
        u32 job_limit=budget ? GUEST_FRAME_JOB_SLICES:GUEST_FRAME_BASE_SLICES;u64 next_event=0;
        for (u32 slice=0;slice<job_limit;slice++) {
            if(job->threaded && !(slice&127u) && cpu_frame_cancelled()){cancelled=true;break;}
            if(budget)cpu->timebase=guest_frame_step(budget,cpu->timebase);
            else cpu->timebase+=(slice&3) ? 7u:6u;
            bool horizon=budget && cpu->timebase>=budget->deadline && !budget->horizon_polled;
            if(!(slice&127u) || (budget && (force_devices || horizon))){
                gx_pipe_process_frame(cpu);audio_tick(cpu);force_devices=false;
                if(budget)next_event=video_next_event(cpu,budget->deadline);
                if(horizon)budget->horizon_polled=true;
            }

            // PAD is sampled at the frame's SDL_PollEvent/input_poll above.
            // Keep long frames responsive without polling XInput at every slice.
            if (!job->threaded && (slice & 2047) == 0) {
                u64 pump_start=SDL_GetPerformanceCounter();
                if(!s_paced_event_pump || pump_start-last_pump_tick>=job->pacing_frequency/120u) {
                    SDL_PumpEvents();last_pump_tick=SDL_GetPerformanceCounter();
                    job->pump_ticks+=last_pump_tick-pump_start;job->pump_calls++;
                }
            }

            dvd_vfs_pump(cpu);
            video_poll_interrupt(cpu);
            hle_callbacks_pump(cpu);
            // A rendered interval may also end at its real VI deadline while
            // foreground code is live. Preserve its PC/stack for next VI;
            // never cut an IRQ, DVD callback or the guest audio mixer here.
            if(budget && cpu->timebase>=budget->deadline && (cpu->msr&0x8000u) && !cpu->exception &&
               !hle_callbacks_busy() && !scheduler_idle(cpu) && mem_read32(cpu,0x800000E4u)!=0x80667F08u &&
               guest_frame_finish_rendered(budget,cpu->timebase,gx_pipe_get_submitted_display_copies()))break;
            // Hardware/callbacks can wake the scheduler; observe idle only after delivery.
            if(budget && scheduler_idle(cpu) && !hle_callbacks_busy()){
                gx_pipe_process_frame(cpu);audio_tick(cpu);dvd_vfs_pump(cpu);video_poll_interrupt(cpu);hle_callbacks_pump(cpu);
                if(scheduler_idle(cpu) && !hle_callbacks_busy()){
                    if(guest_frame_finish_idle(budget,cpu->timebase,gx_pipe_get_submitted_display_copies(),scheduler_waiting_retrace(cpu)))break;
                    u64 event=video_next_event(cpu,budget->deadline);
                    if(dvd_vfs_pending_reads() && cpu->timebase+864<event)event=cpu->timebase+864;
                    cpu->timebase=guest_frame_idle_target(budget,cpu->timebase,event);force_devices=true;continue;
                }
            }else if(!budget && cpu->pc==0x802C7A44u){
                u32 run_bits=cpu->gpr[13]>=GC_RAM_BASE ? mem_read32(cpu,cpu->gpr[13]-25512):0;
                if(!run_bits){
                    u32 skip=127-(slice&127u);if(slice+skip>=GUEST_FRAME_BASE_SLICES)skip=GUEST_FRAME_BASE_SLICES-1-slice;
                    cpu->timebase+=(slice+skip+1)*27u/4u-(slice+1)*27u/4u;slice+=skip;continue;
                }
            }
            // Thread yield / sleep unblock: if stuck waiting on OSSleepThread with MSR=0
            if (cpu->pc == 0x802C7874u || cpu->pc == 0x8022BD44u) {
                u32 cur_th = mem_read32(cpu, 0x800000E4u);
                u32 def_th = mem_read32(cpu, 0x800000DCu);
                if (cur_th != def_th && def_th >= GC_RAM_BASE) {
                    save_thread_context(cpu, cur_th);
                    restore_thread_context(cpu, def_th);
                } else {
                    cpu->msr |= 0x8000u;
                }
            }
            if (cpu->pc >= 0x801CDFE4u && cpu->pc <= 0x801CE058u) {
                u32 node = (cpu->gpr[1] >= GC_RAM_BASE) ? mem_read32(cpu, cpu->gpr[1] + 8) : 0;
                if (node == 0 || node < GC_RAM_BASE || node == cpu->gpr[23]) {
                    cpu->pc = 0x801CE05Cu;
                }
            }
            if (cpu->pc == 0x80212490u || cpu->pc == 0x80212494u) {
                u32 ev340 = cpu->gpr[30];
                if (ev340 == 0xFFFFFFFFu) {
                    cpu->pc = 0x802124D0u;
                }
            }
            if (cpu->pc == 0x802DCED8u) {
                static int s_retrace_count = 0;
                if (s_retrace_count < 5) {
                    s_retrace_count++;
                    printf("[VIRetraceHandler ENTER #%d] r1=0x%08X r13=0x%08X\n", s_retrace_count, cpu->gpr[1], cpu->gpr[13]);
                    fflush(stdout);
                }
            }
            if (cpu->pc == 0x802C397Cu) {
                static int s_discard_count = 0;
                if (s_discard_count < 5) {
                    s_discard_count++;
                    printf("[INT DISCARD #%d] r4=0x%08X r31=0x%08X\n", s_discard_count, cpu->gpr[4], cpu->gpr[31]);
                    fflush(stdout);
                }
            }

            diagnose_lua_error(cpu);
            job->active_blocks++;if(budget)budget->dispatches++;
            u32 prev_pc = cpu->pc;
            bool sample_cpu=false;u64 sample_start=0;
            if(job->profile_cpu) {job->profile_random=job->profile_random*1664525u+1013904223u;sample_cpu=(job->profile_random>>26)==0;}
            if(sample_cpu)sample_start=SDL_GetPerformanceCounter();
            DispatchContinuation continuation={job,&slice,job_limit,next_event,&force_devices};
            if(budget){s_dispatch_context=&continuation;s_dispatch_continue=dispatch_continue;}
            int executed=platform_execute_cpu_slice(cpu);
            s_dispatch_continue=NULL;s_dispatch_context=NULL;
            if(sample_cpu && prev_pc>=GC_RAM_BASE && prev_pc-GC_RAM_BASE<0x300000u) {
                CPUProfileEntry* sample=&s_cpu_profile[(prev_pc-GC_RAM_BASE)/4];
                sample->ticks+=SDL_GetPerformanceCounter()-sample_start;sample->samples++;
            }
            if (!executed) {
                if (handle_guest_exception(cpu)) { job->total_blocks++; continue; }
                static u32 s_unmapped_cnt = 0;
                if (s_unmapped_cnt++ < 25) {
                    printf("[UNMAPPED #%u] PC=0x%08X (prev_pc=0x%08X, LR=0x%08X SP=0x%08X)\n",
                           s_unmapped_cnt, cpu->pc, prev_pc, cpu->lr, cpu->gpr[1]);
                    fflush(stdout);
                }
                if (cpu->lr >= GC_RAM_BASE && cpu->lr < (GC_RAM_BASE + cpu->ram_size) && cpu->lr != cpu->pc) {
                    cpu->pc = cpu->lr;
                    job->total_blocks++;
                    continue;
                }
                u32 stack_lr = (cpu->gpr[1] >= GC_RAM_BASE && (cpu->gpr[1] - GC_RAM_BASE + 8) <= cpu->ram_size) ?
                               mem_read32(cpu, cpu->gpr[1] + 4) : 0;
                if (stack_lr >= GC_RAM_BASE && stack_lr < (GC_RAM_BASE + cpu->ram_size) && stack_lr != cpu->pc) {
                    cpu->pc = stack_lr;
                    job->total_blocks++;
                    continue;
                }
                // Advance past invalid instruction instead of breaking and closing/freezing
                cpu->pc = (prev_pc >= GC_RAM_BASE) ? (prev_pc + 4) : (cpu->pc + 4);
                job->total_blocks++;
                continue;
            }
            job->total_blocks++;
        }

        if(budget && !budget->finished && !cancelled)guest_frame_watchdog(budget);
        job->cpu_ticks+=SDL_GetPerformanceCounter()-cpu_start;
        frame_timing_leave(game_stage);
    input_bind_frame(NULL);
}

int main(int argc, char** argv) {
#ifdef _WIN32
    SetUnhandledExceptionFilter(log_host_exception);
#endif
    if (argc == 2 && strcmp(argv[1], "--self-test") == 0) return platform_self_test();
    if(argc>=3 && argc<=5 && !strcmp(argv[1],"--gx-validate-decode"))return gx_pipe_validate_decode(argv[2],argc>=4 && !strcmp(argv[3],"scalar"),argc==5 ? (u32)strtoul(argv[4],NULL,10):0);
    if ((argc==4 || argc==5) && strcmp(argv[1],"--gx-replay")==0) return gx_pipe_replay(argv[2],argv[3],argc==5 && strcmp(argv[4],"software")==0);
    if (argc==3 && strcmp(argv[1],"--lua-probe")==0) return platform_lua_probe(argv[2]);
    if (argc==7 && strcmp(argv[1],"--guest-call")==0) return platform_guest_call(argv[2],(u32)strtoul(argv[3],NULL,0),(u32)strtoul(argv[4],NULL,0),(u32)strtoul(argv[5],NULL,0),(u32)strtoul(argv[6],NULL,0));
    bool portable_mode=false;
    char selected_disc[LAUNCHER_PATH_MAX]={0};
    for(int i=1;i<argc;i++)if(!strcmp(argv[i],"--portable"))portable_mode=true;
#ifdef _WIN32
    if(portable_mode){
        int count=0;LPWSTR* args=CommandLineToArgvW(GetCommandLineW(),&count);
        if(!args)return 1;
        for(int i=1;i+1<count;i++)if(!wcscmp(args[i],L"--disc"))WideCharToMultiByte(CP_UTF8,0,args[++i],-1,selected_disc,sizeof(selected_disc),NULL,NULL);
        LocalFree(args);
        char base[LAUNCHER_PATH_MAX];wchar_t root[LAUNCHER_PATH_MAX];
        if(!portable_executable_root(base,sizeof(base))||!MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,base,-1,root,LAUNCHER_PATH_MAX)||!SetCurrentDirectoryW(root))return 1;
    }
#endif
    LauncherConfig launch_config;char config_error[256];
    if(!launcher_config_load("config/launcher_config.json",&launch_config,config_error,sizeof(config_error))){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Launcher configuration",config_error,NULL);return 1;
    }
    input_configure(&launch_config);
    card_store_init("saves");card_hle_reset();
    const char* tuning_path=portable_mode?"config/runtime_tuning.cfg":"build_test/runtime_tuning.cfg";
    const char* chain_path=portable_mode?"config/dispatch_chain.cfg":"build_test/dispatch_chain.cfg";
    if(portable_mode){
        char error[256];DiscImage* disc=disc_image_open(selected_disc,error,sizeof(error));
        bool valid=disc&&disc_image_validate_game(disc,error,sizeof(error));disc_image_close(disc);
        if(!valid){SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Game image",error,NULL);return 1;}
    }
    static char stdout_buffer[65536];
    setvbuf(stdout,stdout_buffer,_IOFBF,sizeof(stdout_buffer));
    printf("[Frame timing] QPC exclusive wall ms; game includes dispatcher/HLE outside GX; EFB includes XFB. 60-frame windows. Release PGO USE is not collection.\n");
    // Initialize SDL2
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) != 0) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao inicializar SDL2: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, NULL);
        return 1;
    }

    static const struct { int w, h; } s_window_res_table[] = {
        {640, 480}, {1280, 720}, {1366, 768}, {1600, 900}, {1920, 1080}, {2560, 1440}, {3840, 2160}
    };
    static const float s_internal_res_table[] = { 1.0f, 1.5f, 2.0f, 3.0f, 4.0f };
    int win_w = 1280, win_h = 720;
    if(launch_config.window_resolution >= 0 && launch_config.window_resolution < (int)(sizeof(s_window_res_table)/sizeof(s_window_res_table[0]))){
        win_w = s_window_res_table[launch_config.window_resolution].w;
        win_h = s_window_res_table[launch_config.window_resolution].h;
    }
    float efb_scale = 1.0f;
    if(launch_config.internal_resolution >= 0 && launch_config.internal_resolution < (int)(sizeof(s_internal_res_table)/sizeof(s_internal_res_table[0]))){
        efb_scale = s_internal_res_table[launch_config.internal_resolution];
    }
    int aspect_ratio = 0;
    if(launch_config.aspect_ratio >= 0 && launch_config.aspect_ratio <= 1){
        aspect_ratio = launch_config.aspect_ratio;
    }
    for(int i=1;i<argc;i++){
        if(!strcmp(argv[i],"--window-res") && i+1<argc){
            int idx = atoi(argv[++i]);
            if(idx >= 0 && idx < 7){ win_w = s_window_res_table[idx].w; win_h = s_window_res_table[idx].h; }
        }
        if(!strcmp(argv[i],"--internal-scale") && i+1<argc){
            efb_scale = (float)atof(argv[++i]);
        }
        if(!strcmp(argv[i],"--aspect-ratio") && i+1<argc){
            aspect_ratio = atoi(argv[++i]);
            if(aspect_ratio < 0 || aspect_ratio > 1) aspect_ratio = 0;
        }
    }
    gx_pipe_set_internal_scale(efb_scale);
    gx_pipe_set_aspect_ratio(aspect_ratio);
    s_aspect_ratio = aspect_ratio;
    printf("[Video Configuration] Window: %dx%d, Internal EFB scale: %.2fx (%dx%d), Aspect Ratio: %s\n",
           win_w, win_h, efb_scale, (int)(640.0f * efb_scale + 0.5f), (int)(528.0f * efb_scale + 0.5f),
           aspect_ratio == 1 ? "16:9 Widescreen" : "4:3 Standard");

    SDL_Window* window = SDL_CreateWindow(
        "Digimon Rumble Arena 2 - PC Port (Native Recompilation)",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        win_w, win_h,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao criar janela SDL2: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, NULL);
        SDL_Quit();
        return 1;
    }

    DisplayModeState display_mode;
    display_mode_init(&display_mode,launch_config.window_mode);
    if(!display_mode_apply(window,&display_mode,launch_config.window_mode)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"Modo de tela",SDL_GetError(),window);
        display_mode_apply(window,&display_mode,DISPLAY_WINDOWED);
    }
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    if (!renderer) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao criar renderer: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, window);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_RendererInfo renderer_info;
    if (SDL_GetRendererInfo(renderer, &renderer_info) == 0) printf("[Renderer] %s\n", renderer_info.name);
    int requested_vsync=launch_config.vsync ? 1 : 0;
    int vsync_result=SDL_RenderSetVSync(renderer,requested_vsync);
    int swap_result=SDL_GL_SetSwapInterval(requested_vsync);
    printf("[Pacer] requested_vsync=%d renderer_result=%d gl_swap_result=%d swap_interval=%d (guest cadence unchanged)\n",
           requested_vsync,vsync_result,swap_result,SDL_GL_GetSwapInterval());
    s_main_window = window;
    s_main_renderer = renderer;

    // Initialize Video Blitter & Audio Driver
    video_audio_init(renderer);

    // Initialize Gamepad & Keyboard Input Driver
    input_init();

    // Initialize CPU and Memory
    CPUState cpu;
#ifdef _WIN32
    s_crash_cpu = &cpu;
#endif
    memset(&cpu, 0, sizeof(cpu));

    if (!cpu_init(&cpu)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", "Falha ao alocar RAM do GameCube!", window);
        video_audio_shutdown();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize GX GPU Pipeline (Command Processor & Gather Pipe)
    gx_pipe_init(&cpu);
    gx_pipe_set_renderer(renderer);
    gx_pipe_set_xfb_vram(&cpu, true);

    cpu.instruction_fallback = handle_instruction_fallback;
    cpu.spr_read=platform_spr_read;cpu.spr_write=platform_spr_write;
    locked_cache_reset();
    cpu.external_read = handle_external_read;
    cpu.external_write = handle_external_write;
    cpu.external_pointer = handle_external_pointer;

    // Developer DOL+disc arguments remain supported; portable builds boot from the user's disc.
    char ciso_path[LAUNCHER_PATH_MAX]={0};
    if(portable_mode)snprintf(ciso_path,sizeof(ciso_path),"%s",selected_disc);
    else if(argc>2)snprintf(ciso_path,sizeof(ciso_path),"%s",argv[2]);
    bool disc_ready=false;
    if(portable_mode||argc>2||find_existing_file("Digimon Rumble Arena 2 (USA).ciso",ciso_path,sizeof(ciso_path)))
        disc_ready=dvd_vfs_init(ciso_path,&cpu)&&dvd_vfs_read_bytes(0,cpu.ram,0x440);
    char dol_path[LAUNCHER_PATH_MAX]={0};DolMetadata meta;bool loaded=false;
    if(portable_mode&&disc_ready){
        char error[256];DiscImage* disc=disc_image_open(ciso_path,error,sizeof(error));void* data=NULL;size_t size=0;
        if(disc&&disc_image_dol(disc,&data,&size))loaded=dol_load_memory(data,size,&cpu,&meta);
        free(data);disc_image_close(disc);
    }else if(!portable_mode){
        if(argc>1)snprintf(dol_path,sizeof(dol_path),"%s",argv[1]);
        if(argc>1||find_existing_file("extracted/sys/main.dol",dol_path,sizeof(dol_path)))loaded=dol_load(dol_path,&cpu,&meta);
    }
    if(!loaded||(portable_mode&&!disc_ready)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Digimon Recomp","Falha ao carregar DOL/disco. Verifique o dump original no Launcher.",window);
        gx_pipe_shutdown();video_audio_shutdown();cpu_free(&cpu);dvd_vfs_shutdown();card_store_shutdown();
        SDL_DestroyRenderer(renderer);SDL_DestroyWindow(window);SDL_Quit();return 1;
    }

    // Load FST into RAM at 0x80400000 (safely above CRT0 boot stack at 0x803D54E0)
    dvd_vfs_load_fst(&cpu, 0x80400000);

    printf("[DOL Loader] _ctors table at 0x803591E0:\n");
    for (u32 a = 0x803591E0; a <= 0x80359200; a += 4) {
        printf("  [0x%08X] = 0x%08X\n", a, mem_read32(&cpu, a));
    }

    bool running = true;
    SDL_Event event;
    u64 total_blocks = 0;
    u32 frame_count = 0;
    Uint32 start_time = SDL_GetTicks();
    u64 cpu_ticks=0,previous_render_ticks=0,previous_copy_ticks=0;
    u64 pump_ticks=0;u32 pump_calls=0;
    u64 pacing_frequency=SDL_GetPerformanceFrequency(),next_frame_deadline=SDL_GetPerformanceCounter();
    u64 previous_display_copies=0,previous_ax_lists=0,active_blocks=0;
    u64 previous_vertex_hits=0,previous_vertex_misses=0;
    u64 previous_decode_ticks=0,previous_texture_copy_ticks=0;
    bool trace_runtime=getenv("RUNTIME_TRACE")!=NULL;
    bool profile_cpu=getenv("CPU_PROFILE")!=NULL;
    u32 profile_random=1;u64 profile_deadline=next_frame_deadline+pacing_frequency*5u;

    GuestFrameBudget guest_budget={0};
    bool xfb_vram_requested=true,fast_float_requested=true,frame_pipeline_requested=true;
    while (running) {
        frame_timing_begin();
        g_fast_float_enabled=fast_float_requested && s_scene_address && mem_read32(&cpu,s_scene_address+8)==4;
        bool in_combat=s_scene_address && mem_read32(&cpu,s_scene_address+8)==4;
        bool continuing=guest_budget.open;
        bool managed_frame=in_combat || continuing;
        if(gx_frame_active() && (!in_combat || !frame_pipeline_requested)){if(!gx_pipe_frame_stop(&cpu)){running=false;break;}}
        gx_pipe_set_xfb_vram(&cpu,xfb_vram_requested);
        if(in_combat && frame_pipeline_requested && !gx_frame_active())gx_pipe_frame_start(&cpu,window);
        if(!continuing){s_total_frames++;s_current_frame_num++;}


        // Auto-exit de teste removido para garantir que a janela fique aberta continuamente

        // Poll OS events
        while (SDL_PollEvent(&event)) {
            if(display_mode_event(window,&display_mode,&event)){input_suppress_enter();continue;}
            if (event.type == SDL_QUIT) {
                printf("[Exit] SDL_QUIT received\n");
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    printf("[Exit] physical Escape received\n");
                    running = false;
                }
            }
            input_handle_event(&event);
        }
        input_poll();

        // 1-line debug log requested by user when any button is pressed:
        const NativePadState* p0 = input_get_pad(0);
        static u16 s_last_logged_button = 0;
        if (p0->button != 0 && p0->button != s_last_logged_button) {
            printf("[INPUT] Botao pressionado! Mask=0x%04X\n", p0->button);
            fflush(stdout);
        }
        s_last_logged_button = p0->button;

        // Trigger 60Hz VBLANK (VI Retrace)
        if(!continuing)video_trigger_vblank(&cpu);
        if(managed_frame && !continuing)guest_frame_begin(&guest_budget,cpu.timebase,gx_pipe_get_submitted_display_copies());

        // Audio thread (0x80667F08) and DefThread (0x803B3050) scheduling synchronization:
        u32 cur_thread = mem_read32(&cpu, 0x800000E4u);
        u32 def_thread = mem_read32(&cpu, 0x800000DCu);
        if (!continuing && cur_thread == 0x80667F08u) {
            u32 th_queue = mem_read32(&cpu, 0x80667F08u + 0x2DC);
            u16 th_state = mem_read16(&cpu, 0x80667F08u + 0x2C8);
            if (th_queue == 0x8035C3E0u || th_state == 4 || th_state == 1) {
                if (def_thread >= GC_RAM_BASE) {
                    save_thread_context(&cpu, cur_thread);
                    restore_thread_context(&cpu, def_thread);
                }
            }
        }

        CPUFrameJob job={0};job.cpu=&cpu;job.total_blocks=total_blocks;job.active_blocks=active_blocks;job.cpu_ticks=cpu_ticks;
        job.pump_ticks=pump_ticks;job.pump_calls=pump_calls;job.profile_random=profile_random;job.profile_cpu=profile_cpu;job.pacing_frequency=pacing_frequency;
        for(u32 pad=0;pad<4;pad++)job.pads[pad]=*input_get_pad((int)pad);
        job.threaded=gx_frame_active();job.budget=managed_frame ? &guest_budget:NULL;
        if(job.threaded){
            if(!gx_frame_begin_cpu_frame()){fprintf(stderr,"[CPU frame] backend rejected frame credit\n");running=false;break;}
            if(!cpu_frame_start(run_guest_frame) || !cpu_frame_submit(&job)){fprintf(stderr,"[CPU frame] cannot start CPU worker\n");running=false;break;}
            bool timing_before=frame_timing_worker(true);
            while(!cpu_frame_done()){
                gx_frame_pump(true);
                while(SDL_PollEvent(&event)){
                    if(display_mode_event(window,&display_mode,&event)){input_suppress_enter();continue;}
                    if(event.type==SDL_QUIT || (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE)){running=false;cpu_frame_cancel();}
                    input_handle_event(&event);
                }
            }
            frame_timing_worker(timing_before);
        }else run_guest_frame(&job);
        total_blocks=job.total_blocks;active_blocks=job.active_blocks;cpu_ticks=job.cpu_ticks;pump_ticks=job.pump_ticks;pump_calls=job.pump_calls;profile_random=job.profile_random;
        // Read-only diagnostics for the loading stall reported near VS.
        static u32 stall_draws,stall_frames;
        u32 observed_draws=gx_pipe_get_draw_calls();
        if (observed_draws==stall_draws) stall_frames++; else {stall_draws=observed_draws;stall_frames=0;}
        if (stall_frames && stall_frames%300==0 && cpu.pc>=0x80296A50u && cpu.pc<0x80296BA4u) {
            printf("[Guest stall] frames=%u PC=%08X LR=%08X r28=%08X r31=%08X\n",stall_frames,cpu.pc,cpu.lr,cpu.gpr[28],cpu.gpr[31]);
            u32 sp=cpu.gpr[1];
            for (u32 i=0;i<12 && sp>=GC_RAM_BASE && sp-GC_RAM_BASE<=cpu.ram_size-8;i++) {
                u32 next=mem_read32(&cpu,sp),lr=mem_read32(&cpu,sp+4);
                printf("[Guest stack] SP=%08X LR=%08X\n",sp,lr);if(next<=sp)break;sp=next;
            }
            for (u32 reg=3;reg<=31;reg++) if (reg==3 || reg==4 || reg==28 || reg==31) {
                u32 at=cpu.gpr[reg];
                if(at>=GC_RAM_BASE && at-GC_RAM_BASE<cpu.ram_size) {
                    char value[129]={0};u32 available=cpu.ram_size-(at-GC_RAM_BASE);if(available>128)available=128;
                    memcpy(value,cpu.ram+at-GC_RAM_BASE,available);printf("[Guest string r%u] %.128s\n",reg,value);
                }
            }
        }

        // Process GPU FIFO commands
        gx_pipe_process_frame(&cpu);

        static u32 s_ana_count = 0;
        if (trace_runtime && (s_ana_count++ < 3 || (s_ana_count % 60 == 0))) {
            u32 non_zero = 0;
            u32 target_fb = video_get_xfb_addr();
            if (target_fb >= GC_RAM_BASE && (target_fb - GC_RAM_BASE + 640*480*2) <= cpu.ram_size) {
                u8* p = cpu.ram + (target_fb - GC_RAM_BASE);
                for (int i = 0; i < 640*480*2; i++) {
                    if (p[i] != 0) non_zero++;
                }
                printf("[XFB Analysis #%u] Buffer 0x%08X: %u bytes nao-zero de %u (amostra: %02X %02X %02X %02X)\n",
                       s_ana_count, target_fb, non_zero, 640*480*2, p[0], p[1], p[2], p[3]);
                fflush(stdout);
            }
        }

        if (trace_runtime && frame_count <= 5) {
            printf("[DEBUG] Frame %u: PC=0x%08X LR=0x%08X msr=0x%08X ctx=0x%08X\n",
                   frame_count, cpu.pc, cpu.lr, cpu.msr, mem_read32(&cpu, 0x800000D4u));
            fflush(stdout);
        }

        bool guest_completed=!managed_frame || guest_budget.finished;
        if(guest_completed)frame_count++;

        int w=1280,h=720;
        if(!guest_completed){/* Keep last presented XFB; resume without an extra VI. */}
        else if(gx_frame_active()){
            if(!gx_pipe_frame_present(&cpu)){fprintf(stderr,"[GX frame] backend error; stopping without continuing corrupted state\n");running=false;break;}
        }else{
        // Clear screen with pure black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        // Use RenderGetOutputSize (physical pixels) — SDL_GetWindowSize returns
        // logical DPI-scaled pixels which can be wrong on high-DPI Windows systems.
        SDL_GetRendererOutputSize(renderer, &w, &h);
        // Sanity fallback: if SDL returns nonsense (e.g. h=44 due to DPI virtualization),
        // fall back to the window's requested size.
        if (w < 320 || h < 240) {
            SDL_GetWindowSize(window, &w, &h);
        }
        if (w < 320) w = 1280;
        if (h < 240) h = 720;
        FrameStage present_stage=frame_timing_enter(FRAME_GL_SUBMIT);
        video_present_frame(renderer, &cpu, w, h);
        frame_timing_leave(present_stage);

        }
        static u64 s_last_fifo_bytes = 0;
        static u32 s_last_draws = 0;
        u64 cur_fifo_bytes = gx_pipe_get_total_bytes();
        u32 cur_draws = gx_pipe_get_draw_calls();
        if (trace_runtime && (cur_fifo_bytes != s_last_fifo_bytes || cur_draws != s_last_draws)) {
            printf("[FIFO Activity Frame %u] Total Bytes=%llu (+%llu), Draws=%u (+%u)\n",
                   frame_count, cur_fifo_bytes, cur_fifo_bytes - s_last_fifo_bytes,
                   cur_draws, cur_draws - s_last_draws);
            fflush(stdout);
            s_last_fifo_bytes = cur_fifo_bytes;
            s_last_draws = cur_draws;
        }

        static int s_sshot_taken = 0;
        s_sshot_taken++;
        if (trace_runtime && (s_sshot_taken == 30 || s_sshot_taken == 60 || s_sshot_taken == 100 || s_sshot_taken == 150 || s_sshot_taken == 200 || s_sshot_taken == 220 || s_sshot_taken == 240 || s_sshot_taken == 260 || s_sshot_taken == 280 || s_sshot_taken == 300 || s_sshot_taken == 400 || s_sshot_taken == 500 || s_sshot_taken == 600)) {
            SDL_Surface* sshot = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
            if (sshot) {
                SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA32, sshot->pixels, sshot->pitch);
                u32 non_black = 0;
                u32* px = (u32*)sshot->pixels;
                int total_px = w * h;
                for (int i = 0; i < total_px; i++) {
                    if ((px[i] & 0x00FFFFFF) != 0) non_black++;
                }
                char sshot_name[64];
                snprintf(sshot_name, sizeof(sshot_name), "frame_capture_%d.bmp", s_sshot_taken);
                SDL_SaveBMP(sshot, sshot_name);
                SDL_SaveBMP(sshot, "frame_capture.bmp");
                SDL_FreeSurface(sshot);
                printf("[Capture] Frame %d capturado (%u non-black pixels) e salvo em %s e frame_capture.bmp!\n",
                       s_sshot_taken, non_black, sshot_name);
                fflush(stdout);
            }
        }

        FrameStage swap_stage=frame_timing_enter(FRAME_SWAP);
        if(!gx_frame_active() && guest_completed)SDL_RenderPresent(renderer);
        frame_timing_leave(swap_stage);
        if(profile_cpu && SDL_GetPerformanceCounter()>=profile_deadline) {
            dump_cpu_profile(pacing_frequency);profile_deadline=SDL_GetPerformanceCounter()+pacing_frequency*5u;
        }

        // One host pacing source: no swap-interval wait plus a second frame cap.
        FrameStage pacing_stage=frame_timing_enter(FRAME_PACING);
        u64 now=SDL_GetPerformanceCounter();
        // A watchdog yield is a continuation of this VI, never a host frame.
        // Don't charge it an extra 16.67ms before resuming unfinished work.
        if(guest_completed)next_frame_deadline=frame_pacer_target(next_frame_deadline,now,pacing_frequency);
        else next_frame_deadline=now;
        while(now<next_frame_deadline) {
            u32 remaining=(u32)((next_frame_deadline-now)*1000u/pacing_frequency);
            SDL_Delay(remaining>1 ? remaining-1 : 0);
            now=SDL_GetPerformanceCounter();
        }

        frame_timing_leave(pacing_stage);

        // Update window title with FPS and executed blocks every second
        Uint32 current_time = SDL_GetTicks();
        if (current_time - start_time >= 1000) {
            FILE* chain_config=fopen(chain_path,"r");
            if(chain_config){int enabled;if(fscanf(chain_config,"%d",&enabled)==1 && (enabled==0 || enabled==1))s_chain_requested=enabled!=0;fclose(chain_config);}
            // Host-only live diagnostics: change scheduling/worker cost while
            // the user's actual four-player selection stays intact. No PAD or
            // guest-state writes. All GX workers have completed at this point.
            int completion=0,pump=0,domain=1,m44=1,attrs=1,fbits=0,gpu_xf=1,vram_only=1,geometry_cache=1,xfb_vram=1,decode_cache=1,fast_float=1,dirty_tracking=0,async_decode=0,image_versions=0,frame_pipeline=1;
            FILE* tuning=fopen(tuning_path,"r");
            if(tuning) {
                u32 quantum;int parallel,packed=1,skinning=1,ram_inline=0,blocks_enabled=1;
                if(fscanf(tuning,"%u %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&quantum,&parallel,&packed,&skinning,&ram_inline,&blocks_enabled,&completion,&pump,&domain,&m44,&attrs,&fbits,&gpu_xf,&vram_only,&geometry_cache,&xfb_vram,&decode_cache,&fast_float,&dirty_tracking,&async_decode,&image_versions,&frame_pipeline)>=2 && quantum>=64 && quantum<=4096 &&
                   (parallel==0 || parallel==1) && (packed==0 || packed==1) && (skinning==0 || skinning==1) && (ram_inline==0 || ram_inline==1) && (blocks_enabled==0 || blocks_enabled==1) && (completion==0 || completion==1) && (pump==0 || pump==1) && (domain==0 || domain==1) && (m44==0 || m44==1) && (attrs==0 || attrs==1) && (fbits==0 || fbits==1) && (gpu_xf==0 || gpu_xf==1) && (vram_only==0 || vram_only==1) && (geometry_cache==0 || geometry_cache==1) && (xfb_vram==0 || xfb_vram==1) && (decode_cache==0 || decode_cache==1) && (fast_float==0 || fast_float==1) && (dirty_tracking==0 || dirty_tracking==1) && (async_decode==0 || async_decode==1) && (image_versions==0 || image_versions==1) && (frame_pipeline==0 || frame_pipeline==1)) {
                    static int prior_config[22];
                    int config[22]={(int)quantum,parallel,packed,skinning,ram_inline,blocks_enabled,completion,pump,domain,m44,attrs,fbits,gpu_xf,vram_only,geometry_cache,xfb_vram,decode_cache,fast_float,dirty_tracking,async_decode,image_versions,frame_pipeline};
                    if(memcmp(prior_config,config,sizeof(config))){
                        if(gx_frame_active())gx_pipe_frame_stop(&cpu);
                        memcpy(prior_config,config,sizeof(config));frame_pipeline_requested=frame_pipeline!=0;
                    platform_set_cpu_quantum(quantum);gx_pipe_set_parallel_vertices(parallel!=0);
                    gx_pipe_set_packed_copy(packed!=0);paired_skinning_set_enabled(skinning!=0);
                    g_native_ram_inline_enabled=ram_inline!=0;
                    g_native_blocks_enabled=blocks_enabled!=0;
                    gx_pipe_set_coalesced_completion(completion!=0);
                    s_paced_event_pump=pump!=0;
                    paired_skinning_set_wide_domain(domain!=0);
                    sdk_mtx44_set_enabled(m44!=0);
                    gx_pipe_set_direct_attributes(attrs!=0);
                    g_float_bits_enabled=g_float_bits_available && fbits!=0;
                    gx_pipe_set_gpu_xf(gpu_xf!=0);
                    gx_pipe_set_image_versions(&cpu,image_versions!=0);gx_pipe_set_async_decode(async_decode!=0);
                    fast_float_requested=fast_float!=0;gx_pipe_set_dirty_tracking(dirty_tracking!=0);
                    xfb_vram_requested=xfb_vram!=0;gx_pipe_set_xfb_vram(&cpu,xfb_vram_requested);gx_pipe_set_decode_cache(decode_cache!=0);
                    gx_pipe_set_vram_only(&cpu,vram_only!=0);gx_gl_set_geometry_cache(geometry_cache!=0);
                    }
                }
                fclose(tuning);
            }
            float fps = (float)frame_count * 1000.0f / (float)(current_time - start_time);
            char title[256];
            snprintf(title, sizeof(title),
                "Digimon Rumble Arena 2 - PC Port | %.1f FPS | Blocos: %llu | VBL: %u | INT: %u | GX: %.1f KB (%u draws) | PC: 0x%08X",
                fps, total_blocks, video_get_vblank_count(), video_get_interrupt_count(),
                (double)gx_pipe_get_total_bytes() / 1024.0, gx_pipe_get_draw_calls(), cpu.pc);
            SDL_SetWindowTitle(window, title);

            u32 curr_thread = mem_read32(&cpu, 0x800000E4u);
            u32 def_thread = mem_read32(&cpu, 0x800000DCu);
            u32 active_head = mem_read32(&cpu, 0x800000E0u);
            u32 alarm_head = mem_read32(&cpu, 0x800000ECu);
            u32 run_bits = (cpu.gpr[13] >= GC_RAM_BASE) ? mem_read32(&cpu, cpu.gpr[13] - 25512) : 0;
            printf("[Native top] floor=%llu matrix_copy_bytes=%llu vector_transforms=%llu\n",sdk_floor_calls(),native_copy_bytes(),sdk_vec_calls());
            u64 xfb_copies,xfb_resolves;gx_pipe_xfb_diagnostics(&xfb_copies,&xfb_resolves);
            printf("[XFB VRAM] requested=%d copies=%llu resolves=%llu\n",xfb_vram_requested,xfb_copies,xfb_resolves);
            u64 render_ticks,copy_ticks;gx_pipe_get_timing(&render_ticks,&copy_ticks);
            double milliseconds=1000.0/(double)SDL_GetPerformanceFrequency();
            printf("[Timing] CPU+GX=%.2f ms/frame render=%.2f readback+YUY2=%.2f\n",cpu_ticks*milliseconds/frame_count,(render_ticks-previous_render_ticks)*milliseconds/frame_count,(copy_ticks-previous_copy_ticks)*milliseconds/frame_count);
            u64 decode_ticks,texture_copy_ticks;gx_pipe_get_costs(&decode_ticks,&texture_copy_ticks);
            printf("[Host input] pump=%.3f ms/frame calls=%.2f/frame\n",pump_ticks*milliseconds/frame_count,(double)pump_calls/frame_count);
            pump_ticks=0;pump_calls=0;
            printf("[GX cost] vertices=%.2f ms/frame texture copy=%.2f parallel batches=%llu\n",(decode_ticks-previous_decode_ticks)*milliseconds/frame_count,(texture_copy_ticks-previous_texture_copy_ticks)*milliseconds/frame_count,gx_pipe_get_parallel_batches());
            previous_decode_ticks=decode_ticks;previous_texture_copy_ticks=texture_copy_ticks;
            u64 display_copies=gx_pipe_get_display_copies(),ax_lists=ax_hle_stats()->lists;
            double seconds=(current_time-start_time)/1000.0;
            printf("[Progress] XFB copies=%.1f/s AX lists=%.1f/s active dispatches=%.0f/frame quantum=%u\n",
                   (display_copies-previous_display_copies)/seconds,(ax_lists-previous_ax_lists)/seconds,(double)active_blocks/frame_count,s_cpu_quantum);
            previous_display_copies=display_copies;previous_ax_lists=ax_lists;active_blocks=0;
            printf("[Skinning] native loop vertices=%llu accumulate=%llu envmap=%llu transform=%llu env_batches=%llu blend=%llu block_entries=%llu\n",paired_skinning_vertices(),paired_skinning_accumulated(),paired_skinning_environment_vertices(),paired_skinning_transformed(),paired_skinning_environment_batches(),paired_skinning_blended(),platform_native_block_entries());
            printf("[Native RAM] inline=%u blocks=%u completion=%u pump=%u domain=%u m44=%u attrs=%u fbits=%u gpu_xf=%u vram_only=%u geometry_cache=%u\n",g_native_ram_inline_enabled,g_native_blocks_enabled,gx_pipe_coalesced_completion(),s_paced_event_pump,paired_skinning_wide_domain(),sdk_mtx44_enabled(),gx_pipe_direct_attributes(),g_float_bits_enabled,gx_pipe_gpu_xf(),gx_pipe_vram_only(),gx_gl_geometry_cache());
            printf("[SDK matrices] concat44=%llu gpu_xf_batches=%llu\n",sdk_mtx44_calls(),gx_pipe_gpu_xf_batches());
            u64 texture_hits,texture_hashed,texture_readbacks;gx_pipe_texture_diagnostics(&texture_hits,&texture_hashed,&texture_readbacks);
            printf("[Texture cache] hits=%llu hash_bytes=%llu uploads=%llu EFB_readbacks=%llu\n",texture_hits,texture_hashed,gx_pipe_get_texture_uploads(),texture_readbacks);
            u64 vram_copies,vram_resolves;u32 vram_pending;gx_pipe_vram_diagnostics(&vram_copies,&vram_resolves,&vram_pending);
            GXGLStats graphics;gx_pipe_frame_gl_stats(&graphics);
            printf("[GL driver] draws=%llu stream_bytes=%llu orphans=%llu shader_compiles=%llu uniform_queries=%llu vram_copies=%llu geometry_hits=%llu geometry_uploads=%llu xf_uniform_blocks=%llu merged_packets=%llu geometry_hashes=%llu dynamic_streams=%llu vram_only_copies=%llu vram_materializations=%llu VRAM_pending=%u DVD_pending=%u\n",
                graphics.draws,graphics.stream_bytes,graphics.orphans,graphics.shader_compiles,graphics.uniform_lookups,graphics.vram_copies,graphics.geometry_hits,graphics.geometry_uploads,graphics.xf_uniform_blocks,gx_pipe_merged_packets(),graphics.geometry_hashes,graphics.dynamic_streams,vram_copies,vram_resolves,vram_pending,dvd_vfs_pending_reads());
            u64 vertex_hits,vertex_misses;gx_pipe_get_vertex_cache_stats(&vertex_hits,&vertex_misses);
            u64 dh=vertex_hits-previous_vertex_hits,dm=vertex_misses-previous_vertex_misses;
            printf("[Vertex cache] hits=%llu misses=%llu reuse=%.1f%%\n",dh,dm,dh+dm ? 100.0*dh/(dh+dm) : 0);
            previous_vertex_hits=vertex_hits;previous_vertex_misses=vertex_misses;
            cpu_ticks=0;previous_render_ticks=render_ticks;previous_copy_ticks=copy_ticks;
            printf("[Runtime Stats] %.1f FPS | Blocos: %llu | VBL: %u | INT: %u | GX: %.1f KB (%u draws) | XFB=0x%08X | PC: 0x%08X | RunBits: 0x%08X\n",
                   fps, total_blocks, video_get_vblank_count(), video_get_interrupt_count(),
                   (double)gx_pipe_get_total_bytes() / 1024.0, gx_pipe_get_draw_calls(),
                   video_get_xfb_addr(), cpu.pc, run_bits);
            printf("  [OS Threads Info] CurrThread=0x%08X DefThread=0x%08X ActiveHead=0x%08X AlarmHead=0x%08X (TimeBase=%llu)\n",
                   curr_thread, def_thread, active_head, alarm_head, cpu.timebase);

            // Iterate active thread list starting from active_head (or def_thread)
            u32 th = (active_head >= GC_RAM_BASE) ? active_head : def_thread;
            int th_count = 0;
            while (th >= GC_RAM_BASE && th < (GC_RAM_BASE + cpu.ram_size) && th_count < 8) {
                u16 state = mem_read16(&cpu, th + 0x2C8);
                u32 prio = mem_read32(&cpu, th + 0x2D0);
                u32 q = mem_read32(&cpu, th + 0x2DC);
                u32 pc = mem_read32(&cpu, th + 0x198);
                u32 lr = mem_read32(&cpu, th + 0x084);
                u32 sp = mem_read32(&cpu, th + 0x004);
                const char* state_str = (state == 1) ? "READY" : (state == 2) ? "RUNNING" : (state == 4) ? "WAITING" : (state == 8) ? "MORIBUND" : "UNKNOWN";
                printf("    Thread #%d [0x%08X]: state=%u(%s) prio=%u queue=0x%08X saved_pc=0x%08X saved_lr=0x%08X sp=0x%08X\n",
                       th_count++, th, state, state_str, prio, q, pc, lr, sp);
                th = mem_read32(&cpu, th + 0x2FC); // nextActive
            }

            if (alarm_head >= GC_RAM_BASE && alarm_head < (GC_RAM_BASE + cpu.ram_size)) {
                u32 a_handler = mem_read32(&cpu, alarm_head + 0x00);
                u32 a_fire_hi = mem_read32(&cpu, alarm_head + 0x08);
                u32 a_fire_lo = mem_read32(&cpu, alarm_head + 0x0C);
                u64 a_fire = ((u64)a_fire_hi << 32) | a_fire_lo;
                printf("  [OS Alarm] Head=0x%08X handler=0x%08X fire=%llu (diff=%lld)\n",
                       alarm_head, a_handler, a_fire, (s64)(a_fire - cpu.timebase));
            }
            printf("[Sync] PI=%08X mask=%08X PE=%04X drawDone=%u drawCb=%08X flip=%u pre=%08X post=%08X retraces=%u\n",
                   (u32)video_read_pi(&cpu,0,4), (u32)video_read_pi(&cpu,4,4), gx_pipe_read_pe(&cpu,0xA),
                   mem_read8(&cpu,cpu.gpr[13]-25320), mem_read32(&cpu,cpu.gpr[13]-25324),
                   mem_read32(&cpu,cpu.gpr[13]-29800), mem_read32(&cpu,cpu.gpr[13]-25180),
                   mem_read32(&cpu,cpu.gpr[13]-25176), mem_read32(&cpu,cpu.gpr[13]-25196));
            printf("[FIFO regs] ctrl=%04X base=%04X%04X end=%04X%04X read=%04X%04X write=%04X%04X distance=%04X%04X PIwrite=%08X scene=%u\n",
                   gx_pipe_read_cp(&cpu,2),gx_pipe_read_cp(&cpu,0x22),gx_pipe_read_cp(&cpu,0x20),
                   gx_pipe_read_cp(&cpu,0x26),gx_pipe_read_cp(&cpu,0x24),gx_pipe_read_cp(&cpu,0x3A),gx_pipe_read_cp(&cpu,0x38),
                   gx_pipe_read_cp(&cpu,0x36),gx_pipe_read_cp(&cpu,0x34),gx_pipe_read_cp(&cpu,0x32),gx_pipe_read_cp(&cpu,0x30),
                   gx_pipe_read_pi(0x14),s_scene_address ? mem_read32(&cpu,s_scene_address+8) : 0);
            fflush(stdout);
            frame_count = 0;
            start_time = current_time;
        }
        FrameTimingReport frame_report;
        if(frame_timing_end(&frame_report)) {
            static u64 prior_hosts,prior_calls,prior_links,prior_budget_stops,prior_fence_stops;
            printf("[Dispatch60] enabled=%u hosts=%llu calls=%llu links=%llu budget_stops=%llu fence_stops=%llu\n",s_chain_requested,
                s_dispatch_stats.hosts-prior_hosts,s_dispatch_stats.calls-prior_calls,s_dispatch_stats.links-prior_links,
                s_dispatch_stats.budget_stops-prior_budget_stops,s_dispatch_stats.fence_stops-prior_fence_stops);
            prior_hosts=s_dispatch_stats.hosts;prior_calls=s_dispatch_stats.calls;prior_links=s_dispatch_stats.links;
            prior_budget_stops=s_dispatch_stats.budget_stops;prior_fence_stops=s_dispatch_stats.fence_stops;
            static GuestFrameBudget prior_budget;
            printf("[Guest budget60] quota=%u quantum=%u completed=%llu submitted=%llu empty=%llu watchdog_jobs=%llu over_base=%llu idle_jumps=%llu idle_tb_skipped=%llu retrace_waits=%llu max_dispatches=%llu pending=%d\n",
                GUEST_FRAME_JOB_SLICES,s_cpu_quantum,guest_budget.completed-prior_budget.completed,guest_budget.submitted-prior_budget.submitted,
                guest_budget.empty-prior_budget.empty,guest_budget.watchdogs-prior_budget.watchdogs,guest_budget.over_base-prior_budget.over_base,
                guest_budget.idle_jumps-prior_budget.idle_jumps,guest_budget.idle_ticks-prior_budget.idle_ticks,guest_budget.retrace_waits-prior_budget.retrace_waits,
                guest_budget.max_dispatches,guest_budget.open);
            printf("[Guest boundary60] rendered_deadline=%llu\n",guest_budget.rendered_deadlines-prior_budget.rendered_deadlines);prior_budget=guest_budget;
            printf("[Guest dispatch60] dispatches=%llu peak_dispatches=%llu completed=%llu\n",guest_budget.window_dispatches,guest_budget.window_max_dispatches,
                guest_budget.window_completed);
            guest_budget.window_dispatches=guest_budget.window_max_dispatches=guest_budget.window_completed=0;

            u64 fifo_stores,fifo_lines,fifo_deferred,fifo_parses;
            gx_pipe_fifo_diagnostics(&fifo_stores,&fifo_lines,&fifo_deferred,&fifo_parses);
            printf("[FIFO60] stores=%llu lines=%llu incomplete_deferrals=%llu parser_calls=%llu\n",fifo_stores,fifo_lines,fifo_deferred,fifo_parses);
            static u64 previous_detail[8];u64 detail[8];GXGLStats stats;gx_pipe_frame_gl_stats(&stats);
            gx_pipe_decode_diagnostics(detail,detail+1,detail+2,detail+3,detail+4);
            detail[5]=stats.hash_ticks;detail[6]=stats.lookup_ticks;detail[7]=stats.repack_ticks;
            double scale=1000.0/SDL_GetPerformanceFrequency()/frame_report.frames;
            u64 watched,dirty_pages,spans,fallbacks;ppc_ram_watch_stats(&watched,&dirty_pages);gx_pipe_dirty_diagnostics(&spans,&fallbacks);
            printf("[Fast modes] fast_float=%d dirty_tracking=%d watch_queries=%llu dirty_pages=%llu tracked_spans=%llu hash_fallbacks=%llu\n",g_fast_float_enabled,gx_pipe_dirty_tracking(),watched,dirty_pages,spans,fallbacks);
            static u64 previous_keys[6];u64 keys[6];gx_pipe_key_details(keys);
            printf("[GX key60] page_query_ms=%.4f input_hash_ms=%.4f input_lookup_ms=%.4f ram_key_bytes=%.0f version_key_bytes=%.0f decode_miss_ms=%.4f\n",
                (keys[0]-previous_keys[0])*scale,(keys[1]-previous_keys[1])*scale,(keys[2]-previous_keys[2])*scale,
                (double)(keys[3]-previous_keys[3])/frame_report.frames,(double)(keys[4]-previous_keys[4])/frame_report.frames,
                (keys[5]-previous_keys[5])*scale);
            memcpy(previous_keys,keys,sizeof(keys));
            static u64 old_async[5];u64 asynchronous[5];
            gx_pipe_async_diagnostics(asynchronous,asynchronous+1,asynchronous+2,asynchronous+3,asynchronous+4);
            printf("[GX async60] async_jobs=%llu async_vertices=%llu async_worker_ms=%.4f async_wait_ms=%.4f async_snapshot_ms=%.4f\n",
                asynchronous[0]-old_async[0],asynchronous[1]-old_async[1],(asynchronous[2]-old_async[2])*scale,
                (asynchronous[3]-old_async[3])*scale,(asynchronous[4]-old_async[4])*scale);
            memcpy(old_async,asynchronous,sizeof(asynchronous));
            static u64 old_reuse[3];u64 reuse[4];gx_pipe_async_reuse(reuse,reuse+1,reuse+2,reuse+3);
            printf("[GX async reuse60] async_vertex_hits=%llu async_vertex_misses=%llu async_drains=%llu async_peak_pending=%llu\n",
                reuse[0]-old_reuse[0],reuse[1]-old_reuse[1],reuse[2]-old_reuse[2],reuse[3]);memcpy(old_reuse,reuse,sizeof(old_reuse));
            static u64 old_images[7];u64 image_stats[7];gx_pipe_image_diagnostics(image_stats);
            printf("[GX image60] async_enabled=%d immutable_images=%d image_cache_hits=%llu image_copy_bytes=%llu palette_cache_hits=%llu palette_copy_bytes=%llu tlut_deferred=%llu tlut_sync=%llu image_fallbacks=%llu\n",
                gx_pipe_async_decode(),gx_pipe_image_versions(),image_stats[0]-old_images[0],image_stats[1]-old_images[1],image_stats[2]-old_images[2],
                image_stats[3]-old_images[3],image_stats[4]-old_images[4],image_stats[5]-old_images[5],image_stats[6]-old_images[6]);
            memcpy(old_images,image_stats,sizeof(image_stats));
            printf("[GX60] decoded_hits=%llu decoded_misses=%llu key_ms=%.4f worker_wait_ms=%.4f vertex_main_ms=%.4f vbo_hash_ms=%.4f vbo_lookup_ms=%.4f vbo_repack_ms=%.4f\n",
                detail[0]-previous_detail[0],detail[1]-previous_detail[1],(detail[2]-previous_detail[2])*scale,
                (detail[3]-previous_detail[3])*scale,(detail[4]-previous_detail[4])*scale,
                (detail[5]-previous_detail[5])*scale,(detail[6]-previous_detail[6])*scale,(detail[7]-previous_detail[7])*scale);
            memcpy(previous_detail,detail,sizeof(detail));
            if(gx_frame_active()){
                GXFrameStats pipeline;gx_frame_stats(&pipeline);
                printf("[Render pipeline] packets=%llu bytes=%llu backend_ms_total=%.3f producer_wait_ms_total=%.3f cpu_worker=1 SDL_owner=main\n",pipeline.packets,pipeline.bytes,pipeline.worker_ticks*1000.0/(double)pacing_frequency,pipeline.wait_ticks*1000.0/(double)pacing_frequency);
                static GXFrameStats previous_pipeline;
                if(pipeline.packets<previous_pipeline.packets)memset(&previous_pipeline,0,sizeof(previous_pipeline));
                printf("[Render pipeline60] backend_draw_ms=%.4f backend_copy_ms=%.4f backend_swap_ms=%.4f backend_work_ms=%.4f producer_wait_ms=%.4f\n",
                    (pipeline.draw_ticks-previous_pipeline.draw_ticks)*scale,(pipeline.copy_ticks-previous_pipeline.copy_ticks)*scale,
                    (pipeline.swap_ticks-previous_pipeline.swap_ticks)*scale,(pipeline.worker_ticks-previous_pipeline.worker_ticks)*scale,(pipeline.wait_ticks-previous_pipeline.wait_ticks)*scale);
                printf("[Render sync60] backend_decode_ms=%.4f barrier_wait_ms=%.4f queue_wait_ms=%.4f barriers_per_frame=%.3f blocked_barriers_per_frame=%.3f queue_blocks_per_frame=%.3f pe_submits_per_frame=%.3f raw_draws_per_frame=%.3f raw_vertices_per_frame=%.0f captured_bytes_per_frame=%.0f ram_copies_per_frame=%.3f\n",
                    (pipeline.decode_ticks-previous_pipeline.decode_ticks)*scale,(pipeline.barrier_ticks-previous_pipeline.barrier_ticks)*scale,(pipeline.pressure_ticks-previous_pipeline.pressure_ticks)*scale,
                    (double)(pipeline.barrier_calls-previous_pipeline.barrier_calls)/frame_report.frames,(double)(pipeline.barrier_waits-previous_pipeline.barrier_waits)/frame_report.frames,
                    (double)(pipeline.pressure_waits-previous_pipeline.pressure_waits)/frame_report.frames,(double)(pipeline.pe_submits-previous_pipeline.pe_submits)/frame_report.frames,
                    (double)(pipeline.raw_draws-previous_pipeline.raw_draws)/frame_report.frames,(double)(pipeline.raw_vertices-previous_pipeline.raw_vertices)/frame_report.frames,
                    (double)(pipeline.snapshot_bytes-previous_pipeline.snapshot_bytes)/frame_report.frames,(double)(pipeline.ram_copies-previous_pipeline.ram_copies)/frame_report.frames);
                printf("[Render snapshot60] capture_unique_bytes_per_frame=%.0f capture_reused_bytes_per_frame=%.0f capture_compare_ms=%.4f arenas=%u\n",
                    (double)(pipeline.unique_bytes-previous_pipeline.unique_bytes)/frame_report.frames,(double)(pipeline.reused_bytes-previous_pipeline.reused_bytes)/frame_report.frames,
                    (pipeline.compare_ticks-previous_pipeline.compare_ticks)*scale,GX_FRAME_ARENAS);
                previous_pipeline=pipeline;
                printf("[Render credits] frames_queued=%llu frames_presented=%llu frame_limit_ms_total=%.3f\n",pipeline.frames_queued,pipeline.frames_presented,pipeline.frame_limit_ticks*1000.0/(double)pacing_frequency);
            }
            printf("[Frame60] frames=%u cpu_game_logic_ms=%.4f cpu_gx_decode_ms=%.4f gl_draw_submit_ms=%.4f gl_efb_copy_ms=%.4f gl_swap_wait_ms=%.4f host_other_ms=%.4f host_pacing_ms=%.4f frame_wall_ms=%.4f scene=%u cpu_game_logic_peak_ms=%.4f frame_wall_peak_ms=%.4f\n",
                frame_report.frames,frame_report.ms[FRAME_GAME],frame_report.ms[FRAME_GX_DECODE],
                frame_report.ms[FRAME_GL_SUBMIT],frame_report.ms[FRAME_EFB_COPY],frame_report.ms[FRAME_SWAP],
                frame_report.ms[FRAME_OTHER],frame_report.ms[FRAME_PACING],frame_report.wall_ms,
                s_scene_address ? mem_read32(&cpu,s_scene_address+8):0,frame_report.peak_ms[FRAME_GAME],frame_report.wall_peak_ms);
            fflush(stdout);
        }
    }

    cpu_frame_stop();
    if(gx_frame_active())gx_pipe_frame_stop(&cpu);
    gx_pipe_shutdown();
    input_shutdown();
    video_audio_shutdown();
    dvd_vfs_shutdown();
    card_store_shutdown();
    cpu_free(&cpu);
#ifdef _WIN32
    s_crash_cpu = NULL;
#endif
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
