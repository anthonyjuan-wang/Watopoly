#ifndef __OSAP_H__
#define __OSAP_H__
#include <string>
#include <memory>
#include "tile.h"
#include "player.h"
#include "board.h"
class TileImpl;

class Osap : public Tile {
    std::shared_ptr<TileImpl> impl;

public:
    Osap(int position, std::string str, std::shared_ptr<Board> board);
    ~Osap();

    void action(std::shared_ptr<Player> player) override;
};

#endif
