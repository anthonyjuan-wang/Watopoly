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
Residences::Residences(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, true, false, position, 200, board} {
}

Residences::~Residences() {}

void Residences::action(shared_ptr<Player> player) {
    if (!isOwned()) {
        // Player has the option to buy this house
        cout << "Would you like to buy " << getName() << " for " << getPrice() << "?" << endl;
        cout << "Types \"yes\" to buy or \"no\" to not buy" << endl;
        // ADDED SPACES HERE
        cout << "\n\n\n\n\n\n";
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
                    vector<shared_ptr<Tile>> currBoard = getBoard()->getTiles();
                    int currPos = getPos();
                    player->addTile(currBoard[currPos]);
                    cout << "You have successfully bought " << getName() << " for" << getPrice() << endl;
                    player->subtractMoney(getPrice());
                    setOwner(player);
                    break;
                }
            } else if (answer == "no") {
                cout << getName() << " is now going up for auction" << endl;
                auction();
                break;
            } else {
                cout << "Please enter either \"yes\" or \"no\": Would you like to purchase " << getName() << " for " << getPrice() << "?" << endl;
            }
        }
    } else {
        // Player lands on anther players tile
        if (getOwner() != player) {
            int residenceCount = 0;

            std::vector<std::shared_ptr<Tile>> listOfOwnedTiles = getOwner()->getTiles();
            for (unsigned int i = 0; i < listOfOwnedTiles.size(); i++) {
                if ((listOfOwnedTiles[i]->getName() == "MKV")
                    || (listOfOwnedTiles[i]->getName() =="UWP")
                    || (listOfOwnedTiles[i]->getName() =="V1")
                    || (listOfOwnedTiles[i]->getName() =="REV")) {
                    residenceCount += 1;
                }
            }
            
            // Determine how much the fee is based on the other player's owned residence's
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

            // Make the player pay the toll
            cout << "This residence is owned by" << getOwner()->getName() << ". Since " << getOwner()->getName() << " has " << residenceCount 
            << " properties,  you must pay $" << payment << endl;
            int remaining = player->getMoney() - payment;
            cout << "Please type \"pay\" to pay for these fines" << endl;
            string response;
            while (1) {
                cin >> response;
                if (response == "pay") {
                    if (remaining < 0) {
                        cout << "You do not have enough to pay for these fees. Find a way to pay for this property or you must drop out" << endl;
                        player->setAlmostBankruptStatus(true);
                        player->setMoneyOwed(payment);
                        break;
                    } else {
                        player->subtractMoney(payment);
                        cout << "You have successfully paid the fee of " << payment << endl;
                        break;
                    }
                } else {
                    cout << "Please type \"pay\" to pay for these fines" << endl;
                }
            }
        } else {
            // When the player lands on their own residencec square
            cout << "Wow you own this residence! :o" << endl;
        }
    }
}
