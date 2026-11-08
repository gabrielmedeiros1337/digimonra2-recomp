#include "gx_images.h"
#include <stdlib.h>
#include <string.h>
#ifdef DIGIMON_XXHASH
#include "xxhash.h"
#endif
#define SOURCES 128
#define PALETTES 128
#define SOURCE_BUDGET (32u*1024u*1024u)
struct GXSourceImage {u32 address,bytes,id,refs,next,nversions;u64 used;u8* data;u64* versions;};
struct GXPaletteImage {u32 bytes,id,refs,next;u8 format;u64 hash,used;u8* data;};
static GXSourceImage sources[SOURCES];static GXPaletteImage palettes[PALETTES];
static u32 source_buckets[256],palette_buckets[256],source_serial,palette_serial;
static u64 clock_serial,source_hits,source_copies,palette_hits,palette_copies;static size_t source_bytes;
static u64 version_scratch[1026];
static u32 source_bucket(u32 address,u32 bytes){u32 h=address^(bytes*0x9E3779B9u);h^=h>>16;return h&255u;}
static u32 palette_bucket(u64 hash,u32 bytes,u8 fmt){return (u32)(hash^(hash>>32)^bytes^fmt)&255u;}
static void unlink_source(u32 slot){
    GXSourceImage* p=sources+slot;if(!p->data)return;
    u32* link=source_buckets+source_bucket(p->address,p->bytes);
    while(*link && *link!=slot+1)link=&sources[*link-1].next;
    if(*link)*link=p->next;source_bytes-=p->bytes;free(p->data);free(p->versions);memset(p,0,sizeof(*p));
}
static void unlink_palette(u32 slot){
    GXPaletteImage* p=palettes+slot;if(!p->data)return;
    u32* link=palette_buckets+palette_bucket(p->hash,p->bytes,p->format);
    while(*link && *link!=slot+1)link=&palettes[*link-1].next;
    if(*link)*link=p->next;free(p->data);memset(p,0,sizeof(*p));
}
static u32 oldest_source(void){u32 slot=SOURCES;for(u32 i=0;i<SOURCES;i++)if(!sources[i].refs && sources[i].data && (slot==SOURCES || sources[i].used<sources[slot].used))slot=i;return slot;}
static void remember_versions(GXSourceImage* image,u32 count){
    if(!count){image->nversions=0;return;}
    u64* data=realloc(image->versions,count*sizeof(u64));
    if(!data){image->nversions=0;return;}
    image->versions=data;memcpy(data,version_scratch,count*sizeof(u64));image->nversions=count;
}
static GXSourceImage* source_capture(CPUState* cpu,u32 address,u32 bytes){
    if(address<GC_RAM_BASE || !bytes || bytes>SOURCE_BUDGET)return NULL;
    u32 offset=address-GC_RAM_BASE;if(offset>cpu->ram_size || bytes>cpu->ram_size-offset)return NULL;
    const u8* input=cpu->ram+offset;u32 versions=0,bucket=source_bucket(address,bytes);
    if(!ppc_ram_page_versions(cpu,offset,bytes,version_scratch,1026,&versions))versions=0;
    for(u32 id=source_buckets[bucket];id;id=sources[id-1].next){
        GXSourceImage* p=sources+id-1;if(p->address!=address || p->bytes!=bytes)continue;
        bool same=versions && p->nversions==versions && !memcmp(p->versions,version_scratch,versions*sizeof(u64));
        if(same || !memcmp(p->data,input,bytes)){
            if(!same)remember_versions(p,versions);p->refs++;p->used=++clock_serial;source_hits++;return p;
        }
    }
    if(source_serial==0xFFFFFFFFu)return NULL;
    while(source_bytes+bytes>SOURCE_BUDGET){u32 old=oldest_source();if(old==SOURCES)return NULL;unlink_source(old);}
    u32 slot=SOURCES;for(u32 i=0;i<SOURCES;i++)if(!sources[i].data){slot=i;break;}
    if(slot==SOURCES){slot=oldest_source();if(slot==SOURCES)return NULL;unlink_source(slot);}
    u8* data=malloc(bytes);if(!data)return NULL;memcpy(data,input,bytes);
    GXSourceImage* p=sources+slot;*p=(GXSourceImage){0};p->address=address;p->bytes=bytes;p->data=data;p->id=++source_serial;p->refs=1;p->used=++clock_serial;
    remember_versions(p,versions);p->next=source_buckets[bucket];source_buckets[bucket]=slot+1;source_bytes+=bytes;source_copies+=bytes;return p;
}
static GXPaletteImage* palette_capture(const u8* input,u32 bytes,u8 format){
    if(!input || !bytes || bytes>32768)return NULL;
#ifdef DIGIMON_XXHASH
    u64 hash=XXH64(input,bytes,0x544C5554u);
#else
    u64 hash=0xCBF29CE484222325ull;for(u32 i=0;i<bytes;i++)hash=(hash^input[i])*0x100000001B3ull;
#endif
    u32 bucket=palette_bucket(hash,bytes,format);
    for(u32 id=palette_buckets[bucket];id;id=palettes[id-1].next){GXPaletteImage* p=palettes+id-1;
        if(p->bytes==bytes && p->format==format && p->hash==hash && !memcmp(p->data,input,bytes)){
            p->refs++;p->used=++clock_serial;palette_hits++;return p;
        }
    }
    if(palette_serial==0xFFFFFFFFu)return NULL;
    u32 slot=PALETTES;for(u32 i=0;i<PALETTES;i++)if(!palettes[i].data){slot=i;break;}
    if(slot==PALETTES){for(u32 i=0;i<PALETTES;i++)if(!palettes[i].refs && (slot==PALETTES || palettes[i].used<palettes[slot].used))slot=i;
        if(slot==PALETTES)return NULL;unlink_palette(slot);}
    u8* data=malloc(bytes);if(!data)return NULL;memcpy(data,input,bytes);
    GXPaletteImage* p=palettes+slot;*p=(GXPaletteImage){0};p->bytes=bytes;p->format=format;p->hash=hash;p->id=++palette_serial;p->refs=1;p->used=++clock_serial;p->data=data;
    p->next=palette_buckets[bucket];palette_buckets[bucket]=slot+1;palette_copies+=bytes;return p;
}
bool gx_images_capture(CPUState* cpu,u32 address,u32 bytes,const u8* palette,u32 palette_bytes,u8 format,GXImageSnapshot* out){
    *out=(GXImageSnapshot){0};out->source=source_capture(cpu,address,bytes);if(!out->source)return false;
    if(palette_bytes){out->palette=palette_capture(palette,palette_bytes,format);if(!out->palette){gx_images_release(out);return false;}}
    return true;
}
void gx_images_release(GXImageSnapshot* image){if(image->source)image->source->refs--;if(image->palette)image->palette->refs--;*image=(GXImageSnapshot){0};}
const u8* gx_images_raw(const GXImageSnapshot* image){return image->source ? image->source->data:NULL;}
const u8* gx_images_palette(const GXImageSnapshot* image){return image->palette ? image->palette->data:NULL;}
u64 gx_images_key(const GXImageSnapshot* image){return image->source ? ((u64)image->source->id<<32)|(image->palette ? image->palette->id:0):0;}
void gx_images_stats(u64* sh,u64* sb,u64* ph,u64* pb){*sh=source_hits;*sb=source_copies;*ph=palette_hits;*pb=palette_copies;}
void gx_images_shutdown(void){
    for(u32 i=0;i<SOURCES;i++)unlink_source(i);for(u32 i=0;i<PALETTES;i++)unlink_palette(i);
    memset(source_buckets,0,sizeof(source_buckets));memset(palette_buckets,0,sizeof(palette_buckets));source_serial=palette_serial=0;source_bytes=0;
}
