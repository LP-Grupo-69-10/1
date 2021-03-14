#include <stdlib.h>
#include <stdio.h>
#include "libs/list.h"

int main() {
  list l = new_list();
  int n;
  scanf("%d",&n);

  for(int i=0; i<n; i++) {
    byte a;
    scanf("%hhd",&a);
    task *t = new_task();
    set_priority(t,a);
    set_id(t,(unsigned short)i+1);    
    insert(l,t);
  }

  list _1,_2;
  search_id(l,3,&_1,&_2);
  remove_task(l,_2->data);

  list run = l->next;
  while(run != NULL) {
    printf("%hhd\n", run->data->priority);
    run = run->next;
  }

  return 0;
}
