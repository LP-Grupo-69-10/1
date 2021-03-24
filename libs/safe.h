#ifndef SAFE_H
#define SAFE_H

#include <time.h>

// Read specific type
void read_safe_num(int*, char*);
void read_safe_int(int*, char*);
void read_safe_string(char*, char*);
void read_safe_date(time_t*, char*);

// Read functions that call the ones above and prints information
void read_id(int*);
void read_option(int*);
void read_priority(int*);
void read_description(char*);
void read_person(char*);
void read_creation(char*);
void read_deadline(time_t*);

void wrong_input();

#endif /* SAFE_H */
