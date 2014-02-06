#include "computer.h"

#ifndef EXPERT_H
#define EXPERT_H

using namespace std;

namespace Battleships
{
    class Expert : public Computer
    {
        private:

        Attack* lastSuccess;
        enum Alignment {NONE = 0, VERTICAL = 1, HORIZONTAL = 2, BOTH = 3};

        public:

        Expert(Coordinate* sizeOfBoard, string playerName);
        ~Expert();
        Attack* getAttack();
        void setAttackResult(Attack* theAttack);

        Attack* randomAttack();
        Alignment getAttackOrientation();
        bool getLocationValid(unsigned row, unsigned column, Board* theBoard);
        vector<Coordinate>* getPotentialTargets();


    };
}
#endif

