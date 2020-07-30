#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

#define WIDTH 300
#define HEIGHT 300
#define DELAY 10000

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect rectangle;
    SDL_Event event;
} App;

void applicationInit(App* app); // TODO
void applicationQuit(App* app); // TODO

void sdlExitWithMessage(const char*);

#endif