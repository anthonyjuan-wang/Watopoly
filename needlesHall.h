#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include "tile.h"
#include <string>
#include <memory>
class NeedlesHall : public Tile
{

    std::shared_ptr<TileImpl> impl;

public:
    NeedlesHall(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~NeedlesHall();

    void action(std::shared_ptr<Player> player) override;
};

#endif
