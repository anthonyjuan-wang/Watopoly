#include "dcTimsLine.h"
#include "tile.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>


using namespace std;

DcTimsLine::DcTimsLine(int position, string blockName, vector<shared_ptr<Tile>> board) : Tile{blockName, false, false, position, 0, board} {

}

DcTimsLine::~DcTimsLine() {}

void DcTimsLine::action(shared_ptr<Player> player) {
    cout << "You have landed on the DcTimsLine square" << endl;
    while (true) {
        if (player->getJailStatus()) {
            if (player->getJailCount() == 2) {
                cout << "This is your last turn in jail. You must use a roll up the rim cup or pay up." << endl;
                cout << "Enter 'pay' to pay the jail fee, or 'up' to use your Roll Up cup" << endl;
                string cmd;
                cin >> cmd; 
                if (cmd == "pay") {
                    if (player->getMoney() < 50) {
                        cout << "You have less than 50$! This command is invalid. Please enter a valid command" << endl;
                        continue;
                    } else {
                        player->subtractMoney(50);
                        cout << "You pay 50$, and are now free from jail!." << endl;
                        break;
                    }    
                }
            }
        }  
    }
}
