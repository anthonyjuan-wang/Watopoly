#include "goToTims.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GoToTims::GoToTims(int position, string blockName) : Tile{blockName, false, false, position, 0} {}

GoToTims::~GoToTims() {}

void GoToTims::action(std::shared_ptr<Player> player) {

}

// std::shared_ptr<TileImpl> GoToTims::getImpl() {

// }

<<<<<<< HEAD
void GoToTims::setOwner(std::shared_ptr<Player> player) {
=======
// std::shared_ptr<Player> GoToTims::getOwner() {
>>>>>>> main

// }

// void GoToTims::setOwner(std::shared_ptr<Player> player) {

// }

// int GoToTims::getImprovement() { // returns the improvement #

// } 

// void GoToTims::setImprovement(int x) {

// }

// void GoToTims::mortgage(std::shared_ptr<Player> player) {

// }

// void GoToTims::auction() {

// }

// bool GoToTims::isMortgaged() {

// }

// bool GoToTims::isOwned() {

// }

// int GoToTims::getPos() {
//     return impl->pos;
// }

// int GoToTims::getPrice() {

// }

// string GoToTims::getName() {
//     return impl->name;
// }

// void GoToTims::improveBuy(std::shared_ptr<Player> player) {

// }

// void GoToTims::improveSell(std::shared_ptr<Player> player) {
    
// }

// int GoToTims::getImproveCost() {
    
// }

// std::string GoToTims::getMonopolyName() {
    
// }

// void GoToTims::unmortgage(std::shared_ptr<Player> player) {

// }
