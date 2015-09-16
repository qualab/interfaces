#pragma once

#include "object.h"

class object::data
{
public:
    virtual data* clone() const = 0;

    virtual const char* class_name() const = 0;
};
