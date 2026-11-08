#include "native_copy.h"
#include "cpu/ps_fast.h"
#include <string.h>
extern bool g_native_blocks_enabled;
static u64 copied;
u64 native_copy_bytes(void){return copied;}
void native_copy_tail(CPUState* c,u32 source,u32 dest,u32 counter){
    u32 remaining=c->gpr[counter];
    if(!g_native_blocks_enabled || c->downcount>4096 || !remaining || remaining%24 || remaining>4096 || c->downcount<=-256 ||
       c->exception || c->reserve_valid || g_mem_write_journal || c->cache_control)return;
    u32 iterations=(u32)((c->downcount+256+15)/16);if(iterations>remaining/24)iterations=remaining/24;
    u32 bytes=iterations*24;if(!bytes)return;
    const u8* input=psq_direct_pointer(c,c->gpr[source],bytes);
    u8* output=psq_direct_pointer(c,c->gpr[dest]+24,bytes);
    if(!input || !output || ((uintptr_t)input<(uintptr_t)output+bytes && (uintptr_t)output<(uintptr_t)input+bytes))return;
    ppc_mark_host_write(output,bytes);
    // Bitwise matrix copies need no endian round trip. SSE2 handles the16-byte
    // prefix, followed by the8-byte tail, for each original24-byte iteration.
    for(u32 i=0;i<bytes;i+=24){
#if defined(_M_X64) || defined(__x86_64__)
        _mm_storeu_si128((__m128i*)(output+i),_mm_loadu_si128((const __m128i*)(input+i)));
#else
        memcpy(output+i,input+i,16);
#endif
        memcpy(output+i+16,input+i+16,8);
    }
    c->gpr[0]=psq_read_be(input+bytes-4,4);c->gpr[source]+=bytes;c->gpr[dest]+=bytes;
    c->gpr[counter]-=bytes;c->downcount-=iterations*16u;c->xer|=0x20000000u;
    u32 cr=(c->gpr[counter] ? 4u:2u)|((c->xer>>31)&1u);c->cr=(c->cr&0x0FFFFFFFu)|(cr<<28);copied+=bytes;
}
