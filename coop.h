#ifndef __COOP_H__
#define __COOP_H__
#include "tile.h"
#include <string>
#include <memory>
class Player;
class Board;

class Coop : public Tile {

public:
    Coop(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~Coop();
    
    void action(std::shared_ptr<Player> player) override;
};

#endif
