#include "video_audio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _MSC_VER
#define BSWAP32(x) _byteswap_ulong(x)
#else
#define BSWAP32(x) __builtin_bswap32(x)
#endif

// Video State
static SDL_Texture* s_xfb_texture = NULL;
static u8 s_vi_regs[128] = {0};
static u32 s_pi_cause = 0x00010000u; // DOL_PI_CAUSE_RST_BUTTON (unpressed by default)
static u32 s_pi_mask = 0;
static u32 s_xfb_addr = 0;
static u16 s_v_beam = 0;
static bool s_has_rendered_any_frame = false;
static u32 s_vblank_count = 0;
static u32 s_interrupt_count = 0;

static u64 read_reg(const u8* regs, u32 off, u8 size) {
    u64 value = 0;
    for (u8 i = 0; i < size; i++)
        value = (value << 8) | regs[off + i];
    return value;
}

static void write_reg(u8* regs, u32 off, u8 size, u64 value) {
    for (u8 i = 0; i < size; i++)
        regs[off + (size - 1u - i)] = (u8)(value >> (8u * i));
}

static void sync_vi_cause(void) {
    u8 di0 = s_vi_regs[0x30];
    // DOL_VI_DI0_STATUS_BIT = 0x80, DOL_VI_DI0_MASK_BIT = 0x10
    if ((di0 & 0x80u) && (di0 & 0x10u)) {
        s_pi_cause |= 0x00000100u; // DOL_PI_CAUSE_VI
    } else {
        s_pi_cause &= ~0x00000100u;
    }
}

// Audio State
static SDL_AudioDeviceID s_audio_dev = 0;
static u32 s_ai_regs[16] = {0};
static u32 s_ai_dma_addr = 0;
static u32 s_ai_dma_len = 0;

bool video_audio_init(SDL_Renderer* renderer) {
    // 1. Create XFB Streaming Texture (GameCube 640x480 standard YUY2)
    s_xfb_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_YUY2,
        SDL_TEXTUREACCESS_STREAMING,
        640, 480
    );

    if (!s_xfb_texture) {
        printf("[Video] Aviso: Falha ao criar textura YUY2 (%s), tentando RGB565...\n", SDL_GetError());
        s_xfb_texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGB565,
            SDL_TEXTUREACCESS_STREAMING,
            640, 480
        );
    }

    if (s_xfb_texture) {
        printf("[Video Blitter] Textura de Framebuffer XFB criada (640x480).\n");
    }

    // 2. Initialize SDL Audio Output
    SDL_AudioSpec wanted, have;
    SDL_zero(wanted);
    wanted.freq = 48000;              // 48 kHz GameCube standard
    wanted.format = AUDIO_S16MSB;      // Big-Endian 16-bit PCM (nativo do GameCube!)
    wanted.channels = 2;              // Stereo
    wanted.samples = 1024;

    s_audio_dev = SDL_OpenAudioDevice(NULL, 0, &wanted, &have, 0);
    if (s_audio_dev != 0) {
        SDL_PauseAudioDevice(s_audio_dev, 0); // Unpause
        printf("[Audio Driver] Dispositivo de som aberto com sucesso (%d Hz, Stereo, Big-Endian PCM).\n", have.freq);
    } else {
        printf("[Audio Driver] Aviso: Nao foi possivel abrir dispositivo de audio: %s\n", SDL_GetError());
    }

    return true;
}

// VI MMIO Handlers
u64 video_read_vi(CPUState* cpu, u32 reg_offset, u8 size) {
    if (reg_offset + size > 128 || size == 0) return 0;

    // Scanline / vertical beam register (0x2C..0x2D)
    if (reg_offset <= 0x2C && (reg_offset + size) >= 0x2E) {
        s_v_beam = (s_v_beam + 8) % 525;
        s_vi_regs[0x2C] = (u8)(s_v_beam >> 8);
        s_vi_regs[0x2D] = (u8)(s_v_beam & 0xFF);
    }

    sync_vi_cause();
    return read_reg(s_vi_regs, reg_offset, size);
}

