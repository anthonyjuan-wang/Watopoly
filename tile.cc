#include <iostream>
#include "tile.h"
#include "board.h"
#include <string>
#include <memory>
#include "player.h"
#include <vector>

using namespace std;

Tile::Tile(string name, bool ownable, bool improvable, int position, int price, vector<shared_ptr<Tile>> board) : impl{make_shared<TileImpl>()} {
    //impl->theBoard = board;
    impl->owner = nullptr;
    impl->name = name;
    impl->ownable = ownable;
    impl->residence = false;
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

vector<shared_ptr<Tile>> Tile::getBoard(){
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

bool Tile::isResidence() {
    return impl->residence;
}

bool Tile::isMortgaged() {
    return impl->mortgaged; 
}

bool Tile::isOwned() {
    if (impl->owner == nullptr) return false;
    else return true;
}

void Tile::auction() {

}

void Tile::mortgage(shared_ptr<Player> player) {
    int purchase = getPrice();
    cout << "You receive " << purchase << "$ from mortgaging " << getName() << endl;
    player->addMoney(purchase / 2);
    impl->mortgaged = true;
}

void Tile::unmortgage(shared_ptr<Player> player) {
    int purchase = getPrice();
    cout << "You pay " << purchase/2 << "$ + " << purchase*0.1 << "to unmortgage your property" << getName() <<  endl;
    player->subtractMoney(purchase*0.6);
    impl->mortgaged = false;
    
}

void Tile::action(std::shared_ptr<Player> player){}
int Tile::getImprovement(){ return -1; }
void Tile::setImprovement(int x){}
int Tile::getImproveCost(){ return -1; }
std::string Tile::getMonopolyName(){ return "noMonopoly"; }
void Tile::improveBuy(std::shared_ptr<Player> player){}
void Tile::improveSell(std::shared_ptr<Player> player){}
