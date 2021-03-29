// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#ifndef LIST_H
#define LIST_H

#include "task.h"

typedef struct node_ *list;

typedef struct node_ {
  task *data;
  list next;
} node;

list new_list();
void add_first(list, task*);

void search_priority(list, int, list*, list*);
void insert(list, task*);

void search_id(list, int, list*, list*);
void remove_task(list, int);

void edit_person(list, int, char*);
list person_list(list, char*);

task *find_task(list, int);

void print_list(list, int);

#endif /* LIST_H */
