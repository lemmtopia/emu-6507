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

// basic defines
#define TRUE 1
#define FALSE 0

#define globalvar static
#define internal static

#endif // TYPEDEFS_H
