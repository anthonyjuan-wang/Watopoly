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
    std::vector<std::shared_ptr<Tile>> boardTiles;
    std::string name;
    bool ownable;
    bool residence;
    bool gym;
    bool improvable;
    bool mortgaged;
    int pos;
    int purchase;
    //int improvement;
    //std::string monopoly;
    //std::vector<int> tuition;
};

#endif
