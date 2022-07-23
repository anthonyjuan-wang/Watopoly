#ifndef __RESIDENCES_H__
#define __RESIDENCES_H__
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include <vector>
class Player;
class Board;

class Residences : public Tile {
    
    std::shared_ptr<TileImpl> impl;

public:
    Residences(int position, std::string blockName);
    ~Residences();
    void action(std::shared_ptr<Player> player) override;

    // std::shared_ptr<TileImpl> getImpl() override;
    // std::shared_ptr<Player> getOwner() override;
    // void setOwner(std::shared_ptr<Player> player) override;
    // int getImprovement() override; // returns the improvement #
    // void setImprovement(int x) override;
    // void mortgage(std::shared_ptr<Player> player) override;
    // void auction() override;
    // bool isMortgaged() override;
    // bool isOwned() override;
    // int getPos() override;
    // int getPrice() override;
    // std::string getName() override;
    // void improveBuy(std::shared_ptr<Player> player) override;
    // void improveSell(std::shared_ptr<Player> player) override;
    // int getImproveCost() override;
    // std::string getMonopolyName() override;
    // void unmortgage(std::shared_ptr<Player> player) override;
};

#endif
