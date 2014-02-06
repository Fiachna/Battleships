#include "game.h"
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Game::startup()
    {
        unsigned input, numPlayers, numComputer, numExpert;
        unsigned i, j;
        string playerName;
        stringstream playerNameNumber;
        Player* newPlayer;
        Player* opponent;

        srand(time(NULL));
        theInterface = new Graphical;

        cout << "Welcome to Battleships!" << endl << "Please enter a number of players between 2 and 4" << endl;
        cin >> input;
        cin.ignore();
        while(input < 2 || input > 4)
        {
            cout << "invalid number, please enter a number between 2 and 4" << endl;
            cin >> input;
            cin.ignore();
        }
        numPlayers = input;

        cout << "How many human players will there be?" << endl;
        cin >> input;
        cin.ignore();
        while(input > numPlayers)
        {
            cout << "invalid number, please enter a number between 0 and " << numPlayers << endl;
            cin >> input;
            cin.ignore();
        }
        numComputer = numPlayers - input;

        if(numComputer > 0)
        {
            cout << "How many Expert computer players do you wish to play against?" << endl;
            cin >> input;
            cin.ignore();
            while(input > numComputer)
            {
                cout << "invalid number, please enter a number between 0 and " << numComputer << endl;
                cin >> input;
                cin.ignore();
            }
            numExpert = input;
        }
        else
        {
            numExpert = 0;
        }

        cout << "How large will the board be? between 10 and 20 cells" << endl;
        cin >> input;
        cin.ignore();
        while(input < 10 || input > 20)
        {
            cout << "invalid number, please enter a number between 10 and 20" << endl;
            cin >> input;
            cin.ignore();
        }

        boardSize = new Coordinate;
        boardSize->init_SpecificCoordinate(input, input);

        for(i=1; i<=numPlayers; i++)
        {
            cout << i << endl;
            if(i <= (numComputer))
            {
                if(i <= (numExpert))
                {
                    playerNameNumber.clear();
                    playerNameNumber << "Computer" << i << "(Expert)";
                    playerNameNumber >> playerName;
                    newPlayer = new Expert(boardSize, playerName);
                }
                else
                {
                    playerNameNumber.clear();
                    playerNameNumber << "Computer" << i << "(Novice)";
                    playerNameNumber >> playerName;
                    newPlayer = new Novice(boardSize, playerName);
                }
            }
            else
            {
                cout << "Please enter a player name" << endl;
                cin >> playerName;
                newPlayer = new Human(theInterface, boardSize, playerName);
            }
            players.push_back(newPlayer);
        }
        theInterface->init_Interface();

        for(i=0; i<numPlayers; i++)
        {
            newPlayer = players[i];
            newPlayer->setupFleet();
            for(j=0; j<numPlayers; j++)
            {
                opponent = players[j];
                if(newPlayer != opponent)
                {
                    newPlayer->addOpponent(opponent);
                }
            }
        }

        running = true;
    }
//----------------------------------------------------------------------------------------------------------//
    void Game::executeTurn()
    {
        unsigned i, j, k;
        string winMessage;
        int textPositionX, textPositionY;
        string loserName, playerName, processorName;
        Attack* theAttack;
        Player* thePlayer;
        Player* theLoser;
        Player* theProcessor;
        bool skip;

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

        textPositionY = 700;
        textPositionX = (1024 - textwidth("Use left arrow key to select target opponent")) / 2;
        outtextxy(textPositionX, textPositionY, "Use left arrow key to select target opponent");

        for(i=0; i<players.size(); i++)
        {
            skip = false;

            thePlayer = players[i];
            playerName = thePlayer->getName();
            for(j=0; j<losers.size(); j++)
            {
                theLoser = losers[j];
                loserName = theLoser->getName();
                if(loserName.compare(playerName) == 0)
                {
                    skip = true;
                }
            }
            if(skip == false)
            {
                thePlayer->setCurrentPlayer();
                theAttack = thePlayer->getAttack();
                for(k=0; k<players.size(); k++)
                {
                    theProcessor = players[k];
                    processorName = theProcessor->getName();
                    theProcessor->processAttack(theAttack);
                    if(theAttack->getFleetDestroyed() == true && processorName.compare(theAttack->getTargetName()) == 0)
                    {
                        losers.push_back(theProcessor);
                    }
                }
                thePlayer->setAttackResult(theAttack);
            }
            if(losers.size() == (players.size() - 1))
            {
                cleardevice();
                running = false;
                for(j=0; j<players.size(); j++)
                {
                    thePlayer = players[j];
                    for(k=0; k<losers.size(); k++)
                    {
                        theLoser = losers[k];
                        loserName = theLoser->getName();
                        if(loserName.compare(thePlayer->getName()) == 0)
                        {

                        }
                        else
                        {
                            playerName = thePlayer->getName();
                        }
                    }
                }
                winMessage = "The Winner is ";
                winMessage += playerName;

                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);

                textPositionX = (1024 - textwidth(winMessage.c_str())) / 2;
                textPositionY = (768 - textheight(winMessage.c_str())) / 2;

                outtextxy(textPositionX, textPositionY, winMessage.c_str());
                delay(2000); //5 second delay before closing game
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
    void Game::cleanUp()
    {
        unsigned i;

        for(i=0; i<losers.size(); i++)
        {
            losers[i] = NULL;
        }

        losers.clear();
        players.clear();
        delete random;
        delete specific;
        theInterface->uninit_Interface();
        delete theInterface;
        delete boardSize;
    }
//----------------------------------------------------------------------------------------------------------//
}
