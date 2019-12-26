#ifndef FUNCTION 
#define FUNCTION

#include <string>

class Function
{
    public:
        Function()
        {

        }
        
        Function(const std::string& name, int arguments, int address) : name(name), arguments(arguments), address(address)
        {
            
        }

        int getAddress() const
        {
            return address;
        }

        int getArguments() const
        {
            return arguments;
        }
    
    private:
        std::string name;
        int arguments;
        int address;
};

#endif