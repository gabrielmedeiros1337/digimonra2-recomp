#include "gx_pipe.h"
#include "video_audio.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _MSC_VER
#define BSWAP16(x) _byteswap_ushort(x)
#define BSWAP32(x) _byteswap_ulong(x)
#define BSWAP64(x) _byteswap_uint64(x)
#else
#define BSWAP16(x) __builtin_bswap16(x)
#define BSWAP32(x) __builtin_bswap32(x)
#define BSWAP64(x) __builtin_bswap64(x)
#endif

// FIFO Buffer size: 1 MB
#define FIFO_BUFFER_SIZE (1024 * 1024)

static u8* s_fifo_buf = NULL;
static u32 s_fifo_write_head = 0;
static u32 s_fifo_read_tail = 0;
static u64 s_total_fifo_bytes = 0;
static u32 s_draw_call_count = 0;

// Command Processor (CP) Registers
static u16 s_cp_status = 0x000E; // ReadIdle | CommandIdle | UnderflowLo
static u16 s_cp_control = 0;
static u16 s_cp_clear = 0;
static u32 s_cp_base = 0;
static u32 s_cp_end = 0;
static u32 s_cp_hi_watermark = 0;
static u32 s_cp_lo_watermark = 0;
static u32 s_cp_write_ptr = 0;
static u32 s_cp_read_ptr = 0;

// Pixel Engine (PE) Registers
static u16 s_pe_status = 0x000F; // PE Idle & Ready
static u16 s_pe_token = 0;

bool gx_pipe_init(CPUState* cpu) {
    if (!s_fifo_buf) {
        s_fifo_buf = (u8*)malloc(FIFO_BUFFER_SIZE);
        if (!s_fifo_buf) {
            fprintf(stderr, "[GX Pipe] Falha ao alocar buffer FIFO de 1MB!\n");
            return false;
        }
    }

    s_fifo_write_head = 0;
    s_fifo_read_tail = 0;
    s_total_fifo_bytes = 0;
    s_draw_call_count = 0;

    s_cp_status = 0x000E;
    s_pe_status = 0x000F;

    printf("[GX GPU Pipe] Pipeline de Comandos GX (Flipper GPU) inicializado.\n");
    return true;
}

// Command Processor (CP) MMIO Handlers (0xCC000000 - 0xCC00007F)
u32 gx_pipe_read_cp(CPUState* cpu, u32 reg_offset) {
    switch (reg_offset & 0x7E) {
        case 0x00: return s_cp_status; // STATUS_REGISTER (ReadIdle, CommandIdle, Underflow)
        case 0x02: return s_cp_control;
        case 0x04: return s_cp_clear;
        case 0x20: return (s_cp_base >> 16);
        case 0x22: return (s_cp_base & 0xFFFF);
        case 0x24: return (s_cp_end >> 16);
        case 0x26: return (s_cp_end & 0xFFFF);
        case 0x34: return (s_cp_write_ptr >> 16);
        case 0x36: return (s_cp_write_ptr & 0xFFFF);
        case 0x38: return (s_cp_read_ptr >> 16);
        case 0x3A: return (s_cp_read_ptr & 0xFFFF);
        default: return 0;
    }
}

void gx_pipe_write_cp(CPUState* cpu, u32 reg_offset, u32 val) {
    switch (reg_offset & 0x7E) {
        case 0x00:
            // Clear status bits
            break;
        case 0x02:
            s_cp_control = (u16)val;
            break;
        case 0x04:
            s_cp_clear = (u16)val;
            break;
        case 0x20: s_cp_base = (s_cp_base & 0x0000FFFF) | ((val & 0xFFFF) << 16); break;
        case 0x22: s_cp_base = (s_cp_base & 0xFFFF0000) | (val & 0xFFFF); break;
        case 0x24: s_cp_end = (s_cp_end & 0x0000FFFF) | ((val & 0xFFFF) << 16); break;
        case 0x26: s_cp_end = (s_cp_end & 0xFFFF0000) | (val & 0xFFFF); break;
        case 0x34: s_cp_write_ptr = (s_cp_write_ptr & 0x0000FFFF) | ((val & 0xFFFF) << 16); break;
        case 0x36: s_cp_write_ptr = (s_cp_write_ptr & 0xFFFF0000) | (val & 0xFFFF); break;
        case 0x38: s_cp_read_ptr = (s_cp_read_ptr & 0x0000FFFF) | ((val & 0xFFFF) << 16); break;
        case 0x3A: s_cp_read_ptr = (s_cp_read_ptr & 0xFFFF0000) | (val & 0xFFFF); break;
        default: break;
    }
}

// Pixel Engine (PE) MMIO Handlers (0xCC001000 - 0xCC00103F)
u32 gx_pipe_read_pe(CPUState* cpu, u32 reg_offset) {
    switch (reg_offset & 0x3E) {
        case 0x04: return s_pe_status; // PE Status
        case 0x06: return s_pe_status;
        case 0x0E: return s_pe_token;  // PE Token return
        default: return 0;
    }
}

void gx_pipe_write_pe(CPUState* cpu, u32 reg_offset, u32 val) {
    switch (reg_offset & 0x3E) {
        case 0x0E: s_pe_token = (u16)val; break;
        default: break;
    }
}

// Write port into the Gather Pipe (0xCC008000 / 0x0C008000)
void gx_pipe_write_fifo(CPUState* cpu, u32 ea, u64 value, u8 size) {
    if (!s_fifo_buf) return;

    u8 bytes[8];
    switch (size) {
        case 1:
            bytes[0] = (u8)value;
            break;
        case 2: {
            u16 v = BSWAP16((u16)value);
            memcpy(bytes, &v, 2);
            break;
        }
        case 4: {
            u32 v = BSWAP32((u32)value);
            memcpy(bytes, &v, 4);
            break;
        }
        case 8: {
            u64 v = BSWAP64(value);
            memcpy(bytes, &v, 8);
            break;
        }
        default: return;
    }

    for (u8 i = 0; i < size; i++) {
        s_fifo_buf[s_fifo_write_head] = bytes[i];
        s_fifo_write_head = (s_fifo_write_head + 1) % FIFO_BUFFER_SIZE;
    }

    static bool s_first_fifo_cmd = false;
    if (!s_first_fifo_cmd) {
        s_first_fifo_cmd = true;
        printf("[GX GPU Pipe] Primeiro comando recebido no FIFO da GPU! (ea=0x%08X, size=%u, val=0x%llX)\n",
               ea, size, value);
        fflush(stdout);
    }

    s_total_fifo_bytes += size;
}

#define MAX_QUEUED_VERTICES 65536
#define MAX_QUEUED_DRAWS 2048

typedef struct {
    float x, y;
    u8 r, g, b, a;
    float u, v;
} QueuedVertex;

typedef struct {
    u8 prim_type;
    u16 vtx_start;
    u16 vtx_count;
    u32 tex_addr;
    u16 tex_w;
    u16 tex_h;
    u8 tex_fmt;
    bool has_texture;
} QueuedDraw;

static QueuedVertex s_queued_vertices[MAX_QUEUED_VERTICES];
static u32 s_queued_vtx_count = 0;
static QueuedDraw s_queued_draws[MAX_QUEUED_DRAWS];
static u32 s_queued_draw_count = 0;

