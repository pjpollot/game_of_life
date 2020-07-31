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
    char withColor = 0;
    struct timespec t;
    t.tv_nsec = 70000000L;
    t.tv_sec = 0;

    int param = 0;
    long timeMs;
    while (param != -1) {
        param = getopt(argc,argv,"i:t:p:c");
        switch (param)
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
        case 'c':
            withColor = 1;
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
    if (withColor) {
        // Then we print all cells => colorful screen
        while (iter < maxIter) {
            step1update(grid);
            renderGrid(app,grid);
            nanosleep(&t,NULL);
            cleanRendering(app);
            step2update(grid);
            iter++;
        }
    } else {
        // Then we print only the living and dead cells => black and white screen
        while (iter < maxIter) {
            renderGrid(app,grid);
            nanosleep(&t,NULL);
            cleanRendering(app);
            update(grid);
            iter++;
        }
    }
    
    applicationQuit(app);
    return EXIT_SUCCESS;
}
