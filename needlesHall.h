#include "tile.h"
#include <string>
#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__

class NeedlesHall : public Tile
{

    std::shared_ptr<TileImpl> impl;

public:
    NeedlesHall(int position, std::string blockName);
    ~NeedlesHall();
};

#endif
