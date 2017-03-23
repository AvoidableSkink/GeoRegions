//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_SET_OF_NATIONS_USER_INTERFACE_H
#define GEO_REGIONS_SET_OF_NATIONS_USER_INTERFACE_H

#include "UserInterface.h"
#include "World.h"

class WorldUserInterface : public UserInterface
{
public:
    WorldUserInterface(Region* region);

protected:
    Region::RegionType getSubRegionType();
    void setupMenu();
};


#endif //GEO_REGIONS_SET_OF_NATIONS_USER_INTERFACE_H
