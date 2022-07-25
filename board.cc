#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include "board.h"
#include "player.h"
#include "academic.h"
#include "coop.h"
#include "dcTimsLine.h"
#include "gooseNesting.h"
#include "goToTims.h"
#include "gyms.h"
#include "needlesHall.h"
#include "osap.h"
#include "residences.h"
#include "slc.h"
#include "tuition.h"

using namespace std;

Board::Board() {}

Board::~Board() {}

std::vector<std::shared_ptr<Tile>> Board::getTiles(){
    return board;
}

void Board::loadGame(string input){
    ifstream loadedFile;
    string line;
    getline(loadedFile, line);
    int numPlayers = stoi (line);
    if (numPlayers < 2 || numPlayers > 8){
        throw invalid_argument("")
    }    


}
void Board::saveGame(string fileName, int index){
    ofstream file;
    file.open(fileName);
    int num = players.size();
    file << num << endl;
    string s = "";

    // save players & information
    for (int i = 0; i < num; i++){
        shared_ptr<Player> player = players [ (index+i) % num ];
        string playerInfo = "";
        playerInfo += player->getName() + " ";
        playerInfo += player->getPiece() + " ";
        s = to_string(player->getRollUpCount());
        playerInfo += s + " ";
        s = to_string (player->getMoney());
        playerInfo += s + " ";
        s = to_string (player->getPos());
        playerInfo += s + " ";
        if (player->getPos() == jailPos){
            if (player->getJailStatus() == true){
                    s = to_string (player->getJailCount());
                    playerInfo += "1 " + s;
            } else playerInfo += "0";
        }  file << playerInfo << endl;
    }
        // save Buildings and owners, by looping through academic squares 
        for (unsigned int i = 0; i < board.size(); i++ ){
            shared_ptr<Tile> tile = board[i];
            string tileInfo = "";
            tileInfo += tile->getName();
            if (tile->isOwnable()){
                if (tile->getOwner()){
                    tileInfo += " " + tile->getOwner()->getName();  
                }   
                else{
                     tileInfo += " BANK";
                }
                if (tile->isMortgaged()){
                    tileInfo += " -1";
                }  
                 else if (tile->isImprovable() == false){
                    tileInfo += " 0";
                }
                    tileInfo += " " + to_string(tile->getImprovement());
            }
        }
}



void Board::setTestingMode(){
    
}

