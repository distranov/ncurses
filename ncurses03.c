/*
Вывод без ввода смысла не имеет, поэтому разберём функции ввода. Как и функции вывода, функции ввода 
условно можно поделить на три группы:

getch()-функции. Считывание символа.
scanw()-функции. Форматированный ввод.
getstr()-функции. Считывание строки.

getch()-функции
Эта функция считывает только один символ с терминала. Имеет модификации wgetch(), mvgetch() и mvwgetch(). 
Совместно с функцией keypad() предоставляет удобное средство для управления клавиатурой.

scanw()-функции
Аналог scanf() из stdio, то есть форматированный ввод с клавиатуры. Как всегда, имеется wscanw(), mvscanw(), 
mvwscanw().

getstr()-функции
Как известно, scanf(), а значит и scanw() некорректно считывают строки — только до первого 
символа-разделителя. Чтобы считывать строки вместе с символом разделителем, была создана функция 
getstr() (имеются, соответственно, wgetstr(), mvgetstr() и mvwgetstr()).
*/
#include <ncurses.h>
#include <unistd.h>

const char items[4][6] = {
    "Item1", 
    "Item2",
    "Item3", 
    "Item4"
};

int main()
{
    initscr();

    unsigned choice = 0; //Выбор пользователя

    curs_set(0); //"Убиваем" курсор
    //Включаем режим удобной работы с функциональными клавишами, другими словами KEY_UP и KEY_DOWN без этого не работали бы
    keypad(stdscr, true); 
    bool ex = false;
    while ( !ex )
    {
        clear();
        for ( unsigned i = 0; i < 4; i++ ) //Проходим по всем элементам меню
        {
            if ( i == choice ) //Если текущий элемент совпадает с выбором пользователя
                addch('>'); //Выводим указатель
            else          
                addch(' '); //Иначе выводим " ", для равновесия

            printw("%s\n", items[i]);
        }

        //Получаем нажатие пользователя
        switch ( getch() )
        {
            case KEY_UP:
                if ( choice ) //Если возможно, переводим указатель вверх
                    choice--; 
                break;
            case KEY_DOWN:
                if ( choice != 3 ) //Если возможно, переводим указатель вниз
                    choice++;
                break;
            case '\n' :               
                ex = true;
                break;

        }
    }
    clear();
    char str[100];
    sprintf(str, "your choice %s\n", items[choice]);
    

while ( true )
    {
    //Перемещаем х-координату как можно дальше вправо, и будем уменьшать её, пока она != 0
        for ( unsigned x = getmaxx(stdscr); x; x-- ) 
        {
            clear();
            mvaddstr(getmaxy(stdscr) / 2, x, str);
            refresh();
            usleep(200000);
        }
    }





    getch();
    endwin();
    return 0;
}