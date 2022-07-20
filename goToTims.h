#include "tile.h"
#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__

class GoToTims : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    GoToTims(int position, string blockName);
    ~GoToTims();
};

#endif
