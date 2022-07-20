#include <iostream>
#include <string>
#include "board.h"
#include "boarddisplay.h"
using namespace std;

int main(int argc, char *argv[])
{
        cin.exceptions(ios::eofbit | ios::failbit);
        string cmd;
        BoardDisplay b;
        b.print();
}
