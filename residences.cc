#include "residences.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;
Residences::Residences(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

Residences::~Residences() {}

std::shared_ptr<TileImpl> Residences::getImpl() {

}

std::shared_ptr<Player> Residences::getOwner() {

}

void Residences::setOwner(std::shared_ptr<Player> player) {

}

int Residences::getImprovement() { // returns the improvement #

} 

void Residences::setImprovement(int x) {

}

void Residences::action(shared_ptr<Player> player) {

}

void Residences::mortgage(std::shared_ptr<Player> player) {

}

void Residences::auction() {

}

bool Residences::isMortgaged() {

}

bool Residences::isOwned() {
    return impl->isOwnable;
}

int Residences::getPos() {
    return impl->pos;
}

int Residences::getPrice() {
    return impl->purchase;
}

string Residences::getName() {
    return impl->name;
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
