#include "tile.h"
#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
class DcTimsLine : Tile
{
private:
    int position;

public:
    DcTimsLine(int position);
    ~DcTimsLine();
};
#endif
