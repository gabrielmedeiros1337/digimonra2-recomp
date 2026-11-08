#include "frame_timing.h"
#include "gx_gl.h"
#include <SDL_opengl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#if defined(DIGIMON_XXHASH)
#define XXH_INLINE_ALL
#include "xxhash.h"
#endif

#define GLSL(...) #__VA_ARGS__
#include "gx_vertex_xf.h"
static const char* vertex_source = "#version 120\n" GLSL(
    varying vec2 depthZW;
    varying vec4 raster;
    varying vec3 tc[8];
    void main() {
        gl_Position=vec4(gl_Vertex.xy,0.0,gl_Vertex.w);
        gl_ClipVertex=vec4(0.0,0.0,gl_MultiTexCoord0.w,gl_Vertex.w);
        depthZW=gl_Vertex.zw;
        raster=gl_Color*255.0;
        tc[0]=gl_MultiTexCoord0.xyz; tc[1]=gl_MultiTexCoord1.xyz;
        tc[2]=gl_MultiTexCoord2.xyz; tc[3]=gl_MultiTexCoord3.xyz;
        tc[4]=gl_MultiTexCoord4.xyz; tc[5]=gl_MultiTexCoord5.xyz;
        tc[6]=gl_MultiTexCoord6.xyz; tc[7]=gl_MultiTexCoord7.xyz;
    }
);
static const char* fragment_source = "#version 120\n" GLSL(
    varying vec2 depthZW;
    varying vec4 raster;
    varying vec3 tc[8];
    uniform sampler2D image0,image1,image2,image3,image4,image5,image6,image7;
    uniform vec4 initial[4],konst[4],swapTable[4];
    uniform ivec4 colorInput[16],alphaInput[16],colorOp[16],alphaOp[16];
    uniform ivec4 order[16],selectors[16];
    uniform int stages,bypass,alphaEnabled;
    uniform ivec4 alphaTest;
    uniform vec2 alphaRef;
    float component(vec4 x,int i) { if(i==0)return x.r; if(i==1)return x.g; if(i==2)return x.b; return x.a; }
    vec4 swapColor(vec4 x,int i) {
        vec4 s=swapTable[i]; return vec4(component(x,int(s.r)),component(x,int(s.g)),component(x,int(s.b)),component(x,int(s.a)));
    }
    vec4 sampleTexture(int unit,int coord) {
        vec3 uv=tc[coord]; vec2 p=uv.z==0.0 ? uv.xy : uv.xy/uv.z;
        if(unit==0)return texture2D(image0,p)*255.0; if(unit==1)return texture2D(image1,p)*255.0;
        if(unit==2)return texture2D(image2,p)*255.0; if(unit==3)return texture2D(image3,p)*255.0;
        if(unit==4)return texture2D(image4,p)*255.0; if(unit==5)return texture2D(image5,p)*255.0;
        if(unit==6)return texture2D(image6,p)*255.0; return texture2D(image7,p)*255.0;
    }
    vec3 colorArg(int i,vec4 r[4],vec4 t,vec4 v,vec4 k) {
        if(i<8) { if(mod(float(i),2.0)==0.0)return r[i/2].rgb; return r[i/2].aaa; }
        if(i==8)return t.rgb; if(i==9)return t.aaa; if(i==10)return v.rgb; if(i==11)return v.aaa;
        if(i==12)return vec3(255.0); if(i==13)return vec3(128.0); if(i==14)return k.rgb; return vec3(0.0);
    }
    float alphaArg(int i,vec4 r[4],vec4 t,vec4 v,vec4 k) {
        if(i<4)return r[i].a; if(i==4)return t.a; if(i==5)return v.a; if(i==6)return k.a; return 0.0;
    }
    vec4 konstColor(int kc,int ka) {
        vec4 result=vec4(0.0);
        if(kc<8)result.rgb=vec3(kc==0 ? 255.0 : 256.0-float(kc)*32.0);
        else if(kc>=12 && kc<16)result.rgb=konst[kc-12].rgb;
        else if(kc>=16) { int n=kc-16; result.rgb=vec3(component(konst[int(mod(float(n),4.0))],n/4)); }
        if(ka<8)result.a=ka==0 ? 255.0 : 256.0-float(ka)*32.0;
        else if(ka>=16) { int n=ka-16; result.a=component(konst[int(mod(float(n),4.0))],n/4); }
        return result;
    }
    bool compare(float a,float b,int op) {
        if(op==0)return false; if(op==1)return a<b; if(op==2)return a==b; if(op==3)return a<=b;
        if(op==4)return a>b; if(op==5)return a!=b; if(op==6)return a>=b; return true;
    }
    vec3 combine(vec3 a,vec3 b,vec3 c,vec3 d,ivec4 op) {
        a=mod(a,256.0); b=mod(b,256.0); c=mod(c,256.0); vec3 value;
        if(op.x==3) {
            vec3 flag;
            if(op.z==3) flag=op.y==0 ? vec3(greaterThan(a,b)) : vec3(equal(a,b));
            else {
                vec3 weight=op.z==0 ? vec3(1.0,0.0,0.0) : op.z==1 ? vec3(1.0,256.0,0.0) : vec3(1.0,256.0,65536.0);
                float aa=dot(a,weight),bb=dot(b,weight); flag=vec3((op.y==0 ? aa>bb : aa==bb) ? 1.0 : 0.0);
            }
            value=d+flag*c;
        } else {
            value=floor((a*(255.0-c)+b*c+127.0)/255.0);
            value=d+(op.y==0 ? value : -value);
            if(op.x==1)value+=128.0; if(op.x==2)value-=128.0;
            value*=op.z==0 ? 1.0 : op.z==1 ? 2.0 : op.z==2 ? 4.0 : 0.5;
            value=floor(value);
        }
        return clamp(value,op.w==0 ? -1024.0 : 0.0,op.w==0 ? 1023.0 : 255.0);
    }
    void main() {
        vec4 r[4]; for(int i=0;i<4;i++)r[i]=initial[i];
        vec4 outputColor=raster;
        if(bypass==0) {
            int dc=0,da=0;
            for(int i=0;i<16;i++) {
                if(i>=stages)break;
                ivec4 o=order[i],s=selectors[i];
                vec4 texel=mod(float(o.z),2.0)==0.0 ? vec4(255.0) : swapColor(floor(sampleTexture(o.x,o.y)+0.5),s.w);
                int rasterChannel=int(mod(float(o.w),8.0));
                vec4 ras=(rasterChannel==7 || rasterChannel==5) ? vec4(0.0) : raster;
                ras=swapColor(ras,s.z);
                vec4 k=konstColor(s.x,s.y); ivec4 ci=colorInput[i],ai=alphaInput[i];
                vec3 color=combine(colorArg(ci.x,r,texel,ras,k),colorArg(ci.y,r,texel,ras,k),colorArg(ci.z,r,texel,ras,k),colorArg(ci.w,r,texel,ras,k),colorOp[i]);
                float alpha=combine(vec3(alphaArg(ai.x,r,texel,ras,k)),vec3(alphaArg(ai.y,r,texel,ras,k)),vec3(alphaArg(ai.z,r,texel,ras,k)),vec3(alphaArg(ai.w,r,texel,ras,k)),alphaOp[i]).r;
                dc=o.z/2; da=o.w/8;
                r[dc].rgb=color; r[da].a=alpha;
            }
            outputColor=vec4(r[dc].rgb,r[da].a);
        }
        outputColor=clamp(outputColor,0.0,255.0);
        if(alphaEnabled!=0) {
            float a=floor(outputColor.a+0.5); bool first=compare(a,alphaRef.x,alphaTest.x),second=compare(a,alphaRef.y,alphaTest.y);
            bool pass=alphaTest.z==0 ? first && second : alphaTest.z==1 ? first || second : alphaTest.z==2 ? first!=second : first==second;
            if(!pass)discard;
        }
        gl_FragDepth=clamp((depthZW.x/depthZW.y+1.0)*0.5,0.0,1.0);
        gl_FragColor=outputColor/255.0;
    }
);

typedef void (APIENTRY *GXClientActiveTextureProc)(GLenum);

