#include <iostream>
#include <string>
#include <vector>
#include "board.h"

#ifndef __DISPLAYBOARD_H__
#define __DISPLAYBOARD_H__

class displayBoard : Board {
    public:
        displayBoard();
        ~displayBoard();
        Board getBoard();
        void print();
};

#endif
