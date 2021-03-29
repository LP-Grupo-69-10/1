// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

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

char *string_task(task*);

#endif /* TASK_H */
