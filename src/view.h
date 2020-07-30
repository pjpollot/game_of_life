#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

#define WIDTH 500
#define HEIGHT 500
#define DELAY 10000

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect rectangle;
    SDL_Event event;
} App;

App* applicationInit();
void applicationQuit(App* app); 

void renderGrid(App* ,const Grid);
void cleanRendering(App*);

// Additionnal tools
void setColorWhite(App*);
void setColorBlack(App*);
void sdlExitWithMessage(const char*);

#endif