#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
  list l = new_list();
  
  set_id(l->data, 2);

  printf("%hu\n", l->data->id);
  
  return 0;
}
