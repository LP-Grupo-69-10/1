#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

task *new_task() {
  task *t = (task*)malloc(sizeof(task));
  t->id = 0;
  t->priority = 0;
  t->creation = time(NULL);
  t->description = (char*)malloc(50*sizeof(char));
  t->person = (char*)malloc(50*sizeof(char));
  t->deadline = (time_t)0; // (time_t*)malloc(sizeof(time_t));
  t->conclusion = (time_t)0; // (time_t*)malloc(sizeof(time_t));
    
  return t;
}

void set_id(task *t, unsigned short i) {
  t->id = i;
}

void set_priority(task *t, byte p) {
  t->priority = p;
}

void set_creation(task *t, time_t d) {
  t->creation = d;
}

void set_description(task *t, char *d) {
  strcpy(t->description, d);
}

void set_person(task *t, char *p) {
  strcpy(t->person, p);
}

void set_deadline(task *t, time_t d) {
  t->deadline = d;
}

void set_conclusion(task *t, time_t d) {
  t->conclusion = d;
}
