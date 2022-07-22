#include "osap.h"
#include "tile.h"
#include <string>
#include <memory>
#include "player.h"
class Board;

using namespace std;

Osap::Osap(int position, std::string str) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = str;
}

void Osap::action() {
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    impl->Owner->addMoney(200);
}

std::shared_ptr<TileImpl> Osap::getImpl() {

}

std::shared_ptr<Player> Osap::getOwner() {

}

void Osap::setOwner(std::shared_ptr<Player> player) {

}

int Osap::getImprovement() { // returns the improvement #

} 

void Osap::setImprovement(int x) {

}

void Osap::action(shared_ptr<Player> player) {

}

void Osap::mortgage(std::shared_ptr<Player> player) {

}

void Osap::auction() {

}

bool Osap::isMortgaged() {

}

bool Osap::isOwned() {

}

int Osap::getPos() {
    return impl->pos;
}

int Osap::getPrice() {

}

string Osap::getName() {
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
