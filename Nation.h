//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_NATION_H
#define GEO_REGIONS_NATION_H

#include "Region.h"

#include <string>

class Nation : public Region
{
public:
    Nation(const std::string data[]);
};


#endif //GEO_REGIONS_NATION_H
