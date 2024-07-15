//
// Created by krone on 4/2/24.
//

#include "../include/chunk.h"

#include <stdlib.h>

#include "../include/memory.h"

void initChunk(Chunk* chunk)
{
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  // The dynamic array starts off completely empty.
  //  We don’t even allocate a raw array yet.
  //  To append a byte to the end of the chunk, we use a new function.
}
void writeChunk(Chunk* chunk, uint8_t byte)
{
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = GROW_ARRAY(chunk->code, uint8_t oldCapacity, chunk->capacity);
  }
  chunk->code[chunk->count] = byte;
  chunk->count++;
}

void freeChunk(Chunk* chunk)
{
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  initChunk(chunk);
}