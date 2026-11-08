/* One GL owner, two immutable command arenas. No per-draw worker or guest CPU
 * execution on the consumer. Producer register/vertex state stays on CPU. */
enum {FRAME_DRAW=1,FRAME_COPY,FRAME_PRESENT,FRAME_RESOLVE,FRAME_CLEAR};
typedef struct {u32 type,bytes;} FrameOp;
typedef struct {u32 target,offset,bytes,data;} FrameRange;
typedef struct {
    FrameOp op;u32 draws,vertices,raw,transforms,gpu,hashes,ranges;
    u32 draw_count,vertex_count,range_count;
} FrameDraw;
typedef struct {FrameOp op;u32 bp[256],control,display,real_ram,seed_bytes;u8 seed[2048];} FrameCopy;
typedef struct {FrameOp op;VideoXFB image;u32 pixels,bytes;} FramePresent;
typedef struct {FrameOp op;u32 address,bytes;} FrameResolve;
typedef struct {FrameOp op;SDL_Rect region;u32 ar,gb,z;} FrameClear;
static struct {
    CPUState cpu;u8* shadow;u8 palette[512*1024];u8* real_ram;
    u32 i4[64],i4_count;VideoXFB xfb[8];u32 xfb_count;
    u64 draw_ticks,copy_ticks,swap_ticks;
} frame_backend;
static u32 frame_align(u32 n){return (n+15u)&~15u;}
static void frame_mirrors(void){
    frame_backend.i4_count=frame_backend.xfb_count=0;
    for(u32 i=0;i<s_tex_cache_count && frame_backend.i4_count<64;i++)if(s_tex_cache[i].vram_only)frame_backend.i4[frame_backend.i4_count++]=s_tex_cache[i].gc_addr;
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].pending && s_xfb_images[i].image){XFBImage* x=s_xfb_images+i;frame_backend.xfb[frame_backend.xfb_count++]=(VideoXFB){x->address,x->width,x->height,x->pitch};}
}
static bool frame_queue_barrier(void){return !gx_frame_active() || gx_frame_drain();}
static bool frame_backend_ensure(void){
    if(s_efb)return true;
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);
    s_efb=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,640,528);
    if(!s_efb)return false;
    SDL_SetRenderTarget(s_renderer,s_efb);SDL_SetRenderDrawColor(s_renderer,0,0,0,255);SDL_RenderClear(s_renderer);SDL_SetRenderTarget(s_renderer,previous);return true;
}
static bool frame_resource(FrameRange* ranges,u32* count,u32 target,u32 offset,u32 bytes){
    for(u32 i=0;i<*count;i++)if(ranges[i].target==target && ranges[i].offset==offset && ranges[i].bytes==bytes)return true;
    if(*count==1024)return false;ranges[(*count)++]=(FrameRange){target,offset,bytes,0};return true;
}
static bool frame_resolve(CPUState* cpu,u32 address,u32 bytes){
    if(!gx_frame_drain())return false;
    FrameResolve* op=gx_frame_alloc(sizeof(*op));if(!op)return false;
    *op=(FrameResolve){{FRAME_RESOLVE,frame_align(sizeof(*op))},address,bytes};
    if(!gx_frame_drain())return false;frame_mirrors();(void)cpu;return true;
}
static bool frame_queue_draws(CPUState* cpu){
    if(!s_queued_draw_count)return true;
    FrameRange ranges[1024];u32 range_count=0;
    static const u8 tw[15]={8,8,8,4,4,4,4,0,8,8,4,0,0,0,8};
    static const u8 th[15]={8,4,4,4,4,4,4,0,8,4,4,0,0,0,8};
    for(u32 d=0;d<s_queued_draw_count;d++){
        const u32* bp=s_queued_draws[d].material.bp;u32 units=0;
        for(u32 stage=0;stage<((bp[0]>>10)&15u)+1;stage++){u32 order=bp[0x28+stage/2]>>((stage&1)*12);if(order&64u)units|=1u<<(order&7u);}
        for(u32 u=0;u<8;u++)if(units&(1u<<u)){
            u32 base=u<4 ? 0x80:0xA0,n=u&3,image=bp[base+8+n],address=bp[base+20+n]<<5,fmt=(image>>20)&15u;
            u32 w=(image&1023u)+1,h=((image>>10)&1023u)+1;if(!bp[base+20+n] || fmt>=15 || !tw[fmt])continue;
            u32 bytes=((w+tw[fmt]-1)/tw[fmt])*((h+th[fmt]-1)/th[fmt])*(fmt==6 ? 64u:32u);
            if(address>cpu->ram_size || bytes>cpu->ram_size-address)continue;
            for(u32 i=0;i<frame_backend.i4_count;i++){
                u32 v=frame_backend.i4[i]-GC_RAM_BASE;
                if((u64)address+bytes>v && (u64)v+2048>address && !(address==v && fmt==0 && w==64 && h==64)){
                    if(!frame_resolve(cpu,address|GC_RAM_BASE,bytes))return false;break;
                }
            }
            if(!frame_resource(ranges,&range_count,0,address,bytes))return false;
            u32 palette_bytes=fmt==8 ? 32u:fmt==9 ? 512u:fmt==10 ? 32768u:0,offset=(bp[base+24+n]&1023u)<<9;
            if(palette_bytes && offset<=sizeof(s_tlut_memory) && palette_bytes<=sizeof(s_tlut_memory)-offset)
                if(!frame_resource(ranges,&range_count,1,offset,palette_bytes))return false;
        }
    }
    u64 bytes=frame_align(sizeof(FrameDraw));
    u32 draws=(u32)bytes;bytes+=frame_align(s_queued_draw_count*sizeof(QueuedDraw));
    u32 vertices=(u32)bytes;bytes+=frame_align(s_queued_vtx_count*sizeof(QueuedVertex));
    u32 raw=(u32)bytes;bytes+=frame_align(s_queued_vtx_count*sizeof(GXGLRawVertex));
    u32 transforms=(u32)bytes;bytes+=frame_align(s_queued_draw_count*sizeof(GXGLTransform));
    u32 gpu=(u32)bytes;bytes+=frame_align(s_queued_draw_count*sizeof(bool));
    u32 hashes=(u32)bytes;bytes+=frame_align(s_queued_draw_count*sizeof(u64));
    u32 resources=(u32)bytes;bytes+=frame_align(range_count*sizeof(FrameRange));
    for(u32 i=0;i<range_count;i++){ranges[i].data=(u32)bytes;bytes+=frame_align(ranges[i].bytes);}
    if(bytes>64u*1024u*1024u-16)return false;
    FrameDraw* op=gx_frame_alloc((u32)bytes);if(!op)return false;
    *op=(FrameDraw){{FRAME_DRAW,(u32)bytes},draws,vertices,raw,transforms,gpu,hashes,resources,s_queued_draw_count,s_queued_vtx_count,range_count};u8* p=(u8*)op;
    memcpy(p+draws,s_queued_draws,s_queued_draw_count*sizeof(QueuedDraw));memcpy(p+vertices,s_queued_vertices,s_queued_vtx_count*sizeof(QueuedVertex));
    memcpy(p+raw,s_raw_vertices,s_queued_vtx_count*sizeof(GXGLRawVertex));memcpy(p+transforms,s_gpu_transforms,s_queued_draw_count*sizeof(GXGLTransform));
    memcpy(p+gpu,s_gpu_draws,s_queued_draw_count*sizeof(bool));memcpy(p+hashes,s_gpu_raw_hash,s_queued_draw_count*sizeof(u64));memcpy(p+resources,ranges,range_count*sizeof(FrameRange));
    for(u32 i=0;i<range_count;i++)memcpy(p+ranges[i].data,(ranges[i].target ? s_tlut_memory:cpu->ram)+ranges[i].offset,ranges[i].bytes);
    s_queued_draw_count=s_queued_vtx_count=0;return true;
}
static bool frame_queue_copy(CPUState* cpu,u32 control,bool display){
    if(!frame_queue_draws(cpu))return false;
    u32 dest=s_bp[0x4B]<<5,w=(s_bp[0x4A]&1023u)+1,h=((s_bp[0x4A]>>10)&1023u)+1,pitch=(s_bp[0x4D]&1023u)<<5;
    u32 scale=s_bp[0x4E]&511u,out_h=(control&0x400u) && scale ? 1u+((h-1u)*256u)/scale:1u+((h-1u)*scale)/256u;
    bool known=false;
    if(display && s_xfb_vram){for(u32 i=0;i<frame_backend.xfb_count;i++){VideoXFB* x=frame_backend.xfb+i;if(x->address==(dest|GC_RAM_BASE) && x->width==w && x->height==out_h && x->pitch==pitch)known=true;}}
    u32 fmt=(control>>3)&15u;fmt=(fmt>>1)|((fmt&1u)<<3);
    if(!display && s_vram_only_enabled && fmt==0 && !(control&512u) && w==64 && h==64 && pitch==256){
        for(u32 i=0;i<frame_backend.i4_count;i++)if(frame_backend.i4[i]==(dest|GC_RAM_BASE))known=true;
        for(u32 i=0;i<frame_backend.i4_count;i++)if(frame_backend.i4[i]!=(dest|GC_RAM_BASE) && (u64)dest+2048>frame_backend.i4[i]-GC_RAM_BASE && (u64)(frame_backend.i4[i]-GC_RAM_BASE)+2048>dest)known=false;
    }
    FrameCopy* op=gx_frame_alloc(sizeof(*op));if(!op)return false;
    op->op=(FrameOp){FRAME_COPY,frame_align(sizeof(*op))};memcpy(op->bp,s_bp,sizeof(s_bp));op->control=control;op->display=display;op->real_ram=!known;op->seed_bytes=0;
    if(!display && dest<=cpu->ram_size && 2048u<=cpu->ram_size-dest){op->seed_bytes=2048;memcpy(op->seed,cpu->ram+dest,2048);}
    if(display)video_configure_xfb(dest|GC_RAM_BASE,w,out_h,pitch);
    if(!gx_frame_submit(!known))return false;
    if(!known)frame_mirrors();return true;
}
static bool frame_queue_clear(const SDL_Rect* region,u32 ar,u32 gb,u32 z){
    FrameClear* op=gx_frame_alloc(sizeof(*op));if(!op)return false;*op=(FrameClear){{FRAME_CLEAR,frame_align(sizeof(*op))},*region,ar,gb,z};return true;
}
static bool frame_execute(const u8* data,u32 bytes,void* ignored){
    (void)ignored;CPUState cpu=frame_backend.cpu;cpu.ram=frame_backend.shadow;s_backend_palette=frame_backend.palette;
    for(u32 at=0;at<bytes;){
        const FrameOp* header=(const FrameOp*)(data+at);if(header->bytes<sizeof(*header) || header->bytes>bytes-at)return false;
        if(header->type==FRAME_DRAW){
            u64 started=SDL_GetPerformanceCounter();
            const FrameDraw* op=(const FrameDraw*)header;const u8* p=(const u8*)op;const FrameRange* r=(const FrameRange*)(p+op->ranges);
            for(u32 i=0;i<op->range_count;i++)memcpy((r[i].target ? frame_backend.palette:cpu.ram)+r[i].offset,p+r[i].data,r[i].bytes);
            GXRenderView view={(QueuedDraw*)(p+op->draws),(QueuedVertex*)(p+op->vertices),(GXGLRawVertex*)(p+op->raw),(GXGLTransform*)(p+op->transforms),(bool*)(p+op->gpu),(u64*)(p+op->hashes),op->draw_count,op->vertex_count};
            if(!frame_backend_ensure())return false;SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);
            gx_pipe_render_to_sdl_timed_body(s_renderer,&cpu,0,0,640,480,&view);SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,previous);
            frame_backend.draw_ticks+=SDL_GetPerformanceCounter()-started;
        }else if(header->type==FRAME_COPY){
            const FrameCopy* op=(const FrameCopy*)header;CPUState copy=cpu;if(op->real_ram)copy.ram=frame_backend.real_ram;
            u32 dest=op->bp[0x4B]<<5;if(!op->real_ram && op->seed_bytes)memcpy(copy.ram+dest,op->seed,op->seed_bytes);
            s_backend_bp=op->bp;u64 before=op->display ? s_xfb_gpu_copies:s_vram_only_copies,start=SDL_GetPerformanceCounter();
            bool ok=op->display ? copy_efb_timed_body(&copy,op->control):copy_efb_texture_timed_body(&copy,op->control);
            if(!op->display)s_texture_copy_ticks+=SDL_GetPerformanceCounter()-start;
            frame_backend.copy_ticks+=SDL_GetPerformanceCounter()-start;
            s_backend_bp=NULL;if(!ok || (!op->real_ram && before==(op->display ? s_xfb_gpu_copies:s_vram_only_copies)))return false;
        }else if(header->type==FRAME_PRESENT){
            const FramePresent* op=(const FramePresent*)header;
            if(op->bytes)memcpy(cpu.ram+op->image.address-GC_RAM_BASE,(const u8*)op+op->pixels,op->bytes);
            SDL_SetRenderTarget(s_renderer,NULL);SDL_SetRenderDrawColor(s_renderer,0,0,0,255);SDL_RenderClear(s_renderer);
            int w,h;SDL_GetRendererOutputSize(s_renderer,&w,&h);video_present_snapshot(s_renderer,&cpu,w,h,&op->image);
            u64 started=SDL_GetPerformanceCounter();SDL_RenderPresent(s_renderer);frame_backend.swap_ticks+=SDL_GetPerformanceCounter()-started;
        }else if(header->type==FRAME_RESOLVE){
            const FrameResolve* op=(const FrameResolve*)header;CPUState real=cpu;real.ram=frame_backend.real_ram;if(!resolve_vram_overlap(&real,op->address,op->bytes,false))return false;
        }else if(header->type==FRAME_CLEAR){
            const FrameClear* op=(const FrameClear*)header;if(!frame_backend_ensure())return false;SDL_Texture* old=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);clear_efb_region(&op->region,op->ar,op->gb,op->z);SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,old);
        }else return false;
        at+=header->bytes;
    }
    s_backend_palette=NULL;return true;
}
static void frame_report(GXFrameStats* r){
    gx_gl_get_stats(&r->gl);r->render=s_render_ticks;r->copy=s_copy_ticks;r->texture_copy=s_texture_copy_ticks;r->uploads=s_texture_uploads;
    r->texture_hits=s_tex_hits;r->hash_bytes=s_tex_hash_bytes;r->readbacks=s_texture_readbacks;r->vram_copies=s_vram_only_copies;r->vram_resolves=s_vram_materializations;
    r->xfb_copies=s_xfb_gpu_copies;r->xfb_resolves=s_xfb_resolves;r->display_copies=s_display_copies;r->merged=s_merged_packets;r->vram_pending=s_vram_pending;
    r->draw_ticks=frame_backend.draw_ticks;r->copy_ticks=frame_backend.copy_ticks;r->swap_ticks=frame_backend.swap_ticks;
}
bool gx_pipe_frame_start(CPUState* cpu,SDL_Window* window){
    if(gx_frame_active())return true;
    if(s_capture || getenv("RUNTIME_TRACE") || !native_route() || !s_renderer || !gx_gl_available(s_renderer) || !gx_gl_xf_available(s_renderer))return false;
    if(!flush_efb(cpu))return false;SDL_RenderFlush(s_renderer);
    frame_backend.shadow=malloc(cpu->ram_size);if(!frame_backend.shadow)return false;
    memcpy(frame_backend.shadow,cpu->ram,cpu->ram_size);memcpy(frame_backend.palette,s_tlut_memory,sizeof(s_tlut_memory));frame_backend.cpu=*cpu;frame_backend.real_ram=cpu->ram;
    frame_backend.draw_ticks=frame_backend.copy_ticks=frame_backend.swap_ticks=0;frame_mirrors();
    SDL_GLContext context=SDL_GL_GetCurrentContext();
    if(!context || SDL_GL_GetCurrentWindow()!=window || !gx_frame_start(frame_execute,frame_report,NULL)){free(frame_backend.shadow);frame_backend.shadow=NULL;return false;}
    printf("[GX frame pipeline] main-thread GL consumer, two command arenas; readbacks/PE remain barriers\n");return true;
}
bool gx_pipe_frame_stop(CPUState* cpu){
    if(!gx_frame_active())return true;
    bool queued=frame_queue_draws(cpu);bool ok=gx_frame_stop() && queued;free(frame_backend.shadow);frame_backend.shadow=NULL;s_backend_bp=NULL;s_backend_palette=NULL;return ok;
}
bool gx_pipe_frame_present(CPUState* cpu){
    if(!frame_queue_draws(cpu))return false;
    VideoXFB image;video_xfb_snapshot(&image);u32 offset=image.address-GC_RAM_BASE;u64 span=(u64)image.pitch*image.height;
    u32 bytes=offset<=cpu->ram_size && span<=cpu->ram_size-offset ? (u32)span:0;
    for(u32 i=0;i<frame_backend.xfb_count;i++)if(frame_backend.xfb[i].address==image.address && frame_backend.xfb[i].width==image.width && frame_backend.xfb[i].height==image.height && frame_backend.xfb[i].pitch==image.pitch)bytes=0;
    FramePresent* op=gx_frame_alloc(frame_align(sizeof(*op))+bytes);if(!op)return false;
    op->op=(FrameOp){FRAME_PRESENT,frame_align(frame_align(sizeof(*op))+bytes)};op->image=image;op->pixels=frame_align(sizeof(*op));op->bytes=bytes;
    if(bytes)memcpy((u8*)op+op->pixels,cpu->ram+offset,bytes);return gx_frame_submit(false);
}
void gx_pipe_frame_gl_stats(void* result){if(gx_frame_active()){GXFrameStats stats;gx_frame_stats(&stats);*(GXGLStats*)result=stats.gl;}else gx_gl_get_stats(result);}

