#include "compiler.h"
#include "opcodes.h"

#include <iostream>

double Compiler::getOpcode(const std::string& opcode)
{
    if(opcode == "STOP") return ABORT;
    else if(opcode == "ADD") return ADD;
    else if(opcode == "SUB") return SUB;
    else if(opcode == "MUL") return MUL;
    else if(opcode == "FMUL") return FMUL;
    else if(opcode == "DIV") return DIV;
    else if(opcode == "FDIV") return FDIV;
    else if(opcode == "POW") return POW;
    else if(opcode == "PRINT") return PRINT;
    else if(opcode == "FPRINT") return FPRINT;
    else if(opcode == "SQRT") return SQRT;
    else if(opcode == "PUSH") return PUSH;
    else if(opcode == "POP") return POP;
    else if(opcode == "EQ") return EQ;
    else if(opcode == "STORE") return LOCAL_STORE;
    else if(opcode == "LOAD") return LOCAL_LOAD;
    else if(opcode == "GSTORE") return GLOBAL_STORE;
    else if(opcode == "GLOAD") return GLOBAL_LOAD;
    else if(opcode == "FUNC") return FUNC;
    else if(opcode == "CALL") return CALL;
    else if(opcode == "END") return END;
    else if(opcode == "RETURN") return RETURN;

    double code = -1;

    try
    {
        code = std::stod(opcode);
    }
    catch(const std::invalid_argument& e)
    {
        if(keywords.find(opcode) == keywords.end())
        {
            keywords[opcode] =  ++keyword;
            code = keyword;
        }
        else
        {
            code = keywords[opcode];
        }
    }
    
    return code;
}

int main(int argc, char* argv[])
{
    std::vector<double> program;
    std::string instruction;

    std::ifstream input(argv[1]);
    std::ofstream output("main.bin");

    Compiler compiler;

    while(input >> instruction)
    {
        double opcode = compiler.getOpcode(instruction);
        output << opcode << " ";
    }
}
