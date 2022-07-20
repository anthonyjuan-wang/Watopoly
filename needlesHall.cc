#include "needlesHall.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

NeedlesHall::NeedlesHall(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

NeedlesHall::~NeedlesHall() {}

TileImpl NeedlesHall::*getImpl() {

}

Board NeedlesHall::*getBoard() {

}

Player NeedlesHall::*getOwner() {

}

void NeedlesHall::setOwner(Player *player) {

}

int NeedlesHall::getImprovement() { // returns the improvement #

} 

void NeedlesHall::setImprovement(int x) {

}

void NeedlesHall::action(shared_ptr<Player> player) {

}

void NeedlesHall::mortgage(Player *player) {

}

void NeedlesHall::auction() {

}

bool NeedlesHall::isMortgaged() {

}

bool NeedlesHall::isOwned() {

}

int NeedlesHall::getPos() {

}

int NeedlesHall::getPrice() {

}

string NeedlesHall::getName() {

}
