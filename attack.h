#include "coordinate.h"
#include "cell.h"
#include <string>

#ifndef ATTACK_H
#define ATTACK_H

using namespace std;

namespace Battleships
{
    class Attack
    {
        private:

        string targetName;
        Coordinate *targetCoordinate;
        Cell::State result;
        bool fleetDestroyed;

        public:

        inline void init_Attack(string theTarget, Coordinate *theAttack) {targetName = theTarget, targetCoordinate = theAttack, fleetDestroyed = false;}
        inline void uninit_Attack() {delete targetCoordinate;}
        inline void setResult(Cell::State theResult) {result = theResult;}
        inline void setFleetDestroyed(bool isDestroyed) {fleetDestroyed = isDestroyed;}
        inline bool getFleetDestroyed() {return fleetDestroyed;}
        inline Cell::State getResult() {return result;}
        inline Coordinate* getTargetCoordinate() {return targetCoordinate;}
        inline string getTargetName() {return targetName;}
    };
}
#endif
