//
// Created by Stephen Clyde on 3/6/17.
//

#ifndef GEO_REGIONS_STATE_USER_INTERFACE_H
#define GEO_REGIONS_STATE_USER_INTERFACE_H

#include "UserInterface.h"

class StateUserInterface : public UserInterface
{
public:
    StateUserInterface(Region* contextRegion);

    Region::RegionType getSubRegionType();
    void setupMenu();
};


#endif //GEO_REGIONS_STATE_USER_INTERFACE_H
