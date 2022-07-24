#include <string>
#include <memory>
#include "osap.h"
#include "tile.h"
#include "tileimpl.h"
#include "player.h"
#include "board.h"

using namespace std;

Osap::Osap(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, false, false, position, 0, board} {}

Osap::~Osap() {}

void Osap::action(std::shared_ptr<Player> player) {
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    getOwner()->addMoney(200);
}
