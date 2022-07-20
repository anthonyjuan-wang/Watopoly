#ifndef __COOP_H__
#define __COOP_H__
#include "tile.h"
#include <string>

class Coop : public Tile
{

    std::shared_ptr<TileImpl> impl;

public:
    Coop(int position, std::string blockName);
    ~Coop();
};

#endif
