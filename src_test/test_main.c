#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOLRECOMP_ENABLE_REPLACEMENTS
#include "generated.h"
#include "dol_loader.h"
#include "dvd_vfs.h"
#include "video_audio.h"
#include "input.h"
#include "gx_pipe.h"

static u32 s_spr_hid0 = 0x0011C064u;

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
    if (ea < cpu->ram_size) {
        u8* ptr = cpu->ram + ea;
        switch (size) {
            case 1: return *ptr;
            case 2: { u16 v; memcpy(&v, ptr, 2); return _byteswap_ushort(v); }
            case 4: { u32 v; memcpy(&v, ptr, 4); return _byteswap_ulong(v); }
            case 8: { u64 v; memcpy(&v, ptr, 8); return _byteswap_uint64(v); }
        }
    }

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
    // External Interface (EXI) MMIO (0xCC006800 & 0xCC006C00)
    if ((reg & 0xFFFFFF00) == 0xCC006800 || (reg & 0xFFFFFF00) == 0xCC006C00) {
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
    if (ea < cpu->ram_size) {
        u8* ptr = cpu->ram + ea;
        switch (size) {
            case 1: *ptr = (u8)value; break;
            case 2: { u16 v = _byteswap_ushort((u16)value); memcpy(ptr, &v, 2); break; }
            case 4: { u32 v = _byteswap_ulong((u32)value); memcpy(ptr, &v, 4); break; }
            case 8: { u64 v = _byteswap_uint64(value); memcpy(ptr, &v, 8); break; }
        }
        return;
    }

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
    // External Interface (EXI) MMIO (0xCC006800 & 0xCC006C00)
    if ((reg & 0xFFFFFF00) == 0xCC006800 || (reg & 0xFFFFFF00) == 0xCC006C00) {
        return;
    }
    // DVD Interface MMIO (0xCC006000)
    if ((reg & 0xFFFFFF00) == 0xCC006000) {
        dvd_vfs_write_reg(cpu, ea & 0xFF, (u32)value);
        return;
    }
    // GX Gather Pipe write port (0xCC008000 or 0x0C008000)
    if (reg == 0xCC008000 || reg == 0x0C008000) {
        gx_pipe_write_fifo(cpu, ea, value, size);
        return;
    }
}

void handle_instruction_fallback(CPUState* cpu, u32 raw, u32 cia) {
    u32 opcode = (raw >> 26) & 0x3F;
    u32 sub_op = (raw >> 1) & 0x3FF;

    if (opcode == 31 && sub_op == 339) { // mfspr
        u32 rd = (raw >> 21) & 0x1F;
        u32 spr = ((raw >> 16) & 0x1F) | (((raw >> 11) & 0x1F) << 5);
        cpu->gpr[rd] = (spr == 1008) ? s_spr_hid0 : 0;
        cpu->pc = cia + 4;
        return;
    }
    if (opcode == 31 && sub_op == 467) { // mtspr
        u32 rs = (raw >> 21) & 0x1F;
        u32 spr = ((raw >> 16) & 0x1F) | (((raw >> 11) & 0x1F) << 5);
        if (spr == 1008) s_spr_hid0 = cpu->gpr[rs];
        cpu->pc = cia + 4;
        return;
    }

    cpu->pc = cia + 4;
}

static SDL_Window* s_main_window = NULL;
static SDL_Renderer* s_main_renderer = NULL;
static u32 s_current_frame_num = 0;
static bool s_user_confirmed_dlg = false;
static bool s_unblack_called = false;
static u32 s_dvd_read_count = 0;

static void save_thread_context(CPUState* cpu, u32 thread_addr) {
    if (thread_addr < GC_RAM_BASE || (thread_addr - GC_RAM_BASE + 0x2C8) > cpu->ram_size) return;
    for (int i = 0; i < 32; i++) {
        mem_write32(cpu, thread_addr + (u32)i * 4u, cpu->gpr[i]);
    }
    mem_write32(cpu, thread_addr + 0x080u, cpu->cr);
    mem_write32(cpu, thread_addr + 0x084u, cpu->lr);
    mem_write32(cpu, thread_addr + 0x088u, cpu->ctr);
    mem_write32(cpu, thread_addr + 0x08Cu, cpu->xer);
    for (int i = 0; i < 32; i++) {
        u64 bits;
        memcpy(&bits, &cpu->fpr[i], sizeof(bits));
        mem_write64(cpu, thread_addr + 0x090u + (u32)i * 8u, bits);
    }
    mem_write32(cpu, thread_addr + 0x194u, cpu->fpscr);
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
    for (int i = 0; i < 32; i++) {
        u64 bits = mem_read64(cpu, thread_addr + 0x090u + (u32)i * 8u);
        memcpy(&cpu->fpr[i], &bits, sizeof(bits));
    }
    cpu->fpscr = mem_read32(cpu, thread_addr + 0x194u);
    u32 saved_pc = mem_read32(cpu, thread_addr + 0x198u);
    if (saved_pc >= GC_RAM_BASE && saved_pc < GC_RAM_BASE + cpu->ram_size) {
        cpu->pc = saved_pc;
    }
    cpu->msr = mem_read32(cpu, thread_addr + 0x19Cu) | 0x8000u; // Enable MSR[EE]
    for (int i = 0; i < 8; i++) {
        cpu->gqr[i] = mem_read32(cpu, thread_addr + 0x1A4u + (u32)i * 4u);
    }
    mem_write32(cpu, 0x800000D4u, thread_addr);
    mem_write32(cpu, 0x800000E4u, thread_addr);
    mem_write16(cpu, thread_addr + 0x2C8u, 2); // OS_THREAD_STATE_RUNNING
}

