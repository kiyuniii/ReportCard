#ifndef __REPORT_H__
#define __REPORT_H__

#include "student.h"

/* Node */
typedef struct _node_ {
    Student data;
    struct _node_ *next;    //self-referential
} Node;

/* List */
typedef struct {
    Node *head; //head node
    Node *crnt; //current node
} List;

void initialize(List *list);
Node *Search(List *list, const Student* x,
    int (*compare)(const Student *x, const Student *y));
int compare_byId(const Student *x, const Student *y);
int compare_byName(const Student *x, const Student *y);
int compare_byClass(const Student *x, const Student *y);

void insert_front(List *list, const Student *x);
void insert_rear(List *list, const Student *x);
void remove_front(List *list);
void remove_rear(List *list);
void remove_current(List *list);
void remove_all(List *list);

void print_current(const List *list);
void print_all(const List *list);
void terminate(List *list);

#endif//__REPORT_H__