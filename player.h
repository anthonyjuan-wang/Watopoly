#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "tile.h"
struct PlayerImpl
{
    std::string name;
    char piece;
    int money;
    int pos;
    bool bankrupt;
    bool almostBankrupt;
    int rollUpCount;
    bool isInJail;
    int inJailCounter;
    std::vector<std::shared_ptr<Tile>> tilesOwned;
    int moneyOwed;
};
class Player
{
    // Prob will need a private class for money, roll, etc
    std::shared_ptr<PlayerImpl> impl;

public:
    Player(std::string name, char piece, int money, int pos);
    ~Player();
    void move(int n);
    int getMoney();
    void addMoney(int n);
    void subtractMoney(int n);
    void declareBankruptcy();
    int getRollUpCount();
    void addRollUpCount();
    void useRollUpCount();
    void displayAssets();
    std::string getName();
    int getPos();
    void setPos(int n);
    bool getJailStatus();
    void setJailStatus(bool status);
    int getJailCount();
    void setJailCount(int n);
    bool getAlmostBankruptStatus();
    bool getBankruptStatus();
    void setBankruptStatus(bool status);
    void addTile(std::shared_ptr<Tile> t);
    std::vector<std::shared_ptr<Tile>> getTiles();
};

#endif
