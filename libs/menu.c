#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "file.h"
#include "menu.h"
#include "safe.h"

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
  printf("\n----------------------------------------------------\n");
  printf("MENU:\n\n");
  printf("1 - Inserir nova tarefa\n");
  printf("2 - Mover cartões\n");
  printf("3 - Alterar a pessoa responsável\n");
  printf("4 - Fechar tarefa\n");
  printf("5 - Reabrir tarefa\n");
  printf("6 - Visualizar o quadro\n");
  printf("7 - Visualizar as tarefas de uma pessoa\n");
  printf("8 - Visualizar tarefas ordenadas por data de criação\n");
  printf("0 - Terminar\n");
  printf("----------------------------------------------------\n");
}

void insert_new_task() {
  task *t = new_task();
  
  byte priority;
  read_priority(&priority);
  set_priority(t, priority);
  
  char* description = malloc(60 * sizeof(char));
  read_description(description);
  set_description(t, description);

  char* person = malloc(60 * sizeof(char));
  read_person(person);
  set_person(t, person);

  /*
    DATAS
   */
  
  insert(TO_DO, t);
}

void start_task() { //Sofia
  unsigned short id;
  read_id(&id);
}

void change_responsible() { //Sofia
  
}

void end_task() { //Gui
  unsigned short id;
  read_id(&id);
  
  task *to_add = find_task(DOING, id);
  remove_task(DOING, id);
  to_add->conclusion = 0; /*TIME NOW*/
  insert(DONE, to_add);
}

void redo_task() { //Gui
  unsigned short id;
  read_id(&id);
  
  task *to_add = find_task(DONE, id);
  remove_task(DONE, id);

  to_add->creation = 0/*TIME NOW*/;
  to_add->conclusion = 0; 
  
  insert(TO_DO, to_add);
}

void print_board() { //Gui
  putchar('\n');
  printf("+----------------+----------------+----------------+\n");
  printf("|     TO DO      |     DOING      |      DONE      |\n");
  printf("+----------------+----------------+----------------+\n");
  
  for(int i = 0; i < 20; i++) {
    printf("| %.14s | %.14s | %.14s |\n", "LAVAR A LOICA        ", "FAZER A CAMA           ", "FAZER COCO                  ");
  }
  
  printf("+----------------+----------------+----------------+\n");
}

void person_list1() {//Miguel
  char *s = malloc(60 * sizeof(char));
  read_person(s);
  list lp = person_list(TO_DO, s); // e as outras duas
  print_list(lp, 127);
}

void print_by_creation() { //Miguel
  
}
