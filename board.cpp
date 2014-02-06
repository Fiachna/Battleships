#include "board.h"

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Board::init_Board(unsigned rows, unsigned columns)
    {
        unsigned i;

        grid.resize(rows);
        for(i=0; i<columns; i++)
        {
            grid[i].resize(columns);
        }
    }
//----------------------------------------------------------------------------------------------------------//
    void Board::uninit_Board()
    {
        unsigned i, numRows;

        numRows = grid.size();

        for(i=0; i<numRows; i++)
        {
            grid[i].clear();
        }

        grid.clear();
    }
//----------------------------------------------------------------------------------------------------------//
    Cell* Board::getCellByCoordinate(Coordinate selection)
    {
        unsigned row, column;
        row = selection.getCoordinateRow();
        column = selection.getCoordinateColumn();

        return &grid[row][column];
    }
//----------------------------------------------------------------------------------------------------------//
}
