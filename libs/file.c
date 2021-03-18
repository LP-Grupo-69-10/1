#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void write_lf(list l, char *filename) {  
  FILE *fp = fopen(filename,"wb");

  if(fp != NULL)
    while((l = l->next) != NULL)
      (void)fwrite(l->data, sizeof(task), 1, fp);

  fclose(fp);
}

// reads list from file in reverse order
list read_fl(char *filename) {
  FILE *fp = fopen(filename, "rb");
  list l = new_list();
  fseek(fp, 0L, SEEK_END);

  while(fseek(fp, -sizeof(task), SEEK_CUR) != -1) {
    task *t = new_task();

    // read task and comeback to beggining of task
    (void)fread(t, sizeof(task), 1, fp);
    fseek(fp, -sizeof(task), SEEK_CUR);
    
    add_first(l, t);
  }

  fclose(fp);
  return l;
}
