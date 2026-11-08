#include "gx_decode_async.h"
#include <SDL.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>
#if defined(_M_X64) || defined(__x86_64__)
#include <xmmintrin.h>
#endif
struct GXRawSnapshot {
    VertexLayout layout;size_t bytes;u32 count,matrix[3],minimum[12],stride[12];
    const u8* array[12];u32 array_bytes[12];u8* packet;int rounding;u32 mxcsr;
};
static u32 scalar_bytes(u32 f){return f<2 ? 1:f<4 ? 2:4;}
static u32 color_bytes(u32 f){static const u8 n[]={2,3,4,2,3,4,4,4};return n[f&7];}
static u32 index_at(const u8* p,u32 size){return size==1 ? p[0]:((u32)p[0]<<8)|p[1];}
GXRawSnapshot* gx_raw_snapshot(CPUState* cpu,const VertexLayout* l,const u32* cp,const u8* fifo,u32 fifo_bytes,u32 cursor,u32 count){
    if(!count || !fifo_bytes || (u64)count*l->stride>=fifo_bytes)return NULL;
    u32 matrix_bytes=0;for(u32 j=0;j<9;j++)matrix_bytes+=(cp[0x50]>>j)&1u;
    if(matrix_bytes!=l->matrix_bytes || l->components[0]>3 || (l->mode[1] && l->components[1]<3))return NULL;
    for(u32 j=4;j<12;j++)if(l->components[j]>2)return NULL;
    u32 bytes=count*l->stride,at=cursor%fifo_bytes,first=fifo_bytes-at;if(first>bytes)first=bytes;
    GXRawSnapshot* s=calloc(1,sizeof(*s));if(!s)return NULL;
    s->packet=malloc(bytes);if(!s->packet){free(s);return NULL;}
    memcpy(s->packet,fifo+at,first);if(first<bytes)memcpy(s->packet+first,fifo,bytes-first);
    s->layout=*l;s->count=count;s->matrix[0]=cp[0x30];s->matrix[1]=cp[0x40];s->matrix[2]=cp[0x50];s->rounding=fegetround();
#if defined(_M_X64) || defined(__x86_64__)
    s->mxcsr=_mm_getcsr();
#endif
    u32 offset=l->matrix_bytes;size_t total=bytes;
    for(u32 j=0;j<12;j++){
        u32 mode=l->mode[j];if(!mode)continue;
        u32 size=j==2 || j==3 ? color_bytes(l->format[j]):l->components[j]*scalar_bytes(l->format[j]);
        if(mode==1){offset+=size;continue;}
        u32 nbytes=mode-1,indices=j==1 ? l->normal_indices:1;
        if(offset+nbytes*indices>l->stride)goto fail;
        u32 lo=~0u,hi=0;
        for(u32 i=0;i<count;i++){u32 v=index_at(s->packet+i*l->stride+offset,nbytes);if(v<lo)lo=v;if(v>hi)hi=v;}
        s->minimum[j]=lo;s->stride[j]=cp[0xB0+j]&255u;
        u64 begin=(cp[0xA0+j]&0x1FFFFFFu)+(u64)lo*s->stride[j],end=(cp[0xA0+j]&0x1FFFFFFu)+(u64)hi*s->stride[j]+size;
        if(begin>end || end>cpu->ram_size || end-begin>4u*1024u*1024u-total)goto fail;
        u32 length=(u32)(end-begin);u8* p=malloc(length ? length:1);if(!p)goto fail;
        memcpy(p,cpu->ram+(u32)begin,length);s->array[j]=p;s->array_bytes[j]=length;total+=length;
        offset+=nbytes*indices;
    }
    if(offset!=l->stride)goto fail;s->bytes=sizeof(*s)+total;return s;
fail:gx_raw_free(s);return NULL;
}
size_t gx_raw_size(const GXRawSnapshot* s){return s->bytes;}
void gx_raw_free(GXRawSnapshot* s){if(!s)return;for(u32 j=0;j<12;j++)free((void*)s->array[j]);free(s->packet);free(s);}
static float scalar(const u8* p,u32 format,u32 fraction){
    if(format>=4){u32 bits=((u32)p[0]<<24)|((u32)p[1]<<16)|((u32)p[2]<<8)|p[3];float v;memcpy(&v,&bits,4);return v;}
    int value=format==0 ? p[0]:format==1 ? (s8)p[0]:format==2 ? ((int)p[0]<<8)|p[1]:(s16)(((u32)p[0]<<8)|p[1]);
    u32 bits=(127u-fraction)<<23;float scale;memcpy(&scale,&bits,4);return (float)value*scale;
}
static void decode(const GXRawSnapshot* s,GXGLRawVertex* output,u64* hits,u64* misses){
    u32 indices[4096]={0};
    const VertexLayout* l=&s->layout;
    for(u32 i=0;i<s->count;i++){
        GXGLRawVertex* out=output+i;
        const u8* p=s->packet+i*l->stride;u32 slot=0;
        bool reusable=l->mode[0]>=2 && l->stride<=64;
        if(reusable){
            u32 hash=2166136261u;for(u32 j=0;j<l->stride;j++)hash=(hash^p[j])*16777619u;
            slot=hash&4095u;u32 prior=indices[slot];
            if(prior && !memcmp(s->packet+(prior-1)*l->stride,p,l->stride)){
                *out=output[prior-1];(*hits)++;continue;
            }
        }
        (*misses)++;memset(out,0,sizeof(*out));memset(out->color,255,4);u32 matrix=s->matrix[0]&63u;
        for(u32 j=0;j<8;j++)out->tex_matrix[j]=(u8)(j<4 ? (s->matrix[0]>>(6+j*6))&63u:(s->matrix[1]>>((j-4)*6))&63u);
        for(u32 j=0;j<9;j++)if((s->matrix[2]>>j)&1u){u8 index=*p++ &63u;if(!j)matrix=index;else out->tex_matrix[j-1]=index;}
        out->matrix=matrix;
        for(u32 j=0;j<12;j++){
            u32 mode=l->mode[j];if(!mode)continue;
            u32 size=j==2 || j==3 ? color_bytes(l->format[j]):l->components[j]*scalar_bytes(l->format[j]);
            const u8* data=p;u8 zero[36]={0};
            if(mode==1)p+=size;
            else{
                u32 index=index_at(p,mode-1),indices=j==1 ? l->normal_indices:1;p+=indices*(mode-1);
                u64 at=(u64)(index-s->minimum[j])*s->stride[j];
                data=index>=s->minimum[j] && at+size<=s->array_bytes[j] ? s->array[j]+(size_t)at:zero;
            }
            if(j==0)for(u32 k=0;k<l->components[j];k++)out->position[k]=scalar(data+k*scalar_bytes(l->format[j]),l->format[j],l->fraction[j]);
            else if(j==1)for(u32 k=0;k<3;k++)out->normal[k]=scalar(data+k*scalar_bytes(l->format[j]),l->format[j],l->format[j]==1 ? 6:l->format[j]==3 ? 14:0);
            else if(j==2){
                u32 f=l->format[j],word=((u32)data[0]<<8)|data[1];
                if(f==0){out->color[0]=(u8)(((word>>11)&31)*255/31);out->color[1]=(u8)(((word>>5)&63)*255/63);out->color[2]=(u8)((word&31)*255/31);}
                else if(f==3){out->color[0]=(u8)((word>>12)*17);out->color[1]=(u8)(((word>>8)&15)*17);out->color[2]=(u8)(((word>>4)&15)*17);out->color[3]=(u8)((word&15)*17);}
                else if(f==4){word=(word<<8)|data[2];out->color[0]=(u8)(((word>>18)&63)*255/63);out->color[1]=(u8)(((word>>12)&63)*255/63);out->color[2]=(u8)(((word>>6)&63)*255/63);out->color[3]=(u8)((word&63)*255/63);}
                else{out->color[0]=data[0];out->color[1]=data[1];out->color[2]=data[2];if(f==5)out->color[3]=data[3];}
            }else if(j>=4){out->texcoord[j-4][0]=scalar(data,l->format[j],l->fraction[j]);if(l->components[j]>1)out->texcoord[j-4][1]=scalar(data+scalar_bytes(l->format[j]),l->format[j],l->fraction[j]);out->texcoord[j-4][2]=1;}
        }
        if(reusable)indices[slot]=i+1;
    }
}
// The worker owns no CPUState, guest pointers, GX state or GL context. Only
// immutable snapshots and its disjoint raw output span cross this boundary.
static SDL_Thread* thread;static SDL_mutex* lock;static SDL_cond* ready;static SDL_cond* finished;
static GXRawWork* queue[128];static u64 submitted,completed,popped;static bool stop;
static int worker(void* unused){
    (void)unused;
    for(;;){
        SDL_LockMutex(lock);while(popped==submitted && !stop)SDL_CondWait(ready,lock);
        if(stop){SDL_UnlockMutex(lock);return 0;}
        GXRawWork* w=queue[popped++%128];SDL_UnlockMutex(lock);
        fesetround(w->input->rounding);
#if defined(_M_X64) || defined(__x86_64__)
        _mm_setcsr(w->input->mxcsr);
#endif
        u64 began=SDL_GetPerformanceCounter();w->vertex_hits=w->vertex_misses=0;decode(w->input,w->output,&w->vertex_hits,&w->vertex_misses);
        w->raw_hash=w->hash ? w->hash(w->output,(size_t)w->input->count*sizeof(*w->output)):0;
        w->ticks=SDL_GetPerformanceCounter()-began;
        SDL_LockMutex(lock);completed++;SDL_CondBroadcast(finished);SDL_UnlockMutex(lock);
    }
}
static bool initialize(void){
    if(thread)return true;
    lock=SDL_CreateMutex();ready=SDL_CreateCond();finished=SDL_CreateCond();
    if(lock && ready && finished)thread=SDL_CreateThread(worker,"GX raw snapshots",NULL);
    if(thread)return true;
    if(lock)SDL_DestroyMutex(lock);if(ready)SDL_DestroyCond(ready);if(finished)SDL_DestroyCond(finished);
    lock=NULL;ready=finished=NULL;return false;
}
bool gx_raw_async_submit(GXRawWork* w){
    if(!initialize())return false;
    SDL_LockMutex(lock);
    if(submitted-completed>=128){SDL_UnlockMutex(lock);return false;}
    queue[submitted++%128]=w;SDL_CondSignal(ready);SDL_UnlockMutex(lock);return true;
}
void gx_raw_async_wait(void){if(!thread)return;SDL_LockMutex(lock);while(completed!=submitted)SDL_CondWait(finished,lock);SDL_UnlockMutex(lock);}
void gx_raw_async_shutdown(void){
    if(!thread)return;gx_raw_async_wait();SDL_LockMutex(lock);stop=true;SDL_CondSignal(ready);SDL_UnlockMutex(lock);SDL_WaitThread(thread,NULL);
    SDL_DestroyMutex(lock);SDL_DestroyCond(ready);SDL_DestroyCond(finished);thread=NULL;lock=NULL;ready=finished=NULL;stop=false;submitted=completed=popped=0;
}
