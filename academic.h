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
             std::vector<int> tuitionWithExpenses, std::vector<std::shared_ptr<Tile>> board);
    ~Academic();

    void action(std::shared_ptr<Player> player) override;
};

#endif
