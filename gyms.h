#ifndef __GYMS_H__
#define __GYMS_H__
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include <vector>
class Player;
class Board;

class Gyms : public Tile
{
    std::shared_ptr<TileImpl> impl;
    
public:
    Gyms(int position, std::string blockName, std::shared_ptr<Board> board);
    ~Gyms();
    std::vector<int> rollDice();
    void action(std::shared_ptr<Player> player) override;
};

#endif
