#include "needlesHall.h"
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
class Player;
class Board;

using namespace std;

NeedlesHall::NeedlesHall(int position, string blockName, shared_ptr<Board> board, vector<shared_ptr<Tile>> boardTiles) : Tile{blockName, false, false, position, 0, board, boardTiles} {}

NeedlesHall::~NeedlesHall() {}

void NeedlesHall::action(std::shared_ptr<Player> player) {
    
}
