#include <stdlib.h>
#include "list.h"

list new_list() {
  return (list)malloc(sizeof(node));
}

void search_priority(list l, byte key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;
  
  while(*cur != NULL && (*cur)->data->priority > key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->priority != key)
    *cur = NULL;
}

void insert(list l, task *t) {
  list to_add = (list)malloc(sizeof(node));
  list prev,_;

  if(to_add != NULL) {
    to_add->data = t;
    search_priority(l, t->priority, &prev, &_);
    to_add->next = prev->next;
    prev->next = to_add;
  }
}

void search_id(list l, unsigned short key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;
  
  while(*cur != NULL && (*cur)->data->id != key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->id != key)
    *cur = NULL;
}

void remove_task(list l, task *t) {
  list prev,to_remove;
  search_id(l,t->id,&prev,&to_remove);
  prev->next = to_remove->next;
  free(to_remove);
}
