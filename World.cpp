//
// Created by Stephen Clyde on 3/4/17.
//

#include "World.h"
#include <iomanip>

const std::string worldData[3] = {"World", "0", "510100000.0"};

World::World() : Region(WorldType, worldData)
{
    validate();
}
