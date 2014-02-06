#include "coordinate.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned row, column;
    Coordinate *testCoordinate;

    srand(time(NULL));

    cout << "enter a row value for a coordinate" << endl;
    cin >> row;
    cin.ignore();
    cout << "enter a column value for a coordinate" << endl;
    cin >> column;
    cin.ignore();

    testCoordinate = new Coordinate;
    testCoordinate->init_SpecificCoordinate(row, column);

    row = testCoordinate->getCoordinateRow();
    column = testCoordinate->getCoordinateColumn();

    cout << "Coordinate is row: " << row << " column " << column << endl;
    cout << "Randomising coordinate for 10x10 grid" << endl;

    testCoordinate->init_RandomCoordinate(10, 10);

    row = testCoordinate->getCoordinateRow();
    column = testCoordinate->getCoordinateColumn();

    cout << "Coordinate is row: " << row << " column " << column << endl;
    cin.get();

    delete testCoordinate;
}
