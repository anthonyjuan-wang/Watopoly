#include "tile.h"
#include <string>
#include <vector>

#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__

class Academic : Tile {
    private:
        std::string monopolyType;
        int purchaseCost;
        int improvementCost;
        std::vector<int> tuitionWithExpenses;

    public: 
    Academic(std::string monopolyType, int purchaseCost, int improvementCost,
           std::vector <int> tuitionWithExpenses);
    ~Academic();

};

#endif
