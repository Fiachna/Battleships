#include "game.h"
#include <iostream>

using namespace std;
using namespace Battleships;

int main()
{
    Game* theGame;
    theGame = new Game;
    theGame->startup();
    while(theGame->getGameRunning() == true)
    {
        theGame->executeTurn();
    }
    theGame->cleanUp();
    delete theGame;
}