#define GL_FUNCS(X) \
 X(CreateShader,PFNGLCREATESHADERPROC) X(ShaderSource,PFNGLSHADERSOURCEPROC) \
 X(CompileShader,PFNGLCOMPILESHADERPROC) X(GetShaderiv,PFNGLGETSHADERIVPROC) X(GetShaderInfoLog,PFNGLGETSHADERINFOLOGPROC) \
 X(DeleteShader,PFNGLDELETESHADERPROC) X(CreateProgram,PFNGLCREATEPROGRAMPROC) X(AttachShader,PFNGLATTACHSHADERPROC) \
 X(LinkProgram,PFNGLLINKPROGRAMPROC) X(GetProgramiv,PFNGLGETPROGRAMIVPROC) X(GetProgramInfoLog,PFNGLGETPROGRAMINFOLOGPROC) \
 X(DeleteProgram,PFNGLDELETEPROGRAMPROC) X(UseProgram,PFNGLUSEPROGRAMPROC) X(GetUniformLocation,PFNGLGETUNIFORMLOCATIONPROC) \
 X(Uniform1i,PFNGLUNIFORM1IPROC) X(Uniform4iv,PFNGLUNIFORM4IVPROC) X(Uniform4fv,PFNGLUNIFORM4FVPROC) X(Uniform2fv,PFNGLUNIFORM2FVPROC) \
 X(ActiveTexture,PFNGLACTIVETEXTUREPROC) X(ClientActiveTexture,GXClientActiveTextureProc) X(BindBuffer,PFNGLBINDBUFFERPROC) X(BlendEquation,PFNGLBLENDEQUATIONPROC) \
 X(GenRenderbuffers,PFNGLGENRENDERBUFFERSPROC) X(BindRenderbuffer,PFNGLBINDRENDERBUFFERPROC) \
 X(RenderbufferStorage,PFNGLRENDERBUFFERSTORAGEPROC) X(FramebufferRenderbuffer,PFNGLFRAMEBUFFERRENDERBUFFERPROC) \
 X(DeleteRenderbuffers,PFNGLDELETERENDERBUFFERSPROC) \
 X(GenBuffers,PFNGLGENBUFFERSPROC) X(DeleteBuffers,PFNGLDELETEBUFFERSPROC) X(BufferData,PFNGLBUFFERDATAPROC) X(BufferSubData,PFNGLBUFFERSUBDATAPROC)
#define DECLARE(name,type) static type g##name;
GL_FUNCS(DECLARE)
static GLuint s_program,s_depth,s_depth_fbo;
static GLuint s_pack_program;static int s_pack_init,s_copy_init;
static SDL_Texture* s_pack_target;
static u32 s_pack_width,s_pack_height;
static GLint s_pack_efb,s_pack_rect,s_pack_scale;
static GLuint s_stream_buffer;static size_t s_stream_head,s_stream_capacity;
static PFNGLMAPBUFFERRANGEPROC streamMap;static PFNGLUNMAPBUFFERPROC streamUnmap;
static GLuint s_copy_fbo,s_copy_program;static GLint s_copy_sampler,s_copy_rect,s_copy_info,s_copy_scale;static bool s_copy_procs_checked;
static PFNGLGENFRAMEBUFFERSPROC copyGen;static PFNGLBINDFRAMEBUFFERPROC copyBind;static PFNGLFRAMEBUFFERTEXTURE2DPROC copyAttach;
static PFNGLCHECKFRAMEBUFFERSTATUSPROC copyCheck;static PFNGLBLITFRAMEBUFFERPROC copyBlit;static PFNGLDELETEFRAMEBUFFERSPROC copyDelete;
static GXGLStats s_stats;
void gx_gl_get_stats(GXGLStats* stats){*stats=s_stats;}
static GLint uniform_location(GLuint program,const char* name){s_stats.uniform_lookups++;return gGetUniformLocation(program,name);}

typedef struct {GLfloat clip[4];u8 color[4];GLfloat texcoord[8][4],normal[3];} HostVertex;
static HostVertex* s_vertices;
static u32 s_vertex_capacity;
static int s_init; // 0 untried, 1 usable, -1 failed
typedef struct {GLint initial,konst,swap,ci,ai,co,ao,order,select,stages,bypass,alpha,atest,aref;} TevUniforms;
static TevUniforms s_u,s_tev_uniforms[2];
#define u_initial s_u.initial
#define u_konst s_u.konst
#define u_swap s_u.swap
#define u_ci s_u.ci
#define u_ai s_u.ai
#define u_co s_u.co
#define u_ao s_u.ao
#define u_order s_u.order
#define u_select s_u.select
#define u_stages s_u.stages
#define u_bypass s_u.bypass
#define u_alpha s_u.alpha
#define u_atest s_u.atest
#define u_aref s_u.aref
static GLuint s_xf_program;static int s_xf_init;
typedef struct {GLint points,normals,postMatrices,lights,lightColors,lightMasks,ambientColor,materialColor,
    channelControl,channelAttenuation,texInfo,postInfo,projectionData,viewportScale,viewportOffset,hasProjection,hasLighting,perspective;} XFUniforms;
static XFUniforms s_xf_u;static GXGLTransform s_last_xf;static bool s_xf_values_valid;

