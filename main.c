#include "table.h"
#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    clear_screen();
    update_layout();
    draw_box();

    List *list;
    init_manager(list);
    move_cursor(x_io, y_io);
}