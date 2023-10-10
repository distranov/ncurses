#include <ncurses.h>
int main() {
    int c = 0;
    int height, width, pos_y, pos_x;

    initscr();
    height = 10; width = 20; pos_y = 1; pos_x = 1;
    WINDOW *win = newwin(height, width, pos_y, pos_x);
    refresh();
    box(win, 0, 0);
    wprintw(win, "this is win");
    mvwprintw(win, 1, 1, " win ");
    wrefresh(win);

    height = 10; width = 20; pos_y = 1; pos_x = 30;
    WINDOW *win1 = newwin(height, width, pos_y, pos_x);
    refresh();
    //box(win, 'a', 'b'); // 'a' -top and bottom 'b' - left and right
    wborder(win1, '1', '2', '3', '4', '5', '6', '7', '8');
    wprintw(win1, "this is win1");
    mvwprintw(win1, 1, 1, " win1 ");
    wrefresh(win1);

    c = getch();
    endwin();
    return 0;
}