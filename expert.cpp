#include "expert.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    Expert::Expert(Coordinate* sizeOfBoard, string playerName)
    {
        Chooser* theMethod = new Random;
        init_Local(theMethod, sizeOfBoard, playerName);
        lastSuccess = NULL;
    }
//----------------------------------------------------------------------------------------------------------//
    Expert::~Expert()
    {
        uninit_Local();
    }
//----------------------------------------------------------------------------------------------------------//
    Attack* Expert::getAttack()
    {
        unsigned i;
        vector<Coordinate>* potentials;
        Coordinate* theTarget;
        Attack* theAttack;

        if(lastSuccess != NULL)
        {
            potentials = getPotentialTargets();
            if(potentials->size() > 0)
            {
                theAttack = new Attack;
                i = rand() % potentials->size();
                theTarget = new Coordinate;
                theTarget->init_SpecificCoordinate((*potentials)[i].getCoordinateRow(), (*potentials)[i].getCoordinateColumn());
                theAttack->init_Attack(lastSuccess->getTargetName(), theTarget);
                potentials->clear();
            }
            else
            {
                theAttack = randomAttack();
            }
        }
        else
        {
            theAttack = randomAttack();
        }
        return theAttack;
    }
//----------------------------------------------------------------------------------------------------------//
    void Expert::setAttackResult(Attack* theAttack)
    {
        Board* tempBoard;
        Attack* garbageCollection;
        Cell* tempCell;
        Coordinate* tempCoordinate;
        string playerName;

        playerName = theAttack->getTargetName();
        tempBoard = &(opponents[playerName]);

        tempCoordinate = theAttack->getTargetCoordinate();
        tempCell = tempBoard->getCellByCoordinate(*tempCoordinate);

        tempCell->setCellState(theAttack->getResult());
        if(theAttack->getResult() == Cell::HIT)
        {
            if(lastSuccess != NULL)
            {
                lastSuccess->uninit_Attack();
                garbageCollection = lastSuccess;
                lastSuccess = theAttack;
                delete garbageCollection;
            }
            else
            {
                lastSuccess = theAttack;
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
    Attack* Expert::randomAttack()
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
    bool Expert::getLocationValid(unsigned row, unsigned column, Board* theBoard)
    {
        bool isValid;

        if(row < theBoard->getBoardRows() && column < theBoard->getBoardColumns())
        {
            isValid = true;
        }
        else
        {
            isValid = false;
        }
        return isValid;
    }
//----------------------------------------------------------------------------------------------------------//
    Expert::Alignment Expert::getAttackOrientation()
    {
        unsigned baseRow, baseColumn;
        bool horizontal, vertical;
        string targetName;
        Board* tempBoard;
        Cell* tempCell = NULL;
        Coordinate* tempCoordinate;
        Alignment orientation;

        targetName = lastSuccess->getTargetName();
        tempBoard = &(opponents[targetName]);
        tempCoordinate = lastSuccess->getTargetCoordinate();

        baseRow = tempCoordinate->getCoordinateRow();
        baseColumn = tempCoordinate->getCoordinateColumn();

        orientation = NONE;
        horizontal = false;
        vertical = false;

        if(getLocationValid(baseRow+1, baseColumn, tempBoard) == true)
        {
            tempCell = tempBoard->getCellByLocation(baseRow+1, baseColumn);
            if(tempCell->getCellState() == Cell::HIT)
            {
                vertical = true;
            }
        }
        if(getLocationValid(baseRow-1, baseColumn, tempBoard) == true)
        {
            tempCell = tempBoard->getCellByLocation(baseRow-1, baseColumn);
            if(tempCell->getCellState() == Cell::HIT)
            {
                vertical = true;
            }
        }
        if(getLocationValid(baseRow, baseColumn+1, tempBoard) == true)
        {
            tempCell = tempBoard->getCellByLocation(baseRow, baseColumn+1);
            if(tempCell->getCellState() == Cell::HIT)
            {
                horizontal = true;
            }
        }
        if(getLocationValid(baseRow, baseColumn-1, tempBoard) == true)
        {
            tempCell = tempBoard->getCellByLocation(baseRow, baseColumn-1);
            if(tempCell->getCellState() == Cell::HIT)
            {
                horizontal = true;
            }
        }

        if(horizontal == true && vertical == true)
        {
            orientation = BOTH;
        }
        else if(horizontal == true && vertical == false)
        {
            orientation = HORIZONTAL;
        }
        else if(horizontal == false && vertical == true)
        {
            orientation = VERTICAL;
        }

        return orientation;
    }
//----------------------------------------------------------------------------------------------------------//
    vector<Coordinate>* Expert::getPotentialTargets()
    {
        unsigned baseRow, baseColumn, endsChecked, i;
        string targetName;
        Board* tempBoard;
        Cell* tempCell;
        Coordinate* tempCoordinate;
        Coordinate* targetCoordinate;
        Alignment orientation;
        vector<Coordinate>* potentials;

        targetName = lastSuccess->getTargetName();
        tempBoard = &(opponents[targetName]);
        tempCoordinate = lastSuccess->getTargetCoordinate();
        baseRow = tempCoordinate->getCoordinateRow();
        baseColumn = tempCoordinate->getCoordinateColumn();
        orientation = getAttackOrientation();

        potentials = new vector<Coordinate>;

        if(orientation != VERTICAL)
        {
            endsChecked = 0;
            i = 1;

            do
            {
                if(endsChecked == 0 && getLocationValid(baseRow, baseColumn+i, tempBoard) == true)
                {
                    tempCell = tempBoard->getCellByLocation(baseRow, baseColumn+i);
                    if(tempCell->getCellState() == Cell::UNKNOWN)
                    {
                        targetCoordinate = new Coordinate;
                        targetCoordinate->init_SpecificCoordinate(baseRow, baseColumn+i);
                        potentials->push_back(*targetCoordinate);
                        endsChecked = 1;
                        i = 1;
                    }
                    else if(tempCell->getCellState() == Cell::MISS)
                    {
                        endsChecked = 1;
                        i = 1;
                    }
                    else
                    {
                        i++;
                    }
                }
                else if(endsChecked == 0 && getLocationValid(baseRow, baseColumn+i, tempBoard) == false)
                {
                    endsChecked = 1;
                    i = 1;
                }
                else if(endsChecked == 1 && getLocationValid(baseRow, baseColumn-i, tempBoard) == true)
                {
                    tempCell = tempBoard->getCellByLocation(baseRow, baseColumn-i);
                    if(tempCell->getCellState() == Cell::UNKNOWN)
                    {
                        targetCoordinate = new Coordinate;
                        targetCoordinate->init_SpecificCoordinate(baseRow, baseColumn-i);
                        potentials->push_back(*targetCoordinate);
                        endsChecked = 2;
                    }
                    else if(tempCell->getCellState() == Cell::MISS)
                    {
                        endsChecked = 2;
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                {
                    endsChecked = 2;
                }
            }while(endsChecked < 2);
        }

        if(orientation != HORIZONTAL)
        {
            endsChecked = 0;
            i = 1;

            do
            {
                if(endsChecked == 0 && getLocationValid(baseRow+i, baseColumn, tempBoard) == true)
                {
                    tempCell = tempBoard->getCellByLocation(baseRow+i, baseColumn);
                    if(tempCell->getCellState() == Cell::UNKNOWN)
                    {
                        targetCoordinate = new Coordinate;
                        targetCoordinate->init_SpecificCoordinate(baseRow+i, baseColumn);
                        potentials->push_back(*targetCoordinate);
                        endsChecked = 1;
                        i = 1;
                    }
                    else if(tempCell->getCellState() == Cell::MISS)
                    {
                        endsChecked = 1;
                        i = 1;
                    }
                    else
                    {
                        i++;
                    }
                }
                else if(endsChecked == 0 && getLocationValid(baseRow+i, baseColumn, tempBoard) == false)
                {
                    endsChecked = 1;
                    i = 1;
                }
                else if(endsChecked == 1 && getLocationValid(baseRow-i, baseColumn, tempBoard) == true)
                {
                    tempCell = tempBoard->getCellByLocation(baseRow-i, baseColumn);
                    if(tempCell->getCellState() == Cell::UNKNOWN)
                    {
                        targetCoordinate = new Coordinate;
                        targetCoordinate->init_SpecificCoordinate(baseRow-i, baseColumn);
                        potentials->push_back(*targetCoordinate);
                        endsChecked = 2;
                    }
                    else if(tempCell->getCellState() == Cell::MISS)
                    {
                        endsChecked = 2;
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                {
                    endsChecked = 2;
                }
            }while(endsChecked < 2);
        }
        return potentials;
    }
//----------------------------------------------------------------------------------------------------------//
}

