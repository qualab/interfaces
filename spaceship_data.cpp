#include "spaceship_data.h"

spaceship::data::data(const char* name)
    : m_name(name)
{
}

const char* spaceship::data::get_name() const
{
    return m_name.c_str();
}

object::data* spaceship::data::clone() const
{
    return new spaceship::data(*this);
}

const char* spaceship::data::class_name() const
{
    return "spaceship";
}
