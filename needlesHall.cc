#include "needlesHall.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

NeedlesHall::NeedlesHall(int position, string blockName) : Tile{blockName, false, false, position, 0} {}

NeedlesHall::~NeedlesHall() {}

void NeedlesHall::action(std::shared_ptr<Player> player) {

}

// std::shared_ptr<TileImpl> NeedlesHall::getImpl() {

// }

// std::shared_ptr<Player> NeedlesHall::getOwner() {

// }

// void NeedlesHall::setOwner(std::shared_ptr<Player> player) {

// }

// int NeedlesHall::getImprovement() { // returns the improvement #

// } 

// void NeedlesHall::setImprovement(int x) {

// }

// void NeedlesHall::mortgage(std::shared_ptr<Player> player) {

// }

// void NeedlesHall::auction() {

// }

// bool NeedlesHall::isMortgaged() {

// }

// bool NeedlesHall::isOwned() {

// }

// int NeedlesHall::getPos() {
//     return impl->pos;
// }

// int NeedlesHall::getPrice() {

// }

// string NeedlesHall::getName() {
//     return impl->name;
// }

// void NeedlesHall::improveBuy(std::shared_ptr<Player> player) {

// }

// void NeedlesHall::improveSell(std::shared_ptr<Player> player) {
    
// }

// int NeedlesHall::getImproveCost() {
    
// }

// std::string NeedlesHall::getMonopolyName() {
    
// }

// void NeedlesHall::unmortgage(std::shared_ptr<Player> player) {

// }
