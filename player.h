#include <iostream>
#include <vector>

#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace std;

class Player {
    // Prob will need a private class for money, roll, etc
    public:
        Player();
        ~Player();
        void move();
        int getMoney(int money);
        void subtractMoney(int money);
        void decideBankruptcy();
        void bankruptcy();
        int getRollUpCount();
        void setRollUpCount(int count);
};

#endif
