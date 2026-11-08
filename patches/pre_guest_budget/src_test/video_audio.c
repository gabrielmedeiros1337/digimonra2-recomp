#include "video_audio.h"
#include "gx_pipe.h"
#include "ax_hle.h"
#include "os_context.h"
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
static u32 s_pending_xfb_addr;
static u32 s_xfb_width = 640, s_xfb_height = 480, s_xfb_pitch = 1280;
static u32 s_texture_width = 640, s_texture_height = 480;
static bool s_rgb_fallback;
static bool s_pe_finish, s_pe_token;
static u32 s_pe_enable;

static u16 s_v_beam = 0;
static bool s_has_rendered_any_frame = false;
static u32 s_vblank_count = 0;
static u32 s_interrupt_count = 0;
static void poll_dsp_mail(CPUState* cpu);

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
    s_pi_cause &= ~0x600u;
    if (s_pe_token && (s_pe_enable & 1u)) s_pi_cause |= 0x200u;
    if (s_pe_finish && (s_pe_enable & 2u)) s_pi_cause |= 0x400u;
}

// Audio State
static SDL_AudioDeviceID s_audio_dev = 0;
static u8 s_ai_interface[0x20];
static u64 s_audio_last_timebase, s_ai_counter_timebase, s_ai_counter_phase;
static u64 s_dma_phase;
static u32 s_dma_cursor;
static u32 s_dma_address, s_dma_length;
static SDL_AudioStream* s_audio_stream;
static u32 s_audio_rate;
static u64 s_audio_bytes, s_audio_nonzero;


bool video_audio_init(SDL_Renderer* renderer) {
    char* base=SDL_GetBasePath();
    if(base) {
        char coefficients[1024];snprintf(coefficients,sizeof(coefficients),"%sdsp_coef.bin",base);
        bool loaded=ax_hle_load_coefficients(coefficients);
        printf("[AX SRC] %s\n",loaded ? "Polyphase coefficients loaded" : "Coefficients unavailable; linear fallback");
        SDL_free(base);
    }
    // 1. Create XFB Streaming Texture (GameCube 640x480 standard YUY2)
    s_xfb_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_YUY2,
        SDL_TEXTUREACCESS_STREAMING,
        640, 480
    );

    if (!s_xfb_texture) {
        printf("[Video] Aviso: Falha ao criar textura YUY2 (%s), tentando ARGB8888...\n", SDL_GetError());
        s_rgb_fallback = true;
        s_xfb_texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
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

    // VI registers hold a physical address; bit 28 selects 32-byte units.
    // Latch scanout at retrace, not on intermediate halfword writes.
    if (reg_offset < 0x28 && reg_offset + size > 0x1C) {
        u32 value = (u32)read_reg(s_vi_regs, 0x1C, 4);
        if (!value) value = (u32)read_reg(s_vi_regs, 0x24, 4);
        u32 address = value & 0xFFFFFFu;
        if (value & 0x10000000u) address <<= 5;
        if (address < cpu->ram_size) s_pending_xfb_addr = address | GC_RAM_BASE;
    }
}

// PI MMIO Handlers
u64 video_read_pi(CPUState* cpu, u32 reg_offset, u8 size) {
    sync_vi_cause();
    if (reg_offset == 0x00) return (u64)s_pi_cause;
    if (reg_offset == 0x04) return (u64)s_pi_mask;
    if (reg_offset >= 0x0C && reg_offset <= 0x14) return gx_pipe_read_pi(reg_offset);
    return 0;
}

void video_write_pi(CPUState* cpu, u32 reg_offset, u64 val, u8 size) {
    if (reg_offset >= 0x0C && reg_offset <= 0x14) { gx_pipe_write_pi(reg_offset, (u32)val); return; }
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
    audio_tick(cpu);
    if (s_pending_xfb_addr) s_xfb_addr = s_pending_xfb_addr;
    s_interrupt_pending = true;
    s_vi_regs[0x30] |= 0x80u; // Assert DOL_VI_DI0_STATUS_BIT
    sync_vi_cause();
}

void video_trigger_pe_finish(void) {
    s_pe_finish = true;
    sync_vi_cause();
    s_pi_cause |= 0u; // DOL_PI_CAUSE_PE_FINISH (Interrupt 19)
    s_interrupt_pending = true;
}

void video_trigger_pe_token(void) {
    s_pe_token = true;
    sync_vi_cause();
    s_pi_cause |= 0u; // DOL_PI_CAUSE_PE_TOKEN (Interrupt 18)
    s_interrupt_pending = true;
}

