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

#define SPACES "                                                                 "

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
  sprintf(s, "(#%d): %s, %s [%d]", t->id, (t->person[0] == '\0' ? "N/D" : t->person), t->description, t->priority);

  if(strlen(s) > 33) {
    s[30] = s[31] = s[32] = '.';
  }
  strcat(s, SPACES);
  
  return s;
}

void print_task(task *t) {
  char *s = "+-------------+--------------------------------------------+";
  char *line = malloc(100*sizeof(char));


  // Prioridade
  sprintf(line, "%d%s", t->priority, SPACES);
  printf("%s\n| Prioridade  | %.42s |\n%s\n", s, line, s);

  // Data de criação
  line = ctime(&t -> creation);
  line[strlen(line)-1] = '\0';
  strcat(line, SPACES);
  printf("| Criação     | %.42s |\n%s\n", line, s);

  // Descrição
  sprintf(line, "%s%s", t->description, SPACES);
  printf("| Descrição   | %.42s |\n%s\n", line, s);

  // Responsável
  sprintf(line, "%s%s", (t->person[0] == '\0' ? "Não definido" : t->person),SPACES);
  printf("| Responsável | %.42s |\n%s\n", line, s);
  
  // Prazo
  if(t->deadline == 0) {
    sprintf(line, "Não definido%s", SPACES);
  }
  else {
    line = ctime(&t->deadline);
    line[strlen(line)-1] = '\0';
    strcat(line, SPACES);
  }
  
  printf("| Prazo       | %.42s |\n%s\n", line, s);

  // Conlusão
  if(t->conclusion == 0) {
    sprintf(line, "Nao terminada%s", SPACES);
  }
  else {
    line = ctime(&t->conclusion);
    line[strlen(line)-1] = '\0';
    strcat(line, SPACES);
  }
  
  printf("| Conclusao   | %.42s |\n%s\n", line, s);
}
