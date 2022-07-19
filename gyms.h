#include "tile.h"
#ifndef __GYMS_H__
#define __GYMS_H__

class Gyms : Tile {
    private:
        std::string blockName;
    public:
        Gyms(std::string Blockname);
};

#endif
