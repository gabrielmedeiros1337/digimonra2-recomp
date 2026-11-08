#include "gx_frame.h"
#include "frame_timing.h"
#include <stdlib.h>
#include <string.h>
enum {FREE,BUILDING,READY,EXECUTING};
typedef struct {u8* bytes;u32 used,capacity,state;u64 ticket;} Slot;
static struct {
    bool active;SDL_threadID owner;SDL_mutex* lock;SDL_sem* ready;SDL_cond* changed;
    GXFrameExecute execute;GXFrameReport report;void* user;
    Slot slots[2];u32 building;u64 issued,completed,wait_ticks;bool failed;
    GXFrameStats stats;
} s;
#ifdef _MSC_VER
static __declspec(thread) bool worker;
#else
static _Thread_local bool worker;
#endif
bool gx_frame_consuming(void){return worker;}
bool gx_frame_active(void){return s.active;}
void gx_frame_wake(void){if(s.active)SDL_SemPost(s.ready);}
bool gx_frame_pump(bool wait){
    if(!s.active || SDL_ThreadID()!=s.owner)return false;
    if(wait)SDL_SemWaitTimeout(s.ready,1);else SDL_SemTryWait(s.ready);
    SDL_LockMutex(s.lock);Slot* slot=NULL;
    for(u32 i=0;i<2;i++)if(s.slots[i].state==READY && (!slot || s.slots[i].ticket<slot->ticket))slot=s.slots+i;
    if(!slot){SDL_UnlockMutex(s.lock);return false;}
    slot->state=EXECUTING;SDL_UnlockMutex(s.lock);
    worker=true;bool previous=frame_timing_worker(true);u64 start=SDL_GetPerformanceCounter();
    bool ok=s.execute(slot->bytes,slot->used,s.user);u64 elapsed=SDL_GetPerformanceCounter()-start;
    SDL_LockMutex(s.lock);if(!ok)s.failed=true;s.stats.packets++;s.stats.bytes+=slot->used;s.stats.worker_ticks+=elapsed;
    if(s.report)s.report(&s.stats);s.completed=slot->ticket;slot->used=0;slot->state=FREE;SDL_CondBroadcast(s.changed);SDL_UnlockMutex(s.lock);
    frame_timing_worker(previous);worker=false;return true;
}
bool gx_frame_start(GXFrameExecute execute,GXFrameReport report,void* user){
    if(s.active || !execute)return false;
    memset(&s,0,sizeof(s));s.building=2;s.execute=execute;s.report=report;s.user=user;s.owner=SDL_ThreadID();
    s.lock=SDL_CreateMutex();s.ready=SDL_CreateSemaphore(0);s.changed=SDL_CreateCond();
    if(!s.lock || !s.ready || !s.changed){if(s.lock)SDL_DestroyMutex(s.lock);if(s.ready)SDL_DestroySemaphore(s.ready);if(s.changed)SDL_DestroyCond(s.changed);memset(&s,0,sizeof(s));return false;}
    if(s.report)s.report(&s.stats);s.active=true;return true;
}
static Slot* acquire(void){
    SDL_LockMutex(s.lock);
    for(;;){
        if(s.failed){SDL_UnlockMutex(s.lock);return NULL;}
        for(u32 i=0;i<2;i++)if(s.slots[i].state==FREE){s.slots[i].state=BUILDING;s.slots[i].used=0;s.building=i;SDL_UnlockMutex(s.lock);return s.slots+i;}
        u64 at=SDL_GetPerformanceCounter();
        if(SDL_ThreadID()==s.owner){SDL_UnlockMutex(s.lock);gx_frame_pump(true);SDL_LockMutex(s.lock);}else SDL_CondWait(s.changed,s.lock);
        s.wait_ticks+=SDL_GetPerformanceCounter()-at;
    }
}
void* gx_frame_alloc(u32 bytes){
    if(!s.active || !bytes || bytes>64u*1024u*1024u-15)return NULL;bytes=(bytes+15u)&~15u;
    Slot* slot=s.building<2 ? s.slots+s.building:acquire();if(!slot)return NULL;
    if(bytes>64u*1024u*1024u-slot->used){if(!gx_frame_submit(false))return NULL;slot=acquire();if(!slot)return NULL;}
    u32 needed=slot->used+bytes;
    if(needed>slot->capacity){u32 capacity=slot->capacity ? slot->capacity:1048576u;while(capacity<needed)capacity*=2;
        u8* storage=realloc(slot->bytes,capacity);if(!storage)return NULL;slot->bytes=storage;slot->capacity=capacity;}
    void* result=slot->bytes+slot->used;slot->used+=bytes;return result;
}
bool gx_frame_submit(bool wait){
    if(!s.active)return true;
    SDL_LockMutex(s.lock);
    if(s.building<2){Slot* slot=s.slots+s.building;if(slot->used){slot->ticket=++s.issued;slot->state=READY;SDL_SemPost(s.ready);}else slot->state=FREE;s.building=2;}
    u64 target=s.issued;
    while(wait && s.completed<target && !s.failed){u64 at=SDL_GetPerformanceCounter();
        if(SDL_ThreadID()==s.owner){SDL_UnlockMutex(s.lock);gx_frame_pump(true);SDL_LockMutex(s.lock);}else SDL_CondWait(s.changed,s.lock);
        s.wait_ticks+=SDL_GetPerformanceCounter()-at;}
    bool ok=!s.failed;SDL_UnlockMutex(s.lock);return ok;
}
bool gx_frame_drain(void){return gx_frame_submit(true);}
void gx_frame_stats(GXFrameStats* result){
    if(!s.active){memset(result,0,sizeof(*result));return;}
    SDL_LockMutex(s.lock);*result=s.stats;result->wait_ticks=s.wait_ticks;SDL_UnlockMutex(s.lock);
}
bool gx_frame_stop(void){
    if(!s.active)return true;bool ok=gx_frame_drain();
    for(u32 i=0;i<2;i++)free(s.slots[i].bytes);
    SDL_DestroyCond(s.changed);SDL_DestroySemaphore(s.ready);SDL_DestroyMutex(s.lock);memset(&s,0,sizeof(s));return ok;
}
