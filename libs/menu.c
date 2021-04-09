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

int MAX_DOING = 5;

list TO_DO;
list DOING;
list DONE;

void load_lists() {
  TO_DO = read_fl("files/to_do");
  DOING = read_fl("files/doing");
  DONE  = read_fl("files/done");
}

void write_lists() {
  write_lf(TO_DO, "files/to_do");
  write_lf(DOING, "files/doing");
  write_lf(DONE,  "files/done");
}

void print_menu() {
  printf("\n+------------------------------------------------------+\n");
  printf("| MENU:                                                |\n");
  printf("+------------------------------------------------------+\n");
  printf("|                                                      |\n");
  printf("| 1 - Inserir nova tarefa                              |\n");
  printf("| 2 - Ver tarefa                                       |\n");
  printf("| 3 - Mover cartoes                                    |\n");
  printf("| 4 - Alterar a pessoa responsavel                     |\n");
  printf("| 5 - Fechar tarefa                                    |\n");
  printf("| 6 - Reabrir tarefa                                   |\n");
  printf("| 7 - Visualizar o quadro                              |\n");
  printf("| 8 - Visualizar as tarefas de uma pessoa              |\n");
  printf("| 9 - Visualizar tarefas ordenadas por data de criacao |\n");
  printf("| 0 - Terminar                                         |\n");
  printf("|                                                      |\n");
  printf("+------------------------------------------------------+\n");
}

void insert_new_task() {
  task *t = new_task();
  
  read_priority(&t->priority);
  read_description(t->description);
  read_person(t->person, 0);
  read_deadline(&t->deadline, 0);
  
  insert_priority(TO_DO, t);
}

void see_task() {
  printf("%s", print_board(TO_DO, DOING, DONE));
  
  int id;
  read_id(&id);

  task *t;
  if((t = find_task(TO_DO, id)) != NULL) print_task(t);
  else if((t = find_task(DOING, id)) != NULL) print_task(t);
  else if((t = find_task(DONE, id)) != NULL) print_task(t);
  else printf("Tarefa nao encontrada.\n");
}

void start_task() {
  printf("%s", print_board(TO_DO, DOING, DONE));
  
  int id;
  read_id(&id);
  
  task *to_start = find_task(TO_DO, id);
  if(to_start != NULL) {
    if(length(DOING) == MAX_DOING) {
      printf("Demasiadas tarefas abertas\n");
      return;
    }

    if(to_start->person[0] == '\0') {
      read_person(to_start->person, 1);
    }
    if(to_start->deadline == 0) {
      read_deadline(&to_start->deadline, 1);
    }
    
    remove_task(TO_DO, id);
    insert_priority(DOING, to_start);
  }  
  else {
    to_start = find_task(DOING, id);
    if(to_start == NULL) {
      printf("Tarefa nao encontrada.\n");
      return;
    }
    
    remove_task(DOING, id);
    insert_priority(TO_DO, to_start);
  }
}

void change_responsible() {
  printf("%s", print_board(TO_DO, DOING, DONE));
  
  int id;
  read_id(&id);

  if(find_task(DOING, id) != NULL) {
    char *person = malloc(60 * sizeof(char));
    read_person(person, 1);
    edit_person(DOING, id, person);
  }
  
  else {
    printf("Tarefa nao encontrada.\n");
  }
}

void end_task() {
  printf("%s", print_board(TO_DO, DOING, DONE));
  
  int id;
  read_id(&id);

  task *to_add = find_task(DOING, id);
  if(to_add != NULL) {
    to_add->conclusion = time(NULL);
    remove_task(DOING, id);
    insert_priority(DONE, to_add);
  }

  else {
    printf("Tarefa nao encontrada.\n");
  }
}

void redo_task() {
  printf("%s", print_board(TO_DO, DOING, DONE));
  
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
    printf("Tarefa nao encontrada.\n");
  }
}

void print_by_priority(int save) {
  char *board = print_board(TO_DO, DOING, DONE);
  printf("%s", board);
  read_save(board);
}

void print_by_person() {
  char *s = malloc(60 * sizeof(char));
  read_person(s, 1);
  char *board = print_board(person_list(TO_DO, s), person_list(DOING, s), person_list(DONE, s));
  printf("%s", board);
  read_save(board);
}

void print_by_creation() {
  char *board = print_board(creation_list(TO_DO), creation_list(DOING), creation_list(DONE));
  printf("%s", board);
  read_save(board);
}

char* print_board(list to_do, list doing, list done) {
  char *to_write = malloc(5000 * sizeof(char));

  sprintf(to_write,                  "+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  sprintf(to_write+strlen(to_write), "|               TO DO               |               DOING %3d           |                DONE               |\n", MAX_DOING);
  sprintf(to_write+strlen(to_write), "+-----------------------------------+-----------------------------------+-----------------------------------+\n");
    
  do {
    if(to_do != NULL) to_do = to_do->next;
    if(doing != NULL) doing = doing->next;
    if(done  != NULL) done  = done->next;
    
    char *s1 = string_task((to_do != NULL ? to_do->data : NULL));
    char *s2 = string_task((doing != NULL ? doing->data : NULL));
    char *s3 = string_task((done  != NULL ? done->data  : NULL));

    sprintf(to_write+strlen(to_write), "| %.33s | %.33s | %.33s |\n", s1, s2, s3);
  }  while(to_do != NULL || doing != NULL || done != NULL);
  
  sprintf(to_write+strlen(to_write), "+-----------------------------------+-----------------------------------+-----------------------------------+\n");
  sprintf(to_write+strlen(to_write), "- (#n): ID da tarefa\n");

  return to_write;
}
