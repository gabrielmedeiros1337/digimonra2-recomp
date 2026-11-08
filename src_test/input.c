#include "input.h"
#include "input_devices.h"
#include "portable_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static NativePadState s_pads[4];
static u32 s_si_regs[16];
static LauncherConfig s_config;
static SDL_GameController* s_controllers[4];
static SDL_Joystick* s_joysticks[4];
void input_configure(const LauncherConfig* c){s_config=*c;}
static void close_devices(void){for(int i=0;i<4;i++){if(s_controllers[i])SDL_GameControllerClose(s_controllers[i]);else if(s_joysticks[i])SDL_JoystickClose(s_joysticks[i]);s_controllers[i]=NULL;s_joysticks[i]=NULL;}}
static void open_devices(void){
 close_devices();InputDevice devices[INPUT_DEVICE_MAX];int n=input_devices_list(devices),selected[4];
 input_devices_assign(devices,n,s_config.ports,selected);
 for(int p=0;p<4;p++)if(selected[p]>=0){
  int d=selected[p];
  int index=devices[d].index;if(SDL_IsGameController(index)){s_controllers[p]=SDL_GameControllerOpen(index);if(s_controllers[p])s_joysticks[p]=SDL_GameControllerGetJoystick(s_controllers[p]);}else s_joysticks[p]=SDL_JoystickOpen(index);
 }
}
bool input_init(void){memset(s_pads,0,sizeof(s_pads));open_devices();return true;}
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


static void poll_controller(int p){
 NativePadState* pad=&s_pads[p];SDL_GameController* c=s_controllers[p];SDL_Joystick* j=s_joysticks[p];
 if(!j||!SDL_JoystickGetAttached(j))return;pad->connected=true;
 if(c){
  static const SDL_GameControllerButton buttons[]={SDL_CONTROLLER_BUTTON_A,SDL_CONTROLLER_BUTTON_B,SDL_CONTROLLER_BUTTON_X,SDL_CONTROLLER_BUTTON_Y,SDL_CONTROLLER_BUTTON_BACK,SDL_CONTROLLER_BUTTON_START,SDL_CONTROLLER_BUTTON_LEFTSHOULDER,SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,SDL_CONTROLLER_BUTTON_DPAD_UP,SDL_CONTROLLER_BUTTON_DPAD_DOWN,SDL_CONTROLLER_BUTTON_DPAD_LEFT,SDL_CONTROLLER_BUTTON_DPAD_RIGHT};
  static const u16 masks[]={PAD_BUTTON_A,PAD_BUTTON_B,PAD_BUTTON_X,PAD_BUTTON_Y,PAD_TRIGGER_Z,PAD_BUTTON_START,PAD_TRIGGER_L,PAD_TRIGGER_Z,PAD_BUTTON_UP,PAD_BUTTON_DOWN,PAD_BUTTON_LEFT,PAD_BUTTON_RIGHT};
  for(int i=0;i<12;i++)if(SDL_GameControllerGetButton(c,buttons[i]))pad->button|=masks[i];
  int x=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_LEFTX),y=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_LEFTY),cx=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_RIGHTX),cy=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_RIGHTY);
  if(abs(x)>8000)pad->stick_x=(s8)(x/258);if(abs(y)>8000)pad->stick_y=(s8)(-y/258);if(abs(cx)>8000)pad->substick_x=(s8)(cx/258);if(abs(cy)>8000)pad->substick_y=(s8)(-cy/258);
  int l=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_TRIGGERLEFT),r=SDL_GameControllerGetAxis(c,SDL_CONTROLLER_AXIS_TRIGGERRIGHT);if(l>4000)pad->trigger_l=(u8)(l/129);if(r>4000)pad->trigger_r=(u8)(r/129);if(l>30000)pad->button|=PAD_TRIGGER_L;if(r>30000)pad->button|=PAD_TRIGGER_R;
 }else{
  static const u16 masks[]={PAD_BUTTON_A,PAD_BUTTON_B,PAD_BUTTON_X,PAD_BUTTON_Y,PAD_TRIGGER_L,PAD_TRIGGER_Z,PAD_BUTTON_START,PAD_TRIGGER_R};
  for(int b=0;b<8&&b<SDL_JoystickNumButtons(j);b++)if(SDL_JoystickGetButton(j,b))pad->button|=masks[b];
  s8* axes[]={&pad->stick_x,&pad->stick_y,&pad->substick_x,&pad->substick_y};for(int a=0;a<4&&a<SDL_JoystickNumAxes(j);a++){int v=SDL_JoystickGetAxis(j,a);if(abs(v)>8000)*axes[a]=(s8)((a&1)?-v/258:v/258);}
  Uint8 hat=SDL_JoystickNumHats(j)?SDL_JoystickGetHat(j,0):0;if(hat&SDL_HAT_UP)pad->button|=PAD_BUTTON_UP;if(hat&SDL_HAT_DOWN)pad->button|=PAD_BUTTON_DOWN;if(hat&SDL_HAT_LEFT)pad->button|=PAD_BUTTON_LEFT;if(hat&SDL_HAT_RIGHT)pad->button|=PAD_BUTTON_RIGHT;
 }
 if(pad->button&PAD_TRIGGER_L)pad->trigger_l=255;if(pad->button&PAD_TRIGGER_R)pad->trigger_r=255;
}
void input_apply_keyboard(const Uint8* state,bool focused,const LauncherConfig* config,NativePadState pads[4]){
 if(!config->keyboard_enabled||config->keyboard_port<0||config->keyboard_port>3)return;
 int p=config->keyboard_port;if(strcmp(config->ports[p],"keyboard"))return;NativePadState* pad=pads+p;pad->connected=true;if(!focused)return;
 static const u16 mask[]={PAD_BUTTON_A,PAD_BUTTON_B,PAD_BUTTON_X,PAD_BUTTON_Y,PAD_TRIGGER_Z,PAD_BUTTON_START,PAD_TRIGGER_L,PAD_TRIGGER_R};
 bool on[KEY_BIND_COUNT];for(int i=0;i<KEY_BIND_COUNT;i++){int k=config->keys[i];on[i]=k>0&&k<SDL_NUM_SCANCODES&&state[k];}
 for(int i=0;i<8;i++)if(on[i])pad->button|=mask[i];pad->trigger_l=on[6]?255:0;pad->trigger_r=on[7]?255:0;
 pad->stick_x=(s8)(100*((int)on[11]-(int)on[10]));pad->stick_y=(s8)(100*((int)on[8]-(int)on[9]));
 pad->substick_x=(s8)(100*((int)on[19]-(int)on[18]));pad->substick_y=(s8)(100*((int)on[16]-(int)on[17]));
 if(on[12])pad->button|=PAD_BUTTON_UP;if(on[13])pad->button|=PAD_BUTTON_DOWN;if(on[14])pad->button|=PAD_BUTTON_LEFT;if(on[15])pad->button|=PAD_BUTTON_RIGHT;
}
void input_poll(void){memset(s_pads,0,sizeof(s_pads));for(int i=0;i<4;i++)poll_controller(i);input_apply_keyboard(SDL_GetKeyboardState(NULL),SDL_GetKeyboardFocus()!=NULL,&s_config,s_pads);}
void input_handle_event(const SDL_Event* event){if(event->type==SDL_JOYDEVICEADDED||event->type==SDL_JOYDEVICEREMOVED)open_devices();}
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

void input_shutdown(void){close_devices();}
