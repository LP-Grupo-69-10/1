#include <stdlib.h>
#include "list.h"

list new_list() {
  list l = (list)malloc(sizeof(task));
  l->data = new_task();
  return l;
}


