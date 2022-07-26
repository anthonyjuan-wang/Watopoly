#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
#include <memory>
#include <vector>


class Tile;
class PlayerImpl;

class Player
{
    // Prob will need a private class for money, roll, etc
    std::shared_ptr<PlayerImpl> impl;

public:
    Player(std::string name, char piece, int money = 1500, int pos = 0, int rollup = 0);
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
    char getPiece();
    void setPos(int n);
    bool getJailStatus();
    void setJailStatus(bool status);
    int getJailCount();
    void setJailCount(int n);
    bool getAlmostBankruptStatus();
    void setAlmostBankruptStatus(bool status);
    bool getBankruptStatus();
    void setBankruptStatus(bool status);
    bool getMoneyOwed();
    void setMoneyOwed(int n);
    void addTile(std::shared_ptr<Tile> t);
    std::vector<std::shared_ptr<Tile>> getTiles();
    void transferProp(std::shared_ptr<Player> otherPlayer, std::shared_ptr<Tile> tile);
};

#endif
