#include "local.h"

#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

namespace Battleships
{
    class Human : public Local
    {
        private:

        Interface* theInterface;

        public:

        Human(Interface* interfaceToUse, Coordinate* sizeOfBoard, string playerName);
        ~Human();

        void setCurrentPlayer();
        void setAttackResult(Attack* theAttack);
        Attack* getAttack();

        string setCurrentTarget();
    };
}
#endif
