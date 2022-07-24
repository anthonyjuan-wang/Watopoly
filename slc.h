#ifndef __SLC_H__
#define __SLC_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Slc : public Tile {

public:

    Slc(int position, std::string blockPosition, std::vector<std::shared_ptr<Tile>> board);
    ~Slc();
    void action(std::shared_ptr<Player> player) override;
};

#endif
