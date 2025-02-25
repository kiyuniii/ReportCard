#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>

typedef struct {
    char name[10];
    int age;
    int classroom;
} Info;

typedef struct {
    int kor_score;
    int math_score;
    int eng_score;
} Score;

typedef struct {
    int id;
    Info* info;
    Score* score;
} Student;

void print_info(Student *x);
void print_score(Student *x);
void print_error(int err_code);
void print_student(Student *x, int num);

#endif//__STUDENT_H__