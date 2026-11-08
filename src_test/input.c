#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static SDL_GameController* s_controller = NULL;
static SDL_Joystick* s_joystick = NULL;
static NativePadState s_pads[4] = {0};
static u32 s_si_regs[16] = {0};

bool input_init(void) {
    memset(s_pads, 0, sizeof(s_pads));
    for(int i=0;i<4;i++)s_pads[i].connected=true; // Four physical-keyboard pads.
    printf("[Input] P2/P3/P4: 7/8/9=A; Shift+7/8/9=Start (also numeric keypad).\n");

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

    if (!s_controller && num_joysticks > 0) s_joystick = SDL_JoystickOpen(0);
    if (!s_controller) {
        printf("[Input Driver] Nenhum controle fisico detectado. Teclado habilitado (WASD/Setas, J=A, K=B, Enter=Start).\n");
    }

    return true;
}

bool input_map_extra_keys(const Uint8* keys,bool focused,NativePadState pads[4]) {
    static const SDL_Scancode top[3]={SDL_SCANCODE_7,SDL_SCANCODE_8,SDL_SCANCODE_9};
    static const SDL_Scancode num[3]={SDL_SCANCODE_KP_7,SDL_SCANCODE_KP_8,SDL_SCANCODE_KP_9};
    bool shift=focused && (keys[SDL_SCANCODE_LSHIFT] || keys[SDL_SCANCODE_RSHIFT]);
    bool used_shift=false;
    for(int i=1;i<4;i++) {
        memset(&pads[i],0,sizeof(pads[i]));pads[i].connected=true;
        if(focused && (keys[top[i-1]] || keys[num[i-1]])) {
            pads[i].button=shift ? PAD_BUTTON_START:PAD_BUTTON_A;
            used_shift|=shift;
        }
    }
    return used_shift;
}

u32 input_store_pad_status(CPUState* cpu,u32 address,const NativePadState pads[4]) {
    u32 mask=0;
    bool valid=cpu->ram && cpu->ram_size>=48 && address>=GC_RAM_BASE && address-GC_RAM_BASE<=cpu->ram_size-48;
    for(u32 i=0;i<4;i++) {
        const NativePadState* pad=&pads[i];if(pad->connected)mask|=0x80000000u>>i;
        if(!valid)continue;
        u32 at=address+i*12u;
        mem_write16(cpu,at,pad->connected ? pad->button:0);
        mem_write8(cpu,at+2,pad->connected ? (u8)pad->stick_x:0);
        mem_write8(cpu,at+3,pad->connected ? (u8)pad->stick_y:0);
        mem_write8(cpu,at+4,pad->connected ? (u8)pad->substick_x:0);
        mem_write8(cpu,at+5,pad->connected ? (u8)pad->substick_y:0);
        mem_write8(cpu,at+6,pad->connected ? pad->trigger_l:0);
        mem_write8(cpu,at+7,pad->connected ? pad->trigger_r:0);
        mem_write8(cpu,at+8,pad->connected && (pad->button&PAD_BUTTON_A) ? 255:0);
        mem_write8(cpu,at+9,pad->connected && (pad->button&PAD_BUTTON_B) ? 255:0);
        mem_write8(cpu,at+10,pad->connected ? 0:255);mem_write8(cpu,at+11,0);
    }
    return mask;
}

