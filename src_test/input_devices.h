#ifndef INPUT_DEVICES_H
#define INPUT_DEVICES_H
#include <SDL.h>
#include <stdbool.h>
#define INPUT_DEVICE_MAX 32
typedef struct {char id[80];char name[256];int index;} InputDevice;
int input_devices_list(InputDevice devices[INPUT_DEVICE_MAX]);
void input_devices_assign(const InputDevice* devices,int count,const char ports[4][80],int selected[4]);
#endif
