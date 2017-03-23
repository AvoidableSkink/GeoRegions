//
// Created by Stephen Clyde on 3/4/17.
//

#include "Nation.h"

Nation::Nation(const std::string data[]) : Region(NationType, data)
{
    validate();
}
