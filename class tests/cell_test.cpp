#include "cell.h"
#include <iostream>

using namespace std;
using namespace Battleships;

int main()
{
    Cell::State testState;
    Ship* aBattleship;
    Cell* testCell;

    cout << "creating a cell and a ship to go in it" << endl;

    aBattleship = new Ship;
    aBattleship->init_Ship("Battleship");

    testCell = new Cell;
    testState = testCell->getCellState();

    cout << "Memory location for test ship: " << int(testCell->getOccupant()) << " Current state: " << testState << endl;
    cout << "Above values should both be 0 at this stage" << endl;

    testCell->setCellOccupant(aBattleship);

    cout << "Ship at location " << int(testCell->getOccupant()) << " now referenced in cell." << endl;

    testCell->setCellState(Cell::MISS);
    testState = testCell->getCellState();

    cout << "State is now: " << testState << " should be 10" << endl;

    testCell->setCellState(Cell::HIT);
    testState = testCell->getCellState();

    cout << "State is now: " << testState << " Occupant is at address: " << int(testCell->getOccupant()) << endl;
    cout << "The above should read 20, 0 respectively." << endl;

    delete aBattleship;
    delete testCell;
}
