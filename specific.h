#include "chooser.h"
#include "graphical.h"

#ifndef SPECIFIC_H
#define SPECIFIC_H

using namespace std;

namespace Battleships
{
    class Specific : public Chooser
    {
        private:

        Interface *theInterface;

        public:

        Specific(Interface *inputInterface) {theInterface = inputInterface;}
        void choosePosition(Ship& shipToPlace);
        bool getPositionValid(Coordinate* thePosition, unsigned shipLength, bool horizontal);
    };
}
#endif

