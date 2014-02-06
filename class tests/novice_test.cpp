#include "novice.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned row, column, i;
    unsigned N1_Losses, N2_Losses;
    Coordinate* testSize;
    Coordinate* tempCoordinate;
    string testName1, testName2, loserName;
    Chooser* testChooser;
    Interface* testInterface;
    Player* testNovice1;
    Player* testNovice2;
    Board* testBoard;
    Attack* testAttack;

    srand(time(NULL));
    N1_Losses = 0;
    N2_Losses = 0;

    testName1 = "Pugwash";
    testName2 = "Roger";

    testSize = new Coordinate;
    testSize->init_SpecificCoordinate(10, 10);

    testChooser = new Random;

    testInterface = new Graphical;
    testInterface->init_Interface();
    for(i=0; i<100; i++)
    {
        testNovice1 = new Novice(testSize, testName1);
        testNovice2 = new Novice(testSize, testName2);
        testNovice1->setupFleet();
        testNovice2->setupFleet();
        testNovice1->addOpponent(testNovice2);
        testNovice2->addOpponent(testNovice1);

        testAttack = NULL;

        testBoard = testNovice1->getBoard();

        testInterface->showMyBoard(*testBoard);
        testInterface->showFleet(*testBoard);

        testBoard = testNovice2->getBoard();

        testInterface->showMyBoard(*testBoard);
        testInterface->showFleet(*testBoard);

        do
        {
            if(testAttack != NULL)
            {
                testAttack->uninit_Attack();
            }
            testAttack = testNovice1->getAttack();

            tempCoordinate = testAttack->getTargetCoordinate();
            row = tempCoordinate->getCoordinateRow();
            column = tempCoordinate->getCoordinateColumn();

            cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

            testNovice2->processAttack(testAttack);
            testNovice1->setAttackResult(testAttack);

            testBoard = testNovice2->getBoard();

            testInterface->showOpponentBoard(*testBoard);

            if(testAttack->getFleetDestroyed() == false)
            {
                testAttack->uninit_Attack();
                testAttack = testNovice2->getAttack();

                tempCoordinate = testAttack->getTargetCoordinate();
                row = tempCoordinate->getCoordinateRow();
                column = tempCoordinate->getCoordinateColumn();

                cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

                testNovice1->processAttack(testAttack);
                testNovice2->setAttackResult(testAttack);

                testBoard = testNovice1->getBoard();

                testInterface->showMyBoard(*testBoard);
            }
        }while(testAttack->getFleetDestroyed() == false);

        loserName = testAttack->getTargetName();
        if(loserName.compare(testName1) == 0)
        {
            N1_Losses++;
        }
        else
        {
            N2_Losses++;
        }
        cout << testAttack->getTargetName() << " has been defeated!" << endl;
        testAttack->uninit_Attack();
        delete testAttack;
        delete testNovice1;
        delete testNovice2;
    }
    cout << testName1 << " lost " << N1_Losses << " " << testName2 << " lost " << N2_Losses << endl;
    cin.get();
}
