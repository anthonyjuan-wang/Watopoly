#include "needlesHall.h"
#include <string>

using namespace std;

NeedlesHall::NeedlesHall(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

NeedlesHall::~NeedlesHall() {}
