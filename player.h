#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
using namespace std;

class Player
{
    // Prob will need a private class for money, roll, etc

    string name;
    char piece;
    int money;
    int pos;
    bool bankrupt;
    int rollUpCount;
    bool isInJail;
    int inJailCounter;

public:
    Player(std::string name, char piece);
    ~Player();
    void move(int n);
    int getMoney();
    void addMoney(int n);
    void subtractMoney(int n);
    void decideBankruptcy();
    void bankruptcy();
    int getRollUpCount();
    void setRollUpCount(int count);
    void displayAssets();
    std::vector<tile> getProperties();
    void setProperties(tile t);
    string getName();
    int getPos();
    void setPos(int n);
    bool getJailStatus();
    void setJailStatus(bool status);
    int getJailCount();
    void setJailCount(int n);
    void addTile(tile t);
    vector<tile *> getTiles();
};

#endif
