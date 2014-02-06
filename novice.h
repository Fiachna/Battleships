#include "computer.h"

#ifndef NOVICE_H
#define NOVICE_H

using namespace std;

namespace Battleships
{
    class Novice : public Computer
    {
        public:

        Novice(Coordinate* sizeOfBoard, string playerName);
        ~Novice();
        Attack* getAttack();
        void setAttackResult(Attack* theAttack);
    };
}
#endif
