#ifndef OPCODES_H
#define OPCODES_H

#include "typedefs.h"

typedef struct __emu_opcode
{
   uint8 opcode;
   uint8 cycle_count;
   uint8 byte_count;

   char mnemonic[3];
} emu_opcode_t;

#endif // OPCODES_H