void video_write_vi(CPUState* cpu, u32 reg_offset, u64 val, u8 size) {
    if (reg_offset + size > 128 || size == 0) return;

    static int s_vi_write_count = 0;
    if (s_vi_write_count < 30) {
        s_vi_write_count++;
        printf("[VI WRITE #%d] offset=0x%02X val=0x%llX size=%d\n", s_vi_write_count, reg_offset, val, size);
        fflush(stdout);
    }

    write_reg(s_vi_regs, reg_offset, size, val);

    // Check if DI0 was written
    if (reg_offset <= 0x30 && (reg_offset + size) > 0x30) {
        sync_vi_cause();
    }

    // Check if Framebuffer address registers (0x1C..0x1F or 0x24..0x27) were written
    if ((reg_offset >= 0x1C && reg_offset <= 0x1F) ||
        (reg_offset >= 0x24 && reg_offset <= 0x27)) {
        u32 tfb_hi = ((u32)s_vi_regs[0x1C] << 8) | (u32)s_vi_regs[0x1D];
        u32 tfb_lo = ((u32)s_vi_regs[0x1E] << 8) | (u32)s_vi_regs[0x1F];
        u32 tfb_val = (tfb_hi << 16) | tfb_lo;

        u32 bfb_hi = ((u32)s_vi_regs[0x24] << 8) | (u32)s_vi_regs[0x25];
        u32 bfb_lo = ((u32)s_vi_regs[0x26] << 8) | (u32)s_vi_regs[0x27];
        u32 bfb_val = (bfb_hi << 16) | bfb_lo;

        u32 fbb_val = (tfb_val != 0) ? tfb_val : bfb_val;
        if (fbb_val != 0 && (fbb_val & 0xFFFF) != 0) { // Require lower 16-bits to avoid intermediate writes
            u32 fbb = fbb_val & 0x00FFFFFFu;
            bool poff = (fbb_val & 0x10000000u) != 0;
            u32 real_addr = poff ? (fbb << 5) : fbb;

            if (real_addr != 0) {
                u32 resolved = (real_addr & 0x01FFFFFFu) | GC_RAM_BASE;
                if (resolved != s_xfb_addr) {
                    s_xfb_addr = resolved;
                    printf("[Video VI] Framebuffer ativo (XFB) configurado: 0x%08X (TFB=0x%08X, BFB=0x%08X)\n",
                           s_xfb_addr, tfb_val, bfb_val);
                    fflush(stdout);
                }
            }
        }
    }
}

// PI MMIO Handlers
u64 video_read_pi(CPUState* cpu, u32 reg_offset, u8 size) {
    sync_vi_cause();
    if (reg_offset == 0x00) return (u64)s_pi_cause;
    if (reg_offset == 0x04) return (u64)s_pi_mask;
    return 0;
}

void video_write_pi(CPUState* cpu, u32 reg_offset, u64 val, u8 size) {
    if (reg_offset == 0x00) {
        // Write-1-to-clear for PI cause
        s_pi_cause &= ~(u32)val;
        s_pi_cause |= 0x00010000u; // RST button unpressed bit is persistent
        return;
    }
    if (reg_offset == 0x04) {
        s_pi_mask = (u32)val;
        return;
    }
}

static bool s_interrupt_pending = false;

// 60Hz VBLANK and Interrupt Dispatch
void video_trigger_vblank(CPUState* cpu) {
    s_vblank_count++;
    s_interrupt_pending = true;
    s_vi_regs[0x30] |= 0x80u; // Assert DOL_VI_DI0_STATUS_BIT
    sync_vi_cause();
}

void video_trigger_pe_finish(void) {
    s_pi_cause |= 0x00000400u; // DOL_PI_CAUSE_PE_FINISH (Interrupt 19)
    s_interrupt_pending = true;
}

void video_trigger_pe_token(void) {
    s_pi_cause |= 0x00000200u; // DOL_PI_CAUSE_PE_TOKEN (Interrupt 18)
    s_interrupt_pending = true;
}

