#include <stdlib.h>
#include <stdio.h>
#include "libs/list.h"

int main() {
  list l = new_list();
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    byte a;
    scanf("%c", &a);
    task *t = new_task();
    set_priority(t, a);
    insert(l, t);
  }

  list run = l;
  while(run != NULL) {
    printf("%c\n", run->data->priority);
    run = run->next;
  }
  
  return 0;
}
