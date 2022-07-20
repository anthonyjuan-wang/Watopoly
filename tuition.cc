#include "tuition.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

Tuition::Tuition(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Tuition::~Tuition() {}

TileImpl Tuition::*getImpl() {

}

Board Tuition::*getBoard() {

}

Player Tuition::*getOwner() {

}

void Tuition::setOwner(Player *player) {

}

int Tuition::getImprovement() { // returns the improvement #

} 

void Tuition::setImprovement(int x) {

}

void Tuition::action(shared_ptr<Player> player) {

}

void Tuition::mortgage(Player *player) {

}

void Tuition::auction() {

}

bool Tuition::isMortgaged() {

}

bool Tuition::isOwned() {

}

int Tuition::getPos() {

}

int Tuition::getPrice() {

}

string Tuition::getName() {

}
