#include "goToTims.h"
#include "tile.h"
#include <string>
#include <memory>
#include "player.h"
#include "board.h"

using namespace std;

GoToTims::GoToTims(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

GoToTims::~GoToTims() {}

void GoToTims::action(std::shared_ptr<Player> player) {
    cout << "You landed on GoToTims! You are now stuck in an exponentially long line and have to wait to get your morning coffee" << endl; 
    player->setPos(10);
    player->setJailStatus(true);
    player->setJailCount(0);
}
