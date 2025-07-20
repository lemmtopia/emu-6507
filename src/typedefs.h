#ifndef TYPEDEFS_H
#define TYPEDEF_SH

#include <stdint.h>

// Rename basic data types.
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8 bool8;
typedef int32 bool32;

typedef float float32;
typedef double float64;

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

// The CPU state struct
typedef struct __cpu_state 
{
    /* CPU pins  */
    uint16 address;
    uint8 data;

    /* CPU internals */
    uint8 accumulator, x, y;
    uint16 program_counter;
    uint8 stack_pointer;
   
    // NOTE(lemmtopia): only 7-bits in the physical CPU, but use uint8.
    e_status_flags_t status_flags; 
} cpu_state_t;

#endif // TYPEDEFS_H
