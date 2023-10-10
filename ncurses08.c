#include <ncurses.h>

int main() {
    initscr();
    noecho();
    cbreak();

    int  xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *playwin = newwin(20, 50, yMax/2 - 10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    
    
    
    getch();
    endwin();
    return 0;
}