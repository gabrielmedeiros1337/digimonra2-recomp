#include "cpu_frame.h"
#include "gx_frame.h"
#include <string.h>
#include <stdio.h>
static struct {SDL_Thread* thread;SDL_sem* ready;CPUFrameRun run;void* job;SDL_atomic_t done,stop,cancel;} s;
static int emulate(void* ignored){
    (void)ignored;
    printf("[CPU frame worker] thread=%lu\n",(unsigned long)SDL_ThreadID());
    for(;;){SDL_SemWait(s.ready);if(SDL_AtomicGet(&s.stop))break;s.run(s.job);SDL_AtomicSet(&s.done,1);gx_frame_wake();}return 0;
}
bool cpu_frame_start(CPUFrameRun run){
    if(s.thread)return true;memset(&s,0,sizeof(s));s.run=run;s.ready=SDL_CreateSemaphore(0);SDL_AtomicSet(&s.done,1);
    if(!s.ready)return false;s.thread=SDL_CreateThread(emulate,"Gekko frame CPU",NULL);
    if(!s.thread){SDL_DestroySemaphore(s.ready);memset(&s,0,sizeof(s));return false;}
    return true;
}
bool cpu_frame_submit(void* job){if(!s.thread || !SDL_AtomicGet(&s.done))return false;s.job=job;SDL_AtomicSet(&s.cancel,0);SDL_AtomicSet(&s.done,0);SDL_SemPost(s.ready);return true;}
bool cpu_frame_done(void){return !s.thread || SDL_AtomicGet(&s.done)!=0;}
void cpu_frame_cancel(void){SDL_AtomicSet(&s.cancel,1);}
bool cpu_frame_cancelled(void){return SDL_AtomicGet(&s.cancel)!=0;}
void cpu_frame_stop(void){
    if(!s.thread)return;while(!cpu_frame_done())gx_frame_pump(true);
    SDL_AtomicSet(&s.stop,1);SDL_SemPost(s.ready);SDL_WaitThread(s.thread,NULL);SDL_DestroySemaphore(s.ready);memset(&s,0,sizeof(s));
}
