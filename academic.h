#include <iostream>
#include <string>
#include "tile.h"

#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__

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
