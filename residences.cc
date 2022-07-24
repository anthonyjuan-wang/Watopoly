#include "residences.h"
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "player.h"
#include "board.h"

using namespace std;
Residences::Residences(int position, string blockName, bool residence, vector<shared_ptr<Tile>> board) : Tile{blockName, true, false, position, 200, board} {
    isResidence = residence;
}

Residences::~Residences() {}

void Residences::action(shared_ptr<Player> player) {
    cout << "You have landed on " << getName() << endl;

    if (isOwnable()) {
        cout << "Would you like to buy " << getName() << " for " << getPrice() << "?" << endl;
        string answer;
        while(1) {
            cin >> answer;
            if (answer == "yes") {
                int remaining = player->getMoney() - getPrice();
                if (remaining < 0) {
                    cout << "You don't have enough to purchase this building." << endl;
                    cout << getName() << " will now go up for auction" << endl;
                    auction();
                    break;
                } else {
                    player->subtractMoney(getPrice());
                    vector<shared_ptr<Tile>> currBoard = getBoard();
                    int currPos = getPos();
                    player->addTile(currBoard[currPos]);
                    setOwner(player);
                }
            } else if (answer == "no") {
                cout << getName() << " is now going up for auction" << endl;
                auction();
                break;
            } else {
                cout << "Please enter either \"yes\" or \"no\": Would you like to purchase" << getName() << " for " << getPrice() << "?" << endl;
                cin >> answer;
            }
        }
    } else {
        if (getOwner() != player) {
            int residenceCount = 0;

            std::vector<std::shared_ptr<Tile>> listOfOwnedTiles = getOwner()->getTiles();
            for (int i = 0; i < listOfOwnedTiles.size(); i++) {
                if (listOfOwnedTiles->isResidence()) {
                    residenceCount += 1;
                }
            }
            
            int payment = 0;
            if (residenceCount == 1) {
                payment = 25;
            } else if (residenceCount == 2) {
                payment = 50;
            } else if (residenceCount == 3) {
                payment = 100;
            } else {
                payment = 200;
            }

            cout << "This residence is owned by" << getOwner() << ". Since " << getOwner() << "has " << residenceCount 
            << " properties,  you must pay $" << payment << endl;
            int remaining = player->getMoney() - payment;
            if (remaining < 0) {
                cout << "You do not have enough to pay for these fees. Find a way to pay for this property or you must drop out" << endl;
                player->setAlmostBankruptStatus(true);
                player->setMoneyOwed(payment);
            } else {
                player->subtractMoney(payment);
            }
            
        } else {
            cout << "Wow you own this residence! :o" << endl;
        }
    }
}
