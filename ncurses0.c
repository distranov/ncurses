/*
$ sudo apt install libncursesw5-dev
$ gcc ncurses0.c -o ncurses.bin -lncurses
*/

#include <ncurses.h>

int main() {    
    initscr();                   // Переход в curses-режим
    printw("Hello world!\n");    // Отображение приветствия в буфер
    refresh();                   // Вывод приветствия на настоящий экран
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
    return 0;
}

