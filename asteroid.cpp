#include "asteroid_data.h"

asteroid::asteroid(int identifier)
    : object(m_data = new asteroid::data(identifier))
{
}

asteroid::asteroid(const asteroid& another)
    : object(m_data = another.is_null() ? nullptr : static_cast<asteroid::data*>(another.get_data()->clone()))
{
}

asteroid& asteroid::operator = (const asteroid& another)
{
    reset(m_data = another.is_null() ? nullptr : static_cast<asteroid::data*>(another.get_data()->clone()));
    return *this;
}

asteroid::asteroid(const object& another)
    : object(m_data = (dynamic_cast<const asteroid::data*>(another.get_data()) ?
                       dynamic_cast<asteroid::data*>(another.get_data()->clone()) : nullptr))
{
}

asteroid& asteroid::operator = (const object& another)
{
    reset(m_data = (dynamic_cast<const asteroid::data*>(another.get_data()) ?
                    dynamic_cast<asteroid::data*>(another.get_data()->clone()) : nullptr));
    return *this;
}

int asteroid::get_identifier() const
{
    assert_not_null(__FILE__, __LINE__);
    return m_data->get_identifier();
}
