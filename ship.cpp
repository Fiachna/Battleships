#include "ship.h"
#include <iostream>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Ship::init_Ship(string shipType)
    {
        if(shipType.compare("Carrier") == 0)
        {
            name = shipType;
            length = 6;
            hitCount = 0;
        }
        else if(shipType.compare("Battleship") == 0)
        {
            name = shipType;
            length = 4;
            hitCount = 0;
        }
        else if(shipType.compare("Destroyer") == 0)
        {
            name = shipType;
            length = 3;
            hitCount = 0;
        }
        else if(shipType.compare("Frigate") == 0)
        {
            name = shipType;
            length = 2;
            hitCount = 0;
        }
        else
        {
            cout << "If you see this then I have made a grave spelling error somewhere" << endl;
        }
    }
//----------------------------------------------------------------------------------------------------------//
    bool Ship::isSunk()
    {
        if(hitCount >= length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
