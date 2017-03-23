//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef GEO_REGIONS_MENU_OPTION_H
#define GEO_REGIONS_MENU_OPTION_H

#include <string>

class MenuOption {
private:
    std::string m_command;
    std::string m_description;

public:
    MenuOption(std::string command, std::string description);
    const std::string& getCommand() const { return m_command; }
    const std::string& getDescription() const { return m_description; }
};

#endif //GEO_REGIONS_MENUOPTION_H
