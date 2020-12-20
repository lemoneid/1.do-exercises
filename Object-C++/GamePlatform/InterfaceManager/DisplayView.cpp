#include "DisplayView.h"
#include <locale.h>
#include <iostream>

// void BaseView::GlobleConfig()
// {
//     setlocale(LC_ALL,"");
//     initscr();
// }

void LoginView::backUp()
{
    if (currentWindow == nullptr)
    {
        currentWindow = newwin(20,60,0,0);
    }

    box(currentWindow, 0, 0);

    noecho();
    nodelay(currentWindow, TRUE);
    cbreak();
    curs_set(FALSE);

    keypad(currentWindow, TRUE);
}

void LoginView::show()
{
    setlocale(LC_ALL,"");
    initscr();
    backUp();
    wrefresh(currentWindow);
}

void LoginView::hide()
{
    delwin(currentWindow);
    currentWindow = nullptr;
}

void LoginView::helpMeShow(std::function<void (WINDOW *)> helpfunc)
{
    helpfunc(currentWindow);
}
