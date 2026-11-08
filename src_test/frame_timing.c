#include "frame_timing.h"
#include <string.h>
#include <assert.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
static uint64_t counter(void){LARGE_INTEGER t;QueryPerformanceCounter(&t);return (uint64_t)t.QuadPart;}
static uint64_t frequency(void){LARGE_INTEGER t;QueryPerformanceFrequency(&t);return (uint64_t)t.QuadPart;}
#else
#include <SDL.h>
static uint64_t counter(void){return SDL_GetPerformanceCounter();}
static uint64_t frequency(void){return SDL_GetPerformanceFrequency();}
#endif

typedef struct {
    uint64_t ticks[FRAME_STAGE_COUNT], last, start, wall, hz;
    uint64_t begin_ticks[FRAME_STAGE_COUNT],peak_ticks[FRAME_STAGE_COUNT],wall_peak;
    unsigned frames;
    FrameStage stage;
    bool active;
} TimingState;
static TimingState s;
#ifdef _MSC_VER
static __declspec(thread) bool s_worker;
#else
static _Thread_local bool s_worker;
#endif
bool frame_timing_worker(bool enabled){bool before=s_worker;s_worker=enabled;return before;}

static FrameStage transition(TimingState* state,FrameStage next,uint64_t now){
    FrameStage previous=state->stage;
    state->ticks[previous]+=now-state->last;
    state->last=now;state->stage=next;return previous;
}
void frame_timing_begin(void){
    assert(!s.active);
    if(!s.hz)s.hz=frequency();
    s.last=s.start=counter();s.stage=FRAME_OTHER;s.active=true;
    memcpy(s.begin_ticks,s.ticks,sizeof(s.ticks));
}
FrameStage frame_timing_enter(FrameStage stage){
    if(s_worker || !s.active)return FRAME_STAGE_COUNT;
    if(s.stage==stage)return stage;
    return transition(&s,stage,counter());
}
void frame_timing_leave(FrameStage previous){
    if(!s_worker && previous!=FRAME_STAGE_COUNT && s.active && previous!=s.stage)
        transition(&s,previous,counter());
}
static bool finish(TimingState* state,uint64_t now,FrameTimingReport* report){
    assert(state->active && state->stage==FRAME_OTHER);
    transition(state,FRAME_OTHER,now);state->active=false;
    for(unsigned i=0;i<FRAME_STAGE_COUNT;i++){
        uint64_t elapsed=state->ticks[i]-state->begin_ticks[i];
        if(elapsed>state->peak_ticks[i])state->peak_ticks[i]=elapsed;
    }
    if(now-state->start>state->wall_peak)state->wall_peak=now-state->start;
    state->wall+=now-state->start;
    if(++state->frames<60)return false;
    double scale=1000.0/(double)state->hz/state->frames;
    for(unsigned i=0;i<FRAME_STAGE_COUNT;i++)report->ms[i]=state->ticks[i]*scale;
    for(unsigned i=0;i<FRAME_STAGE_COUNT;i++)report->peak_ms[i]=state->peak_ticks[i]*scale*state->frames;
    report->wall_peak_ms=state->wall_peak*scale*state->frames;
    report->wall_ms=state->wall*scale;report->frames=state->frames;
    memset(state->ticks,0,sizeof(state->ticks));memset(state->peak_ticks,0,sizeof(state->peak_ticks));state->wall_peak=0;state->frames=0;state->wall=0;return true;
}
bool frame_timing_end(FrameTimingReport* report){return finish(&s,counter(),report);}

// A missed deadline is immediately runnable; never round up to another
// VBlank. Rebase after lateness rather than accumulating catch-up debt.
uint64_t frame_pacer_target(uint64_t previous,uint64_t now,uint64_t hz){
    uint64_t target=previous+hz/60u;return now>=target ? now:target;
}
int frame_timing_contracts(void){
    const uint64_t hz=60000;
    if(frame_pacer_target(0,900,hz)!=1000 ||
       frame_pacer_target(0,1000,hz)!=1000 ||
       frame_pacer_target(0,1020,hz)!=1020 ||
       frame_pacer_target(0,1200,hz)!=1200 ||
       frame_pacer_target(0,2400,hz)!=2400 ||
       frame_pacer_target(0,3100,hz)!=3100 ||
       frame_pacer_target(1020,1500,hz)!=2020)return 1;
    TimingState t={0};FrameTimingReport report;t.hz=1000;
    for(unsigned frame=0;frame<60;frame++){
        uint64_t base=frame*100;t.active=true;t.stage=FRAME_OTHER;t.start=t.last=base;
        memcpy(t.begin_ticks,t.ticks,sizeof(t.ticks));
        FrameStage game=transition(&t,FRAME_GAME,base+5);
        FrameStage gx=transition(&t,FRAME_GX_DECODE,base+35);
        FrameStage copy=transition(&t,FRAME_EFB_COPY,base+45);
        FrameStage draw=transition(&t,FRAME_GL_SUBMIT,base+55);
        transition(&t,draw,base+60);transition(&t,copy,base+65);
        transition(&t,gx,base+70);transition(&t,game,base+80);
        bool ready=finish(&t,base+100,&report);
        if(ready!=(frame==59))return 1;
    }
    const double expected[]={25,40,15,5,15,0,0};double sum=0;
    for(unsigned i=0;i<FRAME_STAGE_COUNT;i++){if(report.ms[i]!=expected[i] || report.peak_ms[i]!=expected[i])return 1;sum+=report.ms[i];}
    return sum!=report.wall_ms || report.frames!=60 || report.wall_peak_ms!=100;
}
