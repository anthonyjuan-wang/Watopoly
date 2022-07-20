#include "goToTims.h"
#include <string>

using namespace std;

GoToTims::GoToTims(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

GoToTims::~GoToTims() {}
