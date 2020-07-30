#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "properties.h"
#include "grid.h"
#include "rules.h"
#include "view.h"

int main(int argc, char* argv[]) {
    srand(time(0));

    // Fetching parameters
    int maxIter;
    double p;
    struct timespec t;

    if (argc == 4) {
        // Maximum number of steps
        maxIter = atoi(argv[1]);
        // Delay per step
        long timeMs = atol(argv[2]); // argv[2] in ms
        t.tv_sec = timeMs/1000;
        t.tv_nsec = 1000000L*(timeMs%1000);
        // Initial porosity of the grid
        p = atof(argv[3]);
        if (p < 0 || p > 1)
            p = 0.15; // by default 
    } else {
        maxIter = 300;
        t.tv_nsec = 70000000L;
        t.tv_sec = 0;
        p = 0.15;
    }

    // Init
    Grid grid;
    initGrid(grid);
    randomInitialState(grid,p);

    // Rendering
    App* app = applicationInit(app);
    int iter = 0;
    while (iter < maxIter) {
        step1update(grid);
        renderGrid(app,grid);
        nanosleep(&t,NULL);
        cleanRendering(app);
        step2update(grid);
        iter++;
    }
    
    applicationQuit(app);
    return 0;
}
