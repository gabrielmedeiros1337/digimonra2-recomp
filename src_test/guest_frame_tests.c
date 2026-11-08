#include "guest_frame.h"
#include <stdio.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"guest frame FAIL %d: %s\n",__LINE__,#x);return 1;}}while(0)
int main(void){
    GuestFrameBudget b={0};u64 now=1000;guest_frame_begin(&b,now,7);
    for(u32 i=0;i<GUEST_FRAME_JOB_SLICES;i++){now=guest_frame_step(&b,now);b.dispatches++;}
    CHECK(now==1000+GUEST_FRAME_TICKS);CHECK(b.dispatches==300000);
    // Reaching the watchdog without frame completion never closes the VI interval.
    guest_frame_watchdog(&b);CHECK(b.open && !b.finished && b.watchdogs==1);
    now=guest_frame_step(&b,now);b.dispatches++;CHECK(now>b.deadline);
    CHECK(guest_frame_finish_idle(&b,now,8,true));CHECK(b.completed==1 && b.submitted==1 && b.over_base==1 && b.retrace_waits==1);
    CHECK(!guest_frame_finish_idle(&b,now,8,true));
    guest_frame_begin(&b,now,8);u64 start=now;
    for(u32 i=0;i<1000;i++){now=guest_frame_step(&b,now);b.dispatches++;}
    CHECK(!guest_frame_finish_idle(&b,now,9,true)); // CopyDisp alone cannot discard post-copy work/audio.
    u32 events=0;
    while(now<b.deadline){
        u64 due=guest_frame_deadline(now,0,640,32000*4); // 5ms stereo DMA blocks.
        u64 target=guest_frame_idle_target(&b,now,due);
        CHECK(target>now && target<=b.deadline);now=target;if(now==due)events++;
    }
    CHECK(events==3 && now-start==GUEST_FRAME_TICKS && b.dispatches==1000 && b.idle_jumps==4);
    CHECK(guest_frame_finish_idle(&b,now,9,true));
    // Real no-render waits can advance to the next VI; they aren't counted as XFB submissions.
    guest_frame_begin(&b,now,9);now=guest_frame_idle_target(&b,now,~(u64)0);
    CHECK(guest_frame_finish_idle(&b,now,9,false));CHECK(b.empty==1 && b.completed==3 && b.submitted==2);
    CHECK(guest_frame_deadline(100,0,32,32000*4)==10225);
    CHECK(guest_frame_deadline(100,40500000,32,32000*4)==9909);
    CHECK(guest_frame_deadline(100,0,208,40500000)==308);
    CHECK(guest_frame_deadline(100,0,1,0)==~(u64)0);
    guest_frame_begin(&b,now,9);CHECK(!guest_frame_finish_rendered(&b,b.deadline,9));
    CHECK(guest_frame_finish_rendered(&b,b.deadline,10) && b.rendered_deadlines==1);
    CHECK(b.window_completed==4 && b.window_dispatches==301001 && b.window_max_dispatches==300001);
    printf("[Guest frame] 3x quota/constant VI clock, watchdog continuation, copy-vs-idle boundary and event-driven audio deadlines passed\n");return 0;
}
