#include "display_mode.h"
#include <string.h>
void display_mode_init(DisplayModeState* state,int mode){
    memset(state,0,sizeof(*state));state->fullscreen_mode=mode==DISPLAY_EXCLUSIVE?DISPLAY_EXCLUSIVE:DISPLAY_BORDERLESS;
}
bool display_mode_apply(SDL_Window* window,DisplayModeState* state,int mode){
    if(mode<DISPLAY_WINDOWED||mode>DISPLAY_EXCLUSIVE){SDL_SetError("Invalid display mode");return false;}
    Uint32 flags=SDL_GetWindowFlags(window);bool full=(flags&SDL_WINDOW_FULLSCREEN)!=0;
    if(mode==DISPLAY_WINDOWED){
        if(SDL_SetWindowFullscreen(window,0)!=0)return false;
        if(state->saved_window_bounds){SDL_SetWindowSize(window,state->width,state->height);SDL_SetWindowPosition(window,state->x,state->y);state->saved_window_bounds=false;}
        return true;
    }
    if(!full){SDL_GetWindowPosition(window,&state->x,&state->y);SDL_GetWindowSize(window,&state->width,&state->height);state->saved_window_bounds=true;}
    if(mode==DISPLAY_EXCLUSIVE){
        SDL_DisplayMode desktop;int display=SDL_GetWindowDisplayIndex(window);
        if(display<0||SDL_GetDesktopDisplayMode(display,&desktop)!=0||SDL_SetWindowDisplayMode(window,&desktop)!=0)return false;
    }
    if(SDL_SetWindowFullscreen(window,mode==DISPLAY_EXCLUSIVE?SDL_WINDOW_FULLSCREEN:SDL_WINDOW_FULLSCREEN_DESKTOP)!=0)return false;
    state->fullscreen_mode=mode;return true;
}
bool display_mode_event(SDL_Window* window,DisplayModeState* state,const SDL_Event* event){
    if(event->type!=SDL_KEYDOWN||(event->key.keysym.sym!=SDLK_RETURN&&event->key.keysym.sym!=SDLK_KP_ENTER)||!(event->key.keysym.mod&KMOD_ALT))return false;
    if(!event->key.repeat){int mode=(SDL_GetWindowFlags(window)&SDL_WINDOW_FULLSCREEN)?DISPLAY_WINDOWED:state->fullscreen_mode;
        if(!display_mode_apply(window,state,mode))SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION,"Display mode switch failed: %s",SDL_GetError());}
    return true;
}
