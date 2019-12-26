#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "vm.h"
#include "compiler.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cerr << "ERROR: Cannot find file." << endl;
        return 1;
    }

    ifstream input(argv[1]);
    vector<int> program;

    string instruction;
    while(input >> instruction) program.push_back(stoi(instruction));

    if(program.size() > 0)
    {
        Mikro mikro(program);
        mikro.run();
    }

    return 0;
}
