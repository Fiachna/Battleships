#include "cell.h"

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    Cell::Cell()
    {
        state = UNKNOWN;
        occupant = NULL;
    }
//----------------------------------------------------------------------------------------------------------//
    void Cell::setCellState(State newState)
    {
        state = newState;
        if(newState == HIT && occupant != NULL)
        {
            occupant->addHit();
            occupant = NULL; // this cell will not be possible to query for a ship again, prevents problems arising with multiple references to an object.
        }
    }
//----------------------------------------------------------------------------------------------------------//
}
