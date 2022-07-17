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

    bool pieceFound = false;
    char c;
    vector<string> pieces = {"G: Goose", "B: GRT Bus", "D: Tim Hortons Doughnut", "P: Professor", "S: Student", "M: Money", "L: Laptop", "P: Pink Tie"};
    
    for (int i = 1; i <= input; i++) {
        // get a valid playerName
        string playerName;
        while(true) {
            cout << "Hi Player " << i << " enter your name: ";
            cin >> playerName;

            // check if the playerName already exists
            bool nameTaken = false;
            if (playerName == "Bank") {
                cout << "This name is not valid";
                break;
            } else {
                int size = players.size();
                for (int j = 0; j < size; i++) {
                    if (players[j]->getName() == playerName) {
                        nameTaken = true;
                        break;
                    }
                }
            }

            if(nameTaken == false) {
                break;
            } else {
                cout << "The playerName chosen has already been taken";
            }
        }

        // get a valid player piece
        while(true) {
            cout << "Player " << i << " enter the char of the player piece you'd like to choose" << endl;
            cout << "The list of pieces available are" << endl;
            for (auto p: pieces) {
                cout << p << endl;
            }
            cin >> c;

            for (unsigned int j = 0; j < pieces.size(); j++) {
                if (j[0] == c) {
                    pieceFound == true;
                    pieces.erase(j);
                    break;
            }
            }
        }



        if (pieceFound == true) {
            players.emplace_back(Player(c));
            pieceFound == f
        } else {
            i--;
        }
    } 
}