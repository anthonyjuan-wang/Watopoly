#include "residences.h"
#include <string>

using namespace std;
Residences::Residences(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Residences::~Residences() {}
