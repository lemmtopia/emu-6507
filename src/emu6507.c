#include "emu6507.h"

globalvar cpu_state_t cpu_state;
globalvar bool8 init = FALSE;

// emu6507_execute(program_data, prorgam_size): 
//      read and interpret each byte from program_data.
void emu6507_execute(uint8* program_data, uint16 program_size)
{
    // Initialize
    cpu_state.program_counter = 0xFFC;

    cpu_state.data = program_data[cpu_state.program_counter]; 
    cpu_state.temp = cpu_state.data;
    cpu_state.program_counter++;
    cpu_state.data = program_data[cpu_state.program_counter]; 

    cpu_state.reset_vector = (cpu_state.data << 8) | cpu_state.temp;
    printf("reset_vector: %04x\n", cpu_state.reset_vector);
}
