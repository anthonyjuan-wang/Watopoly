#include <iostream>
#include "tile.h"
#include "board.h"
#include <string>
#include <memory>

using namespace std;

Tile::Tile() {}
Tile::~Tile() {}

Tile::Tile(Board* board, string name, bool ownable, bool improvable, int position, int price) : impl{make_shared<TileImpl>()}{
    impl->theBoard = board;
    impl->owner = nullptr;
    impl->name = name;
    impl->ownable = ownable;
    impl->improvable = improvable; 
    impl->mortgaged = false;
    impl->pos = position;
    impl->cost = price;
}

std::shared_ptr<Player> Tile::getOwner(){
    return impl->owner;
}

void Tile::setOwner(std::shared_ptr<Player> player){
    impl->owner = player;
}

int Tile::getPos(){
    return impl->pos;
}

int Tile::getPrice(){
    return impl->cost;
}

string Tile::getName(){
    return impl->name;
}

bool Tile::isImprovable(){
    return impl->improvable;
}

bool Tile::isOwnable(){
    return impl->ownable;
}

bool Tile::isMortgaged(){
    return impl->mortgaged; 
}

bool Tile::isOwned(){
    if (impl->owner == nullptr) return false;
    else return true;
}

void Tile::auction(){

}

void Tile::mortgage(shared_ptr<Player> player){
    int cost = getPrice();
    cout << "You receive " << cost << "$ from mortgaging " << getName();
    player->addMoney(cost / 2);

}






