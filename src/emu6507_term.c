/* 
 * =================================================================
 * emu6507_term: Run a program emulating a 6507 CPU in the terminal. 
 * =================================================================
 */
#include <stdio.h>
#include <stdlib.h>

// include custom .h files
#include "typedefs.h"
#include "opcodes.h"
#include "emu6507.h"

// include custom .c files (for unity build)
#include "opcodes.c"
#include "emu6507.c"

typedef struct __emu_bin_file 
{
    // NOTE(lemmtopia): Support only 16-bit sizes files because the 
    //                      processor can only read 13-bit ROMs.
    uint16 size;
    uint8* data;
} emu_bin_file_t;

// emu6507_term_read_file(f, bin_file): 
//      Read f and store the data + the size inside bin_file.
void emu6507_term_read_file(FILE* f, emu_bin_file_t* bin_file) 
{
    fseek(f, 0, SEEK_END);
    bin_file->size = ftell(f);
    rewind(f);

    bin_file->data = malloc(bin_file->size);
    fread(bin_file->data, 1, bin_file->size, f);
}

// main(argc, argv): read program from argv[1] and execute it.
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("usage: emu6507_term <bin-file>\n");
        return 0;
    }

    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) 
    {
        fprintf(stderr, "error: could not open %s\n", argv[1]);
        return -1;
    }

    emu_bin_file_t bin_file; 
    emu6507_term_read_file(f, &bin_file);

    printf("file size: %d\n", bin_file.size);
    for (int i = 0; i < bin_file.size; i++) 
    {
        printf("%02x ", bin_file.data[i]);
        if (i > 0 && i % 8 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
    emu6507_execute_loop(bin_file.data, bin_file.size);

    fclose(f);
    return 0;
}
