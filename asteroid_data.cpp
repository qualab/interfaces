#include "asteroid_data.h"

asteroid::data::data(int identifier)
    : m_identifier(identifier)
{
}

int asteroid::data::get_identifier() const
{
    return m_identifier;
}

object::data* asteroid::data::clone() const
{
    return new asteroid::data(*this);
}

const char* asteroid::data::class_name() const
{
    return "asteroid";
}
