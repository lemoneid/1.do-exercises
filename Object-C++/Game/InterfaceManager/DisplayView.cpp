#include "DisplayView.h"
#include <locale.h>

void BaseView::GlobleConfig() {
    setlocale(LC_ALL, "");
    initscr();
}

void LoginView::backUp() {
    if (currentWindow == nullptr) {
        currentWindow = newwin(20, 60, 0, 0);
    } 
    box(currentWindow, 0, 0);

    noecho();
    nodelay(currentWindow, TRUE);
    cbreak();
    curs_set(FALSE);

    keypad(currentWindow, TRUE);
    mvwprintw(currentWindow, 5, 5, "请输入用户名");
}

void LoginView::show() {
    backUp();

}

void LoginView::hide() {

}
