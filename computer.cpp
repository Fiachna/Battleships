#include "computer.h"
#include "graphical.h"

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Computer::setCurrentPlayer()
    {
        string details;
        int textPositionX, textPositionY;

        details = "The current player is ";
        details += myName;

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

        textPositionX = (1024 - textwidth(details.c_str())) / 2;
        textPositionY = (124 - textheight(details.c_str())) / 2;

        outtextxy(textPositionX, textPositionY, details.c_str());
    }
//----------------------------------------------------------------------------------------------------------//
}
