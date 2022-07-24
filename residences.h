#ifndef __RESIDENCES_H__
#define __RESIDENCES_H__
#include "tile.h"
#include "tileimpl.h"
#include <string>
#include <memory>
#include <vector>
class Player;
class Board;

class Residences : public Tile {
    
    std::shared_ptr<TileImpl> impl;
    bool isResidence;
public:
    Residences(int position, std::string blockName, bool residence, std::shared_ptr<Board> board, std::vector<std::shared_ptr<Tile>> boardTiles);
    ~Residences();
    void action(std::shared_ptr<Player> player) override;
};

#endif