void input_poll(void) {
    for(int i=0;i<4;i++){memset(&s_pads[i],0,sizeof(s_pads[i]));s_pads[i].connected=true;}
    const Uint8* state=SDL_GetKeyboardState(NULL);
    bool extra_shift=input_map_extra_keys(state,SDL_GetKeyboardFocus()!=NULL,s_pads);
    static u16 previous_extra[3];
    for(int i=1;i<4;i++)if(previous_extra[i-1]!=s_pads[i].button) {
        printf("[Input P%d] buttons=%04X\n",i+1,s_pads[i].button);previous_extra[i-1]=s_pads[i].button;
    }
    if(!SDL_GetKeyboardFocus())goto controller_poll;

    // D-Pad / Movement (Arrow keys and WASD fallback)
    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
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
    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
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
    // PAD_BUTTON_X = 0x0400 (Tecla C ou U)
    if (state[SDL_SCANCODE_C] || state[SDL_SCANCODE_U]) {
        s_pads[0].button |= PAD_BUTTON_X;
    }
    // PAD_BUTTON_Y = 0x0800 (Tecla V ou I)
    if (state[SDL_SCANCODE_V] || state[SDL_SCANCODE_I]) {
        s_pads[0].button |= PAD_BUTTON_Y;
    }
    // PAD_BUTTON_START = 0x1000 (Tecla Enter ou Espaço)
    if (state[SDL_SCANCODE_RETURN] || state[SDL_SCANCODE_SPACE]) {
        s_pads[0].button |= PAD_BUTTON_START;
    }
    if (state[SDL_SCANCODE_Q] || (state[SDL_SCANCODE_LSHIFT] && !extra_shift)) {
        s_pads[0].button |= PAD_TRIGGER_L;
        s_pads[0].trigger_l = 255;
    }
    if (state[SDL_SCANCODE_E] || (state[SDL_SCANCODE_RSHIFT] && !extra_shift)) {
        s_pads[0].button |= PAD_TRIGGER_R;
        s_pads[0].trigger_r = 255;
    }
    if (state[SDL_SCANCODE_TAB]) {
        s_pads[0].button |= PAD_TRIGGER_Z;
    }

controller_poll:
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
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER))
            s_pads[0].button |= PAD_TRIGGER_L;
        if (SDL_GameControllerGetButton(s_controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER))
            s_pads[0].button |= PAD_TRIGGER_Z;

        // Left Analog Stick
        Sint16 lx = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_LEFTX);
        Sint16 ly = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_LEFTY);
        if (abs(lx) > 8000) s_pads[0].stick_x = (s8)(lx / 256);
        if (abs(ly) > 8000) s_pads[0].stick_y = (s8)(-ly / 258); // Invert Y for GameCube

        // Right Analog Stick (C-Stick)
        Sint16 rx = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_RIGHTX);
        Sint16 ry = SDL_GameControllerGetAxis(s_controller, SDL_CONTROLLER_AXIS_RIGHTY);
        if (abs(rx) > 8000) s_pads[0].substick_x = (s8)(rx / 256);
        if (abs(ry) > 8000) s_pads[0].substick_y = (s8)(-ry / 258);

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
    if (s_joystick && SDL_JoystickGetAttached(s_joystick)) {
        static const u16 buttons[] = { PAD_BUTTON_A, PAD_BUTTON_B, PAD_BUTTON_X,
            PAD_BUTTON_Y, PAD_TRIGGER_L, PAD_TRIGGER_Z, PAD_BUTTON_START, PAD_TRIGGER_R };
        int count = SDL_JoystickNumButtons(s_joystick);
        for (int i = 0; i < count && i < 8; i++)
            if (SDL_JoystickGetButton(s_joystick, i)) s_pads[0].button |= buttons[i];
        if (SDL_JoystickNumAxes(s_joystick) >= 2) {
            int x = SDL_JoystickGetAxis(s_joystick, 0), y = SDL_JoystickGetAxis(s_joystick, 1);
            if (abs(x) > 8000) s_pads[0].stick_x = (s8)(x / 258);
            if (abs(y) > 8000) s_pads[0].stick_y = (s8)(-y / 258);
        }
        Uint8 hat = SDL_JoystickNumHats(s_joystick) ? SDL_JoystickGetHat(s_joystick, 0) : 0;
        if (hat & SDL_HAT_UP) s_pads[0].button |= PAD_BUTTON_UP;
        if (hat & SDL_HAT_DOWN) s_pads[0].button |= PAD_BUTTON_DOWN;
        if (hat & SDL_HAT_LEFT) s_pads[0].button |= PAD_BUTTON_LEFT;
        if (hat & SDL_HAT_RIGHT) s_pads[0].button |= PAD_BUTTON_RIGHT;
    }

}

void input_handle_event(const SDL_Event* event) {
    if (event->type == SDL_CONTROLLERDEVICEREMOVED && s_controller &&
        SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(s_controller)) == event->cdevice.which) {
        SDL_GameControllerClose(s_controller);
        s_controller = NULL;
    }
    if (event->type == SDL_JOYDEVICEREMOVED && s_joystick &&
        SDL_JoystickInstanceID(s_joystick) == event->jdevice.which) {
        SDL_JoystickClose(s_joystick);
        s_joystick = NULL;
    }
    if (event->type == SDL_CONTROLLERDEVICEADDED && !s_controller &&
        SDL_IsGameController(event->cdevice.which)) {
        if (s_joystick) { SDL_JoystickClose(s_joystick); s_joystick = NULL; }
        s_controller = SDL_GameControllerOpen(event->cdevice.which);
    }
    if (event->type == SDL_JOYDEVICEADDED && !s_controller && !s_joystick &&
        !SDL_IsGameController(event->jdevice.which))
        s_joystick = SDL_JoystickOpen(event->jdevice.which);
}

#ifdef _MSC_VER
static __declspec(thread) const NativePadState* s_frame_pads;
#else
static _Thread_local const NativePadState* s_frame_pads;
#endif
void input_bind_frame(const NativePadState* physical_snapshot){s_frame_pads=physical_snapshot;}
const NativePadState* input_get_pad(int idx) {
    const NativePadState* pads=s_frame_pads ? s_frame_pads:s_pads;
    return &pads[idx>=0 && idx<4 ? idx:0];
}

u32 input_read_si(CPUState* cpu, u32 reg_offset) {
    u32 idx = (reg_offset & 0x7F) >> 2;

    if(reg_offset<0x30u && (reg_offset%12u==4u || reg_offset%12u==8u)) {
        const NativePadState* pad=input_get_pad((int)(reg_offset/12u));
        if(reg_offset%12u==4u)return ((u32)pad->button<<16)|((u32)(u8)(pad->stick_x+128)<<8)|(u8)(pad->stick_y+128);
        return ((u32)(u8)(pad->substick_x+128)<<24)|((u32)(u8)(pad->substick_y+128)<<16)|((u32)pad->trigger_l<<8)|pad->trigger_r;
    }
    switch (reg_offset) {
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
    if (s_joystick) { SDL_JoystickClose(s_joystick); s_joystick = NULL; }
    if (s_controller) {
        SDL_GameControllerClose(s_controller);
        s_controller = NULL;
    }
}
