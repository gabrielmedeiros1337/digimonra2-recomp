#include "frame_timing.h"
#include "gx_pipe.h"
#include "gx_frame.h"
#include "video_audio.h"
#include "gx_gl.h"
#include "vertex_completion.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>
#if defined(DIGIMON_XXHASH)
#define XXH_INLINE_ALL
#include "xxhash.h"
#endif
#if defined(_M_X64) || defined(__x86_64__)
#include <xmmintrin.h>
#endif

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
static u32 s_fifo_needed=1;
static u64 s_fifo_stores,s_fifo_lines,s_fifo_deferred,s_fifo_parses;
static u64 s_total_fifo_bytes = 0;
static u64 s_submitted_display_copies;
u64 gx_pipe_get_submitted_display_copies(void){return s_submitted_display_copies;}
static u32 s_draw_call_count = 0;
static u8* s_display_list_buffers[8];
static u8* s_readback_pixels;
static int s_dl_depth;

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
static u32 s_cp_distance, s_cp_breakpoint;
static u32 s_pi_fifo_base, s_pi_fifo_end, s_pi_fifo_write;
static u8 s_gather[32];
static u32 s_gather_count;


// Pixel Engine (PE) Registers
static u16 s_pe_status = 0x000F; // PE Idle & Ready
static u16 s_pe_token = 0;
static SDL_Renderer* s_renderer;
static SDL_Texture* s_efb;
static float s_internal_scale = 1.0f;
typedef struct {u32 address,width,height,pitch,scaled_w,scaled_h;SDL_Texture* image;bool pending;} XFBImage;
static XFBImage s_xfb_images[8];
static bool s_xfb_vram;
static u64 s_xfb_gpu_copies,s_xfb_resolves;
void gx_pipe_set_internal_scale(float scale) {
    if(scale<1.0f)scale=1.0f;if(scale>4.0f)scale=4.0f;
    s_internal_scale=scale;gx_gl_set_internal_scale(scale);
    if(s_efb){
        int w=0,h=0;SDL_QueryTexture(s_efb,NULL,NULL,&w,&h);
        int target_w=(int)(640.0f*scale+0.5f),target_h=(int)(528.0f*scale+0.5f);
        if(w!=target_w || h!=target_h){SDL_DestroyTexture(s_efb);s_efb=NULL;}
    }
}
float gx_pipe_get_internal_scale(void){return s_internal_scale;}
static int s_aspect_ratio = 0;
void gx_pipe_set_aspect_ratio(int ratio) {
    s_aspect_ratio = (ratio == 1) ? 1 : 0;
    gx_gl_set_aspect_ratio(s_aspect_ratio);
    video_set_aspect_ratio(s_aspect_ratio);
}
int gx_pipe_get_aspect_ratio(void) { return s_aspect_ratio; }
static bool resolve_xfb(CPUState* cpu,XFBImage* image) {
    if(!image->pending)return true;
    u32 offset=image->address-GC_RAM_BASE;
    if(offset>cpu->ram_size || (u64)image->pitch*image->height>cpu->ram_size-offset)return false;
    SDL_Rect source={0,0,(int)image->width,(int)image->height};
    FrameStage stage=frame_timing_enter(FRAME_EFB_COPY);
    bool ok=gx_gl_pack_yuy2(s_renderer,image->image,&source,image->height,cpu->ram+offset,image->pitch);
    frame_timing_leave(stage);
    if(ok){ppc_mark_host_write(cpu->ram+offset,image->pitch*image->height);image->pending=false;s_xfb_resolves++;}return ok;
}
bool gx_pipe_set_xfb_vram(CPUState* cpu,bool enabled) {
    if(s_xfb_vram==enabled)return true;
    if(!enabled)for(u32 i=0;i<8;i++)if(!resolve_xfb(cpu,s_xfb_images+i))return false;
    s_xfb_vram=enabled;return true;
}
void gx_pipe_xfb_diagnostics(u64* copies,u64* resolves){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);*copies=x.xfb_copies;*resolves=x.xfb_resolves;return;}*copies=s_xfb_gpu_copies;*resolves=s_xfb_resolves;}
bool gx_pipe_present_xfb(SDL_Renderer* renderer,u32 address,const SDL_Rect* dest) {
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].pending && s_xfb_images[i].address==address)
        return SDL_RenderCopy(renderer,s_xfb_images[i].image,NULL,dest)==0;
    return false;
}
static bool snapshot_xfb(CPUState* cpu,u32 address,u32 width,u32 height,u32 pitch,const SDL_Rect* source) {
    XFBImage* image=NULL;
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].address==address){image=s_xfb_images+i;break;}
    if(!image)for(u32 i=0;i<8;i++)if(!s_xfb_images[i].pending){image=s_xfb_images+i;break;}
    if(!image)return false; // Preserve all live VI allocations; use RAM fallback at capacity.
    u32 scaled_w = (u32)(width * s_internal_scale + 0.5f);
    u32 scaled_h = (u32)(height * s_internal_scale + 0.5f);
    if(image->image && (image->width!=width || image->height!=height || image->scaled_w!=scaled_w || image->scaled_h!=scaled_h)) {
        if(!resolve_xfb(cpu,image))return false;
        SDL_DestroyTexture(image->image);image->image=NULL;
    }
    if(!image->image)image->image=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,scaled_w,scaled_h);
    if(!image->image)return false;
    SDL_Rect scaled_source = {
        (int)(source->x * s_internal_scale + 0.5f),
        (int)(source->y * s_internal_scale + 0.5f),
        (int)(source->w * s_internal_scale + 0.5f),
        (int)(source->h * s_internal_scale + 0.5f)
    };
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_BlendMode blend;
    SDL_GetTextureBlendMode(s_efb,&blend);SDL_SetTextureBlendMode(s_efb,SDL_BLENDMODE_NONE);
    bool ok=SDL_SetRenderTarget(s_renderer,image->image)==0;
    if(ok)ok=SDL_RenderCopy(s_renderer,s_efb,&scaled_source,NULL)==0;
    SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,previous);SDL_SetTextureBlendMode(s_efb,blend);
    if(ok){image->address=address;image->width=width;image->height=height;image->pitch=pitch;image->scaled_w=scaled_w;image->scaled_h=scaled_h;image->pending=true;s_xfb_gpu_copies++;}
    return ok;
}
static u32 s_bp[256];
static bool s_bp_written[256];
static u32 s_tev_registers[8], s_konst_registers[8];
static u32 s_cp[256], s_xf[0x1058];
static bool s_projection_loaded,s_lighting_loaded;
static u64 s_matrix_valid;
static bool s_normal_lighting_required,s_scalar_transforms;
static void write_xf_word(u32 address,u32 value) {
    if(address>=0x1058)return;
    s_xf[address]=value;
    if(address<0x108 || (address>=0x400 && address<0x466))s_matrix_valid=0;
}
static u32 s_bp_mask = 0xFFFFFFu;
static void gx_pipe_process_internal(CPUState* cpu);
static bool flush_efb(CPUState* cpu);
static bool copy_efb(CPUState* cpu, u32 control);
static bool copy_efb_texture(CPUState* cpu,u32 control);

void gx_pipe_set_renderer(SDL_Renderer* renderer) {
    s_renderer = renderer;
    if (s_renderer && !s_efb) {
        int efb_w = (int)(640.0f * s_internal_scale + 0.5f);
        int efb_h = (int)(528.0f * s_internal_scale + 0.5f);
        s_efb = SDL_CreateTexture(s_renderer, SDL_PIXELFORMAT_RGBA32,
                                  SDL_TEXTUREACCESS_TARGET, efb_w, efb_h);
        if (s_efb) {
            SDL_Texture* prev = SDL_GetRenderTarget(s_renderer);
            SDL_SetRenderTarget(s_renderer, s_efb);
            SDL_SetRenderDrawColor(s_renderer, 0, 0, 0, 255);
            SDL_RenderClear(s_renderer);
            SDL_SetRenderTarget(s_renderer, prev);
        }
    }
}


bool gx_pipe_init(CPUState* cpu) {
    if (!s_fifo_buf) {
        s_fifo_buf = (u8*)malloc(FIFO_BUFFER_SIZE);
        if (!s_fifo_buf) {
            fprintf(stderr, "[GX Pipe] Falha ao alocar buffer FIFO de 1MB!\n");
            return false;
        }
    }

    s_fifo_write_head = 0;
    s_fifo_read_tail = 0;s_fifo_needed=1;
    s_total_fifo_bytes = 0;
    s_submitted_display_copies=0;
    s_draw_call_count = 0;
    s_matrix_valid=0;

    s_cp_status = 0x000E;
    s_pe_status = 0x000F;

    s_bp[0x49] = 0;
    s_bp[0x4A] = 639u | (479u << 10);
    s_bp[0x4D] = (640u * 2u) >> 5;
    s_bp[0x4E] = 256;
    s_bp[0x20] = 0;
    s_bp[0x21] = 639u | (479u << 12);
    s_bp_written[0x20] = true;
    s_bp_written[0x21] = true;
    float vp_w2 = 320.0f, vp_h2 = -240.0f, vp_zscale = 16777215.0f;
    float vp_ox = 320.0f + 342.0f, vp_oy = 240.0f + 342.0f, vp_zoffset = 0.0f;
    memcpy(&s_xf[0x101A], &vp_w2, 4);
    memcpy(&s_xf[0x101B], &vp_h2, 4);
    memcpy(&s_xf[0x101C], &vp_zscale, 4);
    memcpy(&s_xf[0x101D], &vp_ox, 4);
    memcpy(&s_xf[0x101E], &vp_oy, 4);
    memcpy(&s_xf[0x101F], &vp_zoffset, 4);
    s_xfb_vram = true;

    printf("[GX GPU Pipe] Pipeline de Comandos GX (Flipper GPU) inicializado.\n");
    return true;
}

// Command Processor (CP) MMIO Handlers (0xCC000000 - 0xCC00007F)
u32 gx_pipe_read_cp(CPUState* cpu, u32 offset) {
    if((offset&0x7Eu)==0 && (s_cp_control&1u) && s_cp_distance>=32)gx_pipe_process_frame(cpu);
    switch (offset & 0x7Eu) {
    case 0: return s_cp_status | (s_cp_distance == 0 ? 0xCu : 0);
    case 2: return s_cp_control;
    case 4: return s_cp_clear;
    case 0x20: return s_cp_base & 0xFFFFu;
    case 0x22: return s_cp_base >> 16;
    case 0x24: return s_cp_end & 0xFFFFu;
    case 0x26: return s_cp_end >> 16;
    case 0x28: return s_cp_hi_watermark & 0xFFFFu;
    case 0x2A: return s_cp_hi_watermark >> 16;
    case 0x2C: return s_cp_lo_watermark & 0xFFFFu;
    case 0x2E: return s_cp_lo_watermark >> 16;
    case 0x30: return s_cp_distance & 0xFFFFu;
    case 0x32: return s_cp_distance >> 16;
    case 0x34: return s_cp_write_ptr & 0xFFFFu;
    case 0x36: return s_cp_write_ptr >> 16;
    case 0x38: return s_cp_read_ptr & 0xFFFFu;
    case 0x3A: return s_cp_read_ptr >> 16;
    case 0x3C: return s_cp_breakpoint & 0xFFFFu;
    case 0x3E: return s_cp_breakpoint >> 16;
    default: return 0;
    }
}
static void cp_half(u32* reg, u32 offset, u32 value) {
    if (offset & 2) *reg = (*reg & 0xFFFFu) | ((value & 0xFFFFu) << 16);
    else *reg = (*reg & 0xFFFF0000u) | (value & 0xFFFFu);
}
void gx_pipe_write_cp(CPUState* cpu, u32 offset, u32 value) {
    (void)cpu;
    switch (offset & 0x7Eu) {
    case 2:
        s_cp_control = (u16)value;
        if(value&1u)gx_pipe_process_frame(cpu); // newly selected RAM FIFO is ready now
        break;
    case 4: s_cp_clear = (u16)value; break;
    default:
        switch (offset & 0x7Cu) {
        case 0x20: cp_half(&s_cp_base,offset,value); break;
        case 0x24: cp_half(&s_cp_end,offset,value); break;
        case 0x28: cp_half(&s_cp_hi_watermark,offset,value); break;
        case 0x2C: cp_half(&s_cp_lo_watermark,offset,value); break;
        case 0x30: cp_half(&s_cp_distance,offset,value); break;
        case 0x34: cp_half(&s_cp_write_ptr,offset,value); break;
        case 0x38: cp_half(&s_cp_read_ptr,offset,value); break;
        case 0x3C: cp_half(&s_cp_breakpoint,offset,value); break;
        }
        break;
    }
}
u32 gx_pipe_read_pi(u32 offset) {
    if (offset == 0x0C) return s_pi_fifo_base;
    if (offset == 0x10) return s_pi_fifo_end;
    if (offset == 0x14) return s_pi_fifo_write;
    return 0;
}
void gx_pipe_write_pi(u32 offset, u32 value) {
    value &= 0x01FFFFE0u;
    if (offset == 0x0C) s_pi_fifo_base = value;
    if (offset == 0x10) s_pi_fifo_end = value;
    if (offset == 0x14) s_pi_fifo_write = value;
}

// Pixel Engine (PE) MMIO Handlers (0xCC001000 - 0xCC00103F)
u32 gx_pipe_read_pe(CPUState* cpu, u32 reg_offset) {
    switch (reg_offset & 0x3E) {
        case 0x04: return s_pe_status; // PE Status
        case 0x06: return s_pe_status;
        case 0x0A: return s_pe_status;
        case 0x0E: return s_pe_token;  // PE Token return
        default: return 0;
    }
}

void gx_pipe_write_pe(CPUState* cpu, u32 reg_offset, u32 val) {
    switch (reg_offset & 0x3E) {
        case 0x0A:
            s_pe_status = (u16)(val & 3u);
            video_set_pe_enable(val);
            video_ack_pe((val & 4u) != 0, (val & 8u) != 0);
            break;
        case 0x0E: s_pe_token = (u16)val; break;
        default: break;
    }
}

// Copy one linked gather line immediately (CP read/distance stay observable),
// but only run the parser when a complete next packet can be available. This
// never delays a completed indexed draw past the store that completes it.
static void consume_linked_line(CPUState* cpu){
    u32 available=(s_fifo_write_head+FIFO_BUFFER_SIZE-s_fifo_read_tail)%FIFO_BUFFER_SIZE;
    if(s_cp_distance!=32 || ((s_cp_control&2u) && s_cp_read_ptr==s_cp_breakpoint) ||
       s_cp_read_ptr>cpu->ram_size-32 || s_cp_read_ptr<s_cp_base || s_cp_read_ptr>s_cp_end ||
       available+32>=FIFO_BUFFER_SIZE){gx_pipe_process_frame(cpu);return;}
    u32 first=FIFO_BUFFER_SIZE-s_fifo_write_head;if(first>32)first=32;
    memcpy(s_fifo_buf+s_fifo_write_head,cpu->ram+s_cp_read_ptr,first);
    if(first<32)memcpy(s_fifo_buf,cpu->ram+s_cp_read_ptr+first,32-first);
    s_fifo_write_head=(s_fifo_write_head+32)%FIFO_BUFFER_SIZE;
    s_cp_read_ptr+=32;if(s_cp_read_ptr>s_cp_end)s_cp_read_ptr=s_cp_base;
    s_cp_distance=0;
    if(available+32<s_fifo_needed){s_fifo_deferred++;return;}
    gx_pipe_process_internal(cpu);
}
void gx_pipe_fifo_diagnostics(u64* stores,u64* lines,u64* deferred,u64* parses){
    *stores=s_fifo_stores;*lines=s_fifo_lines;*deferred=s_fifo_deferred;*parses=s_fifo_parses;
}

// Write port into the Gather Pipe (0xCC008000 / 0x0C008000)
void gx_pipe_write_fifo(CPUState* cpu, u32 ea, u64 value, u8 size) {
    if (!s_fifo_buf) return;

    s_fifo_stores++;
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

    if (s_pi_fifo_end > s_pi_fifo_base && s_pi_fifo_end < cpu->ram_size) {
        for(u32 j=0;j<size;){
            u32 batch=32-s_gather_count;if(batch>size-j)batch=size-j;
            memcpy(s_gather+s_gather_count,bytes+j,batch);s_gather_count+=batch;j+=batch;
            if (s_gather_count == 32) {
                if (s_pi_fifo_write >= s_pi_fifo_base && s_pi_fifo_write <= s_pi_fifo_end &&
                    s_pi_fifo_write <= cpu->ram_size - 32) {
                    ppc_mark_host_write(cpu->ram+s_pi_fifo_write,32);
                    memcpy(cpu->ram + s_pi_fifo_write, s_gather, 32);
                    u32 next = s_pi_fifo_write + 32;
                    if (next > s_pi_fifo_end) next = s_pi_fifo_base;
                    if ((s_cp_control & 0x10u) && s_cp_base == s_pi_fifo_base) {
                        s_cp_write_ptr = next; s_cp_distance += 32;
                    }
                    s_pi_fifo_write = next;
                }
                s_gather_count = 0;s_fifo_lines++;
                // GP runs concurrently with the producer. Decode linked FIFO packets
                // before the guest can recycle transient indexed vertex arrays.
                if ((s_cp_control&0x11u)==0x11u) consume_linked_line(cpu);
            }
        }
        s_total_fifo_bytes += size;
        return;
    }
    u32 available = (s_fifo_write_head + FIFO_BUFFER_SIZE - s_fifo_read_tail) % FIFO_BUFFER_SIZE;
    if (available + size >= FIFO_BUFFER_SIZE) gx_pipe_process_internal(cpu);
    available = (s_fifo_write_head + FIFO_BUFFER_SIZE - s_fifo_read_tail) % FIFO_BUFFER_SIZE;
    if (available + size >= FIFO_BUFFER_SIZE) {
        fprintf(stderr, "[GX] FIFO full: incomplete packet; refusing overwrite\n");
        cpu->exception |= PPC_EXC_PROGRAM;
        return;
    }
    u32 first=FIFO_BUFFER_SIZE-s_fifo_write_head;if(first>size)first=size;
    memcpy(s_fifo_buf+s_fifo_write_head,bytes,first);
    if(first<size)memcpy(s_fifo_buf,bytes+first,size-first);
    s_fifo_write_head=(s_fifo_write_head+size)%FIFO_BUFFER_SIZE;

    static bool s_first_fifo_cmd = false;
    if (!s_first_fifo_cmd) {
        s_first_fifo_cmd = true;
        printf("[GX GPU Pipe] Primeiro comando recebido no FIFO da GPU! (ea=0x%08X, size=%u, val=0x%llX)\n",
               ea, size, value);
        fflush(stdout);
    }

    static FILE* trace;
    static bool trace_checked;
    if (!trace_checked) { const char* path = getenv("GX_FIFO_TRACE"); if (path && *path) trace = fopen(path, "wb"); trace_checked = true; }
    if (trace) { fwrite(bytes, 1, size, trace); fflush(trace); }
    s_total_fifo_bytes += size;
}

#define MAX_QUEUED_VERTICES 65536
#define MAX_QUEUED_DRAWS 2048

typedef struct {
    float x, y;
    u8 r, g, b, a;
    float u, v;
    GXGLVertex native;
    float object_position[3];
    u32 object_matrix;
    u8 position_bytes[12];
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
    u32 blend_control;
    u32 palette_offset;
    u8 palette_format;
    GXGLMaterial material;
    u32 debug_cp[256],debug_xf[256],debug_transform[13];
} QueuedDraw;

static QueuedVertex s_queued_vertices[MAX_QUEUED_VERTICES];
static u32 s_queued_vtx_count = 0;
static QueuedDraw s_queued_draws[MAX_QUEUED_DRAWS];
static u32 s_queued_draw_count = 0;
// Recovery route: resources are consumed synchronously from guest RAM/VRAM.
static u64 s_tlut_sync;

static GXGLRawVertex s_raw_vertices[MAX_QUEUED_VERTICES],s_raw_vertex_cache[4096];
static GXGLTransform s_gpu_transforms[MAX_QUEUED_DRAWS];
static bool s_gpu_draws[MAX_QUEUED_DRAWS],s_gpu_xf_enabled=true;
static u64 s_gpu_raw_hash[MAX_QUEUED_DRAWS];
typedef struct {
    QueuedDraw* draws;QueuedVertex* vertices;GXGLRawVertex* raw;GXGLTransform* transforms;
    bool* gpu;u64* hashes;u32 draw_count,vertex_count;
} GXRenderView;
static bool frame_queue_draws(CPUState* cpu);
static bool frame_queue_copy(CPUState* cpu,u32 control,bool display);
static bool frame_queue_barrier(void);
static bool frame_queue_pe(void);
static bool frame_backend_ensure(void);
static bool frame_queue_clear(const SDL_Rect* region,u32 ar,u32 gb,u32 z);
#ifdef _MSC_VER
static __declspec(thread) const u8* s_backend_palette;
static __declspec(thread) const u32* s_backend_bp;
#else
static _Thread_local const u8* s_backend_palette;
static _Thread_local const u32* s_backend_bp;
#endif
static u64 s_gpu_xf_batches,s_merged_packets;
u64 gx_pipe_merged_packets(void){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);return x.merged;}return s_merged_packets;}
void gx_pipe_set_gpu_xf(bool enabled){s_gpu_xf_enabled=enabled;}
bool gx_pipe_gpu_xf(void){return s_gpu_xf_enabled;}
u64 gx_pipe_gpu_xf_batches(void){return s_gpu_xf_batches;}


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
static u8 s_active_tlut_fmt = 1;
static u8 s_tlut_memory[512 * 1024];
static u32 s_palette_offset;
static u8 s_palette_format;
// Texture cache entry for decoded textures
typedef struct {
    u32 gc_addr;
    u16 width;
    u16 height;
    u8 format;
    u64 hash;
    u32 epoch;u64 palette_key;
    SDL_Texture* sdl_tex;
    u32 next;u64 last_used;bool vram_only;
} TexCacheEntry;

