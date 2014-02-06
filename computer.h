#include "local.h"

#ifndef COMPUTER_H
#define COMPUTER_H

using namespace std;

namespace Battleships
{
    class Computer : public Local
    {
        public:

        void setCurrentPlayer();
    };
}
#endif