typedef struct {u64 hash,used;u32 count,next;GLuint buffer;GXGLRawVertex* source;} GeometryEntry;
static GeometryEntry s_geometry[128];static u32 s_geometry_buckets[256];
static struct {u64 hash;u32 count;} s_geometry_candidates[256];
static u64 s_geometry_serial;static size_t s_geometry_bytes;
static bool s_geometry_cache_enabled=true;
void gx_gl_set_geometry_cache(bool enabled){s_geometry_cache_enabled=enabled;}
bool gx_gl_geometry_cache(void){return s_geometry_cache_enabled;}
static u64 geometry_hash(const GXGLRawVertex* source,u32 count){
    s_stats.geometry_hashes++;
#if defined(DIGIMON_XXHASH)
    return XXH64(source,(size_t)count*sizeof(*source),0x58464758u);
#else
    const u8* data=(const u8*)source;u64 h=0xCBF29CE484222325ull;for(size_t i=0;i<(size_t)count*sizeof(*source);i++)h=(h^data[i])*0x100000001B3ull;return h;
#endif
}
static GLuint geometry_find(u64 hash,const GXGLRawVertex* source,u32 count){
    for(u32 id=s_geometry_buckets[hash&255u];id;id=s_geometry[id-1].next){GeometryEntry* e=s_geometry+id-1;
        if(e->hash==hash && e->count==count && !memcmp(e->source,source,(size_t)count*sizeof(*source))){e->used=++s_geometry_serial;s_stats.geometry_hits++;return e->buffer;}}
    return 0;
}
static void geometry_evict(u32 slot){
    GeometryEntry* e=s_geometry+slot;if(!e->buffer)return;
    u32* link=s_geometry_buckets+(e->hash&255u);while(*link && *link!=slot+1)link=&s_geometry[*link-1].next;if(*link)*link=e->next;
    s_geometry_bytes-=(size_t)e->count*(sizeof(GXGLRawVertex)+sizeof(HostVertex));gDeleteBuffers(1,&e->buffer);free(e->source);memset(e,0,sizeof(*e));
}
static GLuint geometry_store(u64 hash,const GXGLRawVertex* source,u32 count){
    size_t bytes=(size_t)count*(sizeof(*source)+sizeof(HostVertex));if(bytes>32u*1024u*1024u)return 0;
    u32 candidate=(u32)(hash&255u);
    bool seen=s_geometry_candidates[candidate].hash==hash && s_geometry_candidates[candidate].count==count;
    s_geometry_candidates[candidate].hash=hash;s_geometry_candidates[candidate].count=count;if(!seen)return 0;
    u32 slot=128;
    for(u32 i=0;i<128;i++)if(!s_geometry[i].buffer){slot=i;break;}
    while(slot==128 || s_geometry_bytes+bytes>32u*1024u*1024u){
        u32 oldest=128;for(u32 i=0;i<128;i++)if(s_geometry[i].buffer && (oldest==128 || s_geometry[i].used<s_geometry[oldest].used))oldest=i;
        if(oldest==128)return 0;geometry_evict(oldest);slot=oldest;
    }
    GXGLRawVertex* copy=malloc((size_t)count*sizeof(*copy));if(!copy)return 0;memcpy(copy,source,(size_t)count*sizeof(*copy));
    GLuint buffer;gGenBuffers(1,&buffer);if(!buffer){free(copy);return 0;}gBindBuffer(GL_ARRAY_BUFFER,buffer);
    gBufferData(GL_ARRAY_BUFFER,(GLsizeiptr)((size_t)count*sizeof(HostVertex)),s_vertices,GL_STATIC_DRAW);
    s_geometry[slot]=(GeometryEntry){hash,++s_geometry_serial,count,s_geometry_buckets[hash&255u],buffer,copy};s_geometry_buckets[hash&255u]=slot+1;
    s_geometry_bytes+=bytes;s_stats.geometry_uploads++;return buffer;
}
static GLuint compile_shader(GLenum type,const char* source) {
    s_stats.shader_compiles++;GLuint shader=gCreateShader(type); GLint ok=0;
    gShaderSource(shader,1,&source,NULL); gCompileShader(shader); gGetShaderiv(shader,GL_COMPILE_STATUS,&ok);
    if(!ok) { char error[4096]; gGetShaderInfoLog(shader,sizeof(error),NULL,error); fprintf(stderr,"[GX GL shader] %s\n",error); gDeleteShader(shader); return 0; }
    return shader;
}
static TevUniforms find_tev_uniforms(GLuint program) {
#define UNIFORM(var,name) var=uniform_location(program,name)
    UNIFORM(u_initial,"initial");UNIFORM(u_konst,"konst");UNIFORM(u_swap,"swapTable");
    UNIFORM(u_ci,"colorInput");UNIFORM(u_ai,"alphaInput");UNIFORM(u_co,"colorOp");UNIFORM(u_ao,"alphaOp");
    UNIFORM(u_order,"order");UNIFORM(u_select,"selectors");UNIFORM(u_stages,"stages");UNIFORM(u_bypass,"bypass");
    UNIFORM(u_alpha,"alphaEnabled");UNIFORM(u_atest,"alphaTest");UNIFORM(u_aref,"alphaRef");
#undef UNIFORM
return s_u;
}
bool gx_gl_available(SDL_Renderer* renderer) {
    SDL_RendererInfo info;
    if(!renderer || SDL_GetRendererInfo(renderer,&info)!=0 || strcmp(info.name,"opengl"))return false;
    if(s_init)return s_init>0;
    s_init=-1;
#define LOAD(name,type) g##name=(type)SDL_GL_GetProcAddress("gl" #name); if(!g##name){fprintf(stderr,"[GX GL] missing gl%s\n",#name);return false;}
    GL_FUNCS(LOAD)
#undef LOAD
    streamMap=(PFNGLMAPBUFFERRANGEPROC)SDL_GL_GetProcAddress("glMapBufferRange");streamUnmap=(PFNGLUNMAPBUFFERPROC)SDL_GL_GetProcAddress("glUnmapBuffer");
    GLuint vs=compile_shader(GL_VERTEX_SHADER,vertex_source),fs=compile_shader(GL_FRAGMENT_SHADER,fragment_source);
    if(!vs || !fs){if(vs)gDeleteShader(vs);if(fs)gDeleteShader(fs);return false;}
    s_program=gCreateProgram();gAttachShader(s_program,vs);gAttachShader(s_program,fs);gLinkProgram(s_program);
    gDeleteShader(vs);gDeleteShader(fs);GLint ok=0;gGetProgramiv(s_program,GL_LINK_STATUS,&ok);
    if(!ok){char error[4096];gGetProgramInfoLog(s_program,sizeof(error),NULL,error);fprintf(stderr,"[GX GL link] %s\n",error);gDeleteProgram(s_program);s_program=0;return false;}
s_tev_uniforms[0]=find_tev_uniforms(s_program);
    GLint previous;glGetIntegerv(GL_CURRENT_PROGRAM,&previous);gUseProgram(s_program);
    for(int i=0;i<8;i++){char name[16];snprintf(name,sizeof(name),"image%d",i);gUniform1i(uniform_location(s_program,name),i);}
    gUseProgram((GLuint)previous);s_init=1;
    printf("[GX GL] per-pixel TEV, 8 texture units and homogeneous/depth rasterization enabled\n");return true;
}
static void ensure_depth(void) {
    GLint fbo=0;glGetIntegerv(GL_FRAMEBUFFER_BINDING,&fbo);if(!fbo || (GLuint)fbo==s_depth_fbo)return;
    if(!s_depth){gGenRenderbuffers(1,&s_depth);GLint previous;glGetIntegerv(GL_RENDERBUFFER_BINDING,&previous);gBindRenderbuffer(GL_RENDERBUFFER,s_depth);gRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH_COMPONENT24,640,528);gBindRenderbuffer(GL_RENDERBUFFER,(GLuint)previous);}
    gFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_RENDERBUFFER,s_depth);s_depth_fbo=(GLuint)fbo;
    glPushAttrib(GL_DEPTH_BUFFER_BIT|GL_SCISSOR_BIT);glDisable(GL_SCISSOR_TEST);glDepthMask(GL_TRUE);glClearDepth(1.0);glClear(GL_DEPTH_BUFFER_BIT);glPopAttrib();
}
static XFUniforms find_xf_uniforms(GLuint program){XFUniforms result;
#define XF_LOCATION(name) result.name=uniform_location(program,#name)
    XF_LOCATION(points);XF_LOCATION(normals);XF_LOCATION(postMatrices);XF_LOCATION(lights);XF_LOCATION(lightColors);XF_LOCATION(lightMasks);
    XF_LOCATION(ambientColor);XF_LOCATION(materialColor);XF_LOCATION(channelControl);XF_LOCATION(channelAttenuation);XF_LOCATION(texInfo);XF_LOCATION(postInfo);
    XF_LOCATION(projectionData);XF_LOCATION(viewportScale);XF_LOCATION(viewportOffset);XF_LOCATION(hasProjection);XF_LOCATION(hasLighting);XF_LOCATION(perspective);
#undef XF_LOCATION
return result;
}
bool gx_gl_xf_available(SDL_Renderer* renderer) {
    if(!gx_gl_available(renderer))return false;
    if(s_xf_init)return s_xf_init>0;s_xf_init=-1;
    GLint components=0;glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS,&components);
    if(components<1024){fprintf(stderr,"[GX XF GL] insufficient vertex uniforms: %d\n",components);return false;}
    GLuint vs=compile_shader(GL_VERTEX_SHADER,vertex_xf_source),fs=compile_shader(GL_FRAGMENT_SHADER,fragment_source);
    if(!vs || !fs){if(vs)gDeleteShader(vs);if(fs)gDeleteShader(fs);return false;}
    GLuint program=gCreateProgram();gAttachShader(program,vs);gAttachShader(program,fs);gLinkProgram(program);
    gDeleteShader(vs);gDeleteShader(fs);GLint ok=0;gGetProgramiv(program,GL_LINK_STATUS,&ok);
    if(!ok){char error[4096];gGetProgramInfoLog(program,sizeof(error),NULL,error);fprintf(stderr,"[GX XF GL link] %s\n",error);gDeleteProgram(program);return false;}
    s_xf_program=program;s_tev_uniforms[1]=find_tev_uniforms(program);
