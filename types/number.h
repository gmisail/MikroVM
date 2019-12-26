#ifndef MIKRO_NUMBER
#define MIKRO_NUMBER

#include <string>

#include "object.h"

class Number : public Object
{
    public:
        Number(const std::string& id, double value) : Object(id), value(value) {}

    private:
        double value;
};

#endif