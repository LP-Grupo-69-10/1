// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safe.h"
#include "task.h"

void read_safe_num(int *a, char* msg) {
  printf("%s", msg);
  
  char *buf = malloc(100 * sizeof(char));
  char *t_buf = malloc(100 * sizeof(char));
  
  fgets(buf, 100, stdin);
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

void read_safe_string(char *a, char *msg) {
  if(a == NULL) {
    printf("Sem memória disponível. Devias começar a trabalhar!");
  }
  else {
    printf("%s", msg);
    fgets(a, 60, stdin);

    if(a[strlen(a) - 1] == '\n') {
      a[strlen(a) - 1] = '\0';
    }
  }
}

void read_safe_date(time_t *a, char *msg) {
  printf("%s", msg);
  int year, month, day, hour, min;
  
  read_safe_int(&year,  "\nInsira o ano: ");
  read_safe_int(&month, "\nInsira o mês: ");
  read_safe_int(&day,   "\nInsira o dia: ");
  read_safe_int(&hour,  "\nInsira a hora: ");
  read_safe_int(&min,   "\nInsira o minuto: ");
  year -= 1900; month--;

  struct tm input = {
    .tm_year = year,
    .tm_mon = month,
    .tm_mday = day,
    .tm_hour = hour,
    .tm_min = min
  };
  
  *a = mktime(&input);

  struct tm *output = localtime(a);
  
  if(output->tm_year != year || output->tm_mon != month || output->tm_mday != day || output->tm_hour != hour || output->tm_min != min) {
    wrong_input();
    read_safe_date(a, msg);
  }

  //free(output);
}

void read_option(int *a) {
  read_safe_int(a, "\nInsira uma opção: ");
  if(*a > 9) {
    wrong_input();
    read_option(a);
  }
}

void read_id(int *a) {
  read_safe_int(a, "\nInsira o ID da tarefa: ");
  if(*a < 1000 || *a >= ID_COUNT) {
    wrong_input();
    read_id(a);
  }
}

void read_priority(int *a) {
  read_safe_int(a, "\nInsira a prioridade da tarefa (1-10): ");
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
