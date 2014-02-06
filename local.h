#include "player.h"
#include "board.h"
#include "random.h"
#include "specific.h"
#include <vector>
#include <map>

#ifndef LOCAL_H
#define LOCAL_H

using namespace std;

namespace Battleships
{
    class Local : public Player
    {
        protected:

        Board* myBoard;
        map<string, Board> opponents;
        vector<Ship> myFleet;
        Chooser* setupType;

        public:

        void init_Local(Chooser* theMethod, Coordinate* sizeOfBoard, string playerName);
        void uninit_Local();
        void addOpponent(Player* theOpponent);
        void processAttack(Attack* theAttack);
        void setupFleet();

        Board* getBoard() {return myBoard;}
    };
}
#endif
