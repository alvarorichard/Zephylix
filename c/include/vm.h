#ifndef ZEPHYLIX_VM_H
#define ZEPHYLIX_VM_H

#include "chunk.h"
#include "value.h"
#include "table.h"

#define STACK_MAX 256

typedef struct {
	Chunk *chunk;
	uint8_t *ip;
	Value stack[STACK_MAX];
	Value *stackTop;
	Obj* objects;
	Table strings;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpretSource(const char* source);
InterpretResult interpretChunk(Chunk* chunk);
void push(Value value);
Value pop();

#endif // ZEPHYLIX_VM_H