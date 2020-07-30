#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "rules.h"
#include "view.h"

int main() {
    /*
    Grid grid;
    initGrid(grid);
    setSeed(grid,"saves/seed");
    do {
        printGrid(grid);
        printf("\n");
        update(grid);
        sleep(1);
    } while (1);
    */
    App* app = applicationInit(app);
    sleep(6);
    applicationQuit(app);
    return 0;
}