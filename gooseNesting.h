#include "tile.h"
#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
class GooseNesting : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    GooseNesting(int position, string blockName);
    ~GooseNesting();
};

#endif
