#include "academic.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int improvementCost,
                   vector<int> tuitionWithExpenses) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
    impl->monopoly = monopolyType;
    impl->purchase = purchaseCost;
    impl->improvement = improvementCost;
    impl->tuition = tuitionWithExpenses;
}

Academic::~Academic() {}

TileImpl Academic::*getImpl() {

}

Board Academic::*getBoard() {

}

Player Academic::*getOwner() {
    
}

void Academic::setOwner(Player *player) {
    impl->Owner = player;
}

int Academic::getImprovement() { // returns the improvement #
    return impl->improvement;
}

void Academic::setImprovement(int x) {
    impl->improvement = x;
}

void Academic::action(shared_ptr<Player> player) {
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

void Academic::mortgage(Player *player) {

}

void Academic::auction() {

}

bool Academic::isMortgaged() {

}

bool Academic::isOwned() {
    return impl->isOwnable;
}

int Academic::getPos() {
    return impl->pos;
}

int Academic::getPrice() {
    return impl->purchase;
}

string Academic::getName() {
    return impl->name;
}
