#include "gyms.h"
#include <string>

using namespace std;

Gyms::Gyms(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

Gyms::~Gyms() {}
