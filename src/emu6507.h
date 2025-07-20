#ifndef EMU6507_H
#define EMU6507_H

#include "typedefs.h"

// CPU defines
typedef enum STATUS_FLAGS
{
    SF_CARRY,
    SF_ZERO,
    SF_INTERRUPT,
    SF_DECIMAL_MODE,
    SF_UNUSED_1,
    SF_UNUSED_2,
    SF_OVERFLOW,
    SF_NEGATIVE,

    SF_MAX          // Number of status flags
} e_status_flags_t;

#define MEMORY_NORMALIZE_FACTOR 0xF000

// The CPU state struct
typedef struct __cpu_state 
{
    bool8 active;

    /* CPU pins  */
    uint16 address;
    uint8 data;

    /* CPU internals */
    uint8 accumulator, x, y;
    uint16 program_counter;
    uint8 stack_pointer;
   
    // NOTE(lemmtopia): only 7-bits in the physical CPU, but use uint8.
    e_status_flags_t status_flags; 

    uint8 temp;                 // Utils

    uint16 reset_vector;
    uint16 interrupt_vector;    // UNUSED
} cpu_state_t;

bool8 emu6507_initialize(uint8* program_data, uint16 program_size);
void emu6507_execute(uint8* program_data, uint16 program_size);

#endif // EMU6507_H
