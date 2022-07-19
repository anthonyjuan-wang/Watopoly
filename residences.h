#include "tile.h"

#ifndef __RESIDENCES_H__
#define __RESIDENCES_H__

class Residences : Tile {
    private:
        std::string blockName;
    public:
        Residences(std::string blockName);
        ~Residences();
};

#endif
