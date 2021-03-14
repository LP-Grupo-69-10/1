#include <stdlib.h>
#include <string.h>
#include "task.h"

task *new_task() {
  return (task*)malloc(sizeof(task));
}

void set_id(task *t, unsigned short i) {
  t->id = i;
}

void set_priority(task *t, byte p) {
  t->priority = p;
}

void set_creation(task *t, time_t d) {
  t->priority = d;
}

void set_description(task *t, char *d) {
  strcpy(t->description, d);
}

void set_person(task *t, char *p) {
  strcpy(t->person, p);
}

void set_deadline(task *t, time_t d) {
  t->priority = d;
}

void set_conclusion(task *t, time_t d) {
  t->priority = d;
}
