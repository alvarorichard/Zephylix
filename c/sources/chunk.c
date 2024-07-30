// //
// // Created by krone on 4/2/24.
// //

// #include "../include/chunk.h"

// #include <stdlib.h>

// #include "../include/memory.h"
// #include "../include/common.h"
// #include "../include/value.h"
// #include "../include/chunk.h"

// void initChunk(Chunk *chunk)
// {
// 	chunk->count = 0;
// 	chunk->capacity = 0;
// 	chunk->code = NULL;
// 	freeValueArray(&chunk -> constants);
// 	// The dynamic array starts off completely empty.
// 	//  We don’t even allocate a raw array yet.
// 	//  To append a byte to the end of the chunk, we use a new function.
// }
// void writeChunk(Chunk *chunk, uint8_t byte)
// {
// 	if (chunk->capacity < chunk->count + 1) {
// 		int oldCapacity = chunk->capacity;
// 		chunk->capacity = GROW_CAPACITY(oldCapacity);
// 		chunk->code = GROW_ARRAY(chunk->code, uint8_t oldCapacity,
// 					 chunk->capacity);
// 	}
// 	chunk->code[chunk->count] = byte;
// 	chunk->count++;
// }

// void freeChunk(Chunk *chunk)
// {
// 	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
// 	initChunk(chunk);
// 	freeValueArray(&chunk -> constants);
// }
//

#include "../include/chunk.h"

#include <stdlib.h>

#include "../include/memory.h"
#include "../include/value.h"

void initChunk(Chunk *chunk)
{
	chunk -> count = 0;
	chunk -> capacity = 0;
	chunk -> code = NULL;
	chunk -> lines = NULL; 
	freeValueArray(&chunk->constants);
}




void writeChunk(Chunk* chunk, uint8_t byte, int line)
{
	if (chunk->capacity < chunk->count + 1)
    {
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity,
					 chunk->capacity);
		chunk -> lines = GROW_ARRAY(int, chunk -> lines, oldCapacity, chunk -> capacity);
	}
	chunk->code[chunk->count] = byte;
	chunk -> lines[chunk -> count] = line;
	chunk->count++;
	
}

int addConstant(Chunk* chunk,Value value)
{
    writeValueArray(&chunk -> constants, value);
    return chunk -> constants.count - 1;
}

int addConstant(Chunk* chunk, Value value);

void freeChunk(Chunk *chunk)
{
   	initChunk(chunk);
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(int, chunk -> lines, chunk -> capacity);
	freeValueArray(&chunk -> constants);
}
