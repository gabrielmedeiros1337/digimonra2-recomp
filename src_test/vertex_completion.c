#include "vertex_completion.h"
#define WAITER 0x10000
bool vertex_completion_init(VertexCompletion* g) {
    SDL_AtomicSet(&g->state,0);g->done=SDL_CreateSemaphore(0);return g->done!=NULL;
}
void vertex_completion_begin(VertexCompletion* g,int workers) {SDL_AtomicSet(&g->state,workers);}
bool vertex_completion_finish(VertexCompletion* g) {
    // Each worker publishes its output before decrementing the count. SDL's
    // modifying atomics are full barriers. Only the last registered waiter
    // receives a notification; completed-before-wait batches need no signal.
    int previous=SDL_AtomicAdd(&g->state,-1);
    return previous!=WAITER+1 || SDL_SemPost(g->done)==0;
}
bool vertex_completion_wait(VertexCompletion* g) {
    for(;;) {
        int state=SDL_AtomicGet(&g->state);
        if(!(state&0xFFFF)){SDL_MemoryBarrierAcquire();return true;}
        // Register before the final worker completes, or retry after its CAS
        // race. Exactly one signal is consumed; no token leaks to next batch.
        if(SDL_AtomicCAS(&g->state,state,state|WAITER)) {
            if(SDL_SemWait(g->done)!=0)return false;
            SDL_MemoryBarrierAcquire();return true;
        }
    }
}
void vertex_completion_destroy(VertexCompletion* g) {
    if(g->done)SDL_DestroySemaphore(g->done);g->done=NULL;SDL_AtomicSet(&g->state,0);
}
