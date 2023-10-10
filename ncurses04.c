#include <ncurses.h>

int main() {

    initscr();
/*
    if(!has_colors()) {
        printw("terminal does not support color");
        getch();
        endwin();
        return(-1);
    }
*/
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);    

    attron(A_REVERSE);
    printw("This is some text\n");
    attroff(A_REVERSE);

    if(can_change_color()) init_color(COLOR_CYAN, 500, 300, 500);

    init_pair(2, COLOR_WHITE, COLOR_CYAN);
    attron(COLOR_PAIR(2));
    printw("This is some text\n");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    printw("This is some text\n");
    attroff(COLOR_PAIR(1));

    getch();
    endwin();
    return 0;
}