/* Test actual GPU copy ordering, not just the transport's opaque packets. */
int gx_pipe_frame_contracts(CPUState* cpu,SDL_Window* window){
    u32 saved_bp[256];memcpy(saved_bp,s_bp,sizeof(s_bp));
    u8 saved_i4[2048],saved_xfb[256];memcpy(saved_i4,cpu->ram+0x70000,2048);memcpy(saved_xfb,cpu->ram+0x80000,256);
    bool old_i4=s_vram_only_enabled,old_xfb=s_xfb_vram;int result=0;
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_Rect region={0,0,64,64};
    if(!flush_efb(cpu))return 1;
    SDL_Texture* backup=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,64,64);
    if(!backup)return 1;
    SDL_SetRenderTarget(s_renderer,backup);SDL_RenderCopy(s_renderer,s_efb,&region,NULL);SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,previous);
    if(!gx_pipe_set_vram_only(cpu,true) || !gx_pipe_set_xfb_vram(cpu,true) || !gx_pipe_frame_start(cpu,window))return 1;
    memset(cpu->ram+0x70000,0x5A,2048);memset(cpu->ram+0x80000,0x5A,256);
    for(u32 pass=0;pass<2 && !result;pass++){
        // First pass initializes GPU allocations at a barrier. Second pass is asynchronous.
        if(!frame_queue_clear(&region,0xFF00u|(pass ? 0u:255u),pass ? 255u:0u,0xFFFFFFu))result=1;
        s_bp[0x49]=0;s_bp[0x4A]=63u|(63u<<10);s_bp[0x4B]=0x70000u>>5;s_bp[0x4D]=8;s_bp[0x4E]=256;
        if(!copy_efb_texture(cpu,0))result=1;
        s_bp[0x4A]=15u|(7u<<10);s_bp[0x4B]=0x80000u>>5;s_bp[0x4D]=1;
        if(!copy_efb(cpu,0) || !frame_queue_barrier())result=1;
        for(u32 i=0;i<2048;i++)if(cpu->ram[0x70000+i]!=0x5A)result=1;
        for(u32 i=0;i<256;i++)if(cpu->ram[0x80000+i]!=0x5A)result=1;
        SDL_Texture* sample=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,16,8);
        if(!sample){result=1;break;}
        SDL_SetRenderTarget(s_renderer,sample);if(!gx_pipe_present_xfb(s_renderer,0x80080000u,NULL))result=1;
        u8 pixel[4];SDL_Rect point={0,0,1,1};
        if(SDL_RenderReadPixels(s_renderer,&point,SDL_PIXELFORMAT_RGBA32,pixel,4) || pixel[pass ? 2:0]!=255 || pixel[pass ? 0:2]!=0)result=1;
        SDL_SetRenderTarget(s_renderer,previous);SDL_DestroyTexture(sample);
    }
    if(!gx_pipe_frame_stop(cpu))result=1;
    if(!gx_pipe_set_vram_only(cpu,false) || !gx_pipe_set_xfb_vram(cpu,false))result=1;
    // Last copy was blue: I4 takes R; YUY2 has Y=41. Materialize only on explicit disable.
    if(cpu->ram[0x70000]!=0 || cpu->ram[0x80000]!=41)result=1;
    memcpy(cpu->ram+0x70000,saved_i4,2048);memcpy(cpu->ram+0x80000,saved_xfb,256);memcpy(s_bp,saved_bp,sizeof(s_bp));
    gx_pipe_set_vram_only(cpu,old_i4);gx_pipe_set_xfb_vram(cpu,old_xfb);
    SDL_SetRenderTarget(s_renderer,s_efb);SDL_SetTextureBlendMode(backup,SDL_BLENDMODE_NONE);SDL_RenderCopy(s_renderer,backup,NULL,&region);SDL_RenderFlush(s_renderer);
    SDL_SetRenderTarget(s_renderer,previous);SDL_DestroyTexture(backup);
    printf("[GX frame GPU contracts] ordered I4/XFB copies, async reuse, unchanged guest RAM, explicit materialization result=%d\n",result);return result;
}
