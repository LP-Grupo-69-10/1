// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"
#include "file.h"
#include "menu.h"
#include "safe.h"

list TO_DO;
list DOING;
list DONE;

void load_lists() {
  TO_DO = read_fl(".files/to_do");
  DOING = read_fl(".files/doing");
  DONE  = read_fl(".files/done");
}

void write_lists() {
  write_lf(TO_DO, ".files/to_do");
  write_lf(DOING, ".files/doing");
  write_lf(DONE,  ".files/done");
}

void print_menu() {
  printf("\n+------------------------------------------------------+\n");
  printf("| MENU:                                                |\n");
  printf("+------------------------------------------------------+\n");
  printf("|                                                      |\n");
  printf("| 1 - Inserir nova tarefa                              |\n");
  printf("| 2 - Ver tarefa                                       |\n");
  printf("| 3 - Mover cartões                                    |\n");
  printf("| 4 - Alterar a pessoa responsável                     |\n");
  printf("| 5 - Fechar tarefa                                    |\n");
  printf("| 6 - Reabrir tarefa                                   |\n");
  printf("| 7 - Visualizar o quadro                              |\n");
  printf("| 8 - Visualizar as tarefas de uma pessoa              |\n");
  printf("| 9 - Visualizar tarefas ordenadas por data de criação |\n");
  printf("| 0 - Terminar                                         |\n");
  printf("|                                                      |\n");
  printf("+------------------------------------------------------+\n");
}

void insert_new_task() {
  task *t = new_task();
  
  read_priority(&t->priority);  
  read_description(t->description);
  read_person(t->person);
  read_deadline(&t->deadline);
  
  insert_priority(TO_DO, t);
}

void see_task() {
  int id;
  read_id(&id);

  task *t;
  if((t = find_task(TO_DO, id)) != NULL) print_task(t);
  else if((t = find_task(DOING, id)) != NULL) print_task(t);
  else if((t = find_task(DONE, id)) != NULL) print_task(t);
  else printf("Tarefa não encontrada.\n");
}

void start_task() {
  int id;
  read_id(&id);
  
  task *to_start = find_task(TO_DO, id);
  if(to_start != NULL) {
  
    while(to_start->person[0] == '\0') {
      printf("Tem que especificar o responsável.");
      read_person(to_start->person);
    }

    while(to_start->deadline == 0) {
      printf("Tem que especificar o prazo.");
      read_deadline(&to_start->deadline);
    }
    
    remove_task(TO_DO, id);
    insert_priority(DOING, to_start);
  }
  
  else {
    to_start = find_task(DOING, id);
    if(to_start == NULL) {
      printf("Tarefa não encontrada.\n");
      return;
    }
    
    remove_task(DOING, id);
    insert_priority(TO_DO, to_start);
  }
}

void change_responsible() {
  int id;
  read_id(&id);

  if(find_task(DOING, id) != NULL) {
    char *person = malloc(60 * sizeof(char));
    read_person(person);
    edit_person(DOING, id, person);
  }
  
  else {
    printf("Tarefa não encontrada.\n");
  }
}

void end_task() {
  int id;
  read_id(&id);

  task *to_add = find_task(DOING, id);
  if(to_add != NULL) {
    to_add->conclusion = time(NULL);
    remove_task(DOING, id);
    insert_priority(DONE, to_add);
  }

  else {
    printf("Tarefa não encontrada.\n");
  }
}

void redo_task() {
  int id;
  read_id(&id);
  
  task *to_add = find_task(DONE, id);

  if(to_add != NULL) {
    remove_task(DONE, id);
    
    to_add->creation = time(NULL);
    to_add->conclusion = 0; 
  
    insert_priority(TO_DO, to_add);
  }

  else {
    printf("Tarefa não encontrada.\n");
  }
}

void print_by_priority() {
  print_board(TO_DO, DOING, DONE);
}

void print_by_person() {
  char *s = malloc(60 * sizeof(char));
  read_person(s);
  print_board(person_list(TO_DO, s), person_list(DOING, s), person_list(DONE, s));
}

void print_by_creation() {
  print_board(creation_list(TO_DO), creation_list(DOING), creation_list(DONE));
}

void print_board(list to_do, list doing, list done) {
  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  printf("|               TO DO               |               DOING               |                DONE               |\n");
  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");

  do {
    if(to_do != NULL) to_do = to_do->next;
    if(doing != NULL) doing = doing->next;
    if(done  != NULL) done  = done->next;
    
    char *s1 = string_task((to_do != NULL ? to_do->data : NULL));
    char *s2 = string_task((doing != NULL ? doing->data : NULL));
    char *s3 = string_task((done  != NULL ? done->data  : NULL));
    
    printf("| %.33s | %.33s | %.33s |\n", s1, s2, s3);
  }  while(to_do != NULL || doing != NULL || done != NULL);

  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  printf("- (#n): ID da tarefa\n");
}
