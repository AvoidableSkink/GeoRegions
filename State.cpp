//
// Created by Stephen Clyde on 3/4/17.
//

#include "State.h"

// TODO: implement State class functionality
State::State(const std::string data[]) : Region(NationType, data)
{
    validate();
}
