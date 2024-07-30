#ifndef ZEPHYLIX_COMPILER_H
#define ZEPHYLIX_COMPILER_H

#include "chunk.h"
#include "vm.h"
#include "object.h"
#include <stdbool.h>



bool compile(const char* source, Chunk* chunk);



#endif
