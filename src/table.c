#include "table.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

int left_w;
int list_h;
int right_w;
int overview_h;
int search_h;
int io_h;
int msg_h;

int x_list;
int y_list;
int x_overview;
int y_overview;
int x_search;
int y_search;
int x_io;
int y_io;
int x_message;
int y_message;

void get_terminal_size(int *width, int *height) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *width = w.ws_col;
    *height = w.ws_row;
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void clear_screen() {
    printf("\033[2J\033[H");
}

void boxline_top(int x, int y) {
    move_cursor(x, y);
    printf("┌");
    for (int i = 0; i < left_w - 2; i++) printf("─");
    printf("┐");
}

void boxline_txt(int x, int y, char *text) {
    move_cursor(x - 2, y);
    printf("│ ");
    printf("%s", text);
    move_cursor(x + left_w - 3, y);
    printf("│");
}

void boxline_nul(int x, int y) {
    move_cursor(x, y + 1);
    printf("│ ");
    move_cursor(x + left_w - 1, y + 1);
    printf("│");
}

void boxline_bot(int x, int y, int h) {
    move_cursor(x, y + h - 1);
    printf("└");
    for (int i = 0; i < left_w - 2; i++) printf("─");
    printf("┘");
}

void boxline_left(int x, int y, int h) {
    for (int i = 1; i < h - 1; i++) {
        move_cursor(x, y + i);
        printf("│");
    }
}

void boxline_right(int x, int y, int w, int h) {
    for (int i = 1; i < h - 1; i++) {
        move_cursor(x + w - 1, y + i);
        printf("│");
    }
}

void update_layout() {
    int width, height;
    get_terminal_size(&width, &height);

    left_w = width * 0.5 - PADDING;
    list_h = height;
    right_w = width * 0.5 - PADDING;
    overview_h = height * 0.12;
    search_h = height * 0.5;
    io_h = height * 0.35;
    msg_h = height * 0.1;

    x_list = PADDING + 2;
    y_list = PADDING + 1;
    x_overview = left_w + 4;
    y_overview = PADDING + 1;
    x_search = x_overview;
    y_search = y_overview + overview_h;
    x_io = x_overview;
    y_io = y_search + search_h;
    x_message = x_overview;
    y_message = y_io + io_h;
}

void draw_box() {
    update_layout();

    /* BOX: LIST */
    boxline_top(PADDING, PADDING);
    boxline_bot(PADDING, PADDING, list_h);

    /* BOX: OVERVIEW */
    boxline_top(left_w + 2, PADDING);
    boxline_bot(left_w + 2, PADDING, overview_h);

    /* BOX: SEARCH */
    boxline_top(left_w + 2, PADDING + overview_h);
    boxline_bot(left_w + 2, PADDING + overview_h, search_h);

    /* BOX: MESSAGE */
    boxline_top(left_w + 2, PADDING + overview_h + search_h + io_h);
    boxline_bot(left_w + 2, PADDING + overview_h + search_h + io_h, msg_h);

    /* BOX: I/O */
    boxline_top(left_w + 2, PADDING + overview_h + search_h);
    boxline_bot(left_w + 2, PADDING + overview_h + search_h, io_h);
}