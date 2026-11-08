#ifndef FRAME_TIMING_H
#define FRAME_TIMING_H
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    FRAME_OTHER, FRAME_GAME, FRAME_GX_DECODE, FRAME_GL_SUBMIT,
    FRAME_EFB_COPY, FRAME_SWAP, FRAME_PACING, FRAME_STAGE_COUNT
} FrameStage;
typedef struct {
    double ms[FRAME_STAGE_COUNT], wall_ms;
    double peak_ms[FRAME_STAGE_COUNT],wall_peak_ms;
    unsigned frames;
} FrameTimingReport;

/* Exclusive CPU timeline; ownership follows a submitted CPU frame job.
 * Backend overlap is reported separately, never added to the CPU timeline.
 * Synchronization waits remain wall time in the waiting CPU stage. */
void frame_timing_begin(void);
bool frame_timing_worker(bool enabled);
FrameStage frame_timing_enter(FrameStage stage);
void frame_timing_leave(FrameStage previous);
bool frame_timing_end(FrameTimingReport* report);
uint64_t frame_pacer_target(uint64_t previous,uint64_t now,uint64_t hz);
int frame_timing_contracts(void);
#endif
