#ifndef MIKRO_NUMBER
#define MIKRO_NUMBER

#include <string>

#include "object.h"

class String : public Object
{
    public:
        String(const std::string& id, const std::string& value) : Object(id), value(value) {}

    private:
        std::string value;
};

#endif