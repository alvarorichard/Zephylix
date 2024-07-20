#include "../include/chunk.h"
#include "../include/debug.h"
#include "../include/vm.h"
#include <stdlib.h>

#define EXIT_SUCCESS 0

int main(int argc, char* argv[])
{   
    initVM();
    Chunk chunk;
    intitChunk(&chunk);  // Corrected typo here

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    constant = addConstant(&chunk, 3.4);
     writeChunk(&chunk, OP_CONSTANT, 123);
     writeChunk(&chunk, constant, 123);
   
     writeChunk(&chunk, OP_ADD, 123);
   
     constant = addConstant(&chunk, 5.6);
     writeChunk(&chunk, OP_CONSTANT, 123);
     writeChunk(&chunk, constant, 123);
   
     writeChunk(&chunk, OP_DIVIDE, 123);
    writeChunk(&chunk, OP_NEGATE, 123);
    writeChunk(&chunk, (uint8_t)constant, 1);  // Pass the constant index
    writeChunk(&chunk, OP_RETURN, 123);    
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return EXIT_SUCCESS;
}
