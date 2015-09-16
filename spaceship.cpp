#include "spaceship_data.h"

spaceship::spaceship(const char* name)
    : object(m_data = new spaceship::data(name))
{
}

spaceship::spaceship(const spaceship& another)
    : object(m_data = another.is_null() ? nullptr : static_cast<spaceship::data*>(another.get_data()->clone()))
{
}

spaceship& spaceship::operator = (const spaceship& another)
{
    reset(m_data = another.is_null() ? nullptr : static_cast<spaceship::data*>(another.get_data()->clone()));
    return *this;
}

spaceship::spaceship(const object& another)
    : object(m_data = (dynamic_cast<const spaceship::data*>(another.get_data()) ?
                       dynamic_cast<spaceship::data*>(another.get_data()->clone()) : nullptr))
{
}

spaceship& spaceship::operator = (const object& another)
{
    reset(m_data = (dynamic_cast<const spaceship::data*>(another.get_data()) ?
                    dynamic_cast<spaceship::data*>(another.get_data()->clone()) : nullptr));
    return *this;
}

const char* spaceship::get_name() const
{
    assert_not_null(__FILE__, __LINE__);
    return m_data->get_name();
}
