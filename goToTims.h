#include "tile.h"
#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
class Player;
class Board;

class GoToTims : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    GoToTims(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~GoToTims();
    
    void action(std::shared_ptr<Player> player) override;
   
};

#endif
