#ifndef __BOARD_DISPLAY_H__
#define __BOARD_DISPLAY_H__
#include <memory>
#include <vector>

class Board;
class Tile;
class Player;
class BoardDisplay {
    std::shared_ptr<Board> theBoard;
    
    public:
        void print();  
        BoardDisplay(std::shared_ptr<Board> theBoard);
};

#endif
