#include "dvd_vfs.h"
#include "video_audio.h"
#include "hle_callbacks.h"
#include <SDL.h>
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
static SDL_mutex* s_io_mutex;
typedef struct {u32 info,destination,length,callback;u64 offset;u8* data;bool hardware,ok,done;} DVDJob;
static DVDJob s_jobs[16];static u32 s_head,s_tail,s_worker_next,s_count;
static SDL_mutex* s_job_mutex;static SDL_sem* s_job_ready;static SDL_Thread* s_io_thread;static bool s_stop;
static SDL_atomic_t s_completed;
static bool s_di_pending;
static int dvd_worker(void* unused){
    (void)unused;
    for(;;){
        if(SDL_SemWait(s_job_ready)!=0)return -1;
        SDL_LockMutex(s_job_mutex);if(s_stop){SDL_UnlockMutex(s_job_mutex);break;}
        DVDJob* job=s_jobs+s_worker_next;SDL_UnlockMutex(s_job_mutex);
        bool ok=dvd_vfs_read_bytes(job->offset,job->data,job->length);
        SDL_LockMutex(s_job_mutex);job->ok=ok;job->done=true;s_worker_next=(s_worker_next+1)%16;SDL_AtomicAdd(&s_completed,1);SDL_UnlockMutex(s_job_mutex);
    }
    return 0;
}
static bool submit_read(u32 info,u32 destination,u32 length,u64 offset,u32 callback,bool hardware){
    if(length>GC_MAIN_RAM_SIZE)return false;
    if(!s_io_thread){
        s_job_mutex=SDL_CreateMutex();s_job_ready=SDL_CreateSemaphore(0);s_stop=false;
        if(s_job_mutex && s_job_ready)s_io_thread=SDL_CreateThread(dvd_worker,"DVD reads",NULL);
        if(!s_io_thread){if(s_job_mutex)SDL_DestroyMutex(s_job_mutex);if(s_job_ready)SDL_DestroySemaphore(s_job_ready);s_job_mutex=NULL;s_job_ready=NULL;return false;}
    }
    u8* data=malloc(length ? length:1u);if(!data)return false;
    SDL_LockMutex(s_job_mutex);
    if(s_count==16){SDL_UnlockMutex(s_job_mutex);free(data);return false;}
    s_jobs[s_tail]=(DVDJob){info,destination,length,callback,offset,data,hardware,false,false};s_tail=(s_tail+1)%16;s_count++;
    SDL_UnlockMutex(s_job_mutex);SDL_SemPost(s_job_ready);return true;
}
bool dvd_vfs_read_async(u32 info,u32 destination,u32 length,u32 offset,u32 callback){return submit_read(info,destination,length,offset,callback,false);}
u32 dvd_vfs_pending_reads(void){if(!s_job_mutex)return 0;SDL_LockMutex(s_job_mutex);u32 count=s_count;SDL_UnlockMutex(s_job_mutex);return count;}
void dvd_vfs_pump(CPUState* cpu){
    if(!SDL_AtomicGet(&s_completed))return;
    for(u32 n=0;n<16;n++){
        SDL_LockMutex(s_job_mutex);DVDJob job=s_jobs[s_head];
        if(!s_count || !job.done || (!job.hardware && job.callback && !hle_callbacks_has_space())){SDL_UnlockMutex(s_job_mutex);break;}
        memset(s_jobs+s_head,0,sizeof(DVDJob));s_head=(s_head+1)%16;s_count--;SDL_AtomicAdd(&s_completed,-1);SDL_UnlockMutex(s_job_mutex);
        u32 off=job.destination-GC_RAM_BASE;
        bool ok=job.ok && job.destination>=GC_RAM_BASE && off<=cpu->ram_size && job.length<=cpu->ram_size-off;
        if(ok && job.length){
            ppc_mark_host_write(cpu->ram+off,job.length);
            memcpy(cpu->ram+off,job.data,job.length);
            if(g_mem_write_journal)g_mem_write_journal(job.destination,job.length,g_mem_write_journal_user);
            u32 line=(cpu->reserve_addr&0x1FFFFFFFu)&~31u;
            if(cpu->reserve_valid && (u64)off+job.length>line && (u64)line+32>off)cpu->reserve_valid=false;
        }
        if(job.hardware){s_di_pending=false;s_dimar+=job.length;s_dilength=0;s_disr|=ok ? 0x10u:4u;s_dicr&=~1u;video_set_di_interrupt((s_disr&(s_disr<<1)&0x54u)!=0);}
        else if(job.info>=GC_RAM_BASE && job.info-GC_RAM_BASE<=cpu->ram_size && 48<=cpu->ram_size-(job.info-GC_RAM_BASE)){
            mem_write32(cpu,job.info+8,1);mem_write32(cpu,job.info+16,(u32)job.offset);mem_write32(cpu,job.info+20,job.length);mem_write32(cpu,job.info+24,job.destination);mem_write32(cpu,job.info+40,job.callback);
            mem_write32(cpu,job.info+12,ok ? 0:0xFFFFFFFFu);mem_write32(cpu,job.info+28,ok ? job.length:0);mem_write32(cpu,job.info+32,ok ? job.length:0);
            if(job.callback)hle_callbacks_enqueue(job.callback,ok ? job.length:0xFFFFFFFFu,job.info);
        }
        free(job.data);
    }
}