#define MAX_TEX_CACHE 512
static u32 s_tex_cache_victim, s_texture_epoch;
static u64 s_render_ticks,s_copy_ticks;
static u64 s_vertex_decode_ticks,s_texture_copy_ticks;
static u64 s_texture_uploads;
static bool s_gpu_packed_copy_enabled=true;
u64 gx_pipe_get_texture_uploads(void){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);return x.uploads;}return s_texture_uploads;}
void gx_pipe_set_packed_copy(bool enabled){s_gpu_packed_copy_enabled=enabled;}
void gx_pipe_get_costs(u64* vertices,u64* textures){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);*vertices=s_vertex_decode_ticks;*textures=x.texture_copy;return;}*vertices=s_vertex_decode_ticks;*textures=s_texture_copy_ticks;}
static u64 s_display_copies;
static u64 s_vertex_cache_hits,s_vertex_cache_misses;
void gx_pipe_get_vertex_cache_stats(u64* hits,u64* misses){*hits=s_vertex_cache_hits;*misses=s_vertex_cache_misses;}
u64 gx_pipe_get_display_copies(void){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);return x.display_copies;}return s_display_copies;}
void gx_pipe_get_timing(u64* render,u64* copy){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);*render=x.render;*copy=x.copy;return;}*render=s_render_ticks;*copy=s_copy_ticks;}
static TexCacheEntry s_tex_cache[MAX_TEX_CACHE];
static u32 s_tex_cache_count = 0;
static u32 s_tex_buckets[1024];static u64 s_tex_serial,s_tex_hits,s_tex_hash_bytes,s_texture_readbacks;
static u32* s_decode_pixels;static size_t s_decode_capacity;
static bool s_vram_only_enabled=true;static u32 s_vram_pending;
static u32 s_vram_min=~0u,s_vram_max;
static u64 s_vram_only_copies,s_vram_materializations;
static SDL_Texture* s_vram_read_target;
bool gx_pipe_vram_only(void){return s_vram_only_enabled;}
void gx_pipe_vram_diagnostics(u64* copies,u64* materializations,u32* pending){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);*copies=x.vram_copies;*materializations=x.vram_resolves;*pending=x.vram_pending;return;}*copies=s_vram_only_copies;*materializations=s_vram_materializations;*pending=s_vram_pending;}
static void vram_unpin(TexCacheEntry* entry){if(entry->vram_only){entry->vram_only=false;if(!--s_vram_pending){s_vram_min=~0u;s_vram_max=0;}}}
static u32 texture_bucket(u32 address,u16 w,u16 h,u8 format,u64 palette){
    u32 value=address^((u32)w<<16)^h^((u32)format*0x9E3779B9u)^(u32)palette^((u32)(palette>>32)*0x85EBCA6Bu);
    value^=value>>16;value*=0x7FEB352Du;value^=value>>15;return value&1023u;
}
static u32 texture_find(u32 address,u16 w,u16 h,u8 format,u64 palette){
    for(u32 id=s_tex_buckets[texture_bucket(address,w,h,format,palette)];id;id=s_tex_cache[id-1].next){
        TexCacheEntry* e=s_tex_cache+id-1;
        if(e->gc_addr==address && e->width==w && e->height==h && e->format==format && e->palette_key==palette)return id-1;
    }
    return MAX_TEX_CACHE;
}
static u32 texture_reserve(void){
    if(s_tex_cache_count<MAX_TEX_CACHE)return s_tex_cache_count++;
    u32 slot=MAX_TEX_CACHE;for(u32 i=0;i<MAX_TEX_CACHE;i++)if(!s_tex_cache[i].vram_only && (slot==MAX_TEX_CACHE || s_tex_cache[i].last_used<s_tex_cache[slot].last_used))slot=i;
    if(slot==MAX_TEX_CACHE)return slot;
    TexCacheEntry* e=s_tex_cache+slot;
    u32* link=s_tex_buckets+texture_bucket(e->gc_addr,e->width,e->height,e->format,e->palette_key);
    while(*link && *link!=slot+1)link=&s_tex_cache[*link-1].next;
    if(*link)*link=e->next;
    if(e->sdl_tex)SDL_DestroyTexture(e->sdl_tex);memset(e,0,sizeof(*e));return slot;
}
static void texture_publish(u32 slot,TexCacheEntry value){
    u32 bucket=texture_bucket(value.gc_addr,value.width,value.height,value.format,value.palette_key);
    value.next=s_tex_buckets[bucket];value.last_used=++s_tex_serial;s_tex_cache[slot]=value;s_tex_buckets[bucket]=slot+1;
}


static FILE* s_capture;
void gx_pipe_texture_diagnostics(u64* hits,u64* hashed,u64* readbacks){if(gx_frame_active() && !gx_frame_consuming()){GXFrameStats x;gx_frame_stats(&x);*hits=x.texture_hits;*hashed=x.hash_bytes;*readbacks=x.readbacks;return;}*hits=s_tex_hits;*hashed=s_tex_hash_bytes;*readbacks=s_texture_readbacks;}
static bool native_route(void) {static int enabled=-1;if(enabled<0)enabled=getenv("GX_FORCE_SDL")==NULL;return enabled!=0;}
static void capture_batch(void) {
    if (!s_capture || !s_queued_draw_count) return;
    u32 sizes[2]={s_queued_draw_count,s_queued_vtx_count};
    fwrite(sizes,sizeof(sizes),1,s_capture);
    fwrite(s_tlut_memory,1,sizeof(s_tlut_memory),s_capture);
    fwrite(s_queued_draws,sizeof(QueuedDraw),s_queued_draw_count,s_capture);
    fwrite(s_queued_vertices,sizeof(QueuedVertex),s_queued_vtx_count,s_capture);
}
static void capture_next_frame(CPUState* cpu) {
    if(gx_frame_consuming())return;
    if (s_capture) { u32 end[2]={0};fwrite(end,sizeof(end),1,s_capture);fclose(s_capture);s_capture=NULL; }
    static int recording=-1;if(recording<0)recording=getenv("GX_RECORD")!=NULL;
    if (!recording || !s_efb) return;
    if(!gx_pipe_set_xfb_vram(cpu,false))return;
    static u32 previous=~0u,copies;
    u32 scene=mem_read32(cpu,0x80682D50u);
    if (scene!=previous) {previous=scene;copies=0;}
    copies++;
    if ((scene!=11 && scene!=18 && scene!=4 && scene!=3) || (copies!=60 && copies!=180))return;
    char name[128];snprintf(name,sizeof(name),"build_test/gx_scene%u_copy%u.gxc",scene,copies);
    if(s_vram_pending){bool enabled=s_vram_only_enabled;if(!gx_pipe_set_vram_only(cpu,false))return;s_vram_only_enabled=enabled;}
    FILE* file=fopen(name,"wb");if(!file)return;
    u32 header[4]={0x47584331u,sizeof(QueuedVertex),sizeof(QueuedDraw),cpu->ram_size};
    SDL_Surface* image=SDL_CreateRGBSurfaceWithFormat(0,640,528,32,SDL_PIXELFORMAT_RGBA32);
    SDL_Texture* old=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);
    bool ok=image && SDL_RenderReadPixels(s_renderer,NULL,SDL_PIXELFORMAT_RGBA32,image->pixels,image->pitch)==0;
    if(ok) {
        fwrite(header,sizeof(header),1,file);fwrite(cpu->ram,1,cpu->ram_size,file);
        fwrite(image->pixels,1,640*528*4,file);s_capture=file;
        printf("[GX capture] recording next frame to %s\n",name);
    }else fclose(file);
    if(image)SDL_FreeSurface(image);SDL_SetRenderTarget(s_renderer,old);
}

// Decode 4x4 CMPR (DXT1) sub-block
static void decode_cmpr_block(const u8* src, u32* dst_rgba, int block_x, int block_y, int img_w, int img_h) {
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
            if (dx < img_w && dy < img_h) {
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
            decode_cmpr_block(src + src_offset, dst_rgba, x + 0, y + 0, width, height);
            src_offset += 8;
            // Sub-block 1: (x+4, y+0)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 4, y + 0, width, height);
            src_offset += 8;
            // Sub-block 2: (x+0, y+4)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 0, y + 4, width, height);
            src_offset += 8;
            // Sub-block 3: (x+4, y+4)
            decode_cmpr_block(src + src_offset, dst_rgba, x + 4, y + 4, width, height);
            src_offset += 8;
        }
    }
}

static u64 texture_hash(const u8* bytes, u32 count, u64 hash) {
#if defined(DIGIMON_XXHASH)
    return XXH64(bytes,count,hash);
#else
    for (u32 i = 0; i < count; i++) hash = (hash ^ bytes[i]) * 16777619u;
    return hash;
#endif
}
static u32 rgba_color(u16 value, bool rgb565) {
    u32 r, g, b, a = 255;
    if (rgb565) { r = ((value >> 11)&31)*255/31; g = ((value >> 5)&63)*255/63; b = (value&31)*255/31; }
    else if (value & 0x8000u) { r = ((value >> 10)&31)*255/31; g = ((value >> 5)&31)*255/31; b = (value&31)*255/31; }
    else { a = ((value >> 12)&7)*255/7; r = ((value >> 8)&15)*17; g = ((value >> 4)&15)*17; b = (value&15)*17; }
    return r | (g<<8) | (b<<16) | (a<<24);
}
// Only the explicitly enabled I4 64x64 render textures may remain GPU-only.
// Disabling the mode/capturing resolves them, without overwriting CPU edits.
static bool materialize_vram_timed_body(CPUState* cpu,TexCacheEntry* entry) {
    if(!entry->vram_only)return true;
    u32 offset=entry->gc_addr-GC_RAM_BASE;
    if(entry->format!=0 || entry->width!=64 || entry->height!=64 || entry->gc_addr<GC_RAM_BASE || offset>cpu->ram_size || 2048u>cpu->ram_size-offset || !s_renderer)return false;
    if(texture_hash(cpu->ram+offset,2048,2166136261u)!=entry->hash){vram_unpin(entry);entry->epoch=~s_texture_epoch;return true;}
    if(!s_vram_read_target)s_vram_read_target=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,64,64);
    if(!s_readback_pixels)s_readback_pixels=malloc(640u*528u*4u);
    if(!s_vram_read_target || !s_readback_pixels)return false;
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_BlendMode blend;SDL_GetTextureBlendMode(entry->sdl_tex,&blend);
    bool ok=SDL_SetRenderTarget(s_renderer,s_vram_read_target)==0;
    if(ok){SDL_SetTextureBlendMode(entry->sdl_tex,SDL_BLENDMODE_NONE);ok=SDL_RenderCopy(s_renderer,entry->sdl_tex,NULL,NULL)==0;}
    if(ok){s_texture_readbacks++;ok=SDL_RenderReadPixels(s_renderer,NULL,SDL_PIXELFORMAT_RGBA32,s_readback_pixels,64*4)==0;}
    SDL_SetTextureBlendMode(entry->sdl_tex,blend);SDL_SetRenderTarget(s_renderer,previous);if(!ok)return false;
    ppc_mark_host_write(cpu->ram+offset,2048);
    memset(cpu->ram+offset,0,2048);
    for(u32 y=0;y<64;y++)for(u32 x=0;x<64;x++){
        u32 tile=(y/8)*8+x/8,n=(y%8)*8+x%8;
        cpu->ram[offset+tile*32+n/2]|=(u8)((s_readback_pixels[(y*64+x)*4]>>4)<<((n&1) ? 0:4));
    }
    entry->hash=texture_hash(cpu->ram+offset,2048,2166136261u);entry->epoch=~s_texture_epoch;vram_unpin(entry);s_vram_materializations++;return true;
}
static bool materialize_vram(CPUState* cpu,TexCacheEntry* entry) {
    FrameStage previous=frame_timing_enter(FRAME_EFB_COPY);
    bool result=materialize_vram_timed_body(cpu,entry);
    frame_timing_leave(previous);return result;
}

bool gx_pipe_set_vram_only(CPUState* cpu,bool enabled){
    if(!enabled && s_vram_pending)for(u32 i=0;i<s_tex_cache_count;i++)if(!materialize_vram(cpu,s_tex_cache+i))return false;
    s_vram_only_enabled=enabled;return true;
}
static bool resolve_vram_overlap(CPUState* cpu,u32 address,u32 bytes,bool replace_same){
    if(!s_vram_pending)return true;
    for(u32 i=0;i<s_tex_cache_count;i++){
        TexCacheEntry* e=s_tex_cache+i;if(!e->vram_only || (replace_same && e->gc_addr==address))continue;
        if((u64)address+bytes>e->gc_addr && (u64)e->gc_addr+2048>address && !materialize_vram(cpu,e))return false;
    }
    return true;
}
// GX tile dimensions differ per format; RGBA8 uses separate AR and GB planes.
static SDL_Texture* get_or_create_texture(SDL_Renderer* renderer, CPUState* cpu, u32 address, u16 w, u16 h, u8 fmt) {
    static const u8 tile_w[15] = {8,8,8,4,4,4,4,0,8,8,4,0,0,0,8};
    static const u8 tile_h[15] = {8,4,4,4,4,4,4,0,8,4,4,0,0,0,8};
    if (!renderer || address < GC_RAM_BASE || !w || !h || w > 1024 || h > 1024 || fmt >= 15 || !tile_w[fmt]) return NULL;
    u32 tw = tile_w[fmt], th = tile_h[fmt], block_bytes = fmt == 6 ? 64 : 32;
    u32 blocks_x = (w + tw - 1) / tw;
    u32 bytes = blocks_x * ((h + th - 1) / th) * block_bytes;
    u32 off = address - GC_RAM_BASE;
    if (off > cpu->ram_size || bytes > cpu->ram_size - off) return NULL;
    const u8* raw = cpu->ram+off;
    u32 palette_count = fmt == 8 ? 16 : fmt == 9 ? 256 : fmt == 10 ? 16384 : 0;
    const u8* palette = NULL;
    if (palette_count && s_palette_offset <= sizeof(s_tlut_memory) &&
        palette_count * 2 <= sizeof(s_tlut_memory) - s_palette_offset)
        palette = (s_backend_palette ? s_backend_palette:s_tlut_memory) + s_palette_offset;
    u64 palette_key=palette_count ? s_palette_offset|((u32)s_palette_format<<28):0;
    u32 slot=texture_find(address,w,h,fmt,palette_key);TexCacheEntry* entry=slot<MAX_TEX_CACHE ? s_tex_cache+slot:NULL;
    if(s_vram_pending && !(entry && entry->vram_only) && (u64)address+bytes>s_vram_min && address<s_vram_max){
        u32 pending=s_vram_pending;if(!resolve_vram_overlap(cpu,address,bytes,false))return NULL;
        if(entry && pending!=s_vram_pending)entry->epoch=~s_texture_epoch;
    }
    if(entry && entry->epoch==s_texture_epoch){entry->last_used=++s_tex_serial;s_tex_hits++;return entry->sdl_tex;}
    u64 hash=texture_hash(raw,bytes,2166136261u);s_tex_hash_bytes+=bytes;
    if(palette){hash=texture_hash(palette,palette_count*2,hash^s_palette_format);s_tex_hash_bytes+=palette_count*2;}
    if(entry && entry->hash==hash){entry->epoch=s_texture_epoch;entry->last_used=++s_tex_serial;s_tex_hits++;return entry->sdl_tex;}
    if(entry)vram_unpin(entry);
    size_t needed=(size_t)w*h;
    if(needed>s_decode_capacity){u32* storage=realloc(s_decode_pixels,needed*sizeof(u32));if(!storage)return NULL;s_decode_pixels=storage;s_decode_capacity=needed;}
    u32* pixels=s_decode_pixels;
    SDL_Texture* tex=entry ? entry->sdl_tex:NULL;
    if(!tex){tex=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,w,h);if(!tex)return NULL;SDL_SetTextureBlendMode(tex,SDL_BLENDMODE_BLEND);}
    if (fmt == 14) decode_cmpr_texture(raw, pixels, w, h);
    else for (u32 y = 0; y < h; y++) for (u32 x = 0; x < w; x++) {
        u32 tile = (y / th) * blocks_x + x / tw, n = (y % th) * tw + x % tw;
        const u8* data = raw + tile * block_bytes;
        u32 value = 0, color = 0xFFFFFFFFu, index = 0;
        if (fmt == 0 || fmt == 8) value = (data[n/2] >> ((n&1) ? 0 : 4)) & 15;
        else if (fmt == 1 || fmt == 2 || fmt == 9) value = data[n];
        else if (fmt != 6) value = ((u32)data[n*2] << 8) | data[n*2+1];
        if (fmt == 0) { value *= 17; color = value*0x01010101u; }
        else if (fmt == 1) color = value*0x01010101u;
        else if (fmt == 2) { u32 intensity = (value&15)*17; color = intensity*0x010101u | ((value>>4)*17<<24); }
        else if (fmt == 3) color = (value&255)*0x010101u | ((value>>8)<<24);
        else if (fmt == 4 || fmt == 5) color = rgba_color((u16)value, fmt == 4);
        else if (fmt == 6) color = data[n*2+1] | ((u32)data[32+n*2]<<8) | ((u32)data[33+n*2]<<16) | ((u32)data[n*2]<<24);
        else {
            index = fmt == 10 ? value & 16383 : value;
            if (palette && index < palette_count) {
                value = ((u32)palette[index*2]<<8) | palette[index*2+1];
                color = s_palette_format == 0 ? (value&255)*0x010101u | ((value>>8)<<24) : rgba_color((u16)value, s_palette_format == 1);
            } else color = 0; // missing palette is not a grayscale texture
        }
        pixels[y*w+x] = color;
    }
    FrameStage upload_stage=frame_timing_enter(FRAME_GL_SUBMIT);
    bool uploaded=SDL_UpdateTexture(tex,NULL,pixels,w*4)==0;
    frame_timing_leave(upload_stage);
    if(!uploaded){if(!entry)SDL_DestroyTexture(tex);return NULL;}s_texture_uploads++;
    if(entry){entry->hash=hash;entry->epoch=s_texture_epoch;entry->last_used=++s_tex_serial;}
    else{slot=texture_reserve();if(slot==MAX_TEX_CACHE){SDL_DestroyTexture(tex);return NULL;}texture_publish(slot,(TexCacheEntry){address,w,h,fmt,hash,s_texture_epoch,palette_key,tex});}
    return tex;
}

bool gx_pipe_image_versions(void){return false;}
void gx_pipe_set_image_versions(CPUState* cpu,bool enabled){(void)cpu;(void)enabled;}
void gx_pipe_image_diagnostics(u64* out){memset(out,0,7*sizeof(*out));out[5]=s_tlut_sync;}

static void gx_pipe_process_display_list(CPUState* cpu, const u8* dl_buf, u32 dl_len) {
    if (!dl_buf || dl_len == 0) return;
    if (s_dl_depth >= 8) return;
    u32 copy_len = (dl_len < FIFO_BUFFER_SIZE) ? dl_len : FIFO_BUFFER_SIZE;
    if(!s_display_list_buffers[s_dl_depth])s_display_list_buffers[s_dl_depth]=(u8*)malloc(FIFO_BUFFER_SIZE);
    u8* dl_copy=s_display_list_buffers[s_dl_depth];if(!dl_copy)return;
    s_dl_depth++;
    memcpy(dl_copy, dl_buf, copy_len);


    u8* old_buf = s_fifo_buf;
    u32 old_tail = s_fifo_read_tail;
    u32 old_needed=s_fifo_needed;s_fifo_needed=1;
    u32 old_head = s_fifo_write_head;

    s_fifo_buf = dl_copy;
    s_fifo_read_tail = 0;
    s_fifo_write_head = copy_len;

    gx_pipe_process_internal(cpu);

    s_fifo_buf = old_buf;
    s_fifo_read_tail = old_tail;s_fifo_needed=old_needed;
    s_fifo_write_head = old_head;

    s_dl_depth--;
}

/* SDL geometry can modulate one texture. Evaluate the complete register/konst
 * chain at white texture input; per-pixel multi-texture operations still need a
 * shader backend. Keeping all stages is essential for UI material constants. */
