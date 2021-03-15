#include "task.h"

typedef struct node_ *list;

typedef struct node_ {
  task *data;
  list next;
} node;

list new_list();
void search_priority(list, byte, list*, list*); // based on priority (order)
void insert(list, task*);
void search_id(list, unsigned short, list*, list*); // based on id (no order)
void remove_task(list, task*);
void edit_person(list, unsigned short, char*);
list person_list(list, char*);
void print_list(list, byte);
