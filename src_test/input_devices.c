#include "input_devices.h"
#include <stdio.h>
#include <string.h>
int input_devices_list(InputDevice devices[INPUT_DEVICE_MAX]){
    SDL_JoystickUpdate();
    int count=0,total=SDL_NumJoysticks();
    for(int i=0;i<total&&count<INPUT_DEVICE_MAX;i++){
        SDL_JoystickGUID g=SDL_JoystickGetDeviceGUID(i);char guid[33];SDL_JoystickGetGUIDString(g,guid,sizeof(guid));int ordinal=0;
        for(int j=0;j<i;j++){SDL_JoystickGUID other=SDL_JoystickGetDeviceGUID(j);if(!memcmp(&g,&other,sizeof(g)))ordinal++;}
        InputDevice* d=devices+count++;snprintf(d->id,sizeof(d->id),"%s:%d",guid,ordinal);d->index=i;
        const char* name=SDL_JoystickNameForIndex(i);snprintf(d->name,sizeof(d->name),"%s #%d%s",name?name:"Controller",ordinal+1,SDL_IsGameController(i)?"":" (DirectInput/Joystick)");
    }return count;
}
void input_devices_assign(const InputDevice* devices,int count,const char ports[4][80],int selected[4]){
    bool used[INPUT_DEVICE_MAX]={false};
    for(int p=0;p<4;p++){
        selected[p]=-1;
        for(int d=0;d<count&&d<INPUT_DEVICE_MAX;d++)if(!used[d]&&!strcmp(ports[p],devices[d].id)){
            selected[p]=d;used[d]=true;break;
        }
    }
    /* Explicit assignments have priority; automatic ports consume remaining pads. */
    for(int p=0;p<4;p++)if(!strcmp(ports[p],"auto")){
        for(int d=0;d<count&&d<INPUT_DEVICE_MAX;d++)if(!used[d]){selected[p]=d;used[d]=true;break;}
    }
}
