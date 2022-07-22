#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
#include "tile.h"
#include "tileimpl.h"
class Player;
class Board;

class Academic : public Tile {

    std::shared_ptr<TileImpl> impl;

public:
    Academic(int position, std::string blockName, std::string monopolyType, int purchaseCost, int improvementCost,
             std::vector<int> tuitionWithExpenses);
    ~Academic();

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
    virtual void improveBuy(std::shared_ptr<Player> player);
    virtual void improveSell(std::shared_ptr<Player> player);
    virtual int getImproveCost();
    virtual std::string getMonopolyName();
};

#endif
