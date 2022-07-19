#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <iostream>
#include <string>
#include "tile.h"

class Tile;
class Academic : Tile {
    std::string blockName;
    std::string monopolyType;
    int purchaseCost;
    int improvementCost;
    std::vector<int> tuitionWithExpenses;

    public:
        Academic(std::string blockName, std::string monopolyType, int purchaseCost, int imporvementCost,
           std::vector <int> tuitionWithExpenses);
        ~Academic();
};

#endif
