#include "table.h"
#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    init_table();       //gen. layout, point

    clear_screen();
    update_layout();    //gen. members of layout, point
    draw_box();

    List *list;
    init_manager(list);
    move_cursor(*point->x_io, *point->y_io);
    
    free_table();
    return 0;
}