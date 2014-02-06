#include "board.h"

#ifndef CHOOSER_H
#define CHOOSER_H

using namespace std;

namespace Battleships
{
    class Chooser
    {
        protected:

        Board* theBoard;

        public:

        inline void setBoard(Board* boardToUse) {theBoard = boardToUse;}
        void init_Fleet(vector<Ship>& theFleet);
        virtual void choosePosition(Ship& shipToPlace);
    };
}
#endif
