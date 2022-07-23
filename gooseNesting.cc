#include "gooseNesting.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GooseNesting::GooseNesting(int position, string blockName) : Tile{blockName, false, false, position, 0} {}

GooseNesting::~GooseNesting() {}

void GooseNesting::action(std::shared_ptr<Player> player) {

}

// std::shared_ptr<TileImpl> GooseNesting::getImpl() {

// }

// std::shared_ptr<Player> GooseNesting::getOwner() {

// }

// void GooseNesting::setOwner(std::shared_ptr<Player> player) {

// }

// int GooseNesting::getImprovement() { // returns the improvement #

// } 

// void GooseNesting::setImprovement(int x) {

// }

// void GooseNesting::mortgage(std::shared_ptr<Player> player) {

// }

// void GooseNesting::auction() {

// }

// bool GooseNesting::isMortgaged() {

// }

// bool GooseNesting::isOwned() {

// }

// int GooseNesting::getPos() {
//     return impl->pos;
// }

// int GooseNesting::getPrice() {

// }

// string GooseNesting::getName() {
//     return impl->name;
// }

// void GooseNesting::improveBuy(std::shared_ptr<Player> player) {

// }

// void GooseNesting::improveSell(std::shared_ptr<Player> player) {
    
// }

// int GooseNesting::getImproveCost() {
    
// }

// std::string GooseNesting::getMonopolyName() {
    
// }

// void GooseNesting::unmortgage(std::shared_ptr<Player> player) {

// }
