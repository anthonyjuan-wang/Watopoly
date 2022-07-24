#include "slc.h"
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
#include "board.h"
class Player;
//class Board;

using namespace std;
Slc::Slc(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, false, false, position, 0, board} {}

Slc::~Slc() {}

void Slc::action(std::shared_ptr<Player> player) {
    int value = rand() % 100 + 1;
    vector<shared_ptr<Tile>> currBoard = getBoard();
    totalRollUpCount = currBoard->getRollUpCount();

    if (value == 100 &&  totalRollUpCount < 4) {
        currBoard->setRollUpCount(rollUpCount + 1);
        player->addRollUpCount();
        cout << "Congrats, you just obtained a roll up the rim cup!" << endl;
        cout << "You have " << player->getRollUpCount() << " roll up the rim cups." << endl;
    }

    value = rand() % 24 + 1;
    if (value >= 1 && value <= 3) {
        player->move(-3);
    } else if (value >= 4 && value <= 7) {
        player->move(-2);
    } else if (value >= 8 && value <= 11) {
        player->move(-1);
    } else if (value >= 12 && value <= 14) {
        player->move(1);
    } else if (value >= 15 && value <= 18) {
        player->move(2);
    } else if (value >= 19 && value <= 22) {
        player->move(3);
    } else if (value == 23) {
        player->setPos(10);
        player->setJailStatus(true);
        player->setJailCount(0);
        return;
    }
}
