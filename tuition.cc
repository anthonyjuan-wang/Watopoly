#include "tuition.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Tuition::Tuition(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

Tuition::~Tuition() {}

std::shared_ptr<TileImpl> Tuition::getImpl() {

}

std::shared_ptr<Player> Tuition::getOwner() {

}

void Tuition::setOwner(std::shared_ptr<Player> player) {

}

int Tuition::getImprovement() { // returns the improvement #

} 

void Tuition::setImprovement(int x) {

}

void Tuition::action(std::shared_ptr<Player> player) {

}

void Tuition::mortgage(std::shared_ptr<Player> player) {

}

void Tuition::auction() {

}

bool Tuition::isMortgaged() {

}

bool Tuition::isOwned() {

}

int Tuition::getPos() {
    return impl->pos;
}

int Tuition::getPrice() {

}

string Tuition::getName() {
    return impl->name;
}

void Tuition::improveBuy(std::shared_ptr<Player> player) {

}

void Tuition::improveSell(std::shared_ptr<Player> player) {
    
}

int Tuition::getImproveCost() {
    
}

std::string Tuition::getMonopolyName() {
    
}

void Tuition::unmortgage(std::shared_ptr<Player> player) {

}
