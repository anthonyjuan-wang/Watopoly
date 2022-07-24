#include "tuition.h"
#include <string>
#include <memory>
#include "player.h"
class Board;

using namespace std;

Tuition::Tuition(int position, string blockName, shared_ptr<Board> board, vector<shared_ptr<Tile>> boardTiles) : Tile{blockName, false, false, position, 0, board, boardTiles} {}

Tuition::~Tuition() {}

void Tuition::action(std::shared_ptr<Player> player) {
    // calculate 10% of total worth
    int totalWorth = 0;
    vector<shared_ptr<Tile>> ownedTiles = player->getTiles();
    int size = ownedTiles.size();

    totalWorth += (0.1 * player->getMoney());
    for (int i = 0; i < size; i++) {
        totalWorth += (0.1 * ownedTiles[i]->getPrice());

        if (ownedTiles[i]->isImprovable()) {
            int improvementNum = ownedTiles[i]->getImprovement();
            int improvementCost = ownedTiles[i]->getImproveCost();
            totalWorth += (0.1 * (improvementNum * improvementCost));
        }
    }

    cout << "You must pay the bank. Choose one of the options '1' or '2':" << endl;
    cout << "1. Pay $300" << endl;
    cout << "2. Pay 10%/ of your total worth (including savings, prices of each building owned, and costs of each improvement)." << endl;
    cout << "Your total worth is $ " << totalWorth << endl;

    int response = 0;
    int cost = 0;
    cin >> response;

    while (true) {
        if (response == 1 ) {
            cost = 300;
        } else if (response == 2) {
            cost = totalWorth;
        } else {
            cout << "Invalid, please enter a valid command" << endl;
        }
    }

    if (cost > player->getMoney()) {
        player->setAlmostBankruptStatus(true);
        player->setMoneyOwed(cost);
    } else {
        player->subtractMoney(cost);
    }
}
