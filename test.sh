g++ compiler.cpp -o mikroc -g
g++ main.cpp vm.cpp frame.cpp -o mikro -g
./mikroc main.mikro
./mikro main.bin
