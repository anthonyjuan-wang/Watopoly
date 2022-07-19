#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class GooseNesting : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    GooseNesting(int position, std::string blockName);
    ~GooseNesting();

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
