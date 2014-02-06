#include "coordinate.h"
#include <stdlib.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Coordinate::init_RandomCoordinate(unsigned maxRow, unsigned maxColumn)
    {
        row = rand() % maxRow;
        column = rand() % maxColumn;
    }
//----------------------------------------------------------------------------------------------------------//
}
