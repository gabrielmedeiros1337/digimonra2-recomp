#include "dvd_vfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _MSC_VER
#define BSWAP32(x) _byteswap_ulong(x)
#else
#define BSWAP32(x) __builtin_bswap32(x)
#endif

static FILE* s_ciso_file = NULL;
static u32 s_fst_offset_iso = 0;
static u32 s_fst_size_iso = 0;

// CISO format metadata
static bool s_is_ciso = false;
static u32 s_ciso_block_size = 2097152;
static u8 s_ciso_map[0x8000 - 8];
static u32 s_ciso_block_positions[0x8000 - 8];

// DVD Hardware Registers
static u32 s_disr = 0;       // 0x00 Status
static u32 s_dicvr = 0;      // 0x04 Cover (0 = closed)
static u32 s_cmd_buf[3] = {0}; // 0x08, 0x0C, 0x10
static u32 s_dimar = 0;      // 0x14 DMA RAM Address
static u32 s_dilength = 0;   // 0x18 DMA Byte Count
static u32 s_dicr = 0;       // 0x1C Control

bool dvd_vfs_read_bytes(u64 virtual_dvd_offset, void* dst, u32 length) {
    if (!s_ciso_file) {
        printf("[DVD VFS] ERRO: Tentativa de leitura sem arquivo ISO/CISO aberto!\n");
        fflush(stdout);
        return false;
    }

    static u32 s_read_log_count = 0;
    if (s_read_log_count < 10) {
        s_read_log_count++;
        printf("[DVD VFS] Leitura de dados/FST: DVD Offset=0x%llX, Tamanho=%u bytes\n",
               virtual_dvd_offset, length);
        fflush(stdout);
    }

    if (!s_is_ciso) {
#ifdef _MSC_VER
        _fseeki64(s_ciso_file, (long long)virtual_dvd_offset, SEEK_SET);
#else
        fseeko(s_ciso_file, virtual_dvd_offset, SEEK_SET);
#endif
        return fread(dst, 1, length, s_ciso_file) == length;
    }

    u8* out = (u8*)dst;
    while (length > 0) {
        u32 block_idx = (u32)(virtual_dvd_offset / s_ciso_block_size);
        u32 offset_in_block = (u32)(virtual_dvd_offset % s_ciso_block_size);
        u32 chunk = s_ciso_block_size - offset_in_block;
        if (chunk > length) chunk = length;

        if (block_idx < sizeof(s_ciso_map) && s_ciso_map[block_idx] == 1) {
            u64 file_pos = 0x8000 + ((u64)s_ciso_block_positions[block_idx] * s_ciso_block_size) + offset_in_block;
#ifdef _MSC_VER
            _fseeki64(s_ciso_file, (long long)file_pos, SEEK_SET);
#else
            fseeko(s_ciso_file, file_pos, SEEK_SET);
#endif
            fread(out, 1, chunk, s_ciso_file);
        } else {
            memset(out, 0, chunk);
        }

        out += chunk;
        virtual_dvd_offset += chunk;
        length -= chunk;
    }
    return true;
}

bool dvd_vfs_init(const char* ciso_path, CPUState* cpu) {
    if (s_ciso_file) {
        fclose(s_ciso_file);
        s_ciso_file = NULL;
    }

    s_ciso_file = fopen(ciso_path, "rb");
    if (!s_ciso_file) {
        fprintf(stderr, "[DVD VFS] ERRO: Nao foi possivel abrir '%s'\n", ciso_path);
        return false;
    }

    // Check if CISO
    char magic[4];
    if (fread(magic, 1, 4, s_ciso_file) == 4 && memcmp(magic, "CISO", 4) == 0) {
        s_is_ciso = true;
        fread(&s_ciso_block_size, 1, 4, s_ciso_file);
        fread(s_ciso_map, 1, sizeof(s_ciso_map), s_ciso_file);

        u32 cur_file_block = 0;
        for (size_t i = 0; i < sizeof(s_ciso_map); i++) {
            if (s_ciso_map[i] == 1) {
                s_ciso_block_positions[i] = cur_file_block++;
            } else {
                s_ciso_block_positions[i] = 0xFFFFFFFFu;
            }
        }
        printf("[DVD VFS] Imagem CISO detectada! Bloco=%u bytes, Blocos fisicos=%u\n",
               s_ciso_block_size, cur_file_block);
    } else {
        s_is_ciso = false;
        printf("[DVD VFS] Imagem ISO pura (1:1 RAW) detectada.\n");
    }

    // Read FST offset and size from disc boot info (virtual DVD offset 0x424)
    u32 meta[2];
    if (dvd_vfs_read_bytes(0x424, meta, 8)) {
        s_fst_offset_iso = BSWAP32(meta[0]);
        s_fst_size_iso   = BSWAP32(meta[1]);
        printf("[DVD VFS] ISO montada! FST Offset: 0x%08X, Tamanho: %u bytes\n",
               s_fst_offset_iso, s_fst_size_iso);
        fflush(stdout);
    }

    s_disr = 0;
    s_dicvr = 0; // Cover closed
    return true;
}

