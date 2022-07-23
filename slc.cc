#include "slc.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;
Slc::Slc(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

Slc::~Slc() {}

std::shared_ptr<TileImpl> Slc::getImpl() {

}

std::shared_ptr<Player> Slc::getOwner() {

}

void Slc::setOwner(std::shared_ptr<Player> player) {

}

int Slc::getImprovement() { // returns the improvement #

} 

void Slc::setImprovement(int x) {

}

void Slc::action(std::shared_ptr<Player> player) {

}

void Slc::mortgage(std::shared_ptr<Player> player) {

}

void Slc::auction() {

}

bool Slc::isMortgaged() {

}

bool Slc::isOwned() {

}

int Slc::getPos() {
    return impl->pos;
}

int Slc::getPrice() {

}

string Slc::getName() {
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
