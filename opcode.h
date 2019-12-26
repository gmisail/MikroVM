#ifndef OPCODE
#define OPCODE

class Opcode
{
    public:
        Opcode(unsigned int type, double value) : type(type), value(value) {}

    private:
        unsigned int type;
        double value;
};

#endif