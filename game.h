#include "human.h"
#include "novice.h"
#include "expert.h"
#include <stdlib.h>

using namespace std;

namespace Battleships
{
    class Game
    {
        private:

        vector<Player*> players;
        vector<Player*> losers;
        bool running;

        Chooser* random;
        Chooser* specific;
        Interface* theInterface;
        Coordinate* boardSize;

        public:

        void startup();
        void executeTurn();
        void cleanUp();
        bool getGameRunning() {return running;}
    };
}
