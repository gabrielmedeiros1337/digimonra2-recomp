/* One GL owner, three immutable command arenas. No per-draw worker or guest CPU
 * execution on the consumer. Producer register/vertex state stays on CPU. */
enum {FRAME_DRAW=1,FRAME_COPY,FRAME_PRESENT,FRAME_RESOLVE,FRAME_CLEAR,FRAME_RAW};
typedef struct {u32 type,bytes;} FrameOp;
typedef struct {u32 target,offset,bytes,data,absolute;} FrameRange;
typedef struct {
    FrameOp op;u32 draws,vertices,raw,transforms,gpu,hashes,ranges;
    u32 draw_count,vertex_count,range_count;
} FrameDraw;
typedef struct {FrameOp op;u32 bp[256],control,display,real_ram,seed_bytes;u8 seed[2048];} FrameCopy;
typedef struct {FrameOp op;VideoXFB image;u32 pixels,bytes;} FramePresent;
typedef struct {FrameOp op;u32 address,bytes;} FrameResolve;
typedef struct {FrameOp op;SDL_Rect region;u32 ar,gb,z;} FrameClear;
typedef struct {FrameOp op;QueuedDraw draw;GXGLTransform xf;VertexLayout layout;u32 fifo,fifo_bytes,ranges,range_count,chosen,mxcsr;int rounding;bool gpu;u64 unique_bytes,reused_bytes,compare_ticks;} FrameRaw;
typedef struct {u64 generation;u32 target,address,bytes,data;} FrameSnapshot;
// Producer only. Offsets refer to the current builder, never another arena.
static FrameSnapshot frame_snapshots[1024];
static struct {
    CPUState cpu;u8* shadow;u8 palette[512*1024];u8* real_ram;
    u32 i4[64],i4_count;VideoXFB xfb[8];u32 xfb_count;
    u64 draw_ticks,copy_ticks,swap_ticks;
    u64 decode_ticks,raw_draws,raw_vertices,snapshot_bytes,ram_copies;
    u64 unique_bytes,reused_bytes,compare_ticks;
    GXGLRawVertex* raw;QueuedVertex* unused;u32 capacity;
} frame_backend;
static u32 frame_align(u32 n){return (n+15u)&~15u;}
static void frame_mirrors(void){
    frame_backend.i4_count=frame_backend.xfb_count=0;
    for(u32 i=0;i<s_tex_cache_count && frame_backend.i4_count<64;i++)if(s_tex_cache[i].vram_only)frame_backend.i4[frame_backend.i4_count++]=s_tex_cache[i].gc_addr;
    for(u32 i=0;i<8;i++)if(s_xfb_images[i].pending && s_xfb_images[i].image){XFBImage* x=s_xfb_images+i;frame_backend.xfb[frame_backend.xfb_count++]=(VideoXFB){x->address,x->width,x->height,x->pitch};}
}
static bool frame_queue_barrier(void){return !gx_frame_active() || gx_frame_drain();}
static bool frame_queue_pe(void){return !gx_frame_active() || gx_frame_submit_pe();}
static bool frame_backend_ensure(void){
    if(s_efb)return true;
    SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);
    int efb_w=(int)(640.0f*s_internal_scale+0.5f),efb_h=(int)(528.0f*s_internal_scale+0.5f);
    s_efb=SDL_CreateTexture(s_renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,efb_w,efb_h);
    if(!s_efb)return false;
    SDL_SetRenderTarget(s_renderer,s_efb);SDL_SetRenderDrawColor(s_renderer,0,0,0,255);SDL_RenderClear(s_renderer);SDL_SetRenderTarget(s_renderer,previous);return true;
}
static bool frame_resource(FrameRange* ranges,u32* count,u32 target,u32 offset,u32 bytes){
    for(u32 i=0;i<*count;i++)if(ranges[i].target==target && ranges[i].offset==offset && ranges[i].bytes==bytes)return true;
    if(*count==1024)return false;ranges[(*count)++]=(FrameRange){target,offset,bytes,0,0};return true;
}
static bool frame_resolve(CPUState* cpu,u32 address,u32 bytes){
    if(!gx_frame_drain())return false;
    FrameResolve* op=gx_frame_alloc(sizeof(*op));if(!op)return false;
    *op=(FrameResolve){{FRAME_RESOLVE,frame_align(sizeof(*op))},address,bytes};
    if(!gx_frame_drain())return false;frame_mirrors();(void)cpu;return true;
}
static bool frame_queue_raw(CPUState* cpu,const QueuedDraw* draw,const GXGLTransform* xf,const VertexLayout* layout,u32 cursor,bool gpu,u32 chosen){
    if(!draw->vtx_count)return true;
    FrameRange ranges[1024];u32 range_count=0,offset=layout->matrix_bytes,count=draw->vtx_count;
    // Capture only the indexed array spans this primitive can read. No float
    // conversion, content hash, matrix math or decode-cache lookup on CPU.
    for(u32 j=0;j<12;j++){
        u32 mode=layout->mode[j];if(!mode)continue;
        u32 size=j==2 || j==3 ? color_size(layout->format[j]):layout->components[j]*scalar_size(layout->format[j]);
        if(mode==1){offset+=size;continue;}
        u32 minimum=~0u,maximum=0,index_bytes=mode-1,indices=j==1 ? layout->normal_indices:1;
        for(u32 i=0;i<count;i++){
            u32 at=(cursor+i*layout->stride+offset)%FIFO_BUFFER_SIZE,index=s_fifo_buf[at];
            if(index_bytes==2)index=(index<<8)|s_fifo_buf[(at+1)%FIFO_BUFFER_SIZE];
            if(index<minimum)minimum=index;if(index>maximum)maximum=index;
        }
        if(count){
            u32 stride=draw->debug_cp[0xB0+j]&255u;u64 base=draw->debug_cp[0xA0+j]&0x1FFFFFFu;
            u64 begin=base+(u64)minimum*stride,end=base+(u64)maximum*stride+size;
            if(end>cpu->ram_size)end=cpu->ram_size;
            if(begin<end && !frame_resource(ranges,&range_count,0,(u32)begin,(u32)(end-begin)))return false;
        }
        offset+=index_bytes*indices;
    }
    if(offset!=layout->stride)return false;
    static const u8 tw[15]={8,8,8,4,4,4,4,0,8,8,4,0,0,0,8},th[15]={8,4,4,4,4,4,4,0,8,4,4,0,0,0,8};
    const u32* bp=draw->material.bp;u32 units=0;
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
        u32 palette_bytes=fmt==8 ? 32u:fmt==9 ? 512u:fmt==10 ? 32768u:0,palette=(bp[base+24+n]&1023u)<<9;
        if(palette_bytes && palette<=sizeof(s_tlut_memory) && palette_bytes<=sizeof(s_tlut_memory)-palette)
            if(!frame_resource(ranges,&range_count,1,palette,palette_bytes))return false;
    }
    u64 bytes=frame_align(sizeof(FrameRaw));u32 fifo=(u32)bytes,fifo_bytes=count*layout->stride;bytes+=frame_align(fifo_bytes);
    u32 spans=(u32)bytes;bytes+=frame_align(range_count*sizeof(FrameRange));
    for(u32 i=0;i<range_count;i++){ranges[i].data=(u32)bytes;bytes+=frame_align(ranges[i].bytes);}
    if(bytes>64u*1024u*1024u-16)return false;
    FrameRaw* op=gx_frame_alloc((u32)bytes);if(!op)return false;
    u8* arena;u32 arena_used;u64 generation=gx_frame_builder(&arena,&arena_used);
    if(!generation)return false;
    u32 op_offset=(u32)((u8*)op-arena),data_end=spans+frame_align(range_count*sizeof(FrameRange));
    op->op=(FrameOp){FRAME_RAW,(u32)bytes};op->draw=*draw;op->draw.vtx_start=0;op->xf=*xf;op->layout=*layout;
    op->fifo=fifo;op->fifo_bytes=fifo_bytes;op->ranges=spans;op->range_count=range_count;op->gpu=gpu;op->chosen=chosen;op->rounding=fegetround();
