#ifndef __GYMS_H__
#define __GYMS_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Gyms : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    Gyms(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~Gyms();
    void action(std::shared_ptr<Player> player) override;
};

#endif
