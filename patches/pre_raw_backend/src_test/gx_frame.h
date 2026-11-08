#ifndef GX_FRAME_H
#define GX_FRAME_H
#include "gx_gl.h"
typedef struct {
    GXGLStats gl;
    u64 render,copy,texture_copy,uploads,texture_hits,hash_bytes,readbacks;
    u64 vram_copies,vram_resolves,xfb_copies,xfb_resolves,display_copies,merged;
    u32 vram_pending;
    u64 packets,bytes,worker_ticks,wait_ticks;
    u64 draw_ticks,copy_ticks,swap_ticks;
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
bool gx_frame_drain(void);
bool gx_frame_stop(void);
void gx_frame_stats(GXFrameStats* result);
#endif