static bool read_bytes_unlocked(u64 virtual_dvd_offset, void* dst, u32 length) {
    if (!dst && length) return false;
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
        if (_fseeki64(s_ciso_file, (long long)virtual_dvd_offset, SEEK_SET) != 0) return false;
#else
        if (fseeko(s_ciso_file, virtual_dvd_offset, SEEK_SET) != 0) return false;
#endif
        return fread(dst, 1, length, s_ciso_file) == length;
    }

    u8* out = (u8*)dst;
    while (length > 0) {
        u32 block_idx = (u32)(virtual_dvd_offset / s_ciso_block_size);
        u32 offset_in_block = (u32)(virtual_dvd_offset % s_ciso_block_size);
        u32 chunk = s_ciso_block_size - offset_in_block;
        if (chunk > length) chunk = length;

        if (block_idx >= sizeof(s_ciso_map)) return false;
        if (s_ciso_map[block_idx] == 1) {
            u64 file_pos = 0x8000 + ((u64)s_ciso_block_positions[block_idx] * s_ciso_block_size) + offset_in_block;
#ifdef _MSC_VER
            if (_fseeki64(s_ciso_file, (long long)file_pos, SEEK_SET) != 0) return false;
#else
            if (fseeko(s_ciso_file, file_pos, SEEK_SET) != 0) return false;
#endif
            if (fread(out, 1, chunk, s_ciso_file) != chunk) return false;
        } else {
            memset(out, 0, chunk);
        }

        out += chunk;
        virtual_dvd_offset += chunk;
        length -= chunk;
    }
    return true;
}
bool dvd_vfs_read_bytes(u64 offset,void* destination,u32 length){
    if(s_io_mutex)SDL_LockMutex(s_io_mutex);bool ok=read_bytes_unlocked(offset,destination,length);if(s_io_mutex)SDL_UnlockMutex(s_io_mutex);return ok;
}

