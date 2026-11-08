#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H
#include <SDL.h>
#include <stdbool.h>
enum { DISPLAY_WINDOWED=0, DISPLAY_BORDERLESS=1, DISPLAY_EXCLUSIVE=2 };
typedef struct {
    int fullscreen_mode;
    int x,y,width,height;
    bool saved_window_bounds;
} DisplayModeState;
void display_mode_init(DisplayModeState* state,int initial_mode);
bool display_mode_apply(SDL_Window* window,DisplayModeState* state,int mode);
/* Returns true for the reserved Alt+Enter chord, including repeated keydowns. */
bool display_mode_event(SDL_Window* window,DisplayModeState* state,const SDL_Event* event);
#endif
