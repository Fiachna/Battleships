#include "novice.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    Novice::Novice(Coordinate* sizeOfBoard, string playerName)
    {
        Chooser* theMethod = new Random;
        init_Local(theMethod, sizeOfBoard, playerName);
    }
//----------------------------------------------------------------------------------------------------------//
    Novice::~Novice()
    {
        uninit_Local();
    }
//----------------------------------------------------------------------------------------------------------//
    Attack* Novice::getAttack()
    {
        unsigned selector;
        string targetName, tempName;
        Coordinate* targetCoordinate;
        Board* targetBoard;
        Cell* tempCell;
        Attack* theAttack;
        map<string, Board>::iterator it;
        vector<string> names;

        for(it=opponents.begin(); it!=opponents.end(); it++)
        {
            tempName = (*it).first;
            names.push_back(tempName);
        }

        selector = rand() % names.size();
        targetName = names[selector];
        targetBoard = &(opponents[targetName]);
        do
        {
            targetCoordinate = new Coordinate;
            targetCoordinate->init_RandomCoordinate(boardSize->getCoordinateRow(), boardSize->getCoordinateColumn());
            tempCell = targetBoard->getCellByCoordinate(*targetCoordinate);
        }while(tempCell->getCellState() != Cell::UNKNOWN);

        theAttack = new Attack;
        theAttack->init_Attack(targetName, targetCoordinate);
        return theAttack;
    }
//----------------------------------------------------------------------------------------------------------//
    void Novice::setAttackResult(Attack* theAttack)
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
    }
//----------------------------------------------------------------------------------------------------------//
}
