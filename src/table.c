#include "table.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

Layout *layout = NULL;
Point *point = NULL;

void init_table() {
    layout = (Layout *)malloc(sizeof(*layout));
    point = (Point *)malloc(sizeof(*point));

    layout->left_w = (int *)malloc(sizeof(int));
    layout->right_w = (int *)malloc(sizeof(int));
    layout->list_h = (int *)malloc(sizeof(int));
    layout->overview_h = (int *)malloc(sizeof(int));
    layout->search_h = (int *)malloc(sizeof(int));
    layout->io_h = (int *)malloc(sizeof(int));
    layout->msg_h = (int *)malloc(sizeof(int));

    point->x_list = (int *)malloc(sizeof(int));
    point->y_list = (int *)malloc(sizeof(int));
    point->x_overview = (int *)malloc(sizeof(int));
    point->y_overview = (int *)malloc(sizeof(int));
    point->x_search = (int *)malloc(sizeof(int));
    point->y_search = (int *)malloc(sizeof(int));
    point->x_io = (int *)malloc(sizeof(int));
    point->y_io = (int *)malloc(sizeof(int));
    point->x_message = (int *)malloc(sizeof(int));
    point->y_message = (int *)malloc(sizeof(int));
}

void free_table() {
    free(layout->left_w);
    free(layout->right_w);
    free(layout->list_h);
    free(layout->overview_h);
    free(layout->search_h);
    free(layout->io_h);
    free(layout->msg_h);
    free(layout);

    free(point->x_list);
    free(point->y_list);
    free(point->x_overview);
    free(point->y_overview);
    free(point->x_search);
    free(point->y_search);
    free(point->x_io);
    free(point->y_io);
    free(point->x_message);
    free(point->y_message);
    free(point);
}

void get_terminal_size(int *width, int *height) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *width = w.ws_col;
    *height = w.ws_row;
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", (int)y, (int)x);
}

void clear_screen() {
    printf("\033[2J\033[H");
}

void boxline_top(int x, int y) {
    move_cursor(x, y);
    printf("┌");
    for (int i = 0; i < *layout->left_w - 2; i++) printf("─");
    printf("┐");
}

void boxline_txt(int x, int y, char* text) {
    move_cursor(x - 2, y);
    printf("│ ");
    printf("%s", text);
    move_cursor(x + *layout->left_w - 3, y);
    printf("│");
}

void boxline_nul(int x, int y) {
    move_cursor(x, y + 1);
    printf("│ ");
    move_cursor(x + *layout->left_w - 1, y + 1);
    printf("│");
}

void boxline_bot(int x, int y, int h) {
    move_cursor(x, y + h - 1);
    printf("└");
    for (int i = 0; i < *layout->left_w - 2; i++) printf("─");
    printf("┘");
}

void update_layout() {
    int width, height;
    get_terminal_size(&width, &height);

    *(layout->left_w) = (int)round(width * 0.5) - PADDING;
    *(layout->list_h) = height;
    *(layout->right_w) = (int)round(width * 0.5) - PADDING;
    *(layout->overview_h) = (int)round(height * 0.12);
    *(layout->search_h) = (int)round(height * 0.4);
    *(layout->io_h) = (int)round(height * 0.4);
    *(layout->msg_h) = (int)round(height * 0.1);

    *(point->x_list) = PADDING + 2;
    *(point->y_list) = PADDING + 1;
    *(point->x_overview) = *layout->left_w + 4;
    *(point->y_overview) = PADDING + 1;
    *(point->x_search) = *point->x_overview;
    *(point->y_search) = *point->y_overview + *(layout->overview_h);
    *(point->x_io) = *point->x_overview;
    *(point->y_io) = *point->y_search + *layout->search_h;
    *(point->x_message) = *point->x_overview;
    *(point->y_message) = *point->y_io + *layout->io_h;
}

void draw_box() {
    update_layout(layout, point);

    /* BOX: LIST */
    boxline_top(PADDING, PADDING);
    boxline_bot(PADDING, PADDING, *layout->list_h);

    /* BOX: OVERVIEW */
    boxline_top(*(layout->left_w) + 2, PADDING);
    boxline_bot(*(layout->left_w) + 2, PADDING, *(layout->overview_h));

    /* BOX: SEARCH */
    boxline_top(*(layout->left_w) + 2, PADDING + *(layout->overview_h));
    boxline_bot(*(layout->left_w) + 2, PADDING + *(layout->overview_h), *(layout->search_h));

    /* BOX: MESSAGE */
    boxline_top(*(layout->left_w) + 2, PADDING + *(layout->overview_h) + *(layout->search_h) + *(layout->io_h));
    boxline_bot(*(layout->left_w) + 2, PADDING + *(layout->overview_h) + *(layout->search_h) + *(layout->io_h), *(layout->msg_h));

    /* B(OX: I/O )*/
    boxline_top(*(layout->left_w) + 2, PADDING + *(layout->overview_h) + *(layout->search_h));
    boxline_bot(*(layout->left_w) + 2, PADDING + *(layout->overview_h) + *(layout->search_h), *(layout->io_h));
}