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

  printf("\n-> ");
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
  
}

void change_responsible() { //Sofia
  
}

void end_task() { //Gui
  
}

void redo_task() { //Gui
  
}

void print_board() { //Gui
  
}

void person_list1() {//Miguel
  char *s = malloc(60 * sizeof(char));
  read_person(s);
  list lp = person_list(TO_DO, s); // e as outras duas
  print_list(lp, 127);
}

void print_by_creation() { //Miguel
  
}

/*     case 2: //mover cartões */
/*       break; */
/*     case 3: //alterar pessoa responsável */
/*       //edit_person(); */
/*       break; */
/*     case 4: //fechar tarefa */
/*       break; */
/*     case 5: //reabrir tarefa */
/*       break; */
/*     case 6: //visualizar quadro */
/*       break; */
/*     case 8: //visualizar tarefas ordenadas por ordem de data de criação */
/*       break; */
/*     case 0: //termina */
/*       break; */
/*   } */
/* } */
