#ifndef __MANAGER_h__
#define __MANAGER_h__

#include "linked_list.h"
#include "student.h"

int get_student_id(char *name, int value, int mode);

/* CRUD */
void create_student(List *list, const Student *x);
void read_student(List *list);
void update_student(List *list, const Student *x);
//void delete_student(List *List, int id, int num); //mode

#endif//__MANAGER_H__