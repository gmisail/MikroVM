#ifndef FRAME
#define FRAME

#include <vector>
#include <iostream>

#include "function.h"
#include "constants.h"

class Frame
{
    public:
        Frame(){ }

        void setParent(Frame* parent);

        Frame* getParent()
        {
            return parent;
        }

        void setLocal(int register_address, int value);
        int getLocal(int register_address);

    private:
        Function func;
        Frame* parent;

        int locals[MIKRO_MEMORY];
};

#endif