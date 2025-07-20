#include "emu6507.h"

globalvar cpu_state_t cpu_state;

// emu6507_initialize(program_data, program_size): 
//      Initialie the CPU by reading memory address 0x0FFC
//      and jumping to the correct location read.
//      Returns TRUE if the file size is 4KB and 
//      the jump was successful.
bool8 emu6507_initialize(uint8* program_data, uint16 program_size)
{
    // Initialize
    cpu_state.program_counter = 0x0FFC;

    if (cpu_state.program_counter  > program_size)
    {
        fprintf(stderr, "error: invalid file size! must be 4KB\n");
        return FALSE;
    }

    cpu_state.data = program_data[cpu_state.program_counter]; 
    cpu_state.temp = cpu_state.data;
    cpu_state.program_counter++;
    cpu_state.data = program_data[cpu_state.program_counter]; 

    uint32 raw_reset_vector = (cpu_state.data << 8) | cpu_state.temp;
    cpu_state.reset_vector = (uint16)(raw_reset_vector - MEMORY_NORMALIZE_FACTOR);
    cpu_state.address = cpu_state.reset_vector;

    return TRUE;
}

// emu6507_execute(program_data, prorgam_size): 
//      read and interpret each byte from program_data.
void emu6507_execute(uint8* program_data, uint16 program_size)
{
    cpu_state.active = emu6507_initialize(program_data, program_size);
    if (!cpu_state.active) 
    {
        return;
    }

    printf("reset_vector: %04x\n", cpu_state.reset_vector);

    /* actually execute something */
    while (cpu_state.active)
    {
        cpu_state.data = program_data[cpu_state.address];

        // TODO(lemmtopia): Access opcode array with the cpu_state.data 
    }
}
