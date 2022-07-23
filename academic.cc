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
}
