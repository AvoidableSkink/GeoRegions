//
// Created by Stephen Clyde on 2/16/17.
//

#include "UserInterface.h"
#include "NationUserInterface.h"
#include "StateUserInterface.h"
#include "CountyUserInterface.h"
#include "Menu.h"
#include "Utils.h"

#include <iostream>

UserInterface::UserInterface(Region* contextRegion) : m_currentRegion(contextRegion)
{
}

UserInterface::~UserInterface()
{
    cleanup();
}

void UserInterface::setupMenu()
{
    m_menu = new Menu(m_currentRegion->getName());
}

Region::RegionType UserInterface::getSubRegionType()
{
    return Region::UnknownRegionType;
}

void UserInterface::cleanup()
{
    if (m_menu != nullptr)
    {
        delete m_menu;
        m_menu = nullptr;
    }

}

void UserInterface::run()
{
    setupMenu();

    std::cout << "Current context: " << m_currentRegion->getName() << std::endl;

    list();

    bool keepGoing = true;
    while (keepGoing)
    {
        std::string command = m_menu->show();
        if (command=="C")
        {
            add();
        }
        else if (command=="L")
        {
            list();
        }
        else if (command=="E")
        {
            edit();
        }
        else if (command=="D")
        {
            remove();
        }
        else if (command=="P")
        {
            print();
        }
        else if (command=="M")
        {
            changeToSubRegion();
        }
        else if (command=="X")
        {
            keepGoing = false;
        }
    }
}

void UserInterface::add()
{
    m_subRegionType = getSubRegionType();

    if (m_subRegionType!=Region::RegionType::UnknownRegionType) {
        std::string data = getStringInput(
                "Enter name,population,areas for " + Region::regionLabel(m_subRegionType) + ":");
        if (data != "") {
            Region *region = Region::create(m_subRegionType, data);
            if (region != nullptr) {
                // TODO: Add region to the m_currentRegion
                std::cout << Region::regionLabel(m_subRegionType) << " added" << std::endl;
            } else {
                std::cout << "Invalid data - no region created" << std::endl;
            }
        } else {
            std::cout << "Nothing entered - no region created" << std::endl;
        }
    }
    else {
        std::cout << "Cannot create a region of an unknown type" << std::endl;
    }
}

void UserInterface::list()
{
    m_currentRegion->list(std::cout);
}

void UserInterface::edit()
{
    std::string input = getStringInput("Which region would you like to edit? Enter the id:");
    if (input!="")
    {
        bool valid;
        unsigned int id = convertStringToUnsignedInt(input, &valid);
        if (valid && id>0)
        {
            Region* region;
            // TODO: Look the region by Id and assign it to region variable
            if (region!=nullptr)
            {
                std::cout << "Editing: ";
                region->display(std::cout, 0, false);
                editName(region);
                editPopulation(region);
                editArea(region);

            }
        }
        else
        {
            std::cout << "Invalid id -- nothing selected for edit" << std::endl;
        }
    }
    else
    {
        std::cout << "No id entered -- nothing selected for edit" << std::endl;
    }

}

void UserInterface::editName(Region* region)
{
    std::string updatedName = getStringInput("Enter an updated name (<enter> to keep current value):");
    if (updatedName!="")
    {
        region->setName(updatedName);
        std::cout << "Name updated" << std::endl;
    }
    else
    {
        std::cout << "Nothing entered - nothing updated" << std::endl;
    }
}

void UserInterface::editPopulation(Region* region)
{
    std::string population = getStringInput("Enter an updated population (<enter> to keep current value):");
    if (population!="")
    {
        bool valid;
        unsigned int newPopulation = convertStringToUnsignedInt(population, &valid);
        if (valid)
        {
            region->setPopulation(newPopulation);
            std::cout << "Population updated" << std::endl;
        }
        else
        {
            std::cout << "Invalid integer - population not updated" << std::endl;
        }
    }
    else
    {
        std::cout << "Nothing entered - nothing updated" << std::endl;
    }

}

void UserInterface::editArea(Region* region)
{
    std::string area = getStringInput("Enter an updated area (<enter> to keep current value):");
    if (area!="")
    {
        bool valid;
        double newArea = convertStringToDouble(area, &valid);
        if (valid)
        {
            region->setArea(newArea);
            std::cout << "Area updated" << std::endl;
        }
        else
        {
            std::cout << "Invalid integer - area not updated" << std::endl;
        }
    }
    else
    {
        std::cout << "Nothing entered - nothing updated" << std::endl;
    }
}


void UserInterface::remove()
{
    std::string input = getStringInput("Which region would you like to remove? Enter the id:");
    if (input!="")
    {
        bool valid;
        unsigned int id = convertStringToUnsignedInt(input, &valid);
        if (valid && id>0)
        {
            // TODO: Look up the region by Id and assign it to the region variable
            std::cout << "Deleted!" << std::endl;
        }
        else
        {
            std::cout << "Invalid region id -- nothing deleted" << std::endl;
        }
    }
    else
    {
        std::cout << "No id entered - nothing removed" << std::endl;
    }
}

void UserInterface::print()
{
    m_currentRegion->display(std::cout, 0, true);
};

void UserInterface::changeToSubRegion()
{
    std::string input = getStringInput("Which region would you work with (enter the id):");
    if (input!="")
    {
        bool valid;
        unsigned int id = convertStringToUnsignedInt(input, &valid);
        if (valid && id>0)
        {
            Region* region;
            // TODO: Lookup the region by Id and assign it to the region variable.
            if (region!=nullptr)
            {
                UserInterface* nextUI = nullptr;
                if (region->getType()==Region::CountyType)
                {
                    nextUI = new CountyUserInterface(region);
                }
                else if (region->getType()==Region::StateType)
                {
                    nextUI = new StateUserInterface(region);
                }
                else if (region->getType()==Region::NationType)
                {
                    nextUI = new NationUserInterface(region);
                }

                if (nextUI != nullptr)
                {
                    nextUI->run();
                    delete nextUI;
                }
                else
                {
                    std::cout << "Can't move into the context of " << region->getName();
                }
            }
        }
    }
};

