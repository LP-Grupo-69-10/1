#include <stdlib.h>
#include "list.h"

list new_list() {
  list l = (list)malloc(sizeof(task));
  l->data = new_task();
  return l;
}

void search(list l, byte key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;

  while(*cur != NULL && (*cur)->data->priority < key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->priority != key)
    *cur = NULL;
}

void insert(list l, task *t) {
  list to_add = (list)malloc(sizeof(node));
  list prev, _;
  
  if(to_add != NULL) {
    to_add->data = t;
    search(l, t->priority, &prev, &_);
    to_add->next = prev->next;
    prev->next = to_add;
  }
}


