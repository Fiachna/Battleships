#include "human.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    Human::Human(Interface* interfaceToUse, Coordinate* sizeOfBoard, string playerName)
    {
        Chooser* theMethod = new Specific(interfaceToUse);
        theInterface = interfaceToUse;
        init_Local(theMethod, sizeOfBoard, playerName);
    }
//----------------------------------------------------------------------------------------------------------//
    Human::~Human()
    {
        uninit_Local();
    }
//----------------------------------------------------------------------------------------------------------//
    void Human::setCurrentPlayer()
    {
        string details;
        int textPositionX, textPositionY;

        details = "The current player is ";
        details += myName;

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

        textPositionX = (1024 - textwidth(details.c_str())) / 2;
        textPositionY = (124 - textheight(details.c_str())) / 2;

        setfillstyle(SOLID_FILL, BLUE);
        bar(0, textPositionY, 1023, textPositionY + textheight(details.c_str()));
        outtextxy(textPositionX, textPositionY, details.c_str());

        theInterface->showMyBoard(*myBoard);
        theInterface->showFleet(*myBoard);
    }
//----------------------------------------------------------------------------------------------------------//
    void Human::setAttackResult(Attack* theAttack)
    {
        Board* tempBoard;
        Cell* tempCell;
        Coordinate* tempCoordinate;
        Cell::State result;
        string playerName;

        playerName = theAttack->getTargetName();
        tempBoard = &(opponents[playerName]);

        tempCoordinate = theAttack->getTargetCoordinate();
        tempCell = tempBoard->getCellByCoordinate(*tempCoordinate);

        result = theAttack->getResult();
        tempCell->setCellState(result);

        theInterface->showOpponentBoard(*tempBoard);
    }
    Attack* Human::getAttack()
    {
        int opponentTextX, opponentTextY;
        map<string, Board>::iterator it;
        string currentTarget;
        Board* targetBoard;
        Cell* tempCell;
        Coordinate* targetCoordinate;
        Attack* theAttack;

        it = opponents.begin();
        do
        {
            if(kbhit() == true)
            {
                if(getch() == KEY_RIGHT)
                {
                    if(it != opponents.end())
                    {
                        it++;
                    }
                    if(it == opponents.end())
                    {
                        it = opponents.begin();
                    }
                }
                else if(getch() == KEY_LEFT)
                {
                    if(it == opponents.begin())
                    {
                        it = opponents.end();
                        it--;
                    }
                    else if(it != opponents.begin())
                    {
                        it--;
                    }
                }
                setfillstyle(SOLID_FILL, BLACK);
                bar(0, opponentTextY, 1023, opponentTextY + textheight(currentTarget.c_str()));
            }

            currentTarget = (*it).first;
            targetBoard = &(opponents[currentTarget]);

            theInterface->showOpponentBoard(*targetBoard);

            settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

            opponentTextX = (512 - textwidth(currentTarget.c_str())) / 2 + 512;
            opponentTextY = 590;

            outtextxy(opponentTextX, opponentTextY, currentTarget.c_str());

            targetCoordinate = theInterface->getCoordinate(*targetBoard, 571);
            if(targetCoordinate != NULL)
            {
                tempCell = targetBoard->getCellByCoordinate(*targetCoordinate);
                if(tempCell->getCellState() != Cell::UNKNOWN)
                {
                    targetCoordinate = NULL;
                }
            }

        }while(targetCoordinate == NULL);

        theAttack = new Attack;
        theAttack->init_Attack(currentTarget, targetCoordinate);

        return theAttack;
    }
//----------------------------------------------------------------------------------------------------------//
}
