#include "rules.h"

static unsigned countLivingNeighors(const unsigned layerIndex, const unsigned columnIndex, const Grid grid) {
    unsigned count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (l!=0 || k!=0) 
                count += (grid[layerIndex+k][columnIndex+l] == '$' || grid[layerIndex+k][columnIndex+l] == '-');
        }
    }
    return count;
}

void update(Grid grid) {
    // Updating
    unsigned count;
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            count = countLivingNeighors(i,j,grid);
            switch (grid[i][j])
            {
            case '$':
                if (count > 3 || count < 2) 
                    grid[i][j] = '-'; // then the cell is dying
                break;
            case ' ':
                if (count == 3) 
                    grid[i][j] = '0'; // Then the cell will live the next generation
            default:
                break;
            }
        }
    }
    // Awaken the half-alive cells and kill the dying cells
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            if (grid[i][j] == '0') 
                grid[i][j] = '$';
            else if (grid[i][j] == '-')
                grid[i][j] = ' ';
        }
    }
}