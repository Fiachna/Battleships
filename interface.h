#include "board.h"
#include "coordinate.h"

#ifndef INTERFACE_H
#define INTERFACE_H

using namespace std;

namespace Battleships
{
    class Interface
    {
        public:

        virtual void init_Interface();
        virtual void uninit_Interface();
        virtual void showMyBoard(Board boardToShow);
        virtual void showOpponentBoard(Board boardToShow);
        virtual void showFleet(Board boardWithFleet);
        virtual Coordinate* getCoordinate(Board currentBoard, unsigned boardOffsetX);
    };
}
#endif