void Board::trade(std::vector<std::string> commands, int currPlayerIndex) {
    int otherPlayerIndex = -1;
    int size = players.size();
    int give = -1;
    int receive = -1;

    for (int i = 0; i < size; i++) {
        if(players[i]->getName() == commands[1]) {
            otherPlayerIndex = i;
            break;
        }
    }

    if (otherPlayerIndex == -1) {
        cout << "The player, " << commands[1] << ", you want to trade with doesn't exist" << endl;
        return;
    }

    if (players[currPlayerIndex]->getName() == players[otherPlayerIndex]->getName()) {
        cout << "You can't trade with yourself" << endl;
        return;
    }

    shared_ptr<Player> currPlayer = players[currPlayerIndex];
    shared_ptr<Player> otherPlayer = players[otherPlayerIndex];

    try {
        give = stoi(commands[2]);
    } catch (exception &error) {}

    try {
        receive = stoi(commands[3]);
    } catch (exception &error) {}

    if (give > -1 && receive > -1) {
        cout << "Invalid command. You cannot trade money for money" << endl;
    }

    // giving away tile and receiving money
    if (receive > -1) {
        string giveBuilding = commands[2];
        string s{};
        int tilePos = -1;

        vector<shared_ptr<Tile>> ownedTiles = currPlayer->getTiles();
        size = ownedTiles.size();
        for (int i = 0; i < size; i++) {
            s = ownedTiles[i]->getName();
            if (s == giveBuilding) {
                tilePos = ownedTiles[i]->getPos();
                break;
            }
        }

        if (tilePos == -1) {
            cout << "You don't own the building " << giveBuilding << "." << endl;
        }
        
        if (board[tilePos]->isImprovable()) {
            string monopoloyName = board[tilePos]->getMonopolyName();
            for (int i = 0; i < numSquares; i++) {
                if (monopoloyName == board[i]->getMonopolyName() && board[i]->getImprovement() > 0) {
                    cout << giveBuilding << " is in a monopoly and one of the buildings in the monopoly has improvements." << endl;
                    cout << "Therefore, you can't trade " << giveBuilding << "." << endl;
                    return;
                } 
            }
        }

        if (otherPlayer->getMoney() < receive) {
            cout << otherPlayer->getName() << " does not have enough money to trade." << endl;
            return;
        }

        string response;
        cout << otherPlayer->getName() << " would you like to accept the trade? Enter 'accept' to accept and any other word to decline." << endl;
        cin >> response;

        if (response != "accept") {
            cout << otherPlayer->getName() << " has rejected the trade." << endl;
            return;
        }
        currPlayer->transferProp(otherPlayer, board[tilePos]);
        otherPlayer->subtractMoney(receive);
        currPlayer->addMoney(receive);
        return;
    } else if (give > -1) {
        // give money and receive a building
        string receiveBuilding = commands[3];
        string s{};
        int tilePos = -1;
        
        vector<shared_ptr<Tile>> otherOwnedTiles = otherPlayer->getTiles();
        size = otherOwnedTiles.size();
        for (int i = 0; i < size; i++) {
            s = otherOwnedTiles[i]->getName();
            if (s == receiveBuilding) {
                tilePos = otherOwnedTiles[i]->getPos();
                break;
            }
        }

        if (tilePos == -1) {
            cout << otherPlayer->getName() << " doesn't own the building " << receiveBuilding << "." << endl;
            return;
        }

        if (board[tilePos]->isImprovable()) {
            string monopoloyName = board[tilePos]->getMonopolyName();
            for (int i = 0; i < numSquares; i++) {
                if (monopoloyName == board[i]->getMonopolyName() && board[i]->getImprovement() > 0) {
                    cout << receiveBuilding << " is in a monopoly and one of the buildings in the monopoly has improvements." << endl;
                    cout << "Therefore, you can't trade " << receiveBuilding << "." << endl;
                    return;
                } 
            }
        }

        if (currPlayer->getMoney() < give) {
            cout << currPlayer->getName() << " does not have enough money to trade." << endl;
            return;
        }

        string response;
        cout << otherPlayer->getName() << " would you like to accept the trade? Enter 'accept' to accept and any other word to decline." << endl;
        cin >> response;

        if (response != "accept") {
            cout << otherPlayer->getName() << " has rejected the trade." << endl;
            return;
        }
        otherPlayer->transferProp(currPlayer, board[tilePos]); // other player transfer prop to currPlayer
        currPlayer->subtractMoney(receive);
        otherPlayer->addMoney(receive);
        return;
    } else {
        // trade square for square
        string giveBuilding = commands[2];
        string receiveBuilding = commands[3];
        string s{};
        int currPlayerPos = -1;
        int otherPlayerPos = -1;
        
        // check if currPlayer and otherPlayer own the buildings
        vector<shared_ptr<Tile>> ownedTiles = currPlayer->getTiles();
        size = ownedTiles.size();
        for (int i = 0; i < size; i++) {
            s = ownedTiles[i]->getName();
            if (s == giveBuilding) {
                currPlayerPos = ownedTiles[i]->getPos();
                break;
            }
        }

        vector<shared_ptr<Tile>> otherOwnedTiles = otherPlayer->getTiles();
        size = otherOwnedTiles.size();
        for (int i = 0; i < size; i++) {
            s = otherOwnedTiles[i]->getName();
            if (s == receiveBuilding) {
                otherPlayerPos = otherOwnedTiles[i]->getPos();
                break;
            }
        }

        if (currPlayerPos == -1) {
            cout << currPlayer->getName() << " doesn't own the building " << giveBuilding << "." << endl;
        }

        if (otherPlayerPos == -1) {
            cout << otherPlayer->getName() << " doesn't own the building " << receiveBuilding << "." << endl;
        }

        // check if the building's monopoly have improvements (if they do, trade cancelled)
        if (board[currPlayerPos]->isImprovable()) {
            string monopoloyName = board[currPlayerPos]->getMonopolyName();
            for (int i = 0; i < numSquares; i++) {
                if (monopoloyName == board[i]->getMonopolyName() && board[i]->getImprovement() > 0) {
                    cout << giveBuilding << " is in a monopoly and one of the buildings in the monopoly has improvements." << endl;
                    cout << "Therefore, you can't trade " << giveBuilding << "." << endl;
                    return;
                } 
            }
        }

        if (board[otherPlayerPos]->isImprovable()) {
            string monopoloyName = board[otherPlayerPos]->getMonopolyName();
            for (int i = 0; i < numSquares; i++) {
                if (monopoloyName == board[i]->getMonopolyName() && board[i]->getImprovement() > 0) {
                    cout << receiveBuilding << " is in a monopoly and one of the buildings in the monopoly has improvements." << endl;
                    cout << "Therefore, you can't trade " << receiveBuilding << "." << endl;
                    return;
                } 
            }
        }

        string response;
        cout << otherPlayer->getName() << " would you like to accept the trade? Enter 'accept' to accept and any other word to decline." << endl;
        cin >> response;

        if (response != "accept") {
            cout << otherPlayer->getName() << " has rejected the trade." << endl;
            return;
        }
        currPlayer->transferProp(otherPlayer, board[currPlayerPos]);
        otherPlayer->transferProp(currPlayer, board[otherPlayerPos]);
        return;
    }
}

