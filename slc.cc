#include "slc.h"

Slc::Slc(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Slc::~Slc() {}
