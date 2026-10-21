#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static SDL_GameController* s_controller = NULL;
static NativePadState s_pads[4] = {0};
static u32 s_si_regs[16] = {0};

bool input_init(void) {
    memset(s_pads, 0, sizeof(s_pads));
    s_pads[0].connected = true; // Player 1 is always connected (Keyboard / Controller)

    int num_joysticks = SDL_NumJoysticks();
    for (int i = 0; i < num_joysticks; i++) {
        if (SDL_IsGameController(i)) {
            s_controller = SDL_GameControllerOpen(i);
            if (s_controller) {
                printf("[Input Driver] Controle conectado: '%s'\n", SDL_GameControllerName(s_controller));
                break;
            }
        }
    }

    if (!s_controller) {
        printf("[Input Driver] Nenhum controle fisico detectado. Teclado habilitado (WASD/Setas, J=A, K=B, Enter=Start).\n");
    }

    return true;
}

static u16 s_injected_buttons = 0;

void input_poll(void) {
    // Reset player 1 state
    s_pads[0].button = 0;
    s_pads[0].stick_x = 0;
    s_pads[0].stick_y = 0;
    s_pads[0].substick_x = 0;
    s_pads[0].substick_y = 0;
    s_pads[0].trigger_l = 0;
    s_pads[0].trigger_r = 0;

    // 1. Keyboard Polling
    const Uint8* state = SDL_GetKeyboardState(NULL);

    // D-Pad / Movement (Arrow keys and WASD fallback)
    if (state[SDL_SCANCODE_LEFT]) {
        s_pads[0].button |= PAD_BUTTON_LEFT;
        s_pads[0].stick_x = -100;
    }
    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
        s_pads[0].button |= PAD_BUTTON_RIGHT;
        s_pads[0].stick_x = 100;
    }
    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
        s_pads[0].button |= PAD_BUTTON_UP;
        s_pads[0].stick_y = 100; // GameCube Y+ is UP
    }
    if (state[SDL_SCANCODE_DOWN]) {
        s_pads[0].button |= PAD_BUTTON_DOWN;
        s_pads[0].stick_y = -100; // GameCube Y- is DOWN
    }

    // Action buttons:
    // PAD_BUTTON_A = 0x0100 (Tecla Z ou J)
    if (state[SDL_SCANCODE_Z] || state[SDL_SCANCODE_J]) {
        s_pads[0].button |= PAD_BUTTON_A;
    }
    // PAD_BUTTON_B = 0x0200 (Tecla X ou K)
    if (state[SDL_SCANCODE_X] || state[SDL_SCANCODE_K]) {
        s_pads[0].button |= PAD_BUTTON_B;
    }
    // PAD_BUTTON_X = 0x0400 (Tecla A ou C ou U)
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_C] || state[SDL_SCANCODE_U]) {
        s_pads[0].button |= PAD_BUTTON_X;
    }
    // PAD_BUTTON_Y = 0x0800 (Tecla S ou V ou I)
    if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_V] || state[SDL_SCANCODE_I]) {
        s_pads[0].button |= PAD_BUTTON_Y;
    }
    // PAD_BUTTON_START = 0x1000 (Tecla Enter ou Espaço)
    if (state[SDL_SCANCODE_RETURN] || state[SDL_SCANCODE_SPACE]) {
        s_pads[0].button |= PAD_BUTTON_START;
    }
    if (state[SDL_SCANCODE_Q] || state[SDL_SCANCODE_LSHIFT]) {
        s_pads[0].button |= PAD_TRIGGER_L;
        s_pads[0].trigger_l = 255;
    }
    if (state[SDL_SCANCODE_E] || state[SDL_SCANCODE_RSHIFT]) {
        s_pads[0].button |= PAD_TRIGGER_R;
        s_pads[0].trigger_r = 255;
    }
    if (state[SDL_SCANCODE_TAB]) {
        s_pads[0].button |= PAD_TRIGGER_Z;
    }

    // Apply any buttons injected during event polling
    s_pads[0].button |= s_injected_buttons;
    if (s_injected_buttons & PAD_BUTTON_DOWN) s_pads[0].stick_y = -100;
    if (s_injected_buttons & PAD_BUTTON_UP)   s_pads[0].stick_y = 100;
    s_injected_buttons = 0;

    // 2. Physical Game Controller Polling
    if (s_controller && SDL_GameControllerGetAttached(s_controller)) {
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_A))
            s_pads[0].button |= PAD_BUTTON_A;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_B))
            s_pads[0].button |= PAD_BUTTON_B;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_X))
            s_pads[0].button |= PAD_BUTTON_X;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_Y))
            s_pads[0].button |= PAD_BUTTON_Y;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_START))
            s_pads[0].button |= PAD_BUTTON_START;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
            s_pads[0].button |= PAD_BUTTON_UP;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN))
            s_pads[0].button |= PAD_BUTTON_DOWN;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT))
            s_pads[0].button |= PAD_BUTTON_LEFT;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
            s_pads[0].button |= PAD_BUTTON_RIGHT;
        // LEFTSHOULDER only activates PAD_TRIGGER_L if analog trigger ALSO exceeds threshold
        // (prevents spurious 0x40 from controller rest position / firmware drift)
        Sint16 lt_check = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) && lt_check > 20000)
            s_pads[0].button |= PAD_TRIGGER_L;

        // RIGHTSHOULDER maps to PAD_TRIGGER_Z only if its analog axis also exceeds threshold
        Sint16 rt_check = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) && rt_check > 20000)
            s_pads[0].button |= PAD_TRIGGER_Z; // Map RB to Z

        // Left Analog Stick
        Sint16 lx = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_LEFTX);
        Sint16 ly = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_LEFTY);
        if (abs(lx) > 8000) s_pads[0].stick_x = (s8)(lx / 256);
        if (abs(ly) > 8000) s_pads[0].stick_y = (s8)(-ly / 256); // Invert Y for GameCube

        // Right Analog Stick (C-Stick)
        Sint16 rx = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_RIGHTX);
        Sint16 ry = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_RIGHTY);
        if (abs(rx) > 8000) s_pads[0].substick_x = (s8)(rx / 256);
        if (abs(ry) > 8000) s_pads[0].substick_y = (s8)(-ry / 256);

        // Analog Triggers — raise digital-press threshold to 30000 to avoid rest-position ghosts
        Sint16 lt = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
        Sint16 rt = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
        if (lt > 4000) {
            s_pads[0].trigger_l = (u8)(lt / 128);
            if (lt > 30000) s_pads[0].button |= PAD_TRIGGER_L;
        }
        if (rt > 4000) {
            s_pads[0].trigger_r = (u8)(rt / 128);
            if (rt > 30000) s_pads[0].button |= PAD_TRIGGER_R;
        }
    }
}