bool dvd_vfs_init(const char* ciso_path, CPUState* cpu) {
    dvd_vfs_shutdown();

    s_ciso_file = fopen(ciso_path, "rb");
    if (!s_ciso_file) {
        fprintf(stderr, "[DVD VFS] ERRO: Nao foi possivel abrir '%s'\n", ciso_path);
        return false;
    }
    s_io_mutex=SDL_CreateMutex();if(!s_io_mutex){dvd_vfs_shutdown();return false;}

    // Check if CISO
    char magic[4];
    if (fread(magic, 1, 4, s_ciso_file) == 4 && memcmp(magic, "CISO", 4) == 0) {
        s_is_ciso = true;
        u8 size_bytes[4];
        if (fread(size_bytes, 1, 4, s_ciso_file) != 4 ||
            fread(s_ciso_map, 1, sizeof(s_ciso_map), s_ciso_file) != sizeof(s_ciso_map)) {
            dvd_vfs_shutdown(); return false;
        }
        s_ciso_block_size = (u32)size_bytes[0] | ((u32)size_bytes[1] << 8) |
            ((u32)size_bytes[2] << 16) | ((u32)size_bytes[3] << 24);
        if (!s_ciso_block_size || (s_ciso_block_size & (s_ciso_block_size - 1))) {
            dvd_vfs_shutdown(); return false;
        }

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
    s_fst_offset_iso = s_fst_size_iso = 0;
    u32 meta[2];
    if (dvd_vfs_read_bytes(0x424, meta, 8)) {
        s_fst_offset_iso = BSWAP32(meta[0]);
        s_fst_size_iso   = BSWAP32(meta[1]);
        printf("[DVD VFS] ISO montada! FST Offset: 0x%08X, Tamanho: %u bytes\n",
               s_fst_offset_iso, s_fst_size_iso);
        fflush(stdout);
    }

    if (!s_fst_size_iso || s_fst_size_iso > cpu->ram_size) { dvd_vfs_shutdown(); return false; }
    s_disr = 0;
    s_dicvr = 0; // Cover closed
    return true;
}

bool dvd_vfs_load_fst(CPUState* cpu, u32 fst_ram_target) {
    if (!s_ciso_file || s_fst_size_iso == 0) return false;

    u32 ram_offset = fst_ram_target - GC_RAM_BASE;
    if (fst_ram_target < GC_RAM_BASE || ram_offset > cpu->ram_size || s_fst_size_iso > cpu->ram_size - ram_offset) {
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
            s_disr = (s_disr & 0x54u & ~(value & 0x54u)) | (value & 0x2Au);
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
            if(s_di_pending){s_dicr|=1;break;}
            s_dicr = value;
            // Bit 0 = Start DMA transfer
            if (value & 1) {
                u8 cmd = (s_cmd_buf[0] >> 24) & 0xFF;
                u64 dvd_offset = (u64)s_cmd_buf[1] << 2; // GameCube sector-to-byte offset
                u32 ram_dest = (s_dimar & 0x1FFFFFFu) | GC_RAM_BASE;
                bool success = false;
                u32 length = s_dilength;

                if (cmd == 0xA8 || cmd == 0x00) { // Read command
                    if (ram_dest >= GC_RAM_BASE &&
                        (u64)(ram_dest - GC_RAM_BASE) + length <= cpu->ram_size) {
                        if(submit_read(0,ram_dest,length,dvd_offset,0,true)){s_di_pending=true;break;}
                    }
                } else if (cmd == 0x12) { // Inquiry command
                    if (ram_dest >= GC_RAM_BASE && (ram_dest - GC_RAM_BASE + 32) <= cpu->ram_size) {
                        u32 ram_offset = ram_dest - GC_RAM_BASE;
                        u32 inq[8] = { 0, BSWAP32(0x20060526), BSWAP32(0x41000000), 0 };
                        ppc_mark_host_write(cpu->ram+ram_offset,32);
                        memcpy(cpu->ram + ram_offset, inq, 32);
                        success = true;
                        printf("[DVD VFS] DVD Inquiry atendido em RAM=0x%08X\n", ram_dest);
                    }
                }

                // DMA Complete: Update DMA pointers and set TCINT (bit 4 = 0x10)
                s_dimar += length;
                s_dilength = 0;
                s_disr |= success ? 0x00000010u : 0x00000004u; // DOL_DI_STATUS_TCINT
                s_dicr &= ~1;          // DMA Idle
            }
            break;
        }
        default: break;
    }
    video_set_di_interrupt((s_disr & (s_disr << 1) & 0x54u) != 0);
}

void dvd_vfs_shutdown(void) {
    if(s_io_thread){SDL_LockMutex(s_job_mutex);s_stop=true;SDL_UnlockMutex(s_job_mutex);SDL_SemPost(s_job_ready);SDL_WaitThread(s_io_thread,NULL);s_io_thread=NULL;}
    if(s_job_mutex)SDL_DestroyMutex(s_job_mutex);if(s_job_ready)SDL_DestroySemaphore(s_job_ready);s_job_mutex=NULL;s_job_ready=NULL;
    for(u32 i=0;i<16;i++)free(s_jobs[i].data);memset(s_jobs,0,sizeof(s_jobs));s_head=s_tail=s_worker_next=s_count=0;SDL_AtomicSet(&s_completed,0);
    if (s_ciso_file) {
        fclose(s_ciso_file);
        s_ciso_file = NULL;
    }
    if(s_io_mutex)SDL_DestroyMutex(s_io_mutex);s_io_mutex=NULL;
    s_di_pending=false;s_dicr=s_disr=s_dilength=0;video_set_di_interrupt(false);
}