void video_poll_interrupt(CPUState* cpu) {
    poll_dsp_mail(cpu);
    sync_vi_cause();
    if (!(cpu->msr & 0x8000u) || !(s_pi_cause & s_pi_mask & ~0x10000u)) return;

    // 2. Current context established?
    u32 ctx = mem_read32(cpu, 0x800000D4u);
    if (ctx < GC_RAM_BASE || ctx > GC_RAM_BASE + cpu->ram_size - 0x2C8)
        return;

    // Causes remain asserted until each device handler acknowledges them.

    // 5. Save state to OSContext
    for (int i = 0; i < 32; i++)
        mem_write32(cpu, ctx + (u32)i * 4u, cpu->gpr[i]);
    mem_write32(cpu, ctx + 0x080u, cpu->cr);
    mem_write32(cpu, ctx + 0x084u, cpu->lr);
    mem_write32(cpu, ctx + 0x088u, cpu->ctr);
    mem_write32(cpu, ctx + 0x08Cu, cpu->xer);
    // FPU registers belong to OS_CURRENT_FPU_CONTEXT (D8), not necessarily D4.
    // The FP-unavailable path performs the lazy save/restore when an IRQ uses FP.
    mem_write32(cpu, ctx + 0x198u, cpu->pc);
    mem_write32(cpu, ctx + 0x19Cu, cpu->msr);
    mem_write16(cpu, ctx + 0x1A2u, (u16)(mem_read16(cpu,ctx+0x1A2u)|2u)); // EXC; preserve FPSAVED bit 0
    for (int i = 0; i < 8; i++)
        mem_write32(cpu, ctx + 0x1A4u + (u32)i * 4u, cpu->gqr[i]);

    // 6. Deliver to __OSDispatchInterrupt (0x802C365C)
    // s_pi_cause retains bit 8 (0x00000100) so __OSDispatchInterrupt sees the VI interrupt!
    cpu->gpr[3] = 4u; // EXC_EXTERNAL (__OS_EXCEPTION_EXTERNAL_INTERRUPT)
    cpu->gpr[4] = ctx;
    cpu->srr0 = cpu->pc;
    cpu->srr1 = cpu->msr;
    cpu->msr &= ~(0x8000u|0x2000u); // Hardware exception entry clears EE and FP
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

// DSP/ARAM registers are byte addressed, big endian, and commonly written as
// halfwords. ARQ transfers use auxiliary RAM, not DVD offsets or MRAM handles.
static u8 s_dsp_regs[0x100];
static u8 s_aram[16 * 1024 * 1024];
static u16 s_dsp_control;
static u32 s_dsp_mail;
static u32 s_dsp_parameter;
static bool s_dsp_task_loaded, s_dsp_command_address;
static u32 s_dsp_command_words, s_dsp_deferred_mail;
static u64 s_dsp_mail_due;

static void sync_dsp_interrupt(void) {
    if ((s_dsp_control & (s_dsp_control >> 1) & 0xA8u) != 0) s_pi_cause |= 0x40u;
    else s_pi_cause &= ~0x40u;
}
static void poll_dsp_mail(CPUState* cpu) {
    if (s_dsp_deferred_mail && cpu->timebase >= s_dsp_mail_due && !(s_dsp_mail & 0x80000000u)) {
        s_dsp_mail = s_dsp_deferred_mail; s_dsp_deferred_mail = 0;
        s_dsp_control |= 0x80u; sync_dsp_interrupt();
    }
}
u64 audio_read_ai(CPUState* cpu, u32 off, u8 size) {
    poll_dsp_mail(cpu);
    if (!size || off + size > sizeof(s_dsp_regs)) return 0;
    if (off == 0 || off == 2) return 0;
    if (off == 4) {
        u32 value = s_dsp_mail;
        if (size == 4) { s_dsp_mail &= ~0x80000000u; return value; }
        return value >> 16;
    }
    if (off == 6) { u32 value = s_dsp_mail & 0xFFFFu; s_dsp_mail &= ~0x80000000u; return value; }
    if (off == 0xA) return s_dsp_control;
    if (off == 0x16) return 1; // ARAM controller initialized
    return read_reg(s_dsp_regs, off, size);
}
void audio_write_ai(CPUState* cpu, u32 off, u64 value, u8 size) {
    if (!size || off + size > sizeof(s_dsp_regs)) return;
    if (off == 0xA) {
        u16 previous = s_dsp_control;
        u16 flags = (u16)(s_dsp_control & 0xA8u & ~(u16)value);
        s_dsp_control = (u16)(((u16)value & ~0xAA9u) | flags);
        if ((previous & 4u) && !(value & 4u)) s_dsp_mail = 0x8071FEEDu;
        sync_dsp_interrupt();
        return;
    }
    u32 previous_dma = (u32)read_reg(s_dsp_regs, 0x36, 2);
    write_reg(s_dsp_regs, off, size, value);
    if (off <= 2 && off + size >= 4) {
        u32 mail = (u32)read_reg(s_dsp_regs, 0, 4);
        if (!s_dsp_task_loaded) {
            if (s_dsp_parameter) {
                if (s_dsp_parameter == 0x80F3D001u) {
                    s_dsp_task_loaded = true;
                    s_dsp_mail = 0xDCD10000u; s_dsp_control |= 0x80u;
                }
                s_dsp_parameter = 0;
            } else if ((mail & 0xFFFF0000u) == 0x80F30000u) s_dsp_parameter = mail;
        } else if (s_dsp_command_address) {
            s_dsp_command_address = false;
            bool ok = ax_hle_execute(cpu, s_aram, (u32)sizeof(s_aram), mail, s_dsp_command_words);
            if (ok) { s_dsp_deferred_mail = 0xDCD10002u; s_dsp_mail_due = cpu->timebase + 208; }
            else fprintf(stderr, "[AX] Command list failed at %08X words=%u\n", mail, s_dsp_command_words);
        } else if ((mail & 0xFFFF0000u) == 0xBABE0000u) {
            s_dsp_command_words = mail & 0xFFFFu; s_dsp_command_address = true;
        }
        else if (mail == 0xCDD10000u) { s_dsp_mail = 0xDCD10001u; s_dsp_control |= 0x80u; }
        sync_dsp_interrupt();
    }
    if (off <= 0x2A && off + size >= 0x2C) {
        u32 main = (u32)read_reg(s_dsp_regs, 0x20, 4) & 0x3FFFFE0u;
        u32 aram = (u32)read_reg(s_dsp_regs, 0x24, 4) & 0x3FFFFE0u;
        u32 count = (u32)read_reg(s_dsp_regs, 0x28, 4);
        u32 length = count & 0x03FFFFE0u;
        if (main <= cpu->ram_size && length <= cpu->ram_size - main) {
            u32 mapped = aram < sizeof(s_aram) ? (u32)sizeof(s_aram) - aram : 0;
            if (mapped > length) mapped = length;
            if (count & 0x80000000u) {
                ppc_mark_host_write(cpu->ram+main,length);
                if (mapped) memcpy(cpu->ram + main, s_aram + aram, mapped);
                if (length > mapped) memset(cpu->ram + main + mapped, 0, length - mapped);
            } else if (mapped) memcpy(s_aram + aram, cpu->ram + main, mapped);
            if (!s_dsp_task_loaded) s_dsp_mail = 0x88880000u;
            s_dsp_control |= 0x20u;
            sync_dsp_interrupt();
        } else fprintf(stderr, "[ARAM DMA] Invalid transfer main=%08X aram=%08X length=%u\n", main, aram, length);
    }
    if (off <= 0x36 && off + size >= 0x38) {
        u32 dma = (u32)read_reg(s_dsp_regs,0x36,2);
        // Reprogramming an enabled DMA changes its NEXT buffer. It must not
        // rewind the active transfer or discard the fractional sample clock.
        if (!(previous_dma & 0x8000u) && (dma & 0x8000u)) {
            s_dma_address=(u32)read_reg(s_dsp_regs,0x30,4)&0x3FFFFE0u;
            s_dma_length=(dma&0x7FFFu)*32u;
            s_dma_cursor=0;s_dma_phase=0;
            u32 blocks=s_dma_length/32u;
            write_reg(s_dsp_regs,0x3A,2,blocks ? blocks-1u : 0);
        }
    }
}

static void sync_ai_interrupt(void) {
    u32 control = (u32)read_reg(s_ai_interface, 0, 4);
    if ((control & 12u) == 12u) s_pi_cause |= 0x80u;
    else s_pi_cause &= ~0x80u;
}
static void audio_update_counter(CPUState* cpu) {
    u64 elapsed = cpu->timebase >= s_ai_counter_timebase ? cpu->timebase - s_ai_counter_timebase : 0;
    s_ai_counter_timebase = cpu->timebase;
    u32 control = (u32)read_reg(s_ai_interface, 0, 4);
    if (!(control & 1u)) return;
    s_ai_counter_phase += elapsed * ((control & 2u) ? 48000u : 32000u);
    u32 samples = (u32)(s_ai_counter_phase / 40500000u);
    s_ai_counter_phase %= 40500000u;
    u32 old = (u32)read_reg(s_ai_interface, 8, 4), count = old + samples;
    write_reg(s_ai_interface, 8, 4, count);
    u32 threshold = (u32)read_reg(s_ai_interface, 12, 4);
    if (!(control & 16u) && threshold > old && threshold <= count) write_reg(s_ai_interface, 0, 4, control | 8u);
    sync_ai_interrupt();
}
u64 audio_read_interface(CPUState* cpu, u32 off, u8 size) {
    audio_update_counter(cpu);
    return size && off + size <= sizeof(s_ai_interface) ? read_reg(s_ai_interface, off, size) : 0;
}
void audio_write_interface(CPUState* cpu, u32 off, u64 value, u8 size) {
    audio_update_counter(cpu);
    if (!size || off + size > sizeof(s_ai_interface)) return;
    u32 previous = (u32)read_reg(s_ai_interface, 0, 4);
    write_reg(s_ai_interface, off, size, value);
    if (off < 4) {
        u32 control = (u32)read_reg(s_ai_interface, 0, 4);
        if (control & 32u) { write_reg(s_ai_interface, 8, 4, 0); s_ai_counter_phase = 0; }
        control = (control & ~40u) | (previous & 8u & ~(control & 8u));
        write_reg(s_ai_interface, 0, 4, control);
    }
    sync_ai_interrupt();
}
void audio_tick(CPUState* cpu) {
    u64 elapsed = cpu->timebase >= s_audio_last_timebase ? cpu->timebase - s_audio_last_timebase : 0;
    s_audio_last_timebase = cpu->timebase;
    if (elapsed > 4050000u) elapsed = 4050000u;
    u32 control = (u32)read_reg(s_ai_interface, 0, 4);
    u32 rate = (control & 64u) ? 32000u : 48000u;
    audio_update_counter(cpu);
    u32 dma = (u32)read_reg(s_dsp_regs, 0x36, 2);
    if (!(dma & 0x8000u) || !s_dma_length) return;
    s_dma_phase += elapsed * rate * 4u;
    // The hardware fetches eight stereo samples (32 bytes) per DMA tick.
    u32 consume = (u32)(s_dma_phase / 40500000u) & ~31u;
    s_dma_phase -= (u64)consume * 40500000u;
    if (s_audio_rate != rate && s_audio_dev) {
        if (s_audio_stream) SDL_FreeAudioStream(s_audio_stream);
        s_audio_stream = SDL_NewAudioStream(AUDIO_S16MSB, 2, (int)rate, AUDIO_S16MSB, 2, 48000);
        s_audio_rate = rate;
    }
    while (consume) {
        if (s_dma_address > cpu->ram_size || s_dma_length > cpu->ram_size-s_dma_address) break;
        u32 count = s_dma_length - s_dma_cursor; if (count > consume) count = consume;
        const u8* samples = cpu->ram + s_dma_address + s_dma_cursor;
        s_audio_bytes += count;
        for (u32 j=0; j<count; j++) if (samples[j]) s_audio_nonzero++;
        if (s_audio_stream && SDL_GetQueuedAudioSize(s_audio_dev) < 19200u) {
            u8 stereo[4096];
            for (u32 offset=0; offset<count;) {
                u32 chunk=count-offset; if (chunk>sizeof(stereo)) chunk=sizeof(stereo);
                for (u32 j=0;j<chunk;j+=4) {
                    stereo[j]=samples[offset+j+2]; stereo[j+1]=samples[offset+j+3];
                    stereo[j+2]=samples[offset+j]; stereo[j+3]=samples[offset+j+1];
                }
                SDL_AudioStreamPut(s_audio_stream,stereo,(int)chunk); offset+=chunk;
            }
        }
        s_dma_cursor += count; consume -= count;
        if (s_dma_cursor == s_dma_length) {
            s_dma_cursor=0;
            s_dma_address=(u32)read_reg(s_dsp_regs,0x30,4)&0x3FFFFE0u;
            s_dma_length=((u32)read_reg(s_dsp_regs,0x36,2)&0x7FFFu)*32u;
            s_dsp_control |= 8u; sync_dsp_interrupt();
            if(!s_dma_length)break;
        }
    }
    u32 remaining=(s_dma_length-s_dma_cursor)/32u;
    write_reg(s_dsp_regs, 0x3A, 2, remaining ? remaining-1u : 0);
    if (s_audio_stream) {
        u8 output[8192]; int count;
        while ((count = SDL_AudioStreamGet(s_audio_stream, output, sizeof(output))) > 0)
            SDL_QueueAudio(s_audio_dev, output, (u32)count);
    }
    static u32 logged_frame;
    bool log = s_vblank_count % 300u == 0 && logged_frame != s_vblank_count;
    if (log) logged_frame = s_vblank_count;
    if (log)
        printf("[Audio] dma=%08X rate=%u bytes=%llu nonzero=%llu queued=%u\n",
               s_dma_address | GC_RAM_BASE, rate, s_audio_bytes, s_audio_nonzero, s_audio_dev ? SDL_GetQueuedAudioSize(s_audio_dev) : 0);
    if (log) {
        const AXHleStats* stats=ax_hle_stats();
        printf("[AX stats] lists=%llu voices=%llu ended=%llu peak=%u\n", stats->lists,stats->voices,stats->ended,stats->peak);
    }
}

void video_set_di_interrupt(bool pending) {
    if (pending) s_pi_cause |= 4u;
    else s_pi_cause &= ~4u;
}

void video_present_snapshot(SDL_Renderer* renderer, CPUState* cpu, int window_w, int window_h,const VideoXFB* image) {
    int h = window_h, w = h * 4 / 3;
    if (w > window_w) { w = window_w; h = w * 3 / 4; }
    SDL_Rect dest = { (window_w - w) / 2, (window_h - h) / 2, w, h };
    if(gx_pipe_present_xfb(renderer,image->address,&dest))return;
    if (!s_xfb_texture || image->address < GC_RAM_BASE) return;
    u32 offset = image->address - GC_RAM_BASE;
    if (offset > cpu->ram_size || (u64)image->pitch * image->height > cpu->ram_size - offset) return;
    if (s_texture_width != image->width || s_texture_height != image->height) {
        SDL_DestroyTexture(s_xfb_texture);
        s_xfb_texture = SDL_CreateTexture(renderer,
            s_rgb_fallback ? SDL_PIXELFORMAT_ARGB8888 : SDL_PIXELFORMAT_YUY2,
            SDL_TEXTUREACCESS_STREAMING, (int)image->width, (int)image->height);
        s_texture_width = image->width; s_texture_height = image->height;
        if (!s_xfb_texture) return;
    }
    const u8* source = cpu->ram + offset;
    if (s_rgb_fallback) {
        u8* rgb = (u8*)malloc(image->width * image->height * 4);
        if (!rgb) return;
        int result = SDL_ConvertPixels((int)image->width, (int)image->height,
            SDL_PIXELFORMAT_YUY2, source, (int)image->pitch,
            SDL_PIXELFORMAT_ARGB8888, rgb, (int)image->width * 4);
        if (!result) SDL_UpdateTexture(s_xfb_texture, NULL, rgb, (int)image->width * 4);
        free(rgb);
        if (result) return;
    } else if (SDL_UpdateTexture(s_xfb_texture, NULL, source, (int)image->pitch) != 0) return;
    SDL_RenderCopy(renderer, s_xfb_texture, NULL, &dest);
}

void video_xfb_snapshot(VideoXFB* result){*result=(VideoXFB){s_xfb_addr,s_xfb_width,s_xfb_height,s_xfb_pitch};}
void video_present_frame(SDL_Renderer* renderer,CPUState* cpu,int w,int h){VideoXFB image;video_xfb_snapshot(&image);video_present_snapshot(renderer,cpu,w,h,&image);}

void video_configure_xfb(u32 address, u32 width, u32 height, u32 pitch) {
    if (!width || (width & 1u) || width > 640 || height > 576 || pitch < width * 2) return;
    s_xfb_width = width; s_xfb_height = height; s_xfb_pitch = pitch;
    // VI selects the displayed allocation. Copying a backbuffer does not flip VI.
    (void)address;
}

void video_ack_pe(bool token, bool finish) {
    if (token) s_pe_token = false;
    if (finish) s_pe_finish = false;
    sync_vi_cause();
}
void video_set_pe_enable(u32 enable) { s_pe_enable = enable & 3u; sync_vi_cause(); }

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
    if (s_audio_stream) { SDL_FreeAudioStream(s_audio_stream); s_audio_stream = NULL; }
    if (s_audio_dev != 0) {
        SDL_CloseAudioDevice(s_audio_dev);
        s_audio_dev = 0;
    }
    if (s_xfb_texture) {
        SDL_DestroyTexture(s_xfb_texture);
        s_xfb_texture = NULL;
    }
}
