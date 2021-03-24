#include "task.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID_SIZE sizeof(unsigned short)

void write_lf(list l, char *filename) {  
  FILE *fp = fopen(filename,"wb");
    
  if(fp != NULL) {
    while((l = l->next) != NULL) 
      fwrite(l->data + ID_SIZE, sizeof(task) - ID_SIZE, 1, fp);
  }

  fclose(fp);
}

list read_fl(char *filename) {
  FILE *fp = fopen(filename,"rb");
  list l = new_list();
  
  if(fp == NULL) return l;
  
  fseek(fp, 0L, SEEK_END);
  while(fseek(fp, -sizeof(task) + ID_SIZE, SEEK_CUR) != -1) {
    task *t = new_task();
    
    // read task and comeback to beggining of task
    fread(t + ID_SIZE, sizeof(task) - ID_SIZE, 1, fp);
    fseek(fp, -sizeof(task) + ID_SIZE, SEEK_CUR);
    
    add_first(l, t);
  }
  
  fclose(fp);
  return l;
}
