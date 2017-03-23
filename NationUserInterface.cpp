//
// Created by Stephen Clyde on 3/4/17.
//

#include "NationUserInterface.h"
#include "Menu.h"

NationUserInterface::NationUserInterface(Region* contextRegion) :
        UserInterface(contextRegion)
{

}

Region::RegionType NationUserInterface::getSubRegionType()
{
    return Region::NationType;
}

void NationUserInterface::setupMenu()
{
    UserInterface::setupMenu();

    m_menu->addOption("C", "Create a new state");
    m_menu->addOption("L", "List all states in this nation");
    m_menu->addOption("E", "Edit a state");
    m_menu->addOption("D", "Delete a state");
    m_menu->addOption("P", "Print a report containing all states in this nation");
    m_menu->addOption("M", "Move into the context of a state");
}
