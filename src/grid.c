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

void printGrid(const Grid grid) {
    for (int i = 0; i < NGRID+2; i++) 
        printf("%s\n",grid[i]);
}

int setSeed(Grid grid, const char* fileName) {
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