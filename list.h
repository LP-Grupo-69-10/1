#include "task.h"

typedef struct node_ *list;

typedef struct node_ {
  task *data;
  list next;
} node;

list new_list();
void search(list, byte, list*, list*);
void insert(list, task*);
