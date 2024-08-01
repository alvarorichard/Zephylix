#ifndef ZEPHYLIX_COMPILER_H
#define ZEPHYLIX_COMPILER_H

#include "chunk.h"
#include "vm.h"
#include "object.h"
#include <stdbool.h>




static void printStatement();
ObjFunction* compile(const char* source);
void markCompilerRoots();






#endif
