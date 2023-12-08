#include <stdlib.h>
#include "memory.h"
#include "vm.h"
void* reallocate(void* point, size_t old, size_t new) {
  if (new == 0) {free(point); return NULL;}
  void* result = realloc(point, new);
  if(result == NULL) exit(1);
  return result;
}
static void freeObject(Obj* object) {
  switch (object->type) {
    case OBJ_STRING: {
      ObjString* string = (ObjString*)object;
      FREE_ARRAY(char, string->chars, string->length + 1);
      FREE(ObjString, object);
      break;
    }
  }
}
void freeObjects() {
  Obj* object = vm.objects;
  while (object != NULL) {
    Obj* next = object->next;
    freeObject(object);
    object = next;
  }
}