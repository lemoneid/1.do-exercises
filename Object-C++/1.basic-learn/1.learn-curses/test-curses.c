/*************************************************************************
	> File Name: test-curses.c
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月26日 星期四 13时16分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    printw("Type any char to see it bold\n");
    char ch = getch();
    if (ch == KEY_F(1)) {
        printw("F1 Key pressed");
    } else {
        printw("the pressed key is");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();
    getch();
    endwin();
    return 0;
}
