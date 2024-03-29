#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include "tile.h"
#include <memory>
#include <string>
class Player;
class Board;

class GoToTims : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    GoToTims(int position, std::string blockName, std::shared_ptr<Board> board);
    ~GoToTims();
    
    void action(std::shared_ptr<Player> player) override;
   
};

#endif
