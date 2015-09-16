#include "object_data.h"
#include <stdexcept>
#include <sstream>

object::object()
{
}

object::~object()
{
}

object::object(object::data* new_data)
    : m_data(new_data)
{
}

object::object(const object& another)
    : m_data(another.is_null() ? nullptr : another.m_data->clone())
{
}

object& object::operator = (const object& another)
{
    m_data.reset(another.is_null() ? nullptr : another.m_data->clone());
    return *this;
}

bool object::is_null() const
{
    return !m_data;
}

object object::clone() const
{
    return is_null() ? object() : object(m_data->clone());
}

const object::data* object::get_data() const
{
    return m_data.get();
}

const char* object::data_class() const
{
    return is_null() ? "null" : m_data->class_name();
}

void object::reset(object::data* new_data)
{
    m_data.reset(new_data);
}

void object::assert_not_null(const char* file, int line) const
{
    if (is_null())
    {
        std::stringstream output;
        output << "Assert 'object is not null' failed at file: '" << file << "' line: " << line;
        throw std::runtime_error(output.str());
    }
}
