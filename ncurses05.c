#include <ncurses.h>

int main() {

    initscr();

    int  x, y;
    getyx(stdscr, y, x);
    printw("getyx x: %d y: %d\n", x, y);
    getbegyx(stdscr, y, x);
    printw("getbegyx x: %d y: %d\n", x, y);
    getmaxyx(stdscr, y, x);
    printw("getmaxyx x: %d y: %d\n", x, y);
    mvprintw(getmaxy(stdscr)/2, getmaxx(stdscr)/2, "center");
    
    getch();
    endwin();
    return 0;
}
