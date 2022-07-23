#include "residences.h"
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include "player.h"
#include "board.h"

using namespace std;
Residences::Residences(int position, string blockName) : Tile{blockName, true, false, position, 200} {}

Residences::~Residences() {}

void Residences::action(shared_ptr<Player> player) {

}
