#include "chooser.h"

#ifndef RANDOM_H
#define RANDOM_H

using namespace std;

namespace Battleships
{
    class Random : public Chooser
    {
        public:

        void choosePosition(Ship& shipToPlace);
        bool getPositionValid(Coordinate* thePosition, unsigned shipLength, bool horizontal);
    };
}
#endif
