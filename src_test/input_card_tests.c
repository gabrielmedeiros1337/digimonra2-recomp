#define SDL_MAIN_HANDLED
#include "input.h"
#include "input_devices.h"
#include "card_hle.h"
#include "card_store.h"
#include "hle_callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>
#include <process.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"FAIL input/CARD line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static u32 callback_pc,callback_chan,callback_result;
bool hle_callbacks_has_space(void){return true;}
bool hle_callbacks_busy(void){return false;}
bool hle_callbacks_enqueue(u32 callback,u32 chan,u32 result){callback_pc=callback;callback_chan=chan;callback_result=result;return true;}
static int call(CPUState* c,u32 pc,u32 a,u32 b,u32 d,u32 e,u32 f){c->gpr[3]=a;c->gpr[4]=b;c->gpr[5]=d;c->gpr[6]=e;c->gpr[7]=f;c->lr=0x80004000;return card_hle_dispatch(c,pc)&&(s32)c->gpr[3]==0&&c->pc==c->lr;}
int main(void){
 InputDevice fake[2]={{"padA","Controller A",0},{"padB","Controller B",1}};
 char assignments[4][80]={"auto","padA","auto","none"};int assigned[4];input_devices_assign(fake,2,assignments,assigned);
 CHECK(assigned[0]==1&&assigned[1]==0&&assigned[2]==-1&&assigned[3]==-1);
 SDL_SetMainReady();CHECK(SDL_Init(SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS)==0);LauncherConfig cfg;launcher_config_defaults(&cfg);NativePadState pads[4]={{0}};Uint8 keys[SDL_NUM_SCANCODES]={0};keys[SDL_SCANCODE_Z]=1;input_apply_keyboard(keys,true,&cfg,pads);CHECK(pads[0].connected&&(pads[0].button&PAD_BUTTON_A));
 memset(pads,0,sizeof(pads));cfg.keyboard_enabled=false;input_apply_keyboard(keys,true,&cfg,pads);CHECK(!pads[0].connected&&!pads[0].button);cfg.keyboard_enabled=true;cfg.keyboard_port=3;strcpy(cfg.ports[0],"none");strcpy(cfg.ports[3],"keyboard");input_apply_keyboard(keys,false,&cfg,pads);CHECK(pads[3].connected&&!pads[3].button);input_apply_keyboard(keys,true,&cfg,pads);CHECK(pads[3].button==PAD_BUTTON_A&&!pads[0].button);
 int v=SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_UNKNOWN,4,8,1);CHECK(v>=0);InputDevice list[INPUT_DEVICE_MAX];int count=input_devices_list(list),found=-1;for(int i=0;i<count;i++)if(list[i].index==v)found=i;CHECK(found>=0);strcpy(cfg.ports[1],list[found].id);cfg.keyboard_enabled=false;input_configure(&cfg);CHECK(input_init());SDL_Joystick* joy=SDL_JoystickOpen(v);CHECK(joy);CHECK(SDL_JoystickSetVirtualButton(joy,0,1)==0);SDL_JoystickUpdate();input_poll();CHECK(input_get_pad(1)->connected&&(input_get_pad(1)->button&PAD_BUTTON_A));CHECK(!input_get_pad(0)->connected&&!input_get_pad(2)->connected&&!input_get_pad(3)->connected);input_shutdown();SDL_JoystickClose(joy);CHECK(SDL_JoystickDetachVirtual(v)==0);SDL_Quit();
 CPUState cpu={0};cpu.ram_size=24*1024*1024;cpu.ram=calloc(1,cpu.ram_size);CHECK(cpu.ram);memcpy(cpu.ram,"GDEE78",6);char folder[128];snprintf(folder,sizeof(folder),"card_contract_%d",_getpid());CHECK(_mkdir(folder)==0);card_store_init(folder);card_hle_reset();
 CHECK(call(&cpu,0x802A8A70,0,0,0,0,0));CHECK(call(&cpu,0x802AA8D4,0,0x80001000,0x80001004,0,0));CHECK(mem_read32(&cpu,0x80001000)==128&&mem_read32(&cpu,0x80001004)==8192);
 CHECK(call(&cpu,0x802AB138,0,0,0,0,0));memcpy(cpu.ram+0x1100,"DRA2SAVE",9);CHECK(call(&cpu,0x802AC22C,0,0x80001100,16384,0x80001200,0x80003000));CHECK(callback_pc==0x80003000&&callback_chan==0&&callback_result==0);
 for(int i=0;i<8192;i++)cpu.ram[0x10000+i]=(u8)(i*17);CHECK(call(&cpu,0x802ACBB8,0x80001200,0x80010000,8192,8192,0x80003100));CHECK(callback_pc==0x80003100&&callback_chan==0&&callback_result==0);
 CHECK(call(&cpu,0x802AD27C,0,0,0x80002000,0,0));CHECK(mem_read32(&cpu,0x80002020)==16384&&!memcmp(cpu.ram+0x2028,"GDEE78",6));CHECK(call(&cpu,0x802AC0A0,0x80001200,0,0,0,0));CHECK(mem_read32(&cpu,0x80001200)==0xffffffffu);
 card_store_shutdown();card_store_init(folder);card_hle_reset();CHECK(call(&cpu,0x802A8A70,0,0,0,0,0));CHECK(call(&cpu,0x802AB138,0,0,0,0,0));CHECK(call(&cpu,0x802ABF28,0,0x80001100,0x80001200,0,0));CHECK(call(&cpu,0x802AC77C,0x80001200,0x80020000,8192,8192,0x80003200));CHECK(!memcmp(cpu.ram+0x20000,cpu.ram+0x10000,8192)&&callback_pc==0x80003200);
 CHECK(card_hle_dispatch(&cpu,0x80000000)==0);CHECK(call(&cpu,0x802ACF2C,0,0x80001100,0x80003300,0,0));card_store_shutdown();char file[256];snprintf(file,sizeof(file),"%s/MemoryCardA.card",folder);remove(file);snprintf(file,sizeof(file),"%s/MemoryCardA.lock",folder);remove(file);CHECK(_rmdir(folder)==0);free(cpu.ram);puts("Four-port physical input mapping and CARD SDK ABI/callback/persistence passed");return 0;
}
