#ifndef __OSAP_H__
#define __OSAP_H__
<<<<<<< HEAD
class Osap : Tile {

    private:

    public:
        Osap(int position, string name);
        ~Osap();
=======
#include <string>
#include <memory>
#include "tile.h"

class Osap : public Tile
{
    std::shared_ptr<TileImpl> impl;

public:
    Osap(int position, std::string str);
    void action() override;
    TileImpl *getImpl ~Osap();
>>>>>>> main
};

#endif
