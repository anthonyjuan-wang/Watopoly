#include "academic.h"
#include "tile.h"
#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include "player.h"
#include "board.h"

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int improvementCost, int improvementNum,
                   vector<int> tuitionCost, shared_ptr<Board> board) : Tile{blockName, true, true, position, purchaseCost, board} {
    tuition = tuitionCost;
    this->improvementCost = improvementCost;
    monopoly = monopolyType;
    this->improvementNum = improvementNum;
}

Academic::~Academic() {}

int Academic::getImprovement() {
    return this->improvementNum;
}
void Academic::setImprovement(int x) {
    this->improvementNum = x;
}

int Academic::getImproveCost() {
    return this->improvementCost;
}

string Academic::getMonopolyName() {
    return monopoly;
}
void Academic::improveBuy(shared_ptr<Player> player) {
    // Get current improvement #
    // Get the improvement cost
    // Subtract cost from bank
    // Increase improvemnt #
    int currentImprovement = getImprovement();
    int improvementCost = getImproveCost();
    player->subtractMoney(improvementCost);
    setImprovement(currentImprovement + 1);
}
void Academic::improveSell(shared_ptr<Player> player) {
    // Get current improvement #
    // Get the improvement cost
    // Add HALf the cost to bank
    // Decrease improvement #
    int currentImprovement = getImprovement();
    int improvementCost = getImproveCost();
    player->addMoney(improvementCost / 2);
    setImprovement(currentImprovement - 1);
}

void Academic::action(std::shared_ptr<Player> player) {
    if (!isOwned()) {
        // Do you have enough money to buy

        cout << "Would you like to buy " << getName() << " for $" << getPrice() << "? Enter 'yes' or 'no'." << endl;
        // ADDED SPACES HERE
        cout << "\n\n\n\n\n\n";
        // Look for "yes" or "no"
        string answer;
        while(1) {
            cin >> answer;
            if (answer == "yes") {
                // Check if almost bankrupt
                int remaining = player->getMoney() - getPrice();
                if (remaining < 0) {
                    cout << "You don't have enough money to purchase this building." << endl;
                    cout << getName() <<  " will now go up for auction" << endl;
                    auction();
                    break;
                 } else {
                    vector<shared_ptr<Tile>> boardTiles = getBoard()->getTiles();
                    int currPos = getPos();
                    player->addTile(boardTiles[currPos]);
                    cout << "You have successfuly purchased " << boardTiles[currPos]->getName() << " for $" << getPrice() << endl;
                    player->subtractMoney(getPrice());
                    setOwner(player);
                    break;
                 }
            } else if (answer == "no") {
                cout << getName() <<  " will now go up for auction" << endl;
                auction();
                break;
            } else {
                cout << "Please enter either \"yes\" or \"no\": Would you like to purchase this building for " << getPrice() << endl;
            }
        }
    } else {
        // Player lands on an already owner academic building
        // Check that the player does not already own this spot
        if (getOwner() != player) {
            cout << "This building is owned by " << getOwner()->getName() << ". You will need to pay tuition worth $" << tuition[getImprovement()] << endl;
            // Get the cost of tuition based on # of improvements
            int cost = tuition[getImprovement()];
            int remaining = player->getMoney() - cost;
            // Check the player is bankrupt after paying for tuition
            if (remaining < 0) {
                cout << "You do not have enough to pay for tution. Find a way to pay for this property or you must drop out" << endl;
                player->setAlmostBankruptStatus(true);
                player->setMoneyOwed(cost);
            } else {
                // Pay for the tution cost
                string answerpay;
                while(1) {
                    cout << "Please type \"pay\" to pay for your tuition" << endl;
                    cin >> answerpay;
                    if (answerpay == "pay") {
                        player->subtractMoney(cost);
                        break;
                    }
                }
            }
        } else {
            // Player lands on their own tile
            cout << "Nice, you own this property!" << endl;
        }
    }
}
