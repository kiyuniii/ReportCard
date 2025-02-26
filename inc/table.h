#ifndef __TABLE_H__
#define __TABLE_H__

#define PADDING 1

typedef struct {
    int *left_w, *right_w, \
           *list_h, *overview_h, *search_h, *io_h, *msg_h;
} Layout;

typedef struct {
    int *x_list, *y_list,           \
           *x_overview, *y_overview,   \
           *x_search, *y_search,       \
           *x_io, *y_io,               \
           *x_message, *y_message;
} Point;

extern Layout *layout;
extern Point *point;

void init_table();
void free_table();
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