#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* Node dynamic allocation */
static Node *alloc_node(void) {
    return calloc(1, sizeof(Node));
}

/* node config: data, node_linking */
static void set_node(Node *n, const Student *x, const Node *next) {
    n->data = *x;
    n->next = next;
}

void initialize(List *list) {
    list->head = NULL;
    list->crnt = NULL;
}

Node *Search(List *list, const Student *x,                          //high-order func
            int (*compare)(const Student *x, const Student *y)) {   //call-back  func
    Node *ptr = list->head;

    while(ptr != NULL) {
        if(compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr;
        } else {
            ptr = ptr->next;
        }
    }
    return NULL;
}

int compare_byId(const Student *x, const Student *y) {
    if(x->id == y->id) {
        return 0;
    } else {
        return 1;
    }
}

int compare_byName(const Student *x, const Student *y) {
    if(x->info->name == y->info->name) {
        return 0;
    } else {
        return 1;
    }
}

int compare_byClass(const Student *x, const Student *y) {
    if(x->info->classroom == y->info->classroom) {
        return 0;
    } else {
        return 1;
    }
}

void insert_front(List *list, const Student *x) {
    Node *ptr = list->head;                 //ptr = points existing list's head node
    list->head = list->crnt = alloc_node(); //new node = list's head node
    set_node(list->head, x, ptr);
    printf("DONE: INSERT FRONT\n");
}

void insert_rear(List *list, const Student *x) {
    if(list->head == NULL) {
        insert_front(list, x);
    } else {
        Node *ptr = list->head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = list->crnt = alloc_node();
        set_node(ptr->next, x, NULL);
    }
    printf("DONE: INSERT REAR\n");
}

void remove_front(List *list) {
    if(list->head != NULL) {
        Node *ptr = list->head->next;   //ptr = points current list's head node's next node
        free(list->head);               //free current list's head node
        list->head = list->crnt = ptr;  //modified list's new head node = ptr
    }
}

void remove_rear(List *list) {
    if(list->head != NULL) {            //if there's node at least 1
        if(list->head->next == NULL) {  //if only 1 node exists
            remove_front(list);
        } else {
            Node *ptr = list->head;
            Node *pre;
            while(ptr->next != NULL) {
                pre = ptr;              
                ptr = ptr->next;        //when the loop ends, ptr points list's tail(NULL)
            }                           //and pre points 2 nodes behind from ptr
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;           //set current node = pre's node
        }
    }
}
