#ifndef GX_FRAME_H
#define GX_FRAME_H
#include "gx_gl.h"
enum {GX_FRAME_ARENAS=3};
typedef struct {
    GXGLStats gl;
    u64 render,copy,texture_copy,uploads,texture_hits,hash_bytes,readbacks;
    u64 vram_copies,vram_resolves,xfb_copies,xfb_resolves,display_copies,merged;
    u32 vram_pending;
    u64 packets,bytes,worker_ticks,wait_ticks;
    u64 draw_ticks,copy_ticks,swap_ticks;
    u64 decode_ticks,raw_draws,raw_vertices,snapshot_bytes,ram_copies;
    u64 barrier_calls,barrier_waits,barrier_ticks,pressure_waits,pressure_ticks,pe_submits;
    u64 frames_queued,frames_presented,frame_limit_ticks;
    u64 unique_bytes,reused_bytes,compare_ticks;
} GXFrameStats;
typedef bool (*GXFrameExecute)(const u8* bytes,u32 size,void* user);
typedef void (*GXFrameReport)(GXFrameStats* result);
bool gx_frame_start(GXFrameExecute execute,GXFrameReport report,void* user);
bool gx_frame_active(void);
bool gx_frame_consuming(void);
bool gx_frame_pump(bool wait);
void gx_frame_wake(void);
void* gx_frame_alloc(u32 bytes);
bool gx_frame_submit(bool wait);
bool gx_frame_submit_pe(void);
void gx_frame_fail(void);
void gx_frame_frame_queued(void);
void gx_frame_presented(void);
bool gx_frame_begin_cpu_frame(void);
bool gx_frame_drain(void);
bool gx_frame_stop(void);
/* Producer-only views; offsets survive builder reallocations. Never share a
 * snapshot across an arena generation that the consumer may recycle. */
u64 gx_frame_builder(u8** base,u32* used);
bool gx_frame_trim(u32 unused_tail);
void gx_frame_stats(GXFrameStats* result);
#endif
