#ifndef GX_GL_H
#define GX_GL_H
#include <SDL.h>
#include "cpu/cpu.h"

/* Host renderer data only; guest CPU and memory ABI are unchanged. */
typedef struct {
    float x, y, z, w, clip_z;
    float texcoord[8][3];
    u8 color[4];
} GXGLVertex;
typedef struct {
    u32 bp[256], colors[8], konst[8];
    bool tev_valid, alpha_valid, scissor_valid;
} GXGLMaterial;
typedef struct {
    float position[3],normal[3],texcoord[8][3];
    u8 color[4],tex_matrix[8];u32 matrix;
} GXGLRawVertex;
typedef struct {u32 words[0x1058];bool projection,lighting;} GXGLTransform;
typedef struct {u64 draws,stream_bytes,orphans,shader_compiles,uniform_lookups,vram_copies,geometry_hits,geometry_uploads,xf_uniform_blocks,geometry_hashes,dynamic_streams,hash_ticks,lookup_ticks,repack_ticks;} GXGLStats;
void gx_gl_set_geometry_cache(bool enabled);
bool gx_gl_geometry_cache(void);
void gx_gl_set_internal_scale(float scale);
float gx_gl_get_internal_scale(void);
void gx_gl_get_stats(GXGLStats* stats);
bool gx_gl_copy_color(SDL_Renderer* renderer,SDL_Texture* destination,const SDL_Rect* source);
bool gx_gl_copy_texture(SDL_Renderer* renderer,SDL_Texture* destination,const SDL_Rect* source,u32 format,u32 step,bool luma);

bool gx_gl_available(SDL_Renderer* renderer);
bool gx_gl_xf_available(SDL_Renderer* renderer);
int gx_gl_validate_xf(SDL_Renderer* renderer,const GXGLTransform* transform,
                     const GXGLRawVertex* raw,const GXGLVertex* expected,u32 stride,u32 count);
bool gx_gl_draw_raw_hashed(SDL_Renderer* renderer,const GXGLMaterial* material,SDL_Texture* textures[8],const GXGLRawVertex* vertices,const GXGLTransform* transform,u32 count,u8 primitive,u64 validated_hash);
bool gx_gl_draw_raw(SDL_Renderer* renderer,const GXGLMaterial* material,
                    SDL_Texture* textures[8],const GXGLRawVertex* vertices,
                    const GXGLTransform* transform,u32 count,u8 primitive);
bool gx_gl_draw(SDL_Renderer* renderer, const GXGLMaterial* material,
                SDL_Texture* textures[8], const GXGLVertex* vertices,
                u32 stride, u32 count, u8 primitive);
void gx_gl_clear_depth(SDL_Renderer* renderer, int x, int y, int w, int h, u32 value);
bool gx_gl_pack_yuy2(SDL_Renderer* renderer,SDL_Texture* efb,const SDL_Rect* source,
                    u32 output_height,u8* output,u32 pitch);
void gx_gl_shutdown(void);
#endif
