#include "paired_skinning.h"
#include "sdk_mtx44.h"
extern void platform_continue_cpu_slice(void);
bool g_native_blocks_enabled=true;
static u64 s_block_entries;
u64 platform_native_block_entries(void){return s_block_entries;}
#if defined(_MSC_VER)
__declspec(noinline)
#endif
bool platform_native_block(CPUState* cpu,u32 address,u32 charged) {
    if(cpu->pc!=address)return false;
    s64 before=cpu->downcount;cpu->downcount+=(s64)charged;
    bool taken=false;
    switch(address) {
    case 0x802B4D08u:taken=sdk_mtx44_concat(cpu);break;
    case 0x8024BC48u:taken=paired_skinning_blend_step(cpu);break;
    case 0x8024C014u:taken=paired_skinning_transform_step(cpu);break;
    case 0x8024C244u:taken=paired_skinning_accumulate_step(cpu);break;
    case 0x8024C500u:
    case 0x8024C508u:
    case 0x8024C518u:taken=paired_skinning_environment_direct_step(cpu);break;
    }
    if(!taken){cpu->downcount=before;return false;}
    s_block_entries++;
    // The caller returns from its generated chunk. Continue at the kernel's
    // PC within this slice when budget remains, as the original chunk did.
    if(cpu->downcount> -256)platform_continue_cpu_slice();
    return true;
}