static inline float read_be_float(const u8* p) {
    u32 u = ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | p[3];
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static inline s16 read_be_s16(const u8* p) {
    return (s16)(((u16)p[0] << 8) | p[1]);
}

// Active texture state from BP registers (TX_SETIMAGE0..3 / BP 0x88..0xBF)
typedef struct {
    u32 addr;
    u16 width;
    u16 height;
    u8 format;
} TexStage;

static TexStage s_tex_stages[8];
static u8 s_active_tex_stage = 0;
static u32 s_active_tex_addr = 0;
static u16 s_active_tex_w = 256;
static u16 s_active_tex_h = 256;
static u8 s_active_tex_fmt = 0x0E; // Default CMPR
static u32 s_active_tlut_addr = 0;
static u8 s_active_tlut_fmt = 1;   // Default RGB5A3

// Texture cache entry for decoded textures
typedef struct {
    u32 gc_addr;
    u16 width;
    u16 height;
    u8 format;
    SDL_Texture* sdl_tex;
} TexCacheEntry;

#define MAX_TEX_CACHE 16
static TexCacheEntry s_tex_cache[MAX_TEX_CACHE];
static u32 s_tex_cache_count = 0;

// Decode 4x4 CMPR (DXT1) sub-block
static void decode_cmpr_block(const u8* src, u32* dst_rgba, int block_x, int block_y, int img_w) {
    u16 c0 = ((u16)src[0] << 8) | src[1];
    u16 c1 = ((u16)src[2] << 8) | src[3];
    u32 bits = ((u32)src[4] << 24) | ((u32)src[5] << 16) | ((u32)src[6] << 8) | src[7];

    u8 r[4], g[4], b[4], a[4];
    r[0] = (u8)(((c0 >> 11) & 0x1F) * 255 / 31);
    g[0] = (u8)(((c0 >> 5) & 0x3F) * 255 / 63);
    b[0] = (u8)((c0 & 0x1F) * 255 / 31);
    a[0] = 255;

    r[1] = (u8)(((c1 >> 11) & 0x1F) * 255 / 31);
    g[1] = (u8)(((c1 >> 5) & 0x3F) * 255 / 63);
    b[1] = (u8)((c1 & 0x1F) * 255 / 31);
    a[1] = 255;

    if (c0 > c1) {
        r[2] = (u8)((2 * r[0] + r[1]) / 3);
        g[2] = (u8)((2 * g[0] + g[1]) / 3);
        b[2] = (u8)((2 * b[0] + b[1]) / 3);
        a[2] = 255;

        r[3] = (u8)((r[0] + 2 * r[1]) / 3);
        g[3] = (u8)((g[0] + 2 * g[1]) / 3);
        b[3] = (u8)((b[0] + 2 * b[1]) / 3);
        a[3] = 255;
    } else {
        r[2] = (u8)((r[0] + r[1]) / 2);
        g[2] = (u8)((g[0] + g[1]) / 2);
        b[2] = (u8)((b[0] + b[1]) / 2);
        a[2] = 255;

        r[3] = 0;
        g[3] = 0;
        b[3] = 0;
        a[3] = 0;
    }

    for (int py = 0; py < 4; py++) {
        for (int px = 0; px < 4; px++) {
            int shift = (15 - (py * 4 + px)) * 2;
            int idx = (bits >> shift) & 3;
            int dx = block_x + px;
            int dy = block_y + py;
            if (dx < img_w) {
                dst_rgba[dy * img_w + dx] = ((u32)a[idx] << 24) | ((u32)b[idx] << 16) | ((u32)g[idx] << 8) | (u32)r[idx];
            }
        }
    }
}

// Decode full CMPR GameCube texture (8x8 tiles composed of four 4x4 sub-blocks)
static void decode_cmpr_texture(const u8* src, u32* dst_rgba, int width, int height) {
    int src_offset = 0;
    for (int y = 0; y < height; y += 8) {
        for (int x = 0; x < width; x += 8) {
            // Sub-block 0: (x+0, y+0)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 0, y + 0, width);
            src_offset += 8;
            // Sub-block 1: (x+4, y+0)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 4, y + 0, width);
            src_offset += 8;
            // Sub-block 2: (x+0, y+4)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 0, y + 4, width);
            src_offset += 8;
            // Sub-block 3: (x+4, y+4)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 4, y + 4, width);
            src_offset += 8;
        }
    }
}

// Decode GameCube CI8 texture (8x4 tiles, 32 bytes per tile)
static void decode_ci8_texture(const u8* src, const u16* palette, bool pal_valid, u8 tlut_fmt, u32* dst_rgba, int width, int height) {
    if (!src || !dst_rgba || width <= 0 || height <= 0) return;

    u32 blocks_per_row = (u32)(width + 7) / 8;

    for (int y = 0; y < height; y++) {
        u32 block_y = (u32)y / 4;
        u32 in_block_y = (u32)y % 4;

        for (int x = 0; x < width; x++) {
            u32 block_x = (u32)x / 8;
            u32 in_block_x = (u32)x % 8;

            u32 block_idx = (block_y * blocks_per_row) + block_x;
            u32 byte_offset = (block_idx * 32) + (in_block_y * 8) + in_block_x;

            u8 palette_index = src[byte_offset];

            u8 r = palette_index, g = palette_index, b = palette_index, a = 255;
            if (pal_valid && palette) {
                u16 c = palette[palette_index];
                if (tlut_fmt == 1) { // RGB565
                    r = (u8)(((c >> 11) & 0x1F) * 255 / 31);
                    g = (u8)(((c >> 5) & 0x3F) * 255 / 63);
                    b = (u8)((c & 0x1F) * 255 / 31);
                    a = 255;
                } else if (tlut_fmt == 0) { // IA8
                    a = (u8)((c >> 8) & 0xFF);
                    r = g = b = (u8)(c & 0xFF);
                } else { // RGB5A3 (fmt == 2 or default)
                    if (c & 0x8000) {
                        r = (u8)(((c >> 10) & 0x1F) * 255 / 31);
                        g = (u8)(((c >> 5) & 0x1F) * 255 / 31);
                        b = (u8)((c & 0x1F) * 255 / 31);
                        a = 255;
                    } else {
                        a = (u8)(((c >> 12) & 0x7) * 255 / 7);
                        r = (u8)(((c >> 8) & 0xF) * 255 / 15);
                        g = (u8)(((c >> 4) & 0xF) * 255 / 15);
                        b = (u8)((c & 0xF) * 255 / 15);
                    }
                }
            }
            dst_rgba[y * width + x] = ((u32)a << 24) | ((u32)b << 16) | ((u32)g << 8) | (u32)r;
        }
    }
}

// Retrieve or cache texture in SDL2
static SDL_Texture* get_or_create_texture(SDL_Renderer* renderer, CPUState* cpu, u32 gc_addr, u16 w, u16 h, u8 fmt) {
    if (!renderer || !cpu || gc_addr < GC_RAM_BASE) return NULL;
    u32 ram_offset = gc_addr - GC_RAM_BASE;
    if (ram_offset >= cpu->ram_size) return NULL;

    for (u32 i = 0; i < s_tex_cache_count; i++) {
        if (s_tex_cache[i].gc_addr == gc_addr && s_tex_cache[i].width == w && s_tex_cache[i].height == h && s_tex_cache[i].format == fmt) {
            SDL_SetTextureBlendMode(s_tex_cache[i].sdl_tex, SDL_BLENDMODE_BLEND);
            return s_tex_cache[i].sdl_tex;
        }
    }

    // Allocate new texture in cache (LRU replacement if full)
    u32 slot = 0;
    if (s_tex_cache_count < MAX_TEX_CACHE) {
        slot = s_tex_cache_count++;
    } else {
        slot = 0;
        if (s_tex_cache[0].sdl_tex) {
            SDL_DestroyTexture(s_tex_cache[0].sdl_tex);
            s_tex_cache[0].sdl_tex = NULL;
        }
    }

    SDL_Texture* tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, w, h);
    if (!tex) return NULL;

    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

    // Decode CI8, CMPR or raw buffer into temporary RGBA buffer
    u32* rgba_buf = (u32*)malloc(w * h * sizeof(u32));
    if (rgba_buf) {
        const u8* raw_bytes = cpu->ram + ram_offset;
        if (fmt == 0x09) { // GX_TF_CI8
            u16 pal_buf[256];
            bool pal_valid = false;
            u32 tlut_addr = s_active_tlut_addr;
            if (tlut_addr >= GC_RAM_BASE && (tlut_addr - GC_RAM_BASE + 512) <= cpu->ram_size) {
                const u8* pal_raw = cpu->ram + (tlut_addr - GC_RAM_BASE);
                u32 non_zero = 0;
                for (int p = 0; p < 256; p++) {
                    pal_buf[p] = ((u16)pal_raw[p * 2] << 8) | pal_raw[p * 2 + 1];
                    if (pal_buf[p] != 0) non_zero++;
                }
                if (non_zero > 0) pal_valid = true;
            }
            static bool s_pal_diag = false;
            if (pal_valid && !s_pal_diag) {
                s_pal_diag = true;
                printf("[GX TLUT Palette 0x%08X (fmt=%u)] Primeiras 16 cores:\n  ", tlut_addr, s_active_tlut_fmt);
                for (int p = 0; p < 16; p++) {
                    printf("[%d]=0x%04X ", p, pal_buf[p]);
                }
                printf("\n");
                fflush(stdout);
            }
            decode_ci8_texture(raw_bytes, pal_buf, pal_valid, s_active_tlut_fmt, rgba_buf, w, h);
            static u32 s_ci8_log = 0;
            if (s_ci8_log++ < 10) {
                printf("[GX TexCache] Decodificada textura 0x%08X (%ux%u CI8 %s, fmt=%u) para SDL2 slot %u\n",
                       gc_addr, w, h, pal_valid ? "com TLUT" : "grayscale fallback", s_active_tlut_fmt, slot);
                fflush(stdout);
            }
        } else {
            decode_cmpr_texture(raw_bytes, rgba_buf, w, h);
            static u32 s_cmpr_log = 0;
            if (s_cmpr_log++ < 10) {
                printf("[GX TexCache] Decodificada textura 0x%08X (%ux%u CMPR) para SDL2 slot %u\n",
                       gc_addr, w, h, slot);
                fflush(stdout);
            }
        }
        SDL_UpdateTexture(tex, NULL, rgba_buf, w * sizeof(u32));

        static bool s_diag_printed = false;
        if (!s_diag_printed) {
            s_diag_printed = true;
            u32 non_zero_pixels = 0;
            for (int p = 0; p < w * h; p++) {
                if (rgba_buf[p] != 0) non_zero_pixels++;
            }
            printf("[GX TexCache Diagnostico 0x%08X fmt=0x%02X] Pixels visiveis (RGBA != 0): %u / %u (%.1f%%)\n",
                   gc_addr, fmt, non_zero_pixels, w * h, (double)non_zero_pixels * 100.0 / (w * h));
            printf("  Primeiros 16 pixels RGBA:\n  ");
            for (int p = 0; p < 16; p++) {
                u32 pix = rgba_buf[p];
                u8 r = (u8)(pix & 0xFF);
                u8 g = (u8)((pix >> 8) & 0xFF);
                u8 b = (u8)((pix >> 16) & 0xFF);
                u8 a = (u8)((pix >> 24) & 0xFF);
                printf("[%02X,%02X,%02X,%02X] ", r, g, b, a);
            }
            printf("\n");
            fflush(stdout);
        }

        free(rgba_buf);
    }

    s_tex_cache[slot].gc_addr = gc_addr;
    s_tex_cache[slot].width = w;
    s_tex_cache[slot].height = h;
    s_tex_cache[slot].format = fmt;
    s_tex_cache[slot].sdl_tex = tex;

    return tex;
}

