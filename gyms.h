#include "tile.h"
#ifndef __GYMS_H__
#define __GYMS_H__

class Gyms : Tile
{
private:
    int position;
    std::string blockName;

public:
    Gyms(int position, std::string blockName);
    ~Gyms();
};

#endif
