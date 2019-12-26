#ifndef OBJECT
#define OBJECT

#include <string>

class Object
{
    public:
        Object(const std::string& id) : id(id) {}
        
    protected:
        std::string id;
};

#endif