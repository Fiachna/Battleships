#include "graphics.h"
#include "interface.h"

#ifndef GRAPHICAL_H
#define GRAPHICAL_H

using namespace std;

namespace Battleships
{
    class Graphical : public Interface
    {
        private:

        int window;

        public:

        void init_Interface();
        void uninit_Interface();
        void showMyBoard(Board boardToShow);
        void showOpponentBoard(Board boardToShow);
        void showFleet(Board boardWithFleet);
        Coordinate* getCoordinate(Board currentBoard, unsigned boardOffsetX);
    };
}
#endif