static u32 tev_texture_stage(void) {
    u32 count=((s_bp[0]>>10)&15u)+1;
    for (u32 stage=0;stage<count;stage++) {
        u32 order=s_bp[0x28+stage/2] >> ((stage&1)*12);
        u32 color=s_bp[0xC0+stage*2],alpha=s_bp[0xC1+stage*2];
        for (u32 j=0;j<4;j++) {
            u32 input=(color>>(j*4))&15;
            if ((order&64u) && (input==8 || input==9 || ((alpha>>(4+j*3))&7)==4)) return stage;
        }
    }
    return 0;
}
static bool tev_uses_texture(void) {
    u32 stage=tev_texture_stage(), order=s_bp[0x28+stage/2] >> ((stage&1)*12);
    if (!(order&64u)) return false;
    u32 color=s_bp[0xC0+stage*2],alpha=s_bp[0xC1+stage*2];
    for (u32 j=0;j<4;j++) {
        u32 input=(color>>(j*4))&15;
        if (input==8 || input==9 || ((alpha>>(4+j*3))&7)==4) return true;
    }
    return false;
}
static int tev_register_component(const u32* words,u32 reg,u32 channel) {
    u32 ra=words[reg*2],bg=words[reg*2+1];
    u32 value=channel==0 ? ra&2047u : channel==1 ? (bg>>12)&2047u : channel==2 ? bg&2047u : (ra>>12)&2047u;
    return (value&1024u) ? (int)value-2048 : (int)value;
}
static int tev_konst(u32 selection,u32 channel) {
    if (selection<8) return selection ? 256-(int)selection*32 : 255;
    if (selection<12) return 0;
    u32 component=selection<16 ? channel : (selection-16)/4;
    return tev_register_component(s_konst_registers,selection&3u,component)&255;
}
static int tev_input(u32 input,u32 channel,int regs[4][4],const int raster[4],int konst,bool alpha) {
    if (alpha) {
        if (input<4) return regs[input][3];
        return input==4 ? 255 : input==5 ? raster[3] : input==6 ? konst : 0;
    }
    if (input<8) return regs[input/2][(input&1) ? 3 : channel];
    if (input==8 || input==9 || input==12) return 255;
    if (input==10) return raster[channel];
    if (input==11) return raster[3];
    if (input==13) return 128;
    return input==14 ? konst : 0;
}
static int tev_mix(int a,int b,int c,int d,u32 env) {
    a&=255; b&=255; c&=255;
    u32 bias=(env>>16)&3,scale=(env>>20)&3;
    int value;
    if (bias==3) value=d+(((env&0x40000u) ? a==b : a>b) ? c : 0);
    else {
        value=(a*(255-c)+b*c+127)/255;
        value=d+((env&0x40000u) ? -value : value);
        if (bias==1) value+=128; else if (bias==2) value-=128;
        if (scale<3) value*=1<<scale; else value/=2;
    }
    int lo=(env&0x80000u) ? 0 : -1024,hi=(env&0x80000u) ? 255 : 1023;
    return value<lo ? lo : value>hi ? hi : value;
}
static void tev_vertex(QueuedVertex* vertex) {
    if (!s_bp[0xC0] && !s_bp[0xC1]) return;
    int regs[4][4],raster[4]={vertex->r,vertex->g,vertex->b,vertex->a};
    for (u32 r=0;r<4;r++) for (u32 c=0;c<4;c++) regs[r][c]=tev_register_component(s_tev_registers,r,c);
    u32 count=((s_bp[0]>>10)&15u)+1,last_color=0,last_alpha=0;
    for (u32 stage=0;stage<count;stage++) {
        u32 color=s_bp[0xC0+stage*2],alpha=s_bp[0xC1+stage*2];
        u32 ksel=s_bp[0xF6+stage/2],shift=(stage&1)*10;
        u32 kc=(ksel>>(4+shift))&31u,ka=(ksel>>(9+shift))&31u;
        int output[4];
        for (u32 channel=0;channel<4;channel++) {
            bool a=channel==3; u32 env=a ? alpha : color;
            int k=tev_konst(a ? ka : kc,channel);
            u32 ia=a ? (env>>13)&7u : (env>>12)&15u;
            u32 ib=a ? (env>>10)&7u : (env>>8)&15u;
            u32 ic=a ? (env>>7)&7u : (env>>4)&15u;
            u32 id=a ? (env>>4)&7u : env&15u;
            output[channel]=tev_mix(tev_input(ia,channel,regs,raster,k,a),tev_input(ib,channel,regs,raster,k,a),
                                     tev_input(ic,channel,regs,raster,k,a),tev_input(id,channel,regs,raster,k,a),env);
        }
        last_color=(color>>22)&3u; last_alpha=(alpha>>22)&3u;
        for (u32 channel=0;channel<3;channel++) regs[last_color][channel]=output[channel];
        regs[last_alpha][3]=output[3];
    }
    u8* components[4]={&vertex->r,&vertex->g,&vertex->b,&vertex->a};
    for (u32 c=0;c<4;c++) { int v=regs[c==3 ? last_alpha : last_color][c]; *components[c]=(u8)(v<0 ? 0 : v>255 ? 255 : v); }
}

typedef struct {
    u32 stride,matrix_bytes;
    u8 mode[12],format[12],components[12],fraction[12],normal_indices;
} VertexLayout;
typedef struct {const u32* cp;const u8* fifo;u32 size;} VertexInput;
#if defined(_M_X64) || defined(__x86_64__)
typedef struct {__m128 point[4],normal[3];} MatrixColumns;
static MatrixColumns s_matrix_columns[64];
#endif
typedef struct {
    const VertexInput* input;const GXGLTransform* xf;u64 valid;bool normal_required;
#if defined(_M_X64) || defined(__x86_64__)
    MatrixColumns columns[64];
#endif
} DecodeEnvironment;
#ifdef _MSC_VER
static __declspec(thread) DecodeEnvironment* s_decode_environment;
#else
static _Thread_local DecodeEnvironment* s_decode_environment;
#endif

static bool frame_queue_raw(CPUState* cpu,const QueuedDraw* draw,const GXGLTransform* xf,const VertexLayout* layout,u32 cursor,bool gpu,u32 chosen);
static bool frame_validate_capture(CPUState* cpu,SDL_Window* window,const VertexLayout* layout,u32 cursor,u32 count,const GXGLTransform* xf,const GXGLRawVertex* expected,const GXGLVertex* native_expected);
static u32 scalar_size(u32 format) { return format < 2 ? 1 : format < 4 ? 2 : 4; }
static u32 color_size(u32 format) { static const u8 sizes[8] = {2,3,4,2,3,4,4,4}; return sizes[format & 7]; }
static bool s_direct_attributes=true;
void gx_pipe_set_direct_attributes(bool enabled){s_direct_attributes=enabled;}
bool gx_pipe_direct_attributes(void){return s_direct_attributes;}
static VertexLayout vertex_layout(u32 vat) {
    VertexLayout l = {0};
    u32 lo = s_cp[0x50], hi = s_cp[0x60], a = s_cp[0x70 + vat];
    u32 b = s_cp[0x80 + vat], c = s_cp[0x90 + vat];
    for (u32 j = 0; j < 9; j++) l.matrix_bytes += (lo >> j) & 1;
    l.stride = l.matrix_bytes;
    l.mode[0] = (lo >> 9) & 3; l.mode[1] = (lo >> 11) & 3;
    l.mode[2] = (lo >> 13) & 3; l.mode[3] = (lo >> 15) & 3;
    l.format[0] = (a >> 1) & 7; l.components[0] = 2 + (a & 1);
    l.fraction[0] = (a >> 4) & 31;
    l.format[1] = (a >> 10) & 7; l.components[1] = (a & 0x200u) ? 9 : 3;
    l.normal_indices = ((a >> 31) && (a & 0x200u)) ? 3 : 1;
    l.format[2] = (a >> 14) & 7; l.format[3] = (a >> 18) & 7;
    l.format[4] = (a >> 22) & 7; l.components[4] = 1 + ((a >> 21) & 1);
    l.fraction[4] = (a >> 25) & 31;
    for (u32 j = 1; j < 8; j++) {
        u32 bits;
        if (j < 4) bits = b >> ((j - 1) * 9);
        else if (j == 4) bits = ((b >> 27) & 15u) | ((c & 31u) << 4);
        else bits = c >> (5 + (j - 5) * 9);
        l.components[4 + j] = 1 + (bits & 1);
        l.format[4 + j] = (bits >> 1) & 7;
        l.fraction[4 + j] = (bits >> 4) & 31;
    }
    for (u32 j = 0; j < 8; j++) l.mode[4+j] = (hi >> (j*2)) & 3;
    for (u32 j = 0; j < 12; j++) {
        if (l.mode[j] == 1) l.stride += (j == 2 || j == 3) ? color_size(l.format[j]) : l.components[j] * scalar_size(l.format[j]);
        else if (l.mode[j] >= 2) l.stride += (l.mode[j] - 1) * (j == 1 ? l.normal_indices : 1);
    }
    return l;
}
static u8 vertex_byte(const VertexInput* input,u32* cursor) {
    u8 value = input->fifo[*cursor % input->size]; (*cursor)++; return value;
}
static float vertex_scalar(const u8* p, u32 fmt, u32 fraction) {
    if (fmt >= 4) return read_be_float(p);
    int value = fmt == 0 ? p[0] : fmt == 1 ? (s8)p[0] : fmt == 2 ? ((int)p[0] << 8) | p[1] : read_be_s16(p);
    // Integer attributes have at most 16 bits; scaling by this normal power
    // of two is exact and avoids a CRT ldexpf call for every component.
    u32 bits=(127u-fraction)<<23;float scale;memcpy(&scale,&bits,4);
    return (float)value*scale;
}
/* These aliases are scoped to decoder functions. Frontend CP/XF registers
 * outside this region are never switched or touched by the GL consumer. */
#define s_cp (s_decode_environment ? s_decode_environment->input->cp:s_cp)
#define s_fifo_buf (s_decode_environment ? s_decode_environment->input->fifo:s_fifo_buf)
#define s_xf (s_decode_environment ? s_decode_environment->xf->words:s_xf)
#define s_projection_loaded (s_decode_environment ? s_decode_environment->xf->projection:s_projection_loaded)
#define s_lighting_loaded (s_decode_environment ? s_decode_environment->xf->lighting:s_lighting_loaded)
#define s_matrix_valid (*(s_decode_environment ? &s_decode_environment->valid:&s_matrix_valid))
#define s_normal_lighting_required (*(s_decode_environment ? &s_decode_environment->normal_required:&s_normal_lighting_required))
#if defined(_M_X64) || defined(__x86_64__)
#define s_matrix_columns (s_decode_environment ? s_decode_environment->columns:s_matrix_columns)
#endif
static float xf_float(u32 addr) { float value; memcpy(&value, &s_xf[addr], 4); return value; }
static bool lighting_needs_normal(void) {
    if(!s_lighting_loaded)return false;
    for(u32 i=0;i<2;i++) {
        u32 c=s_xf[i ? 0x1010:0x100E];
        u32 mask=((c>>2)&15u)|((c>>7)&240u);
        if((c&2u) && mask && ((c>>7)&3u))return true;
    }
    return false;
}

static void prepare_matrix_index(u32 matrix) {
#if defined(_M_X64) || defined(__x86_64__)
    if(s_matrix_valid&(1ull<<matrix))return;
    u32 point=matrix*4,normal=0x400+(matrix&31u)*3;
    for(u32 col=0;col<4;col++)s_matrix_columns[matrix].point[col]=_mm_setr_ps(xf_float(point+col),xf_float(point+4+col),xf_float(point+8+col),0);
    for(u32 col=0;col<3;col++)s_matrix_columns[matrix].normal[col]=_mm_setr_ps(xf_float(normal+col),xf_float(normal+3+col),xf_float(normal+6+col),0);
    s_matrix_valid|=1ull<<matrix;
#else
    (void)matrix;
#endif
}
static void transform_scalar(u32 matrix,const float input[3],float output[3],bool normal) {
    u32 base=normal ? 0x400+(matrix&31u)*3:matrix*4;
    u32 stride=normal ? 3:4;
    for(u32 row=0;row<3;row++) {
        u32 at=base+row*stride;
        output[row]=xf_float(at)*input[0]+xf_float(at+1)*input[1]+xf_float(at+2)*input[2];
        if(!normal)output[row]+=xf_float(at+3);
    }
}
static void transform_prepared(u32 matrix,const float input[3],float output[3],bool normal) {
#if defined(_M_X64) || defined(__x86_64__)
    if(!s_scalar_transforms) {
        const __m128* cols=normal ? s_matrix_columns[matrix].normal:s_matrix_columns[matrix].point;
        __m128 result=_mm_mul_ps(cols[0],_mm_set1_ps(input[0]));
        result=_mm_add_ps(result,_mm_mul_ps(cols[1],_mm_set1_ps(input[1])));
        result=_mm_add_ps(result,_mm_mul_ps(cols[2],_mm_set1_ps(input[2])));
        if(!normal)result=_mm_add_ps(result,cols[3]);
        float lanes[4];_mm_storeu_ps(lanes,result);memcpy(output,lanes,3*sizeof(float));return;
    }
#endif
    transform_scalar(matrix,input,output,normal);
}
static void prepare_vertex_constants(const VertexLayout* layout,u32 cursor,u32 count) {
    s_normal_lighting_required=lighting_needs_normal();
    if(!s_projection_loaded && !s_normal_lighting_required && !s_scalar_transforms)return;
    u64 needed=1ull<<(s_cp[0x30]&63u);
    if(s_cp[0x50]&1u) {
        needed=0;
        for(u32 i=0;i<count;i++)needed|=1ull<<(s_fifo_buf[(cursor+i*layout->stride)%FIFO_BUFFER_SIZE]&63u);
    }
    u64 missing=needed&~s_matrix_valid;
    if(!missing)return;
    for(u32 i=0;i<64;i++)if(missing&(1ull<<i))prepare_matrix_index(i);
}
static void shade_vertex(QueuedVertex* vertex,const float position[3],const float normal[3],u32 matrix) {
    if(!s_lighting_loaded)return;
    u8 raw[4]={vertex->r,vertex->g,vertex->b,vertex->a};u8* output[4]={&vertex->r,&vertex->g,&vertex->b,&vertex->a};
    float n[3]={0};
    if(s_normal_lighting_required || s_scalar_transforms) {
        transform_prepared(matrix,normal,n,true);
        float nl=sqrtf(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);if(nl>0)for(u32 j=0;j<3;j++)n[j]/=nl;
    }
    float factors[8]={0};u32 cached_control=~0u;
    for(u32 channel=0;channel<4;channel++) {
        u32 control=s_xf[channel==3 ? 0x1010 : 0x100E];
        u32 shift=(3-channel)*8;
        float material=(float)((control&1u) ? raw[channel] : (s_xf[0x100C]>>shift)&255u);
        if(!(control&2u)){*output[channel]=(u8)material;continue;}
        float light=(float)((control&64u) ? raw[channel] : (s_xf[0x100A]>>shift)&255u);
        u32 mask=((control>>2)&15u)|((control>>7)&240u),diffuse=(control>>7)&3,attenuation=(control>>9)&3;
        u32 factor_control=control&~65u;
        if(cached_control!=factor_control) {
          for(u32 i=0;i<8;i++)if(mask&(1u<<i)) {
            u32 at=0x600+i*16;
            float factor=1.0f;
            if(diffuse || attenuation==3) {
              float direction[3],distance2=0;
              for(u32 j=0;j<3;j++){direction[j]=xf_float(at+10+j)-position[j];distance2+=direction[j]*direction[j];}
              float distance=sqrtf(distance2);if(distance>0)for(u32 j=0;j<3;j++)direction[j]/=distance;
              if(diffuse){factor=n[0]*direction[0]+n[1]*direction[1]+n[2]*direction[2];if(diffuse!=1 && factor<0)factor=0;}
              if(attenuation==3) {
                float cosine=-(direction[0]*xf_float(at+13)+direction[1]*xf_float(at+14)+direction[2]*xf_float(at+15));
                float numerator=xf_float(at+4)+xf_float(at+5)*cosine+xf_float(at+6)*cosine*cosine;
                float denominator=xf_float(at+7)+xf_float(at+8)*distance+xf_float(at+9)*distance2;
                factor*=numerator<=0 ? 0 : denominator>0 ? numerator/denominator : 1;
              }
            }
            factors[i]=factor;
          }
          cached_control=factor_control;
        }
        for(u32 i=0;i<8;i++)if(mask&(1u<<i))light+=factors[i]*(float)((s_xf[0x600+i*16+3]>>shift)&255u);
        if(light<0)light=0;if(light>255)light=255;
        float result=floorf(material*light/255.0f+0.5f);*output[channel]=(u8)(result<0 ? 0 : result>255 ? 255 : result);
    }
}
static void decode_vertex_input(CPUState* cpu, const VertexLayout* l, u32 cursor, QueuedVertex* out,u32 chosen,bool software_tev,GXGLRawVertex* raw,const VertexInput* input) {
    // Raw GPU vertices do not consume the CPU projection/debug output.
    QueuedVertex raw_scratch;
    if(raw)out=&raw_scratch;else memset(out,0,sizeof(*out));
    out->r = out->g = out->b = out->a = 255;
    u32 matrix = input->cp[0x30] & 63u;
    u32 tex_matrix[8];
    for (u32 j=0;j<8;j++) tex_matrix[j] = j<4 ? (input->cp[0x30] >> (6+j*6)) & 63u : (input->cp[0x40] >> ((j-4)*6)) & 63u;
    for (u32 j = 0; j < 9; j++) if ((input->cp[0x50] >> j) & 1) {
        u32 index = vertex_byte(input,&cursor); if (j == 0) matrix = index & 63u; else tex_matrix[j-1] = index & 63u;
    }
    float position[3] = {0}, normal[3] = {0}, texcoord[8][3] = {{0}};
    for (u32 j = 0; j < 12; j++) {
        u32 mode = l->mode[j]; if (!mode) continue;
        u8 scratch[36];const u8* data=scratch;
        if(!s_direct_attributes)memset(scratch,0,sizeof(scratch));
        u32 size = (j == 2 || j == 3) ? color_size(l->format[j]) : l->components[j] * scalar_size(l->format[j]);
        if (mode == 1) {
            u32 at=cursor%input->size;
            if(s_direct_attributes && size && size<=input->size-at){data=input->fifo+at;cursor+=size;}
            else {if(s_direct_attributes)memset(scratch,0,sizeof(scratch));for(u32 k=0;k<size;k++)scratch[k]=vertex_byte(input,&cursor);}
        }
        else {
            if(s_direct_attributes)memset(scratch,0,sizeof(scratch));
            u32 indices = j == 1 ? l->normal_indices : 1;
            for (u32 n = 0; n < indices; n++) {
                u32 index = vertex_byte(input,&cursor);
                if (mode == 3) index = (index << 8) | vertex_byte(input,&cursor);
                u64 addr = (input->cp[0xA0+j] & 0x1FFFFFFu) + (u64)index * (input->cp[0xB0+j] & 255u);
                if (n == 0 && addr <= cpu->ram_size && size <= cpu->ram_size - addr) {
                    if(s_direct_attributes && size)data=cpu->ram+(u32)addr;
                    else memcpy(scratch,cpu->ram+(u32)addr,size);
                }
            }
        }
        if (j == 0) {
            if(!raw)memcpy(out->position_bytes,data,size<12 ? size : 12);
            for (u32 k = 0; k < l->components[0]; k++)position[k] = vertex_scalar(data + k * scalar_size(l->format[0]), l->format[0], l->fraction[0]);
        }
        else if (j == 1) for (u32 k=0;k<3;k++)
            normal[k] = vertex_scalar(data+k*scalar_size(l->format[j]),l->format[j], l->format[j]==1 ? 6 : l->format[j]==3 ? 14 : 0);
        else if (j == 2) {
            u32 f = l->format[j], word = ((u32)data[0] << 8) | data[1];
            if (f == 0) { out->r = (u8)(((word >> 11) & 31)*255/31); out->g = (u8)(((word >> 5)&63)*255/63); out->b = (u8)((word&31)*255/31); }
            else if (f == 3) { out->r = (u8)((word>>12)*17); out->g = (u8)(((word>>8)&15)*17); out->b = (u8)(((word>>4)&15)*17); out->a = (u8)((word&15)*17); }
            else if (f == 4) {
                word = (word << 8) | data[2]; out->r = (u8)(((word>>18)&63)*255/63); out->g = (u8)(((word>>12)&63)*255/63);
                out->b = (u8)(((word>>6)&63)*255/63); out->a = (u8)((word&63)*255/63);
            } else { out->r=data[0]; out->g=data[1]; out->b=data[2]; if (f == 5) out->a=data[3]; }
        } else if (j >= 4) {
            texcoord[j-4][0] = vertex_scalar(data,l->format[j],l->fraction[j]);
            if (l->components[j]>1) texcoord[j-4][1] = vertex_scalar(data+scalar_size(l->format[j]),l->format[j],l->fraction[j]);
            texcoord[j-4][2] = 1;
        }
    }
    if(!raw){memcpy(out->object_position,position,sizeof(position));out->object_matrix=matrix;}
    if(raw) {
        memcpy(raw->position,position,sizeof(position));memcpy(raw->normal,normal,sizeof(normal));memcpy(raw->texcoord,texcoord,sizeof(texcoord));
        raw->color[0]=out->r;raw->color[1]=out->g;raw->color[2]=out->b;raw->color[3]=out->a;raw->matrix=matrix;
        for(u32 i=0;i<8;i++)raw->tex_matrix[i]=(u8)tex_matrix[i];return;
    }
    for (u32 coord=0;coord<8;coord++) {
    float stq[3] = {texcoord[coord][0],texcoord[coord][1],1};
    if (s_xf[0x103F] > coord) {
        u32 info=s_xf[0x1040+coord], row=(info>>7)&31u;
        const float* source = row==0 ? position : row==1 ? normal : row>=5 && row<=12 ? texcoord[row-5] : texcoord[coord];
        float input[4]={source[0],source[1],(info&4u) ? source[2] : 1.0f,1};
        u32 index=tex_matrix[coord]*4;
        if (tex_matrix[coord] != 60 && ((info>>4)&7u)==0) {
            for (u32 r=0;r<3;r++) stq[r]=xf_float(index+r*4)*input[0]+xf_float(index+r*4+1)*input[1]+xf_float(index+r*4+2)*input[2]+xf_float(index+r*4+3);
            if (!(info&2u)) stq[2]=1;
        } else { stq[0]=source[0]; stq[1]=source[1]; }
        if (s_xf[0x1012]&1u) {
            u32 post=s_xf[0x1050+coord],base=0x500+(post&63u)*4;
            float value[3]={stq[0],stq[1],stq[2]};
            if (post&256u) { float length=sqrtf(value[0]*value[0]+value[1]*value[1]+value[2]*value[2]); if (length>0) for (u32 r=0;r<3;r++) value[r]/=length; }
            for(u32 r=0;r<3;r++)stq[r]=xf_float(base+r*4)*value[0]+xf_float(base+r*4+1)*value[1]+xf_float(base+r*4+2)*value[2]+xf_float(base+r*4+3);
        }
    }
    memcpy(out->native.texcoord[coord],stq,sizeof(stq));
    if (coord==chosen) {
        out->u = stq[2] != 0 ? stq[0]/stq[2] : stq[0];
        out->v = stq[2] != 0 ? stq[1]/stq[2] : stq[1];
    }
    }
    out->x = position[0]; out->y = position[1];
    out->native.x=position[0]; out->native.y=position[1];
    out->native.w=1.0f; out->native.z=0.5f; out->native.clip_z=-0.5f;
    float view_position[3]={position[0],position[1],position[2]};
    if (s_projection_loaded) {
        float transformed[3];
        transform_prepared(matrix,position,transformed,false);
        memcpy(view_position,transformed,sizeof(transformed));
        bool perspective = s_xf[0x1026] == 0;
        float w = perspective ? -transformed[2] : 1.0f;
        float proj_sx = xf_float(0x1020);
        float proj_ox = xf_float(0x1021);
        if (s_aspect_ratio == 1 && !perspective) {
            proj_sx *= 0.75f;
            proj_ox *= 0.75f;
        }
        float x = proj_sx*transformed[0] + proj_ox*(perspective ? transformed[2] : 1.0f);
        float y = xf_float(0x1022)*transformed[1] + xf_float(0x1023)*(perspective ? transformed[2] : 1.0f);
        if (fabsf(w) > 0.000001f) {
            out->native.w=w;
            // Preserve homogeneous XY. Dividing then multiplying near w=0 loses precision.
            out->native.x=x*xf_float(0x101A)+(xf_float(0x101D)-342.0f)*w;
            out->native.y=y*xf_float(0x101B)+(xf_float(0x101E)-342.0f)*w;
            float projected_z=xf_float(0x1024)*transformed[2]+xf_float(0x1025);
            out->native.clip_z=projected_z;
            out->native.z=(projected_z/w*xf_float(0x101C)+xf_float(0x101F))/16777215.0f;
            out->x = x/w*xf_float(0x101A) + xf_float(0x101D) - 342.0f;
            out->y = y/w*xf_float(0x101B) + xf_float(0x101E) - 342.0f;
        }
    }
    shade_vertex(out,view_position,normal,matrix);
    out->native.color[0]=out->r; out->native.color[1]=out->g; out->native.color[2]=out->b; out->native.color[3]=out->a;
    // GL consumes native.color (the lit raster color) and evaluates TEV per
    // pixel. Only the software route/captures need the white-texture fallback.
    if(software_tev)tev_vertex(out);
    if (!isfinite(out->x) || !isfinite(out->y)) out->x = out->y = 0;
}

