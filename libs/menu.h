#ifndef MENU_H
#define MENU_H

extern list TO_DO;
extern list DOING;
extern list DONE;

void load_lists();

void print_menu();

void insert_new_task();
void start_task();
void change_responsible();
void end_task();
void redo_task();
void print_board();
void person_list1();
void print_by_creation();

#endif /* MENU_H */

