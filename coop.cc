#include "coop.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Coop::Coop(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Coop::~Coop() {}

TileImpl Coop::*getImpl() {

}

Board Coop::*getBoard() {

}

Player Coop::*getOwner() {

}

void Coop::setOwner(Player *player) {

}

int Coop::getImprovement() { // returns the improvement #

} 

void Coop::setImprovement(int x) {

}

void Coop::action(shared_ptr<Player> player) {

}

void Coop::mortgage(Player *player) {

}

void Coop::auction() {

}

bool Coop::isMortgaged() {

}

bool Coop::isOwned() {

}

int Coop::getPos() {

}

int Coop::getPrice() {

}

string Coop::getName() {

}
