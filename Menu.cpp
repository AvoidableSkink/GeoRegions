//
// Created by Stephen Clyde on 2/16/17.
//

#include "Menu.h"
#include <locale>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

Menu::Menu(const std::string& header) : m_header(header)
{
    m_optionAllocation = 2;
    m_options = new MenuOption* [m_optionAllocation];
}

Menu::~Menu()
{
    // When a menu object is destroyed, it must release all of things it allocated dynamically.
    // This includes the menu options and the array of pointers to memory options

    for (int i=0; i<getOptionCount(); i++)
        delete m_options[i];
    delete[] m_options;
}

void Menu::addOption(const std::string& command, const std::string& description)
{
    if (command!="")
    {
        if (m_optionCount == m_optionAllocation)
            growOptionAllocation();

        MenuOption* menuOption = new MenuOption(command, description);
        m_options[m_optionCount++] = menuOption;
    }
}

const MenuOption* Menu::getOption(int optionIndex) const
{
    const MenuOption* option = nullptr;
    if (optionIndex>=0 && optionIndex<getOptionCount())
        option = m_options[optionIndex];
    return option;
}

std::string Menu::show() const
{
    std::string command;
    bool keepGoing = true;

    while (keepGoing)
    {
        std::string optionList;

        std::cout << std::endl;
        std::cout << getHeader() << " menu:" << std::endl;
        for (int i=0; i<getOptionCount(); i++)
        {
            const MenuOption* option = getOption(i);
            if (option!= nullptr)
            {
                std::cout << std::setw(6) << option->getCommand() << " - " << option->getDescription() << std::endl;
                optionList += option->getCommand() + ", ";
            }
        }
        std::cout << std::setw(6) << "X" << " - Exit" << std::endl << std::endl;
        optionList += "X";

        std::cout << std::endl;
        std::cout << "Enter a " << getHeader() << " command (" << optionList << "): " << std::endl;
        std::getline(std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);     // Convert the command to upper case

        keepGoing = !isValidCommand(command);
    }

    return command;
}

bool Menu::isValidCommand(std::string command) const
{
    bool isValid = false;

    if (command=="X")
        isValid = true;
    else
    {
        for (int i=0; i<getOptionCount() && !isValid; i++)
        {
            if (command == getOption(i)->getCommand())
                isValid = true;
        }
    }

    return isValid;
}

void Menu::growOptionAllocation()
{
    m_optionAllocation = 2 * m_optionAllocation;
    MenuOption** newArray = new MenuOption* [m_optionAllocation];
    for (int i=0; i<m_optionCount; i++)
    {
        newArray[i] = m_options[i];
    }
    delete[] m_options;
    m_options = newArray;
}
