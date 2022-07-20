#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
#include "tile.h"
#include <memory>
#include <string>
class Player;
class Board;

class DcTimsLine : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    DcTimsLine(int position, std::string blockName);
    ~DcTimsLine();

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
