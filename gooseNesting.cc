#include "gooseNesting.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GooseNesting::GooseNesting(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

GooseNesting::~GooseNesting() {}

TileImpl GooseNesting::*getImpl() {

}

Board GooseNesting::*getBoard() {

}

Player GooseNesting::*getOwner() {

}

void GooseNesting::setOwner(Player *player) {

}

int GooseNesting::getImprovement() { // returns the improvement #

} 

void GooseNesting::setImprovement(int x) {

}

void GooseNesting::action(shared_ptr<Player> player) {

}

void GooseNesting::mortgage(Player *player) {

}

void GooseNesting::auction() {

}

bool GooseNesting::isMortgaged() {

}

bool GooseNesting::isOwned() {

}

int GooseNesting::getPos() {
    return impl->pos;
}

int GooseNesting::getPrice() {

}

string GooseNesting::getName() {
    return impl->name;
}
