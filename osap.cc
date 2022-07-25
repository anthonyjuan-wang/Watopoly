#include <string>
#include <memory>
#include "osap.h"
#include "tile.h"
#include "tileimpl.h"
#include "player.h"
#include "board.h"

using namespace std;

Osap::Osap(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

Osap::~Osap() {}

void Osap::action(std::shared_ptr<Player> player) {
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    player->addMoney(200);
}
