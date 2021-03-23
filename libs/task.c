#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

unsigned short ID_COUNT = 1;

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

void load_id(char *filename) {
  FILE *fp = fopen(filename, "rb");

  if(fp != NULL)
    (void)fread(&ID_COUNT, sizeof(unsigned short), 1, fp);

  fclose(fp);
}

void set_priority(task *t, byte p) {
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
