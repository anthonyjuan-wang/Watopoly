#include "tile.h"
#ifndef __COOP_H__
#define __COOP_H__

class Coop : Tile
{
private:
    int position;

public:
    Coop(int position);
    ~Coop();
};

#endif
