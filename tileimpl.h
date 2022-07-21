#ifndef __TILEIMPL__H__
#define __TILEIMPL__H__
#include <vector>
#include <string>

class Board;
class Player;


class TileImpl {
    public:

}

// Make this into a class ... 
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
    class Private;
    Private *TilepImpl;
};

#endif
