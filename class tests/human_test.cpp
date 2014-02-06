#include "novice.h"
#include "expert.h"
#include "human.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned row, column;
    unsigned N_Losses, H_Losses;
    Coordinate* testSize;
    Coordinate* tempCoordinate;
    string testName1, testName2, loserName;
    Chooser* testChooser;
    Interface* testInterface;
    Player* testNovice;
    Player* testHuman;
    Board* testBoard;
    Attack* testAttack;

    srand(time(NULL));
    N_Losses = 0;
    H_Losses = 0;

    testName1 = "Pugwash";
    testName2 = "Roger";

    testSize = new Coordinate;
    testSize->init_SpecificCoordinate(10, 10);

    testChooser = new Random;

    testInterface = new Graphical;
    testInterface->init_Interface();

    testNovice = new Novice(testSize, testName1);
    testHuman = new Human(testInterface, testSize, testName2);
    testNovice->setupFleet();
    testHuman->setupFleet();
    testNovice->addOpponent(testHuman);
    testHuman->addOpponent(testNovice);

    testAttack = NULL;

    testBoard = testNovice->getBoard();

    testInterface->showMyBoard(*testBoard);
    testInterface->showFleet(*testBoard);

    testBoard = testHuman->getBoard();

    testInterface->showMyBoard(*testBoard);
    testInterface->showFleet(*testBoard);

    do
    {
        testAttack = testNovice->getAttack();

        tempCoordinate = testAttack->getTargetCoordinate();
        row = tempCoordinate->getCoordinateRow();
        column = tempCoordinate->getCoordinateColumn();

        cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

        testHuman->processAttack(testAttack);
        testNovice->setAttackResult(testAttack);

        testBoard = testHuman->getBoard();

        testInterface->showMyBoard(*testBoard);
        testInterface->showFleet(*testBoard);

        if(testAttack->getFleetDestroyed() == false)
        {
            testAttack = testHuman->getAttack();

            tempCoordinate = testAttack->getTargetCoordinate();
            row = tempCoordinate->getCoordinateRow();
            column = tempCoordinate->getCoordinateColumn();

            cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

            testNovice->processAttack(testAttack);
            testHuman->setAttackResult(testAttack);
        }
    }while(testAttack->getFleetDestroyed() == false);

    loserName = testAttack->getTargetName();
    if(loserName.compare(testName1) == 0)
    {
        N_Losses++;
    }
    else
    {
        H_Losses++;
    }
    cout << testAttack->getTargetName() << " has been defeated!" << endl;
    testAttack->uninit_Attack();
    delete testAttack;
    delete testNovice;
    delete testHuman;
    cout << testName1 << " lost " << N_Losses << " " << testName2 << " lost " << H_Losses << endl;
    cin.get();
}

