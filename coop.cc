#include "coop.h"
#include "tile.h"
#include <string>
#include <memory>
#include "player.h"
#include "board.h"

using namespace std;

Coop::Coop(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

Coop::~Coop() {}

void Coop::action(shared_ptr<Player> player) {
    cout << "You've landed on Coop. You must pay the Coop fee of $150." << endl; 
    
    if (player->getMoney() < 150) {
        cout << "You do not have enough to pay the $150 fee. You now have the ability to declare bankruptcy." << endl;
        player->setAlmostBankruptStatus(true);
        player->setMoneyOwed(150);
    } else{ 
        player->subtractMoney(150);
    }
}
