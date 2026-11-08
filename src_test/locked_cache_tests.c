#include "locked_cache.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define CHECK(x) do {if(!(x)){fprintf(stderr,"LC contract line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static double now(void) {
#ifdef _WIN32
    LARGE_INTEGER value,frequency;QueryPerformanceCounter(&value);QueryPerformanceFrequency(&frequency);
    return (double)value.QuadPart/(double)frequency.QuadPart;
#else
    return (double)clock()/CLOCKS_PER_SEC;
#endif
}
static void transfer(CPUState* cpu,u32 memory,u32 cache,u32 blocks,bool load) {
    u32 encoded=blocks&127u;
    locked_cache_spr_write(cpu,922,memory|(encoded>>2));
    locked_cache_spr_write(cpu,923,cache|((encoded&3u)<<2)|2u|(load ? 16u:0));
}
int main(int argc,char** argv) {
    u8 ram[8192],expected_ram[8192],expected_cache[16384];
    CPUState cpu={0};cpu.ram=ram;cpu.ram_size=sizeof(ram);locked_cache_reset();
    u8* cache=locked_cache_pointer(0xE0000000u,16384);CHECK(cache);
    const u32 offsets[]={0,32,4096,8192,12288,16320,16352};u32 cases=0,status;
    for(u32 load=0;load<2;load++)for(u32 n=0;n<7;n++)for(u32 blocks=1;blocks<=128;blocks++) {
        for(u32 i=0;i<sizeof(ram);i++)ram[i]=(u8)(i*31u+cases*37u);
        for(u32 i=0;i<16384;i++)cache[i]=(u8)(i*17u+cases*53u+3u);
        memcpy(expected_ram,ram,sizeof(ram));memcpy(expected_cache,cache,16384);
        // Hardware reference: each byte advances modulo 16 KiB in LC, while
        // the RAM address advances linearly. Compare all bytes, not just output.
        for(u32 i=0;i<blocks*32;i++) {
            u32 at=(offsets[n]+i)&16383u;
            if(load)expected_cache[at]=ram[4096+i];else expected_ram[4096+i]=cache[at];
        }
        transfer(&cpu,4096,offsets[n],blocks,load!=0);
        CHECK(!memcmp(ram,expected_ram,sizeof(ram)) && !memcmp(cache,expected_cache,16384));
        CHECK(locked_cache_spr_read(922,&status) && status==(4096|((blocks&127u)>>2)));
        CHECK(locked_cache_spr_read(923,&status) && status==(offsets[n]|(((blocks&127u)&3u)<<2)|(load ? 16u:0)));
        cases++;
    }
    // Invalid RAM spans and writes without the start bit must not transfer.
    memcpy(expected_ram,ram,sizeof(ram));memcpy(expected_cache,cache,16384);
    transfer(&cpu,8160,16352,2,true);transfer(&cpu,8160,16352,2,false);
    locked_cache_spr_write(&cpu,922,4096);locked_cache_spr_write(&cpu,923,16);
    CHECK(!memcmp(ram,expected_ram,sizeof(ram)) && !memcmp(cache,expected_cache,16384));
    CHECK(locked_cache_spr_read(923,&status) && status==16);
    CHECK(!locked_cache_spr_write(&cpu,924,0));
    printf("[LC DMA] %u transfers: full RAM/LC, wrap, zero=128 and status match\n",cases);
    if(argc==2 && !strcmp(argv[1],"--bench")) {
        const u32 repeats=500000;double start=now();
        for(u32 i=0;i<repeats;i++)transfer(&cpu,4096,(i*32u)&16383u,7,true);
        double elapsed=now()-start;u32 checksum=2166136261u;
        for(u32 i=0;i<16384;i++)checksum=(checksum^cache[i])*16777619u;
        printf("[LC DMA benchmark] bytes=%u transfers=%u time_ms=%.3f checksum=%08X\n",repeats*224u,repeats,elapsed*1000.0,checksum);
    }
    return 0;
}