s_xf_u=find_xf_uniforms(program);
    GLint previous;glGetIntegerv(GL_CURRENT_PROGRAM,&previous);gUseProgram(program);
    for(int i=0;i<8;i++){char name[16];snprintf(name,sizeof(name),"image%d",i);gUniform1i(uniform_location(program,name),i);}
    gUseProgram((GLuint)previous);s_xf_init=1;printf("[GX XF GL] vertex transform, lighting and texgen program ready; uniforms=%d\n",components);return true;
}
static void unpack_color(u32 value,GLfloat color[4]){for(u32 c=0;c<4;c++)color[c]=(GLfloat)((value>>((3-c)*8))&255u);}
static void upload_xf(const GXGLTransform* transform,bool cache_values) {
    const u32* x=transform->words;const u32* old=s_last_xf.words;bool fresh=!cache_values || !s_xf_values_valid;GLfloat data[264];
#define DIRTY(at,count) (fresh || memcmp(x+(at),old+(at),(count)*sizeof(u32))!=0)
#define XF_FLOAT_BLOCK(name,at,count) if(DIRTY(at,(count)*4u)){memcpy(data,x+(at),(count)*4u*sizeof(float));gUniform4fv(s_xf_u.name,count,data);s_stats.xf_uniform_blocks++;}
    XF_FLOAT_BLOCK(points,0,66);XF_FLOAT_BLOCK(normals,0x400,26);XF_FLOAT_BLOCK(postMatrices,0x500,66);XF_FLOAT_BLOCK(lights,0x600,32);
#undef XF_FLOAT_BLOCK
    if(DIRTY(0x600,128)){
        GLfloat colors[8][4];for(u32 i=0;i<8;i++)unpack_color(x[0x603+i*16],colors[i]);gUniform4fv(s_xf_u.lightColors,8,&colors[0][0]);s_stats.xf_uniform_blocks++;
    }
    if(DIRTY(0x100A,7)){
        GLfloat masks[4][4]={{0}},ambient[4],material[4];GLint controls[2][4]={{0}},attenuation[2][4]={{0}};
        unpack_color(x[0x100A],ambient);unpack_color(x[0x100C],material);
        for(u32 c=0;c<2;c++){
            u32 control=x[c ? 0x1010:0x100E],mask=((control>>2)&15u)|((control>>7)&240u);
            controls[c][0]=control&1u;controls[c][1]=(control>>1)&1u;controls[c][2]=(control>>6)&1u;controls[c][3]=(control>>7)&3u;attenuation[c][0]=(control>>9)&3u;
            for(u32 i=0;i<8;i++)masks[c*2+i/4][i%4]=(GLfloat)((mask>>i)&1u);
        }
        gUniform4fv(s_xf_u.lightMasks,4,&masks[0][0]);gUniform4fv(s_xf_u.ambientColor,1,ambient);gUniform4fv(s_xf_u.materialColor,1,material);
        gUniform4iv(s_xf_u.channelControl,2,&controls[0][0]);gUniform4iv(s_xf_u.channelAttenuation,2,&attenuation[0][0]);s_stats.xf_uniform_blocks+=5;
    }
    if(DIRTY(0x103F,9) || DIRTY(0x1050,8) || DIRTY(0x1012,1)){
        GLint info[8][4],post[8][4];for(u32 i=0;i<8;i++){
            u32 value=x[0x1040+i],p=x[0x1050+i];info[i][0]=(value>>7)&31;info[i][1]=(value>>2)&1;info[i][2]=(value>>4)&7;info[i][3]=(value>>1)&1;
            post[i][0]=p&63u;post[i][1]=(p>>8)&1;post[i][2]=x[0x1012]&1u;post[i][3]=x[0x103F]>i;
        }
        gUniform4iv(s_xf_u.texInfo,8,&info[0][0]);gUniform4iv(s_xf_u.postInfo,8,&post[0][0]);s_stats.xf_uniform_blocks+=2;
    }
    if(DIRTY(0x1020,8)){memcpy(data,x+0x1020,8*sizeof(float));gUniform4fv(s_xf_u.projectionData,2,data);gUniform1i(s_xf_u.perspective,x[0x1026]==0);s_stats.xf_uniform_blocks+=2;}
    if(DIRTY(0x101A,6)){GLfloat scale[4]={0},offset[4]={0};memcpy(scale,x+0x101A,3*sizeof(float));memcpy(offset,x+0x101D,3*sizeof(float));gUniform4fv(s_xf_u.viewportScale,1,scale);gUniform4fv(s_xf_u.viewportOffset,1,offset);s_stats.xf_uniform_blocks+=2;}
    if(fresh || transform->projection!=s_last_xf.projection){gUniform1i(s_xf_u.hasProjection,transform->projection);s_stats.xf_uniform_blocks++;}
    if(fresh || transform->lighting!=s_last_xf.lighting){gUniform1i(s_xf_u.hasLighting,transform->lighting);s_stats.xf_uniform_blocks++;}
    if(cache_values){s_last_xf=*transform;s_xf_values_valid=true;}
#undef DIRTY
}
static float reg_component(const u32* words,u32 reg,u32 c,bool is_konst) {
    u32 ra=words[reg*2],bg=words[reg*2+1];u32 value=c==0 ? ra&2047 : c==1 ? (bg>>12)&2047 : c==2 ? bg&2047 : (ra>>12)&2047;
    return is_konst ? (float)(value&255) : (float)((value&1024) ? (int)value-2048 : (int)value);
}
static bool gx_gl_draw_internal_timed_body(SDL_Renderer* renderer,const GXGLMaterial* m,SDL_Texture* textures[8],const GXGLVertex* vertices,u32 stride,u32 count,u8 primitive,const GXGLRawVertex* raw,const GXGLTransform* xf,u64 validated_hash) {
    if(!count)return true;
    if(!gx_gl_available(renderer) || (raw && !gx_gl_xf_available(renderer)))return false;
    s_u=s_tev_uniforms[raw ? 1:0];
    static const GLenum types[8]={GL_QUADS,GL_QUADS,GL_TRIANGLES,GL_TRIANGLE_STRIP,GL_TRIANGLE_FAN,GL_LINES,GL_LINE_STRIP,GL_POINTS};
    if(primitive<0x80 || primitive>0xB8)return true;
    SDL_RenderFlush(renderer);ensure_depth();GLint program,active;
    glGetIntegerv(GL_CURRENT_PROGRAM,&program);glGetIntegerv(GL_ACTIVE_TEXTURE,&active);glPushAttrib(GL_ALL_ATTRIB_BITS);
    FrameStage preparation=frame_timing_enter(FRAME_GX_DECODE);
    u32 stages=((m->bp[0]>>10)&15u)+1,used=0;
    GLint ci[16][4],ai[16][4],co[16][4],ao[16][4],order[16][4],select[16][4];
    GLfloat initial[4][4],konst[4][4],swaps[4][4];
    for(u32 r=0;r<4;r++)for(u32 c=0;c<4;c++){initial[r][c]=reg_component(m->colors,r,c,false);konst[r][c]=reg_component(m->konst,r,c,true);}
    for(u32 r=0;r<4;r++) {u32 first=m->bp[0xF6+r*2],second=m->bp[0xF7+r*2];swaps[r][0]=(float)(first&3);swaps[r][1]=(float)((first>>2)&3);swaps[r][2]=(float)(second&3);swaps[r][3]=(float)((second>>2)&3);}
    /* Default identity is used until swap-table registers have been configured. */
    bool any_swap=false;for(u32 r=0;r<8;r++)any_swap|=(m->bp[0xF6+r]&15)!=0;
    if(!any_swap)for(u32 r=0;r<4;r++)for(u32 c=0;c<4;c++)swaps[r][c]=(float)c;
    for(u32 i=0;i<16;i++) {
        u32 color=m->bp[0xC0+i*2],alpha=m->bp[0xC1+i*2],o=m->bp[0x28+i/2]>>((i&1)*12),k=m->bp[0xF6+i/2]>>((i&1)*10);
        ci[i][0]=(color>>12)&15;ci[i][1]=(color>>8)&15;ci[i][2]=(color>>4)&15;ci[i][3]=color&15;
        ai[i][0]=(alpha>>13)&7;ai[i][1]=(alpha>>10)&7;ai[i][2]=(alpha>>7)&7;ai[i][3]=(alpha>>4)&7;
        for(u32 a=0;a<2;a++){u32 env=a ? alpha : color;GLint* out=a ? ao[i] : co[i];out[0]=(env>>16)&3;out[1]=(env>>18)&1;out[2]=(env>>20)&3;out[3]=(env>>19)&1;}
        order[i][0]=o&7;order[i][1]=(o>>3)&7;
        /* Pack destination with enable/channel; shader unpacks arithmetically (GLSL 1.20). */
        order[i][2]=((color>>22)&3)*2+((o>>6)&1);order[i][3]=((alpha>>22)&3)*8+((o>>7)&7);
        select[i][0]=(k>>4)&31;select[i][1]=(k>>9)&31;select[i][2]=alpha&3;select[i][3]=(alpha>>2)&3;
        if(i<stages && (o&64))used|=1u<<(o&7);
    }
    frame_timing_leave(preparation);
    for(u32 i=0;i<8;i++)if(used&(1u<<i)) {
        gActiveTexture(GL_TEXTURE0+i);float w,h;
        if(textures[i] && SDL_GL_BindTexture(textures[i],&w,&h)==0) {
            u32 mode=m->bp[(i<4 ? 0x80 : 0xA0)+(i&3)];
            static const GLint wrap[4]={GL_CLAMP_TO_EDGE,GL_REPEAT,GL_MIRRORED_REPEAT,GL_CLAMP_TO_EDGE};
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,wrap[mode&3]);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,wrap[(mode>>2)&3]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,(mode&16) ? GL_LINEAR : GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,((mode>>5)&4) ? GL_LINEAR : GL_NEAREST);
        } else {glBindTexture(GL_TEXTURE_2D,0);}
    }
    gUseProgram(raw ? s_xf_program:s_program);if(raw)upload_xf(xf,true);gUniform4fv(u_initial,4,&initial[0][0]);gUniform4fv(u_konst,4,&konst[0][0]);gUniform4fv(u_swap,4,&swaps[0][0]);
    gUniform4iv(u_ci,16,&ci[0][0]);gUniform4iv(u_ai,16,&ai[0][0]);gUniform4iv(u_co,16,&co[0][0]);gUniform4iv(u_ao,16,&ao[0][0]);
    gUniform4iv(u_order,16,&order[0][0]);gUniform4iv(u_select,16,&select[0][0]);gUniform1i(u_stages,(GLint)stages);gUniform1i(u_bypass,!m->tev_valid);
    u32 at=m->bp[0xF3];GLint test[4]={(at>>16)&7,(at>>19)&7,(at>>22)&3,0};GLfloat refs[2]={(float)(at&255),(float)((at>>8)&255)};
    gUniform4iv(u_atest,1,test);gUniform2fv(u_aref,1,refs);gUniform1i(u_alpha,m->alpha_valid);
    glViewport(0,0,640,528);glDepthRange(0.0,1.0);
    // GX clips the projected -w..0 volume before applying the viewport depth range.
    // Native GL clipping of the viewport-mapped Z would incorrectly discard HUDs.
    const GLdouble near_plane[4]={0,0,1,1},far_plane[4]={0,0,-1,0};
    GLint matrix_mode;glGetIntegerv(GL_MATRIX_MODE,&matrix_mode);glMatrixMode(GL_MODELVIEW);glPushMatrix();glLoadIdentity();
    glClipPlane(GL_CLIP_PLANE0,near_plane);glClipPlane(GL_CLIP_PLANE1,far_plane);
    glPopMatrix();glMatrixMode((GLenum)matrix_mode);glEnable(GL_CLIP_PLANE0);glEnable(GL_CLIP_PLANE1);
