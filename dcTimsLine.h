#include "tile.h"
#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
class DcTimsLine : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    DcTimsLine(int position, string blockName);
    ~DcTimsLine();
};
#endif
