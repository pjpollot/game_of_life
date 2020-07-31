#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "properties.h"
#include "grid.h"

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

// Event handling
char quitEvent(App*); // Returns 1 if the application has to quit, 0 otherwise

// Additionnal tools
void setColorWhite(App*);
void setColorBlack(App*);
void setColorGreen(App*);
void setColorRed(App*);
void sdlExitWithMessage(const char*);

#endif