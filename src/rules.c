#include "rules.h"

static unsigned countLivingNeighors(const unsigned layerIndex, const unsigned columnIndex, const Grid grid) {
    unsigned count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (l!=0 || k!=0) 
                count += (grid[layerIndex+k][columnIndex+l] == '$');
        }
    }
    return count;
}

void update(Grid grid) {
    // Updating
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            unsigned count;
            switch (grid[i][j])
            {
            case '$': // Alive
                count = countLivingNeighors(i,j,grid);
                if (count > 3 || count < 2) 
                    grid[i][j] = ' '; // The cell dies
                break;

            case ' ': // Dead
                count = countLivingNeighors(i,j,grid);
                if (count == 3) 
                    grid[i][j] = '0'; // The cell becomes alive in the next generation
                break;

            default:
                break;
            }
        }
    }
    // Next generation
    for (int i = 1; i <= NGRID; i++) {
        for (int j = 1; j <= NGRID; j++) {
            if (grid[i][j] == '0')
                grid[i][j] = '$';
        }
    }
}