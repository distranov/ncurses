#include <ncurses.h>

int main() {

    initscr();
    noecho();
    cbreak();

    int  xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *inputwin = newwin(3, xMax-12, yMax-5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin, true);

    int c = wgetch(inputwin);
    if(c == KEY_F(2)) {
        mvwprintw(inputwin, 1, 1, "you pressed F2!");
        wrefresh(inputwin);
    }


    getch();
    endwin();
    return 0;
}
