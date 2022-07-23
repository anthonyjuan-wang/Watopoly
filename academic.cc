#include "academic.h"
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>

#include "player.h"
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

std::shared_ptr<TileImpl> Academic::getImpl() {
    return impl;
}

std::shared_ptr<Player> Academic::getOwner() {
    return impl->Owner;
}

void Academic::setOwner(std::shared_ptr<Player> player) {
    impl->Owner = player;
}

int Academic::getImprovement() { // returns the improvement #
    return impl->improvement;
}

void Academic::setImprovement(int x) {
    impl->improvement = x;
}

void Academic::action(std::shared_ptr<Player> player) {
    // Check if tile is owned
        // If is owned, Pay Tuition

}

void Academic::mortgage(std::shared_ptr<Player> player) {

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

void Academic::improveBuy(std::shared_ptr<Player> player) {
    int improveNum = getImprovement();
    int price = getPrice();
    setImprovement(improveNum + 1);
    player->subtractMoney(price);
}

void Academic::improveSell(std::shared_ptr<Player> player) {
    int improveNum = getImprovement();
    int price = getPrice();
    setImprovement(improveNum - 1);
    player->addMoney(price/2);
}

int Academic::getImproveCost() {
    return impl->improvement;
}

string Academic::getMonopolyName() {
    return impl->monopoly;
}

void improveBuy(std::shared_ptr<Player> player) {

}

void improveSell(std::shared_ptr<Player> player) {
    
}

int getImproveCost() {
    
}

std::string getMonopolyName() {
    
}

void unmortgage(std::shared_ptr<Player> player) {

}
