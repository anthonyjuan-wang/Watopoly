#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include "tile.h"
#include <memory>
class Player;
class Board;

class GoToTims : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    GoToTims(int position, std::string blockName);
    ~GoToTims();
<<<<<<< HEAD

    std::shared_ptr<TileImpl> getImpl() override;
    std::shared_ptr<Player> getOwner() override;
    void setOwner(std::shared_ptr<Player> player) override;
    int getImprovement() override; // returns the improvement #
    void setImprovement(int x) override;
    void action(std::shared_ptr<Player> player) override;
    void mortgage(std::shared_ptr<Player> player) override;
    void auction() override;
    bool isMortgaged() override;
    bool isOwned() override;
    int getPos() override;
    int getPrice() override;
    std::string getName() override;
    void improveBuy(std::shared_ptr<Player> player) override;
    void improveSell(std::shared_ptr<Player> player) override;
    int getImproveCost() override;
    std::string getMonopolyName() override;
    void unmortgage(std::shared_ptr<Player> player) override;
=======
    
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
>>>>>>> main
};

#endif
