#include "academic.h"
#include <string>
#include <iostream>

using namespace std;

Academic::Academic(string monopolyType, int purchaseCost, int improvementCost,
           vector <int> tuitionWithExpenses) : monopolyType{monopolyType}, purchaseCost{purchaseCost}, 
           improvementCost{improvementCost}, tuitionWithExpenses{tuitionWithExpenses} {}

Academic::~Academic();