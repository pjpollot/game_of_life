#include "view.h"

App* applicationInit() {

    App* app = malloc(sizeof(App));
    if (app == NULL) {
        fprintf(stderr,"ERROR: can't initialize the application, memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        sdlExitWithMessage("can't init SDL2");

    // Init application components
    // - window and renderer
    app->window = SDL_CreateWindow(
        "Conway's game of life",
        SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
        WIDTH,HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (app->window == NULL)
        sdlExitWithMessage("can't create the window");
    
    app->renderer = SDL_CreateRenderer(app->window,-1,SDL_RENDERER_ACCELERATED);
    if (app->renderer == NULL)
        sdlExitWithMessage("can't create the renderer");

    // rectangle shapes
    
    app->rectangle.h = HEIGHT/NGRID;
    app->rectangle.w = WIDTH/NGRID;

    return app;
}

char quitEvent(App* app) {
    SDL_PollEvent(&(app->event));
    return (app->event.type == SDL_QUIT);
}

void applicationQuit(App* app) {
    // Destroy app's components
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);

    // Destroy the app itself
    free(app);

    // Quit SDL
    SDL_Quit();
}

void renderGrid(App* app, const Grid grid) {
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            if (grid[i][j] != ' ') {
                app->rectangle.y = (i-1)*HEIGHT/NGRID;
                app->rectangle.x = (j-1)*WIDTH/NGRID;
                switch (grid[i][j]) {
                case '$':
                    setColorWhite(app);
                    break;
                case '0':
                    setColorGreen(app);
                    break;
                case '-':
                    setColorRed(app);
                    break;
                default:
                    break;
                }
                if (SDL_RenderFillRect(app->renderer,&(app->rectangle)) != 0) 
                    sdlExitWithMessage("can't draw a filled rectangle");
            }
        }
    }
    SDL_RenderPresent(app->renderer);
} 

void cleanRendering(App* app) {
    setColorBlack(app);
    if (SDL_RenderClear(app->renderer))
        sdlExitWithMessage("can't clean the renderer");
}

void setColorWhite(App* app) {
    if (SDL_SetRenderDrawColor(app->renderer,255,255,255,SDL_ALPHA_OPAQUE) != 0)
        sdlExitWithMessage("can't change the fill color to white");
}

void setColorBlack(App* app) {
    if (SDL_SetRenderDrawColor(app->renderer,0,0,0,SDL_ALPHA_OPAQUE) != 0)
        sdlExitWithMessage("can't change the fill color to black");
}

void setColorGreen(App* app) {
    if (SDL_SetRenderDrawColor(app->renderer,86,227,159,SDL_ALPHA_OPAQUE) != 0)
        sdlExitWithMessage("can't change the fill color to black");
}

void setColorRed(App* app) {
    if (SDL_SetRenderDrawColor(app->renderer,156,74,63,SDL_ALPHA_OPAQUE) != 0)
        sdlExitWithMessage("can't change the fill color to black");
}

void sdlExitWithMessage(const char* message) {
    fprintf(stderr,"ERROR: %s: %s\n",message,SDL_GetError());
    exit(EXIT_FAILURE);
}