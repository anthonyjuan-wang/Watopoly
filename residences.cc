#include "residences.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;
Residences::Residences(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Residences::~Residences() {}

TileImpl Residences::*getImpl() {

}

Board Residences::*getBoard() {

}

Player Residences::*getOwner() {

}

void Residences::setOwner(Player *player) {

}

int Residences::getImprovement() { // returns the improvement #

} 

void Residences::setImprovement(int x) {

}

void Residences::action(shared_ptr<Player> player) {

}

void Residences::mortgage(Player *player) {

}

void Residences::auction() {

}

bool Residences::isMortgaged() {

}

bool Residences::isOwned() {

}

int Residences::getPos() {

}

int Residences::getPrice() {

}

string Residences::getName() {

}
