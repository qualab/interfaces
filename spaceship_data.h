#pragma once

#include "spaceship.h"
#include "object_data.h"
#include <string>

class spaceship::data : public object::data
{
public:
    data(const char* name);

    const char* get_name() const;

    virtual object::data* clone() const override;

    virtual const char* class_name() const override;

private:
    std::string m_name;
};
