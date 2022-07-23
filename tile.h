#ifndef __TILE_H_
#define __TILE_H_
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "tileimpl.h"

class Player;
class Board;
//class TileImpl;

class Tile {
    std::shared_ptr<TileImpl> impl;
public:
    Tile();
   //Tile(std::string name, std::string monopolyBlock, int position, int cost, 
   // Player * owner, int improvement_level, bool ownable, bool improvable);
    virtual ~Tile();    
    std::shared_ptr<TileImpl> getImpl();
    virtual std::shared_ptr<Player> getOwner() = 0;
    virtual void setOwner(std::shared_ptr<Player> player) = 0;
    virtual int getImprovement() = 0; // returns the improvement #
    virtual void setImprovement(int x) = 0;
    virtual void action(std::shared_ptr<Player> player) = 0;
    virtual void mortgage(std::shared_ptr<Player> player) = 0;
    virtual void auction() = 0;
    virtual bool isMortgaged() = 0;
    virtual bool isOwned() = 0;
    virtual int getPos() = 0;
    virtual int getPrice() = 0;
    virtual std::string getName() = 0;
    virtual void improveBuy(std::shared_ptr<Player> player) = 0;
    virtual void improveSell(std::shared_ptr<Player> player) = 0;
    virtual int getImproveCost() = 0;
    virtual std::string getMonopolyName() = 0;
    virtual void unmortgage(std::shared_ptr<Player> player) = 0;
};

#endif