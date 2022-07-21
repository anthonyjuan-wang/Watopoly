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

void Academic::action(std::shared_ptr<Player> player) {
    /*
    if (isOwned() == true) {
                // get price and make player pay
    } else {
                cout << "Would you like to purchase this building? Enter 'yes' or 'no'." << endl;
                string s;
                cin >> s;

                
            }
            break;
    */
}