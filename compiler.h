#ifndef COMPILER
#define COMPILER

#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

class Compiler
{
    public:
        Compiler() : keyword(-1) {}

        double getOpcode(const std::string& opcode);

    private:
        unsigned int keyword;

        std::unordered_map<std::string, unsigned int> keywords;
};

#endif