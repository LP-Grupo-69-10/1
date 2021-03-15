#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/list.h"

int main() {
  int n;
  scanf("%d", &n);
  list l = new_list();
  
  for(int i = 0; i < n; i++) {
    task *t = new_task();    
    byte a;
    scanf("%hhd", &a);

    set_priority(t, a);
    set_id(t, (unsigned short)i+1);
    set_person(t, "michael");
    set_description(t, "lavar loiça");

    insert(l,t);
  }

  // edit_person(l, 3, "ola");
  // list lp = person_list(l, "oi");

  print_list(l, 127);

  return 0;
}
