//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_COUNTY_USER_INTERFACE_H
#define GEO_REGIONS_COUNTY_USER_INTERFACE_H

#include "UserInterface.h"

class CountyUserInterface : public UserInterface
{
public:
    CountyUserInterface(Region* region);

protected:
    Region::RegionType getSubRegionType();
    void setupMenu();

};

#endif //GEO_REGIONS_COUNTY_USER_INTERFACE_H
