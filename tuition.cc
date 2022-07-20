#include "tuition.h"
#include <string>
#include <iostream>

Tuition::Tuition(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Tuition::~Tuition() {}
