#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/list.h"

void menu() {
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

void check_opt(list l, int opt) {

  int a;
  switch (opt) {
    case 1: ;//inserir nova tarefa
      task *t = new_task();
      int tmpid = 1, tmppt = 10;
      //printf("*Insert id*\n\n-> "); //temporary
      //unsigned short id;
      //scanf("%hu", &id);
      set_id(t, tmpid++);
      //printf("*Insert priority*\n\n-> "); //temporary
      //byte priority;
      //scanf("%c", &priority);
      set_priority(t, tmppt--);
      //set_description();
      insert(l, t);
      printf("\nDeseja mais alguma opção?\n");
      printf("(1 - yes, 0 - no)\n\n-> ");
      scanf("%d", &a);
      //printf("xcfhcvgj\n");
      if(a == 1) {
        menu();
        int i;
        scanf("%d", &i);
        check_opt(l, i);
      } else break;
      break;
    case 2: //mover cartões
      break;
    case 3: //alterar pessoa responsável
      //edit_person();
      break;
    case 4: //fechar tarefa
      break;
    case 5: //reabrir tarefa
      break;
    case 6: //visualizar quadro
      break;
    case 7: ;//visualizar todas as tarefas de uma pessoa
      char *s = "H";
      list lp = person_list(l, s);
      print_list(lp, 127);
      printf("\nDeseja mais alguma opção?\n");
      printf("(1 - yes, 0 - no)\n\n-> ");
      scanf("%d", &a);
      //printf("xcfhcvgj\n");
      if(a == 1) {
        menu();
        int i;
        scanf("%d", &i);
        check_opt(l, i);
      } else break;
      break;
    case 8: //visualizar tarefas ordenadas por ordem de data de criação
      break;
    case 0: //termina
      break;
  }
}

int main() {

  menu();
  int i;
  scanf("%d", &i);
  list l = new_list();
  check_opt(l, i);
  int n;
  scanf("%d",&n);

  /*for(int i=0; i<5; i++) {
    byte a;
    scanf("%hhd",&a);
    task *t = new_task();
    set_priority(t,a);
    set_id(t,(unsigned short)i+1);
    char *s = "oi";
    set_person(t, s);
    set_description(t, "lavar loiça");
    insert(l,t);
  }*/

  /*list _1,_2;
  search_id(l,3,&_1,&_2);
  remove_task(l,_2->data);*/

  //edit_person(l, 3, "H");

  //list lp = person_list(l, "oi");
  //print_list(lp, 127);

  /*list run = l->next;
  while(run != NULL) {
    printf("%hhd %s\n", run->data->priority, run->data->person);
    run = run->next;
  }*/

  return 0;
}
