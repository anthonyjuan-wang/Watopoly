#include "dcTimsLine.h"
#include <string>

using namespace std;

DcTimsLine::DcTimsLine(int position, string blockName) : impl{make_shared<TileImpl>()}
{
    impl->pos = position;
    impl->name = blockName;
}

DcTimsLine::~DcTimsLine() {}
