#ifndef VERTEX_COMPLETION_H
#define VERTEX_COMPLETION_H
#include <SDL.h>
#include <stdbool.h>
typedef struct {SDL_atomic_t state;SDL_sem* done;} VertexCompletion;
bool vertex_completion_init(VertexCompletion* group);
void vertex_completion_begin(VertexCompletion* group,int workers);
bool vertex_completion_finish(VertexCompletion* group);
bool vertex_completion_wait(VertexCompletion* group);
void vertex_completion_destroy(VertexCompletion* group);
#endif
