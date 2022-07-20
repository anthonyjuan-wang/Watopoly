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

TileImpl Slc::*getImpl() {

}

Board Slc::*getBoard() {

}

Player Slc::*getOwner() {

}

void Slc::setOwner(Player *player) {

}

int Slc::getImprovement() { // returns the improvement #

} 

void Slc::setImprovement(int x) {

}

void Slc::action(shared_ptr<Player> player) {

}

void Slc::mortgage(Player *player) {

}

void Slc::auction() {

}

bool Slc::isMortgaged() {

}

bool Slc::isOwned() {

}

int Slc::getPos() {

}

int Slc::getPrice() {

}

string Slc::getName() {

}
