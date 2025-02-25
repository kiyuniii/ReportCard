#ifndef __TABLE_H__
#define __TABLE_H__

/* MVC의 View를 담당하며,
    - 데이터 시각화
    - CRUD를 위한 입출력 담당 */

#define SCREEN_WIDTH 80

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD          "\x1b[1m"

void clear_screen();
void print_boxline_top();
void print_boxline_bottom();
void print_box_content(const char* text);

#endif//__TABLE_H__