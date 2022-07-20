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

}

int Academic::getImprovement() { // returns the improvement #

} 

void Academic::setImprovement(int x) {

}

void Academic::action(shared_ptr<Player> player) {

}

void Academic::mortgage(Player *player) {

}

void Academic::auction() {

}

bool Academic::isMortgaged() {

}

bool Academic::isOwned() {

}

int Academic::getPos() {

}

int Academic::getPrice() {

}

string Academic::getName() {

}
