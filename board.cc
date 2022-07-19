#include "board.h"
#include <iostream>
//#include <vector>
//#include <string>
using namespace std;

Board::Board() {}

Board::~Board() {}

void Board::loadGame(string input) {

}

void Board::saveGame(string input) {

}

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
        }
    }

    // play game - continues until there are < 2 players
    while(true) {
        player *currPlayer = players[currPlayerNum];
        string input{};
        string cmd;
        vector<string> commands{};
        vector<string> cmdInterpreter = {"roll", "next", "trade", "improve", "mortgage", "unmortgage", "bankrupt", "assets", "all", "save"};

        // checks if the # of players are < 2 
        if (currPlayerNum < 2) {
            cout << "Congratulations " << players[0]->getName << " you are the winner! The game is now over" << endl; 
        }

        // stores the line of input into a vector 'commands'
        getline(cin, input);
        istringstream iss{input};
        while(iss >> cmd) {
            commands.emplaceback(cmd);
        }

        if (commands.size() < 1) { // user needs to enter command again
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
                
                break;
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

vector<Player*> Board::getPlayers() {
    return players;
}

void Board::setTestingMode() {

}