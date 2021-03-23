#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/list.h"
#include "libs/task.h"
#include "libs/file.h"
#include "libs/safe.h"
#include "libs/menu.h"

int main() {
  printf("+----------------+\n");
  printf("|Quadro de KanBan|\n");
  printf("+----------------+\n");

  load_lists();
  
  int exit_status = 0;
  byte option;
  
  while(!exit_status) {
    print_menu();
    read_option(&option);
    
    switch(option) {
    case 1: insert_new_task(); break;
    case 2: start_task(); break;
    case 3: change_responsible(); break;
    case 4: end_task(); break;
    case 5: redo_task(); break;
    case 6: print_board(); break;
    case 7: person_list1(); break;
    case 8: print_by_creation(); break;
    case 0: exit_status = 1;
    }
  }

  // write_lists();
  
  return EXIT_SUCCESS;
}
