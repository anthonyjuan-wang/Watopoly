#include "board.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Board::Board() {}

Board::~Board() {}

void Board::init(int input) {
    if (!(players.empty())) {
        players.clear();
    }

    vector<string> pieces = {"G: Goose", "B: GRT Bus", "D: Tim Hortons Doughnut", "P: Professor", "S: Student", "M: Money", "L: Laptop", "P: Pink Tie"};
    
    for (int i = 1; i <= input; i++) {
        string playerName;
        char playerPiece;

        // get a valid playerName
        while(true) {
            cout << "Hi Player " << i << " enter your name: ";
            cin >> playerName;

            // check if the playerName already exists
            if (playerName == "Bank") {
                cout << "This name is not valid" << endl;
            } else {
                bool nameTaken = false;
                int size = players.size();
                for (int j = 0; j < size; i++) {
                    if (players[j]->getName() == playerName) {
                        nameTaken = true;
                        break;
                    }
                }
                if(nameTaken == false) {
                    break;
                } else {
                    cout << "The playerName chosen has already been taken" << endl;
                }
            }
        }

        // get a valid player piece
        while(true) {
            cout << "Player " << i << " enter the char of the player piece you'd like to choose" << endl;
            cout << "The list of pieces available are" << endl;
            for (auto p: pieces) {
                cout << p << endl;
            }
            cin >> playerPiece;

            int size = pieces.size();
            bool pieceFound = false;
            for (int j = 0; j < size; j++) {
                if (pieces[j][0] == playerPiece) {
                    pieceFound == true;
                    pieces.erase(j);
                    break;
                }
            }

            if (pieceFound == true) {
                break;
            } else {
                cout << "The piece doesn't exist or has already been chosen." << endl;
            }
        }
        players.emplace_back(Player(playerName, playerPiece));
    } 
}