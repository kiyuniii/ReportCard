#ifndef __STUDENT_H__
#define __STUDENT_H__

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

#endif//__STUDENT_H__