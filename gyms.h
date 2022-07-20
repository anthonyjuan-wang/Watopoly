#ifndef __GYMS_H__
#define __GYMS_H__
#include "tile.h"
#include <string>
class Gyms : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    Gyms(int position, std::string blockName);
    ~Gyms();
};

#endif
