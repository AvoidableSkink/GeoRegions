//
// Created by Stephen Clyde on 3/6/17.
//

#include "StateUserInterface.h"

#include "Menu.h"
#include "Utils.h"

#include <iostream>

StateUserInterface::StateUserInterface(Region* contextRegion) :
        UserInterface(contextRegion)
{

}

Region::RegionType StateUserInterface::getSubRegionType()
{
    Region::RegionType result = Region::RegionType::UnknownRegionType;

    std::string input = getStringInput("Do you want to create a 1) County or 2) City?  Enter a 1 or 2:");
    int choice = convertStringToInt(input);
    if (choice==1)
        result = Region::RegionType::CountyType;
    else if (choice==2)
        result = Region::RegionType::CityType;

    return result;
}

void StateUserInterface::setupMenu()
{
    UserInterface::setupMenu();

    m_menu->addOption("C", "Create a new county or city");
    m_menu->addOption("L", "List all counties or cities in this state");
    m_menu->addOption("E", "Edit a county or city");
    m_menu->addOption("D", "Delete a county or city");
    m_menu->addOption("P", "Print a report containing all counties or cities in this state");
    m_menu->addOption("M", "Move into the context of a county or city");
}

