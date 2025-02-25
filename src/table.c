#include "table.h"
#include <stdio.h>
#include <string.h>

void clear_screen() {
    printf("\033[2J\033[H");    
}

void print_boxline_top() {
    printf(ANSI_BOLD ANSI_COLOR_BLUE);
    printf("┌");
    for (int i = 0; i < SCREEN_WIDTH-2; i++) {
        printf("─");
    }
    printf("┐\n" ANSI_COLOR_RESET);
}

void print_boxline_bottom() {
    printf(ANSI_BOLD ANSI_COLOR_BLUE);
    printf("└");
    for (int i = 0; i < SCREEN_WIDTH-2; i++) {
        printf("─");
    }
    printf("┘\n" ANSI_COLOR_RESET);
}

void print_centered(const char* text) {
    int padding = (SCREEN_WIDTH - strlen(text)) / 2;  
    printf(ANSI_BOLD ANSI_COLOR_GREEN);
    for (int i = 0; i < padding; i++) { 
        printf(" ");
    }
    printf("%s" ANSI_COLOR_RESET "\n", text);  
}

void print_box_content(const char* text) {
    int padding = (SCREEN_WIDTH - strlen(text) - 2) / 2;
    printf(ANSI_BOLD ANSI_COLOR_BLUE "│" ANSI_COLOR_RESET);
    printf(ANSI_BOLD ANSI_COLOR_GREEN);
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", text);
    for (int i = 0; i < padding + ((SCREEN_WIDTH - (int)strlen(text)) % 2); i++) {
        printf(" ");
    }
    printf(ANSI_COLOR_RESET ANSI_COLOR_BLUE "│\n" ANSI_COLOR_RESET);
}
