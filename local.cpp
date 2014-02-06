#include "local.h"
#include <iostream>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Local::init_Local(Chooser* theMethod, Coordinate* sizeOfBoard, string playerName)
    {
        init_Player(playerName, sizeOfBoard);

        myBoard = new Board;
        myBoard->init_Board(boardSize->getCoordinateRow(), boardSize->getCoordinateColumn());

        setupType = theMethod;
        theMethod->setBoard(myBoard);
        theMethod->init_Fleet(myFleet);
    }
//----------------------------------------------------------------------------------------------------------//
    void Local::setupFleet()
    {
        unsigned i;
        string helpTextl1, helpTextl2;          //this stuff until...
        int helpTextl1X, helpTextl2X, helpTextY;

        helpTextl1 = "Place your ships";
        helpTextl2 = "right click to rotate";

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

        helpTextl1X = (512 - textwidth(helpTextl1.c_str())) / 2 + 512;
        helpTextl2X = (512 - textwidth(helpTextl2.c_str())) / 2 + 512;
        helpTextY = 320;

        outtextxy(helpTextl1X, helpTextY, helpTextl1.c_str());
        outtextxy(helpTextl2X, helpTextY + 20, helpTextl2.c_str()); //...here needs to be commented out to run expert test class driver


        for(i=0; i<myFleet.size(); i++)
        {
            setupType->choosePosition(myFleet[i]);
        }
        delete setupType;

        setfillstyle(SOLID_FILL, BLACK); //also here
        bar(512, helpTextY, 1023, helpTextY + 60); //and here
    }
//----------------------------------------------------------------------------------------------------------//
    void Local::uninit_Local()
    {
        Board* tempBoard;
        map<string, Board>::iterator it;

        myFleet.clear();
        myBoard->uninit_Board();

        for(it=opponents.begin(); it!=opponents.end(); it++)
        {
            tempBoard = &(it->second);
            tempBoard->uninit_Board();
        }

        opponents.clear();

        delete myBoard;
    }
//----------------------------------------------------------------------------------------------------------//
    void Local::addOpponent(Player* theOpponent)
    {
        string opponentName;
        Board* opponentBoard;
        Coordinate* tempCoordinate;

        tempCoordinate = theOpponent->getBoardSize();

        opponentName = theOpponent->getName();
        opponentBoard = new Board;
        opponentBoard->init_Board(tempCoordinate->getCoordinateRow(), tempCoordinate->getCoordinateColumn());

        opponents[opponentName] = *opponentBoard;
    }
//----------------------------------------------------------------------------------------------------------//
    void Local::processAttack(Attack *theAttack)
    {
        if(theAttack->getTargetName() == myName)
        {
            unsigned i;
            bool fleetSunk;
            Ship* tempShip;
            Coordinate* tempCoordinate = theAttack->getTargetCoordinate();
            Cell* tempCell = myBoard->getCellByCoordinate(*tempCoordinate);

            if(tempCell->getCellState() != Cell::UNKNOWN)
            {
                theAttack->setResult(tempCell->getCellState());
            }
            else
            {
                if(tempCell->getOccupant() != NULL)
                {
                    tempCell->setCellState(Cell::HIT);
                    theAttack->setResult(Cell::HIT);
                    fleetSunk = true;

                    for(i=0; i<myFleet.size(); i++)
                    {
                        tempShip = &(myFleet[i]);
                        if (tempShip->isSunk() == false)
                        {
                            fleetSunk = false;
                        }
                    }

                    if (fleetSunk == true)
                    {
                        theAttack->setFleetDestroyed(true);
                    }
                }
                else
                {
                    tempCell->setCellState(Cell::MISS);
                    theAttack->setResult(Cell::MISS);
                }
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
}
