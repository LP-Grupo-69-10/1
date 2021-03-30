// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

list new_list() {
  list l = (node*)malloc(sizeof(node));
  l->data = NULL;
  l->next = NULL;

  return l;
}

void add_first(list l, task *t) {
  list to_add = (list)malloc(sizeof(node));
  list post = l->next;

  if(to_add != NULL) {
    to_add->data = t;
    l->next = to_add;
    to_add->next = post;
  }
}

void search_priority(list l, int key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;

  while(*cur != NULL && (*cur)->data->priority > key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->priority != key) {    
    *cur = NULL;
  }
}

void insert_priority(list l, task *t) {
  list to_add = (list)malloc(sizeof(node));
  list prev, _;

  if(to_add != NULL) {
    to_add->data = t;
    search_priority(l, t->priority, &prev, &_);
    to_add->next = prev->next;
    prev->next = to_add;
  }
}

void search_id(list l, int key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;

  while(*cur != NULL && (*cur)->data->id != key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->id != key) {
    *cur = NULL;
  }
}

void remove_task(list l, int key) {
  list prev, to_remove;
  search_id(l, key, &prev, &to_remove);
  prev->next = to_remove->next;
  free(to_remove);
}

void edit_person(list l, int key, char *person) {
  list _, cur;
  search_id(l, key, &_, &cur);
  strcpy(cur->data->person, person);
  free(person);
}

list person_list(list l, char *person) {
  list ans = new_list();
  while((l = l->next) != NULL) {
    if(strcmp(l->data->person, person) == 0) {
      insert_priority(ans, l->data);
    }
  }
  
  return ans;
}

void search_creation(list l, time_t key, list *prev, list *cur) {
  *prev = l;
  *cur = l->next;

  while(*cur != NULL && (*cur)->data->creation < key) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if(*cur != NULL && (*cur)->data->creation != key) {
    *cur = NULL;
  }
}

void insert_creation(list l, task *t) {
  list to_add = (list)malloc(sizeof(node));
  list prev,_;

  if(to_add != NULL) {
    to_add->data = t;
    search_creation(l, t->creation, &prev, &_);
    to_add->next = prev->next;
    prev->next = to_add;
  }
}

list creation_list(list l) {
  list ans = new_list();
  
  while((l = l->next) != NULL) {
    insert_creation(ans, l->data);
  }
  
  return ans;
}

task *find_task(list l, int key) {
  list _, cur;
  search_id(l, key, &_, &cur);
  
  return (cur == NULL ? NULL : cur->data);
}
