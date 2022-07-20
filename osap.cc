#include "osap.h"
#include <iostream>
using namespace std;

Osap::Osap(int position, std::string str) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = str;
}

void Osap::action()
{
    cout << "Osap bestows you with some grants. Feel blessed upon this joyous day." << endl;
    impl->Owner->addMoney(200);
}
