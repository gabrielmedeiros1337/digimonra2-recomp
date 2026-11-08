#ifndef GX_PIPE_H
#define GX_PIPE_H

#include <stdbool.h>
#include <SDL_rect.h>
#include "cpu/cpu.h"

struct SDL_Renderer;
void gx_pipe_set_renderer(struct SDL_Renderer* renderer);
u32 gx_pipe_read_pi(u32 offset);
void gx_pipe_write_pi(u32 offset, u32 value);

// Initializes GX Gather Pipe and Command Processor
bool gx_pipe_init(CPUState* cpu);

// Command Processor (CP) MMIO handlers (0xCC000000 - 0xCC00007F)
u32 gx_pipe_read_cp(CPUState* cpu, u32 reg_offset);
void gx_pipe_write_cp(CPUState* cpu, u32 reg_offset, u32 val);

// Pixel Engine (PE) MMIO handlers (0xCC001000 - 0xCC00103F)
u32 gx_pipe_read_pe(CPUState* cpu, u32 reg_offset);
void gx_pipe_write_pe(CPUState* cpu, u32 reg_offset, u32 val);

// GX Gather Pipe write port (0xCC008000 / 0x0C008000)
void gx_pipe_write_fifo(CPUState* cpu, u32 ea, u64 value, u8 size);
void gx_pipe_write_fifo_bytes(CPUState* cpu,const u8* bytes,u32 size,u32 stores);

// Flushes and processes any pending commands in the FIFO
void gx_pipe_process_frame(CPUState* cpu);

// Renders extracted 2D primitives directly to the SDL2 renderer
void gx_pipe_render_to_sdl(struct SDL_Renderer* renderer, CPUState* cpu, int game_x, int game_y, int game_w, int game_h);
void gx_pipe_clear_queued_draws(void);

void gx_pipe_fifo_diagnostics(u64* stores,u64* lines,u64* deferred,u64* parses);

bool gx_pipe_image_versions(void);
void gx_pipe_set_image_versions(CPUState* cpu,bool enabled);
void gx_pipe_image_diagnostics(u64* output);
bool gx_pipe_async_decode(void);
void gx_pipe_set_async_decode(bool enabled);
void gx_pipe_async_reuse(u64* hits,u64* misses,u64* drains,u64* peak);
void gx_pipe_async_diagnostics(u64* jobs,u64* vertices,u64* worker,u64* wait,u64* snapshot);

// Telemetry statistics
void gx_pipe_get_timing(u64* render,u64* copy);
void gx_pipe_get_costs(u64* vertices,u64* textures);
u64 gx_pipe_get_display_copies(void);
void gx_pipe_get_vertex_cache_stats(u64* hits,u64* misses);
u64 gx_pipe_get_parallel_batches(void);
void gx_pipe_key_details(u64* output);
bool gx_pipe_dirty_tracking(void);
void gx_pipe_set_dirty_tracking(bool enabled);
void gx_pipe_dirty_diagnostics(u64* spans,u64* fallbacks);
void gx_pipe_set_decode_cache(bool enabled);
void gx_pipe_decode_diagnostics(u64* hits,u64* misses,u64* keys,u64* waits,u64* main);
void gx_pipe_set_parallel_vertices(bool enabled);
void gx_pipe_set_coalesced_completion(bool enabled);
bool gx_pipe_coalesced_completion(void);
void gx_pipe_set_direct_attributes(bool enabled);
bool gx_pipe_direct_attributes(void);
void gx_pipe_set_gpu_xf(bool enabled);
bool gx_pipe_gpu_xf(void);
u64 gx_pipe_gpu_xf_batches(void);
u64 gx_pipe_merged_packets(void);
void gx_pipe_set_packed_copy(bool enabled);
u64 gx_pipe_get_texture_uploads(void);
void gx_pipe_texture_diagnostics(u64* hits,u64* hashed,u64* readbacks);
bool gx_pipe_set_vram_only(CPUState* cpu,bool enabled);
bool gx_pipe_vram_only(void);
void gx_pipe_vram_diagnostics(u64* copies,u64* materializations,u32* pending);
bool gx_pipe_set_xfb_vram(CPUState* cpu,bool enabled);
bool gx_pipe_present_xfb(struct SDL_Renderer* renderer,u32 address,const SDL_Rect* dest);
void gx_pipe_xfb_diagnostics(u64* copies,u64* resolves);
u64 gx_pipe_get_total_bytes(void);
u32 gx_pipe_get_draw_calls(void);

int gx_pipe_transform_contracts(void);
int gx_pipe_worker_contracts(CPUState* cpu);
int gx_pipe_xfb_contracts(CPUState* cpu,struct SDL_Renderer* renderer);
int gx_pipe_attribute_contracts(CPUState* cpu);
int gx_pipe_gpu_xf_contracts(CPUState* cpu,struct SDL_Renderer* renderer);
int gx_pipe_texture_contracts(CPUState* cpu,struct SDL_Renderer* renderer);
int gx_pipe_validate_decode(const char* path,bool scalar,u32 repetitions);
int gx_pipe_replay(const char* path,const char* output,bool software);
void gx_pipe_shutdown(void);

#endif // GX_PIPE_H
