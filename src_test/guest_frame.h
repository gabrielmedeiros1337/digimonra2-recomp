#ifndef DIGIMON_GUEST_FRAME_H
#define DIGIMON_GUEST_FRAME_H
#include "common/types.h"
#include <stdbool.h>
enum {GUEST_FRAME_TICKS=675000,GUEST_FRAME_BASE_SLICES=100000,GUEST_FRAME_JOB_SLICES=300000};
typedef struct {
    u64 start,deadline,copy_start,dispatches;
    u64 completed,submitted,empty,watchdogs,over_base,idle_jumps,idle_ticks,max_dispatches,retrace_waits,rendered_deadlines;
    u64 window_dispatches,window_max_dispatches,window_completed;
    u32 phase;bool open,finished,horizon_polled;
} GuestFrameBudget;
void guest_frame_begin(GuestFrameBudget* b,u64 timebase,u64 copies);
u64 guest_frame_step(GuestFrameBudget* b,u64 timebase);
u64 guest_frame_idle_target(GuestFrameBudget* b,u64 timebase,u64 next_event);
bool guest_frame_finish_idle(GuestFrameBudget* b,u64 timebase,u64 copies,bool waiting_retrace);
bool guest_frame_finish_rendered(GuestFrameBudget* b,u64 timebase,u64 copies);
void guest_frame_watchdog(GuestFrameBudget* b);
u64 guest_frame_deadline(u64 now,u64 phase,u64 units,u64 rate);
#endif
