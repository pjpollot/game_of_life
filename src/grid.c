#include "grid.h"

void initGrid(Grid grid) {
    // The horizontal layers
    for (int j = 0; j < NGRID+2; j++) {
        grid[0][j] = '*';
        grid[NGRID+1][j] = '*';
    }
    grid[0][NGRID+2] = '\0';
    grid[NGRID+1][NGRID+2] = '\0';

    // The main layers
    for (int i = 1; i <= NGRID; i++) {
        grid[i][0] = '*';
        for (int j = 1; j < NGRID+1; j++)
            grid[i][j] = ' ';
        grid[i][NGRID+1] = '*';
        grid[i][NGRID+2] = '\0';
    } 
}

int loadSave(Grid grid, const char* fileName) {
    FILE* seedFile = fopen(fileName,"r");
    if (seedFile == NULL) return 1; // Error: file not found
    unsigned x, y;
    while (!feof(seedFile)) {
        fscanf(seedFile,"%d %d",&y,&x);
        grid[y][x] = '$';
    }
    fclose(seedFile);
    return 0; // All went well
}

void randomInitialState(Grid grid, const double p) {
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            if (((double) rand())/RAND_MAX <= p)
                grid[i][j] = '$'; // Then it's alive
        }
    }
}