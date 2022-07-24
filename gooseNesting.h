#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
class Player;
class Board;

class GooseNesting : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    GooseNesting(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~GooseNesting();
    void action(std::shared_ptr<Player> player) override;
};

#endif
