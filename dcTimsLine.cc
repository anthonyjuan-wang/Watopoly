#include "dcTimsLine.h"
#include "tile.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

DcTimsLine::DcTimsLine(int position, string blockName, shared_ptr<Board> board) : Tile{blockName, false, false, position, 0, board} {}

DcTimsLine::~DcTimsLine() {}

void DcTimsLine::action(shared_ptr<Player> player) {
if (player->getJailStatus() == true) {  
    while (true) {
            // If player is in last turn
             if (player->getJailCount() == 2) {
                            cout << "This is your last turn in jail. You must use a roll up the rim cup or pay up." << endl;
                      }
            // If player cannot pay 
            if (player->getRollUpCount() == 0 && player->getMoney() < 50){
                     if (player->getJailCount() == 2) {
                            player->setAlmostBankruptStatus(true);
                            player->setMoneyOwed(50);
                            break;
                      }
                     else { 
                            cout << "Your turn is over. You cannot pay or use a roll up the rim cup." << endl;
                            player->setJailCount(player->getJailCount() + 1);
                            break;
                    }
                  }  
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
                        player->setJailStatus(false);
                        player->setJailCount(0);
                        break;
                    }    
                } else if (cmd == "up") {   
                    // cannot use rolluprim cup
                    if (player->getRollUpCount() == 0 ){
                        cout << "You don't have a roll up the rim cup. Please enter a valid command." << endl;
                        continue;
                    } 
                    else {
                        // use up roll up the rim cup
                        player->useRollUpCount(); 
                        player->setJailStatus(false);
                        player->setJailCount(0);
                        break;              
                    }   
                }
            }
        }  
}


