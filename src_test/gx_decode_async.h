#ifndef GX_DECODE_ASYNC_H
#define GX_DECODE_ASYNC_H
#include "gx_gl.h"
#include "cpu/cpu.h"
#include <stddef.h>
typedef struct {
    u32 stride,matrix_bytes;
    u8 mode[12],format[12],components[12],fraction[12],normal_indices;
} VertexLayout;
typedef struct GXRawSnapshot GXRawSnapshot;
typedef struct {
    GXRawSnapshot* input;GXGLRawVertex* output;
    u64 (*hash)(const void*,size_t);u64 ticks,raw_hash,vertex_hits,vertex_misses;
} GXRawWork;
GXRawSnapshot* gx_raw_snapshot(CPUState* cpu,const VertexLayout* layout,const u32* cp,const u8* fifo,u32 fifo_bytes,u32 cursor,u32 count);
size_t gx_raw_size(const GXRawSnapshot* snapshot);
void gx_raw_free(GXRawSnapshot* snapshot);
bool gx_raw_async_submit(GXRawWork* work);
void gx_raw_async_wait(void);
void gx_raw_async_shutdown(void);
#endif
