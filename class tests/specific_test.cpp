#include "specific.h"
#include "graphical.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned i;
    Board* testBoard;
    Ship* tempShip;
    vector<Ship> testFleet;
    Interface* theInterface;
    Chooser* theChooser;

    srand(time(NULL));

    testBoard = new Board;
    testBoard->init_Board(10, 10);

    theInterface = new Graphical;
    theInterface->init_Interface();

    theChooser = new Specific(theInterface);
    theChooser->setBoard(testBoard);
    theChooser->init_Fleet(testFleet);

    theInterface->showMyBoard(*testBoard);

    for(i=0; i<testFleet.size(); i++)
    {
        tempShip = &testFleet[i];
        cout << "tempShip set" << endl;
        theChooser->choosePosition(*tempShip);
        cout << "tempShip placed" << endl;
        theInterface->showFleet(*testBoard);
    }
    cin.get();
}
