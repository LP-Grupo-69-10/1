#include <time.h>

typedef char byte;

typedef struct {
  unsigned short id;
  byte priority;
  time_t creation;
  char *description;
  char *person;
  time_t deadline;
  time_t conclusion;
} task;

task *new_task();

// Setters
void set_id(task*,unsigned short);
void set_priority(task*,byte);
void set_creation(task*,time_t);
void set_description(task*,char*);
void set_person(task*,char*);
void set_deadline(task*,time_t);
void set_conclusion(task*,time_t);
