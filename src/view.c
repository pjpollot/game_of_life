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
    
    app->renderer = SDL_CreateRenderer(app->window,-1,SDL_RENDERER_SOFTWARE);
    if (app->renderer == NULL)
        sdlExitWithMessage("can't create the renderer");

    // - drawing and rectangle parameters
    if (SDL_SetRenderDrawColor(app->renderer,255,255,255,SDL_ALPHA_OPAQUE) != 0)
        sdlExitWithMessage("can't set the color of rendering");
    
    app->rectangle.h = HEIGHT/NGRID;
    app->rectangle.w = WIDTH/NGRID;

    // Displaying
    while (SDL_PollEvent(&(app->event))) {
        /* NOTHING */
    }

    return app;
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

void sdlExitWithMessage(const char* message) {
    fprintf(stderr,"ERROR: %s: %s\n",message,SDL_GetError());
    exit(EXIT_FAILURE);
}