#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/list.h"

int main() {
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

  // edit_person(l, 2, "michaela");  
  // list lp = person_list(l, "michaela");

  print_list(l, 127);

  return 0;
}
