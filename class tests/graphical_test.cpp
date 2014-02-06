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

    cout << "Pick some random coordinates then redrawing board with updated cell states" << endl;

    i = 0;

    do
    {
        testCoordinate = theInterface->getCoordinate(*testBoard, 58);
        if(testCoordinate != NULL)
        {
            cout << "coordinate at row " << testCoordinate->getCoordinateRow() + 1 << ", column " << testCoordinate->getCoordinateColumn() + 1 << endl;
            testCell = testBoard->getCellByCoordinate(*testCoordinate);
            testCell ->setCellState(Cell::MISS);
            i++;
            theInterface->showMyBoard(*testBoard);
        }
    }while(i < 10);

    cin.get();
}

