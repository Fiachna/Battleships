#include "novice.h"
#include "expert.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned row, column, i;
    unsigned N_Losses, E_Losses;
    Coordinate* testSize;
    Coordinate* tempCoordinate;
    string testName1, testName2, loserName;
    Chooser* testChooser;
    Player* testNovice;
    Player* testExpert;
    Attack* testAttack;

    srand(time(NULL));
    N_Losses = 0;
    E_Losses = 0;

    testName1 = "Pugwash";
    testName2 = "Roger";

    testSize = new Coordinate;
    testSize->init_SpecificCoordinate(10, 10);

    testChooser = new Random;

    for(i=0; i<1000; i++)
    {
        testNovice = new Novice(testSize, testName1);
        testExpert = new Expert(testSize, testName2);
        testNovice->setupFleet();
        testExpert->setupFleet();
        testNovice->addOpponent(testExpert);
        testExpert->addOpponent(testNovice);

        do
        {
            testAttack = testNovice->getAttack();

            tempCoordinate = testAttack->getTargetCoordinate();
            row = tempCoordinate->getCoordinateRow();
            column = tempCoordinate->getCoordinateColumn();

            cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

            testExpert->processAttack(testAttack);
            testNovice->setAttackResult(testAttack);

            if(testAttack->getFleetDestroyed() == false)
            {
                testAttack = testExpert->getAttack();

                tempCoordinate = testAttack->getTargetCoordinate();
                row = tempCoordinate->getCoordinateRow();
                column = tempCoordinate->getCoordinateColumn();

                cout << "Attack on " << testAttack->getTargetName() << " at row " << row << " column " << column << endl;

                testNovice->processAttack(testAttack);
                testExpert->setAttackResult(testAttack);
            }
        }while(testAttack->getFleetDestroyed() == false);

        loserName = testAttack->getTargetName();
        if(loserName.compare(testName1) == 0)
        {
            N_Losses++;
        }
        else
        {
            E_Losses++;
        }
        cout << testAttack->getTargetName() << " has been defeated!" << endl;
        testAttack->uninit_Attack();
        delete testAttack;
        delete testNovice;
        delete testExpert;
    }
    cout << testName1 << " lost " << N_Losses << " " << testName2 << " lost " << E_Losses << endl;
    cin.get();
}
