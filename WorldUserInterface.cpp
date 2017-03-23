//
// Created by Stephen Clyde on 3/4/17.
//

#include "WorldUserInterface.h"
#include "Menu.h"

WorldUserInterface::WorldUserInterface(Region* region) : UserInterface(region)
{
}

Region::RegionType WorldUserInterface::getSubRegionType()
{
    return Region::NationType;
}

void WorldUserInterface::setupMenu()
{
    UserInterface::setupMenu();

    m_menu->addOption("C", "Create a new nation");
    m_menu->addOption("L", "List all nations");
    m_menu->addOption("E", "Edit a nation");
    m_menu->addOption("D", "Delete a nation");
    m_menu->addOption("P", "Print a report containing all nations");
    m_menu->addOption("M", "Move into the context of a nation");
}



