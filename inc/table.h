#ifndef __TABLE_H__
#define __TABLE_H__

//#define SCREEN_HEIGHT 50
#define PADDING 1

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD          "\x1b[1m"

void get_terminal_size(int *width, int *height);
void move_cursor(int x, int y);
void clear_screen();

void print_boxline_top(int x, int y, int w);
void print_boxline_bottom(int x, int y, int w, int h);
void print_boxline_left(int x, int y, int h);
void print_boxline_right(int x, int y, int w, int h);

void draw_box();

#endif//__TABLE_H__