#include <string>
#include <memory>
#include "osap.h"
#include "tile.h"
#include "tileimpl.h"
#include "player.h"
#include "board.h"

using namespace std;

Osap::Osap(int position, string str) : impl{make_shared<TileImpl>()} {
    // Tile{position, str};
    // TileImpl impl = getImpl();
    impl->pos = position;
    impl->name = str;

    // impl->isOwnable = false;
    // impl->isImprovable = false;
    // impl->purchase = 0;
    // impl->improvement;
    // impl->monopoly = {};
    //std::vector<int> tuition;
}

void Osap::action(std::shared_ptr<Player> player) {
    
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    getImpl()->Owner->addMoney(200);
}

// std::shared_ptr<TileImpl> Osap::getImpl() {

// }

std::shared_ptr<Player> Osap::getOwner() {

}

void Osap::setOwner(std::shared_ptr<Player> player) {

}

int Osap::getImprovement() {

} 

void Osap::setImprovement(int x) {

}

void Osap::action(std::shared_ptr<Player> player) {

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
