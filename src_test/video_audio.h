#ifndef VIDEO_AUDIO_H
#define VIDEO_AUDIO_H

#include <SDL.h>
#include <stdbool.h>
#include "cpu/cpu.h"

// Initializes Video Blitter (SDL_Texture) and Audio Output (SDL_AudioDevice)
bool video_audio_init(SDL_Renderer* renderer);

// VI (Video Interface) MMIO handlers
u64 video_read_vi(CPUState* cpu, u32 reg_offset, u8 size);
void video_write_vi(CPUState* cpu, u32 reg_offset, u64 val, u8 size);

// PI (Processor Interface) MMIO handlers
u64 video_read_pi(CPUState* cpu, u32 reg_offset, u8 size);
void video_write_pi(CPUState* cpu, u32 reg_offset, u64 val, u8 size);

// 60Hz VBLANK and Interrupt Dispatch
void video_trigger_vblank(CPUState* cpu);
void video_trigger_pe_finish(void);
void video_trigger_pe_token(void);
void video_ack_pe(bool token, bool finish);
void video_set_pe_enable(u32 enable);
void video_set_di_interrupt(bool pending);
void video_configure_xfb(u32 address, u32 width, u32 height, u32 pitch);
void video_poll_interrupt(CPUState* cpu);
u32 video_get_vblank_count(void);
u32 video_get_interrupt_count(void);

// AI (Audio Interface) MMIO handlers
u64 audio_read_ai(CPUState* cpu, u32 reg_offset, u8 size);
u64 audio_read_interface(CPUState* cpu, u32 offset, u8 size);
void audio_write_interface(CPUState* cpu, u32 offset, u64 value, u8 size);
void audio_tick(CPUState* cpu);
u64 video_next_event(CPUState* cpu,u64 limit);
bool video_interrupt_pending(void);
void audio_write_ai(CPUState* cpu, u32 reg_offset, u64 val, u8 size);

// Presents the GameCube XFB frame to the SDL2 window
void video_present_frame(SDL_Renderer* renderer, CPUState* cpu, int window_w, int window_h);

typedef struct {u32 address,width,height,pitch;} VideoXFB;
void video_xfb_snapshot(VideoXFB* result);
void video_present_snapshot(SDL_Renderer* renderer,CPUState* cpu,int window_w,int window_h,const VideoXFB* image);

// Sets the active Framebuffer (XFB) address in GameCube RAM
void video_set_xfb_addr(u32 addr);
u32 video_get_xfb_addr(void);

void video_set_aspect_ratio(int ratio);
int video_get_aspect_ratio(void);

// Shuts down SDL audio and destroys textures
void video_audio_shutdown(void);

#endif // VIDEO_AUDIO_H