static void decode_vertex(CPUState* cpu,const VertexLayout* l,u32 cursor,QueuedVertex* out,u32 chosen,bool software_tev,GXGLRawVertex* raw){
    VertexInput input={s_cp,s_fifo_buf,FIFO_BUFFER_SIZE};decode_vertex_input(cpu,l,cursor,out,chosen,software_tev,raw,&input);
}

#undef s_cp
#undef s_fifo_buf
#undef s_xf
#undef s_projection_loaded
#undef s_lighting_loaded
#undef s_matrix_valid
#undef s_normal_lighting_required
#if defined(_M_X64) || defined(__x86_64__)
#undef s_matrix_columns
#endif

typedef struct {u32 epoch;u8 key[64];QueuedVertex vertex;} VertexCacheEntry;
static VertexCacheEntry s_vertex_cache[4096];
static u32 s_vertex_cache_epoch;
static void decode_cached_vertex(CPUState* cpu,const VertexLayout* layout,u32 cursor,QueuedVertex* out,u32 chosen,bool software_tev,VertexCacheEntry* cache,u64* hits,u64* misses,GXGLRawVertex* raw,GXGLRawVertex* raw_cache,const VertexInput* input) {
    // Only reuse within one draw: XF/CP state and guest arrays cannot change
    // while this synchronous parser decodes it. Compare the complete FIFO key.
    if(layout->mode[0]<2 || layout->stride>64) {
        decode_vertex_input(cpu,layout,cursor,out,chosen,software_tev,raw,input);return;
    }
    u8 key[64];u32 hash=2166136261u;
    for(u32 i=0;i<layout->stride;i++){key[i]=input->fifo[(cursor+i)%input->size];hash=(hash^key[i])*16777619u;}
    VertexCacheEntry* entry=&cache[hash&4095u];
    if(entry->epoch==s_vertex_cache_epoch && !memcmp(entry->key,key,layout->stride)) {
        if(raw)*raw=raw_cache[hash&4095u];else *out=entry->vertex;(*hits)++;return;
    }
    decode_vertex_input(cpu,layout,cursor,out,chosen,software_tev,raw,input);
    entry->epoch=s_vertex_cache_epoch;memcpy(entry->key,key,layout->stride);if(raw)raw_cache[hash&4095u]=*raw;else entry->vertex=*out;(*misses)++;
}

typedef struct {
    CPUState* cpu;VertexLayout layout;VertexInput input;DecodeEnvironment* environment;QueuedVertex* output;VertexCacheEntry* cache;
    u32 cursor,count,chosen,mxcsr;bool software_tev,stop;int rounding;
    u64 hits,misses;SDL_Thread* thread;SDL_sem* ready;
    GXGLRawVertex* raw;GXGLRawVertex* raw_cache;
} VertexDecodeJob;
static VertexDecodeJob s_vertex_workers[3];
static SDL_sem* s_vertices_done;
static VertexCompletion s_vertex_completion;
static bool s_coalesced_enabled=false,s_coalesced_batch;
void gx_pipe_set_coalesced_completion(bool enabled){s_coalesced_enabled=enabled;}
bool gx_pipe_coalesced_completion(void){return s_coalesced_enabled;}
static u32 s_vertex_worker_count;
static bool s_vertex_pool_initialized,s_validate_workers;
static bool s_parallel_vertices_enabled=true;
void gx_pipe_set_parallel_vertices(bool enabled){s_parallel_vertices_enabled=enabled;}
static u64 s_parallel_batches;
u64 gx_pipe_get_parallel_batches(void){return s_parallel_batches;}
static void run_vertex_job(VertexDecodeJob* job) {
    DecodeEnvironment* previous=s_decode_environment;s_decode_environment=job->environment;
    for(u32 i=0;i<job->count;i++)decode_cached_vertex(job->cpu,&job->layout,
        (job->cursor+i*job->layout.stride)%job->input.size,job->output+i,job->chosen,job->software_tev,
        job->cache,&job->hits,&job->misses,job->raw ? job->raw+i:NULL,job->raw_cache,&job->input);
    s_decode_environment=previous;
}
static int vertex_worker(void* user) {
    VertexDecodeJob* job=(VertexDecodeJob*)user;
    for(;;) {
        if(SDL_SemWait(job->ready)!=0)return -1;
        if(job->stop)break;
        fesetround(job->rounding);
#if defined(_M_X64) || defined(__x86_64__)
        _mm_setcsr(job->mxcsr);
#endif
        run_vertex_job(job);
        if(s_coalesced_batch){if(!vertex_completion_finish(&s_vertex_completion))abort();}
        else SDL_SemPost(s_vertices_done);
    }
    return 0;
}
static void initialize_vertex_workers(void) {
    if(s_vertex_pool_initialized)return;s_vertex_pool_initialized=true;
    s_validate_workers=getenv("GX_VALIDATE_WORKERS")!=NULL;
    if(getenv("GX_SINGLE_THREADED") || SDL_GetCPUCount()<2)return;
    s_vertices_done=SDL_CreateSemaphore(0);if(!s_vertices_done)return;
    if(!vertex_completion_init(&s_vertex_completion))fprintf(stderr,"[GX workers] completion group unavailable; using original semaphores\n");
    u32 wanted=(u32)SDL_GetCPUCount()-1;if(wanted>3)wanted=3;
    for(u32 i=0;i<wanted;i++) {
        VertexDecodeJob* job=&s_vertex_workers[i];
        job->cache=(VertexCacheEntry*)calloc(4096,sizeof(VertexCacheEntry));job->raw_cache=(GXGLRawVertex*)calloc(4096,sizeof(GXGLRawVertex));job->ready=SDL_CreateSemaphore(0);
        if(job->cache && job->raw_cache && job->ready)job->thread=SDL_CreateThread(vertex_worker,"GX vertices",job);
        if(!job->thread){if(job->ready)SDL_DestroySemaphore(job->ready);free(job->cache);free(job->raw_cache);memset(job,0,sizeof(*job));break;}
        s_vertex_worker_count++;
    }
    printf("[GX vertices] %u helper threads; PPC and OpenGL stay on main thread\n",s_vertex_worker_count);
}
typedef struct {u64 hash,used,raw_hash;u32 bytes,count;u8* signature;GXGLRawVertex* vertices;} RawDrawCache;
static RawDrawCache s_raw_draw_cache[256];
static u8* s_raw_signature;static u32 s_raw_signature_capacity,s_raw_signature_bytes;
static size_t s_raw_cache_bytes;static u64 s_raw_cache_serial,s_raw_cache_hits,s_raw_cache_misses,s_last_raw_hash;
static bool s_decode_cache_enabled=true;
bool gx_pipe_dirty_tracking(void){return false;}
void gx_pipe_set_dirty_tracking(bool enabled){(void)enabled;}
void gx_pipe_dirty_diagnostics(u64* spans,u64* fallbacks){*spans=*fallbacks=0;}
static u64 s_decode_key_ticks,s_worker_wait_ticks,s_vertex_main_ticks;
static u64 s_key_details[6]; // page queries, input hash, input lookup, RAM bytes, versions bytes, misses ticks
void gx_pipe_key_details(u64* output){memcpy(output,s_key_details,sizeof(s_key_details));}
void gx_pipe_set_decode_cache(bool enabled){s_decode_cache_enabled=enabled;}
void gx_pipe_decode_diagnostics(u64* hits,u64* misses,u64* keys,u64* waits,u64* main){*hits=s_raw_cache_hits;*misses=s_raw_cache_misses;*keys=s_decode_key_ticks;*waits=s_worker_wait_ticks;*main=s_vertex_main_ticks;}
static u64 raw_hash(const void* data,size_t bytes){
#ifdef DIGIMON_XXHASH
    return XXH64(data,bytes,0x58464758u);
#else
    const u8* p=data;u64 h=0xCBF29CE484222325ull;for(size_t i=0;i<bytes;i++)h=(h^p[i])*0x100000001B3ull;return h;
#endif
}
static bool raw_signature_append(const void* data,u32 bytes){
    if(bytes>1024u*1024u-s_raw_signature_bytes)return false;
    u32 needed=s_raw_signature_bytes+bytes;
    if(needed>s_raw_signature_capacity){u8* p=realloc(s_raw_signature,needed);if(!p)return false;s_raw_signature=p;s_raw_signature_capacity=needed;}
    memcpy(s_raw_signature+s_raw_signature_bytes,data,bytes);s_raw_signature_bytes=needed;return true;
}
static bool raw_signature(CPUState* cpu,const VertexLayout* layout,u32 cursor,u32 count,const VertexInput* input){
    s_raw_signature_bytes=0;
    if(!count || (u64)layout->stride*count>input->size)return false;
    // Raw attributes depend on the active layout, matrix-index defaults and
    // indexed arrays actually consumed. Other VATs/materials/XF matrices do not
    // invalidate decoded geometry. Serialize members, never struct padding.
    VertexLayout key={0};key.stride=layout->stride;key.matrix_bytes=layout->matrix_bytes;
    for(u32 j=0;j<12;j++)if(layout->mode[j]){
        key.mode[j]=layout->mode[j];key.format[j]=layout->format[j];
        key.components[j]=layout->components[j];key.fraction[j]=layout->fraction[j];
    }
    if(layout->mode[1])key.normal_indices=layout->normal_indices;
    u32 matrices[3]={input->cp[0x30]&0x3FFFFFFFu,input->cp[0x40]&0xFFFFFFu,input->cp[0x50]&0x1FFu};
    if(!raw_signature_append(&key.stride,8) || !raw_signature_append(key.mode,49) ||
       !raw_signature_append(matrices,sizeof(matrices)))return false;
    u32 bytes=layout->stride*count,at=cursor%input->size,first=input->size-at;if(first>bytes)first=bytes;
    if(!raw_signature_append(input->fifo+at,first) || !raw_signature_append(input->fifo,bytes-first))return false;
    u32 offset=layout->matrix_bytes;
    for(u32 j=0;j<12;j++){
        u32 mode=layout->mode[j];if(!mode)continue;
        u32 size=j==2 || j==3 ? color_size(layout->format[j]):layout->components[j]*scalar_size(layout->format[j]);
        if(mode==1){offset+=size;continue;}
        u32 minimum=~0u,maximum=0,index_bytes=mode-1,indices=j==1 ? layout->normal_indices:1;
        // Decoder consumes NBT's additional indices but reads the first array
        // element. Hash that exact source span, including invalidation holes.
        for(u32 i=0;i<count;i++){
            u32 p=(cursor+i*layout->stride+offset)%input->size,index=input->fifo[p];
            if(index_bytes==2)index=(index<<8)|input->fifo[(p+1)%input->size];
            if(index<minimum)minimum=index;if(index>maximum)maximum=index;
        }
        u32 stride=input->cp[0xB0+j]&255u;
        u32 array[2]={input->cp[0xA0+j]&0x1FFFFFFu,stride};
        if(!raw_signature_append(array,sizeof(array)))return false;
        u64 begin=(input->cp[0xA0+j]&0x1FFFFFFu)+(u64)minimum*stride,end=(input->cp[0xA0+j]&0x1FFFFFFu)+(u64)maximum*stride+size;
        if(end>cpu->ram_size || begin>end)return false;
        u32 length=(u32)(end-begin);
        s_key_details[3]+=length;
        if(!raw_signature_append(&length,4) || !raw_signature_append(cpu->ram+(u32)begin,length))return false;
        offset+=indices*index_bytes;
    }
    return offset==layout->stride;
}
static RawDrawCache* raw_draw_find(u64 hash,u32 count){
    for(u32 i=0;i<256;i++){RawDrawCache* e=s_raw_draw_cache+i;
        if(e->vertices && e->hash==hash && e->count==count && e->bytes==s_raw_signature_bytes && !memcmp(e->signature,s_raw_signature,e->bytes)){
            e->used=++s_raw_cache_serial;return e;
        }
    }return NULL;
}
static void raw_draw_evict(RawDrawCache* e){
    if(e->vertices)s_raw_cache_bytes-=e->bytes+(size_t)e->count*sizeof(*e->vertices);
    free(e->signature);free(e->vertices);memset(e,0,sizeof(*e));
}
static void raw_draw_store_key(u64 hash,u32 count,const GXGLRawVertex* raw,const u8* key,u32 key_bytes,u64 raw_value){
    size_t bytes=key_bytes+(size_t)count*sizeof(*raw);if(bytes>32u*1024u*1024u)return;
    RawDrawCache* slot=NULL;
    for(u32 i=0;i<256;i++)if(!s_raw_draw_cache[i].vertices){slot=s_raw_draw_cache+i;break;}
    while(!slot || s_raw_cache_bytes+bytes>32u*1024u*1024u){
        RawDrawCache* oldest=NULL;
        for(u32 i=0;i<256;i++)if(s_raw_draw_cache[i].vertices && (!oldest || s_raw_draw_cache[i].used<oldest->used))oldest=s_raw_draw_cache+i;
        if(!oldest)return;raw_draw_evict(oldest);slot=oldest;
    }
    u8* signature=malloc(key_bytes);GXGLRawVertex* vertices=malloc((size_t)count*sizeof(*raw));
    if(!signature || !vertices){free(signature);free(vertices);return;}
    memcpy(signature,key,key_bytes);memcpy(vertices,raw,(size_t)count*sizeof(*raw));
    *slot=(RawDrawCache){hash,++s_raw_cache_serial,raw_value,key_bytes,count,signature,vertices};s_raw_cache_bytes+=bytes;
}
static void raw_draw_store(u64 hash,u32 count,const GXGLRawVertex* raw){
    s_last_raw_hash=raw_hash(raw,(size_t)count*sizeof(*raw));
    raw_draw_store_key(hash,count,raw,s_raw_signature,s_raw_signature_bytes,s_last_raw_hash);
}
bool gx_pipe_async_decode(void){return false;}
void gx_pipe_set_async_decode(bool enabled){(void)enabled;}
void gx_pipe_async_reuse(u64* hits,u64* misses,u64* drains,u64* peak){*hits=*misses=*drains=*peak=0;}
void gx_pipe_async_diagnostics(u64* jobs,u64* vertices,u64* worker,u64* wait,u64* snapshot){*jobs=*vertices=*worker=*wait=*snapshot=0;}
static void decode_vertices_input(CPUState* cpu,const VertexLayout* layout,u32 cursor,QueuedVertex* output,u32 count,u32 chosen,bool software_tev,GXGLRawVertex* raw,const VertexInput* input) {
    u64 started=SDL_GetPerformanceCounter();
    s_last_raw_hash=0;u64 signature_hash=0;
    bool cacheable=false;
    if(raw && s_decode_cache_enabled){
        u64 key_start=SDL_GetPerformanceCounter();cacheable=raw_signature(cpu,layout,cursor,count,input);
        RawDrawCache* cached=NULL;
        if(cacheable){
            u64 measured=SDL_GetPerformanceCounter();signature_hash=raw_hash(s_raw_signature,s_raw_signature_bytes);
            s_key_details[1]+=SDL_GetPerformanceCounter()-measured;measured=SDL_GetPerformanceCounter();cached=raw_draw_find(signature_hash,count);
            s_key_details[2]+=SDL_GetPerformanceCounter()-measured;
        }
        s_decode_key_ticks+=SDL_GetPerformanceCounter()-key_start;
        if(cached){memcpy(raw,cached->vertices,(size_t)count*sizeof(*raw));s_last_raw_hash=cached->raw_hash;s_raw_cache_hits++;s_vertex_decode_ticks+=SDL_GetPerformanceCounter()-started;return;}
        s_raw_cache_misses++;
    }
    u64 miss_start=SDL_GetPerformanceCounter();
    if(!raw)prepare_vertex_constants(layout,cursor,count);
    u32 parallel_min=raw ? 4096u:1024u;
    if(count>=parallel_min && s_parallel_vertices_enabled)initialize_vertex_workers();
    u32 workers=count>=parallel_min && s_parallel_vertices_enabled ? s_vertex_worker_count : 0,part=count/(workers+1u);
    VertexDecodeJob main_job={0};main_job.cpu=cpu;main_job.layout=*layout;main_job.input=*input;main_job.environment=s_decode_environment;main_job.chosen=chosen;main_job.software_tev=software_tev;
    main_job.rounding=fegetround();
#if defined(_M_X64) || defined(__x86_64__)
    main_job.mxcsr=_mm_getcsr();
#endif
    s_coalesced_batch=workers && s_coalesced_enabled && s_vertex_completion.done;
    if(s_coalesced_batch)vertex_completion_begin(&s_vertex_completion,(int)workers);
    for(u32 i=0;i<workers;i++) {
        VertexDecodeJob* job=&s_vertex_workers[i];
        job->cpu=cpu;job->layout=*layout;job->input=*input;job->environment=s_decode_environment;job->chosen=chosen;job->software_tev=software_tev;
        job->rounding=main_job.rounding;job->mxcsr=main_job.mxcsr;job->hits=job->misses=0;
        job->cursor=(cursor+i*part*layout->stride)%input->size;job->count=part;job->output=output+i*part;job->raw=raw ? raw+i*part:NULL;
        SDL_SemPost(job->ready);
    }
    main_job.cursor=(cursor+workers*part*layout->stride)%input->size;main_job.count=count-workers*part;
    main_job.output=output+workers*part;main_job.cache=s_vertex_cache;main_job.raw=raw ? raw+workers*part:NULL;main_job.raw_cache=s_raw_vertex_cache;u64 main_started=SDL_GetPerformanceCounter();run_vertex_job(&main_job);
    s_vertex_main_ticks+=SDL_GetPerformanceCounter()-main_started;u64 wait_started=SDL_GetPerformanceCounter();
    if(s_coalesced_batch){if(!vertex_completion_wait(&s_vertex_completion))abort();}
    else for(u32 i=0;i<workers;i++)SDL_SemWait(s_vertices_done);
    s_worker_wait_ticks+=SDL_GetPerformanceCounter()-wait_started;
    for(u32 i=0;i<workers;i++){main_job.hits+=s_vertex_workers[i].hits;main_job.misses+=s_vertex_workers[i].misses;}
    s_vertex_cache_hits+=main_job.hits;s_vertex_cache_misses+=main_job.misses;
    if(workers) {
        s_parallel_batches++;
        if(s_validate_workers)for(u32 i=0;i<count;i++) {
            QueuedVertex reference;GXGLRawVertex raw_reference;decode_vertex_input(cpu,layout,(cursor+i*layout->stride)%input->size,&reference,chosen,software_tev,raw ? &raw_reference:NULL,input);
            if(raw ? memcmp(&raw_reference,raw+i,sizeof(raw_reference)) : memcmp(&reference,output+i,sizeof(reference))){fprintf(stderr,"[GX workers] serial/parallel mismatch at vertex %u\n",i);abort();}
        }
    }
    if(cacheable)raw_draw_store(signature_hash,count,raw);
    if(raw)s_key_details[5]+=SDL_GetPerformanceCounter()-miss_start;
    s_vertex_decode_ticks+=SDL_GetPerformanceCounter()-started;
}
static void decode_vertices(CPUState* cpu,const VertexLayout* layout,u32 cursor,QueuedVertex* output,u32 count,u32 chosen,bool software_tev,GXGLRawVertex* raw){
    VertexInput input={s_cp,s_fifo_buf,FIFO_BUFFER_SIZE};decode_vertices_input(cpu,layout,cursor,output,count,chosen,software_tev,raw,&input);
}


