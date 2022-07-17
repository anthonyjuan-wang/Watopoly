#include "tile.h"
#include <string>
#include <iostream>
#include <vector>

        // std::string blockName;
        // std::string monopolyType;
        // int purchaseCost;
        // int improvementCost;
        // std::vector <std::vector <int>> tuitionWithExpenses;

using namespace std;
tile::tile(string blockName, string monopolyType, int purchaseCost, int imporvementCost,
            vector<int> tuitionWithExpenses) : blockName{blockName}, monopolyType{monopolyType}, 
            purchaseCost{purchaseCost}, improvementCost{improvementCost}, 
            tuitionWithExpenses{tuitionWithExpenses} {}

tile::~tile() {}