bool dvd_vfs_load_fst(CPUState* cpu, u32 fst_ram_target) {
    if (!s_ciso_file || s_fst_size_iso == 0) return false;

    u32 ram_offset = fst_ram_target - GC_RAM_BASE;
    if (ram_offset + s_fst_size_iso > cpu->ram_size) {
        fprintf(stderr, "[DVD VFS] ERRO: Memoria insuficiente para FST em 0x%08X\n", fst_ram_target);
        return false;
    }

    if (!dvd_vfs_read_bytes(s_fst_offset_iso, cpu->ram + ram_offset, s_fst_size_iso)) {
        fprintf(stderr, "[DVD VFS] ERRO: Falha ao ler FST da imagem de disco!\n");
        return false;
    }

    // Write FST location and length to GameCube OS low memory
    u32 swapped_loc = BSWAP32(fst_ram_target);
    u32 swapped_len = BSWAP32(s_fst_size_iso);
    memcpy(cpu->ram + 0x38, &swapped_loc, 4); // 0x80000038 = FST address
    memcpy(cpu->ram + 0x3C, &swapped_len, 4); // 0x8000003C = FST size

    // GameCube Apploader / Dolphin standard: ArenaLo is placed immediately after the FST.
    // This ensures OSInit memset(ArenaLo, 0, ArenaHi - ArenaLo) does not wipe the CRT0 stack (0x803D54E0) or FST.
    u32 arena_lo = (fst_ram_target + s_fst_size_iso + 31) & ~31u;
    u32 swapped_arena_lo = BSWAP32(arena_lo);
    memcpy(cpu->ram + 0x30, &swapped_arena_lo, 4); // 0x80000030 = ArenaLo

    printf("[DVD VFS] FST carregada na RAM em 0x%08X (0x%08X - 0x%08X) | ArenaLo atualizado para 0x%08X\n",
           fst_ram_target, fst_ram_target, fst_ram_target + s_fst_size_iso, arena_lo);
    fflush(stdout);
    return true;
}

u32 dvd_vfs_read_reg(CPUState* cpu, u32 reg_offset) {
    switch (reg_offset) {
        case 0x00: return s_disr;
        case 0x04: return s_dicvr;
        case 0x08: return s_cmd_buf[0];
        case 0x0C: return s_cmd_buf[1];
        case 0x10: return s_cmd_buf[2];
        case 0x14: return s_dimar;
        case 0x18: return s_dilength;
        case 0x1C: return s_dicr;
        default: return 0;
    }
}

void dvd_vfs_write_reg(CPUState* cpu, u32 reg_offset, u32 value) {
    switch (reg_offset) {
        case 0x00:
            // Clear interrupt flags on write
            s_disr &= ~(value & 0x0000002A);
            s_disr |= (value & 0x00000001); // Interrupt mask
            break;
        case 0x04:
            s_dicvr = value;
            break;
        case 0x08: s_cmd_buf[0] = value; break;
        case 0x0C: s_cmd_buf[1] = value; break;
        case 0x10: s_cmd_buf[2] = value; break;
        case 0x14: s_dimar = value; break;
        case 0x18: s_dilength = value; break;
        case 0x1C: {
            s_dicr = value;
            // Bit 0 = Start DMA transfer
            if (value & 1) {
                u8 cmd = (s_cmd_buf[0] >> 24) & 0xFF;
                u64 dvd_offset = (u64)s_cmd_buf[1] << 2; // GameCube sector-to-byte offset
                u32 ram_dest = s_dimar;
                u32 length = s_dilength;

                if (cmd == 0xA8 || cmd == 0x00) { // Read command
                    if (ram_dest >= GC_RAM_BASE &&
                        (ram_dest - GC_RAM_BASE + length) <= cpu->ram_size) {
                        u32 ram_offset = ram_dest - GC_RAM_BASE;
                        dvd_vfs_read_bytes(dvd_offset, cpu->ram + ram_offset, length);
                        printf("[DVD VFS DMA] Leitura de Disco: Offset=0x%llX, Tam=%u bytes -> RAM=0x%08X\n",
                               dvd_offset, length, ram_dest);
                    }
                } else if (cmd == 0x12) { // Inquiry command
                    if (ram_dest >= GC_RAM_BASE && (ram_dest - GC_RAM_BASE + 32) <= cpu->ram_size) {
                        u32 ram_offset = ram_dest - GC_RAM_BASE;
                        u32 inq[8] = { 0, BSWAP32(0x20060526), BSWAP32(0x41000000), 0 };
                        memcpy(cpu->ram + ram_offset, inq, 32);
                        printf("[DVD VFS] DVD Inquiry atendido em RAM=0x%08X\n", ram_dest);
                    }
                }

                // DMA Complete: Update DMA pointers and set TCINT (bit 4 = 0x10)
                s_dimar += length;
                s_dilength = 0;
                s_disr |= 0x00000010u; // DOL_DI_STATUS_TCINT
                s_dicr &= ~1;          // DMA Idle
            }
            break;
        }
        default: break;
    }
}

void dvd_vfs_shutdown(void) {
    if (s_ciso_file) {
        fclose(s_ciso_file);
        s_ciso_file = NULL;
    }
}
