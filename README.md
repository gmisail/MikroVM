# μικρό

Mikro is a basic virtual machine written in C++. It is a spirtual successor to a previous 
pet project that I had, PocoVM. 

## Programs

The project includes two parts: the compiler and virtual machine.

## Bytecode

Below is the bytecode for a program that calculates the quadratic roots for the equation 6x^2 + 11x - 35.
Since command line input is still a work in progress, these values are hard-coded.

```
PUSH 0
PUSH 11
SUB
GSTORE 0

PUSH 2
PUSH 11
POW
GSTORE 1

PUSH 4
PUSH 6
MUL
PUSH -35
MUL
GSTORE 2

GLOAD 1
GLOAD 2
SUB
SQRT
GSTORE 3

GLOAD 0
GLOAD 3
SUB
GSTORE 4

PUSH 2
PUSH 6
FMUL
GSTORE 5

GLOAD 4
GLOAD 5
FDIV
FPRINT
```

This bytecode compiles to the following MikroVM machine code:

```
11 0 11 11 4 22 0 11 2 11 11 9 22 1 11 4 11 6 5 11 -35 5 22 2 21 1 21 2 4 10 22 3 21 0 21 3 4 22 4 11 2 11 6 6 22 5 21 4 21 5 8 2 
```
