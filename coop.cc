#include "coop.h"
#include <string>

using namespace std;

Coop::Coop(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Coop::~Coop() {}
