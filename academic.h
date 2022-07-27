#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
#include "tile.h"
#include "tileimpl.h"
class Player;
class Board;

class Academic : public Tile {
    std::string monopoly;
    int improvementCost;
    std::vector<int> tuition;
    int improvementNum;

public:
    Academic(int position, std::string blockName, std::string monopolyType, int purchaseCost, int improvementCost, int improvementNum,
             std::vector<int> tuitionWithExpenses, std::shared_ptr<Board> board);
    ~Academic();

    virtual int getImprovement() override;
    virtual void setImprovement(int x) override;
    virtual int getImproveCost() override;
    virtual std::string getMonopolyName() override;
    virtual void improveBuy(std::shared_ptr<Player> player) override;
    virtual void improveSell(std::shared_ptr<Player> player) override;
    void action(std::shared_ptr<Player> player) override;
    
};

#endif