void input_inject_button(u16 button_mask) {
    s_injected_buttons |= button_mask;
    s_pads[0].button |= button_mask;
}

const NativePadState* input_get_pad(int idx) {
    if (idx >= 0 && idx < 4) return &s_pads[idx];
    return &s_pads[0];
}

u32 input_read_si(CPUState* cpu, u32 reg_offset) {
    u32 idx = (reg_offset & 0x7F) >> 2;

    switch (reg_offset) {
        // Channel 0 Input 1 (Buttons + Stick X/Y)
        case 0x04: {
            u16 btn = s_pads[0].button;
            u8 sx = (u8)s_pads[0].stick_x;
            u8 sy = (u8)s_pads[0].stick_y;
            return ((u32)btn << 16) | ((u32)sx << 8) | (u32)sy;
        }
        // Channel 0 Input 2 (C-Stick + Triggers)
        case 0x08: {
            u8 cx = (u8)s_pads[0].substick_x;
            u8 cy = (u8)s_pads[0].substick_y;
            u8 tl = s_pads[0].trigger_l;
            u8 tr = s_pads[0].trigger_r;
            return ((u32)cx << 24) | ((u32)cy << 16) | ((u32)tl << 8) | (u32)tr;
        }
        // Channel 0 Command / COMCSR: TSTART is bit 0; transfer completes synchronously so bit 0 is 0
        case 0x0C:
            return (s_si_regs[3] & ~1u) | 0x80000000u;
        // SI Status Register (SISR / COMCSR 0x34): Bit 31 indicates Channel 0 Ready / TCINT
        case 0x34:
            return (s_si_regs[idx & 0x0F] & ~1u) | 0x80000000u;
        // EXISR / Device status
        case 0x38:
            return 0x00800000u; // Normal standard GameCube pad detected
        default:
            return s_si_regs[idx & 0x0F] & ~1u;
    }
}

void input_write_si(CPUState* cpu, u32 reg_offset, u32 val) {
    u32 idx = (reg_offset & 0x7F) >> 2;
    // Host completes SI transfers synchronously: TSTART (bit 0) clears and TCINT (bit 31) latches
    if (val & 1) {
        val &= ~1u;
        val |= 0x80000000u;
    }
    s_si_regs[idx & 0x0F] = val;
}

void input_shutdown(void) {
    if (s_controller) {
        SDL_GameControllerClose(s_controller);
        s_controller = NULL;
    }
}
