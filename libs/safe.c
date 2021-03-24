#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safe.h"

void read_safe_num(int *a, char* msg) {
  printf("%s", msg);
  
  char *buf = malloc(100 * sizeof(char));
  char *t_buf = malloc(100 * sizeof(char));
  
  fgets(buf, 60, stdin);
  *(buf+strlen(buf)-1) = '\0';
  
  *a = atoi(buf);
  sprintf(t_buf, "%d", *a);
  
  if(*a < 0 || strcmp(t_buf, buf) != 0) { 
    wrong_input();
    read_safe_num(a, msg);
  }
  
  free(buf);
  free(t_buf);
}

void read_safe_int(int* a, char* msg) {
  int t;
  read_safe_num(&t, msg); 
  *a = t;
}

void read_safe_byte(byte *a, char* msg) {
  int t;
  read_safe_num(&t, msg);
  *a = (byte)t;
  if((int)*a != t) {
    wrong_input();
    read_safe_byte(a, msg);
  }
}

void read_safe_ushort(unsigned short *a, char *msg) {
  int t;
  read_safe_num(&t, msg);
  *a = (unsigned short)t;
  if((int)*a != t) read_safe_ushort(a, msg);
}

void read_safe_string(char *a, char *msg) {
  if(a == NULL)
    printf("Sem memória disponível. Devias começar a trabalhar!");
  else {
    printf("%s", msg);
    fgets(a, 60, stdin);
    if(a[strlen(a) - 1] == '\n') a[strlen(a) - 1] = '\0';
  }
}

void read_safe_date(time_t *a, char *msg) {
  printf("%s", msg);
  struct tm *date = (struct tm*)malloc(sizeof(struct tm));
  
  read_safe_int(&date->tm_year, "Insira o ano: ");
  read_safe_int(&date->tm_mon,  "Insira o mês: ");
  read_safe_int(&date->tm_mday, "Insira o dia: ");
  read_safe_int(&date->tm_hour, "Insira a hora: ");
  read_safe_int(&date->tm_min , "Insira o minuto: ");
  date->tm_year -= 1900; date->tm_mon--;
  
  *a = mktime(date);
  free(date);
 
  if(*a == -1) {
    wrong_input();
    read_safe_date(a, msg);
  }
}

// ------------------------------------------------------------------- //

void read_option(byte *a) {
  read_safe_byte(a, "\nInsira uma opção: ");
  if(*a > 9) {
    wrong_input();
    read_option(a);
  }
}

void read_id(unsigned short *a) {
  read_safe_ushort(a, "\nInsira o ID da tarefa: ");
  if(1/*ID DOESNT EXIT*/) {
    wrong_input();
    read_id(a);
  }
}

void read_priority(byte *a) {
  read_safe_byte(a, "\nInsira a prioridade da tarefa (1-10): ");
  if(*a == 0 || *a > 10) {
    wrong_input();
    read_priority(a);
  }
}

void read_description(char *a) {
  read_safe_string(a, "\nInsira a descrição desta tarefa: ");
}

void read_person(char *a) {
  read_safe_string(a, "\nInsira o nome do responsável por esta tarefa: ");
}

void read_deadline(time_t *a) {
  read_safe_date(a, "\nInsira a data limite para a conclusão da tarefa:\n");
}

void wrong_input() {
  printf("Input Errado!\n");
}
