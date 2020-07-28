#include <unistd.h>
#include <stdio.h>
#include "grid.h"
#include "rules.h"

int main() {
    Grid grid;
    initGrid(grid);
    setSeed(grid,"saves/seed");
    do {
        printGrid(grid);
        printf("\n");
        update(grid);
        sleep(1);
    } while (1);
    return 0;
}