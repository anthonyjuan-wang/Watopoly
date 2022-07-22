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
     
    std::shared_ptr<TileImpl> getImpl() override;
    std::shared_ptr<Player> getOwner() override;
    virtual void setOwner(std::shared_ptr<Player> player) override;
    virtual int getImprovement() override; // returns the improvement #
    virtual void setImprovement(int x) override;
    virtual void action(std::shared_ptr<Player> player) override;
    virtual void mortgage(std::shared_ptr<Player> player) override;
    virtual void auction() override;
    virtual bool isMortgaged() override;
    virtual bool isOwned() override;
    virtual int getPos() override;
    virtual int getPrice() override;
    virtual std::string getName() override;
    void improveBuy(std::shared_ptr<Player> player) override;
    void improveSell(std::shared_ptr<Player> player) override;
    int getImproveCost() override;
    std::string getMonopolyName() override;
    void unmortgage(std::shared_ptr<Player> player) override;
};

#endif
