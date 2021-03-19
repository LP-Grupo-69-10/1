#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safe.h"

void read_safe_num(int *a) {
  char *buf = malloc(100 * sizeof(char));
  char *t_buf = malloc(100 * sizeof(char));
  
  fgets(buf, 60, stdin);
  *(buf+strlen(buf)-1) = '\0';
  
  *a = atoi(buf);
  sprintf(t_buf, "%d", *a);
  
  if(strcmp(t_buf, buf) != 0) { 
    wrong_input();
    read_safe_num(a);
  }
  
  free(buf);
  free(t_buf);
}

void read_safe_int(int* a) {
  int t;
  read_safe_num(&t); 
  *a = t;
}

void read_safe_byte(byte *a) {
  int t;
  read_safe_num(&t);
  *a = (byte)t;
  if((int)*a != t || *a < 1 || *a > 10) {
    wrong_input();
    read_safe_byte(a);
  }
}

void read_safe_ushort(unsigned short *a) {
  int t;
  read_safe_num(&t);
  *a = (unsigned short)t;
  if((int)*a != t) read_safe_ushort(a);
}

void read_safe_string(char *a) {
  char *buf = malloc(60 * sizeof(char));

  if(buf == NULL) printf("Sem memória disponível. Devias começar a trabalhar!");
  else {
    fgets(buf, 60, stdin);
    strcpy(a, buf);
  }
  free(buf);
}

void read_date(time_t *a) {
  int min, hour, day, month, year;

  do {
    read_safe_int(&min);
    read_safe_int(&hour);
    read_safe_int(&day);
    read_safe_int(&month);
    read_safe_int(&year);
    // mudar estrutura;
  } while(1/* not null a*/);
}

void wrong_input() {
  printf("Input Errado!\n");
}
