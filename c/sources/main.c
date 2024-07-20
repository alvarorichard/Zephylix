#include "../include/chunk.h"
#include "../include/debug.h"
#include <stdlib.h>

#define EXIT_SUCCESS 0

int main(int argc, char* argv[]) {
    Chunk chunk;
    intitChunk(&chunk);  // Corrected typo here

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, (uint8_t)constant, 1);  // Pass the constant index
    writeChunk(&chunk, OP_RETURN, 1);

    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return EXIT_SUCCESS;
}
