#include "cell.h"
#include "coordinate.h"
#include <vector>

#ifndef BOARD_H
#define BOARD_H

using namespace std;

namespace Battleships
{
    class Board
    {
        private:

        vector<vector<Cell> > grid;

        public:

        void init_Board(unsigned rows = 12, unsigned columns = 12);
        void uninit_Board();
        unsigned getBoardRows() {return grid.size();}
        unsigned getBoardColumns() {return grid[0].size();}
        Cell* getCellByCoordinate(Coordinate selection);
        Cell* getCellByLocation(unsigned row, unsigned column) {return &(grid[row][column]);}
    };
}
#endif
