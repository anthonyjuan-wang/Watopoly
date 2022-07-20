#include "goToTims.h"
#include "tile.h"
#include <string>
class Player;
class Board;

using namespace std;

GoToTims::GoToTims(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

GoToTims::~GoToTims() {}

TileImpl GoToTims::*getImpl() {

}

Board GoToTims::*getBoard() {

}

Player GoToTims::*getOwner() {

}

void GoToTims::setOwner(Player *player) {

}

int GoToTims::getImprovement() { // returns the improvement #

} 

void GoToTims::setImprovement(int x) {

}

void GoToTims::action(shared_ptr<Player> player) {

}

void GoToTims::mortgage(Player *player) {

}

void GoToTims::auction() {

}

bool GoToTims::isMortgaged() {

}

bool GoToTims::isOwned() {

}

int GoToTims::getPos() {

}

int GoToTims::getPrice() {

}

string GoToTims::getName() {

}
