//---------------------------------------------------------------------------
#pragma hdrstop
#include <ida.hpp>
#include <idp.hpp>
#include "ReadInformationInstruction.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

typedef struct{
              const char *name;
              }Tinstruct;

Tinstruct InstructionFunc[] =
{
    { "null",    },    // 0x00 Null instruction
    { "add",     },    // 0x01 Add
    { "add3",    },    // 0x02 Add 3-operand
    { "addi",    },    // 0x03 Add immediate
    { "addv",    },    // 0x04 Add with overflow checking
    { "addv3",   },    // 0x05 Add 3-operand with overflow checking
    { "addx",    },    // 0x06 Add with carry
    { "and",     },    // 0x07 AND
    { "and3",    },    // 0x08 AND 3-operand
    { "bc",      },    // 0x09 Branch on C-bit
    { "beq",     },    // 0x0A Branch on equal
    { "beqz",    },    // 0x0B Branch on equal zero
    { "bgez",    },    // 0x0C Branch on greater than or equal zero
    { "bgtz",    },    // 0x0D Branch on greater than zero
    { "bl",      },    // 0x0E Branch and link
    { "blez",    },    // 0x0F Branch on less than or equal zero
    { "bltz",    },    // 0x10 Branch on less than zero
    { "bnc",     },    // 0x11 Branch on not C-bit
    { "bne",     },    // 0x12 Branch on not equal
    { "bnez",    },    // 0x13 Branch on not equal zero
    { "bra",     },    // 0x14 Branch
    { "cmp",     },    // 0x15 Compare
    { "cmpi",    },    // 0x16 Compare immediate
    { "cmpu",    },    // 0x17 Compare unsigned
    { "cmpui",   },    // 0x18 Compare unsigned immediate
    { "div",     },    // 0x19 Divide
    { "divu",    },    // 0x1A Divide unsigned
    { "jl",      },    // 0x1B Jump and link
    { "jmp",     },    // 0x1C Jump
    { "ld",      },    // 0x1D Load
    { "ld24",    },    // 0x1E Load 24-bit immediate
    { "ldb",     },    // 0x1F Load byte
    { "ldh",     },    // 0x20 Load halfword
    { "ldi",     },    // 0x21 Load immediate
    { "ldub",    },    // 0x22 Load unsigned byte
    { "lduh",    },    // 0x23 Load unsigned halfword
    { "lock",    },    // 0x24 Load locked
    { "machi",   },    // 0x25 Multiply-accumulate high-order halfwords
    { "maclo",   },    // 0x26 Multiply-accumulate low-order halfwords
    { "macwhi",  },    // 0x27 Multiply-accumulate word and high-order halfword
    { "macwlo",  },    // 0x28 Multiply-accumulate word and low-order halfword
    { "mul",     },    // 0x29 Multiply
    { "mulhi",   },    // 0x2A Multiply high-order halfwords
    { "mullo",   },    // 0x2B Multiply low-order halfwords
    { "mulwhi",  },    // 0x2C Multiply word high-order halfwords
    { "mulwlo",  },    // 0x2D Multiply word low-order halfwords
    { "mv",      },    // 0x2E Move register
    { "mvfachi", },    // 0x2F Move from accumulator high-order word
    { "mvfaclo", },    // 0x30 Move from accumulator low-order word
    { "mvfacmi", },    // 0x31 Move from accumulator middle-order word
    { "mvfc",    },    // 0x32 Move from control register
    { "mvtachi", },    // 0x33 Move to accumulator high-order word
    { "mvtaclo", },    // 0x34 Move to accumulator low-order word
    { "mvtc",    },    // 0x35 Move to control register
    { "neg",     },    // 0x36 Negate
    { "nop",     },    // 0x37 No operation
    { "not",     },    // 0x38 Logical NOT
    { "or",      },    // 0x39 OR
    { "or3",     },    // 0x3A OR 3-operand
    { "push",    },    // 0x3B Push, mnem for st reg, @-sp
    { "pop",     },    // 0x3C Pop, mnem for ld reg, @sp+
    { "rac",     },    // 0x3D Round accumulator
    { "rach",    },    // 0x3E Round accumulator halfword
    { "rem",     },    // 0x3F Remainder
    { "remu",    },    // 0x40 Remainder unsigned
    { "rte",     },    // 0x41 Return from EIT
    { "seth",    },    // 0x42 Set high-order 16-bit
    { "sll",     },    // 0x43 Shift left logical
    { "sll3",    },    // 0x44 Shift left logical 3-operand
    { "slli",    },    // 0x45 Shift left logical immediate
    { "sra",     },    // 0x46 Shirt right arithmetic
    { "sra3",    },    // 0x47 Shirt right arithmetic 3-operand
    { "srai",    },    // 0x48 Shirt right arithmetic immediate
    { "srl",     },    // 0x49 Shift right logical
    { "srl3",    },    // 0x4A Shift right logical 3-operand
    { "srli",    },    // 0x4B Shift right logical immediate
    { "st",      },    // 0x4C Store
    { "stb",     },    // 0x4D Store byte
    { "sth",     },    // 0x4E Store halfword
    { "sub",     },    // 0x4F Substract
    { "subv",    },    // 0x50 Substract with overflow checking
    { "subx",    },    // 0x51 Substract with borrow
    { "trap",    },    // 0x52 Trap
    { "unlock",  },    // 0x53 Store unlocked
    { "xor",     },    // 0x54 Exclusive OR
    { "xor3",    }     // 0x55 Exclusive OR 3-operand

};
//------------------------------------------------------------------------------
void Read_Information_Instruction(ea_t CA)
{
int i;
decode_insn(CA);//
insn_t  insn = cmd;
msg("cs=%08Xh\nip=%08Xh\nea=%08Xh\nitype=%02Xh  < %s >\nsize=%02Xh   < ",
     insn.cs,  insn.ip,  insn.ea,  insn.itype, InstructionFunc[insn.itype].name,   insn.size);
for(i=0;i<insn.size;i++)
   { msg("%02x ",get_full_byte(CA+i)); }
msg(">\n");
msg("auxpref=%04Xh { low=%02xh  high=%02xh }\nsegpref=%02xh\ninsnpref=%02xh\nflags=%02xh\n",
     insn.auxpref,    insn.auxpref_chars.low,insn.auxpref_chars.high, insn.segpref,insn.insnpref,insn.flags);
for(i=0;i<6;i++)
   {if(insn.Operands[i].type==0)
      { break; }
    msg("Op%d = { type = ",i+1);
    switch(insn.Operands[i].type)
          {case  o_void    :msg("no operand\n");break;
           case  o_reg     :msg("reg    - General Register\n");break;
           case  o_mem     :msg("mem    - Direct Memory Reference (DATA)\n");break;
           case  o_phrase  :msg("phrase - Memory Ref [Base Reg + Index Reg]\n");break;
           case  o_displ   :msg("displ  - Memory Reg [Base Reg + Index Reg + Displacement] phrase+addr\n");break;
           case  o_imm     :msg("imm    - Immediate Value \n");break;
           case  o_far     :msg("far    - Immediate Far Address  (CODE)\n");break;
           case  o_near    :msg("near   - Immediate Near Address (CODE)\n");break;
           case  o_idpspec0:msg("idpspec0 - IDP specific type\n");break;
           case  o_idpspec1:msg("idpspec1 - IDP specific type\n");break;
           case  o_idpspec2:msg("idpspec2 - IDP specific type\n");break;
           case  o_idpspec3:msg("idpspec3 - IDP specific type\n");break;
           case  o_idpspec4:msg("idpspec4 - IDP specific type\n");break;
           case  o_idpspec5:msg("idpspec5 - IDP specific type\n");break;
           case  o_last    :msg("last     - first unused type\n");break;
           default         :msg("UNDEF\n");
          }
    msg("        offb  = %02Xh\n", insn.Operands[i].offb);
    msg("        offo  = %02Xh\n", insn.Operands[i].offo);
    msg("        flags = ");
    switch(insn.Operands[i].flags)
          {case OF_NO_BASE_DISP:msg("OF_NO_BASE_DISP \n");break;
           case OF_OUTER_DISP  :msg("OF_OUTER_DISP   \n");break;
           case PACK_FORM_DEF  :msg("PACK_FORM_DEF   \n");break;
           case OF_NUMBER      :msg("OF_NUMBER       \n");break;
           case OF_SHOW        :msg("OF_SHOW         \n");break;
           default             :msg("UNDEF           \n");
          }
    msg("        dtyp = ");
    switch(insn.Operands[i].dtyp)
          {case dt_byte    :msg("byte    \n");break;    // 8 bit
           case dt_word    :msg("word    \n");break;    // 16 bit
           case dt_dword   :msg("dword   \n");break;    // 32 bit
           case dt_float   :msg("float   \n");break;    // 4 byte
           case dt_double  :msg("double  \n");break;    // 8 byte
           case dt_tbyte   :msg("tbyte   \n");break;    // variable size (ph.tbyte_size)
           case dt_packreal:msg("packreal\n");break;    // packed real format for mc68040
           case dt_qword   :msg("qword   \n");break;    // 64 bit
           case dt_byte16  :msg("byte16  \n");break;    // 128 bit
           case dt_code    :msg("code    \n");break;    // ptr to code (not used?)
           case dt_void    :msg("void    \n");break;    // none
           case dt_fword   :msg("fword   \n");break;    // 48 bit
           case dt_bitfild :msg("bitfild \n");break;    // bit field (mc680x0)
           case dt_string  :msg("string  \n");break;    // pointer to asciiz string
           case dt_unicode :msg("unicode \n");break;    // pointer to unicode string
           case dt_3byte   :msg("3byte   \n");break;    // 3-byte data
           case dt_ldbl    :msg("ldbl    \n");break;    // long double (which may be different from tbyte)
           default         :msg("UNDEF   \n");
          }
    msg("        reg     = %02Xh\n", insn.Operands[i].reg);
    msg("        phrase  = %02Xh\n", insn.Operands[i].phrase);
    msg("        value   = %08xh { low=%04xh high=%04xh }\n",insn.Operands[i].value,insn.Operands[i].value_shorts.low,insn.Operands[i].value_shorts.high);
    msg("        addr    = %08xh { low=%04xh high=%04xh }\n",insn.Operands[i].addr,insn.Operands[i].addr_shorts.low,insn.Operands[i].addr_shorts.high);
    msg("        specval = %08xh { low=%04xh high=%04xh }\n",insn.Operands[i].specval,insn.Operands[i].specval_shorts.low,insn.Operands[i].specval_shorts.high);
    //msg("value=%08Xh ",insn.Operands[i].value);
    //msg("addr=%08Xh ",insn.Operands[i].addr);
    //msg("specval=%08Xh } ",insn.Operands[i].specval);
    msg("        specflag1 = %02Xh, specflag2 = %02Xh, specflag3 = %02Xh, specflag4 = %02Xh\n",insn.Operands[i].specflag1,insn.Operands[i].specflag2,insn.Operands[i].specflag3,insn.Operands[i].specflag4);
    msg("      }\n");
   }//for(int i=0;i<6;i++)
}// END Read_Information_Instruction(CA);
//------------------------------------------------------------------------------
void Read_Referens_Info(ea_t CA)
{
bool ret=false;
int i;
refinfo_t ref;      
reftype_t ref_type;
decode_insn(CA);//
msg("address 0:%08x\n", CA);
for(i=0;i<6;i++)
   {if(cmd.Operands[i].type==o_void)
      {break;}
    msg("operand %u - ", i);  
    ret=get_refinfo(CA, i, &ref);   
    if(ret==0)
      {msg("no refinfo\n"); continue; }
    msg("0:%08x - reference target \n", ref.target);
    msg("            0:%08x - base of reference\n", ref.base);  
    msg("            0:%08x - offset from the target\n", ref.tdelta);
    msg("            0:%08x - flags\n", ref.flags);
    ///*
    switch(ref.flags)
          {case  REFINFO_TYPE    :msg("REFINFO_TYPE - reference type\n");break;
           case  REFINFO_RVAOFF  :msg("REFINFO_RVAOFF - based reference (rva)\n");break;
           case  REFINFO_PASTEND :msg("REFINFO_PASTEND - reference past an item it may point to an nonexistitng address do not destroy alignment dirs\n");break;
           case  REFINFO_CUSTOM  :msg("REFINFO_CUSTOM - a custom reference \n");break;
           case  REFINFO_NOBASE  :msg("REFINFO_NOBASE - don't create the base xref\n");break;
           case  REFINFO_SUBTRACT:msg("REFINFO_SUBTRACT - the reference value is subtracted from the base value instead of (as usual) being added to it\n");break;
           case  REFINFO_SIGNEDOP:msg("REFINFO_SIGNEDOP - the operand value is sign-extended (only supported for REF_OFF8/16/32/64)\n");break;
          }
    ref_type=ref.type();           
    switch(ref_type)
          {case REF_OFF8  : msg("REF_OFF8   - 8bit full offset\n");break;
           case REF_OFF16 : msg("REF_OFF16  - 16bit full offset\n");break;
           case REF_OFF32 : msg("REF_OFF32  - 32bit full offset\n");break;
           case REF_LOW8  : msg("REF_LOW8   - low 8bits of 16bit offset\n");break;
           case REF_LOW16 : msg("REF_LOW16  - low 16bits of 32bit offset\n");break;
           case REF_HIGH8 : msg("REF_HIGH8  - high 8bits of 16bit offset\n");break;
           case REF_HIGH16: msg("REF_HIGH16 - high 16bits of 32bit offset\n");break;
           case REF_VHIGH : msg("REF_VHIGH  - high ph.high_fixup_bits of 32bit offset\n");break;
           case REF_VLOW  : msg("REF_VLOW   - low  ph.high_fixup_bits of 32bit offset\n");break;
           case REF_OFF64 : msg("REF_OFF64  - 64bit full offset\n");break;
           //case REF_LAST = REF_OFF64;
           
          }
    msg("\n");
    //*/
   } 
}// END Read_Referens_Info(CA);
//------------------------------------------------------------------------------

