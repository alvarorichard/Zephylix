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
  int count;
  int capacity;
} Chunk;



void intitChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);
void freeChunk(Chunk* chunk);

#endif // ZEPHYLIX_CHUNK_H
