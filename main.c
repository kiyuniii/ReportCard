#include "linked_list.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int get_terminal_width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // 터미널 크기 가져오기
    return w.ws_col; // 너비(컬럼 개수) 반환
}

int main() {
    // clear_screen();
    // print_boxline_top();
    // print_box_content("REPORT CARD");
    // print_boxline_bottom();
    int SCREEN_WIDTH = get_terminal_width();

    clear_screen();
    draw_box();
}