// Process pending commands in FIFO
static void gx_pipe_process_internal_timed_body(CPUState* cpu) {
    s_fifo_parses++;
    static u32 s_bp_log_count = 0;
    static u32 s_draw_log_count = 0;

    while (s_fifo_read_tail != s_fifo_write_head) {
        u32 available = (s_fifo_write_head >= s_fifo_read_tail)
                        ? (s_fifo_write_head - s_fifo_read_tail)
                        : (FIFO_BUFFER_SIZE - s_fifo_read_tail + s_fifo_write_head);
        if (available == 0) break;

        s_fifo_needed=1;
        u8 opcode = s_fifo_buf[s_fifo_read_tail];

        // 1. NOP (0x00)
        if (opcode == 0x00) {
            s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 2. Load CP Register (0x08) - 6 bytes: 0x08 <u8 reg> <u32 val>
        if (opcode == 0x08) {
            if (available < 6) {s_fifo_needed=6;break;}
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
            s_cp[cp_reg] = cp_val;
            s_fifo_read_tail = (s_fifo_read_tail + 6) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 3. Load XF Register (0x10) - 5 + (count * 4) bytes: 0x10 <u16 count_minus_1> <u16 addr> <data...>
        if (opcode == 0x10) {
            if (available < 5) {s_fifo_needed=5;break;}
            u16 count_m1 = ((u16)s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE] << 8) |
                            s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE];
            u16 xf_addr = ((u16)s_fifo_buf[(s_fifo_read_tail + 3) % FIFO_BUFFER_SIZE] << 8) |
                           s_fifo_buf[(s_fifo_read_tail + 4) % FIFO_BUFFER_SIZE];
            u32 count = (u32)count_m1 + 1;
            u32 total_len = 5 + count * 4;
            if (available < total_len) {s_fifo_needed=total_len;break;}
            static u32 s_xf_log = 0;
            if (s_xf_log++ < 25) {
                printf("[GX XF #%u] addr=0x%04X count=%u (len=%u)\n", s_xf_log, xf_addr, count, total_len);
                fflush(stdout);
            }
            for (u32 j = 0; j < count; j++) {
                u32 word = 0;
                for (u32 k = 0; k < 4; k++) word = (word << 8) | s_fifo_buf[(s_fifo_read_tail + 5 + j*4 + k) % FIFO_BUFFER_SIZE];
                write_xf_word(xf_addr+j,word);
            }
            if (xf_addr<=0x1011 && xf_addr+count>0x100A)s_lighting_loaded=true;
            if (xf_addr <= 0x1026 && xf_addr + count > 0x1026) s_projection_loaded = true;
            s_fifo_read_tail = (s_fifo_read_tail + total_len) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 4. Load Indx A/B/C/D (0x20, 0x28, 0x30, 0x38) - 5 bytes: opcode <u32 val>
        if (opcode == 0x20 || opcode == 0x28 || opcode == 0x30 || opcode == 0x38) {
            if (available < 5) {s_fifo_needed=5;break;}
            u32 value = 0;
            for (u32 j = 1; j <= 4; j++) value = (value << 8) | s_fifo_buf[(s_fifo_read_tail + j) % FIFO_BUFFER_SIZE];
            u32 array = 12 + ((opcode - 0x20) >> 3), index = value >> 16;
            u32 target = value & 0xFFFu, words = ((value >> 12) & 15u) + 1;
            u32 addr = (s_cp[0xA0 + array] & 0x1FFFFFFu) + index * (s_cp[0xB0 + array] & 255u);
            if (addr <= cpu->ram_size && words * 4 <= cpu->ram_size - addr)
                for (u32 j = 0; j < words && target + j < 0x1058; j++)
                    write_xf_word(target+j,mem_read32(cpu,GC_RAM_BASE+addr+j*4));
            s_fifo_read_tail = (s_fifo_read_tail + 5) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 5. Call Display List (0x40) - 9 bytes: 0x40 <u32 addr> <u32 size>
        if (opcode == 0x40) {
            if (available < 9) {s_fifo_needed=9;break;}
            u32 dl_addr = ((u32)s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE] << 24) |
                          ((u32)s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE] << 16) |
                          ((u32)s_fifo_buf[(s_fifo_read_tail + 3) % FIFO_BUFFER_SIZE] << 8)  |
                          s_fifo_buf[(s_fifo_read_tail + 4) % FIFO_BUFFER_SIZE];
            u32 dl_size = ((u32)s_fifo_buf[(s_fifo_read_tail + 5) % FIFO_BUFFER_SIZE] << 24) |
                          ((u32)s_fifo_buf[(s_fifo_read_tail + 6) % FIFO_BUFFER_SIZE] << 16) |
                          ((u32)s_fifo_buf[(s_fifo_read_tail + 7) % FIFO_BUFFER_SIZE] << 8)  |
                          s_fifo_buf[(s_fifo_read_tail + 8) % FIFO_BUFFER_SIZE];
            s_fifo_read_tail = (s_fifo_read_tail + 9) % FIFO_BUFFER_SIZE;
            static u32 s_dl_log = 0;
            if (s_dl_log++ < 20) {
                printf("[GX Call DL #%u] addr=0x%08X size=%u bytes\n", s_dl_log, dl_addr, dl_size);
                fflush(stdout);
            }
            u32 gc_dl_addr = (dl_addr & 0x01FFFFFFu) | GC_RAM_BASE;
            if (gc_dl_addr >= GC_RAM_BASE && (gc_dl_addr - GC_RAM_BASE + dl_size) <= cpu->ram_size && dl_size > 0 && dl_size < 1048576) {
                gx_pipe_process_display_list(cpu, cpu->ram + (gc_dl_addr - GC_RAM_BASE), dl_size);
            }
            continue;
        }

        // 6. Invalidate Vertex Cache (0x48) - 1 byte
        if (opcode == 0x48) {
            s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
            continue;
        }

        // 7. Load BP Register (0x61) - 5 bytes: 0x61 <u32 val>
        if (opcode == 0x61) {
            if (available < 5) {s_fifo_needed=5;break;}
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

            if (bp_reg == 0xFE) { s_bp_mask = reg_val; continue; }
            reg_val = (s_bp[bp_reg] & ~s_bp_mask) | (reg_val & s_bp_mask);
            s_bp_mask = 0xFFFFFFu;
            // Material state must be consumed before changing texture/palette bindings.
            if (bp_reg >= 0xE0 && bp_reg <= 0xE7)
                ((reg_val&0x800000u) ? s_konst_registers : s_tev_registers)[bp_reg-0xE0]=reg_val;
            s_bp[bp_reg] = reg_val;
            s_bp_written[bp_reg]=true;
            if (bp_reg == 0x52) {
                if (reg_val & 0x4000u) copy_efb(cpu, reg_val);
                else {u64 started=SDL_GetPerformanceCounter();bool threaded=gx_frame_active();copy_efb_texture(cpu,reg_val);if(!threaded)s_texture_copy_ticks+=SDL_GetPerformanceCounter()-started;}
            } else if (bp_reg == 0x45 && (reg_val & 2u)) {
                if (flush_efb(cpu) && frame_queue_pe()) video_trigger_pe_finish();
            } else if (bp_reg == 0x47 || bp_reg == 0x48) {
                s_pe_token = (u16)reg_val;
                if (bp_reg == 0x48 && flush_efb(cpu) && frame_queue_pe()) video_trigger_pe_token();
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
            } else if (bp_reg == 0x65) {
                s_tlut_sync++;flush_efb(cpu);
                u32 offset = (reg_val & 1023u) << 9;
                u32 length = ((reg_val >> 10) & 2047u) * 32;
                u32 source = s_active_tlut_addr & 0x1FFFFFFFu;
                if (source <= cpu->ram_size && length <= cpu->ram_size-source &&
                    offset <= sizeof(s_tlut_memory) && length <= sizeof(s_tlut_memory)-offset)
                    {memcpy(s_tlut_memory+offset,cpu->ram+source,length);if(!gx_frame_active())s_texture_epoch++;}
            } else if ((bp_reg >= 0x98 && bp_reg <= 0x9B) || (bp_reg >= 0xB8 && bp_reg <= 0xBB)) {
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
                    if (gc_tex >= GC_RAM_BASE && gc_tex < (GC_RAM_BASE + cpu->ram_size)) {
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

        // Packet length is derived from VCD/VAT, never from plausible command bytes.
        if ((opcode & 0xF8) >= 0x80 && (opcode & 0xF8) <= 0xB8) {
            if (available < 3) {s_fifo_needed=3;break;}
            u32 count = ((u32)s_fifo_buf[(s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE] << 8) |
                        s_fifo_buf[(s_fifo_read_tail + 2) % FIFO_BUFFER_SIZE];
            VertexLayout layout = vertex_layout(opcode & 7);
            u32 packet = 3 + count * layout.stride;
            if ((count && !layout.stride) || packet >= FIFO_BUFFER_SIZE) {
                fprintf(stderr, "[GX] invalid VCD/VAT at FIFO offset %u\n", s_fifo_read_tail);
                fprintf(stderr, "opcode=%02X count=%u lo=%08X hi=%08X VAT=%08X bytes:", opcode, count, s_cp[0x50], s_cp[0x60], s_cp[0x70+(opcode&7)]);
                for (u32 z=0; z<32; z++) fprintf(stderr, " %02X", s_fifo_buf[(s_fifo_read_tail+z)%FIFO_BUFFER_SIZE]);
                fprintf(stderr, "\n");
                break;
            }
            if (available < packet) {s_fifo_needed=packet;break;}
            if (s_queued_draw_count >= MAX_QUEUED_DRAWS || s_queued_vtx_count + count > MAX_QUEUED_VERTICES) flush_efb(cpu);
            if (s_queued_draw_count < MAX_QUEUED_DRAWS && s_queued_vtx_count + count <= MAX_QUEUED_VERTICES) {
                u32 draw_index=s_queued_draw_count++;QueuedDraw* draw=&s_queued_draws[draw_index];
                draw->prim_type = opcode & 0xF8;
                draw->vtx_start = (u16)s_queued_vtx_count;
                draw->vtx_count = (u16)count;
                u32 selected=tev_texture_stage();
                u32 order=s_bp[0x28+selected/2] >> ((selected&1)*12);
                u32 unit = order & 7u;
                TexStage* stage = &s_tex_stages[unit];
                draw->tex_addr = stage->addr; draw->tex_w = stage->width;
                draw->tex_h = stage->height; draw->tex_fmt = stage->format;
                draw->has_texture = (order & 64u) && stage->addr && tev_uses_texture();
                u32 tlut = s_bp[(unit < 4 ? 0x98 : 0xB8) + (unit & 3)];
                draw->palette_offset = (tlut & 1023u) << 9;
                draw->palette_format = (u8)((tlut >> 10) & 3u);
                draw->blend_control = s_bp[0x41];
                memcpy(draw->material.bp,s_bp,sizeof(s_bp));
                memcpy(draw->material.colors,s_tev_registers,sizeof(s_tev_registers));
                memcpy(draw->material.konst,s_konst_registers,sizeof(s_konst_registers));
                memcpy(draw->debug_cp,s_cp,sizeof(s_cp));draw->debug_cp[255]=opcode&7u;
                memcpy(draw->debug_xf,s_xf,256*4);
                memcpy(draw->debug_transform,s_xf+0x101A,13*4);
                draw->material.tev_valid=s_bp_written[0xC0] || s_bp_written[0xC1];
                draw->material.alpha_valid=s_bp_written[0xF3];
                draw->material.scissor_valid=s_bp_written[0x20] && s_bp_written[0x21];
                bool software_tev=s_capture!=NULL || !(native_route() && (gx_frame_active() || gx_gl_available(s_renderer)));
                bool gpu=s_gpu_xf_enabled && !software_tev && s_projection_loaded && fegetround()==FE_TONEAREST && (gx_frame_active() || gx_gl_xf_available(s_renderer));
                s_gpu_draws[draw_index]=gpu;
                if(gpu || gx_frame_active()){memcpy(s_gpu_transforms[draw_index].words,s_xf,sizeof(s_xf));s_gpu_transforms[draw_index].projection=s_projection_loaded;s_gpu_transforms[draw_index].lighting=s_lighting_loaded;if(gpu)s_gpu_xf_batches++;}
                u32 chosen=(order>>3)&7u;
                if(gx_frame_active()){
                    // All attribute conversion, CPU-XF fallback and geometry
                    // caches belong to the consumer's private decoder view.
                    --s_queued_draw_count;
                    if(!frame_queue_draws(cpu) || !frame_queue_raw(cpu,draw,s_gpu_transforms+draw_index,&layout,(s_fifo_read_tail+3)%FIFO_BUFFER_SIZE,gpu,chosen))gx_frame_fail();
                }else{
                    if(++s_vertex_cache_epoch==0){
                        memset(s_vertex_cache,0,sizeof(s_vertex_cache));s_vertex_cache_epoch=1;
                        for(u32 i=0;i<s_vertex_worker_count;i++)memset(s_vertex_workers[i].cache,0,sizeof(s_vertex_cache));
                    }
                    decode_vertices(cpu,&layout,(s_fifo_read_tail+3)%FIFO_BUFFER_SIZE,s_queued_vertices+s_queued_vtx_count,count,chosen,software_tev,gpu ? s_raw_vertices+s_queued_vtx_count:NULL);
                    s_gpu_raw_hash[draw_index]=gpu ? s_last_raw_hash:0;s_queued_vtx_count+=count;
                }
            }
            s_draw_call_count++;
            s_fifo_read_tail = (s_fifo_read_tail + packet) % FIFO_BUFFER_SIZE;
            continue;
        }

        // Unknown byte: advance by 1
        s_fifo_read_tail = (s_fifo_read_tail + 1) % FIFO_BUFFER_SIZE;
    }
    if(s_fifo_read_tail==s_fifo_write_head)s_fifo_needed=1;
}
static void gx_pipe_process_internal(CPUState* cpu) {
    FrameStage previous=frame_timing_enter(FRAME_GX_DECODE);
    gx_pipe_process_internal_timed_body(cpu);
    frame_timing_leave(previous);
}


// Flushes and processes any pending commands in the FIFO
static void gx_pipe_process_frame_timed_body(CPUState* cpu) {
    u32 budget = FIFO_BUFFER_SIZE / 32;
    while ((s_cp_control & 1u) && s_cp_distance >= 32 && budget--) {
        if ((s_cp_control & 2u) && s_cp_read_ptr == s_cp_breakpoint) break;
        if (s_cp_read_ptr > cpu->ram_size - 32 || s_cp_read_ptr < s_cp_base || s_cp_read_ptr > s_cp_end) break;
        u32 available = (s_fifo_write_head + FIFO_BUFFER_SIZE - s_fifo_read_tail) % FIFO_BUFFER_SIZE;
        if (available + 32 >= FIFO_BUFFER_SIZE) gx_pipe_process_internal(cpu);
        available = (s_fifo_write_head + FIFO_BUFFER_SIZE - s_fifo_read_tail) % FIFO_BUFFER_SIZE;
        if (available + 32 >= FIFO_BUFFER_SIZE) break;
        u32 batch=s_cp_distance&~31u;
        u32 contiguous=s_cp_end-s_cp_read_ptr+32u;
        if(batch>contiguous)batch=contiguous;
        if(batch>cpu->ram_size-s_cp_read_ptr)batch=(cpu->ram_size-s_cp_read_ptr)&~31u;
        u32 room=(FIFO_BUFFER_SIZE-1u-available)&~31u;
        if(batch>room)batch=room;
        if(batch>65536u)batch=65536u;
        if(batch>(budget+1u)*32u)batch=(budget+1u)*32u;
        if((s_cp_control&2u) && s_cp_breakpoint>s_cp_read_ptr && s_cp_breakpoint-s_cp_read_ptr<batch)
            batch=(s_cp_breakpoint-s_cp_read_ptr)&~31u;
        if(!batch)break;
        u32 first=FIFO_BUFFER_SIZE-s_fifo_write_head;if(first>batch)first=batch;
        memcpy(s_fifo_buf+s_fifo_write_head,cpu->ram+s_cp_read_ptr,first);
        if(first<batch)memcpy(s_fifo_buf,cpu->ram+s_cp_read_ptr+first,batch-first);
        s_fifo_write_head=(s_fifo_write_head+batch)%FIFO_BUFFER_SIZE;
        s_cp_read_ptr += batch;
        if (s_cp_read_ptr > s_cp_end) s_cp_read_ptr = s_cp_base;
        s_cp_distance -= batch;
        budget-=batch/32u-1u;
        gx_pipe_process_internal(cpu);
    }
    gx_pipe_process_internal(cpu);
}
void gx_pipe_process_frame(CPUState* cpu) {
    FrameStage previous=frame_timing_enter(FRAME_GX_DECODE);
    gx_pipe_process_frame_timed_body(cpu);
    frame_timing_leave(previous);
}


// Clear queued draws and vertices each frame
void gx_pipe_clear_queued_draws(void) {
    
    s_queued_vtx_count = 0;
    s_queued_draw_count = 0;
}

static SDL_BlendMode gx_blend_mode(u32 control) {
    if (!(control & 1u)) return SDL_BLENDMODE_NONE;
    static const SDL_BlendFactor source[8] = {SDL_BLENDFACTOR_ZERO,SDL_BLENDFACTOR_ONE,
        SDL_BLENDFACTOR_DST_COLOR,SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR,SDL_BLENDFACTOR_SRC_ALPHA,
        SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,SDL_BLENDFACTOR_DST_ALPHA,SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA};
    static const SDL_BlendFactor dest[8] = {SDL_BLENDFACTOR_ZERO,SDL_BLENDFACTOR_ONE,
        SDL_BLENDFACTOR_SRC_COLOR,SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR,SDL_BLENDFACTOR_SRC_ALPHA,
        SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,SDL_BLENDFACTOR_DST_ALPHA,SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA};
    return SDL_ComposeCustomBlendMode(source[(control>>8)&7],dest[(control>>5)&7],
        (control & 0x800u) ? SDL_BLENDOPERATION_REV_SUBTRACT : SDL_BLENDOPERATION_ADD,
        SDL_BLENDFACTOR_ONE,SDL_BLENDFACTOR_ZERO,SDL_BLENDOPERATION_ADD);
}

// Renders extracted 2D primitives directly to the SDL2 renderer
static bool merge_raw_draws(const QueuedDraw* first,const GXGLTransform* xf,const QueuedDraw* next,const GXGLTransform* next_xf,u32 end){
    u32 group=first->prim_type==0x80 || first->prim_type==0x88 ? 4:first->prim_type==0x90 ? 3:first->prim_type==0xA8 ? 2:first->prim_type==0xB8 ? 1:0;
    return group && first->vtx_count%group==0 && next->vtx_count%group==0 && next->vtx_start==end &&
        first->prim_type==next->prim_type && !memcmp(&first->material,&next->material,sizeof(first->material)) &&
        xf->projection==next_xf->projection && xf->lighting==next_xf->lighting && !memcmp(xf->words,next_xf->words,sizeof(xf->words));
}
static void gx_pipe_render_to_sdl_timed_body(SDL_Renderer* renderer, CPUState* cpu, int game_x, int game_y, int game_w, int game_h,GXRenderView* view) {
    if (!renderer || view->draw_count == 0) return;
    u64 timing_start=SDL_GetPerformanceCounter();
    s_texture_epoch++;

    static u32 s_sdl_render_log = 0;
    if (s_sdl_render_log++ < 10) {
        printf("[GX SDL2 Renderer #%u] Desenhando %u primitivas (%u vertices) na janela SDL2! Viewport: (%d, %d, %dx%d)\n",
               s_sdl_render_log, view->draw_count, view->vertex_count, game_x, game_y, game_w, game_h);
        fflush(stdout);
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Buffer for batching contiguous triangles with identical texture state
    #define MAX_BATCH_VERTS 2048
    static SDL_Vertex s_batch_verts[MAX_BATCH_VERTS];
    int batch_count = 0;
    SDL_Texture* current_tex = NULL;

    for (u32 d = 0; d < view->draw_count; d++) {
        QueuedDraw* qd = &view->draws[d];
        u32 start = qd->vtx_start;
        u32 count = qd->vtx_count;

        if (native_route() && gx_gl_available(renderer)) {
            u32 transform_index=d;
            if(view->gpu[d])while(d+1<view->draw_count && view->gpu[d+1] && merge_raw_draws(qd,view->transforms+transform_index,view->draws+d+1,view->transforms+d+1,start+count)){
                count+=view->draws[++d].vtx_count;s_merged_packets++;
            }
            SDL_Texture* images[8]={0};
            u32 units=0,stages=((qd->material.bp[0]>>10)&15u)+1;
            for (u32 stage=0;stage<stages;stage++) {
                u32 order=qd->material.bp[0x28+stage/2]>>((stage&1)*12);
                if (order&64u) units|=1u<<(order&7u);
            }
            for (u32 unit=0;unit<8;unit++) if (units&(1u<<unit)) {
                u32 base=unit<4 ? 0x80 : 0xA0,index=unit&3;
                u32 image0=qd->material.bp[base+8+index],image3=qd->material.bp[base+20+index];
                u32 tlut=qd->material.bp[base+24+index];
                s_palette_offset=(tlut&1023u)<<9; s_palette_format=(u8)((tlut>>10)&3);
                if (image3) images[unit]=get_or_create_texture(renderer,cpu,(image3<<5)|GC_RAM_BASE,
                    (u16)((image0&1023u)+1),(u16)(((image0>>10)&1023u)+1),(u8)((image0>>20)&15));
            }
            if(view->gpu[transform_index])gx_gl_draw_raw_hashed(renderer,&qd->material,images,view->raw+start,view->transforms+transform_index,count,qd->prim_type,d==transform_index ? view->hashes[transform_index]:0);
            else gx_gl_draw(renderer,&qd->material,images,&view->vertices[start].native,sizeof(QueuedVertex),count,qd->prim_type);
            continue;
        }

        // Flush before a cached texture can be replaced or its blend mode changes.
        if (batch_count) { SDL_RenderGeometry(renderer,current_tex,s_batch_verts,batch_count,NULL,0); batch_count=0; }
        SDL_BlendMode blend = gx_blend_mode(qd->blend_control);
        if (SDL_SetRenderDrawBlendMode(renderer,blend) != 0) SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        s_palette_offset = qd->palette_offset; s_palette_format = qd->palette_format;
        SDL_Texture* tex = NULL;
        if (qd->has_texture && qd->tex_addr >= GC_RAM_BASE) {
            tex = get_or_create_texture(renderer, cpu, qd->tex_addr, qd->tex_w, qd->tex_h, qd->tex_fmt);
        }

        if (tex && SDL_SetTextureBlendMode(tex,blend) != 0) SDL_SetTextureBlendMode(tex,SDL_BLENDMODE_BLEND);

        // Quads (0x80): decompose each quad of 4 vertices into 2 triangles (6 vertices)
        if ((qd->prim_type == 0x80 || qd->prim_type == 0x88)) {
            u32 num_quads = count / 4;
            for (u32 q = 0; q < num_quads; q++) {
                QueuedVertex* v0 = &view->vertices[start + q * 4 + 0];
                QueuedVertex* v1 = &view->vertices[start + q * 4 + 1];
                QueuedVertex* v2 = &view->vertices[start + q * 4 + 2];
                QueuedVertex* v3 = &view->vertices[start + q * 4 + 3];

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
                        v->color.r = qverts[i]->r;
                        v->color.g = qverts[i]->g;
                        v->color.b = qverts[i]->b;
                        v->color.a = qverts[i]->a;

                    v->tex_coord.x = qverts[i]->u;
                    v->tex_coord.y = qverts[i]->v;
                }
            }
        }
        // Triangles (0x90 or 0x88): discrete triangles if divisible by 3, or triangle strip fallback
        else if (qd->prim_type == 0x90) {
            if ((count % 3) == 0) {
                u32 num_tris = count / 3;
                for (u32 t = 0; t < num_tris; t++) {
                    if (batch_count > 0 && (current_tex != tex || batch_count + 3 > MAX_BATCH_VERTS)) {
                        SDL_RenderGeometry(renderer, current_tex, s_batch_verts, batch_count, NULL, 0);
                        batch_count = 0;
                    }
                    current_tex = tex;

                    for (int i = 0; i < 3; i++) {
                        QueuedVertex* qv = &view->vertices[start + t * 3 + i];
                        SDL_Vertex* v = &s_batch_verts[batch_count++];
                        v->position.x = (float)game_x + (qv->x / 640.0f) * (float)game_w;
                        v->position.y = (float)game_y + (qv->y / 480.0f) * (float)game_h;
                            v->color.r = qv->r;
                            v->color.g = qv->g;
                            v->color.b = qv->b;
                            v->color.a = qv->a;

                        v->tex_coord.x = qv->u;
                        v->tex_coord.y = qv->v;
                    }
                }
            } else {
                for (u32 i = 2; i < count; i++) {
                    QueuedVertex* v0;
                    QueuedVertex* v1;
                    QueuedVertex* v2 = &view->vertices[start + i];

                    if (i % 2 == 0) {
                        v0 = &view->vertices[start + i - 2];
                        v1 = &view->vertices[start + i - 1];
                    } else {
                        v0 = &view->vertices[start + i - 1];
                        v1 = &view->vertices[start + i - 2];
                    }

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
        // Triangle Strip (0x98 or 0x90 fallback)
        else if (qd->prim_type == 0x98) {
            for (u32 i = 2; i < count; i++) {
                QueuedVertex* v0;
                QueuedVertex* v1;
                QueuedVertex* v2 = &view->vertices[start + i];

                // Alternating winding order for triangle strip to prevent diagonal inversion
                if (i % 2 == 0) {
                    v0 = &view->vertices[start + i - 2];
                    v1 = &view->vertices[start + i - 1];
                } else {
                    v0 = &view->vertices[start + i - 1];
                    v1 = &view->vertices[start + i - 2];
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
        // Triangle Fan (0xA0 or legacy 0x98)
        else if (qd->prim_type == 0xA0) {
            for (u32 i = 1; i + 1 < count; i++) {
                QueuedVertex* v0 = &view->vertices[start];
                QueuedVertex* v1 = &view->vertices[start + i];
                QueuedVertex* v2 = &view->vertices[start + i + 1];

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

    s_render_ticks+=SDL_GetPerformanceCounter()-timing_start;
}
void gx_pipe_render_to_sdl(SDL_Renderer* renderer, CPUState* cpu, int game_x, int game_y, int game_w, int game_h) {
    if(gx_frame_active() && !gx_frame_consuming()){frame_queue_draws(cpu);gx_frame_submit(false);return;}
    FrameStage previous=frame_timing_enter(FRAME_GX_DECODE);
    capture_batch();
    GXRenderView view={s_queued_draws,s_queued_vertices,s_raw_vertices,s_gpu_transforms,s_gpu_draws,s_gpu_raw_hash,s_queued_draw_count,s_queued_vtx_count};
    gx_pipe_render_to_sdl_timed_body(renderer,cpu,game_x,game_y,game_w,game_h,&view);
    s_queued_draw_count=s_queued_vtx_count=0;
    frame_timing_leave(previous);
}


/* Persistent EFB: draw commands are rendered offscreen; only BP COPY_TRIGGER
 * writes guest XFB. Presentation never overlays pending GX draws on the window. */
static bool flush_efb_timed_body(CPUState* cpu) {
    if (!s_renderer) return false;
    SDL_Texture* previous = SDL_GetRenderTarget(s_renderer);
    int efb_w=(int)(640.0f*s_internal_scale+0.5f),efb_h=(int)(528.0f*s_internal_scale+0.5f);
    if (!s_efb) {
        s_efb = SDL_CreateTexture(s_renderer, SDL_PIXELFORMAT_RGBA32,
                                  SDL_TEXTUREACCESS_TARGET, efb_w, efb_h);
        if (!s_efb) return false;
        SDL_SetRenderTarget(s_renderer, s_efb);
        SDL_SetRenderDrawColor(s_renderer, 0, 0, 0, 255);
        SDL_RenderClear(s_renderer);
    } else if (SDL_SetRenderTarget(s_renderer, s_efb) != 0) return false;
    gx_pipe_render_to_sdl(s_renderer, cpu, 0, 0, efb_w, (int)(480.0f * s_internal_scale + 0.5f));
    SDL_RenderFlush(s_renderer);
    SDL_SetRenderTarget(s_renderer, previous);
    return true;
}
static bool flush_efb(CPUState* cpu) {
    if(gx_frame_consuming())return frame_backend_ensure();
    if(gx_frame_active())return frame_queue_draws(cpu);
    FrameStage previous=frame_timing_enter(FRAME_GL_SUBMIT);
    bool result=flush_efb_timed_body(cpu);
    frame_timing_leave(previous);return result;
}


static void clear_efb_region(const SDL_Rect* region,u32 ar,u32 gb,u32 z) {
    SDL_SetRenderDrawColor(s_renderer,(u8)ar,(u8)(gb>>8),(u8)gb,(u8)(ar>>8));
    SDL_BlendMode previous;SDL_GetRenderDrawBlendMode(s_renderer,&previous);
    SDL_SetRenderDrawBlendMode(s_renderer,SDL_BLENDMODE_NONE);
    SDL_Rect scaled = {
        (int)(region->x * s_internal_scale + 0.5f),
        (int)(region->y * s_internal_scale + 0.5f),
        (int)(region->w * s_internal_scale + 0.5f),
        (int)(region->h * s_internal_scale + 0.5f)
    };
    SDL_RenderFillRect(s_renderer,&scaled);
    SDL_SetRenderDrawBlendMode(s_renderer,previous);
    gx_gl_clear_depth(s_renderer,region->x,region->y,region->w,region->h,z);
}
static bool cache_efb_texture(CPUState* cpu,u32 address,u16 width,u16 height,u32 size,u8 texture_format,u32 copy_format,u32 step,bool luma,const SDL_Rect* source,bool vram_only){
    u32 slot=texture_find(address,width,height,texture_format,0);TexCacheEntry* entry=slot<MAX_TEX_CACHE ? s_tex_cache+slot:NULL;
    SDL_Texture* texture=entry ? entry->sdl_tex:SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,width,height);
    if(!texture)return false;
    if(!gx_gl_copy_texture(s_renderer,texture,source,copy_format,step,luma)){if(!entry)SDL_DestroyTexture(texture);else entry->epoch=~s_texture_epoch;return false;}
    u64 hash=texture_hash(cpu->ram+(address-GC_RAM_BASE),size,2166136261u);
    if(entry){if(!vram_only)vram_unpin(entry);entry->hash=hash;entry->epoch=s_texture_epoch;entry->last_used=++s_tex_serial;}
    else{SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);slot=texture_reserve();if(slot==MAX_TEX_CACHE){SDL_DestroyTexture(texture);return false;}texture_publish(slot,(TexCacheEntry){address,width,height,texture_format,hash,s_texture_epoch,0,texture});}
    entry=s_tex_cache+slot;if(vram_only && !entry->vram_only){entry->vram_only=true;s_vram_pending++;if(address<s_vram_min)s_vram_min=address;if(address+2048>s_vram_max)s_vram_max=address+2048;}return true;
}
static bool copy_efb_texture_timed_body(CPUState* cpu,u32 control) {
    const u32* bp=s_backend_bp ? s_backend_bp:s_bp;
    u32 x=bp[0x49]&1023u,y=(bp[0x49]>>10)&1023u;
    u32 w=(bp[0x4A]&1023u)+1,h=((bp[0x4A]>>10)&1023u)+1;
    u32 format=(control>>3)&15u;format=(format>>1)|((format&1)<<3);
    static const u8 tilew[13]={8,8,8,4,4,4,4,8,8,8,8,4,4};
    static const u8 tileh[13]={8,4,4,4,4,4,4,4,4,4,4,4,4};
    u32 step=(control&512u) ? 2 : 1,ow=w/step,oh=h/step;
    u32 dest=bp[0x4B]<<5,pitch=(bp[0x4D]&1023u)<<5;
    if(format>12 || !ow || !oh || x+w>640 || y+h>528)return false;
    u32 tw=tilew[format],th=tileh[format],bytes=format==6 ? 64 : 32;
    u32 tiles=(ow+tw-1)/tw,rows=(oh+th-1)/th;
    if(pitch<tiles*bytes || dest>cpu->ram_size || (u64)pitch*rows>cpu->ram_size-dest || !flush_efb(cpu))return false;
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);
    SDL_Rect source={(int)x,(int)y,(int)w,(int)h};
    bool fast=s_vram_only_enabled && !s_capture && format==0 && step==1 && ow==64 && oh==64 && pitch==256;
    u32 existing=fast ? texture_find(dest|GC_RAM_BASE,64,64,0,0):MAX_TEX_CACHE;
    if(fast && s_vram_pending>=64 && (existing==MAX_TEX_CACHE || !s_tex_cache[existing].vram_only))fast=false;
    if(!resolve_vram_overlap(cpu,dest|GC_RAM_BASE,pitch*rows,fast)){SDL_SetRenderTarget(s_renderer,previous);return false;}
    if(fast && cache_efb_texture(cpu,dest|GC_RAM_BASE,64,64,2048,0,0,1,(control&0x8000u)!=0,&source,true)){
        s_vram_only_copies++;
        if(control&0x800u)clear_efb_region(&source,bp[0x4F],bp[0x50],bp[0x51]);
        SDL_SetRenderTarget(s_renderer,previous);return true;
    }
    if(!s_readback_pixels)s_readback_pixels=(u8*)malloc(640u*528u*4u);
    u8* pixels=s_readback_pixels;if(!pixels){SDL_SetRenderTarget(s_renderer,previous);return false;}
    s_texture_readbacks++;bool ok=SDL_RenderReadPixels(s_renderer,&source,SDL_PIXELFORMAT_RGBA32,pixels,(int)w*4)==0;
    if(ok) {
        ppc_mark_host_write(cpu->ram+dest,pitch*rows);
        memset(cpu->ram+dest,0,pitch*rows);
        for(u32 py=0;py<oh;py++)for(u32 px=0;px<ow;px++) {
            u32 c[4]={0};for(u32 dy=0;dy<step;dy++)for(u32 dx=0;dx<step;dx++) {
                const u8* p=pixels+(((py*step+dy)*w)+px*step+dx)*4;
                for(u32 channel=0;channel<4;channel++)c[channel]+=p[channel];
            }
            for(u32 channel=0;channel<4;channel++)c[channel]/=step*step;
            u32 r=c[0],g=c[1],b=c[2],a=c[3];
            u32 intensity=(control&0x8000u) ? ((66*r+129*g+25*b+128)>>8)+16 : r;
            if(intensity>255)intensity=255;
            u32 n=(py%th)*tw+px%tw;u8* out=cpu->ram+dest+(py/th)*pitch+(px/tw)*bytes;
            u32 value=0;
            if(format==0) {u32 shift=(n&1) ? 0 : 4;out[n/2]=(u8)((out[n/2]&~(15u<<shift))|((intensity>>4)<<shift));}
            else if(format==1 || format==8)out[n]=(u8)intensity;
            else if(format==2)out[n]=(u8)((a&240)|(intensity>>4));
            else if(format==6) {out[n*2]=(u8)a;out[n*2+1]=(u8)r;out[32+n*2]=(u8)g;out[33+n*2]=(u8)b;}
            else if(format==7)out[n]=(u8)a;
            else if(format==9)out[n]=(u8)g;
            else if(format==10)out[n]=(u8)b;
            else {
                if(format==3)value=(a<<8)|intensity;
                else if(format==4)value=((r>>3)<<11)|((g>>2)<<5)|(b>>3);
                else if(format==5)value=a>=224 ? 0x8000|((r>>3)<<10)|((g>>3)<<5)|(b>>3) : ((a>>5)<<12)|((r>>4)<<8)|((g>>4)<<4)|(b>>4);
                else if(format==11)value=(g<<8)|r;
                else if(format==12)value=(b<<8)|g;
                out[n*2]=(u8)(value>>8);out[n*2+1]=(u8)value;
            }
        }
        if(pitch==tiles*bytes){static const u8 sampled_format[13]={0,1,2,3,4,5,6,1,1,1,1,3,3};cache_efb_texture(cpu,dest|GC_RAM_BASE,(u16)ow,(u16)oh,pitch*rows,sampled_format[format],format,step,(control&0x8000u)!=0,&source,false);}
        if(s_capture) {
            u32 event[12]={0,1,dest,pitch*rows,(control>>11)&1,x,y,w,h,bp[0x4F],bp[0x50],bp[0x51]};
            fwrite(event,sizeof(event),1,s_capture);fwrite(cpu->ram+dest,1,pitch*rows,s_capture);
        }
        if(control&0x800u)clear_efb_region(&source,bp[0x4F],bp[0x50],bp[0x51]);
        static u32 logs;if(logs++<8)printf("[GX texture copy] dst=%08X %ux%u format=%u stride=%u clear=%u\n",dest,ow,oh,format,pitch,(control>>11)&1);
    }
    SDL_SetRenderTarget(s_renderer,previous);return ok;
}
static bool copy_efb_texture(CPUState* cpu,u32 control) {
    if(gx_frame_active() && !gx_frame_consuming())return frame_queue_copy(cpu,control,false);
    FrameStage previous=frame_timing_enter(FRAME_EFB_COPY);
    bool result=copy_efb_texture_timed_body(cpu,control);
    frame_timing_leave(previous);return result;
}


static u8 clamp_byte(int value) { return (u8)(value < 0 ? 0 : value > 255 ? 255 : value); }
static bool copy_efb_timed_body(CPUState* cpu, u32 control) {
    const u32* bp=s_backend_bp ? s_backend_bp:s_bp;
    u32 x = bp[0x49] & 1023u, y = (bp[0x49] >> 10) & 1023u;
    u32 w = (bp[0x4A] & 1023u) + 1, h = ((bp[0x4A] >> 10) & 1023u) + 1;
    u32 dest = bp[0x4B] << 5, pitch = (bp[0x4D] & 1023u) << 5;
    u32 scale = bp[0x4E] & 511u;
    u32 out_h = (control & 0x400u) && scale ? 1u + ((h - 1u) * 256u) / scale : 1u + ((h - 1u) * scale) / 256u;
    if (!w || (w & 1u) || x + w > 640 || y + h > 528 || pitch < w * 2 ||
        !out_h || out_h > 576 || dest > cpu->ram_size ||
        (u64)pitch * out_h > cpu->ram_size - dest || !flush_efb(cpu)) {
        fprintf(stderr, "[GX copy] rejected dst=%08X src=%u,%u %ux%u pitch=%u height=%u\n",
                dest, x, y, w, h, pitch, out_h);
        return false;
    }
    SDL_Texture* previous = SDL_GetRenderTarget(s_renderer);
    SDL_Rect source = { (int)x, (int)y, (int)w, (int)h };
    u64 copy_start=SDL_GetPerformanceCounter();
    if(s_xfb_vram && !s_capture && native_route() && gx_gl_available(s_renderer) && snapshot_xfb(cpu,dest|GC_RAM_BASE,w,out_h,pitch,&source)) {
        if(!gx_frame_consuming())video_configure_xfb(dest|GC_RAM_BASE,w,out_h,pitch);s_display_copies++;
        if(control&0x800u){SDL_SetRenderTarget(s_renderer,s_efb);clear_efb_region(&source,bp[0x4F],bp[0x50],bp[0x51]);}
        SDL_SetRenderTarget(s_renderer,previous);s_copy_ticks+=SDL_GetPerformanceCounter()-copy_start;
        capture_next_frame(cpu);return true;
    }
    // Any eager write supersedes the GPU image at the same guest allocation.
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].address==(dest|GC_RAM_BASE))s_xfb_images[i].pending=false;
    bool gpu_copy=s_gpu_packed_copy_enabled && native_route() && gx_gl_pack_yuy2(s_renderer,s_efb,&source,out_h,cpu->ram+dest,pitch);
    static int validate_copy=-1;if(validate_copy<0)validate_copy=getenv("GX_VALIDATE_COPY")!=NULL;
    bool ok=gpu_copy;
    if(!gpu_copy || validate_copy) {
      if(!s_readback_pixels)s_readback_pixels=(u8*)malloc(640u*528u*4u);
      u8* pixels=s_readback_pixels;if(!pixels)return false;
      SDL_SetRenderTarget(s_renderer,s_efb);
      ok=SDL_RenderReadPixels(s_renderer,&source,SDL_PIXELFORMAT_RGBA32,pixels,(int)w*4)==0;
      if(ok) {
        for (u32 row = 0; row < out_h; row++) {
            u32 sy = row * h / out_h;
            u8* out = cpu->ram + dest + row * pitch;
            for (u32 col = 0; col < w; col += 2) {
                const u8* a = pixels + (sy * w + col) * 4;
                const u8* b = a + 4;
                int r = ((int)a[0] + b[0]) / 2, g = ((int)a[1] + b[1]) / 2, bl = ((int)a[2] + b[2]) / 2;
                u8 encoded[4]={clamp_byte(((66*a[0]+129*a[1]+25*a[2]+128)>>8)+16),
                    clamp_byte(((-38*r-74*g+112*bl+128)>>8)+128),
                    clamp_byte(((66*b[0]+129*b[1]+25*b[2]+128)>>8)+16),
                    clamp_byte(((112*r-94*g-18*bl+128)>>8)+128)};
                if(gpu_copy) {
                    if(memcmp(out+col*2,encoded,4)){fprintf(stderr,"[YUY2] GPU/CPU mismatch at %u,%u: %02X %02X %02X %02X vs %02X %02X %02X %02X\n",col,row,out[col*2],out[col*2+1],out[col*2+2],out[col*2+3],encoded[0],encoded[1],encoded[2],encoded[3]);abort();}
                } else memcpy(out+col*2,encoded,4);
            }
        }
      }
    }
    if(ok) {
        ppc_mark_host_write(cpu->ram+dest,pitch*out_h);
        if(!gx_frame_consuming())video_configure_xfb(dest | GC_RAM_BASE, w, out_h, pitch);
        s_display_copies++;
    }
    if (ok && (control & 0x800u)) {SDL_SetRenderTarget(s_renderer,s_efb);clear_efb_region(&source,bp[0x4F],bp[0x50],bp[0x51]);}
    SDL_SetRenderTarget(s_renderer, previous);
    s_copy_ticks+=SDL_GetPerformanceCounter()-copy_start;
    capture_next_frame(cpu);
    return ok;
}
static bool copy_efb(CPUState* cpu, u32 control) {
    if(gx_frame_active() && !gx_frame_consuming()){
        bool ok=frame_queue_copy(cpu,control,true);if(ok)s_submitted_display_copies++;return ok;
    }
    FrameStage previous=frame_timing_enter(FRAME_EFB_COPY);
    bool result=copy_efb_timed_body(cpu,control);
    if(result)s_submitted_display_copies++;
    frame_timing_leave(previous);return result;
}


u64 gx_pipe_get_total_bytes(void) {
    return s_total_fifo_bytes;
}

u32 gx_pipe_get_draw_calls(void) {
    return s_draw_call_count;
}

void gx_pipe_shutdown(void) {
    s_queued_draw_count=s_queued_vtx_count=0;
    for(u32 i=0;i<256;i++)raw_draw_evict(s_raw_draw_cache+i);free(s_raw_signature);s_raw_signature=NULL;s_raw_signature_capacity=0;
    for(u32 i=0;i<8;i++){free(s_display_list_buffers[i]);s_display_list_buffers[i]=NULL;}s_dl_depth=0;
    free(s_readback_pixels);s_readback_pixels=NULL;
    for(u32 i=0;i<s_vertex_worker_count;i++){s_vertex_workers[i].stop=true;SDL_SemPost(s_vertex_workers[i].ready);}
    for(u32 i=0;i<s_vertex_worker_count;i++){
        SDL_WaitThread(s_vertex_workers[i].thread,NULL);SDL_DestroySemaphore(s_vertex_workers[i].ready);free(s_vertex_workers[i].cache);free(s_vertex_workers[i].raw_cache);
    }
    vertex_completion_destroy(&s_vertex_completion);
    if(s_vertices_done)SDL_DestroySemaphore(s_vertices_done);
    memset(s_vertex_workers,0,sizeof(s_vertex_workers));s_vertex_worker_count=0;s_vertices_done=NULL;s_vertex_pool_initialized=false;
    if(s_capture){fclose(s_capture);s_capture=NULL;}
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].image)SDL_DestroyTexture(s_xfb_images[i].image);
    memset(s_xfb_images,0,sizeof(s_xfb_images));s_xfb_vram=false;
    gx_gl_shutdown();
    if (s_efb) { SDL_DestroyTexture(s_efb); s_efb = NULL; }
    s_renderer = NULL;
    for (u32 i = 0; i < s_tex_cache_count; i++) {
        if (s_tex_cache[i].sdl_tex) {
            SDL_DestroyTexture(s_tex_cache[i].sdl_tex);
            s_tex_cache[i].sdl_tex = NULL;
        }
    }
    s_tex_cache_count = 0;s_vram_pending=0;if(s_vram_read_target)SDL_DestroyTexture(s_vram_read_target);s_vram_read_target=NULL;memset(s_tex_buckets,0,sizeof(s_tex_buckets));s_tex_serial=0;free(s_decode_pixels);s_decode_pixels=NULL;s_decode_capacity=0;

    if (s_fifo_buf) {
        free(s_fifo_buf);
        s_fifo_buf = NULL;
    }
}

/* Host-only deterministic renderer replay; contains no CPU execution or input. */
int gx_pipe_replay(const char* path,const char* output,bool software) {
    FILE* file=fopen(path,"rb");if(!file){fprintf(stderr,"Cannot open GX capture %s\n",path);return 1;}
    u32 header[4];
    if(fread(header,sizeof(header),1,file)!=1 || header[0]!=0x47584331u || (header[1]!=sizeof(QueuedVertex) && header[1]!=140 && header[1]!=156) || (header[2]!=sizeof(QueuedDraw) && header[2]!=1124) || header[3]!=0x1800000u) {fclose(file);return 1;}
    SDL_SetMainReady();if(SDL_Init(SDL_INIT_VIDEO)!=0){fclose(file);return 1;}
    SDL_SetHint(SDL_HINT_RENDER_DRIVER,software ? "software" : "opengl");
    SDL_Window* window=SDL_CreateWindow("GX replay",0,0,640,528,SDL_WINDOW_HIDDEN);
    SDL_Renderer* renderer=window ? SDL_CreateRenderer(window,-1,(software ? SDL_RENDERER_SOFTWARE : SDL_RENDERER_ACCELERATED)|SDL_RENDERER_TARGETTEXTURE) : NULL;
    CPUState cpu={0};int result=1;
    if(!renderer || !cpu_init(&cpu))goto done;
    if(fread(cpu.ram,1,cpu.ram_size,file)!=cpu.ram_size)goto done;
    if(!gx_pipe_init(&cpu))goto done;gx_pipe_set_renderer(renderer);
    SDL_Surface* initial=SDL_CreateRGBSurfaceWithFormat(0,640,528,32,SDL_PIXELFORMAT_RGBA32);
    if(!initial)goto done;
    bool valid=fread(initial->pixels,1,640*528*4,file)==640*528*4;
    if(!valid){SDL_FreeSurface(initial);goto done;}
    s_efb=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,640,528);
    SDL_Texture* background=SDL_CreateTextureFromSurface(renderer,initial);SDL_FreeSurface(initial);
    if(!s_efb || !background){if(background)SDL_DestroyTexture(background);goto done;}
    SDL_SetRenderTarget(renderer,s_efb);SDL_SetTextureBlendMode(background,SDL_BLENDMODE_NONE);SDL_RenderCopy(renderer,background,NULL,NULL);SDL_DestroyTexture(background);
    if(getenv("GX_FRAME_REPLAY") && !gx_pipe_frame_start(&cpu,window))goto done;
    u32 sizes[2],batches=0;
    while(fread(sizes,sizeof(sizes),1,file)==1) {
        if(!sizes[0] && !sizes[1]) {result=0;break;}
        if(!sizes[0] && sizes[1]==1) {
            u32 event[10];if(fread(event,sizeof(event),1,file)!=1 || event[0]>cpu.ram_size || event[1]>cpu.ram_size-event[0])break;
            if(fread(cpu.ram+event[0],1,event[1],file)!=event[1])break;
            if(event[2]) {SDL_Rect region={(int)event[3],(int)event[4],(int)event[5],(int)event[6]};if(gx_frame_active()){if(!frame_queue_clear(&region,event[7],event[8],event[9]))break;}else clear_efb_region(&region,event[7],event[8],event[9]);}
            continue;
        }
        if(++batches>4096 || sizes[0]>MAX_QUEUED_DRAWS || sizes[1]>MAX_QUEUED_VERTICES)break;
        if(fread(s_tlut_memory,1,sizeof(s_tlut_memory),file)!=sizeof(s_tlut_memory))break;
        bool loaded=true;
        for(u32 j=0;j<sizes[0];j++){memset(&s_queued_draws[j],0,sizeof(QueuedDraw));if(fread(&s_queued_draws[j],1,header[2],file)!=header[2])loaded=false;}
        for(u32 j=0;j<sizes[1];j++){memset(&s_queued_vertices[j],0,sizeof(QueuedVertex));if(fread(&s_queued_vertices[j],1,header[1],file)!=header[1])loaded=false;}
        if(!loaded)break;
        bool bounds=true;
        for(u32 j=0;j<sizes[0];j++)if((u32)s_queued_draws[j].vtx_start+s_queued_draws[j].vtx_count>sizes[1])bounds=false;
        if(!bounds)break;
        s_queued_draw_count=sizes[0];s_queued_vtx_count=sizes[1];
        gx_pipe_render_to_sdl(renderer,&cpu,0,0,640,480);
    }
    if(gx_frame_active() && !gx_pipe_frame_stop(&cpu))result=1;
    if(!result) {
        SDL_Surface* image=SDL_CreateRGBSurfaceWithFormat(0,640,528,32,SDL_PIXELFORMAT_RGBA32);
        if(!image || SDL_RenderReadPixels(renderer,NULL,SDL_PIXELFORMAT_RGBA32,image->pixels,image->pitch)!=0 || SDL_SaveBMP(image,output)!=0)result=1;
        if(image)SDL_FreeSurface(image);
        printf("[GX replay] batches=%u result=%d output=%s\n",batches,result,output);
    }
    SDL_SetRenderTarget(renderer,NULL);
done:
    if(gx_frame_active())gx_pipe_frame_stop(&cpu);
    gx_pipe_shutdown();cpu_free(&cpu);if(renderer)SDL_DestroyRenderer(renderer);if(window)SDL_DestroyWindow(window);SDL_Quit();fclose(file);return result;
}

int gx_pipe_texture_contracts(CPUState* cpu,SDL_Renderer* renderer){
    if(s_tex_cache_count || cpu->ram_size<0x20100)return 1;
    u8* saved=malloc(520u*64u);if(!saved)return 1;memcpy(saved,cpu->ram+0x10000,520u*64u);
    u32 palette_offset=s_palette_offset;u8 palette_format=s_palette_format;s_palette_offset=s_palette_format=0;
    SDL_Texture* first[8]={0};int result=0;
    for(u32 i=0;i<512 && !result;i++){
        for(u32 n=0;n<16;n++){u8* p=cpu->ram+0x10000+i*64;p[n*2]=255;p[n*2+1]=(u8)i;p[32+n*2]=55;p[33+n*2]=101;}
        SDL_Texture* texture=get_or_create_texture(renderer,cpu,0x80010000u+i*64,4,4,6);
        if(!texture)result=1;if(i<8)first[i]=texture;
    }
    for(u32 i=0;i<8 && !result;i++)if(get_or_create_texture(renderer,cpu,0x80010000u+i*64,4,4,6)!=first[i])result=1;
    for(u32 i=512;i<520 && !result;i++)if(!get_or_create_texture(renderer,cpu,0x80010000u+i*64,4,4,6))result=1;
    for(u32 i=0;i<8 && !result;i++)if(get_or_create_texture(renderer,cpu,0x80010000u+i*64,4,4,6)!=first[i])result=1;
    u64 uploads=s_texture_uploads;s_texture_epoch++;
    if(get_or_create_texture(renderer,cpu,0x80010000u,4,4,6)!=first[0] || uploads!=s_texture_uploads)result=1;
    cpu->ram[0x10001]=213;s_texture_epoch++;
    if(get_or_create_texture(renderer,cpu,0x80010000u,4,4,6)!=first[0] || s_texture_uploads!=uploads+1)result=1;
    SDL_Texture* previous=SDL_GetRenderTarget(renderer),*target=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,4,4);
    if(!target)result=1;
    else{
        SDL_SetRenderTarget(renderer,target);SDL_SetTextureBlendMode(first[0],SDL_BLENDMODE_NONE);SDL_RenderCopy(renderer,first[0],NULL,NULL);
        u8 pixel[4];SDL_Rect at={0,0,1,1};if(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)!=0 || pixel[0]!=213 || pixel[1]!=55 || pixel[2]!=101)result=1;
        SDL_SetRenderTarget(renderer,previous);SDL_DestroyTexture(target);
    }
    for(u32 i=0;i<s_tex_cache_count;i++)if(s_tex_cache[i].sdl_tex)SDL_DestroyTexture(s_tex_cache[i].sdl_tex);
    memset(s_tex_cache,0,sizeof(s_tex_cache));memset(s_tex_buckets,0,sizeof(s_tex_buckets));s_tex_cache_count=0;s_tex_serial=0;
    if(gx_gl_available(renderer) && !result){
        u32 bp_before[256];u8 destination_before[2048];memcpy(bp_before,s_bp,sizeof(s_bp));memcpy(destination_before,cpu->ram+0x20000,sizeof(destination_before));
        SDL_Texture* before_target=SDL_GetRenderTarget(renderer);SDL_BlendMode before_blend;SDL_GetRenderDrawBlendMode(renderer,&before_blend);
        u8 cr,cg,cb,ca;SDL_GetRenderDrawColor(renderer,&cr,&cg,&cb,&ca);
        if(!flush_efb(cpu))result=1;
        else{
            SDL_SetRenderTarget(renderer,s_efb);SDL_Rect source={8,12,8,8};SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_NONE);SDL_SetRenderDrawColor(renderer,200,100,50,255);SDL_RenderFillRect(renderer,&source);
            s_bp[0x49]=8u|(12u<<10);s_bp[0x4A]=7u|(7u<<10);s_bp[0x4B]=0x20000u>>5;s_bp[0x4D]=1;
            GXGLStats before,after;gx_gl_get_stats(&before);u64 old_uploads=s_texture_uploads;
            if(!copy_efb_texture(cpu,0))result=1;
            SDL_Texture* shadow=get_or_create_texture(renderer,cpu,0x80020000u,8,8,0);gx_gl_get_stats(&after);
            if(!shadow || after.vram_copies!=before.vram_copies+1 || s_texture_uploads!=old_uploads)result=1;
            for(u32 i=0;i<32;i++)if(cpu->ram[0x20000+i]!=0xCC)result=1;
            SDL_Texture* sample=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,8,8);
            if(!sample)result=1;
            else if(shadow){SDL_SetRenderTarget(renderer,sample);SDL_SetTextureBlendMode(shadow,SDL_BLENDMODE_NONE);SDL_RenderCopy(renderer,shadow,NULL,NULL);
                u8 pixel[4];SDL_Rect at={0,0,1,1};if(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)!=0 || pixel[0]!=204 || pixel[1]!=204 || pixel[2]!=204 || pixel[3]!=204)result=1;}
            if(!result){
                source.w=source.h=64;SDL_SetRenderTarget(renderer,s_efb);SDL_SetRenderDrawColor(renderer,200,100,50,255);SDL_RenderFillRect(renderer,&source);
                s_bp[0x4A]=63u|(63u<<10);s_bp[0x4D]=8;memset(cpu->ram+0x20000,0x5A,2048);
                u64 reads=s_texture_readbacks,fast_copies=s_vram_only_copies,resolves=s_vram_materializations;
                if(!gx_pipe_set_vram_only(cpu,true) || !copy_efb_texture(cpu,0))result=1;
                for(u32 i=0;i<2048;i++)if(cpu->ram[0x20000+i]!=0x5A)result=1;
                shadow=get_or_create_texture(renderer,cpu,0x80020000u,64,64,0);
                if(!shadow || s_texture_readbacks!=reads || s_vram_only_copies!=fast_copies+1 || s_vram_pending!=1)result=1;
                if(shadow){SDL_SetRenderTarget(renderer,sample);SDL_SetTextureBlendMode(shadow,SDL_BLENDMODE_NONE);SDL_RenderCopy(renderer,shadow,NULL,NULL);
                    u8 pixel[4];SDL_Rect at={0,0,1,1};if(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4)!=0 || pixel[0]!=204 || pixel[3]!=204)result=1;}
                if(!gx_pipe_set_vram_only(cpu,false) || s_vram_pending || s_vram_materializations!=resolves+1)result=1;
                for(u32 i=0;i<2048;i++)if(cpu->ram[0x20000+i]!=0xCC)result=1;
                printf("[GX VRAM-only] I4 64x64: no readback/RAM write, GPU sample, reference-mode materialization result=%d\n",result);
            }
            SDL_SetRenderTarget(renderer,s_efb);SDL_SetRenderDrawColor(renderer,0,0,0,255);SDL_RenderFillRect(renderer,&source);SDL_SetRenderTarget(renderer,before_target);if(sample)SDL_DestroyTexture(sample);
        }
        SDL_SetRenderDrawBlendMode(renderer,before_blend);SDL_SetRenderDrawColor(renderer,cr,cg,cb,ca);memcpy(s_bp,bp_before,sizeof(s_bp));memcpy(cpu->ram+0x20000,destination_before,sizeof(destination_before));
        for(u32 i=0;i<s_tex_cache_count;i++)if(s_tex_cache[i].sdl_tex)SDL_DestroyTexture(s_tex_cache[i].sdl_tex);
        memset(s_tex_cache,0,sizeof(s_tex_cache));memset(s_tex_buckets,0,sizeof(s_tex_buckets));s_tex_cache_count=0;s_tex_serial=0;
    }
    memcpy(cpu->ram+0x10000,saved,520u*64u);free(saved);s_palette_offset=palette_offset;s_palette_format=palette_format;
    printf("[GX texture cache] 520 keys/collisions, LRU live references, content coherence and in-place pixel update result=%d\n",result);return result;
}
int gx_pipe_xfb_contracts(CPUState* cpu,SDL_Renderer* renderer) {
    if(!gx_gl_available(renderer))return 0;
    u32 saved_bp[256];memcpy(saved_bp,s_bp,sizeof(s_bp));u8 saved[512];memcpy(saved,cpu->ram+0x30000,512);
    SDL_Texture* previous=SDL_GetRenderTarget(renderer);int result=0;
    if(!flush_efb(cpu))return 1;
    SDL_Rect source={0,0,16,8};SDL_BlendMode old_blend;SDL_GetRenderDrawBlendMode(renderer,&old_blend);
    u8 red,green,blue,alpha;SDL_GetRenderDrawColor(renderer,&red,&green,&blue,&alpha);
    SDL_Texture* backup=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,16,8);
    if(!backup)return 1;
    SDL_SetRenderTarget(renderer,backup);SDL_RenderCopy(renderer,s_efb,&source,NULL);SDL_RenderFlush(renderer);
    SDL_SetRenderTarget(renderer,s_efb);SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_NONE);
    memset(cpu->ram+0x30000,0x5A,512);gx_pipe_set_xfb_vram(cpu,true);
    s_bp[0x49]=0;s_bp[0x4A]=15u|(7u<<10);s_bp[0x4B]=0x30000u>>5;s_bp[0x4D]=1;s_bp[0x4E]=256;
    SDL_SetRenderDrawColor(renderer,255,0,0,255);SDL_RenderFillRect(renderer,&source);
    if(!copy_efb(cpu,0))result=1;
    s_bp[0x4B]=0x30100u>>5;SDL_SetRenderTarget(renderer,s_efb);SDL_SetRenderDrawColor(renderer,0,0,255,255);SDL_RenderFillRect(renderer,&source);
    if(!copy_efb(cpu,0))result=1;
    for(u32 i=0;i<512;i++)if(cpu->ram[0x30000+i]!=0x5A)result=1;
    SDL_Texture* sample=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,16,8);
    if(!sample)result=1;
    else for(u32 i=0;i<2;i++){
        SDL_SetRenderTarget(renderer,sample);if(!gx_pipe_present_xfb(renderer,0x80030000u+i*256,NULL))result=1;
        u8 pixel[4];SDL_Rect at={0,0,1,1};
        if(SDL_RenderReadPixels(renderer,&at,SDL_PIXELFORMAT_RGBA32,pixel,4) || pixel[i ? 2:0]!=255 || pixel[i ? 0:2]!=0)result=1;
    }
    if(!gx_pipe_set_xfb_vram(cpu,false))result=1;
    if(cpu->ram[0x30000]!=82 || cpu->ram[0x30001]!=90 || cpu->ram[0x30003]!=240 || cpu->ram[0x30100]!=41)result=1;
    SDL_SetRenderTarget(renderer,s_efb);SDL_SetTextureBlendMode(backup,SDL_BLENDMODE_NONE);SDL_RenderCopy(renderer,backup,NULL,&source);SDL_RenderFlush(renderer);
    SDL_SetRenderTarget(renderer,previous);SDL_DestroyTexture(backup);if(sample)SDL_DestroyTexture(sample);
    SDL_SetRenderDrawBlendMode(renderer,old_blend);SDL_SetRenderDrawColor(renderer,red,green,blue,alpha);
    memcpy(cpu->ram+0x30000,saved,512);memcpy(s_bp,saved_bp,sizeof(s_bp));
    printf("[XFB VRAM] two independent VI allocations, no guest write, later YUY2 materialization result=%d\n",result);return result;
}

