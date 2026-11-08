#include "guest_frame.h"
#include <string.h>
void guest_frame_begin(GuestFrameBudget* b,u64 now,u64 copies){
    b->start=now;b->deadline=now+GUEST_FRAME_TICKS;b->copy_start=copies;b->dispatches=0;b->phase=0;b->open=true;b->finished=false;b->horizon_polled=false;
}
u64 guest_frame_step(GuestFrameBudget* b,u64 now){
    // 675000/300000 = 9/4 TB ticks per dispatch: triple the execution
    // opportunities, never triple the VI/audio/timebase clock.
    b->phase+=9;u32 delta=b->phase>>2;b->phase&=3;
    // Beyond the nominal deadline, unfinished work keeps device time moving.
    // Freezing TB here would deadlock guest polling loops before CopyDisp.
    return now<b->deadline && b->deadline-now<delta ? b->deadline:now+delta;
}
u64 guest_frame_idle_target(GuestFrameBudget* b,u64 now,u64 event){
    if(now>=b->deadline)return now;
    u64 target=event<b->deadline ? event:b->deadline;if(target<=now)target=now+1;
    b->idle_jumps++;b->idle_ticks+=target-now;return target;
}
bool guest_frame_finish_idle(GuestFrameBudget* b,u64 now,u64 copies,bool vi){
    if(!b->open || now<b->deadline)return false;
    b->open=false;b->finished=true;b->completed++;
    if(copies!=b->copy_start)b->submitted++;else b->empty++;
    if(vi)b->retrace_waits++;if(b->dispatches>GUEST_FRAME_BASE_SLICES)b->over_base++;
    b->window_dispatches+=b->dispatches;b->window_completed++;
    if(b->dispatches>b->window_max_dispatches)b->window_max_dispatches=b->dispatches;
    if(b->dispatches>b->max_dispatches)b->max_dispatches=b->dispatches;return true;
}
void guest_frame_watchdog(GuestFrameBudget* b){if(b->open)b->watchdogs++;}
bool guest_frame_finish_rendered(GuestFrameBudget* b,u64 now,u64 copies){
    if(copies==b->copy_start || !guest_frame_finish_idle(b,now,copies,false))return false;
    b->rendered_deadlines++;return true;
}
u64 guest_frame_deadline(u64 now,u64 phase,u64 units,u64 rate){
    if(!rate)return ~(u64)0;
    u64 need=units*40500000ull;u64 ticks=need>phase ? (need-phase+rate-1)/rate:1;
    return ticks>~(u64)0-now ? ~(u64)0:now+ticks;
}
