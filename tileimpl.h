#ifndef __TILEIMPL__H__
#define __TILEIMPL__H__
#include <vector>
#include <string>
class Board;
class Player;

struct TileImpl {
    Board *theBoard;
    Player *Owner;
    std::string name;
    bool isOwnable;
    bool isImprovable;
    int pos;
    int purchase;
    int improvement;
    std::string monopoly;
    std::vector<int> tuition;
};

#endif
