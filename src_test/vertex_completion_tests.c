#define SDL_MAIN_HANDLED
#include "vertex_completion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
typedef struct {VertexCompletion* group;SDL_sem* ready;SDL_Thread* thread;unsigned id,sequence,output[32];bool stop;} Job;
static int worker(void* data) {
    Job* j=(Job*)data;
    for(;;) {
        if(SDL_SemWait(j->ready)!=0)abort();if(j->stop)return 0;
        if((j->sequence+j->id)%67==0)SDL_Delay(1);
        for(unsigned i=0;i<32;i++)j->output[i]=(j->sequence*2654435761u)^(i*97u)^j->id;
        if(!vertex_completion_finish(j->group))abort();
    }
}
int main(void) {
    SDL_SetMainReady();CHECK(SDL_Init(SDL_INIT_TIMER)==0);
    VertexCompletion group;CHECK(vertex_completion_init(&group));Job jobs[3]={0};
    for(unsigned j=0;j<3;j++) {
        jobs[j].group=&group;jobs[j].id=j;jobs[j].ready=SDL_CreateSemaphore(0);CHECK(jobs[j].ready);
        jobs[j].thread=SDL_CreateThread(worker,"completion contract",&jobs[j]);CHECK(jobs[j].thread);
    }
    unsigned batches=0;
    for(unsigned round=0;round<1536;round++)for(unsigned count=0;count<=3;count++) {
        vertex_completion_begin(&group,(int)count);
        for(unsigned j=0;j<count;j++){jobs[j].sequence=round+count*10000u;CHECK(SDL_SemPost(jobs[j].ready)==0);}
        if(round%64==0)SDL_Delay(1);else if(round%17==0)SDL_Delay(0);
        CHECK(vertex_completion_wait(&group));
        for(unsigned j=0;j<count;j++)for(unsigned i=0;i<32;i++)CHECK(jobs[j].output[i]==((jobs[j].sequence*2654435761u)^(i*97u)^j));
        CHECK(SDL_SemValue(group.done)==0);batches++;
    }
    for(unsigned j=0;j<3;j++){jobs[j].stop=true;CHECK(SDL_SemPost(jobs[j].ready)==0);}
    for(unsigned j=0;j<3;j++){int status=-1;SDL_WaitThread(jobs[j].thread,&status);CHECK(status==0);SDL_DestroySemaphore(jobs[j].ready);}
    vertex_completion_destroy(&group);CHECK(vertex_completion_init(&group));vertex_completion_begin(&group,0);CHECK(vertex_completion_wait(&group));vertex_completion_destroy(&group);
    SDL_Quit();printf("[Vertex completion] %u batches, 0..3 workers, output visibility, early/late wait, no stale tokens, restart passed\n",batches);return 0;
}
