#include "goToTims.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GoToTims::GoToTims(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, false, false, position, 0, board} {}

GoToTims::~GoToTims() {}

void GoToTims::action(std::shared_ptr<Player> player) {

}
