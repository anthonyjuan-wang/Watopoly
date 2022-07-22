#include "coop.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Coop::Coop(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

Coop::~Coop() {}

std::shared_ptr<TileImpl> Coop::getImpl() {

}

std::shared_ptr<Player> Coop::getOwner() {

}

void Coop::setOwner(std::shared_ptr<Player> player) {

}

int Coop::getImprovement() { // returns the improvement #

} 

void Coop::setImprovement(int x) {

}

void Coop::action(shared_ptr<Player> player) {

}

void Coop::mortgage(std::shared_ptr<Player> player) {

}

void Coop::auction() {

}

bool Coop::isMortgaged() {

}

bool Coop::isOwned() {

}

int Coop::getPos() {
    return impl->pos;
}

int Coop::getPrice() {

}

string Coop::getName() {
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
