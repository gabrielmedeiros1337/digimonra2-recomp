#include "cpu_frame.h"
#include "gx_frame.h"
#include "frame_timing.h"
#include <stdio.h>
#include <string.h>
typedef struct {u32 bytes,sequence;u8 data[8192];} Packet;
static SDL_threadID owner;
static u32 consumed,expected,barriers;
static SDL_atomic_t failed;
static SDL_atomic_t render_started,cpu_progress;
static bool overlap;
static bool credit;
#define CHECK(x) do{if(!(x)){fprintf(stderr,"frame pipeline FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
static bool consume(const u8* bytes,u32 size,void* ignored){
    (void)ignored;const Packet* p=(const Packet*)bytes;
    if(SDL_ThreadID()!=owner || !gx_frame_consuming() || size!=((p->bytes+15u)&~15u) || p->sequence!=consumed++)return false;
    if(frame_timing_enter(FRAME_GL_SUBMIT)!=FRAME_STAGE_COUNT)return false;
    if(overlap){
        SDL_AtomicSet(&render_started,1);u32 deadline=SDL_GetTicks()+1000;
        while(!SDL_AtomicGet(&cpu_progress)){if((s32)(SDL_GetTicks()-deadline)>=0)return false;SDL_Delay(0);}
    }
    for(u32 i=0;i<p->bytes-8;i++)if(p->data[i]!=(u8)(p->sequence*37u+i*19u))return false;
    if(credit)gx_frame_presented();
    return true;
}
static void produce(void* opaque){
    u32 count=*(u32*)opaque;if(SDL_ThreadID()==owner){SDL_AtomicSet(&failed,1);return;}
    FrameStage before=frame_timing_enter(FRAME_GAME);
    for(u32 n=0;n<count;n++){
        Packet source;source.bytes=8+(n*173u)%8193u;source.sequence=expected++;
        for(u32 i=0;i<source.bytes-8;i++)source.data[i]=(u8)(source.sequence*37u+i*19u);
        Packet* p=gx_frame_alloc(source.bytes);
        if(!p){SDL_AtomicSet(&failed,1);break;}memcpy(p,&source,source.bytes);
        if(!(overlap ? gx_frame_submit_pe():gx_frame_submit(false))){SDL_AtomicSet(&failed,1);break;}
        memset(&source,0,sizeof(source)); // Producer storage may be recycled immediately.
        if(overlap){
            u32 deadline=SDL_GetTicks()+1000;
            while(!SDL_AtomicGet(&render_started)){if((s32)(SDL_GetTicks()-deadline)>=0){SDL_AtomicSet(&failed,1);break;}SDL_Delay(0);}
            SDL_AtomicSet(&cpu_progress,1);
        }
        if(n%7==0){if(!gx_frame_drain()){SDL_AtomicSet(&failed,1);break;}barriers++;}
    }
    frame_timing_leave(before);
}
#undef main
int main(void){
    CHECK(SDL_Init(SDL_INIT_TIMER)==0);owner=SDL_ThreadID();CHECK(gx_frame_start(consume,NULL,NULL));CHECK(cpu_frame_start(produce));
    u32 per_frame=12;FrameTimingReport report;
    for(u32 frame=0;frame<60;frame++){
        frame_timing_begin();CHECK(cpu_frame_submit(&per_frame));
        while(!cpu_frame_done())gx_frame_pump(true);
        CHECK(!SDL_AtomicGet(&failed));CHECK(gx_frame_drain());CHECK(frame_timing_end(&report)==(frame==59));
    }
    double sum=0;for(u32 i=0;i<FRAME_STAGE_COUNT;i++)sum+=report.ms[i];CHECK(sum-report.wall_ms<0.001 && report.wall_ms-sum<0.001);
    CHECK(report.ms[FRAME_GL_SUBMIT]==0); // Backend wall time must not be added to simultaneous CPU time.
    // All three arenas can be published before the owner consumes anything.
    GXFrameStats initial;gx_frame_stats(&initial);
    for(u32 i=0;i<GX_FRAME_ARENAS;i++){Packet* p=gx_frame_alloc(32);CHECK(p);p->bytes=8;p->sequence=expected++;CHECK(gx_frame_trim(16));CHECK(gx_frame_submit(false));}
    GXFrameStats queued;gx_frame_stats(&queued);CHECK(queued.packets==initial.packets);CHECK(gx_frame_drain());
    overlap=true;u32 one=1;CHECK(cpu_frame_submit(&one));while(!cpu_frame_done())gx_frame_pump(true);
    CHECK(!SDL_AtomicGet(&failed) && SDL_AtomicGet(&render_started) && SDL_AtomicGet(&cpu_progress));overlap=false;
    credit=true;
    for(u32 i=0;i<2;i++){Packet* p=gx_frame_alloc(8);CHECK(p);p->bytes=8;p->sequence=expected++;CHECK(gx_frame_submit(false));gx_frame_frame_queued();}
    CHECK(gx_frame_begin_cpu_frame());GXFrameStats credits;gx_frame_stats(&credits);
    CHECK(credits.frames_queued==2 && credits.frames_presented==1);CHECK(gx_frame_drain());credit=false;
    u32 stress=3000;CHECK(cpu_frame_submit(&stress));while(!cpu_frame_done())gx_frame_pump(true);
    CHECK(!SDL_AtomicGet(&failed) && gx_frame_drain());CHECK(consumed==expected && barriers>400);
    GXFrameStats stats;gx_frame_stats(&stats);CHECK(stats.packets==expected && stats.bytes>0);
    CHECK(stats.pe_submits==1 && stats.pressure_waits>0 && stats.barrier_calls>0);
    CHECK(!gx_frame_alloc(64u*1024u*1024u+1));cpu_frame_stop();CHECK(gx_frame_stop());
    printf("[Frame pipeline] %u immutable packets, CPU/main owner separation, bounded backpressure, %u barriers, no timing double-count passed\n",consumed,barriers);
    SDL_Quit();return 0;
}
