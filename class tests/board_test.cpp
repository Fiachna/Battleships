#include "board.h"
#include "graphical.h"
#include <iostream>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned i;
    Coordinate* testCoordinate;
    Cell* testCell;
    Board* testBoard;
    Interface* theInterface;

    cout << "Creating a 10x10 board and using graphical interface to display it." << endl;

    testBoard = new Board;
    testBoard->init_Board(10, 10);

    cout << "Board size is: " << testBoard->getBoardRows() << " rows by " << testBoard->getBoardColumns() << " columns." << endl;

    theInterface = new Graphical;
    theInterface->init_Interface();
    theInterface->showMyBoard(*testBoard);

    cout << "Generating some random coordinates then redrawing board with updated cell states" << endl;

    testCoordinate = new Coordinate;

    for(i=0; i<10; i++)
    {
        testCoordinate->init_RandomCoordinate(10, 10);
        cout << "coordinate at row " << testCoordinate->getCoordinateRow() + 1 << ", column " << testCoordinate->getCoordinateColumn() + 1 << endl;
        testCell = testBoard->getCellByCoordinate(*testCoordinate);
        testCell ->setCellState(Cell::MISS);
    }

    theInterface->showMyBoard(*testBoard);


    cin.get();
}
