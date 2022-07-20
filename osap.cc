#include "osap.h"
#include "tile.h"
#include <string>
#include <memory>
#include "player.h"
class Board;

using namespace std;

Osap::Osap(int position, std::string str) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = str;
}

void Osap::action()
{
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    impl->Owner->addMoney(200);
}

TileImpl Osap::*getImpl() {

}

Board Osap::*getBoard() {

}

Player Osap::*getOwner() {

}

void Osap::setOwner(Player *player) {

}

int Osap::getImprovement() { // returns the improvement #

} 

void Osap::setImprovement(int x) {

}

void Osap::action(shared_ptr<Player> player) {

}

void Osap::mortgage(Player *player) {

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
