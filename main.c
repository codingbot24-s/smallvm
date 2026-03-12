
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];

#define unimplemented() printf("implement me\n");

uint16_t mem_read(uint16_t);
int read_image(FILE *f);
/*
 *  10 lc3 register
 *
 */
enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
};
uint16_t reg[R_COUNT];

/*
 *
 */
enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

int main(int argc, const char* argv[])
{
    if (argc < 2) 
    {
        printf("lc3 [image-file1]...\n");
        exit(2);
    }

    for (int i = 1; i < argc; i++)
    {
        if (!read_image(argv[i]))
        {
            printf("failed to load image:%s\n",argv[i]);
            exit(1);
        }
        
    }
     
    
    reg[R_COND] = FL_ZRO;

    enum
    {
        PC_START = 0x3000
    };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
        case OP_ADD:
            unimplemented();
            break;
        case OP_AND:
            unimplemented();
            break;
        case OP_NOT:
            unimplemented();
            break;
        case OP_BR:
            unimplemented();
            break;
        case OP_JMP:
            unimplemented();
            break;
        case OP_JSR:
            unimplemented();
            break;
        case OP_LD:
            unimplemented();
            break;
        case OP_LDI:
            break;
        case OP_LDR:
            break;
        case OP_LEA:
            break;
        case OP_ST:
            break;
        case OP_STI:
            break;
        case OP_STR:
            break;
        case OP_TRAP:
            break;
        case OP_RES:
        case OP_RTI:
        default:
            break;
        }
    }
}

uint16_t mem_read(uint16_t address)
{
    unimplemented();
    return 0;
}

int read_image(FILE *f) {
    unimplemented();
}
