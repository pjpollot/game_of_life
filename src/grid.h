#ifndef GRID_H
#define GRID_H

#include <stdio.h>

#define NGRID 40

typedef char Grid[NGRID+2][NGRID+3];
/** Grid type: 
* - The first and last layers (eg grid[0] and grid[NGRID+1]) are the horizontal borders.
* - The first and before-last columns (eg grid[k][0] and grid[k][NGRID+1] for any k) are the vertical borders.
* - The last column (eg grid[k][NGRID+2]) is the end-of-string character, ie '\0'.
* - A border component is the char '*'.
* - A living cell is represented by the char '$'.
* - Half-living cell (those which will live at the next generation) are reprensented by the char '0'.
* - A dead cell is reprensented by the char ' '.
*/
void initGrid(Grid);

void printGrid(const Grid);

int setSeed(Grid, const char* fileName);

#endif