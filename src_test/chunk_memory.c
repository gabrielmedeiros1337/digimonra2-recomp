#include "chunk_memory.h"
#ifdef _MSC_VER
#define CHUNK_COLD __declspec(noinline)
#else
#define CHUNK_COLD __attribute__((noinline))
#endif
#define CHUNK_SLOW(bits,type) \
CHUNK_COLD type chunk_read##bits##_slow(CPUState* cpu,u32 address,u32 cia){cpu->pc=cia;return mem_read##bits(cpu,address);} \
CHUNK_COLD void chunk_write##bits##_slow(CPUState* cpu,u32 address,type value,u32 cia){cpu->pc=cia;mem_write##bits(cpu,address,value);}
CHUNK_SLOW(8,u8)
CHUNK_SLOW(16,u16)
CHUNK_SLOW(32,u32)
CHUNK_SLOW(64,u64)
