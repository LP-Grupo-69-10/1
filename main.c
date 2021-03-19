#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/list.h"
#include "libs/task.h"
#include "libs/file.h"
#include "libs/safe.h"

/*
void testar1() {
  list l = new_list();
  time_t timer = time(NULL);
  
  printf("---\n%s---\n", ctime(&timer));

  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
    task *t = new_task();    
    byte a;
    scanf("%hhd", &a);

    set_id(t, (unsigned short)i+1);
    set_priority(t, a);
    set_description(t, "lavar loiça");
    set_person(t, "michael");
    
    insert(l,t);
  }
  
  print_list(l, 127);
  
  write_lf(l, "testfile");

  list nl = read_fl("testfile");
  puts("--- --- --- ---");
  print_list(nl, 127);
  
}
*/

/*
void testar2() {
  list l = read_fl("testfile");
  print_list(l, 127);
}
*/

int main() {
  printf("+----------------+\n");
  printf("|Quadro de KanBan|\n");
  printf("+----------------+\n");

  int exit_status = 0;
  byte option;
  
  while(!exit_status) {
    //print_menu();
    read_option(&option);
    
    switch(option) {
    case 1: /* insert_new_task(); */ break;
    case 2: /* start_task(); */ break;
    case 3: /* change_responsible(); */ break;
    case 4: /* end_task(); */ break;
    case 5: /* redo_task(); */ break;
    case 6: /* print_board(); */ break;
    case 7: /* person_list(); */ break;
    case 8: /* print_by_creation(); */ break;
    case 9: exit_status = 1;
    }
  }
  
  return EXIT_SUCCESS;
}
