#define SDL_MAIN_HANDLED
#include "gx_decode_async.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"async FAIL line%d: %s\n",__LINE__,#x);return 1;}}while(0)
int main(void){
    CHECK(SDL_Init(SDL_INIT_TIMER)==0);u8 ram[8192]={0},fifo[4096]={0};u32 cp[256]={0};CPUState c={0};c.ram=ram;c.ram_size=sizeof(ram);
    GXGLRawVertex out[64],repeated[64];VertexLayout l={0};l.stride=8;l.mode[0]=3;l.components[0]=3;l.format[0]=3;l.fraction[0]=1;l.mode[2]=1;l.format[2]=5;l.matrix_bytes=2;l.normal_indices=1;
    cp[0x30]=4;cp[0x40]=60;cp[0x50]=3;cp[0xA0]=0x100;cp[0xB0]=6;
    for(u32 i=0;i<64;i++){
        u8* p=ram+0x100+i*6;for(u32 j=0;j<3;j++){u16 v=(u16)(i*4+j*2);p[j*2]=(u8)(v>>8);p[j*2+1]=(u8)v;}
        u8* f=fifo+i*8;f[0]=9;f[1]=12;f[2]=0;f[3]=(u8)i;f[4]=10;f[5]=20;f[6]=30;f[7]=40;
    }
    GXRawSnapshot* s=gx_raw_snapshot(&c,&l,cp,fifo,sizeof(fifo),0,64);CHECK(s);
    for(u32 i=0;i<64;i++)fifo[i*8+3]=(u8)(i%4);
    GXRawSnapshot* repeat=gx_raw_snapshot(&c,&l,cp,fifo,sizeof(fifo),0,64);CHECK(repeat);
    // Strong lifetime test: producer memory is reused BEFORE the worker starts.
    memset(ram,0xFF,sizeof(ram));memset(fifo,0xAB,sizeof(fifo));memset(cp,0,sizeof(cp));
    GXRawWork w={0},r={0};w.input=s;w.output=out;r.input=repeat;r.output=repeated;CHECK(gx_raw_async_submit(&w) && gx_raw_async_submit(&r));gx_raw_async_wait();
    for(u32 i=0;i<64;i++){CHECK(out[i].matrix==9 && out[i].tex_matrix[0]==12);for(u32 j=0;j<3;j++)CHECK(out[i].position[j]==i*2+j);CHECK(out[i].color[0]==10 && out[i].color[3]==40);}
    CHECK(w.vertex_misses==64 && w.vertex_hits==0 && r.vertex_misses==4 && r.vertex_hits==60);
    for(u32 i=0;i<64;i++)CHECK(!memcmp(repeated+i,out+i%4,sizeof(*out)));
    gx_raw_free(repeat);gx_raw_free(s);gx_raw_async_shutdown();SDL_Quit();puts("[GX async snapshots]64 indexed vertices; CP/FIFO/RAM reused before scheduling, matrix indices/color preserved");return 0;
}
