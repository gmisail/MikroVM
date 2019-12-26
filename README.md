# μικρό

Mikro is a basic virtual machine written in C++. It is a spirtual successor to a previous 
pet project that I had, PocoVM. 

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