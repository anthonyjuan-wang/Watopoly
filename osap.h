#ifndef __OSAP_H__
#define __OSAP_H__
#include <string>
#include <memory>
#include "tile.h"
class Player;
class Board;

class Osap : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    Osap(int position, std::string str);
    ~Osap();

    void action();
    TileImpl *getImpl;
     
    virtual TileImpl *getImpl();
    virtual Board *getBoard();
    virtual Player *getOwner();
    virtual void setOwner(Player *player);
    virtual int getImprovement(); // returns the improvement #
    virtual void setImprovement(int x);
    virtual void action(std::shared_ptr<Player> player);
    virtual void mortgage(Player *player);
    virtual void auction();
    virtual bool isMortgaged();
    virtual bool isOwned();
    virtual int getPos();
    virtual int getPrice();
    virtual std::string getName();
};

#endif