#if defined(_M_X64) || defined(__x86_64__)
    op->mxcsr=_mm_getcsr();
#endif
    u8* p=(u8*)op;
    u32 first=FIFO_BUFFER_SIZE-cursor;if(first>fifo_bytes)first=fifo_bytes;
    memcpy(p+fifo,s_fifo_buf+cursor,first);memcpy(p+fifo+first,s_fifo_buf,fifo_bytes-first);
    op->unique_bytes=op->reused_bytes=op->compare_ticks=0;
    for(u32 i=0;i<range_count;i++){
        FrameRange* r=ranges+i;const u8* source=(r->target ? s_tlut_memory:cpu->ram)+r->offset;
        u32 key=((r->offset>>4)*2654435761u)^(r->bytes*2246822519u)^(r->target*3266489917u);
        FrameSnapshot* entry=frame_snapshots+(key&1023u);bool hit=false;
        if(entry->generation==generation && entry->target==r->target && entry->address==r->offset && entry->bytes==r->bytes && entry->data<=op_offset && r->bytes<=op_offset-entry->data){
            u64 start=SDL_GetPerformanceCounter();hit=memcmp(arena+entry->data,source,r->bytes)==0;op->compare_ticks+=SDL_GetPerformanceCounter()-start;
        }
        r->absolute=1;
        if(hit){r->data=entry->data;op->reused_bytes+=r->bytes;}
        else{
            r->data=op_offset+data_end;memcpy(p+data_end,source,r->bytes);data_end+=frame_align(r->bytes);
            *entry=(FrameSnapshot){generation,r->target,r->offset,r->bytes,r->data};op->unique_bytes+=r->bytes;
        }
    }
    memcpy(p+spans,ranges,range_count*sizeof(FrameRange));
    op->op.bytes=frame_align(data_end);if(!gx_frame_trim((u32)bytes-op->op.bytes))return false;
    return true;
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
    // VRAM-only copies have no CPU-visible pixel result. First allocation is
    // also ordered in the queue, not a reason to wait for the renderer.
    if(display && s_xfb_vram && w<=640 && out_h<=528 && pitch>=w*2 && dest<=cpu->ram_size && (u64)pitch*out_h<=cpu->ram_size-dest){
        u32 slot=frame_backend.xfb_count;
        for(u32 i=0;i<frame_backend.xfb_count;i++)if(frame_backend.xfb[i].address==(dest|GC_RAM_BASE)){slot=i;break;}
        if(slot<8){if(slot==frame_backend.xfb_count)frame_backend.xfb_count++;frame_backend.xfb[slot]=(VideoXFB){dest|GC_RAM_BASE,w,out_h,pitch};known=true;}
    }
    u32 fmt=(control>>3)&15u;fmt=(fmt>>1)|((fmt&1u)<<3);
    if(!display && s_vram_only_enabled && fmt==0 && !(control&512u) && w==64 && h==64 && pitch==256 && dest<=cpu->ram_size && 2048<=cpu->ram_size-dest){
        u32 slot=frame_backend.i4_count;bool overlap=false;
        for(u32 i=0;i<frame_backend.i4_count;i++){
            u32 at=frame_backend.i4[i]-GC_RAM_BASE;
            if(at==dest)slot=i;
            else if((u64)dest+2048>at && (u64)at+2048>dest)overlap=true;
        }
        if(slot<64 && !overlap){if(slot==frame_backend.i4_count)frame_backend.i4_count++;frame_backend.i4[slot]=dest|GC_RAM_BASE;known=true;}
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
    SDL_Texture* initial_target=SDL_GetRenderTarget(s_renderer);
    for(u32 at=0;at<bytes;){
        const FrameOp* header=(const FrameOp*)(data+at);if(header->bytes<sizeof(*header) || header->bytes>bytes-at)return false;
        if(header->type==FRAME_RAW){
            const FrameRaw* op=(const FrameRaw*)header;const u8* p=(const u8*)op;const FrameRange* r=(const FrameRange*)(p+op->ranges);
            u64 decode_start=SDL_GetPerformanceCounter();
            for(u32 i=0;i<op->range_count;i++){
                const u8* source=r[i].absolute ? data+r[i].data:p+r[i].data;
                // References can point backward or into this op, never to a
                // future command, a different arena, or outside the packet.
                if(r[i].absolute && (r[i].data>at+header->bytes || r[i].bytes>at+header->bytes-r[i].data))return false;
                memcpy((r[i].target ? frame_backend.palette:cpu.ram)+r[i].offset,source,r[i].bytes);frame_backend.snapshot_bytes+=r[i].bytes;
            }
            frame_backend.unique_bytes+=op->unique_bytes;frame_backend.reused_bytes+=op->reused_bytes;frame_backend.compare_ticks+=op->compare_ticks;
            u32 count=op->draw.vtx_count;
            if(count>frame_backend.capacity){
                GXGLRawVertex* raw=realloc(frame_backend.raw,count*sizeof(*raw));if(!raw)return false;frame_backend.raw=raw;
                QueuedVertex* unused=realloc(frame_backend.unused,count*sizeof(*unused));if(!unused)return false;frame_backend.unused=unused;frame_backend.capacity=count;
            }
            if(++s_vertex_cache_epoch==0){memset(s_vertex_cache,0,sizeof(s_vertex_cache));s_vertex_cache_epoch=1;for(u32 i=0;i<s_vertex_worker_count;i++)memset(s_vertex_workers[i].cache,0,sizeof(s_vertex_cache));}
            VertexInput input={op->draw.debug_cp,p+op->fifo,op->fifo_bytes ? op->fifo_bytes:1};
            DecodeEnvironment environment={0};environment.input=&input;environment.xf=&op->xf;
            DecodeEnvironment* previous_environment=s_decode_environment;s_decode_environment=&environment;
            int rounding=fegetround();
#if defined(_M_X64) || defined(__x86_64__)
            u32 mxcsr=_mm_getcsr();
#endif
            fesetround(op->rounding);
#if defined(_M_X64) || defined(__x86_64__)
            _mm_setcsr(op->mxcsr);
#endif
            decode_vertices_input(&cpu,&op->layout,0,frame_backend.unused,count,op->chosen,false,op->gpu ? frame_backend.raw:NULL,&input);
            s_decode_environment=previous_environment;fesetround(rounding);
#if defined(_M_X64) || defined(__x86_64__)
            _mm_setcsr(mxcsr);
#endif
            frame_backend.decode_ticks+=SDL_GetPerformanceCounter()-decode_start;frame_backend.raw_draws++;frame_backend.raw_vertices+=count;
            u64 started=SDL_GetPerformanceCounter();bool gpu=op->gpu;QueuedDraw draw=op->draw;
            GXRenderView view={&draw,frame_backend.unused,frame_backend.raw,(GXGLTransform*)&op->xf,&gpu,&s_last_raw_hash,1,count};
            int efb_w=(int)(640.0f*s_internal_scale+0.5f),efb_h=(int)(480.0f*s_internal_scale+0.5f);
            if(!frame_backend_ensure())return false;if(SDL_GetRenderTarget(s_renderer)!=s_efb)SDL_SetRenderTarget(s_renderer,s_efb);
            gx_pipe_render_to_sdl_timed_body(s_renderer,&cpu,0,0,efb_w,efb_h,&view);
            frame_backend.draw_ticks+=SDL_GetPerformanceCounter()-started;
        }else if(header->type==FRAME_DRAW){
            u64 started=SDL_GetPerformanceCounter();
            const FrameDraw* op=(const FrameDraw*)header;const u8* p=(const u8*)op;const FrameRange* r=(const FrameRange*)(p+op->ranges);
            for(u32 i=0;i<op->range_count;i++)memcpy((r[i].target ? frame_backend.palette:cpu.ram)+r[i].offset,p+r[i].data,r[i].bytes);
            GXRenderView view={(QueuedDraw*)(p+op->draws),(QueuedVertex*)(p+op->vertices),(GXGLRawVertex*)(p+op->raw),(GXGLTransform*)(p+op->transforms),(bool*)(p+op->gpu),(u64*)(p+op->hashes),op->draw_count,op->vertex_count};
            int efb_w=(int)(640.0f*s_internal_scale+0.5f),efb_h=(int)(480.0f*s_internal_scale+0.5f);
            if(!frame_backend_ensure())return false;SDL_Texture* previous=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);
            gx_pipe_render_to_sdl_timed_body(s_renderer,&cpu,0,0,efb_w,efb_h,&view);SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,previous);
            frame_backend.draw_ticks+=SDL_GetPerformanceCounter()-started;
        }else if(header->type==FRAME_COPY){
            const FrameCopy* op=(const FrameCopy*)header;CPUState copy=cpu;if(op->real_ram){copy.ram=frame_backend.real_ram;frame_backend.ram_copies++;}
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
            gx_frame_presented();
        }else if(header->type==FRAME_RESOLVE){
            const FrameResolve* op=(const FrameResolve*)header;CPUState real=cpu;real.ram=frame_backend.real_ram;if(!resolve_vram_overlap(&real,op->address,op->bytes,false))return false;
        }else if(header->type==FRAME_CLEAR){
            const FrameClear* op=(const FrameClear*)header;if(!frame_backend_ensure())return false;SDL_Texture* old=SDL_GetRenderTarget(s_renderer);SDL_SetRenderTarget(s_renderer,s_efb);clear_efb_region(&op->region,op->ar,op->gb,op->z);SDL_RenderFlush(s_renderer);SDL_SetRenderTarget(s_renderer,old);
        }else return false;
        at+=header->bytes;
    }
    SDL_SetRenderTarget(s_renderer,initial_target);s_backend_palette=NULL;return true;
}
static void frame_report(GXFrameStats* r){
    gx_gl_get_stats(&r->gl);r->render=s_render_ticks;r->copy=s_copy_ticks;r->texture_copy=s_texture_copy_ticks;r->uploads=s_texture_uploads;
    r->texture_hits=s_tex_hits;r->hash_bytes=s_tex_hash_bytes;r->readbacks=s_texture_readbacks;r->vram_copies=s_vram_only_copies;r->vram_resolves=s_vram_materializations;
    r->xfb_copies=s_xfb_gpu_copies;r->xfb_resolves=s_xfb_resolves;r->display_copies=s_display_copies;r->merged=s_merged_packets;r->vram_pending=s_vram_pending;
    r->draw_ticks=frame_backend.draw_ticks;r->copy_ticks=frame_backend.copy_ticks;r->swap_ticks=frame_backend.swap_ticks;
    r->decode_ticks=frame_backend.decode_ticks;r->raw_draws=frame_backend.raw_draws;r->raw_vertices=frame_backend.raw_vertices;r->snapshot_bytes=frame_backend.snapshot_bytes;r->ram_copies=frame_backend.ram_copies;
    r->unique_bytes=frame_backend.unique_bytes;r->reused_bytes=frame_backend.reused_bytes;r->compare_ticks=frame_backend.compare_ticks;
}
bool gx_pipe_frame_start(CPUState* cpu,SDL_Window* window){
    if(gx_frame_active())return true;
    if(s_capture || getenv("RUNTIME_TRACE") || !native_route() || !s_renderer || !gx_gl_available(s_renderer) || !gx_gl_xf_available(s_renderer))return false;
    if(!flush_efb(cpu))return false;SDL_RenderFlush(s_renderer);
    frame_backend.shadow=malloc(cpu->ram_size);if(!frame_backend.shadow)return false;
    memcpy(frame_backend.shadow,cpu->ram,cpu->ram_size);memcpy(frame_backend.palette,s_tlut_memory,sizeof(s_tlut_memory));frame_backend.cpu=*cpu;frame_backend.real_ram=cpu->ram;
    frame_backend.draw_ticks=frame_backend.copy_ticks=frame_backend.swap_ticks=0;
    frame_backend.decode_ticks=frame_backend.raw_draws=frame_backend.raw_vertices=frame_backend.snapshot_bytes=frame_backend.ram_copies=0;frame_mirrors();
    frame_backend.unique_bytes=frame_backend.reused_bytes=frame_backend.compare_ticks=0;memset(frame_snapshots,0,sizeof(frame_snapshots));
    SDL_GLContext context=SDL_GL_GetCurrentContext();
    if(!context || SDL_GL_GetCurrentWindow()!=window || !gx_frame_start(frame_execute,frame_report,NULL)){free(frame_backend.shadow);frame_backend.shadow=NULL;return false;}
    printf("[GX frame pipeline] main-thread decode/GL, %u raw arenas, exact snapshot reuse; PE async, RAM readbacks remain barriers\n",GX_FRAME_ARENAS);return true;
}
bool gx_pipe_frame_stop(CPUState* cpu){
    if(!gx_frame_active())return true;
    bool queued=frame_queue_draws(cpu);bool ok=gx_frame_stop() && queued;free(frame_backend.shadow);frame_backend.shadow=NULL;free(frame_backend.raw);free(frame_backend.unused);frame_backend.raw=NULL;frame_backend.unused=NULL;frame_backend.capacity=0;s_backend_bp=NULL;s_backend_palette=NULL;return ok;
}
bool gx_pipe_frame_present(CPUState* cpu){
    if(!frame_queue_draws(cpu))return false;
    VideoXFB image;video_xfb_snapshot(&image);u32 offset=image.address-GC_RAM_BASE;u64 span=(u64)image.pitch*image.height;
    u32 bytes=offset<=cpu->ram_size && span<=cpu->ram_size-offset ? (u32)span:0;
    for(u32 i=0;i<frame_backend.xfb_count;i++)if(frame_backend.xfb[i].address==image.address && frame_backend.xfb[i].width==image.width && frame_backend.xfb[i].height==image.height && frame_backend.xfb[i].pitch==image.pitch)bytes=0;
    FramePresent* op=gx_frame_alloc(frame_align(sizeof(*op))+bytes);if(!op)return false;
    op->op=(FrameOp){FRAME_PRESENT,frame_align(frame_align(sizeof(*op))+bytes)};op->image=image;op->pixels=frame_align(sizeof(*op));op->bytes=bytes;
    if(bytes)memcpy((u8*)op+op->pixels,cpu->ram+offset,bytes);
    if(!gx_frame_submit(false))return false;gx_frame_frame_queued();return true;
}
void gx_pipe_frame_gl_stats(void* result){if(gx_frame_active()){GXFrameStats stats;gx_frame_stats(&stats);*(GXGLStats*)result=stats.gl;}else gx_gl_get_stats(result);}

