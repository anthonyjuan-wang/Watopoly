#include <string>
#include <iostream>
#include "tile.h"
#include <memory>
#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player
{
    // Prob will need a private class for money, roll, etc

    string name;
    char piece;
    int money;
    int pos;
    bool bankrupt;
    bool almostBankrupt;
    int rollUpCount;
    bool isInJail;
    int inJailCounter;
    std::vector<std::shared_ptr<Tile *>> tilesOwned;

public:
    Player(std::string name, char piece);
    ~Player();
    void move(int n);
    int getMoney();
    void addMoney(int n);
    void subtractMoney(int n, std::vector<std::shared_ptr<Player *>> players);
    void declareBankruptcy();
    void bankruptcy(int owed, std::vector<std::shared_ptr<Player *>> players);
    int getRollUpCount();
    void addRollUpCount();
    void useRollUpCount();
    void displayAssets();
    string getName();
    int getPos();
    void setPos(int n);
    bool getJailStatus();
    void setJailStatus(bool status);
    int getJailCount();
    void setJailCount(int n);
    void addTile(Tile t);
    std::vector<shared_ptr<Tile *>> getTiles();
};

#endif
