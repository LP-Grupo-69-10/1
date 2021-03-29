// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

#define SPACES "                                   "

int ID_COUNT = 1000;

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

char *string_task(task *t) {
  if(t == NULL) {
    return SPACES;
  }
  
  char *s = malloc(100 * sizeof(char));
  sprintf(s, "(#%d): %s, %s [%d]%s", t->id, t->person, t->description, t->priority, SPACES);
  
  return s;
}
