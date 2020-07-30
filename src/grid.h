#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

#define NGRID 100

typedef char Grid[NGRID+2][NGRID+3];
/** Grid type: 
* - The first and last layers (eg grid[0] and grid[NGRID+1]) are the horizontal borders.
* - The first and before-last columns (eg grid[k][0] and grid[k][NGRID+1] for any k) are the vertical borders.
* - The last column (eg grid[k][NGRID+2]) is the end-of-string character, ie '\0'.
* - A border component is the char '*'.
* - A living cell is represented by the char '$'.
* - A dead cell is reprensented by the char ' '.
* - A dying cell is reprensented by the char '-' and it is considered as a current living cell.
* - A newborn cell is represented by the char '0' and it is considered as a current dead cell.
*/
void initGrid(Grid);

int loadSave(Grid, const char* fileName);

// p is the probabily that one cell is alive
void randomInitialState(Grid, const double p);

#endif