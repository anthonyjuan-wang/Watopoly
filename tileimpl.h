#ifndef __TILEIMPL__H__
#define __TILEIMPL__H__
#include <vector>
#include <string>
#include <memory>
// class Board;
class Player;
class Board;
struct TileImpl
{
    Board *theBoard;
    std::shared_ptr<Player> owner;
    std::string name;
    bool ownable;
    bool improvable;
    bool mortgaged;
    int pos;
    int cost;
    //int improvement;
    //std::string monopoly;
    //std::vector<int> tuition;
};

#endif