// Check if byte offset in FIFO points to a valid GX command
static bool is_valid_fifo_cmd(const u8* buf, u32 offset, u32 available) {
    if (available < 1) return false;
    u8 b = buf[offset % FIFO_BUFFER_SIZE];
    if (b == 0x61) {
        return (available >= 5);
    }
    if (b == 0x10) {
        if (available < 5) return false;
        u16 count_m1 = ((u16)buf[(offset + 1) % FIFO_BUFFER_SIZE] << 8) | buf[(offset + 2) % FIFO_BUFFER_SIZE];
        u32 total = 5 + ((u32)count_m1 + 1) * 4;
        return (available >= total);
    }
    if (b == 0x08) {
        return (available >= 6);
    }
    if ((b & 0xF8) >= 0x80 && (b & 0xF8) <= 0xB8) {
        if (available < 3) return false;
        u16 count = ((u16)buf[(offset + 1) % FIFO_BUFFER_SIZE] << 8) | buf[(offset + 2) % FIFO_BUFFER_SIZE];
        return (count > 0 && count <= 1024);
    }
    return false;
}

// Process pending commands in FIFO
void gx_pipe_process_frame(CPUState* cpu) {
    static u32 s_bp_log_count = 0;
    static u32 s_draw_log_count = 0;

    while (s_fifo_read_tail != s_fifo_write_head) {
        u32 available = (s_fifo_write_head >= s_fifo_read_tail)
                        ? (s_fifo_write_head - s_fifo_read_tail)
                        : (FIFO_BUFFER_SIZE - s_fifo_read_tail + s_fifo_write_head);
        if (available == 0) break;

        u8 opcode = s_fifo_buf[s_fifo_read_tail];

        // 1. NOP (0x00)
        if (opcode == 0x00) {
            s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 2. Load CP Register (0x08) - 6 bytes: 0x08 <u8 reg> <u32 val>
        if (opcode == 0x08) {
            if (available < 6) break;
            u8 cp_reg = s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE];
            u32 cp_val = ((u32)s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE] << 24) |
                         ((u32)s_fifo_buf[(s_fifo_read_tail + 3) % FIFO_BUFFER_SIZE] << 16) |
                         ((u32)s_fifo_buf[(s_fifo_read_tail + 4) % FIFO_BUFFER_SIZE] << 8)  |
                         s_fifo_buf[(s_fifo_read_tail + 5) % FIFO_BUFFER_SIZE];
            static u32 s_cp_log = 0;
            if (s_cp_log++ < 25) {
                printf("[GX CP #%u] reg=0x%02X val=0x%08X\n", s_cp_log, cp_reg, cp_val);
                fflush(stdout);
            }
            s_fifo_read_tail = (s_fifo_read_tail + 6) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 3. Load XF Register (0x10) - 5 + (count * 4) bytes: 0x10 <u16 count_minus_1> <u16 addr> <data...>
        if (opcode == 0x10) {
            if (available < 5) break;
            u16 count_m1 = ((u16)s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE] << 8) |
                            s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE];
            u16 xf_addr = ((u16)s_fifo_buf[(s_fifo_read_tail + 3) % FIFO_BUFFER_SIZE] << 8) |
                           s_fifo_buf[(s_fifo_read_tail + 4) % FIFO_BUFFER_SIZE];
            u32 count = (u32)count_m1 + 1;
            u32 total_len = 5 + count * 4;
            if (available < total_len) break;
            static u32 s_xf_log = 0;
            if (s_xf_log++ < 25) {
                printf("[GX XF #%u] addr=0x%04X count=%u (len=%u)\n", s_xf_log, xf_addr, count, total_len);
                fflush(stdout);
            }
            s_fifo_read_tail = (s_fifo_read_tail + total_len) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 4. Load BP Register (0x61) - 5 bytes: 0x61 <u32 val>
        if (opcode == 0x61) {
            if (available < 5) break;
            s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            u32 bp_val = 0;
            for (int b = 0; b < 4; b++) {
                bp_val = (bp_val << 8) | s_fifo_buf[s_fifo_read_tail];
                s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            }
            u8 bp_reg = (u8)((bp_val >> 24) & 0xFF);
            u32 reg_val = bp_val & 0x00FFFFFFu;

            if (s_bp_log_count++ < 20) {
                printf("[GX BP #%u] reg=0x%02X val=0x%06X\n", s_bp_log_count, bp_reg, reg_val);
                fflush(stdout);
            }

            // PE_COPY_DEST_ADDR (0x4B)
            if (bp_reg == 0x4B) {
                u32 phys_addr = reg_val << 5;
                u32 xfb_addr = phys_addr | GC_RAM_BASE;
                if (xfb_addr >= 0x80300000u && xfb_addr < (GC_RAM_BASE + cpu->ram_size)) {
                    video_set_xfb_addr(xfb_addr);
                }
            }

            // TLUT load registers (0x64, 0x65, 0x98..0x9B)
            if (bp_reg == 0x64) {
                u32 phys_tlut = (reg_val & 0x001FFFFF) << 5;
                u32 gc_tlut = phys_tlut | GC_RAM_BASE;
                if (gc_tlut >= 0x80000000u && gc_tlut < (GC_RAM_BASE + cpu->ram_size)) {
                    s_active_tlut_addr = gc_tlut;
                    static u32 s_tlut_log = 0;
                    if (s_tlut_log++ < 10) {
                        printf("[GX TLUT 0x64] TLUT configurada: addr=0x%08X fmt=%u\n", s_active_tlut_addr, s_active_tlut_fmt);
                        fflush(stdout);
                    }
                }
            } else if (bp_reg >= 0x98 && bp_reg <= 0x9B) {
                s_active_tlut_fmt = (u8)((reg_val >> 10) & 0x3);
                static u32 s_settlut_log = 0;
                if (s_settlut_log++ < 10) {
                    printf("[GX TLUT 0x%02X] SETTLUT: val=0x%06X (tmem=0x%X fmt=%u)\n",
                           bp_reg, reg_val, (reg_val & 0x3FF), s_active_tlut_fmt);
                    fflush(stdout);
                }
            }

            // Texture Image State (TX_SETIMAGE0..3)
            // Stages 0..3: 0x88..0x97 (0x88=Img0_Reg0, 0x8C=Img0_Reg1, 0x90=Img0_Reg2, 0x94=Img0_Reg3)
            // Stages 4..7: 0xA8..0xB7 (0xA8=Img4_Reg0, 0xAC=Img4_Reg1, 0xB0=Img4_Reg2, 0xB4=Img4_Reg3)
            if ((bp_reg >= 0x88 && bp_reg <= 0x97) || (bp_reg >= 0xA8 && bp_reg <= 0xB7)) {
                u8 stage = (bp_reg <= 0x97) ? ((bp_reg - 0x88) % 4) : (4 + ((bp_reg - 0xA8) % 4));
                u8 subreg = (bp_reg <= 0x97) ? ((bp_reg - 0x88) / 4) : ((bp_reg - 0xA8) / 4);

                if (subreg == 0) { // TX_SETIMAGE0: size [w-1:10, h-1:10, fmt:4]
                    u16 w = (u16)((reg_val & 0x3FF) + 1);
                    u16 h = (u16)(((reg_val >> 10) & 0x3FF) + 1);
                    u8 fmt = (u8)((reg_val >> 20) & 0xF);
                    s_tex_stages[stage].width = (w > 0 && w <= 1024) ? w : 256;
                    s_tex_stages[stage].height = (h > 0 && h <= 1024) ? h : 256;
                    s_tex_stages[stage].format = fmt;
                } else if (subreg == 3) { // TX_SETIMAGE3: physical address >> 5 (Main RAM base)
                    u32 phys_tex = (reg_val & 0x001FFFFF) << 5;
                    u32 gc_tex = phys_tex | GC_RAM_BASE;
                    if (gc_tex >= 0x80300000u && gc_tex < (GC_RAM_BASE + cpu->ram_size)) {
                        s_tex_stages[stage].addr = gc_tex;
                        s_active_tex_stage = stage;
                        s_active_tex_addr = gc_tex;
                        s_active_tex_w = s_tex_stages[stage].width;
                        s_active_tex_h = s_tex_stages[stage].height;
                        s_active_tex_fmt = s_tex_stages[stage].format;

                        static u32 s_stage_log = 0;
                        if (s_stage_log++ < 25) {
                            printf("[GX TexStage %u] Textura configurada: 0x%08X (%ux%u fmt=0x%02X)\n",
                                   stage, gc_tex, s_active_tex_w, s_active_tex_h, s_active_tex_fmt);
                            fflush(stdout);
                        }
                    }
                }
            }
            continue;
        }

        // 5. Draw Primitives (0x80 - 0xB8)
        if ((opcode & 0xF8) >= 0x80 && (opcode & 0xF8) <= 0xB8) {
            if (available < 3) break;
            u16 vtx_count = ((u16)s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE] << 8) |
                            s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE];
            if (vtx_count == 0 || vtx_count > 1024) {
                // Not a valid primitive command (likely float data or padding): skip 1 byte
                s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
                continue;
            }
            s_draw_call_count++;

            if (s_draw_call_count <= 8) {
                printf("[GX FIFO Dump #%u] Opcode=0x%02X VtxCount=%u (avail=%u): ", s_draw_call_count, opcode, vtx_count, available);
                for (u32 b = 0; b < 64 && b < available; b++) {
                    printf("%02X ", s_fifo_buf[(s_fifo_read_tail + b) % FIFO_BUFFER_SIZE]);
                }
                printf("\n");
                fflush(stdout);
            }

            u32 stride = 8;
            if (vtx_count > 0 && vtx_count <= 1024) {
                u32 count32 = (u32)vtx_count;

                bool found_stride = false;
                u32 fmt_idx = opcode & 7;
                static const u32 strides_fmt7[] = { 10, 12, 8, 16, 20 };
                static const u32 strides_fmt0_tex[] = { 44, 20, 24, 16, 28, 32, 36, 12, 10, 8, 40 };
                static const u32 strides_default[] = { 10, 12, 44, 20, 36, 16, 24, 28, 32, 14, 8 };

                const u32* cand_strides = strides_default;
                size_t cand_count = sizeof(strides_default)/sizeof(strides_default[0]);

                if (fmt_idx == 7) {
                    cand_strides = strides_fmt7;
                    cand_count = sizeof(strides_fmt7)/sizeof(strides_fmt7[0]);
                } else if (s_active_tex_addr >= 0x80300000u) {
                    cand_strides = strides_fmt0_tex;
                    cand_count = sizeof(strides_fmt0_tex)/sizeof(strides_fmt0_tex[0]);
                }

                // Pass 1: Immediate command match with 0 padding
                for (size_t i = 0; i < cand_count; i++) {
                    u32 s = cand_strides[i];
                    u32 plen = 3 + count32 * s;
                    if (available >= plen) {
                        if (is_valid_fifo_cmd(s_fifo_buf, (s_fifo_read_tail + plen) % FIFO_BUFFER_SIZE, available - plen)) {
                            stride = s;
                            found_stride = true;
                            break;
                        }
                    }
                }

                // Pass 2: Match with 0x00 padding (up to 31 bytes)
                if (!found_stride) {
                    for (size_t i = 0; i < cand_count; i++) {
                        u32 s = cand_strides[i];
                        u32 plen = 3 + count32 * s;
                        if (available >= plen) {
                            u8 next_b = s_fifo_buf[(s_fifo_read_tail + plen) % FIFO_BUFFER_SIZE];
                            if (next_b == 0x00) {
                                bool pad_valid = false;
                                for (u32 pad = 1; pad < 32 && (plen + pad) < available; pad++) {
                                    u32 check_off = (s_fifo_read_tail + plen + pad) % FIFO_BUFFER_SIZE;
                                    if (is_valid_fifo_cmd(s_fifo_buf, check_off, available - (plen + pad))) {
                                        pad_valid = true;
                                        break;
                                    }
                                    if (s_fifo_buf[check_off] != 0x00) break;
                                }
                                if (pad_valid) {
                                    stride = s;
                                    found_stride = true;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (!found_stride) {
                    if (fmt_idx == 7) {
                        stride = 10;
                    } else if (s_active_tex_addr >= 0x80300000u) {
                        stride = 44;
                    } else {
                        stride = 12;
                    }
                }

                u32 packet_len = 3 + count32 * stride;
                if (available < packet_len) break;

            // Extract vertex coordinates and colors into queue for SDL rendering
            if (s_queued_draw_count < MAX_QUEUED_DRAWS &&
                    s_queued_vtx_count + count32 <= MAX_QUEUED_VERTICES) {
                    u32 start_vtx = s_queued_vtx_count;
                    u32 data_head = (s_fifo_read_tail + 3) % FIFO_BUFFER_SIZE;

                    static bool s_first_tex_draw_logged = false;
                    bool is_logging_first_quad = (count32 >= 4 && s_active_tex_addr >= 0x80300000u && !s_first_tex_draw_logged);
                    if (is_logging_first_quad) {
                        s_first_tex_draw_logged = true;
                        printf("=== [GX DUMP PRIMEIRO DRAW TEXTURIZADO (Opcode=0x%02X, tail=%u, data_head=+3=%u, Tex=0x%08X, Stride=%u, VtxCount=%u)] ===\n",
                               opcode, s_fifo_read_tail, data_head, s_active_tex_addr, stride, count32);
                        for (u32 v_idx = 0; v_idx < 4; v_idx++) {
                            u8 vb[64] = {0};
                            for (u32 b = 0; b < stride && b < 64; b++) {
                                vb[b] = s_fifo_buf[(data_head + v_idx * stride + b) % FIFO_BUFFER_SIZE];
                            }
                            printf("  Vtx[%u] Raw (at +%u): ", v_idx, v_idx * stride);
                            for (u32 b = 0; b < stride && b < 36; b++) printf("%02X ", vb[b]);
                            printf("\n    Floats: [0..3]=%.4f [4..7]=%.4f [8..11]=%.4f [12..15]=%.4f [16..19]=%.4f [28..31]=%.4f [32..35]=%.4f\n",
                                   read_be_float(vb + 0), read_be_float(vb + 4), read_be_float(vb + 8),
                                   read_be_float(vb + 12), read_be_float(vb + 16),
                                   read_be_float(vb + 28), read_be_float(vb + 32));
                            printf("    s16:    [0..1]=%d [2..3]=%d [4..5]=%d [6..7]=%d [8..9]=%d [10..11]=%d\n",
                                   read_be_s16(vb + 0), read_be_s16(vb + 2), read_be_s16(vb + 4),
                                   read_be_s16(vb + 6), read_be_s16(vb + 8), read_be_s16(vb + 10));
                        }
                        fflush(stdout);
                    }

                    static const u8 s_palette[8][3] = {
                        {   0, 210, 255 },  // Bright Cyan
                        { 255, 175,   0 },  // Gold / Amber
                        { 235,  60, 220 },  // Vibrant Magenta
                        {  50, 230, 120 },  // Emerald Green
                        { 255, 230,  40 },  // Bright Yellow
                        {  80, 180, 255 },  // Sky Blue
                        { 255,  85,  90 },  // Coral / Red
                        { 240, 240, 255 }   // Pure Off-White
                    };
                    static const u8 s_white[3] = { 255, 255, 255 };
                    const u8* col = (s_active_tex_addr >= 0x80300000u) ? s_white : s_palette[s_queued_draw_count % 8];

                    for (u32 v = 0; v < count32; v++) {
                        u8 vtx_bytes[64];
                        for (u32 b = 0; b < stride && b < 64; b++) {
                            vtx_bytes[b] = s_fifo_buf[(data_head + v * stride + b) % FIFO_BUFFER_SIZE];
                        }

                        QueuedVertex* qv = &s_queued_vertices[s_queued_vtx_count++];
                        qv->r = col[0];
                        qv->g = col[1];
                        qv->b = col[2];
                        qv->a = 255;
                        qv->u = 0.0f;
                        qv->v = 0.0f;

                        if (stride == 44 || stride == 36) {
                            float raw_x = read_be_float(vtx_bytes + 0);
                            float raw_y = read_be_float(vtx_bytes + 4);
                            qv->r = vtx_bytes[24];
                            qv->g = vtx_bytes[25];
                            qv->b = vtx_bytes[26];
                            qv->a = (vtx_bytes[27] != 0) ? vtx_bytes[27] : 255;
                            qv->u = read_be_float(vtx_bytes + 28);
                            qv->v = read_be_float(vtx_bytes + 32);

                            // Coordinate mapping
                            if (isnan(raw_x) || isnan(raw_y)) {
                                qv->x = 0.0f;
                                qv->y = 0.0f;
                            } else if (raw_x >= -450.0f && raw_x <= 450.0f && raw_y >= -350.0f && raw_y <= 350.0f) {
                                qv->x = raw_x + 320.0f;
                                qv->y = 240.0f - raw_y;
                            } else if (fabsf(raw_x) <= 2.0f && fabsf(raw_y) <= 2.0f) {
                                qv->x = (raw_x + 1.0f) * 0.5f * 640.0f;
                                qv->y = (raw_y + 1.0f) * 0.5f * 480.0f;
                            } else {
                                qv->x = raw_x;
                                qv->y = raw_y;
                            }

                            if (isnan(qv->u)) qv->u = 0.0f;
                            if (isnan(qv->v)) qv->v = 0.0f;

                            float tw = (s_active_tex_w > 0) ? (float)s_active_tex_w : 256.0f;
                            float th = (s_active_tex_h > 0) ? (float)s_active_tex_h : 256.0f;
                            if (qv->u > 1.5f || qv->v > 1.5f) {
                                qv->u /= tw;
                                qv->v /= th;
                            }

                            if (is_logging_first_quad && v < 4) {
                                printf("    -> Parsed Vtx[%u] (s%u): pos=(%.2f, %.2f) raw_xy=(%.2f, %.2f) uv=(%.4f, %.4f) rgba=(%u,%u,%u,%u)\n",
                                       v, stride, qv->x, qv->y, raw_x, raw_y, qv->u, qv->v, qv->r, qv->g, qv->b, qv->a);
                                fflush(stdout);
                            }
                        } else if (stride == 20 || stride == 16 || stride == 24) {
                            float raw_x = read_be_float(vtx_bytes + 0);
                            float raw_y = read_be_float(vtx_bytes + 4);
                            if (stride == 16) {
                                qv->u = read_be_float(vtx_bytes + 8);
                                qv->v = read_be_float(vtx_bytes + 12);
                            } else if (stride == 20) {
                                qv->u = read_be_float(vtx_bytes + 12);
                                qv->v = read_be_float(vtx_bytes + 16);
                            } else { // stride == 24
                                qv->r = vtx_bytes[12]; qv->g = vtx_bytes[13]; qv->b = vtx_bytes[14]; qv->a = vtx_bytes[15];
                                qv->u = read_be_float(vtx_bytes + 16);
                                qv->v = read_be_float(vtx_bytes + 20);
                            }

                            // Coordinate mapping
                            if (isnan(raw_x) || isnan(raw_y)) {
                                qv->x = 0.0f;
                                qv->y = 0.0f;
                            } else if (raw_x >= -450.0f && raw_x <= 450.0f && raw_y >= -350.0f && raw_y <= 350.0f) {
                                qv->x = raw_x + 320.0f;
                                qv->y = 240.0f - raw_y;
                            } else if (fabsf(raw_x) <= 2.0f && fabsf(raw_y) <= 2.0f) {
                                 qv->x = (raw_x + 1.0f) * 0.5f * 640.0f;
                                 qv->y = (raw_y + 1.0f) * 0.5f * 480.0f;
                            } else {
                                qv->x = raw_x;
                                qv->y = raw_y;
                            }

                            if (isnan(qv->u)) qv->u = 0.0f;
                            if (isnan(qv->v)) qv->v = 0.0f;

                            // Normalize UV if in pixels
                            float tw = (s_active_tex_w > 0) ? (float)s_active_tex_w : 256.0f;
                            float th = (s_active_tex_h > 0) ? (float)s_active_tex_h : 256.0f;
                            if (qv->u > 1.5f || qv->v > 1.5f) {
                                qv->u /= tw;
                                qv->v /= th;
                            }

                            if (is_logging_first_quad && v < 4) {
                                printf("    -> Parsed Vtx[%u]: pos=(%.2f, %.2f) raw_xy=(%.2f, %.2f) uv=(%.4f, %.4f)\n",
                                       v, qv->x, qv->y, raw_x, raw_y, qv->u, qv->v);
                                fflush(stdout);
                            }
                        } else if (stride == 10) {
                            s16 raw_x = read_be_s16(vtx_bytes + 0);
                            s16 raw_y = read_be_s16(vtx_bytes + 2);
                            qv->x = (float)raw_x;
                            qv->y = (float)raw_y;
                            qv->r = vtx_bytes[6];
                            qv->g = vtx_bytes[7];
                            qv->b = vtx_bytes[8];
                            qv->a = (vtx_bytes[9] != 0) ? vtx_bytes[9] : 255;
                            qv->u = 0.0f;
                            qv->v = 0.0f;
                        } else if (stride == 12) {
                            s16 raw_x = read_be_s16(vtx_bytes + 0);
                            s16 raw_y = read_be_s16(vtx_bytes + 2);
                            qv->x = (float)raw_x;
                            qv->y = (float)raw_y;
                            if (vtx_bytes[8] != 0 || vtx_bytes[9] != 0 || vtx_bytes[10] != 0 || vtx_bytes[11] != 0) {
                                qv->r = vtx_bytes[8];
                                qv->g = vtx_bytes[9];
                                qv->b = vtx_bytes[10];
                                qv->a = (vtx_bytes[11] != 0) ? vtx_bytes[11] : 255;
                            } else if (vtx_bytes[4] != 0 || vtx_bytes[5] != 0 || vtx_bytes[6] != 0 || vtx_bytes[7] != 0) {
                                qv->r = vtx_bytes[4];
                                qv->g = vtx_bytes[5];
                                qv->b = vtx_bytes[6];
                                qv->a = (vtx_bytes[7] != 0) ? vtx_bytes[7] : 255;
                            }
                        } else { // stride == 8
                            float raw_x = read_be_float(vtx_bytes + 0);
                            float raw_y = read_be_float(vtx_bytes + 4);
                            if (isnan(raw_x) || isnan(raw_y)) {
                                qv->x = 0.0f;
                                qv->y = 0.0f;
                            } else if (raw_x >= -450.0f && raw_x <= 450.0f && raw_y >= -350.0f && raw_y <= 350.0f) {
                                qv->x = raw_x + 320.0f;
                                qv->y = 240.0f - raw_y;
                            } else if (fabsf(raw_x) <= 2.0f && fabsf(raw_y) <= 2.0f) {
                                qv->x = (raw_x + 1.0f) * 0.5f * 640.0f;
                                qv->y = (raw_y + 1.0f) * 0.5f * 480.0f;
                            } else {
                                s16 sx = read_be_s16(vtx_bytes + 0);
                                s16 sy = read_be_s16(vtx_bytes + 2);
                                qv->x = (float)sx;
                                qv->y = (float)sy;
                            }
                        }
                        if (isnan(qv->x)) qv->x = 0.0f;
                        if (isnan(qv->y)) qv->y = 0.0f;

                        static u32 s_vtx_sample_log = 0;
                        if (s_vtx_sample_log++ < 8) {
                            printf("[GX Vtx Sample #%u Stride %u] raw bytes: %02X %02X %02X %02X %02X %02X %02X %02X -> (x=%.1f, y=%.1f, u=%.3f, v=%.3f)\n",
                                   s_vtx_sample_log, stride,
                                   vtx_bytes[0], vtx_bytes[1], vtx_bytes[2], vtx_bytes[3],
                                   vtx_bytes[4], vtx_bytes[5], vtx_bytes[6], vtx_bytes[7],
                                   qv->x, qv->y, qv->u, qv->v);
                            fflush(stdout);
                        }

                        static u32 s_vtx_80_log = 0;
                        if ((opcode & 0xF8) == 0x80 && s_vtx_80_log++ < 8) {
                            printf("[GX Vtx 0x80 Sample #%u Stride %u] raw: %02X %02X %02X %02X %02X %02X %02X %02X -> (x=%.1f, y=%.1f, u=%.3f, v=%.3f)\n",
                                   s_vtx_80_log, stride,
                                   vtx_bytes[0], vtx_bytes[1], vtx_bytes[2], vtx_bytes[3],
                                   vtx_bytes[4], vtx_bytes[5], vtx_bytes[6], vtx_bytes[7],
                                   qv->x, qv->y, qv->u, qv->v);
                            fflush(stdout);
                        }
                    }

                    QueuedDraw* qd = &s_queued_draws[s_queued_draw_count++];
                    qd->prim_type = opcode & 0xF8;
                    qd->vtx_start = (u16)start_vtx;
                    qd->vtx_count = (u16)count32;
                    qd->tex_addr = s_active_tex_addr;
                    qd->tex_w = s_active_tex_w;
                    qd->tex_h = s_active_tex_h;
                    qd->tex_fmt = s_active_tex_fmt;
                    qd->has_texture = (stride == 20) || (s_active_tex_addr >= 0x80300000u);
                }

                if (s_draw_log_count++ < 10) {
                    printf("[GX Draw #%u] Primitiva (Opcode=0x%02X, Vertices=%u, Stride=%u, Tex=0x%08X)\n",
                           s_draw_log_count, opcode, vtx_count, stride, s_active_tex_addr);
                    fflush(stdout);
                }
                s_fifo_read_tail = (s_fifo_read_tail + packet_len) % FIFO_BUFFER_SIZE;
                continue;
            }

            s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            continue;
        }

        // Unknown byte: advance by 1
        s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
    }

    // Keep read pointer in sync with write pointer
    s_cp_read_ptr = s_cp_write_ptr;

    // Signal GPU finish and token interrupts
    video_trigger_pe_finish();
    video_trigger_pe_token();
}

// Clear queued draws and vertices each frame
void gx_pipe_clear_queued_draws(void) {
    s_queued_vtx_count = 0;
    s_queued_draw_count = 0;
}

// Renders extracted 2D primitives directly to the SDL2 renderer
void gx_pipe_render_to_sdl(SDL_Renderer* renderer, CPUState* cpu, int game_x, int game_y, int game_w, int game_h) {
    if (!renderer || s_queued_draw_count == 0) return;

    static u32 s_sdl_render_log = 0;
    if (s_sdl_render_log++ < 10) {
        printf("[GX SDL2 Renderer #%u] Desenhando %u primitivas (%u vertices) na janela SDL2! Viewport: (%d, %d, %dx%d)\n",
               s_sdl_render_log, s_queued_draw_count, s_queued_vtx_count, game_x, game_y, game_w, game_h);
        fflush(stdout);
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Buffer for batching contiguous triangles with identical texture state
    #define MAX_BATCH_VERTS 2048
    static SDL_Vertex s_batch_verts[MAX_BATCH_VERTS];
    int batch_count = 0;
    SDL_Texture* current_tex = NULL;

    for (u32 d = 0; d < s_queued_draw_count; d++) {
        QueuedDraw* qd = &s_queued_draws[d];
        u32 start = qd->vtx_start;
        u32 count = qd->vtx_count;

        SDL_Texture* tex = NULL;
        if (qd->has_texture && qd->tex_addr >= 0x80300000u) {
            tex = get_or_create_texture(renderer, cpu, qd->tex_addr, qd->tex_w, qd->tex_h, qd->tex_fmt);
        }

        // Quads (0x80): decompose each quad of 4 vertices into 2 triangles (6 vertices)
        if (qd->prim_type == 0x80) {
            u32 num_quads = count / 4;
            for (u32 q = 0; q < num_quads; q++) {
                QueuedVertex* v0 = &s_queued_vertices[start + q * 4 + 0];
                QueuedVertex* v1 = &s_queued_vertices[start + q * 4 + 1];
                QueuedVertex* v2 = &s_queued_vertices[start + q * 4 + 2];
                QueuedVertex* v3 = &s_queued_vertices[start + q * 4 + 3];

                if (isnan(v0->x) || isnan(v0->y) || isnan(v1->x) || isnan(v1->y) ||
                    isnan(v2->x) || isnan(v2->y) || isnan(v3->x) || isnan(v3->y)) {
                    continue;
                }

                // Screen positions
                float x0 = (float)game_x + (v0->x / 640.0f) * (float)game_w;
                float y0 = (float)game_y + (v0->y / 480.0f) * (float)game_h;
                float x1 = (float)game_x + (v1->x / 640.0f) * (float)game_w;
                float y1 = (float)game_y + (v1->y / 480.0f) * (float)game_h;
                float x2 = (float)game_x + (v2->x / 640.0f) * (float)game_w;
                float y2 = (float)game_y + (v2->y / 480.0f) * (float)game_h;
                float x3 = (float)game_x + (v3->x / 640.0f) * (float)game_w;
                float y3 = (float)game_y + (v3->y / 480.0f) * (float)game_h;

                // Discard zero-area degenerate quads
                float min_x = fminf(fminf(x0, x1), fminf(x2, x3));
                float max_x = fmaxf(fmaxf(x0, x1), fmaxf(x2, x3));
                float min_y = fminf(fminf(y0, y1), fminf(y2, y3));
                float max_y = fmaxf(fmaxf(y0, y1), fmaxf(y2, y3));
                if ((max_x - min_x) < 0.01f || (max_y - min_y) < 0.01f) continue;

                // Discard completely offscreen quads
                if (max_x < 0 || min_x > (game_x + game_w + 100) || max_y < 0 || min_y > (game_y + game_h + 100)) continue;

                // If texture state changes or batch is full, flush current batch
                if (batch_count > 0 && (current_tex != tex || batch_count + 6 > MAX_BATCH_VERTS)) {
                    SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
                    batch_count = 0;
                }
                current_tex = tex;

                QueuedVertex* qverts[6] = { v0, v1, v2, v0, v2, v3 };
                float qpos_x[6] = { x0, x1, x2, x0, x2, x3 };
                float qpos_y[6] = { y0, y1, y2, y0, y2, y3 };

                for (int i = 0; i < 6; i++) {
                    SDL_Vertex* v = &s_batch_verts[batch_count++];
                    v->position.x = qpos_x[i];
                    v->position.y = qpos_y[i];
                    if (tex) {
                        v->color.r = 255;
                        v->color.g = 255;
                        v->color.b = 255;
                        v->color.a = 255;
                    } else {
                        v->color.r = qverts[i]->r;
                        v->color.g = qverts[i]->g;
                        v->color.b = qverts[i]->b;
                        v->color.a = qverts[i]->a;
                    }
                    v->tex_coord.x = qverts[i]->u;
                    v->tex_coord.y = qverts[i]->v;
                }
            }
        }
        // Triangles (0x88)
        else if (qd->prim_type == 0x88) {
            u32 num_tris = count / 3;
            for (u32 t = 0; t < num_tris; t++) {
                if (batch_count > 0 && (current_tex != tex || batch_count + 3 > MAX_BATCH_VERTS)) {
                    SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
                    batch_count = 0;
                }
                current_tex = tex;

                for (int i = 0; i < 3; i++) {
                    QueuedVertex* qv = &s_queued_vertices[start + t * 3 + i];
                    SDL_Vertex* v = &s_batch_verts[batch_count++];
                    v->position.x = (float)game_x + (qv->x / 640.0f) * (float)game_w;
                    v->position.y = (float)game_y + (qv->y / 480.0f) * (float)game_h;
                    if (tex) {
                        v->color.r = 255;
                        v->color.g = 255;
                        v->color.b = 255;
                        v->color.a = 255;
                    } else {
                        v->color.r = qv->r;
                        v->color.g = qv->g;
                        v->color.b = qv->b;
                        v->color.a = qv->a;
                    }
                    v->tex_coord.x = qv->u;
                    v->tex_coord.y = qv->v;
                }
            }
        }
        // Triangle Strip (0x90)
        else if (qd->prim_type == 0x90) {
            for (u32 i = 2; i < count; i++) {
                QueuedVertex* v0;
                QueuedVertex* v1;
                QueuedVertex* v2 = &s_queued_vertices[start + i];

                // Alternating winding order for triangle strip to prevent diagonal inversion
                if (i % 2 == 0) {
                    v0 = &s_queued_vertices[start + i - 2];
                    v1 = &s_queued_vertices[start + i - 1];
                } else {
                    v0 = &s_queued_vertices[start + i - 1];
                    v1 = &s_queued_vertices[start + i - 2];
                }

                // Check for degenerate triangles (separator between character glyphs)
                float px0 = v0->x, py0 = v0->y;
                float px1 = v1->x, py1 = v1->y;
                float px2 = v2->x, py2 = v2->y;

                if ((fabsf(px0 - px1) < 0.001f && fabsf(py0 - py1) < 0.001f) ||
                    (fabsf(px1 - px2) < 0.001f && fabsf(py1 - py2) < 0.001f) ||
                    (fabsf(px0 - px2) < 0.001f && fabsf(py0 - py2) < 0.001f)) {
                    continue; // Skip degenerate triangle
                }

                // Discard zero or near-zero area triangles
                float area = fabsf((px1 - px0) * (py2 - py0) - (py1 - py0) * (px2 - px0));
                if (area < 0.01f) {
                    continue; // Skip zero-area triangle
                }

                // Discard triangle strip bridges between distant glyphs / words / carriage returns
                if (tex != NULL) {
                    float d01_x = fabsf(px0 - px1), d12_x = fabsf(px1 - px2), d02_x = fabsf(px0 - px2);
                    float d01_y = fabsf(py0 - py1), d12_y = fabsf(py1 - py2), d02_y = fabsf(py0 - py2);
                    if (d01_x > 60.0f || d12_x > 60.0f || d02_x > 60.0f ||
                        d01_y > 60.0f || d12_y > 60.0f || d02_y > 60.0f) {
                        continue;
                    }
                }

                if (batch_count > 0 && (current_tex != tex || batch_count + 3 > MAX_BATCH_VERTS)) {
                    SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
                    batch_count = 0;
                }
                current_tex = tex;

                QueuedVertex* qverts[3] = { v0, v1, v2 };
                for (int k = 0; k < 3; k++) {
                    SDL_Vertex* v = &s_batch_verts[batch_count++];
                    v->position.x = (float)game_x + (qverts[k]->x / 640.0f) * (float)game_w;
                    v->position.y = (float)game_y + (qverts[k]->y / 480.0f) * (float)game_h;
                    v->color.r = qverts[k]->r;
                    v->color.g = qverts[k]->g;
                    v->color.b = qverts[k]->b;
                    v->color.a = qverts[k]->a;
                    v->tex_coord.x = qverts[k]->u;
                    v->tex_coord.y = qverts[k]->v;
                }
            }
        }
        // Triangle Fan (0x98)
        else if (qd->prim_type == 0x98) {
            for (u32 i = 1; i + 1 < count; i++) {
                QueuedVertex* v0 = &s_queued_vertices[start];
                QueuedVertex* v1 = &s_queued_vertices[start + i];
                QueuedVertex* v2 = &s_queued_vertices[start + i + 1];

                float px0 = v0->x, py0 = v0->y;
                float px1 = v1->x, py1 = v1->y;
                float px2 = v2->x, py2 = v2->y;

                if ((fabsf(px0 - px1) < 0.001f && fabsf(py0 - py1) < 0.001f) ||
                    (fabsf(px1 - px2) < 0.001f && fabsf(py1 - py2) < 0.001f) ||
                    (fabsf(px0 - px2) < 0.001f && fabsf(py0 - py2) < 0.001f)) {
                    continue;
                }

                float area = fabsf((px1 - px0) * (py2 - py0) - (py1 - py0) * (px2 - px0));
                if (area < 0.01f) continue;

                if (batch_count > 0 && (current_tex != tex || batch_count + 3 > MAX_BATCH_VERTS)) {
                    SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
                    batch_count = 0;
                }
                current_tex = tex;

                QueuedVertex* qverts[3] = { v0, v1, v2 };
                for (int k = 0; k < 3; k++) {
                    SDL_Vertex* v = &s_batch_verts[batch_count++];
                    v->position.x = (float)game_x + (qverts[k]->x / 640.0f) * (float)game_w;
                    v->position.y = (float)game_y + (qverts[k]->y / 480.0f) * (float)game_h;
                    v->color.r = qverts[k]->r;
                    v->color.g = qverts[k]->g;
                    v->color.b = qverts[k]->b;
                    v->color.a = qverts[k]->a;
                    v->tex_coord.x = qverts[k]->u;
                    v->tex_coord.y = qverts[k]->v;
                }
            }
        }
    }

    // Flush remaining batched vertices
    if (batch_count > 0) {
        SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
        batch_count = 0;
    }

    // Reset queue for next frame
    s_queued_vtx_count = 0;
    s_queued_draw_count = 0;
}

u64 gx_pipe_get_total_bytes(void) {
    return s_total_fifo_bytes;
}

u32 gx_pipe_get_draw_calls(void) {
    return s_draw_call_count;
}

void gx_pipe_shutdown(void) {
    for (u32 i = 0; i < s_tex_cache_count; i++) {
        if (s_tex_cache[i].sdl_tex) {
            SDL_DestroyTexture(s_tex_cache[i].sdl_tex);
            s_tex_cache[i].sdl_tex = NULL;
        }
    }
    s_tex_cache_count = 0;

    if (s_fifo_buf) {
        free(s_fifo_buf);
        s_fifo_buf = NULL;
    }
}
