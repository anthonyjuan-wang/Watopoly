#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
#include <vector>
#include <sstream>
class tile;

class Player;
class Board {
    private:
        std::vector<tile> board;
        std::vector<std::shared_ptr<Player*>> players;
    
    public:
        Board::Board();
        virtual Board::~Board();
        void loadGame(std::string input);
        void saveGame(std::string input);
        void init(int input);
        void play();
        void tradeGive(Player *p, std::string s, int n);
        void tradeReceive(Player *p, std::string s, int n);
        std::vector<int> rollDice(); // maybe virtual
        std::vecto<Player*> getPlayers(); // maybe virtual
        void setTestingMode();
};

#endif
