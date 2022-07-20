#include "gooseNesting.h"
#include <string>

using namespace std;

GooseNesting::GooseNesting(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

GooseNesting::~GooseNesting() {}