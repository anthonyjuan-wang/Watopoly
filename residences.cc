#include "residences.h"
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include "player.h"
#include "board.h"

using namespace std;
Residences::Residences(int position, string blockName) : Tile{blockName, true, false, position, 200} {}

Residences::~Residences() {}

void Residences::action(shared_ptr<Player> player) {

}

// std::shared_ptr<TileImpl> Residences::getImpl() {

// }

// std::shared_ptr<Player> Residences::getOwner() {

// }

// void Residences::setOwner(std::shared_ptr<Player> player) {

// }

// int Residences::getImprovement() { // returns the improvement #

// } 

// void Residences::setImprovement(int x) {

// }

// void Residences::mortgage(std::shared_ptr<Player> player) {

// }

// void Residences::auction() {

// }

// bool Residences::isMortgaged() {

// }

// bool Residences::isOwned() {
//     return impl->isOwnable;
// }

// int Residences::getPos() {
//     return impl->pos;
// }

// int Residences::getPrice() {
//     return impl->purchase;
// }

// string Residences::getName() {
//     return impl->name;
// }

// void Residences::improveBuy(std::shared_ptr<Player> player) {

// }

// void Residences::improveSell(std::shared_ptr<Player> player) {
    
// }

// int Residences::getImproveCost() {
    
// }

// std::string Residences::getMonopolyName() {
    
// }

// void Residences::unmortgage(std::shared_ptr<Player> player) {

// }
