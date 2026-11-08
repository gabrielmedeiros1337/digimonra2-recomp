#include "dol_loader.h"
#include "portable_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _MSC_VER
#include <stdlib.h>
#define BSWAP32(x) _byteswap_ulong(x)
#else
#define BSWAP32(x) __builtin_bswap32(x)
#endif

// Helper to write big-endian 32-bit into guest RAM
static inline void write_u32_be(u8* ram, u32 ea, u32 val) {
    u32 offset = ea - GC_RAM_BASE;
    u32 swapped = BSWAP32(val);
    ppc_mark_host_write(ram+offset,4);
    memcpy(ram + offset, &swapped, 4);
}

typedef struct {FILE* file;const u8* data;size_t size,position;} DolInput;
static bool dol_seek(DolInput* in,size_t pos){if(in->file)return _fseeki64(in->file,pos,SEEK_SET)==0;if(pos>in->size)return false;in->position=pos;return true;}
static size_t dol_read(void* dest,size_t count,DolInput* in){if(in->file)return fread(dest,1,count,in->file);if(count>in->size-in->position)return 0;memcpy(dest,in->data+in->position,count);in->position+=count;return count;}
static bool dol_load_input(DolInput* in,CPUState* cpu,DolMetadata* meta_out){
    u32 hdr[64];
    if (dol_read(hdr, 0x100, in) != 0x100) {
        fprintf(stderr, "ERRO: Cabecalho do DOL corrompido ou truncado!\n");

        return false;
    }

    // DOL header:
    // 0x00..0x1C: 7 text section file offsets
    // 0x1C..0x48: 11 data section file offsets
    // 0x48..0x64: 7 text section ram addresses
    // 0x64..0x90: 11 data section ram addresses
    // 0x90..0xAC: 7 text section sizes
    // 0xAC..0xD8: 11 data section sizes
    // 0xD8..0xDC: BSS address
    // 0xDC..0xE0: BSS size
    // 0xE0..0xE4: Entry point

    u32 text_offsets[7];
    u32 data_offsets[11];
    u32 text_addrs[7];
    u32 data_addrs[11];
    u32 text_sizes[7];
    u32 data_sizes[11];

    for (int i = 0; i < 7; i++) {
        text_offsets[i] = BSWAP32(hdr[i]);
        text_addrs[i]   = BSWAP32(hdr[18 + i]);
        text_sizes[i]   = BSWAP32(hdr[36 + i]);
    }
    for (int i = 0; i < 11; i++) {
        data_offsets[i] = BSWAP32(hdr[7 + i]);
        data_addrs[i]   = BSWAP32(hdr[25 + i]);
        data_sizes[i]   = BSWAP32(hdr[43 + i]);
    }

    u32 bss_addr = BSWAP32(hdr[54]);
    u32 bss_size = BSWAP32(hdr[55]);
    u32 entry_point = BSWAP32(hdr[56]);

    printf("[DOL Loader] Loading verified boot image\n");
    printf("[DOL Loader] Entry point: 0x%08X\n", entry_point);
    printf("[DOL Loader] BSS: 0x%08X (tamanho: %u bytes)\n", bss_addr, bss_size);

    // Validate every section before mutating guest RAM; truncated input is fatal.
    if (entry_point < GC_RAM_BASE || entry_point - GC_RAM_BASE >= cpu->ram_size ||
        (bss_size && (bss_addr < GC_RAM_BASE || bss_addr - GC_RAM_BASE > cpu->ram_size ||
                      bss_size > cpu->ram_size - (bss_addr - GC_RAM_BASE)))) {
         return false;
    }
    for (int i = 0; i < 18; i++) {
        u32 addr = i < 7 ? text_addrs[i] : data_addrs[i - 7];
        u32 size = i < 7 ? text_sizes[i] : data_sizes[i - 7];
        if (size && (addr < GC_RAM_BASE || addr - GC_RAM_BASE > cpu->ram_size ||
                     size > cpu->ram_size - (addr - GC_RAM_BASE))) {
             return false;
        }
    }
    u32 highest_addr = 0;

    // Clear BSS section in RAM first (per Dolphin/GameCube IPL DOL bootloader specification)
    if (bss_size > 0 && bss_addr >= GC_RAM_BASE) {
        u32 bss_offset = bss_addr - GC_RAM_BASE;
        if (bss_offset + bss_size <= cpu->ram_size) {
            ppc_mark_host_write(cpu->ram+bss_offset,bss_size);
            memset(cpu->ram + bss_offset, 0, bss_size);
            printf("  -> BSS zerada: 0x%08X - 0x%08X (%u bytes)\n", bss_addr, bss_addr + bss_size, bss_size);
            if (bss_addr + bss_size > highest_addr) highest_addr = bss_addr + bss_size;
        }
    }

    // Load Text sections into RAM
    for (int i = 0; i < 7; i++) {
        if (text_sizes[i] > 0) {
            u32 ea = text_addrs[i];
            u32 sz = text_sizes[i];
            u32 off = text_offsets[i];
            if (ea >= GC_RAM_BASE && (ea + sz) <= (GC_RAM_BASE + cpu->ram_size)) {
                u32 ram_offset = ea - GC_RAM_BASE;
                if (!dol_seek(in,off)) {  return false; }
                ppc_mark_host_write(cpu->ram+ram_offset,sz);
            if (dol_read(cpu->ram+ram_offset,sz,in) != sz) {  return false; }
                {
                    printf("  -> Carregada .text%d: 0x%08X - 0x%08X (%u bytes)\n", i, ea, ea + sz, sz);
                    if (ea + sz > highest_addr) highest_addr = ea + sz;
                }
            }
        }
    }

    // Load Data sections into RAM (overwriting any initialized data within BSS range, e.g. .sdata in .data3)
    for (int i = 0; i < 11; i++) {
        if (data_sizes[i] > 0) {
            u32 ea = data_addrs[i];
            u32 sz = data_sizes[i];
            u32 off = data_offsets[i];
            if (ea >= GC_RAM_BASE && (ea + sz) <= (GC_RAM_BASE + cpu->ram_size)) {
                u32 ram_offset = ea - GC_RAM_BASE;
                if (!dol_seek(in,off)) {  return false; }
                ppc_mark_host_write(cpu->ram+ram_offset,sz);
            if (dol_read(cpu->ram+ram_offset,sz,in) != sz) {  return false; }
                {
                    printf("  -> Carregada .data%d: 0x%08X - 0x%08X (%u bytes)\n", i, ea, ea + sz, sz);
                    if (ea + sz > highest_addr) highest_addr = ea + sz;
                }
            }
        }
    }



    printf("  -> Verificacao .data3 (0x803BF258): 0x%08X\n", mem_read32(cpu, 0x803BF258u));

    // Initialize GameCube OS Low Memory Structure (0x80000000 - 0x80003000)
    u32 arena_lo = (highest_addr + 31) & ~31; // Align to 32 bytes
    if (arena_lo < 0x80400000u) arena_lo = 0x80400000u; // Ensure ArenaLo is safely above CRT0 boot stack (0x803D54E0)
    u32 arena_hi = 0x817FEC60u; // Real hardware / Dolphin BS2 ArenaHi
    u32 init_stack = 0x817FFF00u; // Boot stack ABOVE ArenaHi so OSInit memset never wipes the stack

    write_u32_be(cpu->ram, 0x80000020, 0x0D15EA5E);     // OSBootInfo Magic
    write_u32_be(cpu->ram, 0x80000024, 1);              // OSBootInfo Version
    write_u32_be(cpu->ram, 0x80000028, cpu->ram_size);   // OSPhysicalMemSize = 24MB
    write_u32_be(cpu->ram, 0x8000002C, 2);              // OSConsoleType = Dev/Retail Board
    write_u32_be(cpu->ram, 0x80000030, arena_lo);       // ArenaLo
    write_u32_be(cpu->ram, 0x80000034, arena_hi);       // ArenaHi
    write_u32_be(cpu->ram, 0x800000F8, 162000000);      // BusClock
    write_u32_be(cpu->ram, 0x800000FC, 486000000);      // CoreClock

    // Metadata out
    if (meta_out) {
        meta_out->entry_point = entry_point;
        meta_out->bss_addr = bss_addr;
        meta_out->bss_size = bss_size;
        meta_out->sda_base = data_addrs[3];  // .data3 = SDA
        meta_out->sda2_base = data_addrs[4]; // .data4 = SDA2
        meta_out->arena_lo = arena_lo;
        meta_out->arena_hi = arena_hi;
    }

    // Initial registers
    cpu->pc = entry_point;
    cpu->gpr[1] = init_stack;             // Stack pointer (r1) above ArenaHi
    cpu->gpr[2] = data_addrs[4];          // r2 (SDA2)
    cpu->gpr[13] = data_addrs[3];         // r13 (SDA)

    printf("[DOL Loader] Inicializacao concluida. Stack = 0x%08X, Arena = 0x%08X - 0x%08X\n",
           cpu->gpr[1], arena_lo, arena_hi);

    return true;
}

bool dol_load(const char* path,CPUState* cpu,DolMetadata* meta){FILE* f=portable_fopen(path,"rb");if(!f)return false;DolInput in={f,0,0,0};bool ok=dol_load_input(&in,cpu,meta);fclose(f);return ok;}
bool dol_load_memory(const void* data,size_t size,CPUState* cpu,DolMetadata* meta){DolInput in={0,data,size,0};return dol_load_input(&in,cpu,meta);}