int gx_pipe_attribute_contracts(CPUState* cpu) {
    if(!s_fifo_buf || cpu->ram_size<0x2000u)return 1;
    u32 saved_cp[256],saved_xf[0x1058],ram_size=cpu->ram_size;u8 saved_ram[1536],low[512],high[512];
    memcpy(saved_cp,s_cp,sizeof(s_cp));memcpy(saved_xf,s_xf,sizeof(s_xf));memcpy(saved_ram,cpu->ram+0x1000,sizeof(saved_ram));
    memcpy(low,s_fifo_buf,sizeof(low));memcpy(high,s_fifo_buf+FIFO_BUFFER_SIZE-sizeof(high),sizeof(high));
    bool projection=s_projection_loaded,lighting=s_lighting_loaded,direct=s_direct_attributes;
    int rounding=fegetround(),result=0;u32 compared=0;
#if defined(_M_X64) || defined(__x86_64__)
    u32 csr=_mm_getcsr();
#endif
    const int modes[]={FE_TONEAREST,FE_DOWNWARD,FE_UPWARD,FE_TOWARDZERO};
    memset(s_cp,0,sizeof(s_cp));memset(s_xf,0,sizeof(s_xf));cpu->ram_size=0x1600;
    s_projection_loaded=s_lighting_loaded=false;
    for(u32 i=0;i<sizeof(saved_ram);i++)cpu->ram[0x1000+i]=(u8)(i*37u+11u);
    for(u32 rm=0;rm<4 && !result;rm++)for(u32 mode=1;mode<=3 && !result;mode++)
    for(u32 fmt=0;fmt<8 && !result;fmt++)for(u32 fraction=0;fraction<32 && !result;fraction++)
    for(u32 nbt=0;nbt<2 && !result;nbt++)for(u32 placement=0;placement<4 && !result;placement++) {
        VertexLayout layout={0};layout.normal_indices=nbt ? 3:1;
        u32 cursor=placement&1 ? FIFO_BUFFER_SIZE-1u-fraction:32u,used=0;
        for(u32 j=0;j<12;j++) {
            layout.mode[j]=(placement==3 && (j&1)) ? 0:(u8)mode;layout.format[j]=(u8)fmt;layout.fraction[j]=(u8)fraction;
            layout.components[j]=(u8)(j==1 ? (nbt ? 9:3):j==0 ? 2+(fraction&1):1+(fraction&1));
            u32 size=j==2 || j==3 ? color_size(fmt):layout.components[j]*scalar_size(fmt);
            s_cp[0xA0+j]=placement==2 ? cpu->ram_size-size:placement==3 ? cpu->ram_size-1:0x1000+j*96;
            s_cp[0xB0+j]=32;
            if(!layout.mode[j])continue;
            if(mode==1)for(u32 k=0;k<size;k++)s_fifo_buf[(cursor+used++)%FIFO_BUFFER_SIZE]=(u8)(j*31u+k*19u+fraction);
            else for(u32 n=0;n<(j==1 ? (u32)layout.normal_indices:1u);n++) {
                if(mode==3)s_fifo_buf[(cursor+used++)%FIFO_BUFFER_SIZE]=0;
                s_fifo_buf[(cursor+used++)%FIFO_BUFFER_SIZE]=(u8)(placement==2 ? 0:2+n);
            }
        }
        layout.stride=used;QueuedVertex expected,actual;fesetround(modes[rm]);
#if defined(_M_X64) || defined(__x86_64__)
        u32 control=_mm_getcsr();
#endif
        s_direct_attributes=false;decode_vertex(cpu,&layout,cursor,&expected,fraction&7u,false,NULL);
#if defined(_M_X64) || defined(__x86_64__)
        u32 reference_flags=_mm_getcsr();_mm_setcsr(control);
#endif
        s_direct_attributes=true;decode_vertex(cpu,&layout,cursor,&actual,fraction&7u,false,NULL);
        if(memcmp(&actual,&expected,sizeof(actual)))result=1;
#if defined(_M_X64) || defined(__x86_64__)
        if(_mm_getcsr()!=reference_flags)result=1;
#endif
        compared++;
    }
    cpu->ram_size=ram_size;memcpy(cpu->ram+0x1000,saved_ram,sizeof(saved_ram));memcpy(s_cp,saved_cp,sizeof(s_cp));memcpy(s_xf,saved_xf,sizeof(s_xf));
    memcpy(s_fifo_buf,low,sizeof(low));memcpy(s_fifo_buf+FIFO_BUFFER_SIZE-sizeof(high),high,sizeof(high));
    s_projection_loaded=projection;s_lighting_loaded=lighting;s_direct_attributes=direct;fesetround(rounding);
#if defined(_M_X64) || defined(__x86_64__)
    _mm_setcsr(csr);
#endif
    printf("[GX attribute spans] %u legacy/direct comparisons: formats, fractions, NBT, bounds, FIFO wrap, rounding and FP flags result=%d\n",compared,result);return result;
}
int gx_pipe_worker_contracts(CPUState* cpu) {
    bool saved_decode_cache=s_decode_cache_enabled;s_decode_cache_enabled=false;
    if(!s_fifo_buf || cpu->ram_size<0x2000u)return 1;
    ppc_mark_host_write(cpu->ram+0x1000,1536);
    u32 saved_cp[256],saved_xf[0x1058];u8 saved_ram[1536],saved_fifo[16391];
    memcpy(saved_cp,s_cp,sizeof(s_cp));memcpy(saved_xf,s_xf,sizeof(s_xf));memcpy(saved_ram,cpu->ram+0x1000,sizeof(saved_ram));
    u32 start=FIFO_BUFFER_SIZE-7u;
    for(u32 i=0;i<sizeof(saved_fifo);i++)saved_fifo[i]=s_fifo_buf[(start+i)%FIFO_BUFFER_SIZE];
    bool projection=s_projection_loaded,lighting=s_lighting_loaded,parallel=s_parallel_vertices_enabled,coalesced=s_coalesced_enabled;
    int rounding=fegetround(),result=0;u32 compared=0;
#if defined(_M_X64) || defined(__x86_64__)
    u32 csr=_mm_getcsr();
#endif
    QueuedVertex* expected=malloc(8192u*sizeof(*expected));QueuedVertex* actual=malloc(8192u*sizeof(*actual));
    GXGLRawVertex* expected_raw=malloc(8192u*sizeof(*expected_raw));GXGLRawVertex* actual_raw=malloc(8192u*sizeof(*actual_raw));
    if(!expected || !actual || !expected_raw || !actual_raw){result=1;goto restore;}
    memset(s_cp,0,sizeof(s_cp));memset(s_xf,0,sizeof(s_xf));s_cp[0xA0]=0x1000;s_cp[0xB0]=6;
    s_projection_loaded=s_lighting_loaded=false;s_parallel_vertices_enabled=true;s_matrix_valid=0;
    VertexLayout layout={0};layout.stride=2;layout.mode[0]=3;layout.components[0]=3;layout.format[0]=3;layout.fraction[0]=8;layout.normal_indices=1;
    for(u32 i=0;i<256u*3u;i++)mem_write16(cpu,0x80001000u+i*2u,(u16)(i*97u));
    const u32 counts[]={1024,4096,8192};const int modes[]={FE_TONEAREST,FE_DOWNWARD,FE_UPWARD,FE_TOWARDZERO};
    for(u32 rm=0;rm<4 && !result;rm++)for(u32 ci=0;ci<3 && !result;ci++)for(u32 wrap=0;wrap<2 && !result;wrap++) {
        u32 count=counts[ci],cursor=wrap ? start:0;fesetround(modes[rm]);
        for(u32 i=0;i<count;i++){u32 index=(i*17u)%256;s_fifo_buf[(cursor+i*2u)%FIFO_BUFFER_SIZE]=(u8)(index>>8);s_fifo_buf[(cursor+i*2u+1)%FIFO_BUFFER_SIZE]=(u8)index;}
        prepare_vertex_constants(&layout,cursor,count);
        for(u32 gpu=0;gpu<2 && !result;gpu++){
            for(u32 i=0;i<count;i++)decode_vertex(cpu,&layout,(cursor+i*2u)%FIFO_BUFFER_SIZE,expected+i,0,false,gpu ? expected_raw+i:NULL);
            for(u32 mode=0;mode<2;mode++) {
                s_coalesced_enabled=mode!=0;++s_vertex_cache_epoch;decode_vertices(cpu,&layout,cursor,actual,count,0,false,gpu ? actual_raw:NULL);
                if(gpu ? memcmp(expected_raw,actual_raw,count*sizeof(*actual_raw)) : memcmp(expected,actual,count*sizeof(*actual)))result=1;compared+=count;
            }
            if(gpu && !result){
                s_decode_cache_enabled=true;
                for(u32 change=0;change<3;change++){
                    if(change==1){ppc_mark_host_write(cpu->ram+0x1000,1);cpu->ram[0x1000]^=1;}
                    if(change==2)s_fifo_buf[(cursor+1)%FIFO_BUFFER_SIZE]^=1;
                    for(u32 i=0;i<count;i++)decode_vertex(cpu,&layout,(cursor+i*2u)%FIFO_BUFFER_SIZE,expected+i,0,false,expected_raw+i);
                    ++s_vertex_cache_epoch;decode_vertices(cpu,&layout,cursor,actual,count,0,false,actual_raw);
                    if(memcmp(expected_raw,actual_raw,count*sizeof(*actual_raw)))result=1;
                    u64 hits=s_raw_cache_hits;++s_vertex_cache_epoch;decode_vertices(cpu,&layout,cursor,actual,count,0,false,actual_raw);
                    if(s_raw_cache_hits!=hits+1 || memcmp(expected_raw,actual_raw,count*sizeof(*actual_raw)))result=1;
                    // Unused CP arrays/VATs do not invalidate raw attributes.
                    s_cp[0xA1]^=0x40u;s_cp[0x77]^=0x1234u;hits=s_raw_cache_hits;
                    ++s_vertex_cache_epoch;decode_vertices(cpu,&layout,cursor,actual,count,0,false,actual_raw);
                    if(s_raw_cache_hits!=hits+1 || memcmp(expected_raw,actual_raw,count*sizeof(*actual_raw)))result=1;
                    s_cp[0xA1]^=0x40u;s_cp[0x77]^=0x1234u;
                }
                ppc_mark_host_write(cpu->ram+0x1000,1);cpu->ram[0x1000]^=1;s_fifo_buf[(cursor+1)%FIFO_BUFFER_SIZE]^=1;s_decode_cache_enabled=false;
            }
        }
    }
restore:
    free(expected);free(actual);free(expected_raw);free(actual_raw);memcpy(s_cp,saved_cp,sizeof(s_cp));memcpy(s_xf,saved_xf,sizeof(s_xf));memcpy(cpu->ram+0x1000,saved_ram,sizeof(saved_ram));
    for(u32 i=0;i<sizeof(saved_fifo);i++)s_fifo_buf[(start+i)%FIFO_BUFFER_SIZE]=saved_fifo[i];
    s_decode_cache_enabled=saved_decode_cache;
    s_projection_loaded=projection;s_lighting_loaded=lighting;s_parallel_vertices_enabled=parallel;s_coalesced_enabled=coalesced;s_matrix_valid=0;fesetround(rounding);
#if defined(_M_X64) || defined(__x86_64__)
    _mm_setcsr(csr);
#endif
    printf("[GX worker completion] %u vertices, original/coalesced vs serial CPU/raw, FIFO wrap, four rounding modes result=%d\n",compared,result);return result;
}

