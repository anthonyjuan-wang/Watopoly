#include <string>
#include <vector>
#include "player.h"

#ifndef __BOARD_H__
#define __BOARD_H__

using namespace std;

class Board {
    Board::Board();
    Board::~Board();

    public:
        void loadGame(string input);
        void saveGame(string input);
        void init(int input);
        void play();
        void tradeGive(Player *, string, int);
        void tradeReceive(Player *, string, int);
        vector<int> rollDice(Player *);
        vector<Player*> getPlayers();
        void setTestingMode();
};

#endif

