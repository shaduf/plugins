#ifndef InstructionsH
#define InstructionsH
//------------------------------------------------------------------------------
#include "typedefine.h"
//------------------------------------------------------------------------------
void f_NULL   (void);
void f_ADD    (void);
void f_ADD3   (void);
void f_ADDI   (void);
void f_AND    (void);
void f_AND3   (void);
void f_BC     (void);
void f_BEQ    (void);
void f_BEQZ   (void);
void f_BGEZ   (void);
void f_BGTZ   (void);
void f_BL     (void);
void f_BLEZ   (void);
void f_BLTZ   (void);
void f_BNC    (void);
void f_BNE    (void);
void f_BNEZ   (void);
void f_BRA    (void);
void f_DIV    (void);
void f_DIVU   (void);
void f_JL     (void);
void f_JMP    (void);
void f_LD     (void);
void f_LD24   (void);
void f_LDB    (void);
void f_LDH    (void);
void f_LDI    (void);
void f_LDUB   (void);
void f_LDUHI  (void);
void f_MUL    (void);
void f_MV     (void);
void f_MVFC   (void);
void f_MVTC   (void);
void f_NEG    (void);
void f_NOT    (void);
void f_OR     (void);
void f_OR3    (void);
void f_RTE    (void);
void f_SETH   (void);
void f_SLL    (void);
void f_SLL3   (void);
void f_SLLI   (void);
void f_SRA    (void);
void f_SRA3   (void);
void f_SRAI   (void);
void f_SRL    (void);
void f_SRL3   (void);
void f_SRLI   (void);
void f_ST     (void);
void f_STB    (void);
void f_STH    (void);
void f_SUB    (void);
void f_XOR    (void);
void f_XOR3   (void);
//------------------------------------------------------------------------------
Tinstruct InstructionFunc[] =
{
    { "null",   f_NULL      },    // 0x00 Null instruction
    { "add",    f_ADD       },    // 0x01 Add
    { "add3",   f_NULL/*ff_ADD3  */    },    // 0x02 Add 3-operand
    { "addi",   f_ADDI      },    // 0x03 Add immediate
    { "addv",   f_NULL      },    // 0x04 Add with overflow checking
    { "addv3",  f_NULL      },    // 0x05 Add 3-operand with overflow checking
    { "addx",   f_NULL      },    // 0x06 Add with carry
    { "and",    f_AND       },    // 0x07 AND
    { "and3",   f_NULL/*ff_AND3  */    },    // 0x08 AND 3-operand
    { "bc",     f_BC        },    // 0x09 Branch on C-bit
    { "beq",    f_BEQ       },    // 0x0A Branch on equal
    { "beqz",   f_BEQZ      },    // 0x0B Branch on equal zero
    { "bgez",   f_BGEZ      },    // 0x0C Branch on greater than or equal zero
    { "bgtz",   f_BGTZ      },    // 0x0D Branch on greater than zero
    { "bl",     f_BL        },    // 0x0E Branch and link
    { "blez",   f_BLEZ      },    // 0x0F Branch on less than or equal zero
    { "bltz",   f_BLTZ      },    // 0x10 Branch on less than zero
    { "bnc",    f_BNC       },    // 0x11 Branch on not C-bit
    { "bne",    f_BNE       },    // 0x12 Branch on not equal
    { "bnez",   f_BNEZ      },    // 0x13 Branch on not equal zero
    { "bra",    f_BRA       },    // 0x14 Branch
    { "cmp",    f_NULL      },    // 0x15 Compare
    { "cmpi",   f_NULL      },    // 0x16 Compare immediate
    { "cmpu",   f_NULL      },    // 0x17 Compare unsigned
    { "cmpui",  f_NULL      },    // 0x18 Compare unsigned immediate
    { "div",    f_DIV       },    // 0x19 Divide
    { "divu",   f_DIVU      },    // 0x1A Divide unsigned
    { "jl",     f_JL        },    // 0x1B Jump and link
    { "jmp",    f_JMP       },    // 0x1C Jump
    { "ld",     f_NULL/*ff_LD    */    },    // 0x1D Load
    { "ld24",   f_LD24      },    // 0x1E Load 24-bit immediate
    { "ldb",    f_NULL/*ff_LDB   */    },    // 0x1F Load byte
    { "ldh",    f_NULL/*ff_LDH   */    },    // 0x20 Load halfword
    { "ldi",    f_LDI       },    // 0x21 Load immediate
    { "ldub",   f_NULL/*ff_LDUB  */    },    // 0x22 Load unsigned byte
    { "lduh",   f_NULL/*ff_LDUH  */    },    // 0x23 Load unsigned halfword
    { "lock",   f_NULL      },    // 0x24 Load locked
    { "machi",  f_NULL      },    // 0x25 Multiply-accumulate high-order halfwords
    { "maclo",  f_NULL      },    // 0x26 Multiply-accumulate low-order halfwords
    { "macwhi", f_NULL      },    // 0x27 Multiply-accumulate word and high-order halfword
    { "macwlo", f_NULL      },    // 0x28 Multiply-accumulate word and low-order halfword
    { "mul",    f_MUL       },    // 0x29 Multiply
    { "mulhi",  f_NULL      },    // 0x2A Multiply high-order halfwords
    { "mullo",  f_NULL      },    // 0x2B Multiply low-order halfwords
    { "mulwhi", f_NULL      },    // 0x2C Multiply word high-order halfwords
    { "mulwlo", f_NULL      },    // 0x2D Multiply word low-order halfwords
    { "mv",     f_MV        },    // 0x2E Move register
    { "mvfachi",f_NULL      },    // 0x2F Move from accumulator high-order word
    { "mvfaclo",f_NULL      },    // 0x30 Move from accumulator low-order word
    { "mvfacmi",f_NULL      },    // 0x31 Move from accumulator middle-order word
    { "mvfc",   f_MVFC      },    // 0x32 Move from control register
    { "mvtachi",f_NULL      },    // 0x33 Move to accumulator high-order word
    { "mvtaclo",f_NULL      },    // 0x34 Move to accumulator low-order word
    { "mvtc",   f_MVTC      },    // 0x35 Move to control register
    { "neg",    f_NEG       },    // 0x36 Negate
    { "nop",    f_NULL      },    // 0x37 No operation
    { "not",    f_NOT       },    // 0x38 Logical NOT
    { "or",     f_OR        },    // 0x39 OR
    { "or3",    f_NULL/*ff_OR3   */    },    // 0x3A OR 3-operand
    { "push",   f_NULL/*ff_NULL  */    },    // 0x3B Push, mnem for st reg, @-sp
    { "pop",    f_NULL/*ff_NULL  */    },    // 0x3C Pop, mnem for ld reg, @sp+
    { "rac",    f_NULL      },    // 0x3D Round accumulator
    { "rach",   f_NULL      },    // 0x3E Round accumulator halfword
    { "rem",    f_NULL      },    // 0x3F Remainder
    { "remu",   f_NULL      },    // 0x40 Remainder unsigned
    { "rte",    f_RTE       },    // 0x41 Return from EIT
    { "seth",   f_SETH      },    // 0x42 Set high-order 16-bit
    { "sll",    f_SLL       },    // 0x43 Shift left logical
    { "sll3",   f_NULL/*ff_SLL3  */    },    // 0x44 Shift left logical 3-operand
    { "slli",   f_SLLI      },    // 0x45 Shift left logical immediate
    { "sra",    f_NULL/*ff_SRA   */    },    // 0x46 Shirt right arithmetic
    { "sra3",   f_NULL/*ff_SRA3  */    },    // 0x47 Shirt right arithmetic 3-operand
    { "srai",   f_SRAI      },    // 0x48 Shirt right arithmetic immediate
    { "srl",    f_SRL       },    // 0x49 Shift right logical
    { "srl3",   f_NULL/*ff_SRL3  */    },    // 0x4A Shift right logical 3-operand
    { "srli",   f_SRLI      },    // 0x4B Shift right logical immediate
    { "st",     f_NULL/*ff_ST    */    },    // 0x4C Store
    { "stb",    f_NULL/*ff_STB   */    },    // 0x4D Store byte
    { "sth",    f_NULL/*ff_STH   */    },    // 0x4E Store halfword
    { "sub",    f_SUB       },    // 0x4F Substract
    { "subv",   f_NULL      },    // 0x50 Substract with overflow checking
    { "subx",   f_NULL      },    // 0x51 Substract with borrow
    { "trap",   f_NULL      },    // 0x52 Trap
    { "unlock", f_NULL      },    // 0x53 Store unlocked
    { "xor",    f_XOR       },    // 0x54 Exclusive OR
    { "xor3",   f_NULL/*ff_XOR3  */    }     // 0x55 Exclusive OR 3-operand

};
//------------------------------------------------------------------------------
#endif

