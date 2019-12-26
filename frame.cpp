#include "frame.h"

void Frame::setParent(Frame* frame)
{
    parent = frame;
}

void Frame::setLocal(int register_address, int value)
{
    if(register_address >= MIKRO_MEMORY)
    {
        std::cout << "ERROR! Memory out of bounds" << std::endl;
        exit(1);
    }

    locals[register_address] = value;
}

int Frame::getLocal(int register_address)
{
    if(register_address >= MIKRO_MEMORY)
    {
        std::cout << "ERROR! Memory out of bounds" << std::endl;
        exit(1);
    }

    return locals[register_address];
}