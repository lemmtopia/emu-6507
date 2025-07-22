#ifndef OPCODES_H
#define OPCODES_H

#include "typedefs.h"

typedef enum __e_emu_opcode 
{
    // 0x0X
    O_BRK_IMPL  = 0x00,
    O_ORA_IND_X = 0x01,
    O_ORA_ZPG   = 0x05,
    O_ASL_ZPG   = 0x06,
    O_PHP_IMPL  = 0x08,
    O_ORA_IMM   = 0x09,
    O_ASL_ACCUM = 0x0A,
    O_ORA_ABS   = 0x0D,
    O_ASL_ABS   = 0x0E,
    
    // 0x1X
    O_BPL_REL   = 0x10,
    O_ORA_IND_Y = 0x11,
    O_ORA_ZPG_X = 0x15,
    O_ASL_ZPG_X = 0x16,
    O_CLC_IMPL  = 0x18,
    O_ORA_ABS_Y = 0x19,
    O_ORA_ABS_X = 0x1D,
    O_ASL_ABS_X = 0x1E,

    // 0x2X
    O_JSR_ABS   = 0x20,
    O_ANC_IND_X = 0x21,
    O_BIT_ZPG   = 0x24,
    O_AND_ZPG   = 0x25,
    O_ROL_ZPG   = 0x26,
    O_PLP_IMPL  = 0x28,
    O_AND_IMM   = 0x29,
    O_ROL_ACCUM = 0x2A,
    O_BIT_ABS   = 0x2C,
    O_AND_ABS   = 0x2D,
    O_ROL_ABS   = 0x2E,

    // NOP
    O_NOP_IMPL  = 0xEA,

    // TODO(lemmtopia): the rest
} e_emu_opcode_t;

typedef struct __emu_opcode
{
   uint8 opcode;
   uint8 cycle_count;
   uint8 byte_count;

   char mnemonic[3];
} emu_opcode_t;

#endif // OPCODES_H