void video_poll_interrupt(CPUState* cpu) {
    // 1. Only deliver when an interrupt event occurred
    if (!s_interrupt_pending)
        return;

    sync_vi_cause();

    // Check thread state and scheduler loop
    u32 curr_thread = mem_read32(cpu, 0x800000E4u);
    u16 thread_state = (curr_thread >= GC_RAM_BASE && curr_thread < GC_RAM_BASE + cpu->ram_size)
                       ? mem_read16(cpu, curr_thread + 0x2C8) : 0;
    bool in_scheduler = (cpu->pc >= 0x802C30E8u && cpu->pc <= 0x802C3130u) ||
                        (cpu->pc >= 0x802C8600u && cpu->pc <= 0x802C8700u);
    bool can_dispatch = (cpu->msr & 0x8000u) != 0 || thread_state == 4 || in_scheduler;

    if (!can_dispatch)
        return;

    // Ensure PI mask doesn't block critical VI/PE interrupts while waiting
    if ((s_pi_cause & s_pi_mask) == 0u) {
        if (thread_state == 4 || in_scheduler) {
            s_pi_mask |= (s_pi_cause & 0x00000700u);
        } else {
            return;
        }
    }

    // 2. Current context established?
    u32 ctx = mem_read32(cpu, 0x800000D4u);
    if (ctx < GC_RAM_BASE || ctx > GC_RAM_BASE + cpu->ram_size - 0x2C8)
        return;

    // Acknowledge dispatch
    s_interrupt_pending = false;

    // 5. Save state to OSContext
    for (int i = 0; i < 32; i++)
        mem_write32(cpu, ctx + (u32)i * 4u, cpu->gpr[i]);
    mem_write32(cpu, ctx + 0x080u, cpu->cr);
    mem_write32(cpu, ctx + 0x084u, cpu->lr);
    mem_write32(cpu, ctx + 0x088u, cpu->ctr);
    mem_write32(cpu, ctx + 0x08Cu, cpu->xer);
    for (int i = 0; i < 32; i++) {
        u64 bits;
        memcpy(&bits, &cpu->fpr[i], sizeof(bits));
        mem_write64(cpu, ctx + 0x090u + (u32)i * 8u, bits);
    }
    mem_write32(cpu, ctx + 0x194u, cpu->fpscr);
    mem_write32(cpu, ctx + 0x198u, cpu->pc);
    mem_write32(cpu, ctx + 0x19Cu, cpu->msr);
    mem_write16(cpu, ctx + 0x1A2u, 0x0002u); // OS_CONTEXT_STATE_FPSAVED
    for (int i = 0; i < 8; i++)
        mem_write32(cpu, ctx + 0x1A4u + (u32)i * 4u, cpu->gqr[i]);

    // 6. Deliver to __OSDispatchInterrupt (0x802C365C)
    // s_pi_cause retains bit 8 (0x00000100) so __OSDispatchInterrupt sees the VI interrupt!
    cpu->gpr[3] = 4u; // EXC_EXTERNAL (__OS_EXCEPTION_EXTERNAL_INTERRUPT)
    cpu->gpr[4] = ctx;
    cpu->srr0 = cpu->pc;
    cpu->srr1 = cpu->msr;
    cpu->msr &= ~0x8000u; // Mask MSR_EE during handler execution
    cpu->pc = 0x802C365Cu;

    static int s_int_log_count = 0;
    if (s_int_log_count < 3) {
        s_int_log_count++;
        u32 os_mask = mem_read32(cpu, 0x800000C4u);
        u32 os_dis = mem_read32(cpu, 0x800000C8u);
        u32 tbl_ptr = mem_read32(cpu, cpu->gpr[13] - 25576);
        u32 vi_handler = (tbl_ptr >= GC_RAM_BASE) ? mem_read32(cpu, tbl_ptr + 24 * 4) : 0;
        printf("[INT DISPATCH #%d] PI_cause=0x%08X PI_mask=0x%08X OSMask=0x%08X OSDis=0x%08X tbl=0x%08X VI_Handler[24]=0x%08X\n",
               s_int_log_count, s_pi_cause, s_pi_mask, os_mask, os_dis, tbl_ptr, vi_handler);
        printf("  Tabela de Handlers:");
        for (int i = 0; i < 32; i++) {
            u32 h = (tbl_ptr >= GC_RAM_BASE) ? mem_read32(cpu, tbl_ptr + i * 4) : 0;
            if (h != 0) printf(" [%d]=0x%08X", i, h);
        }
        printf("\n");
        fflush(stdout);
    }

    s_interrupt_count++;
}

