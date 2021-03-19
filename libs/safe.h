#ifndef SAFE_H
#define SAFE_H

#include <time.h>
typedef char byte;

void read_safe_int(int*);
void read_safe_byte(byte*);
void read_safe_ushort(unsigned short*);
void read_safe_string(char*);
void read_date(time_t*);
void wrong_input();

#endif /* SAFE_H */
