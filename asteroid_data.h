#pragma once

#include "asteroid.h"
#include "object_data.h"

class asteroid::data : public object::data
{
public:
    data(int identifier);

    int get_identifier() const;

    virtual object::data* clone() const override;

    virtual const char* class_name() const override;

private:
    int m_identifier;
};
