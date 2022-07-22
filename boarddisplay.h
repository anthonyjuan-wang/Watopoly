#ifndef __BOARD_DISPLAY_H_
#define __BOARD_DISPLAY_H_
#include <memory>
#include <vector>

class Board;
class Tile;
class Player;
class BoardDisplay {
    std::shared_ptr<Board> theBoard;
    void printImprovements(std::shared_ptr<Tile> tile);
    void printPlayers(std::vector<std::shared_ptr<Player>> players, int index);
    public:
        void print();
};

#endif