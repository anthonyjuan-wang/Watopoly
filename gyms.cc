#include "gyms.h"
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "player.h"
#include "board.h"

using namespace std;

Gyms::Gyms(int position, string blockName, bool gym, shared_ptr<Board> board) : Tile{blockName, true, false, position, 150, board} {
    isGym = gym;
}

Gyms::~Gyms() {}

vector<int> Gyms::rollDice() {
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    vector<int> dice = {die1, die2};
    return dice;
}

void Gyms::action(std::shared_ptr<Player> player) {
    cout << "You have landed on " << getName() << endl;
    if (isOwnable()) {
        cout << "Would you like to buy " << getName() << " for " << getPrice() << "?" << endl;
        string answer;
        cin >> answer;
        while(1) {
            if (answer == "yes") {
                int remaining = player->getMoney() - getPrice();
                if (remaining < 0) {
                    cout << "You don't have enough to purchase this building." << endl;
                    cout << getName() << " will now go up for auction" << endl;
                    auction();
                    break;
                } else {
                    player->subtractMoney(getPrice());
                    vector<shared_ptr<Tile>> currBoard = getBoard()->getTiles();
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
            int gymCount = 0;
            std::vector<std::shared_ptr<Tile>> listOfOwnedTiles = getOwner()->getTiles();
            for (unsigned int i = 0; i < listOfOwnedTiles.size(); i++) {
                if (listOfOwnedTiles[i]->isGym()) {
                    gymCount += 1;
                }
            }    
            cout << "This Gym is owned by" << getOwner() << " who owns " << gymCount << endl;
            // Roll of dice to get payment
            int diceSum = 0;
            cout << "Please type \"roll\" to roll two dices to determine your usage fees: 4x the sum of the dices if only 1 gym. 10x sum of dices if 2 gyms are owned" << endl;
            string answer;
            cin >> answer;
            while (1) {
                if (answer == "yes") {
                    vector<int> diceVal = rollDice();
                    cout << "You rolled a " << diceVal[0] << " and " << diceVal[1] << endl;
                    diceSum = diceVal[0] + diceVal[1];
                } else {
                    cout << "Please type \"roll\" to roll two dices" << endl;
                    cin >> answer;
                }
            }    

            int payment = 0;
            if (gymCount == 1) {
                payment = 4 * diceSum;
            } else {
                payment = 10 * diceSum;
            }

            cout << "Please type \"Pay\" to pay for your fees" << endl;
            while(1) {
                cin >> answer;
                if (answer == "pay") {
                    int remaining = player->getMoney() - payment;
                    if (remaining < 0) {
                        cout << "You do not have enough to pay for these fees. Find a way to pay for this property or you must drop out" << endl;
                        player->setAlmostBankruptStatus(true);
                        player->setMoneyOwed(payment);
                        break;
                    } else {
                        cout << "You have successfully paid your gym fees" << payment << endl;
                        player->subtractMoney(payment);
                        break;
                    }
                } else {
                    cout << "Please type \"Pay\" to pay for your fees." << endl;
                }
            }
            
        } else {
            cout << "Wow you own this gym! Time to get swol ᕦ(ಠ‿‿ಠ)ᕥ" << endl;
        }
    }
}
