//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_NATION_STATE_USER_INTERFACE_H
#define GEO_REGIONS_NATION_STATE_USER_INTERFACE_H

#include "UserInterface.h"

class NationUserInterface : public UserInterface
{
public:
    NationUserInterface(Region* contextRegion);

    Region::RegionType getSubRegionType();
    void setupMenu();
};


#endif //GEO_REGIONS_NATION_STATE_USER_INTERFACE_H
