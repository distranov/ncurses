/*



*/


#include <ncurses.h>

int main() {    
    int c = 0;
    int height, width, pos_y, pos_x;
    height = 10;
    width = 20;
    pos_y = 10;
    pos_x = 10;

    initscr();  

    WINDOW *win = newwin(height, width, pos_y, pos_x);
    refresh();
    box(win, 0, 0);
    wprintw(win, "this is my box");
    mvwprintw(win, 1, 1, " in box ");
    wrefresh(win);

    c = getch();                 
    endwin();                    
    return 0;
}