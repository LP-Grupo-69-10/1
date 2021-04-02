// ----------------------------------------------------
// DCC - LP - Quadro de Kanban
// ----------------------------------------------------
// Ana Sofia Teixeira - Guilherme Duarte - Miguel Alves
// ----------------------------------------------------

#ifndef SAFE_H
#define SAFE_H

#include <time.h>

void read_safe_num(int*, char*);
void read_safe_int(int*, char*);
void read_safe_string(char*, char*);
void read_safe_date(time_t*, char*);

void read_id(int*);
void read_option(int*);
void read_priority(int*);
void read_description(char*);
void read_person(char*, int);
void read_creation(char*);
void read_deadline(time_t*, int);

void wrong_input();
void clean_screen();
int old_date(struct tm*);

#endif /* SAFE_H */
