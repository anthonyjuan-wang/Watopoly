#include "academic.h"
#include <string>
#include <iostream>

using namespace std;

Academic::Academic(string blockName, string monopolyType, int purchaseCost, int imporvementCost,
            vector<int> tuitionWithExpenses) : blockName{blockName}, monopolyType{monopolyType}, 
            purchaseCost{purchaseCost}, improvementCost{improvementCost}, 
            tuitionWithExpenses{tuitionWithExpenses} {
    
}

Academic::~Academic() {}