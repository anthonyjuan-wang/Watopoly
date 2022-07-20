#include <iostream>
#include <vector>
#include <string>

#ifndef __TILE_H_
#define __TILE_H_

class Player;
class Board;

class TileImpl;

class Tile {
public:

    Tile();
    virtual ~Tile();
    virtual Board *getBoard() = 0;
    virtual Player *getOwner() = 0;
    virtual void setOwner(Player *player) = 0;
    virtual int getImprovement() = 0;
    virtual void setImprovement(int x) = 0;
    virtual void action(Player *player) = 0;
    virtual void mortgage(Player *player) = 0;
    virtual void auction() = 0;
    virtual bool isMortgaged() = 0;
    virtual bool isOwned() = 0;
    virtual int getPos() = 0;
    virtual int getPrice() = 0;

};

#endif