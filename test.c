#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "libs/file.h"

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

void testar2() {
  list l = read_fl("testfile");
  print_list(l, 127);
}

int main() {
  testar2();
  
  return 0;
}
