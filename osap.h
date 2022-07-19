#include <string>
#include "tile.h"

#ifndef __OSAP_H__
#define __OSAP_H__
class Osap : Tile
{

private:
    int position;

public:
    Osap(int position);
    ~Osap();
};

#endif