glDisable(GL_LIGHTING);glDisable(GL_ALPHA_TEST);glDisable(GL_FOG);glDisable(GL_STENCIL_TEST);
    u32 blend=m->bp[0x41],depth=m->bp[0x40],cull=(m->bp[0]>>14)&3;
    if(blend&1) {
        static const GLenum src[8]={GL_ZERO,GL_ONE,GL_DST_COLOR,GL_ONE_MINUS_DST_COLOR,GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA};
        static const GLenum dst[8]={GL_ZERO,GL_ONE,GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR,GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA};
        glEnable(GL_BLEND);glBlendFunc((blend&0x800) ? GL_ONE : src[(blend>>8)&7],(blend&0x800) ? GL_ONE : dst[(blend>>5)&7]);gBlendEquation((blend&0x800) ? GL_FUNC_REVERSE_SUBTRACT : GL_FUNC_ADD);
    } else glDisable(GL_BLEND);
    if(blend&2){glEnable(GL_COLOR_LOGIC_OP);glLogicOp(GL_CLEAR+((blend>>12)&15));}else glDisable(GL_COLOR_LOGIC_OP);
    if(depth&1)glEnable(GL_DEPTH_TEST);else glDisable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEVER+((depth>>1)&7));glDepthMask((depth&16) ? GL_TRUE : GL_FALSE);glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    if(cull){glEnable(GL_CULL_FACE);glFrontFace(GL_CCW);glCullFace(cull==1 ? GL_BACK : cull==2 ? GL_FRONT : GL_FRONT_AND_BACK);}else glDisable(GL_CULL_FACE);
    if(m->scissor_valid) {
        int ox=(m->bp[0x59]&511)*2,oy=((m->bp[0x59]>>10)&511)*2;
        int x=(int)((m->bp[0x20]>>12)&2047)-ox,y=(int)(m->bp[0x20]&2047)-oy;
        int w=(int)((m->bp[0x21]>>12)&2047)-ox-x+1,h=(int)(m->bp[0x21]&2047)-oy-y+1;
        glEnable(GL_SCISSOR_TEST);glScissor(x,y,w<0 ? 0 : w,h<0 ? 0 : h);
    }else glDisable(GL_SCISSOR_TEST);
    preparation=frame_timing_enter(FRAME_GX_DECODE);
    bool cache=raw && s_geometry_cache_enabled;
    if(raw && !cache)s_stats.dynamic_streams++;
    u64 measured=SDL_GetPerformanceCounter();
    u64 content=cache ? (validated_hash ? validated_hash:geometry_hash(raw,count)):0;
    s_stats.hash_ticks+=SDL_GetPerformanceCounter()-measured;measured=SDL_GetPerformanceCounter();
    GLuint geometry=cache ? geometry_find(content,raw,count):0;
    s_stats.lookup_ticks+=SDL_GetPerformanceCounter()-measured;measured=SDL_GetPerformanceCounter();
    if(!geometry && count>s_vertex_capacity) {
        HostVertex* storage=(HostVertex*)realloc(s_vertices,(size_t)count*sizeof(HostVertex));
        if(!storage){frame_timing_leave(preparation);gUseProgram((GLuint)program);gActiveTexture((GLenum)active);glPopAttrib();return false;}
        s_vertices=storage;s_vertex_capacity=count;
    }
    for(u32 i=0;!geometry && i<count;i++) {
        HostVertex* out=&s_vertices[i];
        if(raw) {
            const GXGLRawVertex* v=raw+i;memcpy(out->clip,v->position,3*sizeof(float));out->clip[3]=(float)v->matrix;
            memcpy(out->color,v->color,4);memcpy(out->normal,v->normal,sizeof(out->normal));
            for(u32 j=0;j<8;j++){memcpy(out->texcoord[j],v->texcoord[j],3*sizeof(float));out->texcoord[j][3]=(float)v->tex_matrix[j];}
        } else {
            const GXGLVertex* v=(const GXGLVertex*)((const u8*)vertices+i*stride);
            out->clip[0]=v->x/320.0f-v->w;out->clip[1]=v->y/264.0f-v->w;
            out->clip[2]=(v->z*2.0f-1.0f)*v->w;out->clip[3]=v->w;memcpy(out->color,v->color,4);
            for(u32 j=0;j<8;j++){memcpy(out->texcoord[j],v->texcoord[j],3*sizeof(float));out->texcoord[j][3]=j==0 ? v->clip_z:1.0f;}
        }
    }
    s_stats.repack_ticks+=SDL_GetPerformanceCounter()-measured;
    frame_timing_leave(preparation);
    // Append to disjoint VBO ranges. Orphan before wrapping; never overwrite
    // storage referenced by an earlier draw and never wait for a fence.
    GLint previous_buffer;glGetIntegerv(GL_ARRAY_BUFFER_BINDING,&previous_buffer);
    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
    size_t bytes=(size_t)count*sizeof(HostVertex),base=0;
    if(!geometry && cache)geometry=geometry_store(content,raw,count);
    if(geometry)gBindBuffer(GL_ARRAY_BUFFER,geometry);
    else{
        if(!s_stream_buffer)gGenBuffers(1,&s_stream_buffer);gBindBuffer(GL_ARRAY_BUFFER,s_stream_buffer);
        if(!s_stream_capacity || s_stream_head+bytes>s_stream_capacity){
            if(s_stream_capacity<bytes || !s_stream_capacity)s_stream_capacity=bytes>16u*1024u*1024u ? bytes:16u*1024u*1024u;
            gBufferData(GL_ARRAY_BUFFER,(GLsizeiptr)s_stream_capacity,NULL,GL_STREAM_DRAW);s_stream_head=0;s_stats.orphans++;
        }
        base=s_stream_head;bool uploaded=false;
        void* mapped=streamMap && streamUnmap ? streamMap(GL_ARRAY_BUFFER,(GLintptr)base,(GLsizeiptr)bytes,GL_MAP_WRITE_BIT|GL_MAP_UNSYNCHRONIZED_BIT|GL_MAP_INVALIDATE_RANGE_BIT):NULL;
        if(mapped){memcpy(mapped,s_vertices,bytes);uploaded=streamUnmap(GL_ARRAY_BUFFER)!=GL_FALSE;
            if(!uploaded){gBufferData(GL_ARRAY_BUFFER,(GLsizeiptr)s_stream_capacity,NULL,GL_STREAM_DRAW);base=s_stream_head=0;s_stats.orphans++;}}
        if(!uploaded)gBufferSubData(GL_ARRAY_BUFFER,(GLintptr)base,(GLsizeiptr)bytes,s_vertices);
        s_stream_head+=bytes;s_stats.stream_bytes+=bytes;
    }
#define STREAM_FIELD(field) ((const GLvoid*)(uintptr_t)(base+offsetof(HostVertex,field)))
    glEnableClientState(GL_VERTEX_ARRAY);glVertexPointer(4,GL_FLOAT,sizeof(HostVertex),STREAM_FIELD(clip));
    if(raw){glEnableClientState(GL_NORMAL_ARRAY);glNormalPointer(GL_FLOAT,sizeof(HostVertex),STREAM_FIELD(normal));}
    glEnableClientState(GL_COLOR_ARRAY);glColorPointer(4,GL_UNSIGNED_BYTE,sizeof(HostVertex),STREAM_FIELD(color));
    for(u32 j=0;j<8;j++) {
        gClientActiveTexture(GL_TEXTURE0+j);glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(4,GL_FLOAT,sizeof(HostVertex),(const GLvoid*)(uintptr_t)(base+offsetof(HostVertex,texcoord)+j*4*sizeof(GLfloat)));
    }
#undef STREAM_FIELD
    glDrawArrays(types[(primitive-0x80)/8],0,(GLsizei)count);s_stats.draws++;
    glPopClientAttrib();gBindBuffer(GL_ARRAY_BUFFER,(GLuint)previous_buffer);
    gUseProgram((GLuint)program);gActiveTexture((GLenum)active);glPopAttrib();return true;
}
static bool gx_gl_draw_internal(SDL_Renderer* renderer,const GXGLMaterial* m,SDL_Texture* textures[8],const GXGLVertex* vertices,u32 stride,u32 count,u8 primitive,const GXGLRawVertex* raw,const GXGLTransform* xf,u64 validated_hash) {
    FrameStage previous=frame_timing_enter(FRAME_GL_SUBMIT);
    bool result=gx_gl_draw_internal_timed_body(renderer,m,textures,vertices,stride,count,primitive,raw,xf,validated_hash);
    frame_timing_leave(previous);return result;
}

