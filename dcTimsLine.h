#ifndef __DCTIMSLINE_H__
#define __DCTIMSLINE_H__
#include "tile.h"
#include <memory>
#include <string>
class Player;
class Board;

class DcTimsLine : public Tile {
    
public:
    DcTimsLine(int position, std::string blockName, std::vector<std::shared_ptr<Tile>> board);
    ~DcTimsLine();
    void action(std::shared_ptr<Player> player) override;
};
#endif
