#ifndef __SLC_H__
#define __SLC_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Slc : public Tile {

public:
    Slc(int position, std::string blockPosition);
    ~Slc();
    void action(std::shared_ptr<Player> player) override;
};

#endif
