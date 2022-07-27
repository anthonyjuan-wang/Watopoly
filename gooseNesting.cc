#include "gooseNesting.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GooseNesting::GooseNesting(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

GooseNesting::~GooseNesting() {}

void GooseNesting::action(std::shared_ptr<Player> player) {
    cout << "You were attacked by a flock of nesting geese. Nothing was lost." << endl;
}