int gx_pipe_gpu_xf_contracts(CPUState* cpu,SDL_Renderer* renderer) {
    u32 saved_cp[256],saved_xf[0x1058];u8 fifo[1152];u32 start=FIFO_BUFFER_SIZE-13;
    memcpy(saved_cp,s_cp,sizeof(s_cp));memcpy(saved_xf,s_xf,sizeof(s_xf));
    for(u32 i=0;i<sizeof(fifo);i++)fifo[i]=s_fifo_buf[(start+i)%FIFO_BUFFER_SIZE];
    bool projection=s_projection_loaded,lighting=s_lighting_loaded;int rounding=fegetround(),result=0;
#if defined(_M_X64) || defined(__x86_64__)
    u32 csr=_mm_getcsr();
#endif
    fesetround(FE_TONEAREST);GXGLRawVertex raw[32];GXGLVertex expected[32];VertexLayout layout={0};
    layout.stride=36;layout.normal_indices=1;layout.mode[0]=layout.mode[1]=layout.mode[2]=layout.mode[4]=1;
    layout.format[0]=layout.format[1]=layout.format[4]=4;layout.format[2]=5;layout.components[0]=layout.components[1]=3;layout.components[4]=2;
    for(u32 test=0;test<12 && !result;test++){
        memset(s_cp,0,sizeof(s_cp));memset(s_xf,0,sizeof(s_xf));s_matrix_valid=0;
        u32 matrix=test==8 ? 63u:0u,texmatrix=test==1 ? 60u:matrix;
        s_cp[0x30]=matrix;for(u32 j=0;j<4;j++){s_cp[0x30]|=texmatrix<<(6+j*6);s_cp[0x40]|=texmatrix<<(j*6);}
        const u32 locations[]={matrix*4,matrix*4+5,matrix*4+10,0x400+(matrix&31u)*3,0x400+(matrix&31u)*3+4,0x400+(matrix&31u)*3+8,0x500,0x505,0x50A};
        float one=1;for(u32 j=0;j<sizeof(locations)/sizeof(locations[0]);j++)memcpy(s_xf+locations[j],&one,4);
        const u32 at[]={0x101A,0x101B,0x101C,0x101D,0x101E,0x101F,0x1020,0x1022,0x1024,0x1025};
        const float values[]={320,264,0,662,606,8388607.5f,1,1,0,-0.5f};
        for(u32 j=0;j<sizeof(at)/sizeof(at[0]);j++)memcpy(s_xf+at[j],values+j,4);
        s_xf[0x100A]=0x10203040u;s_xf[0x100C]=0xC0D0E0FFu;
        s_xf[0x100E]=1u|2u|4u|(2u<<7)|(test>=7 ? 3u<<9:0u);s_xf[0x1010]=2u|4u|(1u<<7);
        s_xf[0x603]=0x80C040FFu;float light[12]={1,0.125f,0.25f,1,0.125f,0.0625f,2,-3,5,0,0,-1};memcpy(s_xf+0x604,light,sizeof(light));
        s_xf[0x103F]=test ? 8:0;s_xf[0x1012]=test>=4 && test<=7 ? 1:0;
        for(u32 j=0;j<8;j++){
            u32 row=test==2 ? 0:test==3 ? 1:5+j;
            s_xf[0x1040+j]=(row<<7)|4u|(test&1 ? 2u:0u)|(test==11 ? 1u<<4:0u);
            s_xf[0x1050+j]=(test&1) ? 256u:0u;
        }
        s_projection_loaded=true;s_lighting_loaded=test>=6;
        for(u32 i=0;i<32;i++){
            float v[8]={((int)(i%7)-3)*0.25f,((int)(i%5)-2)*0.25f,test==9 ? 0:test==10 ? 1:-1.5f-i*0.03125f,
                (i%5)*0.125f,0.25f,0.875f,((int)(i%9)-4)*0.25f,((int)(i%13)-6)*0.125f};
            u8 packet[36];for(u32 j=0;j<6;j++){u32 bits;memcpy(&bits,v+j,4);for(u32 b=0;b<4;b++)packet[j*4+b]=(u8)(bits>>(24-b*8));}
            packet[24]=(u8)(i*7);packet[25]=(u8)(255-i*3);packet[26]=(u8)(64+i*2);packet[27]=(u8)(255-i);
            for(u32 j=0;j<2;j++){u32 bits;memcpy(&bits,v+6+j,4);for(u32 b=0;b<4;b++)packet[28+j*4+b]=(u8)(bits>>(24-b*8));}
            for(u32 j=0;j<sizeof(packet);j++)s_fifo_buf[(start+i*36+j)%FIFO_BUFFER_SIZE]=packet[j];
        }
        prepare_vertex_constants(&layout,start,32);
        for(u32 i=0;i<32;i++){QueuedVertex reference,unused;decode_vertex(cpu,&layout,(start+i*36)%FIFO_BUFFER_SIZE,&reference,0,false,NULL);expected[i]=reference.native;
            decode_vertex(cpu,&layout,(start+i*36)%FIFO_BUFFER_SIZE,&unused,0,false,raw+i);}
        GXGLTransform transform;memcpy(transform.words,s_xf,sizeof(s_xf));transform.projection=true;transform.lighting=s_lighting_loaded;
        result=gx_gl_validate_xf(renderer,&transform,raw,expected,sizeof(expected[0]),32);
    }
    memcpy(s_cp,saved_cp,sizeof(s_cp));memcpy(s_xf,saved_xf,sizeof(s_xf));s_matrix_valid=0;
    for(u32 i=0;i<sizeof(fifo);i++)s_fifo_buf[(start+i)%FIFO_BUFFER_SIZE]=fifo[i];
    s_projection_loaded=projection;s_lighting_loaded=lighting;fesetround(rounding);
#if defined(_M_X64) || defined(__x86_64__)
    _mm_setcsr(csr);
#endif
    printf("[GX GPU XF] projection, matrices, diffuse/spot lighting, texgen/post-normalization, FIFO wrap result=%d\n",result);return result;
}
int gx_pipe_transform_contracts(void) {
    u32 saved[0x1058];memcpy(saved,s_xf,sizeof(saved));
    bool lighting=s_lighting_loaded,required=s_normal_lighting_required,scalar=s_scalar_transforms;
    int rounding=fegetround(),result=0;u32 seed=0x587231u,comparisons=0;
#if defined(_M_X64) || defined(__x86_64__)
    u32 csr=_mm_getcsr();
#endif
    const int modes[4]={FE_TONEAREST,FE_DOWNWARD,FE_UPWARD,FE_TOWARDZERO};
    for(u32 mode=0;mode<4 && !result;mode++)for(u32 flush=0;flush<2 && !result;flush++) {
        fesetround(modes[mode]);
#if defined(_M_X64) || defined(__x86_64__)
        _mm_setcsr((_mm_getcsr()&~0x8040u)|(flush ? 0x8040u:0));
#endif
        for(u32 i=0;i<0x608;i++) {
            seed=seed*1664525u+1013904223u;
            float f=((int)(seed>>16)-32768)/4096.0f;memcpy(&s_xf[i],&f,4);
        }
        s_matrix_valid=0;s_scalar_transforms=false;
        for(u32 matrix=0;matrix<64 && !result;matrix++) {
            prepare_matrix_index(matrix);
            for(u32 sample=0;sample<24 && !result;sample++) {
                float input[3],expected[3],actual[3];
                for(u32 j=0;j<3;j++) {
                    seed=seed*1664525u+1013904223u;
                    input[j]=((int)(seed>>16)-32768)/1024.0f;
                    if(sample<4){u32 bits=(sample&1 ? 0x80000000u:0)|(sample>=2 ? j+1:0);memcpy(input+j,&bits,4);}
                }
                for(u32 normal=0;normal<2;normal++) {
                    transform_scalar(matrix,input,expected,normal!=0);
                    transform_prepared(matrix,input,actual,normal!=0);
                    if(memcmp(expected,actual,sizeof(actual)))result=1;
                    comparisons++;
                }
            }
            float input[3]={1,2,3},expected[3],actual[3];
            write_xf_word(matrix*4,0x3F800000u);write_xf_word(0x400+(matrix&31u)*3,0x40000000u);
            if(s_matrix_valid)result=1;
            prepare_matrix_index(matrix);
            for(u32 normal=0;normal<2;normal++) {
                transform_scalar(matrix,input,expected,normal!=0);transform_prepared(matrix,input,actual,normal!=0);
                if(memcmp(expected,actual,sizeof(actual)))result=1;
            }
        }
    }
    // With no active diffuse lights, normal normalization cannot affect RGBA.
    s_lighting_loaded=true;memset(s_xf,0,sizeof(s_xf));s_xf[0x100C]=0xB7D3E97Fu;s_xf[0x100A]=0x324F6587u;
    const u32 controls[]={0,1,2,3,0x46,0x606,0x626};
    float position[3]={1,2,3},normal[3]={0.25f,0.5f,0.75f};
    for(u32 i=0;i<sizeof(controls)/sizeof(controls[0]);i++) {
        s_xf[0x100E]=controls[i];s_xf[0x1010]=controls[i];s_normal_lighting_required=lighting_needs_normal();
        QueuedVertex a={0},b={0};a.r=123;a.g=45;a.b=67;a.a=89;b=a;
        s_scalar_transforms=true;shade_vertex(&a,position,normal,0);
        s_scalar_transforms=false;shade_vertex(&b,position,normal,0);
        if(memcmp(&a,&b,sizeof(a)))result=1;
    }
    memcpy(s_xf,saved,sizeof(saved));s_matrix_valid=0;s_lighting_loaded=lighting;s_normal_lighting_required=required;s_scalar_transforms=scalar;
    fesetround(rounding);
#if defined(_M_X64) || defined(__x86_64__)
    _mm_setcsr(csr);
#endif
    printf("[GX XF] %u transform comparisons, cache invalidation and lighting result=%d\n",comparisons,result);return result;
}

