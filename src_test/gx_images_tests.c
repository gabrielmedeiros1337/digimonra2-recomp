#include "gx_images.h"
#include <stdio.h>
#include <string.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"images FAIL line%d: %s\n",__LINE__,#x);return 1;}}while(0)
int main(void){
    CPUState c={0};CHECK(cpu_init(&c));u8 red[32]={0xF8,0},green[32]={0x07,0xE0};
    for(u32 i=0;i<32;i++)mem_write8(&c,0x80008000u+i,(u8)i);
    GXImageSnapshot a,b,same;CHECK(gx_images_capture(&c,0x80008000,32,red,32,1,&a));u64 key=gx_images_key(&a);
    CHECK(gx_images_capture(&c,0x80008000,32,red,32,1,&same) && gx_images_key(&same)==key);gx_images_release(&same);
    mem_write8(&c,0x80008080,123); // same4KB page, outside source: preserve content identity
    CHECK(gx_images_capture(&c,0x80008000,32,red,32,1,&same) && gx_images_key(&same)==key);gx_images_release(&same);
    mem_write8(&c,0x80008000,222);CHECK(gx_images_capture(&c,0x80008000,32,green,32,1,&b));
    CHECK(gx_images_key(&b)!=key && gx_images_raw(&a)[0]==0 && gx_images_raw(&b)[0]==222);
    memset(red,0,sizeof(red));memset(green,0,sizeof(green));CHECK(gx_images_palette(&a)[0]==0xF8 && gx_images_palette(&b)[1]==0xE0);
    u64 queries,dirty,after;ppc_ram_watch_stats(&queries,&dirty);
    for(u32 i=0;i<128;i++){CHECK(gx_images_capture(&c,0x80008000,32,NULL,0,0,&same));gx_images_release(&same);}
    ppc_ram_watch_stats(&after,&dirty);CHECK(queries==after);
    gx_images_release(&a);gx_images_release(&b);gx_images_shutdown();cpu_free(&c);
    puts("[Immutable GX images] source copy-on-write, palette ownership, page false-sharing content identity,128lookups without OS queries passed");return 0;
}
