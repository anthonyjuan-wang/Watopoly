#include "slc.h"
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
#include "board.h"
#include "player.h"

using namespace std;
Slc::Slc(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

Slc::~Slc() {}

void Slc::action(std::shared_ptr<Player> player) {
    int value = rand() % 100 + 1;
    shared_ptr<Board> currBoard = getBoard();
    int totalRollUpCount = currBoard->getRollUpCount();

    if (value == 100 &&  totalRollUpCount < 4) {
        currBoard->setRollUpCount(totalRollUpCount + 1);
        player->addRollUpCount();
        cout << "Congrats, you just obtained a roll up the rim cup!" << endl;
        cout << "You have " << player->getRollUpCount() << " roll up the rim cups." << endl;
    }

    value = rand() % 24 + 1;
    if (value >= 1 && value <= 3) {
        cout << "You moved back 3 spaces. ";
        player->move(-3);
    } else if (value >= 4 && value <= 7) {
        cout << "You moved back 2 spaces. ";
        player->move(-2);
    } else if (value >= 8 && value <= 11) {
        cout << "You moved back 1 space. ";
        player->move(-1);
    } else if (value >= 12 && value <= 14) {
        cout << "You moved forward 1 space. ";
        player->move(1);
    } else if (value >= 15 && value <= 18) {
        cout << "You moved forward 2 spaces. ";
        player->move(2);
    } else if (value >= 19 && value <= 22) {
        cout << "You moved forward 3 spaces. ";
        player->move(3);
    } else if (value == 23) {
        cout << "You were moved to the Go To DC Tims Line tile. " << endl;
        player->setPos(10);
        player->setJailStatus(true);
        player->setJailCount(0);
        return;
    } else if (value == 24) {
        cout << "You were moved forward to 'Collect Osap'. ";
        player->setPos(0);
    }

    int currPos = player->getPos();
    vector<shared_ptr<Tile>> boardTiles = getBoard()->getTiles();
    cout << "You have landed on " << boardTiles[currPos]->getName() << ". " << endl;
    boardTiles[currPos]->action(player);
}
