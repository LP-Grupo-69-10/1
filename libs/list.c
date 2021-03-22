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
  list prev, to_remove;
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

    if( b &  1) printf("id: %hu\n", l->data->id);
    if( b &  2) printf("prioridade: %hhd\n", l->data->priority);
    if( b &  4) printf("criado em %s", ctime(&l->data->creation));
    if( b &  8) printf("descricao: %s\n", l->data->description);
    if( b & 16) printf("responsavel: %s\n", l->data->person);
    if((b & 32) && l->data->deadline != 0)
      printf("prazo a %s", ctime(&l->data->deadline));
    if((b & 64) && l->data->conclusion != 0)
      printf("concluido a %s", ctime(&l->data->conclusion));
    
    putchar('\n');
  }
}
