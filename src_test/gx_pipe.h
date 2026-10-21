#ifndef GX_PIPE_H
#define GX_PIPE_H

#include <stdbool.h>
#include "cpu/cpu.h"

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

// Flushes and processes any pending commands in the FIFO
void gx_pipe_process_frame(CPUState* cpu);

// Renders extracted 2D primitives directly to the SDL2 renderer
void gx_pipe_render_to_sdl(struct SDL_Renderer* renderer, CPUState* cpu, int game_x, int game_y, int game_w, int game_h);
void gx_pipe_clear_queued_draws(void);

// Telemetry statistics
u64 gx_pipe_get_total_bytes(void);
u32 gx_pipe_get_draw_calls(void);

void gx_pipe_shutdown(void);

#endif // GX_PIPE_H
