#ifndef ZEPHYLIX_VM_H
#define ZEPHYLIX_VM_H

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
	Chunk *chunk;
	uint8_t *ip;
	Value stack[STACK_MAX];
	Value *stackTop;
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

void push(Value value);
Value pop();

void initVM();
void freeVM();

#endif // ZEPHYLIX_VM_H