std::vector<std::shared_ptr<Player>> Board::getPlayers(){
    return players;
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
        while (true) {
            cout << "Hi Player " << i << " enter your name: ";
            cin >> playerName;
        
            // check if the playerName already exists
            if (playerName == "Bank") {
                cout << "This name is not valid." << endl;
                continue;
            }
            bool nameTaken = false;
            int size = players.size();
            for (int j = 0; j < size; j++) {
                if (players[j]->getName() == playerName) {
                    cout << "This name has already been taken." << endl;
                    nameTaken = true;
                    break;
                }
            }
            
            if (nameTaken == false) {
                break;
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
                if (pieces[j][0] == playerPiece)
                {
                    pieceFound = true;
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
        shared_ptr<Player> person = make_shared<Player>(playerName, playerPiece, 1500, 0);
        players.emplace_back(person);
    }
}


void Board::play() {
    int playersCount = 0;
    int currPlayerIndex = 0;

    // ask the user for the number of players
    while (true) {
        cout << "How many players are there? ";
        cin >> playersCount;

        if (playersCount >= 2 && playersCount <= 8) {
            init(playersCount);
            break;
        }
        else {
            cout << "The number of players you entered is invalid" << endl;
        }
    }
    
    //print();
    // play game - continues until there are > 2 players
    while (true) {
        shared_ptr<Player> currPlayer = players[currPlayerIndex];
        string input{};
        string cmd;
        vector<string> commands{};
        vector<string> cmdInterpreter = {
            "roll", "\n",
            "next", "\n",
            "trade <name> <give> <receive>", "\n",
            "improve <property> buy/sell", "\n",
            "mortgage <property>", "\n",
            "unmortgage <property>", "\n",
            "bankrupt", "\n",
            "assets", "\n",
            "all", "\n",
            "save <filename>"
        };

        // checks if the # of players are < 2
        if (playersCount < 2) {
            cout << "Congratulations " << players[0]->getName() << " you are the winner! The game is now over" << endl;
            break;
        }
    
        // outputs the possible user commands
        if (isTurnOver == false) {
            cout << "It is " << currPlayer->getName() << "'s turn. Enter a command from the following: " << endl;
            for (auto i : cmdInterpreter) {
               //cout << i << endl;
               cout << i;
            }
            cout << endl;
        }
        // ADDED SPACES HERE
        cout << "\n\n\n\n\n\n\n\n\n";

        // stores the line of input into a vector 'commands'
        getline(cin, input);
        istringstream iss{input};
        while (iss >> cmd) {
            commands.emplace_back(cmd);
        }
        
        if (commands.size() < 1) { // user needs to enter command again
            cout << "Please enter a non-empty command" << endl;
            continue;
        }
        
        // switch to check all the possible player command inputs
        if (commands[0] == "roll") {
            if(isTurnOver == true) {
                cout << "You cannot roll, your turn is over." << endl;
                continue;
            }
            // checks if your in jail
            vector<int> dice = rollDice();
            if (currPlayer->getJailStatus() == true) {
                if (dice[1] != dice[2]) {
                    cout << "You rolled " << dice[0] << " and " << dice[1] << endl;
                    cout << "You did not roll doubles so you are still in jail. Here are your options:" << endl;
                    board[jailPos]->action(currPlayer);
                    if (currPlayer->getJailStatus() == true){
                        isTurnOver = true;
                        continue;
                    }
                } else { 
                    currPlayer->setJailCount(0);
                    currPlayer->setJailStatus(false);
                }
            } 

            int total = currPlayer->getPos() + dice[0] + dice[1];
            currPlayer->move(total);
            int pos = currPlayer->getPos();

            cout << "You rolled " << dice[0] << " and " << dice[1] << endl;
            cout << "You just landed on " << board[pos]->getName() << endl;

            if (pos != osapPos && pos != goToJailPos) {
                // add $200 if you pass osap
                if (total > 40 && currPlayer->getJailStatus() == false) {
                    currPlayer->addMoney(200);
                }
                board[pos]->action(currPlayer);
                
                if (currPlayer->getJailStatus() == true) {
                    isTurnOver = true;
                    continue;
                }
            } else if (pos == osapPos) {
                currPlayer->addMoney(200);
            } else if (pos == goToJailPos) {
                currPlayer->setPos(jailPos);
                currPlayer->setJailStatus(true);
                currPlayer->setJailCount(0);
                isTurnOver = true;
                continue;
            }

            // check if the player is almostBankrupt or Bankrupt
            if (currPlayer->getAlmostBankruptStatus() == true) {
                // ADD CODE - NOT FINISHED
            }

            if (currPlayer->getBankruptStatus() == true) {
                // ADD CODE - NOT FINISHED
                isTurnOver = true;
            }

            if (dice[0] != dice[1] || currPlayer->getJailStatus() || currPlayer->getBankruptStatus()) { // idk if the last two checks are needed
                cout << currPlayer->getName() << ", your turn is now finished. Please enter 'next'." << endl;
                // ADDED SPACES HERE
                cout << "\n\n\n\n\n\n\n\n\n";
                doubles = 0;
                isTurnOver = true;
                //print();
            } else {
                doubles++;

                if (doubles == 3) {
                    cout << "You have rolled 3 doubles. You are now going to jail." << endl;
                    currPlayer->setPos(jailPos);
                    currPlayer->setJailStatus(true);
                    currPlayer->setJailCount(0);
                    doubles = 0;
                    isTurnOver = true;
                }
                else {
                    cout << "You have rolled doubles. It is your turn again." << endl;
                }
            }
            //print();
        } else if (commands[0] == "next") {
            if (currPlayer->getBankruptStatus() == true) {
                cout << "You are bankrupt. The next command you need to type is 'bankrupt'." << endl;
                continue;
            }

            if (isTurnOver != true) {
                cout << "You still need to roll. You cannot give control to the next player." << endl;
            }
            else {
                
                cout << currPlayer->getName() << ", your turn is now finished." << endl;
                // ADDED SPACES HERE
                cout << "\n\n\n\n\n\n\n\n\n";
                doubles = 0;
                currPlayerIndex = (currPlayerIndex + 1) % playersCount;
                isTurnOver = false;
                print();
            }
        } else if (commands[0] == "trade" && commands.size() == 4) {
            if (currPlayer->getBankruptStatus() == true) {
                cout << "You are bankrupt. The next command you need to type is 'bankrupt'." << endl;
                continue;
            }

            trade(commands, currPlayerIndex);
        } else if (commands[0] == "improve" && commands.size() == 3) {
            if (currPlayer->getBankruptStatus() == true) {
                cout << "You are bankrupt. The next command you need to type is 'bankrupt'." << endl;
                continue;
            }

            string s{};
            int pos = -1;

            vector<shared_ptr<Tile>> ownedTiles = currPlayer->getTiles();
            int size = ownedTiles.size();
            for (int i = 0; i < size; i++) {
                s = ownedTiles[i]->getName();
                if (s == commands[1]) {
                    pos = ownedTiles[i]->getPos();
                    break;
                }
            }

            if (pos == -1) {
                cout << "You can't improve this building. Please enter another comand" << endl;
                continue;
            }

            if (commands[2] == "buy") {
                if (board[pos]->isMortgaged()) {
                    cout << "The building is mortgaged so it cannot be improved." << endl;
                    continue;
                }
                
                if (board[pos]->getImprovement() >= 5) {
                    cout << "The builidng already has 5 improvements." << endl;
                    continue;
                }
                
                if (!hasMonopoly(board[pos])) {
                    cout << "You don't own the monopoly so you can't improve the building." << endl;
                    continue;
                }
                
                cout << "The cost for the improvement is " << board[pos]->getImproveCost() << "." << endl;
                if (currPlayer->getMoney() < board[pos]->getImproveCost()) {
                    cout << "You don't have enough money to improve this building" << endl;
                    continue;
                }
                
                board[pos]->improveBuy(currPlayer);
            } else if (commands[2] == "sell") {
                if (board[pos]->getImprovement() <= 0) {
                    cout << "You don't have any improvements to sell." << endl;
                    continue;
                }
                board[pos]->improveSell(currPlayer); // GET HALF THE COST OF THE IMPROVEMENT BACK
            } else {
                cout << "This was an invalid command. Please enter another command" << endl;
            }
        } else if (commands[0] == "mortgage" && commands.size() == 2) {
            if (currPlayer->getBankruptStatus() == true) {
                cout << "You are bankrupt. The next command you need to type is 'bankrupt'." << endl;
                continue;
            }

            string s{};
            int pos = -1;

            vector<shared_ptr<Tile>> ownedTiles = currPlayer->getTiles();
            int size = ownedTiles.size();
            for (int i = 0; i < size; i++) {
                s = ownedTiles[i]->getName();
                if (s == commands[1]) {
                    pos = ownedTiles[i]->getPos();
                    break;
                }
            }

            if (pos == -1 || board[pos]->isMortgaged() || board[pos]->getImprovement() > 0) {
                cout << "You can't mortgage this building. Please enter another comand" << endl;
                continue;
            }

            board[pos]->mortgage(currPlayer);            
        } else if (commands[0] == "unmortgage" && commands.size() == 2) {
            if (currPlayer->getBankruptStatus() == true) {
                cout << "You are bankrupt. The next command you need to type is 'bankrupt'." << endl;
                continue;
            }
            
            string s{};
            int pos = -1;

            vector<shared_ptr<Tile>> ownedTiles = currPlayer->getTiles();
            int size = ownedTiles.size();
            for (int i = 0; i < size; i++) {
                s = ownedTiles[i]->getName();
                if (s == commands[1]) {
                    pos = ownedTiles[i]->getPos();
                    break;
                }
            }

            if (pos == -1  || board[pos]->isMortgaged() == false) {
                cout << "You can't unmortgage this building. Please enter another comand" << endl;
                continue;
            }

            board[pos]->unmortgage(currPlayer);
        } else if (commands[0] == "bankrupt") {
            if (currPlayer->getBankruptStatus() == true) {
                // check what tile the player is on and give the owner the properties/money
                // ADD THE CODE HERE
                
                cout << currPlayer->getName() << " you will now be removed from the game." << endl;
                playersCount--;
                players.erase(players.begin() + currPlayerIndex);
                
                cout << "It is now the next player's turn." << endl;
                doubles = 0;
                currPlayerIndex = (currPlayerIndex + 1) % playersCount;
                isTurnOver = false;
                print();
            } else {
                cout << "You can't declare bankrupcy" << endl;
            }
        } else if (commands[0] == "assets") {
            currPlayer->displayAssets();
        } else if (commands[0] == "all") {
            for (unsigned int i = 0; i < players.size(); i++) {
                players[i]->displayAssets();
                cout << endl;
            }
        } else if (commands[0] == "save" && commands.size() == 2) {
            //saveGame(commands[1]);
        }

        else {
            cout << "Please enter a valid command" << endl;
        }
    }
}

vector<int> Board::rollDice() {
    
    int die1 = (rand() % 6) + 1;
    int die2 = (rand() % 6) + 1;
    vector<int> dice = {die1, die2};
    return dice;
}


void Board::initTiles() {
    board.emplace_back(make_shared<Osap>(0, "Osap", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(1, "AL", "Arts1", 40, 50, 0, std::vector<int>{2, 10, 30, 90, 50, 150}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Slc>(2, "SLC", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(3, "ML", "Arts1", 60, 50, 0, vector<int>{4, 20, 60, 180, 320, 450}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Tuition>(4, "Tuition", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Residences>(5, "MKV", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(6, "ECH", "Arts2", 100, 50, 0, vector<int>{6, 30, 90, 270, 400, 550}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<NeedlesHall>(7, "Neeedles Hall", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(8, "PAS", "Arts2", 100, 50, 0, vector<int>{6, 30, 90, 270, 400, 550}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(9, "HH", "Arts2", 120, 50, 0, vector<int>{8, 40, 100, 300, 450, 600}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<DcTimsLine>(10, "DC Tims Line", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(11, "RCH", "Eng", 140, 100, 0, vector<int>{10, 50, 150, 450, 625, 750}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Gyms>(12, "PAC", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(13, "DWE", "Eng", 140, 100, 0, vector<int>{10, 50, 150, 450, 625, 750}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(14, "CPH", "Eng", 160, 100, 0, vector<int>{12, 60, 180, 500, 700, 900}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Residences>(15, "UWP", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(16, "LHI", "Health", 180, 100, 0, vector<int>{14, 70, 200, 550, 750, 950}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Slc>(17, "SLC", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(18, "BMH", "Health", 180, 100, 0, vector<int>{14, 70, 200, 550, 750, 950}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(19, "OPT", "Health", 200, 100, 0, vector<int>{16, 80, 220, 600, 800, 1000}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<GooseNesting>(20, "Goose Nesting", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(21, "EV1", "Env", 220, 150, 0, vector<int>{18, 90, 250, 700, 875, 1050}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<NeedlesHall>(22, "Needles Hall", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(23, "EV2", "Env", 220, 150, 0, vector<int>{18, 90, 250, 700, 875, 1050}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(24, "EV3", "Env", 240, 150, 0, vector<int>{20, 100, 300, 750, 925, 1100}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Residences>(25, "V1", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(26, "PHYS", "Sci1", 260, 150, 0, vector<int>{22, 110, 330, 800, 975, 1150}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(27, "B1", "Sci1", 260, 150, 0, vector<int>{22, 110, 330, 800, 975, 1150}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Gyms>(28, "CIF", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(29, "B2", "Sci1", 280, 150, 0, vector<int>{24, 120, 360, 850, 1025, 1200}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<GoToTims>(30, "Go To Tims", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(31, "EIT", "Sci2", 300, 200, 0, vector<int>{26, 130, 390, 900, 1100, 1275}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(32, "ESC", "Sci2", 300, 200, 0, vector<int>{26, 130, 390, 900, 1100, 1275}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Slc>(33, "SLC", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(34, "C2", "Sci2", 320, 200, 0, vector<int>{28, 150, 450, 1000, 1200, 1400}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Residences>(35, "REV", true, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<NeedlesHall>(36, "Needles Hall", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(37, "MC", "Math", 350, 200, 0, vector<int>{35, 175, 500, 1100, 1300, 1500}, shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Coop>(38, "Coop", shared_ptr<Board>(this)));
    board.emplace_back(make_shared<Academic>(39, "DC", "Math", 400, 200, 0, vector<int>{50, 200, 600, 1400, 1700, 2000}, shared_ptr<Board>(this)));
}

void Board::print() {

}

bool Board::hasMonopoly(std::shared_ptr<Tile> currTile) {
    string monopolyName = currTile->getMonopolyName();

    for (int i = 0; i < numSquares; i++) {
        if (board[i]->isImprovable()) {
            if (board[i]->getMonopolyName() == monopolyName && board[i]->getOwner() != currTile->getOwner()) {
                return false;
            }
        }
    }
    return true;
}

int Board::getRollUpCount() {
    return rollUpCount;
}

void Board::setRollUpCount(int n) {
    rollUpCount = n;
}
