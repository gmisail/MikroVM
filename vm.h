#ifndef VM
#define VM

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>

#include "function.h"
#include "opcodes.h"
#include "frame.h"
#include "constants.h"

class Mikro
{
    public:
        Mikro(const std::vector<int>& program) : ic(0), sp(-1), program(program), running(true)
        {
            for(int i = 0; i < MIKRO_MEMORY; i++) 
            {
                stack[i] = 0;
                globals[i] = 0;
            }

            frame = new Frame();
        }

        ~Mikro()
        {
            for(std::map<int, Function*>::iterator itr = functions.begin(); itr != functions.end(); itr++)
            {
                delete itr->second;
            }

            delete frame;
        }

        bool run();

        void push(double value)
        {
            stack[++sp] = value;
        }

        double pop()
        {
            if(sp < 0)
            {
                std::cout << "ERROR! Cannot access value outside of stack memory" << std::endl;
                running = false;
            }

            return stack[sp--];
        }

        void jump(int address)
        {
            if(address > 0 && address < program.size()) ic = address;
        }

        void print()
        {
            std::cout << "------------------------------------" << std::endl;
            std::cout << "Stack Pointer: " << sp << std::endl;
            std::cout << "Instruction Pointer: " << ic << std::endl;

            std::cout << "Stack: [ ";
            for(int i = 0; i < MIKRO_MEMORY; i++)
            {
                std::cout << stack[i] << " ";
            }
            std::cout << "]" << std::endl;
            std::cout << "------------------------------------" << std::endl;
        }

    private:
        std::vector<int> program;

        double stack[MIKRO_MEMORY];
        double globals[MIKRO_MEMORY];

        std::map<int, Function*> functions;
        std::stack<int> call_stack;

        Frame* frame;

        int ic;
        int sp;

        bool running;

        void eval();
        const int current();
        bool next();
};

#endif
