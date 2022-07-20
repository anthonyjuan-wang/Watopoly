#include <iostream>
#include "tile.h"
#include <string>

using namespace std;

struct TileImpl {
    Board *theBoard;
    Player *Owner;
    std::string name;
    bool isOwnable;
    bool isImprovable;
    int pos;
    int cost;
};

Tile::Tile(string name, int pos) : name{name}, pos{pos} {}

/*
virtual Tile::Board *getBoard() {

}

virtual Tile::Player *getOwner() {

}
void virtual Tile::setOwner(Player *player) {

}

void virtual Tile::getImprovement() {

}

void virtual Tile::setImprovement(int x) {

}

void virtual Tile::action(Player *player) {

}

void virtual Tile::mortgage(Player *player) {

}

void virtual Tile::auction() {
    
}

bool virtual Tile::isMortgaged() {

}

bool virtual Tile::isOwned() {

}

int virtual Tile::getPos() {

}

int virtual Tile::getPrice() {

}
*/

Tile::~Tile() {}
