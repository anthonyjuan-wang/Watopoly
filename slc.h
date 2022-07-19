#ifndef __SLC_H__
#define __SLC_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Slc : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    Slc(int position, std::string blockPosition);
    ~Slc();

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
