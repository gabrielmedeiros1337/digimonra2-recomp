#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <stdbool.h>
#include "portable_config.h"
#include "cpu/cpu.h"

// Standard GameCube Controller Button Mask
#define PAD_BUTTON_LEFT    0x0001
#define PAD_BUTTON_RIGHT   0x0002
#define PAD_BUTTON_DOWN    0x0004
#define PAD_BUTTON_UP      0x0008
#define PAD_TRIGGER_Z      0x0010
#define PAD_TRIGGER_R      0x0020
#define PAD_TRIGGER_L      0x0040
#define PAD_BUTTON_A       0x0100
#define PAD_BUTTON_B       0x0200
#define PAD_BUTTON_X       0x0400
#define PAD_BUTTON_Y       0x0800
#define PAD_BUTTON_START   0x1000

typedef struct {
    u16 button;
    s8  stick_x;
    s8  stick_y;
    s8  substick_x;
    s8  substick_y;
    u8  trigger_l;
    u8  trigger_r;
    bool connected;
} NativePadState;

// Initializes GameController subsystem and opens any connected controllers
void input_configure(const LauncherConfig* config);
void input_apply_keyboard(const Uint8* keys,bool focused,const LauncherConfig* config,NativePadState pads[4]);
bool input_init(void);

// Polls keyboard and connected controllers, updating current pad state
void input_poll(void);
void input_suppress_enter(void);
void input_handle_event(const SDL_Event* event);
const NativePadState* input_get_pad(int idx);
void input_bind_frame(const NativePadState* physical_snapshot);

// Pure keyboard mapping and PADStatus serialization (also used by contracts).
// Returns true when Shift is used for a player 2..4 Start chord.
bool input_map_extra_keys(const Uint8* keys,bool focused,NativePadState pads[4]);
u32 input_store_pad_status(CPUState* cpu,u32 address,const NativePadState pads[4]);

// Serial Interface (SI) MMIO register handlers (0xCC006400 - 0xCC006438)
u32 input_read_si(CPUState* cpu, u32 reg_offset);
void input_write_si(CPUState* cpu, u32 reg_offset, u32 val);

// Shuts down and closes controller devices
void input_shutdown(void);

#endif // INPUT_H
