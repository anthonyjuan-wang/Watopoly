#ifndef __TILEIMPL__H__
#define __TILEIMPL__H__
#include <vector>
#include <string>
#include <memory>
#include "board.h"
class Tile;
class Player;
//class Board;

struct TileImpl {
    std::shared_ptr<Board> theBoard;
    std::shared_ptr<Player> owner;
    std::string name;
    bool ownable;
    bool improvable;
    bool mortgaged;
    int pos;
    int purchase;
    //int improvement;
    //std::string monopoly;
    //std::vector<int> tuition;
};

#endif
