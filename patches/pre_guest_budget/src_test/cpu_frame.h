#ifndef CPU_FRAME_H
#define CPU_FRAME_H
#include <SDL.h>
#include <stdbool.h>
typedef void (*CPUFrameRun)(void* job);
bool cpu_frame_start(CPUFrameRun run);
bool cpu_frame_submit(void* job);
bool cpu_frame_done(void);
void cpu_frame_stop(void);
#endif
