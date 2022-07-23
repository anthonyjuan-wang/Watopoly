#include <string>
#include <memory>
#include "osap.h"
#include "tile.h"
#include "tileimpl.h"
#include "player.h"
#include "board.h"

using namespace std;

Osap::Osap(int position, string blockName) : Tile{blockName, false, false, position, 0} {}

Osap::~Osap() {}

void Osap::action(std::shared_ptr<Player> player) {
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    getOwner()->addMoney(200);
}

// std::shared_ptr<TileImpl> Osap::getImpl() {

// }

// std::shared_ptr<Player> Osap::getOwner() {

// }

// void Osap::setOwner(std::shared_ptr<Player> player) {

// }

// int Osap::getImprovement() {

// } 

// void Osap::setImprovement(int x) {

// }

// void Osap::mortgage(std::shared_ptr<Player> player) {

// }

// void Osap::auction() {

// }

// bool Osap::isMortgaged() {

// }

// bool Osap::isOwned() {

// }

// int Osap::getPos() {
//     return impl->pos;
// }

// int Osap::getPrice() {

// }

// string Osap::getName() {
//     return impl->name;
// }

// void Osap::improveBuy(std::shared_ptr<Player> player) {

// }

// void Osap::improveSell(std::shared_ptr<Player> player) {
    
// }

// int Osap::getImproveCost() {
    
// }

// std::string Osap::getMonopolyName() {
    
// }

// void Osap::unmortgage(std::shared_ptr<Player> player) {

// }
