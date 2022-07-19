#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
#include "tile"

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
    int moneyOwed;
    std::vector<std::shared_ptr<tile*>> tilesOwned;
    

    public:
        Player(std::string name, char piece, int money, int pos);
        ~Player();
        void move(int n);
        int getMoney();
        void addMoney (int n);
        void subtractMoney(int n);
        void declareBankruptcy();
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
        void addTile(tile t);
        std::vector<shared_ptr<tile*>> getTiles();

};

#endif
