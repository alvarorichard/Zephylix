//
// Created by krone on 4/1/24.
//

#ifndef ZEPHYLIX_CHUNK_H
#define ZEPHYLIX_CHUNK_H

#include "../include/common.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    uint8_t* code;
} Chunk;

typedef struct{
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void intitChunk(Chunk* chunk);



#endif //ZEPHYLIX_CHUNK_H
