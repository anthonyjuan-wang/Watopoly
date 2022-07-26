#ifndef __BOARD_DISPLAY_H__
#define __BOARD_DISPLAY_H__
#include <memory>
#include <vector>

class Board;
class Tile;
class Player;
class BoardDisplay {
    Board* theBoard;
    std::vector<std::vector<char>> theDisplay;
    void printImprovements(std::shared_ptr<Tile> tile);
    void printPlayers(std::vector<std::shared_ptr<Player>> players, int index);
    public:
        void print();  
        void update();
        BoardDisplay(Board* b);
};

#endif
