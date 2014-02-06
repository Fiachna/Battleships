#include "ship.h"

#ifndef CELL_H
#define CELL_H

using namespace std;

namespace Battleships
{
    class Cell
    {
        public:

        enum State {UNKNOWN = 0, MISS = 10, HIT = 20};

        Cell();

        void setCellState(State newState);
        inline void setCellOccupant(Ship* theOccupant) {occupant = theOccupant;}
        inline State getCellState() {return state;}
        inline Ship* getOccupant() {return occupant;}

        private:

        State state;
        Ship* occupant;
    };
}
#endif
