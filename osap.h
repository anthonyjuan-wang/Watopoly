#ifndef __OSAP_H__
#define __OSAP_H__
#include <string>
#include <memory>
#include "tile.h"
#include "player.h"
#include "board.h"


class Osap : public Tile {

public:
    Osap(int position, std::string str, std::shared_ptr<Board> board);
    ~Osap();

    void action(std::shared_ptr<Player> player) override;
};

#endif
