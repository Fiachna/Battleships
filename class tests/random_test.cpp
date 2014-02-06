#include "random.h"
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

    theChooser = new Random;
    theChooser->setBoard(testBoard);
    theChooser->init_Fleet(testFleet);

    for(i=0; i<testFleet.size(); i++)
    {
        tempShip = &testFleet[i];
        cout << "tempShip set" << endl;
        theChooser->choosePosition(*tempShip);
        cout << "tempShip placed" << endl;
    }

    theInterface = new Graphical;
    theInterface->init_Interface();
    theInterface->showMyBoard(*testBoard);
    theInterface->showFleet(*testBoard);

    cin.get();
}
