#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
  search_id(l, t->id, &prev, &to_remove);
  prev->next = to_remove->next;
  free(to_remove);
}

void edit_person(list l, unsigned short key, char *person) {
  list _, cur;
  search_id(l, key, &_, &cur);
  strcpy(cur->data->person, person);

}

list person_list(list l, char *person) {
  list r = new_list();
  while((l = l->next) != NULL) {
    if(strcmp(l->data->person, person) == 0) {
      insert(r, l->data);
    }
  }
  return r;
}

void print_list(list l, byte b) {
  while((l = l->next) != NULL) {

    if(b &  1) printf("%hu\n", l->data->id);
    if(b &  2) printf("%hhd\n", l->data->priority);
    if(b &  4) printf("time\n");
    if(b &  8) printf("%s\n", l->data->description);
    if(b & 16) printf("%s\n", l->data->person);
    if(b & 32) printf("time max\n");
    if(b & 64) printf("time cls\n");
    
    printf("\n");
  }
}