static bool frame_validate_capture(CPUState* cpu,SDL_Window* window,const VertexLayout* layout,u32 cursor,u32 count,const GXGLTransform* xf,const GXGLRawVertex* expected,const GXGLVertex* native_expected){
    if(!gx_pipe_frame_start(cpu,window))return false;
    // The backend must use packet spans, not even a stale full-RAM clone.
    memset(frame_backend.shadow,0,cpu->ram_size);
    QueuedDraw draw={0};draw.prim_type=0x90;draw.vtx_count=(u16)count;memcpy(draw.debug_cp,s_cp,sizeof(s_cp));
    bool ok=frame_queue_raw(cpu,&draw,xf,layout,cursor,true,0) && frame_queue_raw(cpu,&draw,xf,layout,cursor,false,0) && frame_queue_pe();
    GXFrameStats submitted;gx_frame_stats(&submitted);if(submitted.barrier_calls || submitted.packets)ok=false;
    memset(cpu->ram,0xCC,cpu->ram_size);memset(s_fifo_buf,0xCD,FIFO_BUFFER_SIZE);memset(s_cp,0,sizeof(s_cp));memset(s_xf,0,sizeof(s_xf));
    if(!frame_queue_barrier() || !frame_backend.raw || memcmp(frame_backend.raw,expected,count*sizeof(*expected)))ok=false;
    for(u32 i=0;i<count;i++)if(memcmp(&frame_backend.unused[i].native,native_expected+i,sizeof(*native_expected)))ok=false;
    if(!frame_backend.reused_bytes)ok=false;
    if(!gx_pipe_frame_stop(cpu))ok=false;
    printf("[GX raw captured combat] %u raw and CPU-XF vertices identical after full RAM/FIFO/CP/XF overwrite; shared snapshots, zero PE drains result=%d\n",count,ok ? 0:1);return ok;
}

