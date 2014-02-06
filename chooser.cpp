#include "chooser.h"
#include <math.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Chooser::init_Fleet(vector<Ship>& theFleet)
    {
        unsigned shipNumberModifier, i;
        unsigned numCarriers, numBattleships, numDestroyers, numFrigates;
        Ship* newShip;

        theFleet.clear(); // make sure there's no garbage in the fleet vector

        if(theBoard->getBoardColumns() == theBoard->getBoardRows())
        {
            shipNumberModifier = sqrt(theBoard->getBoardColumns() * theBoard->getBoardRows());
        }
        else if(theBoard->getBoardColumns() > theBoard->getBoardRows())
        {
            shipNumberModifier = theBoard->getBoardRows();
        }
        else
        {
            shipNumberModifier = theBoard->getBoardColumns();
        }

        numCarriers = 1;
        numBattleships = (shipNumberModifier - 1) / 4;
        numDestroyers = (shipNumberModifier - 1) / 3;
        numFrigates = (shipNumberModifier - 1) / 2;

        //Create a carrier

        newShip = new Ship;
        newShip->init_Ship("Carrier");
        theFleet.push_back(*newShip);

        //Create some battleships

        for(i=0; i<numBattleships; i++)
        {
            newShip = new Ship;
            newShip->init_Ship("Battleship");
            theFleet.push_back(*newShip);
        }

        //Create some destroyers

        for(i=0;  i<numDestroyers; i++)
        {
            newShip = new Ship;
            newShip->init_Ship("Destroyer");
            theFleet.push_back(*newShip);
        }

        //Create some frigates

        for(i=0; i<numFrigates; i++)
        {
            newShip = new Ship;
            newShip->init_Ship("Frigate");
            theFleet.push_back(*newShip);
        }
    }
//----------------------------------------------------------------------------------------------------------//
}
