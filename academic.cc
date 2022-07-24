#include "academic.h"
#include "tile.h"
#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include "player.h"
#include "board.h"

using namespace std;

Academic::Academic(int position, string blockName, string monopolyType, int purchaseCost, int improvementCost,
                   vector<int> tuitionCost, shared_ptr<Board> board, vector<shared_ptr<Tile>> boardTiles) : Tile{blockName, true, true, position, purchaseCost, board, boardTiles} {
    tuition = tuitionCost;
    improvement = improvementCost;
    monopoly = monopolyType;
}

Academic::~Academic() {}

void Academic::action(std::shared_ptr<Player> player) {
    cout << "You have landed on " << getName() << endl;
    if (isOwnable()) {
        // Do you have enough money to buy

        cout << "Would you like to buy " << getName() << " for " << getPrice() << "?" << endl;

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
                    vector<shared_ptr<Tile>> currBoard = getBoardTiles();
                    int currPos = getPos();
                    player->addTile(currBoard[currPos]);
                    setOwner(player);
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
        // Player lands on an already owner academic building
    } else {
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
            cout << "Nice, you own this property!" << endl;
        }
    }
}
