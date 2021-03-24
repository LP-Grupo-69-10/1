#ifndef TASK_H
#define TASK_H

#include <time.h>

extern int ID_COUNT;


typedef struct {
  int id;
  int priority;
  time_t creation;
  char description[50];
  char person[50];
  time_t deadline;
  time_t conclusion;
} task;

task *new_task();

void set_priority(task*, int);
void set_description(task*, char*);
void set_person(task*, char*);
void set_deadline(task*, time_t);
void set_conclusion(task*, time_t);

char *print_task(task*);

#endif /* TASK_H */
