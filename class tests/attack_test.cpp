#include "attack.h"
#include <iostream>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned row, column;
    string targetName;
    Coordinate* targetCoordinate;
    Coordinate* tempCoordinate;
    Attack* theAttack;

    targetName = "target";
    targetCoordinate = new Coordinate;
    targetCoordinate->init_RandomCoordinate(10, 10);

    cout << "random coordinate generated at row " << targetCoordinate->getCoordinateRow() << " column " << targetCoordinate->getCoordinateColumn() << endl;

    theAttack = new Attack;
    theAttack->init_Attack(targetName, targetCoordinate);
    tempCoordinate = theAttack->getTargetCoordinate();
    row = tempCoordinate->getCoordinateRow();
    column = tempCoordinate->getCoordinateColumn();

    cout << "Attack on " << theAttack->getTargetName() << " at row " << row << " column " << column << endl;

    theAttack->setResult(Cell::HIT);
    theAttack->setFleetDestroyed(true);

    cout << "Attack result: " << theAttack->getResult() << " fleet destroyed status: " << theAttack->getFleetDestroyed() << endl;

    delete theAttack;

    cin.get();
}

