#include "student.h"
#include <stdio.h>

void print_info(Student *x) {

}

void print_score(Student *x) {
    
}

void print_error(int err_code) {
    switch(err_code) {
        case 0:
            puts("ERR: WRONG PARAMETER");
            break;
        case 1:
            break;
        default:
            break;
    }
}

void print_student(Student *x, int num) {
    switch(num) {
        case 0: 
            print_info(x);
            print_score(x);
            break;
        case 1:
            print_info(x);
            break;
        case 2:
            print_score(x);
            break;
        default:
            print_error(1);
            break;
    }
}
