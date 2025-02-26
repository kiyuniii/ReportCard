#include "manager.h"
#include "table.h"
#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>

static int count = 0;
void init_manager(List *list) {
    initialize(list);
    if(list->head == NULL) {
        boxline_txt(*point->x_message, *point->y_message, "MANAGER.C: THERE'S NO NODE AT ALL");
        count = 0;
    } else {
        Node *ptr = list->head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
            count++;
        }
    }
    
    openlog("REPORDCARD", LOG_CONS | LOG_PID, LOG_USER);
    syslog(LOG_INFO, "REPORTCARD STARTED, CRNT STUDENT COUNT: %d", count);
}

Info *build_info() {
    Info *info = (Info *)malloc(sizeof(Info));
    if (info == NULL) {
        printf("MALLOC(INFO) FAILED\n");
        return NULL;
    }
    
    char input_name[10] = "";
    int input_age = 0;
    int input_classroom = 0;

    printf(" NAME: ");
    fgets(input_name, sizeof(input_name), stdin);
    input_name[strcspn(input_name, "\n")] = '\0';  // delete "\n"
    printf(" AGE : ");
    scanf("%d", input_age);
    printf("CLASS: ");
    scanf("%d", input_classroom);
    
    strcpy(info->name, input_name);
    strcpy(info->age, input_age);
    strcpy(info->classroom, input_classroom);

    return info;
}

Score *build_score() {   
    Score *score = (Score *)malloc(sizeof(Score));
    if (score == NULL) {
        printf("MALLOC(SCORE) FAILED\n");
        return NULL;
    }

    int input_kor_score = 0;
    int input_math_score = 0;
    int input_eng_score = 0;

    printf(" KOR : ");
    scanf("%d", input_kor_score);
    printf(" MATH: ");
    scanf("%d", input_math_score);
    printf(" ENG : ");
    scanf("%d", input_eng_score);

    strcpy(score->kor_score, input_kor_score);
    strcpy(score->math_score, input_math_score);
    strcpy(score->eng_score, input_eng_score);

    return score;
}

Student *build_student() {
    int new_id = count;
    Student *student = (Student *)malloc(sizeof(Student));

    if(student == NULL) {
        printf("MALLOC(STUDENT) FAILED");
        return NULL;
    }
    

    Info *new_info;
    Score *new_score;
    new_info = build_info();
    new_score = build_score();

    student->id = new_id;
    student->info = new_info;
    student->score = new_score;

    count++;
    return student;
}

void create_student(List *list, const Student *x) {
    insert_front(list, x);
}

void read_student(List *list) {
    print_all(list);
}

void update_student(List *list, const Student *x) {
    if(x->id != list->crnt->data.id) {
        list->crnt->data.id = x->id;
        syslog(LOG_INFO, "UPDATE_ID   : %s --> %s", list->crnt->data.id, x->id);
    }

    if((x->info->name      != list->crnt->data.info->name)    ||
       (x->info->age       != list->crnt->data.info->age)     ||
       (x->info->classroom != list->crnt->data.info->classroom)) {
        strcpy(list->crnt->data.info->name, x->info->name);
        list->crnt->data.info->age = x->info->age;
        list->crnt->data.info->classroom = x->info->classroom;
    
        syslog(LOG_INFO, "UPDATE_INFO : NAME(%s --> %s), AGE(%d --> %d), CLASS(%d --> %d)", \
            list->crnt->data.info->name, x->info->name, \
            list->crnt->data.info->age, x->info->age,   \
            list->crnt->data.info->classroom, x->info->classroom);
    }

    if((x->score->kor_score  != list->crnt->data.score->kor_score)  ||
       (x->score->math_score != list->crnt->data.score->math_score) ||
       (x->score->eng_score  != list->crnt->data.score->eng_score)) {
        list->crnt->data.score->kor_score = x->score->kor_score;
        list->crnt->data.score->math_score = x->score->math_score;
        list->crnt->data.score->eng_score = x->score->eng_score;
    
        syslog(LOG_INFO, "UPDATE_SCORE: KOR(%d --> %d), MATH(%d --> %d), ENG(%d --> %d)", \
            list->crnt->data.score->kor_score, x->score->kor_score,     \
            list->crnt->data.score->math_score, x->score->math_score,   \
            list->crnt->data.score->eng_score, x->score->eng_score);
    }
}

void delete_student(List *List, int id, int num) {

}


void close_manager() {
    syslog(LOG_INFO, "REPORTCARD FINISHED, CRNT STUDENT COUNT: %d", count);
    closelog();
}