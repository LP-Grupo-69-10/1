// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

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
  printf("+------------------+\n");
  printf("| Quadro de KanBan |\n");
  printf("+------------------+\n");
  
  load_lists();
  
  int exit_status = 0;
  int option;
  
  while(!exit_status) {
    print_menu();
    read_option(&option);

    clear_screen();
    
    switch(option) {
    case 1: insert_new_task();    clear_screen(); break;
    case 2: see_task();                           break;
    case 3: start_task();         clear_screen(); break;
    case 4: change_responsible(); clear_screen(); break;
    case 5: end_task();           clear_screen(); break;
    case 6: redo_task();          clear_screen(); break;
    case 7: print_by_priority();                  break;
    case 8: print_by_person();                    break;
    case 9: print_by_creation();                  break;
    case 0: exit_status = 1;
    }
    
    if(option <= 6)
      write_lists();
  }
  
  return EXIT_SUCCESS;
}
