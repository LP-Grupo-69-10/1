#ifndef SAFE_H
#define SAFE_H

#include <time.h>
typedef char byte;

// Read specific type
void read_safe_num(int*, char*);
void read_safe_int(int*, char*);
void read_safe_byte(byte*, char*);
void read_safe_ushort(unsigned short*, char*);
void read_safe_string(char*, char*);
void read_safe_date(time_t*, char*);

// Read functions that call the ones above and prints information
void read_id(unsigned short*);
void read_option(byte*);
void read_priority(byte*);
void read_description(char*);
void read_person(char*);
void read_creation(char*);
void read_deadline(time_t*);

void wrong_input();

#endif /* SAFE_H */
