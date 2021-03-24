#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

int ID_COUNT = 1;

task *new_task() {
  task *t = (task*)malloc(sizeof(task));
  t->id = ID_COUNT++;
  t->priority = 0;
  t->creation = time(NULL);
  t->description[0] = '\0';
  t->person[0] = '\0';
  t->deadline = (time_t)0;
  t->conclusion = (time_t)0;
    
  return t;
}

void set_priority(task *t, int p) {
  t->priority = p;
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

char* print_task(task *t) {
  if(t == NULL) return "                                   ";
  
  char *s = malloc(100 * sizeof(char));
  char *temp = malloc(10 * sizeof(char));
  sprintf(temp, "%d", t->id);

  sprintf(s, "(#%s): %s, %s                              ", temp, t->person, t->description);
  
  return s;
}
