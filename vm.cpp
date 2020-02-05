#include <iostream>
#include <cmath>

#include "vm.h"

bool Mikro::next()
{
    if(ic >= program.size())
    {
        running = false;

        return false;
    }

    ic++;

    return true;
}

const int Mikro::current()
{
    if(ic >= program.size()) 
    {
        running = false;

        return MIKRO_OUT_OF_BOUNDS;
    }

    return program[ic];
}

void Mikro::eval()
{
    if(current() == MIKRO_OUT_OF_BOUNDS && running == false)
        return;

    switch(current())
    {
        case ABORT:
        {
            running = false;

            break;
        }

        case PRINT:
        {
            std::cout << (int) pop() << std::endl;

            break;
        }

        case FPRINT:
        {
            std::cout << pop() << std::endl;

            break;
        }

        case SPRINT:
        {
            int len = pop();
            
            /*
                Keep popping values until you reach the null terminator. For now, print 'len' number of characters
            */
            for(int i = 0; i < len; i++)
            {
                std::cout << (char) pop();
            }

            break;
        }

        case ADD:
        {
            int left = pop();
            int right = pop();
            push(left + right);

            break;
        }

        case SUB:
        {
            int left = pop();
            int right = pop();
            push(right - left);

            break;
        }

        case MUL:
        {
            int left = pop();
            int right = pop();
            push(left * right);

            break;
        }

        case FMUL:
        {
            float left = pop();
            float right = pop();

            push(left * right);

            break;
        }

        case DIV:
        {
            int left = pop();
            int right = pop();
            push(right / left);

            break;
        }

        case FDIV:
        {
            double left = pop();
            double right = pop();

            push(right / left);

            break;
        }

        case POW:
        {
            double base = pop();
            double power = pop();

            push(pow(base, power));

            break;
        }

        case SQRT:
        {
            double value = pop();

            if(value < 0)
            {
                std::cout << "ERROR: Cannot find root of non-zero value" << std::endl;
                running = false;
            }

            push(sqrt(value));

            break;
        }

        case PUSH:
        {
            next();

            push(current());

            break;
        }

        case JUMP:
        {
            next();

            jump(current());

            break;
        }

        case EQ:
        {
            int first = pop();
            int second = pop();

            if(first == second) push(MIKRO_TRUE);
            else push(MIKRO_FALSE);

            break;
        }

        case GLOBAL_LOAD:
        {
            next();

            int address = current();
            int value = globals[address];

            push(value);

            break;
        }

        case GLOBAL_STORE:
        {
            int value = pop();

            next();

            int address = current();
            globals[address] = value;

            break;
        }

        case LOCAL_LOAD:
        {
            next();

            push(frame->getLocal(current()));
            
            break;
        }

        case LOCAL_STORE:
        {
            next();
            
            frame->setLocal(current(), pop());

            break;
        }

        case FUNC:
        {
            next();

            int id = current();

            next();

            int arguments = current();

            Function* func = new Function(std::to_string(id), arguments, ic);
            functions[id] = func;
            
            next();

            while(current() != END) 
                if(!next()) break;
    
            break;
        }

        case CALL:
        {
            next();
            
            std::map<int, Function*>::iterator call = functions.find(current());

            if(call == functions.end())
            {
                std::cout << "ERROR: Cannot call undefined function " << current() << std::endl;
                running = false;
            }
            else
            {    
                Frame* temp = frame;

                frame = new Frame();
                frame->setParent(temp);

                for(int i = 0; i < call->second->getArguments(); i++)
                {
                    frame->setLocal(i, pop());
                }

                call_stack.push(ic);
                jump(functions[current()]->getAddress());
            }
        
            break;
        }

        case END:
        {
            Frame* temp = frame;
            frame = frame->getParent();
            delete temp;

            jump(call_stack.top());
            call_stack.pop();

            break;
        }

        case RETURN:
        {
            Frame* temp = frame;
            frame = frame->getParent();
            delete temp;

            jump(call_stack.top());
            call_stack.pop();

            break;
        }
    }
}

bool Mikro::run()
{
    while(running)
    {
        eval();

        if(!next())
        {
            return false;
        }
    }

    return true;
}
