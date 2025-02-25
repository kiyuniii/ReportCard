#include "table.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

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

void print_boxline_top(int x, int y, int w) {
    move_cursor(x, y);
    printf("┌");
    for (int i = 0; i < w - 2; i++) printf("─");
    printf("┐");
}

void print_boxline_bottom(int x, int y, int w, int h) {
    move_cursor(x, y + h - 1);
    printf("└");
    for (int i = 0; i < w - 2; i++) printf("─");
    printf("┘");
}

void print_boxline_left(int x, int y, int h) {
    for (int i = 1; i < h - 1; i++) {
        move_cursor(x, y + i);
        printf("│");
    }
}

void print_boxline_right(int x, int y, int w, int h) {
    for (int i = 1; i < h - 1; i++) {
        move_cursor(x + w - 1, y + i);
        printf("│");
    }
}

void draw_box() {
    int width, height;
    get_terminal_size(&width, &height);

    int list_w = width * 0.5;
    int list_h = height * 0.85;
    int right_w = width * 0.5 - PADDING;
    int overview_h = height * 0.12;
    int search_h = height * 0.73;
    int io_h = height * 0.1;

    /* BOX: LIST */
    print_boxline_top(PADDING, PADDING, list_w);
    print_boxline_bottom(PADDING, PADDING, list_w, list_h);

    /* BOX: OVERVIEW */
    print_boxline_top(list_w + 2 * PADDING, PADDING, right_w);
    print_boxline_bottom(list_w + 2 * PADDING, PADDING, right_w, overview_h);
    print_boxline_left(list_w + 2 * PADDING, PADDING, overview_h);
    print_boxline_right(list_w + 2 * PADDING, PADDING, right_w, overview_h);

    /* BOX: SEARCH */
    print_boxline_top(list_w + 2 * PADDING, PADDING + overview_h, right_w);
    print_boxline_bottom(list_w + 2 * PADDING, PADDING + overview_h, right_w, search_h);

    /* BOX: I/O */
    print_boxline_top(PADDING, height - io_h - PADDING, width);
    print_boxline_bottom(PADDING, height - io_h - PADDING, width, io_h);
}