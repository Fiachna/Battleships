#include "specific.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Specific::choosePosition(Ship& shipToPlace)
    {
        unsigned row, column, i;
        Cell* tempCell;
        bool horizontal = false;
        Coordinate* thePosition;

        theInterface->showMyBoard(*theBoard);
        theInterface->showFleet(*theBoard);

        do
        {
            do
            {
                thePosition = NULL;
                if(ismouseclick(WM_RBUTTONDOWN))
                {
                    horizontal = abs(horizontal - 1);
                    clearmouseclick(WM_RBUTTONDOWN);
                }
                else if(ismouseclick(WM_LBUTTONDOWN))
                {
                    thePosition = theInterface->getCoordinate(*theBoard, 59);
                    clearmouseclick(WM_LBUTTONDOWN);
                }
            }while(thePosition == NULL);

        }while(getPositionValid(thePosition, shipToPlace.getShipLength(), horizontal) == false);

        row = thePosition->getCoordinateRow();
        column = thePosition->getCoordinateColumn();

        for(i=0; i<shipToPlace.getShipLength(); i++)
        {
            if(horizontal == true)
            {
                tempCell = theBoard->getCellByLocation(row, column + i);
                tempCell->setCellOccupant(&shipToPlace);
            }
            else
            {
                tempCell = theBoard->getCellByLocation(row + i, column);
                tempCell->setCellOccupant(&shipToPlace);
            }
            theInterface->showFleet(*theBoard);
        }


        delete thePosition;
    }
//----------------------------------------------------------------------------------------------------------//
    bool Specific::getPositionValid(Coordinate* thePosition, unsigned shipLength, bool horizontal)
    {
        unsigned row, column, i;
        Cell* tempCell;
        bool isValid = true; // just a temporary measure to ensure conditionals work further down

        row = thePosition->getCoordinateRow();
        column = thePosition->getCoordinateColumn();

        //make sure the location isn't out of bounds, this check should never be used, but just in case...
        if(column > theBoard->getBoardColumns() || row > theBoard->getBoardRows())
        {
            isValid = false;
        }

        //make sure the ship doesn't go out of bounds, very important!
        if(horizontal == true && (column + shipLength) > theBoard->getBoardColumns())
        {
            isValid = false;
        }
        else if(horizontal == false && (row + shipLength) > theBoard->getBoardRows())
        {
            isValid = false;
        }


        //finally check for other ships in the area
        if(isValid == true)
        {
            for(i=0; i<shipLength; i++)
            {
                if(horizontal == true && isValid == true)
                {
                    tempCell = theBoard->getCellByLocation(row, column + i);
                    if(tempCell->getOccupant() != NULL)
                    {
                        isValid = false;
                    }
                }
                else if(horizontal == false && isValid == true)
                {
                    tempCell = theBoard->getCellByLocation(row + i, column);
                    if(tempCell->getOccupant() != NULL)
                    {
                        isValid = false;
                    }
                }
            }
        }
        return isValid;
    }
//----------------------------------------------------------------------------------------------------------//
}
