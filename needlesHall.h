#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include "tile.h"
#include <string>
#include <memory>
#include <vector>
class NeedlesHall : public Tile
{

    std::shared_ptr<TileImpl> impl;

public:
    NeedlesHall(int position, std::string blockName, std::shared_ptr<Board> board, std::vector<std::shared_ptr<Tile>> boardTiles);
    ~NeedlesHall();

    void action(std::shared_ptr<Player> player) override;
};

#endif
