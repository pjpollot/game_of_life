#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "rules.h"
#include "view.h"

int main(int argc, char* argv[]) {
    srand(time(0));

    // Init
    Grid grid;
    initGrid(grid);
    randomInitialState(grid,0.15);
    int maxIter;
    struct timespec t;

    if (argc == 3) {
        maxIter = atoi(argv[1]);
        long timeMs = atol(argv[2]); // argv[2] in ms
        t.tv_sec = timeMs/1000;
        t.tv_nsec = 1000000L*(timeMs%1000);
    } else {
        maxIter = 300;
        t.tv_nsec = 70000000L;
        t.tv_sec = 0;
    }

    // Rendering
    App* app = applicationInit(app);
    int iter = 0;
    do {
        renderGrid(app,grid);
        nanosleep(&t,NULL);
        update(grid);
        cleanRendering(app);
        iter++;
    } while (iter < maxIter);
    applicationQuit(app);
    return 0;
}
