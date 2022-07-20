#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "player.h"
#include "academic.h"
#include "osap.h"
#include "coop.h"
#include "dcTimsLine.h"
#include "goToTims.h"
#include "needlesHall.h"
#include "residences.h"
#include "slc.h"
#include "gyms.h"
#include "tuition.h"
#include "gooseNesting.h"

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
        while (true) {
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
                if (nameTaken == false) {
                    break;
                }
                else {
                    cout << "The playerName chosen has already been taken" << endl;
                }
            }
        }

        // get a valid player piece
        while (true) {
            cout << "Player " << i << " enter the char of the player piece you'd like to choose" << endl;
            cout << "The list of pieces available are" << endl;
            for (auto p : pieces) {
                cout << p << endl;
            }
            cin >> playerPiece;

            int size = pieces.size();
            bool pieceFound = false;
            for (int j = 0; j < size; j++) {
                if (pieces[j][0] == playerPiece) {
                    pieceFound == true;
                    pieces.erase(pieces.begin() + j);
                    break;
                }
            }

            if (pieceFound == true) {
                break;
            }
            else {
                cout << "The piece doesn't exist or has already been chosen." << endl;
            }
        }
        players.emplace_back(Player(playerName, playerPiece));
    } 
}

void Board::play() {
    int playersCount = 0;
    int currPlayerNum = 0;

    // ask the user for the number of players
    while(true) {
        cout << "How many players are there? ";
        cin >> playersCount;

        if (playersCount >= 2 && playersCount <= 8) {
            init(playersCount);
            break;
        } else {
            cout << "The number of players you entered is invalid" << endl;
        }
    }

    // play game - continues until there are < 2 players
    while(true) {
        shared_ptr<Player> currPlayer = players[currPlayerNum];
        string input{};
        string cmd;
        vector<string> commands{};
        vector<string> cmdInterpreter = {"roll", "next", "trade", "improve", "mortgage", "unmortgage", "bankrupt", "assets", "all", "save"};

        // checks if the # of players are < 2 
        if (currPlayerNum < 2) {
            cout << "Congratulations " << players[0]->getName << " you are the winner! The game is now over" << endl;
            break;
        }

        // stores the line of input into a vector 'commands'
        getline(cin, input);
        istringstream iss{input};
        while(iss >> cmd) {
            commands.emplaceback(cmd);
        }

        if (commands.size() < 1) { // user needs to enter command again
            cout << "Please enter a non-empty command" << endl;
            continue;
        }


        // outputs the possible user commands
        cout << "It is " << currPlayer->getName() << " turn. Enter a command from the following: " << endl;
        for (auto i: cmdInterpreter) {
            cout << i << endl;
        }

        // switch to check all the possible player command inputs
        switch (commands[0]) {
            case "roll":
                if (currPlayer->getJailStatus() == true) {
                    cout << "You will not be able to roll the dice. You are in the DC Tims Line" << endl;
                    continue;
                } 
                vector<int> dice = rollDice();
                int total = currPlayer->getPos + dice[0] + dice[1];
                currPlayer->move(total);
                int pos = currPlayer->getPos();
                
                cout << "You rolled " << dice[0] << " and " << dice[1] << endl;
                if (board[pos]->isOwned == true) {
                    //shared_ptr<Player[> tileOwner = board[pos]->getOwner();
                    board[pos]->action(currPlayer); // might have to pass the owner of the tile too
                } else {

                }
                break;
        }


        // check if almostBankrupt is true and check moneyOwed
        currPlayerNum++;
        if (playersCount == currPlayerNum) {
            currPlayerNum = 0; 
        }
    }
}

void Board::tradeGive(Player *p, string s, int n) {

}

void Board::tradeReceive(Player *p, string s, int n) {

}

vector<int> Board::rollDice() {
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    vector<int> dice = {die1, die2};
    return dice; 
}

