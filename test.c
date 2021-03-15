#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/list.h"

int main() {
@@ -12,19 +13,27 @@ int main() {
    scanf("%hhd",&a);
    task *t = new_task();
    set_priority(t,a);
    set_id(t,(unsigned short)i+1);    
    set_id(t,(unsigned short)i+1);
    char *s = "oi";
    set_person(t, s);
    set_description(t, "lavar loiça");
    insert(l,t);
  }

  list _1,_2;
  /*list _1,_2;
  search_id(l,3,&_1,&_2);
  remove_task(l,_2->data);
  remove_task(l,_2->data);*/

  list run = l->next;
  edit_person(l, 3, "ola");

  list lp = person_list(l, "oi");
  print_list(l, 127);

  /*list run = l->next;
  while(run != NULL) {
    printf("%hhd\n", run->data->priority);
    printf("%hhd %s\n", run->data->priority, run->data->person);
    run = run->next;
  }
  }*/

  return 0;
}
