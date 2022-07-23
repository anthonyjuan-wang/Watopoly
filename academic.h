#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
#include "tile.h"
#include "tileimpl.h"
class Player;
class Board;

class Academic : public Tile {
    std::string monopoly;
    int improvement;
    std::vector<int> tuition;

public:
    Academic(int position, std::string blockName, std::string monopolyType, int purchaseCost, int improvementCost,
             std::vector<int> tuitionWithExpenses);
    ~Academic();

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
