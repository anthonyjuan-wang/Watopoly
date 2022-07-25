#include "needlesHall.h"
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
#include "player.h"
//class Player;
class Board;

using namespace std;

NeedlesHall::NeedlesHall(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

NeedlesHall::~NeedlesHall() {}

void NeedlesHall::action(std::shared_ptr<Player> player) {
    int value = rand() % 100 + 1;
    shared_ptr<Board> currBoard = getBoard();
    int totalRollUpCount = currBoard->getRollUpCount();

    if (value == 100 &&  totalRollUpCount < 4) {
        currBoard->setRollUpCount(totalRollUpCount + 1);
        player->addRollUpCount();
        cout << "Congrats, you just obtained a roll up the rim cup!" << endl;
        cout << "You have " << player->getRollUpCount() << " roll up the rim cups." << endl;
    }

    value = rand() % 18 + 1;
    if (value == 1) {
        cout << "You will lose $200. ";
        player->subtractMoney(200);
    } else if (value >= 2 && value <= 3) {
        cout << "You will lose $100. ";
        player->subtractMoney(100);
    } else if (value >= 4 && value <= 6) {
        cout << "You will lose $50. ";
        player->subtractMoney(50);
    } else if (value >= 7 && value <= 12) {
        cout << "You will gain $25. ";
        player->addMoney(25);
    } else if (value >= 13 && value <= 15) {
        cout << "You will gain $50. ";
        player->addMoney(50);
    } else if (value >= 16 && value <= 17) {
        cout << "You will gain $100. ";
        player->addMoney(100);
    } else if (value == 18) {
        cout << "You will gain $200. ";
        player->addMoney(200);
    }
}
