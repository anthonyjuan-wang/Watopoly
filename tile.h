#ifndef __TILE_H_
#define __TILE_H_
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Player;
class Board;

struct TileImpl
{
    Board *theBoard;
    Player *Owner;
    std::string name;
    bool isOwnable;
    bool isImprovable;
    int pos;
    int purchase;
    int improvement;
    std::string monopoly;
    std::vector<int> tuition;
};

class Tile
{
public:
    Tile();
    virtual TileImpl *getImpl() = 0;
    virtual ~Tile();
    virtual Board *getBoard() = 0;
    virtual Player *getOwner() = 0;
    virtual void setOwner(Player *player) = 0;
    virtual int getImprovement() = 0; // returns the improvement #
    virtual void setImprovement(int x) = 0;
    virtual void action(std::shared_ptr<Player> player) = 0;
    virtual void mortgage(Player *player) = 0;
    virtual void auction() = 0;
    virtual bool isMortgaged() = 0;
    virtual bool isOwned() = 0;
    virtual int getPos() = 0;
    virtual int getPrice() = 0;
    virtual std::string getName() = 0;
};

#endif