#ifndef __TABLE_H__
#define __TABLE_H__

//#define SCREEN_HEIGHT 50
#define PADDING 1

// #define ANSI_COLOR_RED     "\x1b[31m"
// #define ANSI_COLOR_GREEN   "\x1b[32m"
// #define ANSI_COLOR_YELLOW  "\x1b[33m"
// #define ANSI_COLOR_BLUE    "\x1b[34m"
// #define ANSI_COLOR_RESET   "\x1b[0m"
// #define ANSI_BOLD          "\x1b[1m"

extern int left_w;
extern int list_h;
extern int right_w;
extern int overview_h;
extern int search_h;
extern int io_h;
extern int msg_h;

extern int x_list;
extern int y_list;
extern int x_overview;
extern int y_overview;
extern int x_search;
extern int y_search;
extern int x_io;
extern int y_io;
extern int x_message;
extern int y_message;

void get_terminal_size(int *width, int *height);
void move_cursor(int x, int y);
void clear_screen();

void boxline_top(int x, int y);
void boxline_txt(int x, int y, char* text);
void boxline_nul(int x, int y);
void boxline_bot(int x, int y, int h);

void update_layout();
void draw_box();

#endif//__TABLE_H__