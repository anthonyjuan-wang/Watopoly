#include "slc.h"
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

using namespace std;
Slc::Slc(int position, string blockName) : Tile{blockName, false, false, position, 0} {}

Slc::~Slc() {}

void Slc::action(std::shared_ptr<Player> player) {

}
