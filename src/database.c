#include "database.h"
#include "linked_list.h"

void save_data(List *list, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) return;

    Node *ptr = list->head;
    while(ptr != NULL) {
        fwrite(&(ptr->data), sizeof(Student), 1, fp);
        ptr = ptr->next;
    }

    fclose(fp);
}

void load_data(List *list, const char* filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) return;

    Student *temp;
    while(fread(&temp, sizeof(Student), 1, fp) == 1) {
        insert_front(list, temp);
    }

    fclose(fp);
}