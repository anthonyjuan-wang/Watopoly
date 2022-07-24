#ifndef __TUITION_H__
#define __TUITION_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Tuition : public Tile {

    std::shared_ptr<TileImpl> impl;

public:
    Tuition(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~Tuition();
    void action(std::shared_ptr<Player> player) override;
};

#endif
