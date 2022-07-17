#include <string>
#include <iostream>
#include "board.h"
#include <vector>

#ifndef __TILE_H__
#define __TILE_H__

class tile : Board {
    private:
        std::string blockName;
        std::string monopolyType;
        int purchaseCost;
        int improvementCost;
        std::vector<int> tuitionWithExpenses;
        
    public:
        tile(std::string blockName, std::string monopolyType, int purchaseCost, int imporvementCost,
           std::vector <int> tuitionWithExpenses);
        ~tile();
};

#endif
