#include "hle_callbacks.h"
#include "os_context.h"
#include <string.h>

/* A guest callback must not consume the interrupted caller's volatile registers.
 * Its normal BLR lands here, restoring the complete CPU (including PS1/GQR).
 * RAM mutations persist. Callbacks may enqueue more reads without recursion. */
#define CALLBACK_RETURN 0x81800000u
#define CALLBACK_CAPACITY 128u
typedef struct { u32 pc, result, argument; } Completion;
static Completion s_queue[CALLBACK_CAPACITY];
static u32 s_head, s_count;
static bool s_active;
static CPUState s_saved;
static u32 s_saved_context,s_saved_physical,s_saved_fpu_owner;

bool hle_callbacks_has_space(void) { return s_count < CALLBACK_CAPACITY; }
bool hle_callbacks_busy(void){return s_active || s_count!=0;}
bool hle_callbacks_enqueue(u32 callback, u32 result, u32 argument) {
    if (!callback) return true;
    if (!hle_callbacks_has_space()) return false;
    s_queue[(s_head + s_count++) % CALLBACK_CAPACITY] =
        (Completion){ callback, result, argument };
    return true;
}
void hle_callbacks_pump(CPUState* cpu) {
    if (s_active || !s_count || !(cpu->msr & 0x8000u) || cpu->exception) return;
    if(cpu->gpr[1]<GC_RAM_BASE+0x400u || cpu->gpr[1]>GC_RAM_BASE+cpu->ram_size)return;
    Completion c = s_queue[s_head];
    s_head = (s_head + 1) % CALLBACK_CAPACITY;
    s_count--;
    memcpy(&s_saved, cpu, sizeof(s_saved));
    s_saved_context=mem_read32(cpu,0x800000D4u);
    s_saved_physical=mem_read32(cpu,0x800000C0u);
    s_saved_fpu_owner=mem_read32(cpu,0x800000D8u);
    // DVD callbacks run in interrupt context, with a separate stack context.
    // This also prevents OSWakeupThread from switching away inside the callback.
    u32 context=(cpu->gpr[1]-0x2E8u)&~31u;
    memset(cpu->ram+context-GC_RAM_BASE,0,0x2C8);
    cpu->gpr[1]=context-32;
    mem_write32(cpu,cpu->gpr[1],s_saved.gpr[1]);
    mem_write32(cpu,0x800000D4u,context);
    mem_write32(cpu,0x800000C0u,context&0x3FFFFFFFu);
    cpu->msr&=~(0x8000u|0x2000u);
    s_active = true;
    cpu->pc = c.pc;
    cpu->lr = CALLBACK_RETURN;
    cpu->gpr[3] = c.result;
    cpu->gpr[4] = c.argument;
}
bool hle_callbacks_return(CPUState* cpu, u32 address) {
    if (!s_active || address != CALLBACK_RETURN) return false;
    u64 timebase = cpu->timebase;
    u32 owner=mem_read32(cpu,0x800000D8u);
    if(owner!=s_saved_fpu_owner)hle_os_save_fpu(cpu,owner);
    mem_write32(cpu,0x800000D8u,s_saved_fpu_owner);
    mem_write32(cpu,0x800000D4u,s_saved_context);
    mem_write32(cpu,0x800000C0u,s_saved_physical);
    memcpy(cpu, &s_saved, sizeof(*cpu));
    cpu->timebase = timebase;
    ppc_fpscr_control_updated(cpu);
    s_active = false;
    return true;
}
