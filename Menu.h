//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef GEO_REGIONS_MENU_H
#define GEO_REGIONS_MENU_H

#include "MenuOption.h"

class Menu {
private:
    std::string m_header;
    MenuOption** m_options;
    int m_optionCount  = 0;
    int m_optionAllocation = 0;

public:
    Menu(const std::string& header);
    ~Menu();
    void addOption(const std::string& command, const std::string& description);

    const std::string& getHeader() const { return m_header; }
    int getOptionCount() const { return m_optionCount; }
    const MenuOption* getOption(int optionIndex) const;

    std::string show() const;

private:
    bool isValidCommand(std::string command) const;
    void growOptionAllocation();
};

#endif //GEO_REGIONS_MENU_H
