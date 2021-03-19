#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/list.h"
#include "libs/task.h"
#include "libs/file.h"

void testar1() {
  int n;  
  scanf("%d", &n);
  list l = new_list();

  load_id("to_do");
  
  for(int i = 0; i < n; i++) {
    task *t = new_task();    
    byte a;
    scanf("%hhd", &a);

    set_priority(t, a);
    set_description(t, "lavar loiça");
    set_person(t, "michael");
    
    insert(l,t);
  }
  
  print_list(l, 127);  
  write_lf(l, "to_do");  
}

void testar2() {
  puts("---");
  
  list nl = read_fl("to_do");
  print_list(nl, 127);

}

int main() {
  // testar1();
  testar2();
  
  return 0;
}
