#ifndef GX_IMAGES_H
#define GX_IMAGES_H
#include "cpu/cpu.h"
typedef struct GXSourceImage GXSourceImage;
typedef struct GXPaletteImage GXPaletteImage;
typedef struct {GXSourceImage* source;GXPaletteImage* palette;} GXImageSnapshot;
bool gx_images_capture(CPUState* cpu,u32 address,u32 bytes,const u8* palette,u32 palette_bytes,u8 palette_format,GXImageSnapshot* out);
void gx_images_release(GXImageSnapshot* image);
const u8* gx_images_raw(const GXImageSnapshot* image);
const u8* gx_images_palette(const GXImageSnapshot* image);
u64 gx_images_key(const GXImageSnapshot* image);
void gx_images_shutdown(void);
void gx_images_stats(u64* source_hits,u64* source_bytes,u64* palette_hits,u64* palette_bytes);
#endif
