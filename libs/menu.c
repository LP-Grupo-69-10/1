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
  printf("| 2 - Mover cartões                                    |\n");
  printf("| 3 - Alterar a pessoa responsável                     |\n");
  printf("| 4 - Fechar tarefa                                    |\n");
  printf("| 5 - Reabrir tarefa                                   |\n");
  printf("| 6 - Visualizar o quadro                              |\n");
  printf("| 7 - Visualizar as tarefas de uma pessoa              |\n");
  printf("| 8 - Visualizar tarefas ordenadas por data de criação |\n");
  printf("| 0 - Terminar                                         |\n");
  printf("|                                                      |\n");
  printf("+------------------------------------------------------+\n");
}

void insert_new_task() {
  task *t = new_task();
  
  read_priority(&t->priority);  
  read_description(t->description);
  read_person(t->person);
  
  insert_priority(TO_DO, t);
}

void start_task() {
  int id = 1002;
  read_id(&id);
  
  task *to_start = find_task(TO_DO, id);
  if(to_start != NULL) {
  
    while(to_start->person[0] == '\0') {
      printf("Tem que especificar o responsável.");
      read_person(to_start->person);
    }

    /*
    time_t deadline;
    read_deadline(&deadline);
    */
    
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

  char *person = malloc(60 * sizeof(char));
  read_person(person);

  if(find_task(TO_DO, id) != NULL) edit_person(TO_DO, id, person);
  else if(find_task(DOING, id) != NULL) edit_person(DOING, id, person);
  else if(find_task(DONE, id) != NULL) edit_person(DONE, id, person);
  else printf("Tarefa não encontrada.\n");
}

void end_task() {
  int id;
  read_id(&id);

  task *to_add = find_task(DOING, id);
  if(to_add == NULL) {
      printf("Tarefa não encontrada.\n");
      return;
    }

  to_add->conclusion = time(NULL);
  remove_task(DOING, id);
  insert_priority(DONE, to_add);
}

void redo_task() {
  int id;
  read_id(&id);
  
  task *to_add = find_task(DONE, id);
  remove_task(DONE, id);
  
  to_add->creation = time(NULL);
  to_add->conclusion = 0; 
  
  insert_priority(TO_DO, to_add);
}

void print_board() {
  list run1 = TO_DO->next, run2 = DOING->next, run3 = DONE->next;
  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  printf("|               TO DO               |               DOING               |                DONE               |\n");
  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");

  if(run1 == NULL && run2 == NULL && run3 == NULL) {
    printf("|                                   |                                   |                                   |\n");
    return;
  }
  
  while(run1 != NULL || run2 != NULL || run3 != NULL) {
    char *s1 = string_task((run1 != NULL ? run1->data : NULL));
    char *s2 = string_task((run2 != NULL ? run2->data : NULL));
    char *s3 = string_task((run3 != NULL ? run3->data : NULL));
    
    printf("| %.33s | %.33s | %.33s |\n", s1, s2, s3);
    
    if(run1 != NULL) run1 = run1->next;
    if(run2 != NULL) run2 = run2->next;
    if(run3 != NULL) run3 = run3->next;
  }

  printf("+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  printf("- (#n): ID da tarefa\n");
}

void print_by_person() {
  list l;    
  char *s = malloc(60 * sizeof(char));
  read_person(s);
  
  l = person_list(TO_DO, s);
  print_list(l, 127);
  l = person_list(DOING, s);
  print_list(l, 127);
  l = person_list(DONE, s);
  print_list(l, 127);
}

void print_by_creation() {
  list l;
  
  l = creation_list(TO_DO);
  print_list(l, 127);
  l = creation_list(DOING);
  print_list(l, 127);
  l = creation_list(DONE);
  print_list(l, 127);
}