u32 video_get_vblank_count(void) {
    return s_vblank_count;
}

u32 video_get_interrupt_count(void) {
    return s_interrupt_count;
}

static u32 s_dsp_mail = 0x88880000u; // Initial startup response mail

// AI MMIO Handlers
u64 audio_read_ai(CPUState* cpu, u32 reg_offset, u8 size) {
    // 0xCC005000 (DSP_MAIL_TO_DSP_HI/LO) - Host consumes mail instantly, mailbox is always ready
    if (reg_offset == 0x00 || reg_offset == 0x02) {
        return 0;
    }
    // 0xCC005004 (DSP_MAIL_FROM_DSP_HI)
    if (reg_offset == 0x04) {
        // DSP Mailbox From DSP: return 0x8888 (with bit 15 set) to satisfy mail checks
        return (size == 4) ? 0x88880000u : 0x8888u;
    }
    // 0xCC005006 (DSP_MAIL_FROM_DSP_LO)
    if (reg_offset == 0x06) {
        return 0;
    }

    // DSP Control/Status Register (0xCC00500A): bit 0 is DSP_RESET (0 = complete), bit 5 is DSP_INIT (1 = init complete)
    if ((reg_offset & 0x0E) == 0x0A) {
        u32 idx = (reg_offset & 0x3F) >> 2;
        return (s_ai_regs[idx] & ~0x00010001u) | 0x00200020u;
    }

    // AI Control Register (AICR: 0xCC005014 / 0xCC005016): bit 0 (PSTAT) = 1 indicates active playback
    if (reg_offset == 0x14 || reg_offset == 0x16) {
        u32 aicr = s_ai_regs[0x14 >> 2] | 0x00000001u;
        if (reg_offset == 0x16 && size == 2) {
            return (u16)(aicr & 0xFFFF);
        }
        return (size == 4) ? aicr : (aicr >> 16);
    }

    u32 idx = (reg_offset & 0x3F) >> 2;
    return s_ai_regs[idx];
}

void audio_write_ai(CPUState* cpu, u32 reg_offset, u64 val, u8 size) {
    u32 idx = (reg_offset & 0x3F) >> 2;
    // Host completes DSP reset synchronously: bit 0 (DSP_RESET) clears immediately
    if ((reg_offset & 0x0E) == 0x0A) {
        val &= ~0x00010001u;
    }
    s_ai_regs[idx] = (u32)val;

    // When CPU writes to DSP Mailbox (0x5000 / 0x5002), acknowledge with reply
    if (reg_offset == 0x00 || reg_offset == 0x02) {
        s_dsp_mail = 0x88880000u;
    }

    if (reg_offset == 0x14) {
        s_ai_dma_addr = (u32)val;
    } else if (reg_offset == 0x18) {
        // AILEN: length in 32-byte blocks
        s_ai_dma_len = ((u32)val & 0x7FFF) * 32;

        static u32 s_ai_dma_count = 0;
        if (s_ai_dma_count++ < 10 || (s_ai_dma_count % 60 == 0)) {
            printf("[Audio DMA #%u] addr=0x%08X len=%u bytes\n", s_ai_dma_count, s_ai_dma_addr, s_ai_dma_len);
            fflush(stdout);
        }

        // If playing and we have valid samples, queue them to SDL Audio
        if (s_audio_dev != 0 && s_ai_dma_len > 0 && s_ai_dma_addr >= GC_RAM_BASE) {
            u32 ram_offset = s_ai_dma_addr - GC_RAM_BASE;
            if (ram_offset + s_ai_dma_len <= cpu->ram_size) {
                SDL_QueueAudio(s_audio_dev, cpu->ram + ram_offset, s_ai_dma_len);
            }
        }
    }
}

