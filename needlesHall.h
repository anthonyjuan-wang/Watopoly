#include "tile.h"
#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__

class NeedlesHall : Tile
{
private:
    int pos;

public:
    NeedlesHall(int pos);
    ~NeedlesHall();
};

#endif
