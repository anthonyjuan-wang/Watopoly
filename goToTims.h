#include "tile.h"
#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__

class GoToTims : Tile
{
private:
    int position;

public:
    GoToTims(int position);
    ~GoToTims();
};

#endif
