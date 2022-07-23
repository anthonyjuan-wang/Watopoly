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

// std::shared_ptr<TileImpl> GoToTims::getImpl() {

// }

std::shared_ptr<Player> GoToTims::getOwner() {

}

void GoToTims::setOwner(std::shared_ptr<Player> player) {

}

int GoToTims::getImprovement() { // returns the improvement #

} 

void GoToTims::setImprovement(int x) {

}

void GoToTims::action(std::shared_ptr<Player> player) {

}

void GoToTims::mortgage(std::shared_ptr<Player> player) {

}

void GoToTims::auction() {

}

bool GoToTims::isMortgaged() {

}

bool GoToTims::isOwned() {

}

int GoToTims::getPos() {
    return impl->pos;
}

int GoToTims::getPrice() {

}

string GoToTims::getName() {
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
