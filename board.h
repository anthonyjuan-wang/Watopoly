#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
#include <vector>
class Tile;

class Player;
class Board {
    private:
        std::vector<std::shared_ptr<Tile*>>board;
        std::vector<Player*> players;
    
    public:
        Board::Board();
        virtual Board::~Board();
        void loadGame(std::string input);
        void saveGame(std::string input);
        void init(int input);
        void initTiles();
        void play();
        void tradeGive(Player *, std::string, int);
        void tradeReceive(Player *, std::string, int);
        std::vector<int> rollDice(Player *); // maybe virtual
        std::vector<Player*> getPlayers(); // maybe virtual
        void setTestingMode();
};

#endif
