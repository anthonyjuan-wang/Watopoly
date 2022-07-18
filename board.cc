#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "tile.h"
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
                    pieces.erase(pieces.begin()+j);
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

void Board::initTiles() {
    board.emplace_back(tile("AL", "Arts1", 40, 50, {2, 10, 30, 90, 160, 250}));
    board.emplace_back(tile("ML", "Arts1", 60, 50, {4, 20, 60, 180, 320, 450}));
    board.emplace_back(tile("ECH", "Arts2", 100, 50, {6, 30, 90, 270, 400, 550}));
    board.emplace_back(tile("PAS", "Arts2", 100, 50, {6, 30, 90, 270, 400, 550}));
    board.emplace_back(tile("HH", "Arts2", 120, 50, {8, 40, 100, 300, 450, 600}));
    board.emplace_back(tile("RCH", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}));
    board.emplace_back(tile("DWE", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}));
    board.emplace_back(tile("CPH", "Eng", 160, 100, {12, 60, 180, 500, 700, 900}));
    board.emplace_back(tile("LHI", "Health", 180, 100, {14, 70, 200, 550, 750, 950}));
    board.emplace_back(tile("BMH", "Health", 180, 100, {14, 70, 200, 550, 750, 950}));
    board.emplace_back(tile("OPT", "Health", 200, 100, {16, 80, 220, 600, 800, 1000}));
    board.emplace_back(tile("EV1", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}));
    board.emplace_back(tile("EV2", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}));
    board.emplace_back(tile("EV3", "Env", 240, 150, {20, 100, 300, 750, 925, 1100}));
    board.emplace_back(tile("PHYS", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150}));
    board.emplace_back(tile("B1", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150}));
    board.emplace_back(tile("B2", "Sci1", 280, 150, {24, 120, 360, 850, 1025, 1200}));
    board.emplace_back(tile("EIT", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}));
    board.emplace_back(tile("ESC", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}));
    board.emplace_back(tile("C2", "Sci2", 320, 200, {28, 150, 450, 1000, 1200, 1400}));
    board.emplace_back(tile("MC", "Math", 350, 200, {35, 175, 500, 1100, 1300, 1500}));
    board.emplace_back(tile("DC", "Math", 400, 200, {50, 200, 600, 1400, 1700, 2000}));
}
