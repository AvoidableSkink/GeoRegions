//
// Created by Stephen Clyde on 3/4/17.
//

#include "CountyUserInterface.h"
#include "Menu.h"

CountyUserInterface::CountyUserInterface(Region* region) : UserInterface(region)
{
}

Region::RegionType CountyUserInterface::getSubRegionType()
{
    return Region::CityType;
}

void CountyUserInterface::setupMenu()
{
    UserInterface::setupMenu();

    m_menu->addOption("C", "Create a new city");
    m_menu->addOption("L", "List all cities in this county");
    m_menu->addOption("E", "Edit a city");
    m_menu->addOption("P", "Print a report containing all counties or cities in this state");
    m_menu->addOption("D", "Delete a city");
}

