//
// Created by krone on 4/2/24.
//

#include "../include/memory.h"
#include "../include/common.h"
#include <stdlib.h>

void *reallocate(void *pointer, size_t oldSize, size_t newSize)
{
  if (newSize == 0)
   {
    free(pointer);
    return NULL;
   }

  void *result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1);
  return result;
}
