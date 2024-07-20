#ifndef ZEPHYLIX_DEBUG_H
#define ZEPHYLIX_DEBUG_H

#include "value.h"
#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk,int offset);



#endif //ZEPHYLIX_DEBUG_H