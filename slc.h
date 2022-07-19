#include "tile.h"
#include <iostream>

#ifndef __SLC_H__
#define __SLC_H__

class Slc : Tile
{
private:
    int position;

public:
    Slc(int position);
    ~Slc();
};

#endif
