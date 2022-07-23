#include "academic.h"
#include "tile.h"
#include <string>
#include <memory>
#include <iostream>

#include "player.h"
class Board;

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int improvementCost,
                   vector<int> tuitionCost) :  Tile{blockName, true, true, position, purchaseCost} {
    tuition = tuitionCost;
    improvement = improvementCost;
    monopoly = monopolyType;
}

Academic::~Academic() {}

<<<<<<< HEAD
std::shared_ptr<TileImpl> Academic::getImpl() {
    return impl;
}

std::shared_ptr<Player> Academic::getOwner() {
    return impl->Owner;
}

void Academic::setOwner(std::shared_ptr<Player> player) {
    impl->Owner = player;
}

int Academic::getImprovement() { // returns the improvement #
    return impl->improvement;
}

void Academic::setImprovement(int x) {
    impl->improvement = x;
}

void Academic::action(std::shared_ptr<Player> player) {
    // Check if tile is owned
        // If is owned, Pay Tuition

}

void Academic::mortgage(std::shared_ptr<Player> player) {

}

void Academic::auction() {

}

bool Academic::isMortgaged() {

}

bool Academic::isOwned() {
    return impl->isOwnable;
}

int Academic::getPos() {
    return impl->pos;
}

int Academic::getPrice() {
    return impl->purchase;
}

string Academic::getName() {
    return impl->name;
}

void Academic::improveBuy(std::shared_ptr<Player> player) {
    int improveNum = getImprovement();
    int price = getPrice();
    setImprovement(improveNum + 1);
    player->subtractMoney(price);
}

void Academic::improveSell(std::shared_ptr<Player> player) {
    int improveNum = getImprovement();
    int price = getPrice();
    setImprovement(improveNum - 1);
    player->addMoney(price/2);
}

int Academic::getImproveCost() {
    return impl->improvement;
}

string Academic::getMonopolyName() {
    return impl->monopoly;
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

=======
void Academic::action(std::shared_ptr<Player> player) {
    cout << "You have landed on " << Academic->getName() << endl;
    if (Academic->isOwnable()) {
        // Do you have enough money to buy

        cout << "Would you like to buy " << Academic->getName() << " for " << Academic->getPrice() << "?" << endl;

        string answer;
        cin >> answer;
        while(1) {
            if (cin == "yes") {
                // Check if almost bankrupt
                int remaining = player->getMoney() - Academic->getPrice();
                if (remaining < 0) {
                    // SET MONEYOWED TO FOR PLAYER
                    cout << "You don't have enough to purchase this property. Broke ass bitch. Would you like to sell some property" << endl;
                    // Do you want to sell some property?
                    while(1) {
                        cin >> answer;
                        if (answer == "yes") {
                            // Start selling some property
                            break;
                        } else {
                            Academic->auction();
                            break;
                        } else {
                            cout << "Please enter either \"yes\" or \"no\": Would you like to sell some property?" << endl;
                        }
                    }
                 }
                break;
            } else if (cin == "no") {
                Academic->auction();
                break;
            } else {
                cout << "Please enter either \"yes\" or \"no\": Would you like to purchase this propertly" << endl;
            }
        }        
    }
>>>>>>> main
}
