//
// Created by krone on 4/2/24.
//

#ifndef ZEPHYLIX_MEMORY_H
#define ZEPHYLIX_MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount)          \
	(type *)reallocate(pointer, sizeof(type) * (oldCount), \
			   sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
	reallocate(pointer, sizeof(type) * (oldCount), 0)

void *reallocate(void *pointer, size_t oldSize, size_t newSize);

// This macro pretties up a function call to reallocate() where the real work
// happens.
//  The macro itself takes care of getting the size of the array’s element type
//  and casting the resulting void* back to a pointer of the right type.

// This reallocate() function is the single function we’ll use for all dynamic
// memory management in clox—allocating memory,
//  freeing it, and changing the size of an existing allocation. Routing all of
//  those operations through a single function will be important later when we
//  add a garbage collector that needs to keep track of how much memory is in
//  use.

#endif // ZEPHYLIX_MEMORY_H
