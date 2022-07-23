#include "gyms.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Gyms::Gyms(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Gyms::~Gyms() {}

std::shared_ptr<TileImpl> Gyms::getImpl() {

}

std::shared_ptr<Player> Gyms::getOwner() {

}

void Gyms::setOwner(std::shared_ptr<Player> player) {
    impl->Owner = player;
}

int Gyms::getImprovement() { // returns the improvement #

}

void Gyms::setImprovement(int x) {

}

void Gyms::action(std::shared_ptr<Player> player) {

}

void Gyms::mortgage(std::shared_ptr<Player> player) {

}

void Gyms::auction() {

}

bool Gyms::isMortgaged() {

}

bool Gyms::isOwned() {
    return impl->isOwnable;
}

int Gyms::getPos() {
    return impl->pos;
}

int Gyms::getPrice() {
    return impl->purchase;
}

string Gyms::getName() {
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
