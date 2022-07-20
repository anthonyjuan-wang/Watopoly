#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <iostream>
#include <string>
#include "tile.h"

class Tile;
class Academic : public Tile
{

    std::shared_ptr<TileImpl> impl;

public:
    Academic(int position, std::string blockName, std::string monopolyType, int purchaseCost, int improvementCost,
             std::vector<int> tuitionWithExpenses);
    ~Academic();
};

#endif
