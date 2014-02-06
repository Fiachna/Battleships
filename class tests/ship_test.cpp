#include "ship.h"
#include <iostream>

using namespace std;
using namespace Battleships;

int main()
{
    unsigned hitTest, length, i;
    string name;

    Ship* Carrier;
    Ship* Battleship;
    Ship* Destroyer;
    Ship* Frigate;
    cout << "creating some ships, will dump results" << endl;

    Carrier = new Ship;
    Carrier->init_Ship("Carrier");

    hitTest = Carrier->getHitCount();
    length = Carrier->getShipLength();
    name = Carrier->getShipName();

    cout << "initial parameters for " << name << ". " << hitTest << " hits, " << length << " long" << endl;

    delete Carrier;

    Battleship = new Ship;
    Battleship->init_Ship("Battleship");

    hitTest = Battleship->getHitCount();
    length = Battleship->getShipLength();
    name = Battleship->getShipName();

    cout << "initial parameters for " << name << ". " << hitTest << " hits, " << length << " long" << endl;

    delete Battleship;

    Destroyer = new Ship;
    Destroyer->init_Ship("Destroyer");

    hitTest = Destroyer->getHitCount();
    length = Destroyer->getShipLength();
    name = Destroyer->getShipName();

    cout << "initial parameters for " << name << ". " << hitTest << " hits, " << length << " long" << endl;

    delete Destroyer;

    Frigate = new Ship;
    Frigate->init_Ship("Frigate");

    hitTest = Frigate->getHitCount();
    length = Frigate->getShipLength();
    name = Frigate->getShipName();

    cout << "initial parameters for " << name << ". " << hitTest << " hits, " << length << " long" << endl;

    cout << "sinking frigate" << endl;

    for(i=0; i<length; i++)
    {
        Frigate->addHit();
        hitTest = Frigate->getHitCount();
        cout << hitTest << " hits so far" << endl;
    }
    if(Frigate->isSunk())
    {
        cout << "isSunk is working correctly" << endl;
    }

    cin.get();

}
