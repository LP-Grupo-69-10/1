#include "task.h"

typedef struct node_ *list;

typedef struct node_ {
  task *data;
  list next;
} node;

list new_list();
