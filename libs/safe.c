// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    printf("Sem memória disponível. Devias começar a trabalhar!\n");
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
  char* input = malloc(60*sizeof(char));
  read_safe_string(input, msg);
  
  if(input[0] == '\0') {
    *a = 0;
    return;
  }
  
  if(strlen(input) != 16 || input[4] != '-' || input[7] != '-' || input[10] != '-' || input[13] != ':') {
    wrong_input();
    read_safe_date(a, msg);
    return;
  }

  for(int i = 0; i < 16; i++) {
    if(i == 4 || i == 7 || i == 10 || i == 13) continue;
    if(!isdigit(*(input + i))) {
      wrong_input();
      read_safe_date(a, msg);
      return;
    }
  }

  char* year_  = malloc(4*sizeof(char));
  char* month_ = malloc(4*sizeof(char));
  char* day_   = malloc(4*sizeof(char));
  char* hour_  = malloc(4*sizeof(char));
  char* min_   = malloc(4*sizeof(char));
  
  strncpy(year_,  input,    4);
  strncpy(month_, input+5,  2);
  strncpy(day_,   input+8,  2);
  strncpy(hour_,  input+11, 2);
  strncpy(min_,   input+14, 2);

  int year = atoi(year_)-1900, month = atoi(month_)-1, day = atoi(day_), hour = atoi(hour_), min = atoi(min_);
  struct tm t = {.tm_year = year, .tm_mon = month, .tm_mday = day, .tm_hour = hour, .tm_min = min, .tm_isdst = -1};
  
  *a = mktime(&t);
  
  struct tm *out = localtime(a);
  time_t rawtime;
  time(&rawtime);

  if(out->tm_year != year || out->tm_mon != month || out->tm_mday != day || out->tm_hour != hour || out->tm_min != min) {
    wrong_input();
    read_safe_date(a, msg);
    return;
  }

  if(difftime(*a, rawtime) <= 0) {
    printf("Data já não mais disponível.");
    *a = 0;
    read_safe_date(a, msg);
  }
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
  if(a[0] == '\0') {
    wrong_input();
    read_description(a);
  }
}

void read_person(char *a, int flag) {
  if(!flag) {
    read_safe_string(a, "\nInsira o nome do responsável por esta tarefa, ENTER caso não ainda nao esteja definido: ");
  }
  else {
    read_safe_string(a, "\nInsira o nome do responsável por esta tarefa: ");
    if(a[0] == '\0') {
      wrong_input();
      read_person(a, 1);
    }
  }
}

void read_deadline(time_t *a, int flag) {
  if(!flag) {
    read_safe_date(a, "\nInsira o prazo para a tarefa com o formato AAAA-MM-DD-HH:MM, ENTER caso não ainda nao esteja definido: ");
  }
  else {
    read_safe_date(a, "\nInsira o prazo para a tarefa com o formato AAAA-MM-DD-HH:MM: ");
    if(*a == 0) {
      wrong_input();
      read_deadline(a, 1);
    }
  }
}

void clear_screen() {
  printf("\e[1;1H\e[2J");
}

void wrong_input() {
  printf("Input Errado!\n");
}
