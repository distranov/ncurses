/*
 cbreak() При частичном контроле все нажимаемые клавиши, прежде чем попасть в stdin, проходят проверку
 raw()    символы попадут в программу без генерирования прерывания. Это очень удобно, поскольку позволяет отслеживать все действия пользователя. 
          Функция cbreak() отменяет действие raw().
 noecho() при вводе, вводимые символы не будут отображаться на экран

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
    //box(win, 'a', 'b');  // 'a' -top and bottom 'b' - left and right
    wborder(win, '1', '2', '3', '4', '5', '6', '7', '8');
    //wprintw(win, "this is my box");
    mvwprintw(win, 1, 1, " in box ");
    wrefresh(win);

    c = getch();                 
    endwin();                    
    return 0;
}