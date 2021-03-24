#include "task.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID_SIZE sizeof(int) 

void write_lf(list l, char *filename) {  
  FILE *fp = fopen(filename,"wb");
    
  if(fp != NULL) {
    while((l = l->next) != NULL) 
      fwrite(&l->data->priority, sizeof(task) - 4, 1, fp);
  }

  fclose(fp);
}

list read_fl(char *filename) {
  FILE *fp = fopen(filename,"rb");
  list l = new_list();
  
  if(fp == NULL) return l;
  
  fseek(fp, 0L, SEEK_END);
  while(fseek(fp, -sizeof(task) + 4, SEEK_CUR) != -1) {
    task *t = new_task();
    
    // read task and comeback to beggining of task
    fread(&t->priority, sizeof(task) - 4, 1, fp);
    fseek(fp, -sizeof(task) + 4, SEEK_CUR);
    
    add_first(l, t);
  }
  fclose(fp);
  printf("que se fonix\n");
  
  return l;
}