int gx_pipe_validate_decode(const char* path,bool scalar,u32 repetitions) {
    FILE* file=fopen(path,"rb");if(!file)return 1;
    char magic[8];u32 h[10];VertexLayout layout;CPUState cpu={0};int result=1;
    SDL_Window* gpu_window=NULL;SDL_Renderer* gpu_renderer=NULL;GXGLRawVertex* gpu_raw=NULL;GXGLVertex* gpu_expected=NULL;
    bool validate_gpu=getenv("GX_VALIDATE_GPU_XF")!=NULL;
    if(fread(magic,1,8,file)!=8 || memcmp(magic,"GXVD0001",8) || fread(h,sizeof(h),1,file)!=1 ||
       h[0]!=sizeof(QueuedVertex) || !h[1] || h[1]>16384 || h[2]>=FIFO_BUFFER_SIZE || h[3]>=8 ||
       h[6]!=GC_MAIN_RAM_SIZE || h[7]!=FIFO_BUFFER_SIZE || fread(&layout,sizeof(layout),1,file)!=1)goto done;
    if(!layout.stride || layout.stride>64 || layout.matrix_bytes>9 || (layout.normal_indices!=1 && layout.normal_indices!=3))goto done;
    for(u32 i=0;i<12;i++)if(layout.mode[i]>3 || layout.fraction[i]>31 || layout.components[i]>(i==1 ? 9:3) ||
        (i!=2 && i!=3 && layout.components[i]*scalar_size(layout.format[i])>36))goto done;
    if(!cpu_init(&cpu) || !gx_pipe_init(&cpu))goto done;
    if(fread(s_cp,sizeof(s_cp),1,file)!=1 || fread(s_xf,sizeof(s_xf),1,file)!=1 ||
       fread(s_fifo_buf,1,FIFO_BUFFER_SIZE,file)!=FIFO_BUFFER_SIZE || fread(cpu.ram,1,cpu.ram_size,file)!=cpu.ram_size)goto done;
    s_projection_loaded=h[8]!=0;s_lighting_loaded=h[9]!=0;s_scalar_transforms=scalar;s_matrix_valid=0;
    fesetround((int)h[4]);
#if defined(_M_X64) || defined(__x86_64__)
    _mm_setcsr(h[5]);
#endif
    prepare_vertex_constants(&layout,h[2],h[1]);
    if(validate_gpu){
        SDL_SetMainReady();if(SDL_Init(SDL_INIT_VIDEO)!=0)goto done;SDL_SetHint(SDL_HINT_RENDER_DRIVER,"opengl");
        gpu_window=SDL_CreateWindow("GPU XF capture validation",0,0,640,528,SDL_WINDOW_HIDDEN);
        gpu_renderer=gpu_window ? SDL_CreateRenderer(gpu_window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE):NULL;
        gpu_raw=malloc((size_t)h[1]*sizeof(*gpu_raw));gpu_expected=malloc((size_t)h[1]*sizeof(*gpu_expected));
        if(!gpu_renderer || !gpu_raw || !gpu_expected)goto done;
    }
    result=0;
    for(u32 i=0;i<h[1];i++) {
        QueuedVertex expected,actual;
        if(fread(&expected,sizeof(expected),1,file)!=1){result=1;break;}
        decode_vertex(&cpu,&layout,(h[2]+i*layout.stride)%FIFO_BUFFER_SIZE,&actual,h[3],false,NULL);
        if(validate_gpu){QueuedVertex unused;gpu_expected[i]=actual.native;decode_vertex(&cpu,&layout,(h[2]+i*layout.stride)%FIFO_BUFFER_SIZE,&unused,h[3],false,gpu_raw+i);}
        if(memcmp(&expected,&actual,sizeof(actual))) {
            const u8* a=(const u8*)&actual;const u8* e=(const u8*)&expected;
            for(u32 j=0;j<sizeof(actual);j++)if(a[j]!=e[j]){fprintf(stderr,"[GX decode] vertex=%u byte=%u expected=%02X actual=%02X\n",i,j,e[j],a[j]);break;}
            result=1;break;
        }
    }
    if(!result && validate_gpu){GXGLTransform transform;memcpy(transform.words,s_xf,sizeof(s_xf));transform.projection=s_projection_loaded;transform.lighting=s_lighting_loaded;
        result=gx_gl_validate_xf(gpu_renderer,&transform,gpu_raw,gpu_expected,sizeof(*gpu_expected),h[1]);
        if(!result && getenv("GX_VALIDATE_FRAME")){gx_pipe_set_renderer(gpu_renderer);if(!frame_validate_capture(&cpu,gpu_window,&layout,h[2],h[1],&transform,gpu_raw,gpu_expected))result=1;}}
    if(!result) {
        printf("[GX decode] %u captured vertices byte-identical; scalar=%u\n",h[1],scalar);
        if(!repetitions)goto done;
        QueuedVertex* output=malloc(h[1]*sizeof(*output));
        if(!output){result=1;goto done;}
        if(repetitions>10000)repetitions=10000;
        u64 start=SDL_GetPerformanceCounter();
        for(u32 r=0;r<repetitions;r++) {
            prepare_vertex_constants(&layout,h[2],h[1]);
            for(u32 i=0;i<h[1];i++)decode_vertex(&cpu,&layout,(h[2]+i*layout.stride)%FIFO_BUFFER_SIZE,output+i,h[3],false,NULL);
        }
        u64 ticks=SDL_GetPerformanceCounter()-start;
        u32 checksum=2166136261u;const u8* bytes=(const u8*)output;
        for(u32 i=0;i<h[1]*sizeof(*output);i++)checksum=(checksum^bytes[i])*16777619u;
        printf("[GX decode benchmark] vertices=%u repeats=%u time_ms=%.3f checksum=%08X\n",h[1],repetitions,1000.0*(double)ticks/(double)SDL_GetPerformanceFrequency(),checksum);
        free(output);
    }
done:
    fclose(file);cpu_free(&cpu);gx_pipe_shutdown();free(gpu_raw);free(gpu_expected);
    if(gpu_renderer)SDL_DestroyRenderer(gpu_renderer);if(gpu_window)SDL_DestroyWindow(gpu_window);if(validate_gpu)SDL_Quit();return result;
}

#include "gx_frame_backend.inc"
