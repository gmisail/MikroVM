#ifndef OPCODE
#define OPCODE

enum Opcodes
{
    ABORT,

    PRINT,
    FPRINT,

    ADD,
    SUB,
    MUL,
    FMUL,
    DIV,
    FDIV,
    POW,
    SQRT,

    PUSH,
    POP,

    JUMP,
    JUMPT,
    JUMPF,

    EQ,
    GT,
    LT,
    GTEQ,
    LTEQ,

    GLOBAL_LOAD,
    GLOBAL_STORE,
    LOCAL_LOAD,
    LOCAL_STORE,

    FUNC,
    CALL,
    END,
    RETURN
};

#endif
