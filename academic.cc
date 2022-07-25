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
    if (isOwnable()) {
        // Do you have enough money to buy

        cout << "Would you like to buy " << getName() << " for " << getPrice() << "? Enter 'yes' or 'no'." << endl;

        // Look for "yes" or "no"
        string answer;
        cin >> answer;
        while(1) {
            if (answer == "yes") {
                // Check if almost bankrupt
                int remaining = player->getMoney() - getPrice();
                if (remaining < 0) {
                    cout << "You don't have enough to purchase this building." << endl;
                    cout << getName() <<  " will now go up for auction" << endl;
                    auction();
                    break;
                 } else {
                    player->subtractMoney(getPrice());
                    vector<shared_ptr<Tile>> boardTiles = getBoard()->getTiles();
                    int currPos = getPos();
                    player->addTile(boardTiles[currPos]);
                    setOwner(player);
                    cout << "You have successfuly purchased " << boardTiles[currPos]->getName() << "." << endl;
                 }
                break;
            } else if (answer == "no") {
                cout << getName() <<  " is now going to be auctioned" << endl;
                auction();
                break;
            } else {
                cout << "Please enter either \"yes\" or \"no\": Would you like to purchase this building for " << getPrice() << endl;
                cin >> answer;
            }
        }
    } else {
        // Player lands on an already owner academic building
        // Check that the player does not already own this spot
        if (getOwner() != player) {
            cout << "This building is owned by " << getOwner() << ". You will need to pay $" << tuition[getImprovement()] << endl;
            // Get the cost of tuition based on # of improvements
            int cost = tuition[getImprovement()];
            int remaining = player->getMoney() - cost;
            // Check the player is bankrupt after paying for tuition
            if (remaining < 0) {
                cout << "You do not have enough to pay for tution. Find a way to pay for this property or you must drop out" << endl;
                player->setAlmostBankruptStatus(true);
                player->setMoneyOwed(cost);
            } else {
                // Pay for the tuition cost
                player->subtractMoney(cost);
            }
        } else {
            // Player lands on their own tile
            cout << "Nice, you own this property!" << endl;
        }
    }
}
