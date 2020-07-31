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
    int maxIter = 300;
    double p = 0.15;
    struct timespec t;
    t.tv_nsec = 70000000L;
    t.tv_sec = 0;

    int c = 0;
    long timeMs;
    while (c != -1) {
        c = getopt(argc,argv,"i:t:p:");
        switch (c)
        {
        case 'i':
            maxIter = atoi(optarg);
            break;
        case 't':
            timeMs = atol(optarg);
            t.tv_sec = timeMs/1000;
            t.tv_nsec = 1000000L*(timeMs%1000);
            break;
        case 'p':
            p = atof(optarg);
            if (p < 0 || p > 1) p = 0.15; // We keep the default value
            break;
        default:
            break;
        }    
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
    return EXIT_SUCCESS;
}
