// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include "task.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STORED_SIZE (sizeof(task) - sizeof(int))

void write_lf(list l, char *filename) {  
  FILE *fp = fopen(filename,"wb");
  
  if(fp != NULL) { 
    while((l = l->next) != NULL) {
      fwrite(&l->data->priority, STORED_SIZE, 1, fp);    
    }
  }
    
  fclose(fp);
}

list read_fl(char *filename) {
  FILE *fp = fopen(filename,"rb");
  list l = new_list();
  
  if(fp == NULL) return l;
  
  fseek(fp, 0L, SEEK_END);
  while(fseek(fp, -STORED_SIZE, SEEK_CUR) != -1) {
    task *t = new_task();
    
    // ler task e colocar o fp de novo no inicio da task
    fread(&t->priority, STORED_SIZE, 1, fp);
    fseek(fp, -STORED_SIZE, SEEK_CUR);
    
    add_first(l, t);
  }
  
  fclose(fp);  
  return l;
}