void Board::initTiles()
{
    board.emplace_back(make_shared<Osap>(0));
    board.emplace_back(make_shared<Academic>(1, "AL", "Arts1", 40, 50, vector<int>{2, 10, 30, 90, 160, 250}));
    board.emplace_back(make_shared<Slc>(2));
    board.emplace_back(make_shared<Academic>(3, "ML", "Arts1", 60, 50, vector<int>{4, 20, 60, 180, 320, 450}));
    board.emplace_back(make_shared<Tuition>(4));
    board.emplace_back(make_shared<Residences>(5, "MKV"));
    board.emplace_back(make_shared<Academic>(6, "ECH", "Arts2", 100, 50, vector<int>{6, 30, 90, 270, 400, 550}));
    board.emplace_back(make_shared<NeedlesHall>(7));
    board.emplace_back(make_shared<Academic>(8, "PAS", "Arts2", 100, 50, vector<int>{6, 30, 90, 270, 400, 550}));
    board.emplace_back(make_shared<Academic>(9, "HH", "Arts2", 120, 50, vector<int>{8, 40, 100, 300, 450, 600}));
    board.emplace_back(make_shared<DcTimsLine>(10));
    board.emplace_back(make_shared<Academic>(11, "RCH", "Eng", 140, 100, vector<int>{10, 50, 150, 450, 625, 750}));
    board.emplace_back(make_shared<Gyms>(12, "PAC"));
    board.emplace_back(make_shared<Academic>(13, "DWE", "Eng", 140, 100, vector<int>{10, 50, 150, 450, 625, 750}));
    board.emplace_back(make_shared<Academic>(14, "CPH", "Eng", 160, 100, vector<int>{12, 60, 180, 500, 700, 900}));
    board.emplace_back(make_shared<Residences>(15, "UWP"));
    board.emplace_back(make_shared<Academic>(16, "LHI", "Health", 180, 100, vector<int>{14, 70, 200, 550, 750, 950}));
    board.emplace_back(make_shared<Slc>(17));
    board.emplace_back(make_shared<Academic>(18, "BMH", "Health", 180, 100, vector<int>{14, 70, 200, 550, 750, 950}));
    board.emplace_back(make_shared<Academic>(19, "OPT", "Health", 200, 100, vector<int>{16, 80, 220, 600, 800, 1000}));
    board.emplace_back(make_shared<GooseNesting>(20));
    board.emplace_back(make_shared<Academic>(21, "EV1", "Env", 220, 150, vector<int>{18, 90, 250, 700, 875, 1050}));
    board.emplace_back(make_shared<NeedlesHall>(22));
    board.emplace_back(make_shared<Academic>(23, "EV2", "Env", 220, 150, vector<int>{18, 90, 250, 700, 875, 1050}));
    board.emplace_back(make_shared<Academic>(24, "EV3", "Env", 240, 150, vector<int>{20, 100, 300, 750, 925, 1100}));
    board.emplace_back(make_shared<Residences>(25, "V1"));
    board.emplace_back(make_shared<Academic>(26, "PHYS", "Sci1", 260, 150, vector<int>{22, 110, 330, 800, 975, 1150}));
    board.emplace_back(make_shared<Academic>(27, "B1", "Sci1", 260, 150, vector<int>{22, 110, 330, 800, 975, 1150}));
    board.emplace_back(make_shared<Gyms>(28, "CIF"));
    board.emplace_back(make_shared<Academic>(29, "B2", "Sci1", 280, 150, vector<int>{24, 120, 360, 850, 1025, 1200}));
    board.emplace_back(make_shared<GoToTims>(30));
    board.emplace_back(make_shared<Academic>(31, "EIT", "Sci2", 300, 200, vector<int>{26, 130, 390, 900, 1100, 1275}));
    board.emplace_back(make_shared<Academic>(32, "ESC", "Sci2", 300, 200, vector<int>{26, 130, 390, 900, 1100, 1275}));
    board.emplace_back(make_shared<Slc>(33));
    board.emplace_back(make_shared<Academic>(34, "C2", "Sci2", 320, 200, vector<int>{28, 150, 450, 1000, 1200, 1400}));
    board.emplace_back(make_shared<Residences>(35, "REV"));
    board.emplace_back(make_shared<NeedlesHall>(36));
    board.emplace_back(make_shared<Academic>(37, "MC", "Math", 350, 200, vector<int>{35, 175, 500, 1100, 1300, 1500}));
    board.emplace_back(make_shared<Coop>(38));
    board.emplace_back(make_shared<Academic>(39, "DC", "Math", 400, 200, vector<int>{50, 200, 600, 1400, 1700, 2000}));
}
