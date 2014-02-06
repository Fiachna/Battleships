#include "coordinate.h"
#include <string>

#ifndef SHIP_H
#define SHIP_H

using namespace std;

namespace Battleships
{
    class Ship
    {
        private:

        string name;
        unsigned length;
        unsigned hitCount;

        public:

        void init_Ship(string shipType);
        inline void addHit() {hitCount++;}
        string getShipName() {return name;}
        unsigned getShipLength() {return length;}
        unsigned getHitCount() {return hitCount;}
        bool isSunk();
    };
}
#endif
