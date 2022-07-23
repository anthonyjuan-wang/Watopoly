#include "dcTimsLine.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

DcTimsLine::DcTimsLine(int position, string blockName) : impl{make_shared<TileImpl>()} {
    impl->pos = position;
    impl->name = blockName;
}

DcTimsLine::~DcTimsLine() {}

// std::shared_ptr<TileImpl> DcTimsLine::getImpl() {

// }

std::shared_ptr<Player> DcTimsLine::getOwner() {

}

void DcTimsLine::setOwner(shared_ptr<Player> player) {

}

int DcTimsLine::getImprovement() { // returns the improvement #

} 

void DcTimsLine::setImprovement(int x) {

}

void DcTimsLine::action(shared_ptr<Player> player) {

}

void DcTimsLine::mortgage(shared_ptr<Player> player) {

}

void DcTimsLine::auction() {

}

bool DcTimsLine::isMortgaged() {

}

bool DcTimsLine::isOwned() {

}

int DcTimsLine::getPos() {
    return impl->pos;
}

int DcTimsLine::getPrice() {

}

string DcTimsLine::getName() {
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
