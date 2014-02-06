#include "attack.h"
#include "coordinate.h"

#include "board.h"

#include <string>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

namespace Battleships
{
    class Player
    {
        protected:

        string myName;
        Coordinate* boardSize;

        public:

        inline void init_Player(string playerName, Coordinate* sizeOfBoard) {myName = playerName, boardSize = sizeOfBoard;}
        inline string getName() {return myName;}
        inline Coordinate* getBoardSize() {return boardSize;}

        virtual void addOpponent(Player* theOpponent)=0;
        virtual void setCurrentPlayer()=0;
        virtual void processAttack(Attack* theAttack)=0;
        virtual void setAttackResult(Attack* theAttack)=0;
        virtual void setupFleet()=0;
        virtual Attack* getAttack()=0;
        virtual Board* getBoard()=0;
    };
}
#endif
