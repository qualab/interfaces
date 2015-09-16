#pragma once

#include <memory>

class object
{
public:
    object();
    virtual ~object();

    object(const object& another);
    object& operator = (const object& another);

    bool is_null() const;
    object clone() const;

    class data;

    const data* get_data() const;

    const char* data_class() const;

protected:
    object(data* new_data);
    void reset(data* new_data);

    void assert_not_null(const char* file, int line) const;

private:
    std::unique_ptr<data> m_data;
};
