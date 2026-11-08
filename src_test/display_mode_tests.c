#define SDL_MAIN_HANDLED
#include "display_mode.h"
#include <stdio.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Display mode FAIL line %d: %s (%s)\n",__LINE__,#x,SDL_GetError());return 1;}}while(0)
int main(void){
 SDL_SetMainReady();CHECK(SDL_Init(SDL_INIT_VIDEO)==0);
 SDL_Window* w=SDL_CreateWindow("Display mode contracts",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);CHECK(w);
 DisplayModeState state;display_mode_init(&state,DISPLAY_WINDOWED);
 CHECK(display_mode_apply(w,&state,DISPLAY_WINDOWED));CHECK(!(SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN));
 SDL_Event e={0};e.type=SDL_KEYDOWN;e.key.keysym.sym=SDLK_RETURN;
 CHECK(!display_mode_event(w,&state,&e));e.key.keysym.mod=KMOD_LALT;
 CHECK(display_mode_event(w,&state,&e));CHECK((SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN_DESKTOP)==SDL_WINDOW_FULLSCREEN_DESKTOP);
 e.key.repeat=1;CHECK(display_mode_event(w,&state,&e));CHECK(SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN);
 e.key.repeat=0;CHECK(display_mode_event(w,&state,&e));CHECK(!(SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN));
 int width,height;SDL_GetWindowSize(w,&width,&height);CHECK(width==640&&height==480);
 CHECK(display_mode_apply(w,&state,DISPLAY_EXCLUSIVE));CHECK(SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN);CHECK(!(SDL_GetWindowFlags(w)&(SDL_WINDOW_FULLSCREEN_DESKTOP&~SDL_WINDOW_FULLSCREEN)));
 CHECK(display_mode_event(w,&state,&e));CHECK(!(SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN));
 CHECK(display_mode_event(w,&state,&e));CHECK((SDL_GetWindowFlags(w)&SDL_WINDOW_FULLSCREEN)&&!(SDL_GetWindowFlags(w)&0x1000));
 CHECK(display_mode_apply(w,&state,DISPLAY_WINDOWED));CHECK(!display_mode_apply(w,&state,3));
 SDL_DestroyWindow(w);SDL_Quit();puts("PASS windowed/borderless/exclusive, Alt+Enter, repeats and window bounds restoration");return 0;
}