static int frame_raw_contract(CPUState* cpu){
    u8 saved_ram[8192],saved_fifo[4096];u32 cursor=FIFO_BUFFER_SIZE-7;
    memcpy(saved_ram,cpu->ram+0x90000,sizeof(saved_ram));
    for(u32 i=0;i<sizeof(saved_fifo);i++)saved_fifo[i]=s_fifo_buf[(cursor+i)%FIFO_BUFFER_SIZE];
    u32 original_cp[256],original_xf[0x1058];memcpy(original_cp,s_cp,sizeof(s_cp));memcpy(original_xf,s_xf,sizeof(s_xf));
    int saved_rounding=fegetround();const int rounding_modes[]={FE_TONEAREST,FE_DOWNWARD,FE_UPWARD,FE_TOWARDZERO};
    int result=0;u32 compared=0;
    for(u32 rm=0;rm<4 && !result;rm++)for(u32 gpu=0;gpu<2 && !result;gpu++)for(u32 mode=1;mode<=3 && !result;mode++)for(u32 fmt=0;fmt<=4 && !result;fmt++)for(u32 nbt=0;nbt<2 && !result;nbt++){
        memcpy(s_cp,original_cp,sizeof(s_cp));memcpy(s_xf,original_xf,sizeof(s_xf));s_matrix_valid=0;fesetround(rounding_modes[rm]);
        VertexLayout l={0};l.matrix_bytes=2;l.normal_indices=nbt ? 3:1;
        l.mode[0]=l.mode[1]=l.mode[4]=(u8)mode;l.mode[2]=1;
        l.format[0]=l.format[1]=l.format[4]=(u8)fmt;l.format[2]=5;
        l.components[0]=3;l.components[1]=nbt ? 9:3;l.components[4]=2;
        l.fraction[0]=7;l.fraction[4]=11;l.stride=2;
        for(u32 j=0;j<12;j++)if(l.mode[j])l.stride+=l.mode[j]==1 ? (j==2 ? 4:l.components[j]*scalar_size(l.format[j])):(l.mode[j]-1)*(j==1 ? l.normal_indices:1);
        QueuedDraw draw={0};draw.prim_type=0x90;draw.vtx_count=30;draw.debug_cp[0x50]=3;draw.debug_cp[0x30]=0x1234567;draw.debug_cp[0x40]=0x12345;
        for(u32 i=0;i<sizeof(saved_ram);i++)cpu->ram[0x90000+i]=(u8)(i*19u+fmt*11u);
        for(u32 j=0;j<12;j++){draw.debug_cp[0xA0+j]=0x90000+j*512;draw.debug_cp[0xB0+j]=36;}
        for(u32 i=0;i<30;i++){
            u32 at=cursor+i*l.stride;
            s_fifo_buf[(at++)%FIFO_BUFFER_SIZE]=(u8)((i*3)&63);s_fifo_buf[(at++)%FIFO_BUFFER_SIZE]=(u8)((i*5)&63);
            for(u32 j=0;j<12;j++)if(l.mode[j]){
                if(l.mode[j]==1){u32 size=j==2 ? 4:l.components[j]*scalar_size(l.format[j]);for(u32 k=0;k<size;k++)s_fifo_buf[(at++)%FIFO_BUFFER_SIZE]=(u8)(i*7u+k*23u);}
                else for(u32 n=0;n<(j==1 ? l.normal_indices:1u);n++){if(mode==3)s_fifo_buf[(at++)%FIFO_BUFFER_SIZE]=0;s_fifo_buf[(at++)%FIFO_BUFFER_SIZE]=(u8)((i+n)%8);}
            }
            if(at!=cursor+(i+1)*l.stride)result=1;
        }
        GXGLRawVertex expected[30];QueuedVertex native_expected[30];VertexInput input={draw.debug_cp,s_fifo_buf,FIFO_BUFFER_SIZE};
        memcpy(s_cp,draw.debug_cp,sizeof(s_cp));prepare_vertex_constants(&l,cursor,30);
        for(u32 i=0;i<30;i++)decode_vertex_input(cpu,&l,(cursor+i*l.stride)%FIFO_BUFFER_SIZE,native_expected+i,0,false,gpu ? expected+i:NULL,&input);
        GXGLTransform xf;memcpy(xf.words,s_xf,sizeof(s_xf));xf.projection=s_projection_loaded;xf.lighting=s_lighting_loaded;GXFrameStats before,after;gx_frame_stats(&before);
        if(!frame_queue_raw(cpu,&draw,&xf,&l,cursor,gpu!=0,0))result=1;
        // Same range/content must reuse; a CPU/DMA write in this same arena
        // must invalidate that reuse without any instrumentation on stores.
        if(!frame_queue_raw(cpu,&draw,&xf,&l,cursor,gpu!=0,0))result=1;
        for(u32 i=0;i<sizeof(saved_ram);i++)cpu->ram[0x90000+i]^=1;
        for(u32 i=0;i<30;i++)decode_vertex_input(cpu,&l,(cursor+i*l.stride)%FIFO_BUFFER_SIZE,native_expected+i,0,false,gpu ? expected+i:NULL,&input);
        if(!frame_queue_raw(cpu,&draw,&xf,&l,cursor,gpu!=0,0))result=1;
        memset(cpu->ram+0x90000,0xCC,sizeof(saved_ram));for(u32 i=0;i<30*l.stride;i++)s_fifo_buf[(cursor+i)%FIFO_BUFFER_SIZE]=0xCD;
        memset(draw.debug_cp,0,sizeof(draw.debug_cp));memset(&xf,0xAB,sizeof(xf));memset(s_cp,0xCE,sizeof(s_cp));memset(s_xf,0xCF,sizeof(s_xf));
        if(!frame_queue_pe())result=1;gx_frame_stats(&after);
        if(after.barrier_calls!=before.barrier_calls || after.packets!=before.packets || after.pe_submits!=before.pe_submits+1)result=1;
        if(!frame_queue_barrier() || (gpu ? memcmp(expected,frame_backend.raw,sizeof(expected)):memcmp(native_expected,frame_backend.unused,sizeof(native_expected))))result=1;compared+=30;
    }
    memcpy(cpu->ram+0x90000,saved_ram,sizeof(saved_ram));for(u32 i=0;i<sizeof(saved_fifo);i++)s_fifo_buf[(cursor+i)%FIFO_BUFFER_SIZE]=saved_fifo[i];
    memcpy(s_cp,original_cp,sizeof(s_cp));memcpy(s_xf,original_xf,sizeof(s_xf));s_matrix_valid=0;fesetround(saved_rounding);
    printf("[GX raw frame] %u raw/native-XF/direct/index8/index16/NBT vertices, all rounding modes; exact snapshot reuse/invalidation, FIFO wrap and overwritten RAM/CP/XF; zero PE drains result=%d\n",compared,result);return result;
}

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
    if(frame_raw_contract(cpu))result=1;
    memset(cpu->ram+0x70000,0x5A,2048);memset(cpu->ram+0x80000,0x5A,256);
    for(u32 pass=0;pass<2 && !result;pass++){
        GXFrameStats before,after;gx_frame_stats(&before);
        // First pass initializes GPU allocations at a barrier. Second pass is asynchronous.
        if(!frame_queue_clear(&region,0xFF00u|(pass ? 0u:255u),pass ? 255u:0u,0xFFFFFFu))result=1;
        s_bp[0x49]=0;s_bp[0x4A]=63u|(63u<<10);s_bp[0x4B]=0x70000u>>5;s_bp[0x4D]=8;s_bp[0x4E]=256;
        if(!copy_efb_texture(cpu,0))result=1;
        s_bp[0x4A]=15u|(7u<<10);s_bp[0x4B]=0x80000u>>5;s_bp[0x4D]=1;
        if(!copy_efb(cpu,0))result=1;gx_frame_stats(&after);
        if(after.barrier_calls!=before.barrier_calls)result=1;
        if(!frame_queue_barrier())result=1;
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
