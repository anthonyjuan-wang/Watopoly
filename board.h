#include <string>
#include <vector>

#ifndef __BOARD_H__
#define __BOARD_H__
class tile;

class Player;
class Board {
    private:
        std::vector<tile> board;
        std::vector<Player*> players;
    
    public:
        Board::Board();
        virtual Board::~Board();
        void loadGame(std::string input);
        void saveGame(std::string input);
        void init(int input);
        void play();
        void tradeGive(Player *, std::string, int);
        void tradeReceive(Player *, std::string, int);
        std::vector<int> rollDice(Player *); // maybe virtual
        std::vector<Player*> getPlayers(); // maybe virtual
        void setTestingMode();
};

#endif
