#pragma once

#include "object.h"

class asteroid : public object
{
public:
    asteroid(int identifier);

    asteroid(const asteroid& another);
    asteroid& operator = (const asteroid& another);

    asteroid(const object& another);
    asteroid& operator = (const object& another);

    int get_identifier() const;

    class data;

private:
    data* m_data;
};
