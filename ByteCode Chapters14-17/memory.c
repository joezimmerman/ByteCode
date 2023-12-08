#include <stdlib.h>
#include "memory.h"
void* reallocate(void* point, size_t old, size_t new) {
  if (new == 0) {free(point); return NULL;}
  void* result = realloc(point, new);
  if(result == NULL) exit(1);
  return result;
}