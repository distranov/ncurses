#include <ncurses.h>
int main() {

    initscr();
    noecho();
    cbreak();

    int  xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true); // for arrow keys

    const char choices[3][5] = { "Walk", "Jog", "Run" };
    int choice;
    int highlight = 0;

    while(1) {
        for(int i = 0; i < 3; i++) {
            if(i == highlight) wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        switch(choice) {
            case KEY_UP   : if(highlight > 0) highlight--; break;
            case KEY_DOWN : if(highlight < 2) highlight++; break;
            default : break;
        }
        if(choice == 10) break;

    }

    clear();
    printw("your choices is %s", choices[highlight]);
    getch();
    endwin();
    return 0;
}