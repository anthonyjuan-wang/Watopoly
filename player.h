#include <iostream>
#include <vector>
#include <string>

#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace std;

class Player {
    // Prob will need a private class for money, roll, etc
    char piece;
    int money;
    

    public:
        Player(char piece);
        ~Player();
        void move();
        int getMoney(int money);
        void subtractMoney(int money);
        void decideBankruptcy();
        void bankruptcy();
        int getRollUpCount();
        void setRollUpCount(int count);
        string getName();
};

#endif