// Replacement dispatcher: hooks and NULL guard
int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address) {
    if (address == 0 || address == 0x80000000u) {
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
    if (address == 0x801CDFACu) {
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
    }
    // Scene Object Node circular list unblock (0x801CDFE4):
    // In chunk_0115, when iterating the circular scene node chain from r23,
    // if 8(r1) is 0 or outside valid RAM, cmpw r9, r23 fails to match (0 != r23), looping forever.
    // Cleanly advance PC to 0x801CE05C to exit the node loop.
    if (address == 0x801CDFE4u) {
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
    }
    // BSS / Data pointer jump guard: Prevent jumping into non-code RAM structures (e.g. 0x803BFD58)
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
    // Audio Voice Allocation Guard (0x80212490):
    // If r30 (event) is -1 (0xFFFFFFFF), there is no pending event (already consumed).
    // Jump directly to epilogue (0x802124D0) to prevent infinite allocation loop.
    if (address == 0x80212490u || address == 0x80212494u) {
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
    if (address == 0x802BEF68u) {
        ctx->pc = ctx->lr;
        return 1;
    }
    if (address >= 0x802BEFE0u && address < 0x802BF114u) {
        ctx->pc = 0x802BF114u;
        return 0; // Let native epilogue at 0x802BF114 run and blr back to caller
    }
    // OSResetSystem (0x802C50DC): Console reset stub - return immediately to continue PC runtime
    if (address == 0x802C50DCu) {
        printf("[HLE OSResetSystem 0x802C50DC] Console reset evitado; avancando para proxima cena! (caller=0x%08X)\n", ctx->lr);
        fflush(stdout);
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADInit (0x802D76D0): Initialize PAD subsystem and return success
    if (address == 0x802D76D0u) {
        printf("[HLE PADInit 0x802D76D0] PAD Subsystem inicializado com sucesso (caller=0x%08X)\n", ctx->lr);
        fflush(stdout);
        ctx->gpr[3] = 1;
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADRead (0x802D78E8 & 0x802D7CB4): Populate 4 PADStatus slots and return port 0 ready
    if (address == 0x802D78E8u || address == 0x802D7CB4u) {
        u32 out = ctx->gpr[3];
        const NativePadState* p0 = input_get_pad(0);

        if (out >= GC_RAM_BASE && (out - GC_RAM_BASE + 48) <= ctx->ram_size) {
            // Port 0: Player 1 connected
            mem_write16(ctx, out + 0, p0->button);
            mem_write8(ctx, out + 2, (u8)p0->stick_x);
            mem_write8(ctx, out + 3, (u8)p0->stick_y);
            mem_write8(ctx, out + 4, (u8)p0->substick_x);
            mem_write8(ctx, out + 5, (u8)p0->substick_y);
            mem_write8(ctx, out + 6, p0->trigger_l);
            mem_write8(ctx, out + 7, p0->trigger_r);
            mem_write8(ctx, out + 8, (p0->button & PAD_BUTTON_A) ? 0xFF : 0);
            mem_write8(ctx, out + 9, (p0->button & PAD_BUTTON_B) ? 0xFF : 0);
            mem_write8(ctx, out + 10, 0); // PAD_ERR_NONE (connected!)
            mem_write8(ctx, out + 11, 0);

            // Ports 1, 2, 3: Disconnected
            for (u32 i = 1; i < 4; i++) {
                u32 p = out + i * 12;
                mem_write16(ctx, p + 0, 0);
                mem_write8(ctx, p + 2, 0);
                mem_write8(ctx, p + 3, 0);
                mem_write8(ctx, p + 4, 0);
                mem_write8(ctx, p + 5, 0);
                mem_write8(ctx, p + 6, 0);
                mem_write8(ctx, p + 7, 0);
                mem_write8(ctx, p + 8, 0);
                mem_write8(ctx, p + 9, 0);
                mem_write8(ctx, p + 10, 0xFF); // PAD_ERR_NO_CONTROLLER (-1)
                mem_write8(ctx, p + 11, 0);
            }
        }

        static u32 s_padread_cnt = 0;
        if (s_padread_cnt++ < 3 || (p0->button != 0 && s_padread_cnt % 60 == 0)) {
            printf("[HLE PADRead 0x%08X #%u] Port 0: btn=0x%04X stick=(%d, %d) err=0 (caller=0x%08X)\n",
                   address, s_padread_cnt, p0->button, p0->stick_x, p0->stick_y, ctx->lr);
            fflush(stdout);
        }

        ctx->gpr[3] = 0x80000000u; // Mask with Port 0 ready (PAD_CHAN0_BIT)
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADClamp (0x802D68E4): Stick normalization & deadzone
    if (address == 0x802D68E4u) {
        ctx->gpr[3] = 1;
        ctx->pc = ctx->lr;
        return 1;
    }
    // PADControlMotor (0x802D7D6C): Rumble motor control
    if (address == 0x802D7D6Cu) {
        ctx->pc = ctx->lr;
        return 1;
    }
    // VIWaitForRetrace (0x802DDA7C / 0x802DDA80): Native GameCube V-Sync hook
    if (address == 0x802DDA7Cu || address == 0x802DDA80u) {
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            u32 retrace_addr = ctx->gpr[13] - 25196;
            u32 count = mem_read32(ctx, retrace_addr);
            mem_write32(ctx, retrace_addr, count + 1);
        }
        static u32 s_retrace_hook_count = 0;
        if (s_retrace_hook_count++ % 60 == 0) {
            printf("[HLE VIWaitForRetrace] Frame %u atendido (caller=0x%08X)\n", s_retrace_hook_count, ctx->lr);
            fflush(stdout);
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // Game File Read (0x80222EA8)
    if (address == 0x80222EA8u) {
        static u32 s_read_cnt = 0;
        if (s_read_cnt++ < 15) {
            printf("[Game Read 0x80222EA8 #%u] handle=0x%08X dst=0x%08X len=%u (caller=0x%08X)\n",
                   s_read_cnt, ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->lr);
            fflush(stdout);
        }
        return 0; // Let native logic run to prepare request
    }
    // DVDReadAsync (0x802B6BA4)
    if (address == 0x802B6BA4u) {
        printf("[DVDReadAsync 0x802B6BA4] info=0x%08X dst=0x%08X len=%u off=%u (caller=0x%08X)\n",
               ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->gpr[6], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // DVDReadAsyncPrio (0x802B92B0): Complete disc read instantly via DVD VFS
    if (address == 0x802B92B0u) {
        u32 info   = ctx->gpr[3];
        u32 dst    = ctx->gpr[4];
        u32 len    = ctx->gpr[5];
        u32 off    = ctx->gpr[6];
        u32 cb     = ctx->gpr[7];

        s_dvd_read_count++;
        printf("[HLE DVDReadAsyncPrio 0x802B92B0 #%u] info=0x%08X dst=0x%08X len=%u off=0x%08X cb=0x%08X (caller=0x%08X)\n",
               s_dvd_read_count, info, dst, len, off, cb, ctx->lr);

        bool should_skip_disc_read = false;
        if (off <= 0x440u && (dst >= 0x80400000u || dst == 0x80683820u || dst == 0x80683220u)) {
            should_skip_disc_read = true;
            printf("  [PROTECTION] Evitando sobrescrever buffer de recurso em 0x%08X com offset ISO 0x%08X (len=%u)!\n",
                   dst, off, len);
            fflush(stdout);
        }

        if (!should_skip_disc_read && dst >= GC_RAM_BASE && (dst - GC_RAM_BASE + len) <= ctx->ram_size) {
            dvd_vfs_read_bytes((u64)off, ctx->ram + (dst - GC_RAM_BASE), len);
            u8* p = ctx->ram + (dst - GC_RAM_BASE);
            printf("  -> Primeiros 16 bytes carregados em 0x%08X: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X ('%c%c%c%c')\n",
                   dst, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7],
                   p[8], p[9], p[10], p[11], p[12], p[13], p[14], p[15],
                   (p[0]>=32&&p[0]<127)?p[0]:'.', (p[1]>=32&&p[1]<127)?p[1]:'.',
                   (p[2]>=32&&p[2]<127)?p[2]:'.', (p[3]>=32&&p[3]<127)?p[3]:'.');
        }

        if (info >= GC_RAM_BASE && (info - GC_RAM_BASE + 96) <= ctx->ram_size) {
            mem_write32(ctx, info + 8, 1);     // command = READ (1)
            mem_write32(ctx, info + 12, 0);    // state = DVD_STATE_END (0)
            mem_write32(ctx, info + 16, off);  // offset
            mem_write32(ctx, info + 20, len);  // length
            mem_write32(ctx, info + 24, dst);  // addr
            mem_write32(ctx, info + 32, len);  // transferredSize = len
            mem_write32(ctx, info + 72, len);  // bytes read
            mem_write32(ctx, info + 84, 0);    // clear pending flag!

            u32 user_cb = mem_read32(ctx, info + 56);
            u32 stream_desc = mem_read32(ctx, info + 76);
            if (stream_desc >= GC_RAM_BASE && (stream_desc - GC_RAM_BASE + 32) <= ctx->ram_size) {
                u32 curr_off = mem_read32(ctx, stream_desc + 8);
                u32 curr_trans = mem_read32(ctx, stream_desc + 12);
                u32 curr_rem = mem_read32(ctx, stream_desc + 16);
                u32 curr_total = mem_read32(ctx, stream_desc + 20);
                u32 new_off = curr_off + len;
                u32 new_trans = curr_trans + len;
                u32 new_rem = (curr_rem >= len) ? (curr_rem - len) : 0;
                u32 new_total = (curr_total >= len) ? (curr_total - len) : 0;
                mem_write32(ctx, stream_desc + 8, new_off);
                mem_write32(ctx, stream_desc + 12, new_trans);
                mem_write32(ctx, stream_desc + 16, new_rem);
                mem_write32(ctx, stream_desc + 20, new_total);
                printf("  -> stream_desc 0x%08X: off=%u trans=%u rem_chunk=%u rem_total=%u\n",
                       stream_desc, new_off, new_trans, new_rem, new_total);
            }
            printf("  -> info atualizado: state=0, flag[84]=0, transferred=%u, user_cb=0x%08X\n", len, user_cb);

            // Invoke user_cb(info, result=0, transferredSize=len) so the engine's
            // async completion chain fires immediately (avoids post-load stall).
            if (user_cb >= GC_RAM_BASE && user_cb < (GC_RAM_BASE + ctx->ram_size)) {
                printf("  -> Invocando user_cb=0x%08X(info=0x%08X, 0, %u) para completar cadeia async!\n",
                       user_cb, info, len);
                fflush(stdout);
                // Save return address so user_cb BLR returns to our caller.
                u32 saved_lr = ctx->lr;
                ctx->gpr[3] = info; // arg0 = DVDFileInfo*
                ctx->gpr[4] = 0;    // arg1 = result (DVDRESULT_GOOD)
                ctx->gpr[5] = len;  // arg2 = transferredSize
                ctx->lr     = saved_lr; // BLR in user_cb will land back at caller
                ctx->pc     = user_cb;
                return 1;
            }
        }

        fflush(stdout);
        ctx->gpr[3] = 1; // return TRUE
        ctx->pc = ctx->lr;
        return 1;
    }
    // OSReport (0x802C06BC)
    if (address == 0x802C06BCu) {
        u32 fmt_ptr = ctx->gpr[3];
        if (fmt_ptr >= GC_RAM_BASE && (fmt_ptr - GC_RAM_BASE) < ctx->ram_size) {
            char fmt_buf[256];
            strncpy(fmt_buf, (const char*)(ctx->ram + (fmt_ptr - GC_RAM_BASE)), sizeof(fmt_buf) - 1);
            fmt_buf[sizeof(fmt_buf) - 1] = '\0';
            printf("[OSReport 0x802C06BC] %s\n", fmt_buf);
            fflush(stdout);
        }
        return 0; // Let native OSReport run
    }
    // OSPanic (0x802C075C): Intercept and diagnose panics with callstack
    if (address == 0x802C075Cu) {
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
    }
    // Panic / Error Handler (0x802C1534)
    if (address == 0x802C1534u) {
        printf("[Panic/Error 0x802C1534] r3=0x%08X r4=0x%08X r5=0x%08X r6=0x%08X (caller=0x%08X)\n",
               ctx->gpr[3], ctx->gpr[4], ctx->gpr[5], ctx->gpr[6], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // PPCHalt (0x802D6458): Game spin/halt loop
    if (address == 0x802D6458u) {
        static u32 s_halt_cnt = 0;
        if (s_halt_cnt++ == 0) {
            printf("[PPCHalt 0x802D6458] System entered PPCHalt spin loop (caller=0x%08X)!\n", ctx->lr);
            fflush(stdout);
        }
        return 0;
    }
    // DVDLowCommand (0x802BC754)
    if (address == 0x802BC754u) {
        printf("[DVDLowCommand 0x802BC754] cmd=0x%08X (caller=0x%08X)\n", ctx->gpr[3], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // Scene UI Start (0x8014B4B4)
    if (address == 0x8014B4B4u) {
        static u32 s_ui_cnt = 0;
        if (s_ui_cnt++ < 3 || (s_ui_cnt % 60 == 0)) {
            printf(">>> [Scene UI Start 0x8014B4B4] obj=0x%08X (caller=0x%08X) <<<\n",
                   ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        return 0;
    }
    // Scene Object Display Readiness hook (0x801AFB48):
    // Returns legitimate display object pointer (e.g. 60(scene) or 64(scene)) or 0 when not ready.
    if (address == 0x801AFB48u) {
        static u32 s_afb48_cnt = 0;
        u32 scn = ctx->gpr[3];
        u32 d60 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 60) : 0;
        u32 d64 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 64) : 0;
        if (s_afb48_cnt++ % 60 == 0 || s_afb48_cnt < 5) {
            printf("[Scene Object Readiness 0x801AFB48 #%u] scn=0x%08X d60=0x%08X d64=0x%08X (caller=0x%08X)\n",
                   s_afb48_cnt, scn, d60, d64, ctx->lr);
            fflush(stdout);
        }
        if (d60 >= GC_RAM_BASE && (d60 - GC_RAM_BASE + 44) <= ctx->ram_size) {
            u32 off36 = mem_read32(ctx, d60 + 36);
            u32 off40 = mem_read32(ctx, d60 + 40);
            if (off36 == 0) mem_write32(ctx, d60 + 36, 1);
            if (off40 == 0) mem_write32(ctx, d60 + 40, 1);
            ctx->gpr[3] = d60;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0; // Let native 0x801AFB48 run and return legitimate display object pointer!
    }
    // Scene Load Start (0x801B14D8)
    if (address == 0x801B14D8u) {
        u32 scn = ctx->gpr[3];
        u32 d60 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 60) : 0;
        printf("\n>>> [Scene Load Start 0x801B14D8] scene=0x%08X 60(scene)=0x%08X (caller=0x%08X) <<<\n\n",
               scn, d60, ctx->lr);
        fflush(stdout);
        return 0;
    }
    // Scene Load Poll (0x801B1510): Check scene completion state
    if (address == 0x801B1510u) {
        u32 scn = ctx->gpr[3];
        if (s_user_confirmed_dlg) {
            static bool s_boot_poll_done = false;
            if (!s_boot_poll_done) {
                s_boot_poll_done = true;
                if (scn >= GC_RAM_BASE && (scn - GC_RAM_BASE + 152) <= ctx->ram_size) {
                    mem_write32(ctx, scn + 140, 1); // 140(scene) = 1 (boot check complete)
                    mem_write32(ctx, scn + 144, 1); // 144(scene) = 1 (load complete)
                    mem_write32(ctx, scn + 148, 0); // 148(scene) = 0 (no pending resources, ready for transition!)
                }
                if (ctx->gpr[13] >= GC_RAM_BASE) {
                    mem_write32(ctx, ctx->gpr[13] - 32164, 1);
                }
                printf("\n============================================================\n");
                printf(">>> [Scene Load Poll 0x801B1510] Diálogo fechado! Retornando 1 (carga completa)! <<<\n");
                printf(">>> scn=0x%08X 140=1 144=1 148=0 (caller=0x%08X) <<<\n", scn, ctx->lr);
                printf("============================================================\n\n");
                fflush(stdout);
                ctx->gpr[3] = 1;
                ctx->pc = ctx->lr;
                return 1;
            }
        }
        static u32 s_poll_cnt = 0;
        if (s_poll_cnt++ % 60 == 0 || s_poll_cnt < 5) {
            u32 r0_val = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 32164) : 0;
            u32 r144 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 144) : 0;
            u32 r148 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 148) : 0;
            printf("[Scene Load Poll 0x801B1510 #%u] scn=0x%08X r0_val=%u r144=%u r148=%u (caller=0x%08X)\n",
                   s_poll_cnt, scn, r0_val, r144, r148, ctx->lr);
            fflush(stdout);
        }
        return 0; // Let native logic evaluate scene completion
    }
    // Hardware VI / Retrace / Reset status check (0x802C54FC)
    if (address == 0x802C54FCu) {
        if (ctx->lr == 0x801AC6D4u) {
            if (s_user_confirmed_dlg) {
                u32 scn = (ctx->gpr[30] >= GC_RAM_BASE) ? ctx->gpr[30] : 0x80682D48u;
                u32 r144 = (scn >= GC_RAM_BASE && (scn - GC_RAM_BASE + 148) <= ctx->ram_size) ? mem_read32(ctx, scn + 144) : 0;
                static bool s_load_start_done = false;
                if (!s_load_start_done && r144 == 0) {
                    s_load_start_done = true;
                    printf("\n>>> [Boot Manager 0x801AC6D0] Invocando Scene Load Start (0x801B14D8)! <<<\n\n");
                    fflush(stdout);
                    ctx->gpr[3] = 1;
                    ctx->pc = ctx->lr;
                    return 1;
                }
            }
            ctx->gpr[3] = 0;
            ctx->pc = ctx->lr;
            return 1;
        }
        if (ctx->lr == 0x801AC6F8u) {
            static bool s_transition_invoked = false;
            if (!s_transition_invoked && s_user_confirmed_dlg) {
                s_transition_invoked = true;
                printf("\n>>> [Scene Load Complete 0x801AC6F8] Chamando Scene Transition (0x801AFA4C) para Title Screen! <<<\n\n");
                fflush(stdout);
                ctx->gpr[3] = 0;
            } else {
                ctx->gpr[3] = 1;
            }
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0; // Let native code run
    }
    // Scene Manager Update (0x801AC614)
    if (address == 0x801AC614u) {
        u32 scn = ctx->gpr[3];
        static u32 s_ac614_cnt = 0;
        static u32 s_last_state = 0xFFFFFFFFu;
        u32 st = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 8) : 0;

        // Desbloqueia o fader travado em status 3 (tela preta) para que o dialogo e o jogo fiquem sempre visiveis
        if (scn >= GC_RAM_BASE) {
            u32 fader = mem_read32(ctx, scn + 4);
            if (fader >= GC_RAM_BASE && (fader - GC_RAM_BASE + 32) <= ctx->ram_size) {
                u32 fst = mem_read32(ctx, fader + 16);
                if (fst == 3) {
                    mem_write32(ctx, fader + 16, 0); // Forca Fader para 0 (claro / inativo)
                    mem_write32(ctx, fader + 20, f32_to_u32_bits(0.0f)); // Alpha do fade = 0.0f
                }
            }
        }

        if (s_ac614_cnt++ % 60 == 0 || st != s_last_state || s_user_confirmed_dlg) {
            u32 fader = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 4) : 0;
            u32 fader_st = (fader >= GC_RAM_BASE) ? mem_read32(ctx, fader + 16) : 0;
            u32 d0 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 0) : 0;
            u32 d52 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 52) : 0;
            u32 d60 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 60) : 0;
            u32 d64 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 64) : 0;
            u32 d140 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 140) : 0;
            u32 d144 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 144) : 0;
            u32 d148 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 148) : 0;
            u32 act_dlg = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 25068) : 0;
            static u32 s_log_limit = 0;
            if (s_log_limit++ < 35 || st != s_last_state || (s_ac614_cnt % 60 == 0)) {
                printf("[Scene Update 0x801AC614 #%u] state=%u fader=0x%08X(st=%u) 0=0x%08X 52=0x%08X 60=0x%08X 64=0x%08X 140=%u 144=%u 148=%u act_dlg=0x%08X\n",
                       s_ac614_cnt, st, fader, fader_st, d0, d52, d60, d64, d140, d144, d148, act_dlg);
                fflush(stdout);
            }
            s_last_state = st;
        }
        if (s_user_confirmed_dlg) {
            u32 ptr_27228 = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 27228) : 0;
            if (st == 2) {
                if (ptr_27228 >= GC_RAM_BASE && (ptr_27228 - GC_RAM_BASE + 8) <= ctx->ram_size) {
                    u32 cur_flag = mem_read32(ctx, ptr_27228 + 4);
                    if (cur_flag == 0) {
                        printf("\n>>> [Resource Pack 0x%08X] Ativando flag 4(r9) = 1 para permitir criacao do Title Screen (60(scene))! <<<\n\n", ptr_27228);
                        fflush(stdout);
                        mem_write32(ctx, ptr_27228 + 4, 1);
                    }
                }
                if (ctx->gpr[13] >= GC_RAM_BASE) {
                    mem_write32(ctx, ctx->gpr[13] - 25068, 0); // Limpa active_dlg no State 2 para permitir finalizacao de 0x801BE824
                }
                u32 d60 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 60) : 0;
                if (d60 != 0) {
                    static bool s_state8_triggered = false;
                    if (!s_state8_triggered) {
                        s_state8_triggered = true;
                        printf("\n============================================================\n");
                        printf(">>> [Scene Manager 0x801AC614] 60(scene)=0x%08X pronto! Liberando avanco para State 8 (Title Screen)! <<<\n", d60);
                        printf("============================================================\n\n");
                        fflush(stdout);
                    }
                    if (ptr_27228 >= GC_RAM_BASE && (ptr_27228 - GC_RAM_BASE + 8) <= ctx->ram_size) {
                        mem_write32(ctx, ptr_27228 + 4, 0); // Desativa flag para que 0x801AD0CC avance para State 8!
                    }
                    mem_write32(ctx, scn + 148, 1);
                    if (ctx->gpr[13] >= GC_RAM_BASE) {
                        mem_write32(ctx, ctx->gpr[13] - 30968, 1);
                        mem_write32(ctx, ctx->gpr[13] - 25064, 3);
                    }
                }
            } else if (st == 8) {
                if (scn >= GC_RAM_BASE && (scn - GC_RAM_BASE + 152) <= ctx->ram_size) {
                    mem_write32(ctx, scn + 148, 0);
                }
            }
        }
        return 0; // Let native code run
    }
    // Fader isBusy check (0x8009B3C4):
    if (address == 0x8009B3C4u) {
        u32 fader = ctx->gpr[3];
        if (fader >= GC_RAM_BASE && (fader - GC_RAM_BASE + 24) <= ctx->ram_size) {
            mem_write32(ctx, fader + 16, 0); // Desbloqueia fader preso em status 3
            mem_write32(ctx, fader + 20, f32_to_u32_bits(0.0f));
        }
        u32 st = (fader >= GC_RAM_BASE) ? mem_read32(ctx, fader + 16) : 0;
        static u32 s_9b3c4_cnt = 0;
        if (s_9b3c4_cnt++ < 15 || (s_9b3c4_cnt % 60 == 0)) {
            printf("[Fader Check 0x8009B3C4 #%u] fader=0x%08X status=%u (caller=0x%08X)\n",
                   s_9b3c4_cnt, fader, st, ctx->lr);
            fflush(stdout);
        }
        if (ctx->lr == 0x801AC72Cu) {
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        ctx->gpr[3] = 0; // Fader not busy!
        ctx->pc = ctx->lr;
        return 1;
    }
    // Scene canTransition check (0x801B1564):
    if (address == 0x801B1564u) {
        static u32 s_b1564_cnt = 0;
        if (s_b1564_cnt++ < 10) {
            printf("[Scene Transition Check 0x801B1564 #%u] scene=0x%08X (caller=0x%08X)\n",
                   s_b1564_cnt, ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        ctx->gpr[3] = 0;
        ctx->pc = ctx->lr;
        return 1;
    }
    // Scene Case 2 (Title Screen Setup 0x801AD25C)
    if (address == 0x801AD25Cu) {
        printf("\n>>> [Scene Case 2 (Title Screen Setup) 0x801AD25C ENTER] scene=0x%08X (caller=0x%08X) <<<\n\n",
               ctx->gpr[3], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // Dialog Close Callback return point (0x801AC9C8 -> LR=0x801AC9CC)
    if (ctx->lr == 0x801AC9CCu) {
        static bool s_dlg_cb_logged = false;
        if (!s_dlg_cb_logged) {
            s_dlg_cb_logged = true;
            printf("\n>>> [Dialog Close Callback Finish] returned r3=%u! (scene will transition to this state) <<<\n\n",
                   ctx->gpr[3]);
            fflush(stdout);
        }
        return 0;
    }
    // Title Screen Scene Setup (0x801AD0CC): Allocates 0(scene), initializes UI and advances to State 8
    if (address == 0x801AD0CCu) {
        static u32 s_ad0cc_cnt = 0;
        if (s_ad0cc_cnt++ < 5) {
            printf("\n============================================================\n");
            printf(">>> [Scene Setup 0x801AD0CC #%u] scene=0x%08X (caller=0x%08X) -> Executando setup nativo! <<<\n",
                   s_ad0cc_cnt, ctx->gpr[3], ctx->lr);
            printf("============================================================\n\n");
            fflush(stdout);
        }
        return 0; // Let native 0x801AD0CC run to allocate 0(scene) and initialize UI!
    }
    // Resource Completion / Scene Async Poll (0x801BE824): Let native code run to parse and initialize resource headers
    if (address == 0x801BE824u) {
        static u32 s_be824_cnt = 0;
        if (s_be824_cnt++ < 10 || (s_be824_cnt % 60 == 0)) {
            printf("[Resource Ready Check 0x801BE824 #%u] obj=0x%08X out_ptr=0x%08X (caller=0x%08X dvd_reads=%u)\n",
                   s_be824_cnt, ctx->gpr[3], ctx->gpr[4], ctx->lr, s_dvd_read_count);
            fflush(stdout);
        }
        if (s_dvd_read_count >= 21) {
            u32 out_ptr = ctx->gpr[4];
            if (out_ptr >= GC_RAM_BASE && (out_ptr - GC_RAM_BASE + 4) <= ctx->ram_size) {
                mem_write32(ctx, out_ptr, 0); // Limpa ponteiro/código de erro
            }
            static bool s_be824_done_logged = false;
            if (!s_be824_done_logged) {
                s_be824_done_logged = true;
                printf("\n============================================================\n");
                printf(">>> [Resource Check 0x801BE824] Todos os %u pacotes de DVD lidos! <<<\n", s_dvd_read_count);
                printf(">>> Retornando 1 para acionar SceneSetState(scene, 8) e fade-in do Title Screen! <<<\n");
                printf("============================================================\n\n");
                fflush(stdout);
            }
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0; // Let native logic parse and initialize resource headers and pointers!
    }
    // Resource System Completion Check (0x801BDA98): Return 1 if Title Screen DVD reads complete
    if (address == 0x801BDA98u) {
        static u32 s_bda98_cnt = 0;
        if (s_bda98_cnt++ < 10 || (s_bda98_cnt % 60 == 0)) {
            printf("[Resource System Completion 0x801BDA98 #%u] (caller=0x%08X dvd_reads=%u)\n",
                   s_bda98_cnt, ctx->lr, s_dvd_read_count);
            fflush(stdout);
        }
        if (s_dvd_read_count >= 21) {
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0; // Let native logic run!
    }
    // Return point from 0x801BE824 in Scene Setup (0x801AD0CC)
    if (address == 0x801AD124u) {
        if (s_dvd_read_count >= 21) {
            ctx->gpr[3] = 1;
            u32 ea = ctx->gpr[1] + 8;
            if (ea >= GC_RAM_BASE && (ea - GC_RAM_BASE + 4) <= ctx->ram_size) {
                mem_write32(ctx, ea, 0);
            }
        }
        static u32 s_ret_be824 = 0;
        if (s_ret_be824++ < 10 || (s_ret_be824 % 60 == 0) || ctx->gpr[3] != 0) {
            printf("[0x801BE824 Return to 0x801AD124] r3=%u (frame=%u dvd_reads=%u)\n",
                   ctx->gpr[3], s_current_frame_num, s_dvd_read_count);
            fflush(stdout);
        }
        return 0;
    }
    // Title Screen UI Initialization (0x80161718):
    if (address == 0x80161718u) {
        printf("\n============================================================\n");
        printf(">>> [Title Screen UI Init 0x80161718] caller=0x%08X r3=0x%08X! <<<\n",
               ctx->lr, ctx->gpr[3]);
        printf("============================================================\n\n");
        fflush(stdout);
        return 0;
    }
    // SceneSetState (0x801AD410)
    if (address == 0x801AD410u) {
        if (ctx->lr == 0x801AFB24u && ctx->gpr[4] == 12) {
            printf("\n>>> [SceneSetState 0x801AD410] Redirecionando state 12 -> state 2 (Title Screen Setup)! <<<\n\n");
            ctx->gpr[4] = 2;
        }
        printf("\n>>> [SceneSetState 0x801AD410] scene=0x%08X state=%u (caller=0x%08X) <<<\n\n",
               ctx->gpr[3], ctx->gpr[4], ctx->lr);
        fflush(stdout);
        return 0;
    }
    // Scene Render (0x801ACB04)
    if (address == 0x801ACB04u) {
        u32 scn = ctx->gpr[3];
        u32 d60 = (scn >= GC_RAM_BASE) ? mem_read32(ctx, scn + 60) : 0;
        if (d60 != 0 && ctx->gpr[13] >= GC_RAM_BASE) {
            u32 r9_ptr = mem_read32(ctx, ctx->gpr[13] - 26792);
            if (r9_ptr >= GC_RAM_BASE && (r9_ptr - GC_RAM_BASE + 228) <= ctx->ram_size) {
                u32 val224 = mem_read32(ctx, r9_ptr + 224);
                if (val224 == 0) {
                    mem_write32(ctx, r9_ptr + 224, 1);
                }
            }
        }
        static u32 s_render_cnt = 0;
        if (s_render_cnt++ % 60 == 0) {
            printf("[Scene Render 0x801ACB04 #%u] scene=0x%08X (caller=0x%08X)\n",
                   s_render_cnt, ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        return 0;
    }
    // Scene Transition Handler (0x801AFA4C): Transitions to "menus/title"
    if (address == 0x801AFA4Cu) {
        printf("\n============================================================\n");
        printf(">>> [Scene Transition 0x801AFA4C] EXECUTANDO TRANSICAO PARA MENUS/TITLE! <<<\n");
        printf(">>> caller=0x%08X scene=0x%08X <<<\n", ctx->lr, ctx->gpr[3]);
        printf("============================================================\n\n");
        fflush(stdout);
        return 0;
    }
    // VISetBlack (0x802DF164): Impede que a tela fique preta durante a transicao pro Title Screen!
    if (address == 0x802DF164u) {
        static u32 s_viblack_cnt = 0;
        if (s_viblack_cnt++ % 60 == 0 || s_viblack_cnt < 10) {
            printf("[VISetBlack 0x802DF164] pedido black=%u -> forcando 0 (caller=0x%08X)\n", ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        ctx->gpr[3] = 0; // Forca VISetBlack(FALSE) para nao apagar o video!
        return 0;
    }
    // Async I/O request queue hook (0x802A2D98): Complete synchronous file/disc request and signal caller
    if (address == 0x802A2D98u) {
        u32 req = ctx->gpr[3];
        u32 dst = ctx->gpr[7];
        u32 handle = ctx->gpr[8];
        u32 len = ctx->gpr[9];
        u32 offset = ctx->gpr[10];

        static u32 s_io_req_count = 0;
        s_io_req_count++;
        if (s_io_req_count <= 25 || (s_io_req_count % 60 == 0)) {
            printf("[HLE I/O 0x802A2D98 #%u] req=0x%08X dst=0x%08X handle=0x%08X len=%u off=%u (caller=0x%08X)\n",
                   s_io_req_count, req, dst, handle, len, offset, ctx->lr);
            fflush(stdout);
        }

        if (req >= GC_RAM_BASE && (req - GC_RAM_BASE + 48) <= ctx->ram_size) {
            mem_write32(ctx, req + 0, 0);
            mem_write32(ctx, req + 4, ctx->gpr[4]);
            mem_write32(ctx, req + 8, ctx->gpr[5]);
            mem_write32(ctx, req + 16, ctx->gpr[7]);
            mem_write32(ctx, req + 20, ctx->gpr[8]);
            mem_write32(ctx, req + 24, ctx->gpr[9]);
            mem_write32(ctx, req + 28, ctx->gpr[10]);
            mem_write32(ctx, req + 32, 0); // status = complete (0)

            u32 cb = mem_read32(ctx, req + 36);
            u32 flag_ptr = mem_read32(ctx, req + 40);

            if (flag_ptr >= GC_RAM_BASE && (flag_ptr - GC_RAM_BASE + 4) <= ctx->ram_size) {
                mem_write32(ctx, flag_ptr, 1);
            }
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // DVD / Disc Drive Status hook (0x8028D82C): Return DVD_STATE_READY (0)
    if (address == 0x8028D82Cu) {
        ctx->gpr[3] = 0;
        ctx->pc = ctx->lr;
        return 1;
    }
    // getenv hook (0x80296AB0)
    if (address == 0x80296AB0u) {
        ctx->gpr[3] = 0;
        ctx->pc = ctx->lr;
        return 1;
    }
    // Boot check completion hook (0x800F0618 -> caller 0x801AC6C4):
    if (address == 0x800F0618u && ctx->lr == 0x801AC6C4u) {
        if (s_user_confirmed_dlg) {
            static bool s_boot_done_logged = false;
            if (!s_boot_done_logged) {
                s_boot_done_logged = true;
                printf("\n============================================================\n");
                printf(">>> [Boot Manager 0x801AC6C4] SUCESSO! Dialog fechado e confirmado! <<<\n");
                printf(">>> Retornando r3=1 para gravar 140(r30)=1 e carregar Title Screen! <<<\n");
                printf("============================================================\n\n");
                fflush(stdout);
            }
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0;
    }
    // Autosave dialog query and confirmation hook (0x800F20EC):
    if (address == 0x800F20ECu) {
        const NativePadState* p1 = input_get_pad(0);
        bool btn_pressed = (p1 && (p1->button & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_BUTTON_START)));

        static u32 s_f20ec_cnt = 0;
        if (s_f20ec_cnt++ < 3 || (s_f20ec_cnt % 60 == 0)) {
            printf("[Autosave 0x800F20EC #%u] caller=0x%08X btn=%d frame=%u\n",
                   s_f20ec_cnt, ctx->lr, btn_pressed, s_current_frame_num);
            fflush(stdout);
        }

        if (btn_pressed || s_user_confirmed_dlg) {
            s_user_confirmed_dlg = true;
            static bool s_dlg_adv = false;
            if (!s_dlg_adv) {
                s_dlg_adv = true;
                printf("\n============================================================\n");
                printf(">>> [Autosave Dialog] CONFIRMACAO ACIONADA (frame %u)! <<<\n", s_current_frame_num);
                printf(">>> Retornando 1 para fechar o diálogo via callback nativo e avancar para o Title Screen! <<<\n");
                printf("============================================================\n\n");
                fflush(stdout);
            }
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0;
    }
    if (address == 0x800F0654u || address == 0x800F06C0u) {
        return 0;
    }
    if (ctx->lr == 0x800F06F0u) {
        static bool s_f06ec_logged = false;
        if (!s_f06ec_logged) {
            s_f06ec_logged = true;
            printf("\n>>> [Autosave Transition 0x800F06EC] Executando target=0x%08X (dialog=0x%08X, reason=%u)! <<<\n\n",
                   address, ctx->gpr[3], ctx->gpr[4]);
            fflush(stdout);
        }
        return 0;
    }
    if (address == 0x800F06ECu) {
        printf("[Boot Transition 0x800F06EC] AVANCANDO CENA! (r3=0x%08X r4=%u ctr=0x%08X)\n",
               ctx->gpr[3], ctx->gpr[4], ctx->ctr);
        fflush(stdout);
        return 0;
    }
    if (address == 0x800FF4C8u) {
        const NativePadState* p1 = input_get_pad(0);
        bool btn_pressed = (p1 && (p1->button & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_BUTTON_START)));
        if (btn_pressed) {
            ctx->gpr[3] = 1;
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0;
    }
    if (address == 0x800F52D4u || address == 0x800F4074u) {
        ctx->pc = ctx->lr;
        return 1;
    }
    if (address == 0x800F0700u) {
        static bool s_boot_exit_logged = false;
        if (!s_boot_exit_logged) {
            s_boot_exit_logged = true;
            printf("[Boot Exit 0x800F0700] SUCESSO! Saiu da checagem de Memory Card e avancando para o jogo!\n");
            fflush(stdout);
        }
    }
    if (address == 0x800F405Cu) {
        static bool s_trans_logged = false;
        if (!s_trans_logged) {
            s_trans_logged = true;
            printf("[Scene Transition 0x800F405C] TRANSICAO DE CENA ACIONADA! (r3=0x%08X r12=0x%08X LR=0x%08X)\n",
                   ctx->gpr[3], ctx->gpr[12], ctx->lr);
            fflush(stdout);
        }
    }
    // Memory Card / Save Subsystem HLE stubs — Todos consistentes como NOCARD (-1)
    if (address == 0x802BA544u) { // CARDInit
        ctx->gpr[3] = 0; // CARD_RESULT_READY
        ctx->pc = ctx->lr;
        return 1;
    }
    // CARDProbe (0x802BA5DC) & CARDProbeEx (0x802BACC0): Retornar -1 (CARD_RESULT_NOCARD)
    // Assim o jogo nao tenta montar nem criar save e vai direto pro Title Screen!
    if (address == 0x802BA5DCu || address == 0x802BACC0u) {
        ctx->gpr[3] = (u32)(s32)(-1); // CARD_RESULT_NOCARD (-1)
        ctx->pc = ctx->lr;
        static u32 s_mc_count_2 = 0;
        if (s_mc_count_2++ < 5) {
            printf("[HLE MemCard Probe 0x%08X] NOCARD (-1) -> caller=0x%08X\n", address, ctx->lr);
            fflush(stdout);
        }
        return 1;
    }
    if (address == 0x802BAF18u || address == 0x802BAF80u || // CARDMount
        address == 0x802BB26Cu ||                           // CARDOpen
        address == 0x802BB3C4u || address == 0x802BB458u || // CARDRead
        address == 0x802BB4ECu || address == 0x802BB57Cu || // CARDWrite
        address == 0x802BAE7Cu ||                           // CARDGetResultCode
        address == 0x802BAC20u ||                           // CARDFreeBlocks
        address == 0x802BB1BCu) {                           // CARDCreate
        ctx->gpr[3] = (u32)(s32)(-1); // CARD_RESULT_NOCARD
        ctx->pc = ctx->lr;
        return 1;
    }
    if (address == 0x802BB608u || address == 0x802BAD18u || address == 0x802BAD8Cu) { // CARDClose / GetStatus
        ctx->gpr[3] = 0;
        ctx->pc = ctx->lr;
        return 1;
    }
    // -------------------------------------------------------------------------
    // Scene Advance 0x80018DC8 (chunk_0006): called from the boot/autosave loop
    if (address == 0x80018DC8u) {
        u32 raw_btn = ctx->gpr[4]; // button word from PADStatus
        u32 valid_btn = raw_btn & ~(u32)(PAD_TRIGGER_L | PAD_TRIGGER_R | PAD_TRIGGER_Z);
        if (valid_btn == 0) {
            ctx->pc = ctx->lr;
            return 1;
        }
        return 0;
    }
    // 0x80281C60: Scene-button-advance called by 0x80018DC8 when button 0x20 (Start) detected.
    if (address == 0x80281C60u) {
        static bool s_adv_logged = false;
        if (!s_adv_logged) {
            s_adv_logged = true;
            printf("[Scene Button Advance 0x80281C60] r3=0x%08X (caller=0x%08X)\n", ctx->gpr[3], ctx->lr);
            fflush(stdout);
        }
        return 0; // let native run
    }
    // -------------------------------------------------------------------------
    // VISetNextFrameBuffer hook (0x802DC848): Capture XFB address from r3 (first argument in PPC ABI)
    if (address == 0x802DC848u) {
        u32 fb = ctx->gpr[3];
        static u32 s_viset_count = 0;
        if (s_viset_count++ < 15) {
            printf("[HLE VI 0x802DC848] VISetNextFrameBuffer: r3=0x%08X r4=0x%08X (caller=0x%08X)\n",
                   ctx->gpr[3], ctx->gpr[4], ctx->lr);
            fflush(stdout);
        }

        // Real framebuffers are in RAM heap (>= 0x80300000), aligned to 32 bytes
        if (fb >= 0x80300000u && fb < (GC_RAM_BASE + ctx->ram_size) && (fb & 0x1Fu) == 0) {
            video_set_xfb_addr(fb);
        }
        return 0; // Let native VI logic continue
    }
    // VI register updater / SetNextFrameBuffer variant (0x802DD108)
    if (address == 0x802DD108u) {
        u32 fb = ctx->gpr[3];
        static u32 s_vi108_count = 0;
        if (s_vi108_count++ < 10) {
            printf("[VI Call 0x802DD108] r3=0x%08X (caller=0x%08X)\n", fb, ctx->lr);
            fflush(stdout);
        }
        if (fb >= 0x80300000u && fb < (GC_RAM_BASE + ctx->ram_size) && (fb & 0x1Fu) == 0) {
            video_set_xfb_addr(fb);
        }
        return 0;
    }
    // GXCopyDisp family hook (0x802D06A0 - 0x802D06DC): Capture framebuffer copy destination
    if (address >= 0x802D06A0u && address <= 0x802D06DCu) {
        u32 dest = ctx->gpr[3];
        static u32 s_copydisp_count = 0;
        if (s_copydisp_count++ < 20 || (s_copydisp_count % 60 == 0)) {
            printf("[GXCopyDisp 0x%08X] Frame %u: r3=0x%08X r4=0x%08X r5=0x%08X caller=0x%08X\n",
                   address, s_copydisp_count, dest, ctx->gpr[4], ctx->gpr[5], ctx->lr);
            fflush(stdout);
        }
        if (dest >= 0x80300000u && dest < (GC_RAM_BASE + ctx->ram_size) && (dest & 0x1Fu) == 0) {
            video_set_xfb_addr(dest);
        }
        return 0; // Let native GXCopyDisp continue
    }
    // VISetNextFrameBuffer wrapper (0x802DF07C)
    if (address == 0x802DF07Cu) {
        u32 fb = ctx->gpr[3];
        static u32 s_vi07c_count = 0;
        if (s_vi07c_count++ < 15) {
            printf("[VI Call 0x802DF07C] r3=0x%08X (caller=0x%08X)\n", fb, ctx->lr);
            fflush(stdout);
        }
        if (fb >= 0x80300000u && fb < (GC_RAM_BASE + ctx->ram_size) && (fb & 0x1Fu) == 0) {
            video_set_xfb_addr(fb);
        }
        return 0;
    }
    // Caller probe for 0x802D78C8 / 0x802D7A4C / 0x80248F18
    if (address == 0x802D78C8u || address == 0x802D7A4Cu || address == 0x80248F18u) {
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
    }
    // Real GXDrawDone hook (0x802CF09C): Flush GPU pipeline, mark token done, and return immediately
    if (address == 0x802CF09Cu) {
        gx_pipe_process_frame(ctx);
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write8(ctx, ctx->gpr[13] - 25320, 1); // Set DrawDone completed flag
        }
        static u32 s_drawdone_count = 0;
        if (s_drawdone_count++ < 5) {
            printf("[HLE GXDrawDone 0x802CF09C #%u] GPU processada, flag completada! (caller=0x%08X)\n",
                   s_drawdone_count, ctx->lr);
            fflush(stdout);
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // Real GXDrawDone wait loop hook (0x802CF0F4 / 0x802CF0EC)
    if (address == 0x802CF0F4u || address == 0x802CF0ECu) {
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write8(ctx, ctx->gpr[13] - 25320, 1);
        }
        static u32 s_drawwait_count = 0;
        if (s_drawwait_count++ < 5) {
            printf("[HLE GXDrawDone Wait #%u] Desbloqueado em 0x%08X -> 0x802CF100\n",
                   s_drawwait_count, address);
            fflush(stdout);
        }
        ctx->pc = 0x802CF100u;
        return 1;
    }
    // Engine Retrace Callback hook (0x80248B60): Clear flip wait flag (-0x7468)
    if (address == 0x80248B60u) {
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write32(ctx, ctx->gpr[13] - 0x7468, 0);
        }
        ctx->pc = ctx->lr;
        return 1;
    }
    // Buffer Swap Wait Loop hook (0x80243D8C / 0x80243D94): Unblock wait on -0x7468
    if (address == 0x80243D8Cu || address == 0x80243D94u) {
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write32(ctx, ctx->gpr[13] - 0x7468, 0);
        }
        ctx->pc = 0x80243D98u;
        return 1;
    }
    // Buffer Flip hook (0x802439E0 / 0x80243E00): Alternate active buffer index
    if (address == 0x802439E0u || address == 0x80243E00u) {
        static u32 s_flip_count = 0;
        u32 old_idx = (ctx->gpr[13] >= GC_RAM_BASE) ? mem_read32(ctx, ctx->gpr[13] - 0x6748) : 0;
        u32 new_idx = old_idx ^ 1;
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write32(ctx, ctx->gpr[13] - 0x6748, new_idx);
        }
        if (s_flip_count++ < 15) {
            printf("[Buffer Flip #%u] Swap concluido! idx: %u -> %u (caller=0x%08X)\n",
                   s_flip_count, old_idx, new_idx, ctx->lr);
            fflush(stdout);
        }
    }
    // Main Display Loop unblock hook (0x802435BC)
    if (address == 0x802435BCu) {
        if (ctx->gpr[13] >= GC_RAM_BASE) {
            mem_write32(ctx, ctx->gpr[13] - 0x7468, 0); // clear flip_flag
        }
        ctx->pc = 0x802435ECu; // Advance directly past the flip wait to loop exit
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    // Initialize SDL2
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) != 0) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao inicializar SDL2: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, NULL);
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Digimon Rumble Arena 2 - PC Port (Native Recompilation)",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao criar janela SDL2: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, NULL);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        char err[256];
        snprintf(err, sizeof(err), "Falha ao criar renderer: %s", SDL_GetError());
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", err, window);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    s_main_window = window;
    s_main_renderer = renderer;

    // Initialize Video Blitter & Audio Driver
    video_audio_init(renderer);

    // Initialize Gamepad & Keyboard Input Driver
    input_init();

    // Initialize CPU and Memory
    CPUState cpu;
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

    cpu.instruction_fallback = handle_instruction_fallback;
    cpu.external_read = handle_external_read;
    cpu.external_write = handle_external_write;

    // Resolve Disc Path & Init DVD VFS
    char ciso_path[512];
    if (find_existing_file("Digimon Rumble Arena 2 (USA).ciso", ciso_path, sizeof(ciso_path))) {
        if (dvd_vfs_init(ciso_path, &cpu)) {
            dvd_vfs_read_bytes(0, cpu.ram, 0x440);
        }
    }

    // Resolve DOL Path
    char dol_path[512];
    if (!find_existing_file("extracted/sys/main.dol", dol_path, sizeof(dol_path))) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp",
            "Nao foi possivel encontrar o arquivo 'extracted/sys/main.dol'!\nCertifique-se de executar o jogo na pasta do projeto.", window);
        gx_pipe_shutdown();
        video_audio_shutdown();
        cpu_free(&cpu);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    DolMetadata meta;
    if (!dol_load(dol_path, &cpu, &meta)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Digimon Recomp", "Falha ao ler o executavel main.dol!", window);
        gx_pipe_shutdown();
        video_audio_shutdown();
        cpu_free(&cpu);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
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

    while (running) {
        s_total_frames++;
        s_current_frame_num++;
        Uint32 frame_start_ticks = SDL_GetTicks();

        // Auto-exit de teste removido para garantir que a janela fique aberta continuamente

        // Poll OS events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE) {
                    input_inject_button(PAD_BUTTON_START);
                    s_user_confirmed_dlg = true;
                }
                if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_j) {
                    input_inject_button(PAD_BUTTON_A);
                    s_user_confirmed_dlg = true;
                }
                if (event.key.keysym.sym == SDLK_x || event.key.keysym.sym == SDLK_k) {
                    input_inject_button(PAD_BUTTON_B);
                }
                if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_c || event.key.keysym.sym == SDLK_u) {
                    input_inject_button(PAD_BUTTON_X);
                }
                if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_v || event.key.keysym.sym == SDLK_i) {
                    input_inject_button(PAD_BUTTON_Y);
                }
            }
        }

        // Auto-inject removido — apenas input real do usuario avanca as telas.

        // Poll Input (Keyboard + Game Controller + Injected)
        input_poll();

        // 1-line debug log requested by user when any button is pressed:
        const NativePadState* p0 = input_get_pad(0);
        static u16 s_last_logged_button = 0;
        if (p0->button != 0 && p0->button != s_last_logged_button) {
            printf("[INPUT] Botao pressionado! Mask=0x%04X\n", p0->button);
            fflush(stdout);
        }
        s_last_logged_button = p0->button;

        // Permite que qualquer botao real (Controle fisico ou Teclado) confirme dialogos
        if (p0->button & (PAD_BUTTON_A | PAD_BUTTON_START | PAD_BUTTON_B | PAD_BUTTON_X)) {
            s_user_confirmed_dlg = true;
        }

        // Controller 0 State synchronization (0x8038C1BC)
        u32 pad0_base = 0x8038C1BCu;
        mem_write32(&cpu, pad0_base + 140, 1); // Device connected flag (1 = connected)
        mem_write32(&cpu, pad0_base + 12, p0->button); // buttons held
        mem_write32(&cpu, pad0_base + 16, p0->button); // buttons pressed (trig)

        // Stick floats (-1.0f to +1.0f)
        float stick_x = (float)p0->stick_x / 100.0f;
        float stick_y = (float)p0->stick_y / 100.0f;
        mem_write32(&cpu, pad0_base + 20, f32_to_u32_bits(stick_x));
        mem_write32(&cpu, pad0_base + 24, f32_to_u32_bits(stick_y));

        // Float pressures checked by IsAnyButtonPressed (0x800FF4C8):
        float press_a     = (p0->button & PAD_BUTTON_A)     ? 1.0f : 0.0f;
        float press_b     = (p0->button & PAD_BUTTON_B)     ? 1.0f : 0.0f;
        float press_x     = (p0->button & PAD_BUTTON_X)     ? 1.0f : 0.0f;
        float press_y     = (p0->button & PAD_BUTTON_Y)     ? 1.0f : 0.0f;
        float press_start = (p0->button & PAD_BUTTON_START) ? 1.0f : 0.0f;
        float press_l     = (p0->button & PAD_TRIGGER_L)     ? 1.0f : 0.0f;
        float press_r     = (p0->button & PAD_TRIGGER_R)     ? 1.0f : 0.0f;

        mem_write32(&cpu, pad0_base + 28, f32_to_u32_bits(press_start));
        mem_write32(&cpu, pad0_base + 32, f32_to_u32_bits(press_a));
        mem_write32(&cpu, pad0_base + 36, f32_to_u32_bits(press_a));
        mem_write32(&cpu, pad0_base + 40, f32_to_u32_bits(press_b));
        mem_write32(&cpu, pad0_base + 44, f32_to_u32_bits(press_x));
        mem_write32(&cpu, pad0_base + 48, f32_to_u32_bits(press_y));
        mem_write32(&cpu, pad0_base + 52, f32_to_u32_bits(press_start));
        mem_write32(&cpu, pad0_base + 56, f32_to_u32_bits(press_l));
        mem_write32(&cpu, pad0_base + 60, f32_to_u32_bits(press_r));

        for (u32 p = 1; p < 4; p++) {
            u32 p_base = pad0_base + p * 156;
            for (u32 offset = 0; offset < 156; offset += 4) {
                mem_write32(&cpu, p_base + offset, 0);
            }
        }

        // Trigger 60Hz VBLANK (VI Retrace)
        video_trigger_vblank(&cpu);

        // HLE V-Sync Message Queue signal for queue 0x803BFD3C
        u32 wait_queue = mem_read32(&cpu, 0x803B3050u + 0x2DC);
        u16 main_state = mem_read16(&cpu, 0x803B3050u + 0x2C8);
        if (wait_queue == 0x803BFD3Cu || main_state == 4) {
            mem_write16(&cpu, 0x803B3050u + 0x2C8, 2); // OS_THREAD_STATE_RUNNING
            cpu.msr |= 0x8000u; // Ensure MSR[EE] is enabled when waking DefThread
            mem_write32(&cpu, 0x803B3050u + 0x2DC, 0); // clear queue pointer
            mem_write32(&cpu, 0x803BFD3Cu + 0x08, 0); // clear queue head
            mem_write32(&cpu, 0x803BFD3Cu + 0x0C, 0); // clear queue tail

            u32 msg_dest = mem_read32(&cpu, 0x803B3050u + 0x2D8);
            if (msg_dest >= GC_RAM_BASE && msg_dest < GC_RAM_BASE + cpu.ram_size) {
                mem_write32(&cpu, msg_dest, 1);
            }
            cpu.gpr[3] = 1; // OSReceiveMessage returns TRUE
            static u32 s_wake_count = 0;
            if (s_wake_count++ < 5) {
                printf("[HLE V-Sync Wakeup #%u] Thread 0x803B3050 acordada da fila 0x803BFD3C! (PC=0x%08X)\n",
                       s_wake_count, cpu.pc);
                fflush(stdout);
            }
        }

        // Retrace pulse to engine to unblock buffer flip
        if (cpu.gpr[13] >= GC_RAM_BASE) {
            mem_write32(&cpu, cpu.gpr[13] - 0x7468, 0);
        }

        // Audio thread (0x80667F08) and DefThread (0x803B3050) scheduling synchronization:
        u32 cur_thread = mem_read32(&cpu, 0x800000E4u);
        u32 def_thread = mem_read32(&cpu, 0x800000DCu);
        if (cur_thread == 0x80667F08u) {
            u32 th_queue = mem_read32(&cpu, 0x80667F08u + 0x2DC);
            u16 th_state = mem_read16(&cpu, 0x80667F08u + 0x2C8);
            if (th_queue == 0x8035C3E0u || th_state == 4 || th_state == 1) {
                if (def_thread >= GC_RAM_BASE) {
                    save_thread_context(&cpu, cur_thread);
                    restore_thread_context(&cpu, def_thread);
                }
            }
        }

        // Execute game CPU slices (50,000 blocks per 60Hz frame = ~3,000,000 blocks/sec)
        for (int slice = 0; slice < 50000; slice++) {
            cpu.timebase += 14; // 40.5 MHz GameCube TimeBase (~700k ticks per 60Hz frame)

            // Pump OS messages regularly to keep Windows window responsive
            if ((slice & 2047) == 0) {
                SDL_PumpEvents();
                // If slice budget or frame time elapsed, avoid starving host window
                if (slice >= 15000 && (SDL_GetTicks() - frame_start_ticks) >= 15) {
                    break;
                }
            }

            // Deliver external interrupts (VI retrace, PE finish, etc.)
            if (cpu.pc == 0x802C7A44u) {
                u32 run_bits = (cpu.gpr[13] >= GC_RAM_BASE) ? mem_read32(&cpu, cpu.gpr[13] - 25512) : 0;
                if (run_bits == 0) {
                    // CPU idle loop waiting for external interrupt (V-Sync)
                    break;
                }
            }
            // DSP loop safety jump: prevent spinning on real hardware DSP polling
            if (cpu.pc >= 0x802BEFE0u && cpu.pc < 0x802BF114u) {
                cpu.pc = 0x802BF114u;
            }
            // Thread yield / sleep unblock: if stuck waiting on OSSleepThread with MSR=0
            if (cpu.pc == 0x802C7874u || cpu.pc == 0x8022BD44u) {
                u32 cur_th = mem_read32(&cpu, 0x800000E4u);
                u32 def_th = mem_read32(&cpu, 0x800000DCu);
                if (cur_th != def_th && def_th >= GC_RAM_BASE) {
                    save_thread_context(&cpu, cur_th);
                    restore_thread_context(&cpu, def_th);
                } else {
                    cpu.msr |= 0x8000u;
                }
            }
            if (cpu.pc >= 0x801CDFE4u && cpu.pc <= 0x801CE058u) {
                u32 node = (cpu.gpr[1] >= GC_RAM_BASE) ? mem_read32(&cpu, cpu.gpr[1] + 8) : 0;
                if (node == 0 || node < GC_RAM_BASE || node == cpu.gpr[23]) {
                    cpu.pc = 0x801CE05Cu;
                }
            }
            if (cpu.pc == 0x80212490u || cpu.pc == 0x80212494u) {
                u32 ev340 = cpu.gpr[30];
                if (ev340 == 0xFFFFFFFFu) {
                    cpu.pc = 0x802124D0u;
                }
            }
            if (cpu.pc == 0x802CF0F4u || cpu.pc == 0x802CF0ECu) {
                if (cpu.gpr[13] >= GC_RAM_BASE) {
                    mem_write8(&cpu, cpu.gpr[13] - 25320, 1);
                }
                cpu.pc = 0x802CF100u;
            }
            if (cpu.pc >= 0x802435BCu && cpu.pc <= 0x802435E8u) {
                if (cpu.gpr[13] >= GC_RAM_BASE) {
                    mem_write32(&cpu, cpu.gpr[13] - 0x7468, 0);
                }
                cpu.pc = 0x802435ECu;
                static u32 s_unblock_bc = 0;
                if (s_unblock_bc++ < 10 || (s_unblock_bc % 120 == 0)) {
                    printf("[Unblock 0x802435BC #%u] Liberando flip_flag e avancando para 0x802435EC!\n", s_unblock_bc);
                    fflush(stdout);
                }
            }
            if (cpu.pc == 0x80243C6Cu || cpu.pc == 0x80243C70u || cpu.pc == 0x80243C74u) {
                if (cpu.gpr[13] >= GC_RAM_BASE) {
                    mem_write32(&cpu, cpu.gpr[13] - 0x7468, 0);
                }
                cpu.pc = 0x80243C78u;
                static u32 s_unblock_c6c = 0;
                if (s_unblock_c6c++ < 10 || (s_unblock_c6c % 120 == 0)) {
                    printf("[Unblock 0x80243C6C #%u] Liberando flip_flag e avancando para 0x80243C78!\n", s_unblock_c6c);
                    fflush(stdout);
                }
            }
            if (cpu.pc == 0x80243D8Cu || cpu.pc == 0x80243D90u || cpu.pc == 0x80243D94u) {
                if (cpu.gpr[13] >= GC_RAM_BASE) {
                    mem_write32(&cpu, cpu.gpr[13] - 0x7468, 0);
                }
                cpu.pc = 0x80243D98u;
                static u32 s_unblock_d8c = 0;
                if (s_unblock_d8c++ < 10 || (s_unblock_d8c % 120 == 0)) {
                    printf("[Unblock 0x80243D8C #%u] Liberando flip_flag e avancando para 0x80243D98!\n", s_unblock_d8c);
                    fflush(stdout);
                }
            }
            if (cpu.pc == 0x80243E00u) {
                static u32 s_e00_count = 0;
                if (s_e00_count++ < 10 || (s_e00_count % 60 == 0)) {
                    u32 cur_idx = (cpu.gpr[13] >= GC_RAM_BASE) ? mem_read32(&cpu, cpu.gpr[13] - 0x6748) : 0;
                    printf("[Engine Buffer Flip 0x80243E00 #%u] idx=%u -> %u\n", s_e00_count, cur_idx, cur_idx ^ 1);
                    fflush(stdout);
                }
            }
            video_poll_interrupt(&cpu);

            if (cpu.pc == 0x802A495Cu) {
                // AX Audio Frame Sync callback simulation (matches 0x802A4818)
                mem_write32(&cpu, cpu.gpr[13] - 26092, 1);
            }
            if (cpu.pc == 0x802DCED8u) {
                static int s_retrace_count = 0;
                if (s_retrace_count < 5) {
                    s_retrace_count++;
                    printf("[VIRetraceHandler ENTER #%d] r1=0x%08X r13=0x%08X\n", s_retrace_count, cpu.gpr[1], cpu.gpr[13]);
                    fflush(stdout);
                }
            }
            if (cpu.pc == 0x802C397Cu) {
                static int s_discard_count = 0;
                if (s_discard_count < 5) {
                    s_discard_count++;
                    printf("[INT DISCARD #%d] r4=0x%08X r31=0x%08X\n", s_discard_count, cpu.gpr[4], cpu.gpr[31]);
                    fflush(stdout);
                }
            }

            u32 prev_pc = cpu.pc;
            if (!dolrecomp_run_blocks(&cpu, 1)) {
                if (cpu.exception & PPC_EXC_SYSTEM_CALL) {
                    cpu.exception &= ~PPC_EXC_SYSTEM_CALL;
                    cpu.pc = cpu.srr0;
                    total_blocks++;
                    continue;
                }
                if ((cpu.exception & PPC_EXC_FP_UNAVAILABLE) || cpu.pc == 0x00000800u || cpu.pc == 0x80000800u) {
                    cpu.exception &= ~PPC_EXC_FP_UNAVAILABLE;
                    cpu.msr |= 0x00002000u; // Enable MSR[FP] (Lazy FPU activation)
                    cpu.pc = cpu.srr0;
                    total_blocks++;
                    continue;
                }
                static u32 s_unmapped_cnt = 0;
                if (s_unmapped_cnt++ < 25) {
                    printf("[UNMAPPED #%u] PC=0x%08X (prev_pc=0x%08X, LR=0x%08X SP=0x%08X)\n",
                           s_unmapped_cnt, cpu.pc, prev_pc, cpu.lr, cpu.gpr[1]);
                    fflush(stdout);
                }
                if (cpu.lr >= GC_RAM_BASE && cpu.lr < (GC_RAM_BASE + cpu.ram_size) && cpu.lr != cpu.pc) {
                    cpu.pc = cpu.lr;
                    total_blocks++;
                    continue;
                }
                u32 stack_lr = (cpu.gpr[1] >= GC_RAM_BASE && (cpu.gpr[1] - GC_RAM_BASE + 8) <= cpu.ram_size) ?
                               mem_read32(&cpu, cpu.gpr[1] + 4) : 0;
                if (stack_lr >= GC_RAM_BASE && stack_lr < (GC_RAM_BASE + cpu.ram_size) && stack_lr != cpu.pc) {
                    cpu.pc = stack_lr;
                    total_blocks++;
                    continue;
                }
                // Advance past invalid instruction instead of breaking and closing/freezing
                cpu.pc = (prev_pc >= GC_RAM_BASE) ? (prev_pc + 4) : (cpu.pc + 4);
                total_blocks++;
                continue;
            }
            total_blocks++;
        }

        // Process GPU FIFO commands
        gx_pipe_process_frame(&cpu);

        // Preserve canonical XFB address captured from GXCopyDisp (0x804F26A0)
        if (video_get_xfb_addr() < 0x804F0000u && cpu.gpr[13] >= GC_RAM_BASE) {
            u32 px0 = mem_read32(&cpu, cpu.gpr[13] - 0x6784);
            u32 px1 = mem_read32(&cpu, cpu.gpr[13] - 0x6780);
            u32 idx = mem_read32(&cpu, cpu.gpr[13] - 0x6748);
            u32 target = (idx == 1 && px1 >= 0x80300000u) ? px1 : px0;
            if (target >= 0x80300000u) {
                video_set_xfb_addr(target);
            }
        }

        static u32 s_ana_count = 0;
        if (s_ana_count++ < 3 || (s_ana_count % 60 == 0)) {
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

        if (frame_count <= 5) {
            printf("[DEBUG] Frame %u: PC=0x%08X LR=0x%08X msr=0x%08X ctx=0x%08X\n",
                   frame_count, cpu.pc, cpu.lr, cpu.msr, mem_read32(&cpu, 0x800000D4u));
            fflush(stdout);
        }

        frame_count++;

        // Clear screen with pure black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int w, h;
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
        video_present_frame(renderer, &cpu, w, h);

        // Render extracted 2D primitives directly to the SDL2 renderer
        int game_h = h - 40;
        int game_w = (game_h * 4) / 3;
        int game_x = (w - game_w) / 2;
        int game_y = 20;
        gx_pipe_render_to_sdl(renderer, &cpu, game_x, game_y, game_w, game_h);

        static u64 s_last_fifo_bytes = 0;
        static u32 s_last_draws = 0;
        u64 cur_fifo_bytes = gx_pipe_get_total_bytes();
        u32 cur_draws = gx_pipe_get_draw_calls();
        if (cur_fifo_bytes != s_last_fifo_bytes || cur_draws != s_last_draws) {
            printf("[FIFO Activity Frame %u] Total Bytes=%llu (+%llu), Draws=%u (+%u)\n",
                   frame_count, cur_fifo_bytes, cur_fifo_bytes - s_last_fifo_bytes,
                   cur_draws, cur_draws - s_last_draws);
            fflush(stdout);
            s_last_fifo_bytes = cur_fifo_bytes;
            s_last_draws = cur_draws;
        }

        static int s_sshot_taken = 0;
        s_sshot_taken++;
        if (s_sshot_taken == 30 || s_sshot_taken == 60 || s_sshot_taken == 100 || s_sshot_taken == 150 || s_sshot_taken == 200 || s_sshot_taken == 220 || s_sshot_taken == 240 || s_sshot_taken == 260 || s_sshot_taken == 280 || s_sshot_taken == 300 || s_sshot_taken == 400 || s_sshot_taken == 500 || s_sshot_taken == 600) {
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

        SDL_RenderPresent(renderer);

        // Frame timing cap for 60 FPS (16.6 ms per frame)
        Uint32 elapsed = SDL_GetTicks() - frame_start_ticks;
        if (elapsed < 16) {
            SDL_Delay(16 - elapsed);
        }

        // Update window title with FPS and executed blocks every second
        Uint32 current_time = SDL_GetTicks();
        if (current_time - start_time >= 1000) {
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
            fflush(stdout);
            frame_count = 0;
            start_time = current_time;
        }
    }

    gx_pipe_shutdown();
    input_shutdown();
    video_audio_shutdown();
    dvd_vfs_shutdown();
    cpu_free(&cpu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}