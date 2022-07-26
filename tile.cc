#include <iostream>
#include "tile.h"
#include "board.h"
#include <string>
#include <memory>
#include "player.h"
#include <vector>

using namespace std;

Tile::Tile(string name, bool ownable, bool improvable, int position, int price, shared_ptr<Board> board) : impl{make_shared<TileImpl>()} {
    //impl->theBoard = board;
    impl->owner = nullptr;
    impl->name = name;
    impl->ownable = ownable;
    impl->improvable = improvable; 
    impl->mortgaged = false;
    impl->pos = position;
    impl->purchase = price;
    impl->theBoard = board;
}

Tile::~Tile() {}

std::shared_ptr<Player> Tile::getOwner() {
    return impl->owner;
}

shared_ptr<Board> Tile::getBoard(){
    return impl->theBoard;
}

void Tile::setOwner(std::shared_ptr<Player> player) {
    impl->owner = player;
}

int Tile::getPos() {
    return impl->pos;
}

int Tile::getPrice() {
    return impl->purchase;
}

string Tile::getName() {
    return impl->name;
}

bool Tile::isImprovable() {
    return impl->improvable;
}

bool Tile::isOwnable() {
    return impl->ownable;
}

bool Tile::isMortgaged() {
    return impl->mortgaged; 
}

bool Tile::isOwned() {
    if (impl->owner == nullptr) return false;
    else return true;
}

void Tile::auction() {
    cout << "We are now auctioning the building " << getName() << "." << endl;
    if (isImprovable()) {
        setImprovement(0);
    }

    vector<shared_ptr<Player>> players = getBoard()->getPlayers();
    vector<bool> withdraw;
    int playersCount = players.size();
    const int numOfPlayers = players.size();
    int currIndex = 0;
    int currBid = 0;
    string response;

    for (int i = 0; i < playersCount; i++) {
        withdraw.emplace_back(false);
    }

    while (true) {
        if (playersCount == 1) {
            break;
        }
        cout << "The current bid on the building is $" << currBid << "." << endl;

        while (true) {
            if (players[currIndex]->getBankruptStatus()) {
                cout << players[currIndex]->getName() << ", you are bankrupt so you can't participate in the auction." << endl;
                playersCount--;
                withdraw[currIndex] = true;
                break;
            }

            if (players[currIndex]->getMoney() <= currBid) {
                cout << players[currIndex]->getName() << ", you do not have enough money to continue participating in the bid. \nYou will now be removed from the auction." << endl;
                playersCount--;
                withdraw[currIndex] = true;
                break;
            }

            cout << "\nIt is now " << players[currIndex]->getName() << "'s turn to bid.\nPlease enter 'withdraw' to withdraw from the auction or 'bid' to bid. ";
            cin >> response;

            if (response == "withdraw") {
                playersCount--;
                withdraw[currIndex] = true;
                break;
            } else if (response == "bid") {
                cout << "Enter how much you'd like to bid: ";
                string bidStr;
                cin >> bidStr;
                try {
                    int newBid = stoi(bidStr);
                    if (newBid > players[currIndex]->getMoney()) {
                        cout << "You do not have enough money to bid $" << newBid << "." << endl;
                        continue;
                    }
                    if (newBid <= currBid) {
                        cout << "Your new bid needs to be higher than the current bid." << endl;
                        continue;
                    }
                    currBid = newBid;
                    break;
                }  catch (invalid_argument &ia) {
                    cout << "Invalid bid. Enter a valid command." << endl;
                    continue;
                }

            } else {
                cout << "Invalid command. Enter 'withdraw' or 'bid'." << endl;
            }
        }
        
        if (playersCount <= 1) {
            continue;
        }
        
        currIndex = (currIndex + 1) % numOfPlayers;
        while (withdraw[currIndex]) {
            currIndex = (currIndex + 1) % numOfPlayers;
        }
        cout << currIndex << endl;
        
    }

    int winnerIndex = 0;
    playersCount = players.size();

    for (int i = 0; i < playersCount; i++) {
        if (withdraw[i] == false) {
            winnerIndex = i;
            break;
        }
    }
    
    cout << "Congrats " << players[winnerIndex]->getName() << "! You have won the auction :) You've purchased " << getName() << " for $" << currBid << "." << endl;
    players[winnerIndex]->subtractMoney(currBid);
    vector<shared_ptr<Tile>> boardTiles = getBoard()->getTiles();
    int currPos = getPos();
    players[winnerIndex]->addTile(boardTiles[currPos]);
    setOwner(players[winnerIndex]);
}

void Tile::mortgage(shared_ptr<Player> player) {
    int purchase = getPrice();
    cout << "You receive $" << purchase / 2 << " from mortgaging " << getName() << endl;
    player->addMoney(purchase / 2);
    impl->mortgaged = true;
}

void Tile::unmortgage(shared_ptr<Player> player) {
    int purchase = getPrice();
    cout << "You pay $" << purchase/2 << " + " << purchase*0.1 << " to unmortgage your property" << getName() <<  endl;
    player->subtractMoney(purchase*0.6);
    impl->mortgaged = false;
    
}

void Tile::setMortgaged(bool status) {
    impl->mortgaged = status;
}

void Tile::action(std::shared_ptr<Player> player){}
int Tile::getImprovement(){ return 0; }
void Tile::setImprovement(int x){}
int Tile::getImproveCost(){ return 0; }
std::string Tile::getMonopolyName(){ return "N/A"; }
void Tile::improveBuy(std::shared_ptr<Player> player){}
void Tile::improveSell(std::shared_ptr<Player> player){}
