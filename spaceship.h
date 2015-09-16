#pragma once

#include "object.h"

class spaceship : public object
{
public:
    spaceship(const char* name);

    spaceship(const spaceship& another);
    spaceship& operator = (const spaceship& another);

    spaceship(const object& another);
    spaceship& operator = (const object& another);

    const char* get_name() const;

    class data;

private:
    data* m_data;
};
