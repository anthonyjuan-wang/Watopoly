#ifndef __PLAYERIMPL_H__
#define __PLAYERIMPL_H__
#include <string>
#include <vector>
#include "tile.h"


struct PlayerImpl {
    std::string name;
    char piece;
    int money;
    int pos;
    bool bankrupt;
    bool almostBankrupt;
    int rollUpCount;
    bool isInJail;
    int inJailCounter;
    int moneyOwed;
    std::vector<std::shared_ptr<Tile>> tilesOwned;
};

#endif