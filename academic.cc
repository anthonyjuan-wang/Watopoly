#include "academic.h"
#include <string>
#include <iostream>

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int improvementCost,
                   vector<int> tuitionWithExpenses) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
    impl->monopoly = monopolyType;
    impl->purchase = purchaseCost;
    impl->improvement = improvementCost;
    impl->tuition = tuitionWithExpenses;
}

Academic::~Academic() {}