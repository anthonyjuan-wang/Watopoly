#ifndef __TILE_H_
#define __TILE_H_
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "tileimpl.h"

class Player;
class Board;
// class TileImpl;

class Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    Tile(Board* board, std::string name,
         bool ownable, bool improvable, int position, int price,
         int improvement, std::string block);
    virtual ~Tile();
 
    // General methods
    std::shared_ptr<TileImpl> getImpl();
    std::shared_ptr<Player> getOwner();
    void setOwner(std::shared_ptr<Player> player);
    int getPos();
    int getPrice();
    std::string getName();
    bool isImprovable();
    bool isOwnable();
    bool isMortgaged();
    bool isOwned();
    void auction();
    void mortgage(std::shared_ptr<Player> player);
    void unmortgage(std::shared_ptr<Player> player);
    virtual void action(std::shared_ptr<Player> player) = 0;
    // Academic methods
    virtual int getImprovement() = 0;
    virtual void setImprovement(int x) = 0;
    virtual void improveBuy(std::shared_ptr<Player> player) = 0;
    virtual void improveSell(std::shared_ptr<Player> player) = 0;
    virtual int getImproveCost() = 0;
    virtual std::string getMonopolyName() = 0;

    
};

#endif