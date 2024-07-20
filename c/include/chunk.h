//
// Created by krone on 4/1/24.
//

#ifndef ZEPHYLIX_CHUNK_H
#define ZEPHYLIX_CHUNK_H

#include "../include/common.h"
#include "../include/value.h"
#include <stdint.h>

typedef enum {
	OP_RETURN,
	OP_CONSTANT,
} OpCode;

typedef struct
{
	uint8_t *code;
	int       count;
	int       capacity;
	int       *lines;
	
	
	ValueArray constants;
	
} Chunk;

void intitChunk(Chunk *chunk);
//void writeChunk(Chunk *chunk, uint8_t byte);
void freeChunk(Chunk *chunk);
int addConstant(Chunk* chunk, Value value);
void writeChunk(Chunk* chunk, uint8_t byte, int line);


#endif // ZEPHYLIX_CHUNK_H