bool gx_gl_draw(SDL_Renderer* renderer,const GXGLMaterial* material,SDL_Texture* textures[8],const GXGLVertex* vertices,u32 stride,u32 count,u8 primitive) {
    return gx_gl_draw_internal(renderer,material,textures,vertices,stride,count,primitive,NULL,NULL,0);
}
bool gx_gl_draw_raw(SDL_Renderer* renderer,const GXGLMaterial* material,SDL_Texture* textures[8],const GXGLRawVertex* vertices,const GXGLTransform* transform,u32 count,u8 primitive) {
    if(!transform || !vertices)return false;
    return gx_gl_draw_internal(renderer,material,textures,NULL,0,count,primitive,vertices,transform,0);
}
bool gx_gl_draw_raw_hashed(SDL_Renderer* renderer,const GXGLMaterial* material,SDL_Texture* textures[8],const GXGLRawVertex* vertices,const GXGLTransform* transform,u32 count,u8 primitive,u64 validated_hash) {
    if(!transform || !vertices)return false;
    return gx_gl_draw_internal(renderer,material,textures,NULL,0,count,primitive,vertices,transform,validated_hash);
}
int gx_gl_validate_xf(SDL_Renderer* renderer,const GXGLTransform* transform,const GXGLRawVertex* raw,const GXGLVertex* expected,u32 stride,u32 count) {
    if(!count || count>65536 || !raw || !expected || !transform || !gx_gl_xf_available(renderer))return 1;
#define TF_LOAD(name,type) type tf##name=(type)SDL_GL_GetProcAddress("gl" #name);if(!tf##name){fprintf(stderr,"[GPU XF validation] missing gl%s\n",#name);return 1;}
    TF_LOAD(TransformFeedbackVaryings,PFNGLTRANSFORMFEEDBACKVARYINGSPROC);
    TF_LOAD(BeginTransformFeedback,PFNGLBEGINTRANSFORMFEEDBACKPROC);TF_LOAD(EndTransformFeedback,PFNGLENDTRANSFORMFEEDBACKPROC);
    TF_LOAD(BindBufferBase,PFNGLBINDBUFFERBASEPROC);TF_LOAD(GenBuffers,PFNGLGENBUFFERSPROC);TF_LOAD(DeleteBuffers,PFNGLDELETEBUFFERSPROC);
    TF_LOAD(BufferData,PFNGLBUFFERDATAPROC);TF_LOAD(GetBufferSubData,PFNGLGETBUFFERSUBDATAPROC);
#undef TF_LOAD
    GLuint vs=compile_shader(GL_VERTEX_SHADER,vertex_xf_source),fs=compile_shader(GL_FRAGMENT_SHADER,fragment_source);
    if(!vs || !fs){if(vs)gDeleteShader(vs);if(fs)gDeleteShader(fs);return 1;}
    GLuint program=gCreateProgram();gAttachShader(program,vs);gAttachShader(program,fs);
    const GLchar* varyings[]={"gl_Position","depthZW","raster","tc"};tfTransformFeedbackVaryings(program,4,varyings,GL_INTERLEAVED_ATTRIBS);gLinkProgram(program);
    gDeleteShader(vs);gDeleteShader(fs);GLint ok=0;gGetProgramiv(program,GL_LINK_STATUS,&ok);
    if(!ok){char log[4096];gGetProgramInfoLog(program,sizeof(log),NULL,log);fprintf(stderr,"[GPU XF feedback link] %s\n",log);gDeleteProgram(program);return 1;}
    HostVertex* input=malloc((size_t)count*sizeof(*input));GLfloat* output=malloc((size_t)count*34u*sizeof(float));
    if(!input || !output){free(input);free(output);gDeleteProgram(program);return 1;}
    for(u32 i=0;i<count;i++){
        HostVertex* out=input+i;const GXGLRawVertex* v=raw+i;
        memcpy(out->clip,v->position,3*sizeof(float));out->clip[3]=(float)v->matrix;memcpy(out->normal,v->normal,3*sizeof(float));memcpy(out->color,v->color,4);
        for(u32 j=0;j<8;j++){memcpy(out->texcoord[j],v->texcoord[j],3*sizeof(float));out->texcoord[j][3]=(float)v->tex_matrix[j];}
    }
    SDL_RenderFlush(renderer);GLint previous_program,previous_array,previous_feedback;
    glGetIntegerv(GL_CURRENT_PROGRAM,&previous_program);glGetIntegerv(GL_ARRAY_BUFFER_BINDING,&previous_array);glGetIntegerv(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,&previous_feedback);
    GLboolean previous_discard=glIsEnabled(GL_RASTERIZER_DISCARD);
    glPushAttrib(GL_ALL_ATTRIB_BITS);glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
    GLuint buffer;tfGenBuffers(1,&buffer);gBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER,buffer);tfBufferData(GL_TRANSFORM_FEEDBACK_BUFFER,(GLsizeiptr)((size_t)count*34u*sizeof(float)),NULL,GL_STREAM_READ);
    tfBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER,0,buffer);gBindBuffer(GL_ARRAY_BUFFER,0);gUseProgram(program);
    XFUniforms saved=s_xf_u;s_xf_u=find_xf_uniforms(program);upload_xf(transform,false);s_xf_u=saved;
    glEnableClientState(GL_VERTEX_ARRAY);glVertexPointer(4,GL_FLOAT,sizeof(HostVertex),input[0].clip);
    glEnableClientState(GL_NORMAL_ARRAY);glNormalPointer(GL_FLOAT,sizeof(HostVertex),input[0].normal);
    glEnableClientState(GL_COLOR_ARRAY);glColorPointer(4,GL_UNSIGNED_BYTE,sizeof(HostVertex),input[0].color);
    for(u32 j=0;j<8;j++){gClientActiveTexture(GL_TEXTURE0+j);glEnableClientState(GL_TEXTURE_COORD_ARRAY);glTexCoordPointer(4,GL_FLOAT,sizeof(HostVertex),input[0].texcoord[j]);}
    for(u32 drain=0;drain<16 && glGetError()!=GL_NO_ERROR;drain++){}
    glEnable(GL_RASTERIZER_DISCARD);tfBeginTransformFeedback(GL_POINTS);glDrawArrays(GL_POINTS,0,(GLsizei)count);tfEndTransformFeedback();
    GLenum error=glGetError();tfGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER,0,(GLsizeiptr)((size_t)count*34u*sizeof(float)),output);
    int result=error!=GL_NO_ERROR;float max_position=0,max_texture=0,max_color=0;
    for(u32 i=0;i<count && !result;i++){
        const GXGLVertex* v=(const GXGLVertex*)((const u8*)expected+(size_t)i*stride);float reference[34];
        reference[0]=v->x/320.0f-v->w;reference[1]=v->y/264.0f-v->w;reference[2]=0;reference[3]=v->w;
        reference[4]=(v->z*2.0f-1.0f)*v->w;reference[5]=v->w;
        for(u32 c=0;c<4;c++)reference[6+c]=(float)v->color[c];memcpy(reference+10,v->texcoord,24*sizeof(float));
        for(u32 j=0;j<34;j++){
            float a=reference[j],b=output[i*34+j];if(a==b || (isnan(a) && isnan(b)))continue;
            float difference=fabsf(a-b),tolerance=j>=6 && j<10 ? 1.0f:0.0001f*fmaxf(1.0f,fabsf(a));
            if(j<6){if(difference>max_position)max_position=difference;}else if(j<10){if(difference>max_color)max_color=difference;}else if(difference>max_texture)max_texture=difference;
            if(!isfinite(difference) || difference>tolerance){fprintf(stderr,"[GPU XF feedback] vertex=%u component=%u CPU=%.9g GPU=%.9g delta=%.9g\n",i,j,a,b,difference);result=1;break;}
        }
    }
    tfBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER,0,0);gBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER,(GLuint)previous_feedback);tfDeleteBuffers(1,&buffer);
    glPopClientAttrib();gBindBuffer(GL_ARRAY_BUFFER,(GLuint)previous_array);gUseProgram((GLuint)previous_program);glPopAttrib();
    if(previous_discard)glEnable(GL_RASTERIZER_DISCARD);else glDisable(GL_RASTERIZER_DISCARD);
    free(input);free(output);gDeleteProgram(program);
    printf("[GPU XF feedback] %u vertices; max position=%g texture=%g raster=%g GL=%04X result=%d\n",count,max_position,max_texture,max_color,error,result);return result;
}
void gx_gl_clear_depth(SDL_Renderer* renderer,int x,int y,int w,int h,u32 value) {
    if(!gx_gl_available(renderer))return;
    SDL_RenderFlush(renderer);ensure_depth();glPushAttrib(GL_DEPTH_BUFFER_BIT|GL_SCISSOR_BIT);
    glEnable(GL_SCISSOR_TEST);glScissor(x,y,w,h);glDepthMask(GL_TRUE);glClearDepth((double)(value&0xFFFFFFu)/16777215.0);glClear(GL_DEPTH_BUFFER_BIT);glPopAttrib();
}
static bool copy_procs_available(void){
    if(!s_copy_procs_checked){
        s_copy_procs_checked=true;
        copyGen=(PFNGLGENFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glGenFramebuffers");copyBind=(PFNGLBINDFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBindFramebuffer");
        copyAttach=(PFNGLFRAMEBUFFERTEXTURE2DPROC)SDL_GL_GetProcAddress("glFramebufferTexture2D");copyCheck=(PFNGLCHECKFRAMEBUFFERSTATUSPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatus");
        copyBlit=(PFNGLBLITFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBlitFramebuffer");copyDelete=(PFNGLDELETEFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteFramebuffers");
    }
    if(!copyGen || !copyBind || !copyAttach || !copyCheck || !copyBlit || !copyDelete)return false;
return true;
}
bool gx_gl_copy_color(SDL_Renderer* renderer,SDL_Texture* destination,const SDL_Rect* source) {
    if(!source || !destination || source->x<0 || source->y<0 || source->w<=0 || source->h<=0 || !gx_gl_available(renderer))return false;
    SDL_Texture* origin=SDL_GetRenderTarget(renderer);int sw,sh,dw,dh;
    if(!origin || origin==destination || SDL_QueryTexture(origin,NULL,NULL,&sw,&sh)!=0 || SDL_QueryTexture(destination,NULL,NULL,&dw,&dh)!=0 ||
       dw!=source->w || dh!=source->h || source->x>sw-dw || source->y>sh-dh)return false;
    if(!copy_procs_available())return false;
    SDL_RenderFlush(renderer);GLint read_fbo,draw_fbo,texture,active;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING,&read_fbo);glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING,&draw_fbo);
    glGetIntegerv(GL_ACTIVE_TEXTURE,&active);gActiveTexture(GL_TEXTURE0);glGetIntegerv(GL_TEXTURE_BINDING_2D,&texture);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    float u=1,v=1;if(SDL_GL_BindTexture(destination,&u,&v)!=0){glPopAttrib();gActiveTexture((GLenum)active);return false;}
    GLint image;glGetIntegerv(GL_TEXTURE_BINDING_2D,&image);bool copied=false;
    if(u==1.0f && v==1.0f){
        if(!s_copy_fbo)copyGen(1,&s_copy_fbo);
        glDisable(GL_SCISSOR_TEST);
        copyBind(GL_DRAW_FRAMEBUFFER,s_copy_fbo);copyAttach(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,(GLuint)image,0);glDrawBuffer(GL_COLOR_ATTACHMENT0);
        if(copyCheck(GL_DRAW_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE){
            copyBind(GL_READ_FRAMEBUFFER,(GLuint)draw_fbo);glReadBuffer(GL_COLOR_ATTACHMENT0);
            // SDL render targets use the same logical row order as decoded
            // static textures. No CPU flip or intermediate pixel buffer.
            copyBlit(source->x,source->y,source->x+dw,source->y+dh,0,0,dw,dh,GL_COLOR_BUFFER_BIT,GL_NEAREST);copied=true;s_stats.vram_copies++;
        }
        copyAttach(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,0,0);
        copyBind(GL_READ_FRAMEBUFFER,(GLuint)read_fbo);copyBind(GL_DRAW_FRAMEBUFFER,(GLuint)draw_fbo);
    }
    SDL_GL_UnbindTexture(destination);glBindTexture(GL_TEXTURE_2D,(GLuint)texture);glPopAttrib();gActiveTexture((GLenum)active);return copied;
}
bool gx_gl_copy_texture(SDL_Renderer* renderer,SDL_Texture* destination,const SDL_Rect* source,u32 format,u32 step,bool luma){
    if(format==6 && step==1)return gx_gl_copy_color(renderer,destination,source);
    if(!source || !destination || format>12 || (step!=1 && step!=2) || source->x<0 || source->y<0 || source->w<=0 || source->h<=0 || !gx_gl_available(renderer) || !copy_procs_available())return false;
    SDL_Texture* origin=SDL_GetRenderTarget(renderer);int sw,sh,dw,dh;
    if(!origin || origin==destination || SDL_QueryTexture(origin,NULL,NULL,&sw,&sh)!=0 || SDL_QueryTexture(destination,NULL,NULL,&dw,&dh)!=0 ||
       dw!=source->w/(int)step || dh!=source->h/(int)step || source->x>sw-source->w || source->y>sh-source->h)return false;
    if(!s_copy_program){
        if(s_copy_init<0)return false;s_copy_init=-1;
        static const char* vertex="#version 120\nvoid main(){gl_Position=gl_Vertex;}";
        static const char* fragment="#version 120\n" GLSL(
            uniform sampler2D efb;uniform vec4 sourceRect,copyInfo,imageScale;
            vec4 pixel(vec2 p){return floor(texture2D(efb,p*imageScale.xy)*255.0+0.5);}
            void main(){
                vec2 p=sourceRect.xy+floor(gl_FragCoord.xy)*copyInfo.x+vec2(0.5);vec4 c=pixel(p);
                if(copyInfo.x==2.0)c=floor((c+pixel(p+vec2(1.0,0.0))+pixel(p+vec2(0.0,1.0))+pixel(p+vec2(1.0,1.0)))/4.0);
                float intensity=copyInfo.z!=0.0 ? min(255.0,floor((dot(c.rgb,vec3(66.0,129.0,25.0))+128.0)/256.0)+16.0):c.r;
                float f=copyInfo.y;vec4 result=c;
                if(f==0.0)result=vec4(floor(intensity/16.0)*17.0);
                else if(f==1.0 || f==8.0)result=vec4(intensity);
                else if(f==2.0)result=vec4(vec3(floor(intensity/16.0)*17.0),floor(c.a/16.0)*17.0);
                else if(f==3.0)result=vec4(vec3(intensity),c.a);
                else if(f==4.0)result=vec4(floor(floor(c.rgb/vec3(8.0,4.0,8.0))*255.0/vec3(31.0,63.0,31.0)),255.0);
                else if(f==5.0){if(c.a>=224.0)result=vec4(floor(floor(c.rgb/8.0)*255.0/31.0),255.0);else result=vec4(floor(c.rgb/16.0)*17.0,floor(floor(c.a/32.0)*255.0/7.0));}
                else if(f==7.0)result=vec4(c.a);else if(f==9.0)result=vec4(c.g);else if(f==10.0)result=vec4(c.b);
                else if(f==11.0)result=vec4(vec3(c.r),c.g);else if(f==12.0)result=vec4(vec3(c.g),c.b);
                gl_FragColor=result/255.0;
            }
        );
        GLuint vs=compile_shader(GL_VERTEX_SHADER,vertex),fs=compile_shader(GL_FRAGMENT_SHADER,fragment);
        if(!vs || !fs){if(vs)gDeleteShader(vs);if(fs)gDeleteShader(fs);return false;}
        s_copy_program=gCreateProgram();gAttachShader(s_copy_program,vs);gAttachShader(s_copy_program,fs);gLinkProgram(s_copy_program);gDeleteShader(vs);gDeleteShader(fs);
        GLint ok;gGetProgramiv(s_copy_program,GL_LINK_STATUS,&ok);if(!ok){gDeleteProgram(s_copy_program);s_copy_program=0;return false;}
        s_copy_sampler=uniform_location(s_copy_program,"efb");s_copy_rect=uniform_location(s_copy_program,"sourceRect");s_copy_info=uniform_location(s_copy_program,"copyInfo");s_copy_scale=uniform_location(s_copy_program,"imageScale");s_copy_init=1;
    }
    SDL_RenderFlush(renderer);GLint read_fbo,draw_fbo,active,texture,program;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING,&read_fbo);glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING,&draw_fbo);glGetIntegerv(GL_CURRENT_PROGRAM,&program);
    glGetIntegerv(GL_ACTIVE_TEXTURE,&active);gActiveTexture(GL_TEXTURE0);glGetIntegerv(GL_TEXTURE_BINDING_2D,&texture);glPushAttrib(GL_ALL_ATTRIB_BITS);
    float u=1,v=1;bool copied=false;
    if(SDL_GL_BindTexture(destination,&u,&v)==0){
        GLint image;glGetIntegerv(GL_TEXTURE_BINDING_2D,&image);SDL_GL_UnbindTexture(destination);
        if(u==1.0f && v==1.0f && SDL_GL_BindTexture(origin,&u,&v)==0){
            GLint min_filter,mag_filter;glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,&min_filter);glGetTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,&mag_filter);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            if(!s_copy_fbo)copyGen(1,&s_copy_fbo);copyBind(GL_DRAW_FRAMEBUFFER,s_copy_fbo);copyAttach(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,(GLuint)image,0);glDrawBuffer(GL_COLOR_ATTACHMENT0);
            if(copyCheck(GL_DRAW_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE){
                glViewport(0,0,dw,dh);glDisable(GL_BLEND);glDisable(GL_DEPTH_TEST);glDisable(GL_SCISSOR_TEST);glDisable(GL_ALPHA_TEST);glDisable(GL_STENCIL_TEST);glDisable(GL_CULL_FACE);glDisable(GL_COLOR_LOGIC_OP);glDisable(GL_DITHER);glDisable(GL_CLIP_PLANE0);glDisable(GL_CLIP_PLANE1);glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
                GLfloat rect[4]={(float)source->x,(float)source->y,(float)source->w,(float)source->h},info[4]={(float)step,(float)format,luma ? 1.0f:0.0f,0},scale[4]={u/sw,v/sh,0,0};
                gUseProgram(s_copy_program);gUniform1i(s_copy_sampler,0);gUniform4fv(s_copy_rect,1,rect);gUniform4fv(s_copy_info,1,info);gUniform4fv(s_copy_scale,1,scale);
                glBegin(GL_TRIANGLE_STRIP);glVertex2f(-1,-1);glVertex2f(1,-1);glVertex2f(-1,1);glVertex2f(1,1);glEnd();copied=true;s_stats.vram_copies++;
            }
            copyAttach(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,0,0);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,min_filter);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,mag_filter);SDL_GL_UnbindTexture(origin);
        }
    }
    copyBind(GL_READ_FRAMEBUFFER,(GLuint)read_fbo);copyBind(GL_DRAW_FRAMEBUFFER,(GLuint)draw_fbo);gUseProgram((GLuint)program);glBindTexture(GL_TEXTURE_2D,(GLuint)texture);glPopAttrib();gActiveTexture((GLenum)active);return copied;
}
bool gx_gl_pack_yuy2(SDL_Renderer* renderer,SDL_Texture* efb,const SDL_Rect* source,u32 output_height,u8* output,u32 pitch) {
    int image_w=0,image_h=0;
    if(efb)SDL_QueryTexture(efb,NULL,NULL,&image_w,&image_h);
    if(!gx_gl_available(renderer) || !efb || !source || !output || !output_height || output_height>576 ||
       source->x<0 || source->y<0 || source->w<=0 || source->h<=0 || source->x+source->w>image_w || source->y+source->h>image_h ||
       (source->w&1) || pitch<(u32)source->w*2u)return false;
    if(!s_pack_program) {
        static const char* vertex="#version 120\nvoid main(){gl_Position=gl_Vertex;}";
        static const char* fragment="#version 120\n" GLSL(
            uniform sampler2D efb;
            uniform vec4 sourceRect;
            uniform vec4 copyScale;
            void main() {
                float col=floor(gl_FragCoord.x)*2.0;
                float row=floor(floor(gl_FragCoord.y)*sourceRect.w/copyScale.z);
                vec2 p=sourceRect.xy+vec2(col+0.5,row+0.5);
                vec3 a=floor(texture2D(efb,p*copyScale.xy).rgb*255.0+0.5);
                vec3 b=floor(texture2D(efb,(p+vec2(1.0,0.0))*copyScale.xy).rgb*255.0+0.5);
                vec3 average=floor((a+b)*0.5);
                float y0=floor((dot(a,vec3(66.0,129.0,25.0))+128.0)/256.0)+16.0;
                float y1=floor((dot(b,vec3(66.0,129.0,25.0))+128.0)/256.0)+16.0;
                float u=floor((dot(average,vec3(-38.0,-74.0,112.0))+128.0)/256.0)+128.0;
                float v=floor((dot(average,vec3(112.0,-94.0,-18.0))+128.0)/256.0)+128.0;
                gl_FragColor=clamp(vec4(y0,u,y1,v),0.0,255.0)/255.0;
            }
        );
        GLuint vs=compile_shader(GL_VERTEX_SHADER,vertex),fs=compile_shader(GL_FRAGMENT_SHADER,fragment);
        if(!vs || !fs){if(vs)gDeleteShader(vs);if(fs)gDeleteShader(fs);return false;}
        s_pack_program=gCreateProgram();gAttachShader(s_pack_program,vs);gAttachShader(s_pack_program,fs);gLinkProgram(s_pack_program);
        gDeleteShader(vs);gDeleteShader(fs);GLint ok;gGetProgramiv(s_pack_program,GL_LINK_STATUS,&ok);
        if(!ok){gDeleteProgram(s_pack_program);s_pack_program=0;return false;}
        s_pack_efb=uniform_location(s_pack_program,"efb");s_pack_rect=uniform_location(s_pack_program,"sourceRect");s_pack_scale=uniform_location(s_pack_program,"copyScale");s_pack_init=1;
    }
    u32 width=(u32)source->w/2;
    if(!s_pack_target || s_pack_width!=width || s_pack_height!=output_height) {
        if(s_pack_target)SDL_DestroyTexture(s_pack_target);
        s_pack_target=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,(int)width,(int)output_height);
        s_pack_width=width;s_pack_height=output_height;
        if(!s_pack_target)return false;
    }
    SDL_Texture* previous=SDL_GetRenderTarget(renderer);SDL_RenderFlush(renderer);
    if(SDL_SetRenderTarget(renderer,s_pack_target)!=0)return false;
    SDL_RenderFlush(renderer);GLint program,active;
    glGetIntegerv(GL_CURRENT_PROGRAM,&program);glGetIntegerv(GL_ACTIVE_TEXTURE,&active);glPushAttrib(GL_ALL_ATTRIB_BITS);
    gActiveTexture(GL_TEXTURE0);float tex_w=1,tex_h=1;
    bool bound=SDL_GL_BindTexture(efb,&tex_w,&tex_h)==0,ok=false;
    if(bound) {
        glViewport(0,0,(GLsizei)width,(GLsizei)output_height);
        glDisable(GL_BLEND);glDisable(GL_DEPTH_TEST);glDisable(GL_ALPHA_TEST);glDisable(GL_STENCIL_TEST);
        glDisable(GL_SCISSOR_TEST);glDisable(GL_CULL_FACE);glDisable(GL_COLOR_LOGIC_OP);glDisable(GL_DITHER);
        glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        gUseProgram(s_pack_program);gUniform1i(s_pack_efb,0);
        GLfloat rect[4]={(float)source->x,(float)source->y,(float)source->w,(float)source->h};
        GLfloat scale[4]={tex_w/(float)image_w,tex_h/(float)image_h,(float)output_height,0};
        gUniform4fv(s_pack_rect,1,rect);gUniform4fv(s_pack_scale,1,scale);
        glBegin(GL_TRIANGLE_STRIP);glVertex2f(-1,-1);glVertex2f(1,-1);glVertex2f(-1,1);glVertex2f(1,1);glEnd();
        ok=SDL_RenderReadPixels(renderer,NULL,SDL_PIXELFORMAT_RGBA32,output,(int)pitch)==0;
        SDL_GL_UnbindTexture(efb);
    }
    gUseProgram((GLuint)program);gActiveTexture((GLenum)active);glPopAttrib();SDL_SetRenderTarget(renderer,previous);
    return ok;
}
void gx_gl_shutdown(void) {
    for(u32 i=0;i<128;i++)geometry_evict(i);memset(s_geometry_candidates,0,sizeof(s_geometry_candidates));s_geometry_serial=0;
    if(s_copy_program && gDeleteProgram)gDeleteProgram(s_copy_program);s_copy_program=0;s_copy_init=0;
    if(s_copy_fbo && copyDelete)copyDelete(1,&s_copy_fbo);s_copy_fbo=0;s_copy_procs_checked=false;
    if(s_stream_buffer && gDeleteBuffers)gDeleteBuffers(1,&s_stream_buffer);s_stream_buffer=0;s_stream_head=s_stream_capacity=0;
    if(s_pack_target)SDL_DestroyTexture(s_pack_target);s_pack_target=NULL;s_pack_width=s_pack_height=0;
    if(s_pack_program && gDeleteProgram)gDeleteProgram(s_pack_program);s_pack_program=0;s_pack_init=0;
    if(s_depth && gDeleteRenderbuffers)gDeleteRenderbuffers(1,&s_depth);
    if(s_program && gDeleteProgram)gDeleteProgram(s_program);
    if(s_xf_program && gDeleteProgram)gDeleteProgram(s_xf_program);s_xf_program=0;s_xf_init=0;s_xf_values_valid=false;
    free(s_vertices);s_vertices=NULL;s_vertex_capacity=0;
    s_program=s_depth=s_depth_fbo=0;s_init=0;
}
