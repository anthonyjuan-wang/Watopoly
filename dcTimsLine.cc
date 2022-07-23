#include "dcTimsLine.h"
#include "tile.h"
#include <string>
#include <memory>
#include "player.h"
#include "board.h"

using namespace std;

DcTimsLine::DcTimsLine(int position, string blockName) : Tile{blockName, false, false, position, 0} {

}

DcTimsLine::~DcTimsLine() {}

void DcTimsLine::action(shared_ptr<Player> player) {
    cout << "You have landed on the DcTimsLine square" << endl;
    while (true){
    if (player->getJailStatus() == true){
        if (player->getJailCount() == 2) cout << "This is your last turn in jail. You must use a roll up the rim cup or pay up."
            cout << "Enter 'roll' to roll the die, 'pay' to pay the jail fee, or 'up' to use your Roll Up cup" << endl;

        }

    }  
    }

// std::shared_ptr<TileImpl> DcTimsLine::getImpl() {

// }

// std::shared_ptr<Player> DcTimsLine::getOwner() {

// }

// void DcTimsLine::setOwner(shared_ptr<Player> player) {

// }

// int DcTimsLine::getImprovement() { // returns the improvement #

// } 

// void DcTimsLine::setImprovement(int x) {

// }

// void DcTimsLine::mortgage(shared_ptr<Player> player) {

// }

// void DcTimsLine::auction() {

// }

// bool DcTimsLine::isMortgaged() {

// }

// bool DcTimsLine::isOwned() {

// }

// int DcTimsLine::getPos() {
//     return impl->pos;
// }

// int DcTimsLine::getPrice() {

// }

// string DcTimsLine::getName() {
//     return impl->name;
// }

// void DcTimsLine::improveBuy(std::shared_ptr<Player> player) {

// }

// void DcTimsLine::improveSell(std::shared_ptr<Player> player) {
    
// }

// int DcTimsLine::getImproveCost() {
    
// }

// std::string DcTimsLine::getMonopolyName() {
    
// }

// void DcTimsLine::unmortgage(std::shared_ptr<Player> player) {

// }
