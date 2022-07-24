#include "gooseNesting.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;

GooseNesting::GooseNesting(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, false, false, position, 0, board} {}

GooseNesting::~GooseNesting() {}

void GooseNesting::action(std::shared_ptr<Player> player) {
    cout << "Preprare to suck some goose dick" << endl;
}
