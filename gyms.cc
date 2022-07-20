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

TileImpl Gyms::*getImpl() {

}

Board Gyms::*getBoard() {

}

Player Gyms::*getOwner() {

}

void Gyms::setOwner(Player *player) {

}

int Gyms::getImprovement() { // returns the improvement #

} 

void Gyms::setImprovement(int x) {

}

void Gyms::action(shared_ptr<Player> player) {

}

void Gyms::mortgage(Player *player) {

}

void Gyms::auction() {

}

bool Gyms::isMortgaged() {

}

bool Gyms::isOwned() {

}

int Gyms::getPos() {

}

int Gyms::getPrice() {

}

string Gyms::getName() {

}