void video_present_frame(SDL_Renderer* renderer, CPUState* cpu, int window_w, int window_h) {
    // 4:3 aspect ratio viewport
    int game_h = window_h - 40;
    int game_w = (game_h * 4) / 3;
    int game_x = (window_w - game_w) / 2;
    int game_y = 20;
    SDL_Rect dest_rect = { game_x, game_y, game_w, game_h };

    // If an XFB buffer address is known, upload and draw it!
    if (s_xfb_texture && s_xfb_addr >= 0x80300000u) {
        u32 offset = s_xfb_addr - GC_RAM_BASE;
        u32 fb_size = 640 * 480 * 2; // YUYV 2 bytes per pixel

        if (offset + fb_size <= cpu->ram_size) {
            u8* fb_pixels = cpu->ram + offset;

            // Pitch calculation: GameCube VI STD register (0x70) or default 640 * 2
            int pitch = 640 * 2;
            u32 std_val = (u32)s_vi_regs[0x70];
            if (std_val >= 20 && std_val <= 80) {
                pitch = (int)(std_val * 32);
            }

            // In YUY2, all-zero bytes (U=0, V=0) render as solid neon green.
            // Check if buffer is completely zeroed (e.g. freshly cleared RAM after Loading).
            // If empty, do not blit green texture over screen; leave clean black background.
            bool has_content = false;
            for (u32 i = 0; i < fb_size; i += 64) {
                if (fb_pixels[i] != 0 || fb_pixels[i + 1] != 0 || fb_pixels[i + 2] != 0 || fb_pixels[i + 3] != 0) {
                    has_content = true;
                    break;
                }
            }
            if (!has_content) {
                return;
            }

            // Sanitize any remaining unwritten / zero-chroma pixels so they render as black (U=0x80, V=0x80)
            for (u32 i = 0; i < fb_size; i += 4) {
                if (fb_pixels[i + 1] == 0 && fb_pixels[i + 3] == 0) {
                    fb_pixels[i + 1] = 0x80; // neutral U
                    fb_pixels[i + 3] = 0x80; // neutral V
                }
            }

            SDL_UpdateTexture(s_xfb_texture, NULL, fb_pixels, pitch);
            SDL_RenderCopy(renderer, s_xfb_texture, NULL, &dest_rect);
            if (!s_has_rendered_any_frame) {
                s_has_rendered_any_frame = true;
                printf("[Video Blitter] PRIMEIRO QUADRO DO JOGO RENDERIZADO COM SUCESSO NA JANELA SDL2! (XFB=0x%08X, pitch=%d)\n",
                       s_xfb_addr, pitch);
                fflush(stdout);
            }
            return;
        }
    }

    // Default: dark stylish canvas with GameCube border
    SDL_SetRenderDrawColor(renderer, 10, 14, 20, 255);
    SDL_RenderFillRect(renderer, &dest_rect);
    SDL_SetRenderDrawColor(renderer, 0, 180, 216, 255);
    SDL_RenderDrawRect(renderer, &dest_rect);
}

void video_set_xfb_addr(u32 addr) {
    // Accept genuine framebuffer allocations in data/heap RAM (>= 0x80300000, up to 48MB RAM)
    if (addr >= 0x80300000u && (addr - GC_RAM_BASE + 640 * 480 * 2) <= 0x03000000u) {
        if (s_xfb_addr != addr) {
            s_xfb_addr = addr;
            printf("[Video VI] Framebuffer ativo (XFB) configurado: 0x%08X\n", s_xfb_addr);
            fflush(stdout);
        }
    }
}

u32 video_get_xfb_addr(void) {
    return s_xfb_addr;
}

void video_audio_shutdown(void) {
    if (s_audio_dev != 0) {
        SDL_CloseAudioDevice(s_audio_dev);
        s_audio_dev = 0;
    }
    if (s_xfb_texture) {
        SDL_DestroyTexture(s_xfb_texture);
        s_xfb_texture = NULL;
    }
}
