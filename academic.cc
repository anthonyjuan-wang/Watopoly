#include "academic.h"
#include <string>
#include <iostream>

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int imporvementCost,
                   vector<int> tuitionWithExpenses) : position{position}, blockName{blockName}, monopolyType{monopolyType},
                                                      purchaseCost{purchaseCost}, improvementCost{improvementCost},
                                                      tuitionWithExpenses{tuitionWithExpenses} {}

Academic::~Academic() {}