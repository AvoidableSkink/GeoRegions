//
// Created by Stephen Clyde on 3/4/17.
//

#include "City.h"

City::City(const std::string data[]) : Region(CityType, data)
{
    validate();
}
