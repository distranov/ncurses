/*
 Использование функций raw() и cbreak() позволяет управлять режимом клавиатуры
 — либо это полный контроль над клавиатурой, либо частичный. При частичном 
 контроле все нажимаемые клавиши, прежде чем попасть в stdin, проходят проверку.
 Хороший пример такой проверки — сочетание CTRL+C. Это сочетание зарезервировано,
 и поэтому при нажатии этих клавиш будет вызвано прерывание, которое завершит
 работу программы. Но в raw-режиме(то есть при полном контроле над клавиатурой), 
 эти символы попадут в программу без генерирования прерывания. Это очень удобно, 
 поскольку позволяет отслеживать все действия пользователя. 
 Функция cbreak() отменяет действие raw().
 
 Функции echo() и noecho() управляют отображением вводимых символов на экран. 
 Если была вызвана функция noecho(), то при вводе, вводимые символы не будут 
 отображаться на экран. echo() отменяет действие noecho().
 
 Функция keypad() включает режим простой работы с функциональными клавишами, 
 такими как F1, F2 и т.п. Принимает два параметра: ncurses-окно(см.ниже) а так же 
 переменную типа bool. Если последняя переменная равна true, то для данного 
 ncurses-окна включается такой режим, если false, то выключается.
 
 Функция halfdelay() включает half-delay-режим, когда функция getch() может ждать
 нажатия клавиши не более чем n десятых секунды. Если же нажатия не последовало, 
 то getch() вернёт ERR.
*/
#include <ncurses.h>

int main()
{
    initscr();             
    raw();                  //Берём управление клавиатурой на себя
	noecho();               //Выключаем отображение вводимых символов, нужно для getch()
    halfdelay(100);         //Устанавливаем ограничение по времени ожидания getch() в 10 сек
    keypad(stdscr, true);   //Включаем режим чтения функциональных клавиш

	bool ex = false;

	while(!ex) {
	    int ch = getch();

        switch(ch) {
			case ERR:
				printw("Please, press any key...\n"); //Если нажатия не было, напоминаем пользователю, что надо нажать клавишу
				break;
			case KEY_F(2): //Выходим из программы, если была нажата F2
				ex = true;
				break;
			default:  //Если всё нормально, выводим код нажатой клавиши
				printw("Code of pressed key is %d\n", ch);
				break;
		}
        refresh(); //Выводим на настоящий экран
	}
    endwin();             
    return 0;
}