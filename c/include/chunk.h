// //
// // Created by krone on 4/1/24.
// //

// #ifndef ZEPHYLIX_CHUNK_H
// #define ZEPHYLIX_CHUNK_H

// #include "common.h"
// #include "value.h"
// #include <stdint.h>

// typedef enum {
// 	OP_RETURN,
// 	OP_CONSTANT,
// 	OP_NEGATE,
// 	OP_ADD,
// 	OP_SUBTRACT,
// 	OP_MULTIPLY,
// 	OP_DIVIDE,
// } OpCode;

// typedef struct {
// 	uint8_t *code;
// 	int count;
// 	int capacity;
// 	int *lines;

// 	ValueArray constants;

// } Chunk;

// void intitChunk(Chunk *chunk);
// // void writeChunk(Chunk *chunk, uint8_t byte);
// void freeChunk(Chunk *chunk);
// int addConstant(Chunk *chunk, Value value);
// void writeChunk(Chunk *chunk, uint8_t byte, int line);

// #endif // ZEPHYLIX_CHUNK_H

//
// Created by krone on 4/1/24.
//

#ifndef ZEPHYLIX_CHUNK_H
#define ZEPHYLIX_CHUNK_H

#include "common.h"
#include "value.h"
#include <stdint.h>

typedef enum {
    OP_RETURN,
    OP_CONSTANT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NIL,
    OP_TRUE,
    OP_NOT,
    OP_FALSE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
} OpCode;

typedef struct {
    uint8_t *code;
    int count;
    int capacity;
    int *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);  // Corrected typo here
void freeChunk(Chunk *chunk);
int addConstant(Chunk *chunk, Value value);
void writeChunk(Chunk *chunk, uint8_t byte, int line);

#endif // ZEPHYLIX_CHUNK_H
