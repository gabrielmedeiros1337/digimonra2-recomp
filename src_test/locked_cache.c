#include "locked_cache.h"
#include <stdio.h>
#include <string.h>

static u8 s_cache[16384];
static u32 s_upper,s_lower,s_transfers;
void* locked_cache_pointer(u32 address,u32 size) {
    return size && address>=0xE0000000u && size<=sizeof(s_cache) && address-0xE0000000u<=sizeof(s_cache)-size ? s_cache+(address-0xE0000000u) : NULL;
}
void locked_cache_reset(void){memset(s_cache,0,sizeof(s_cache));s_upper=s_lower=s_transfers=0;}
bool locked_cache_address(u32 address,u8 size) {
    return size && size<=8 && address>=0xE0000000u && address-0xE0000000u<=sizeof(s_cache)-size;
}
u64 locked_cache_read(u32 address,u8 size) {
    u64 value=0;u32 at=address-0xE0000000u;
    for(u8 i=0;i<size;i++)value=(value<<8)|s_cache[at+i];return value;
}
void locked_cache_write(u32 address,u64 value,u8 size) {
    u32 at=address-0xE0000000u;
    for(u8 i=0;i<size;i++)s_cache[at+size-1-i]=(u8)(value>>(i*8));
}
bool locked_cache_spr_read(u16 spr,u32* value) {
    if(spr==922){*value=s_upper;return true;}
    if(spr==923){*value=s_lower;return true;}
    return false;
}
bool locked_cache_spr_write(CPUState* cpu,u16 spr,u32 value) {
    if(spr==922){s_upper=value;return true;}
    if(spr!=923)return false;
    s_lower=value;
    if(value&2u) {
        u32 memory=s_upper&0x1FFFFFE0u,cache=value&0x3FE0u;
        u32 blocks=((s_upper&31u)<<2)|((value>>2)&3u);
        if(!blocks)blocks=128;
        u32 bytes=blocks*32;
        if(memory<=cpu->ram_size && bytes<=cpu->ram_size-memory) {
            // One DMA is at most 4096 bytes, so it crosses the 16 KiB LC
            // boundary at most once. RAM remains linear on either side.
            u32 first=(u32)sizeof(s_cache)-cache;if(first>bytes)first=bytes;
            if(value&16u) {
                memcpy(s_cache+cache,cpu->ram+memory,first);
                if(bytes>first)memcpy(s_cache,cpu->ram+memory+first,bytes-first);
            }else {
                ppc_mark_host_write(cpu->ram+memory,bytes);
                memcpy(cpu->ram+memory,s_cache+cache,first);
                if(bytes>first)memcpy(cpu->ram+memory+first,s_cache,bytes-first);
            }
            if(s_transfers++<8)printf("[Locked cache DMA] %s RAM=%08X LC=%04X bytes=%u\n",(value&16u) ? "load" : "store",memory,cache,bytes);
        }else fprintf(stderr,"[Locked cache DMA] invalid RAM range %08X + %u\n",memory,bytes);
    }
    /* Transfers complete synchronously; the trigger and queue cannot stay busy. */
    s_lower&=~2u;
    return true;
}
