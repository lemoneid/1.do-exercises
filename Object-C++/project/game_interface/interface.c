/*************************************************************************
	> File Name: game_interface/interface.c
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 10时40分39秒
 ************************************************************************/

#include "interface.h"
#include <locale.h>
#include <unistd.h>
/*
    1、界面中文无法显示 √
    2、程序无法有效退出 √
    3、显示内容的位置未设置 √
    4、键盘按键响应问题 √
    5、临时窗口的内容，产生了界面留存
    TIPS：ncurses没有图层化的概念，所有内容，
            其实都是在同一张画布上处理的。
            （1）初始化欢迎界面，需要进行保存
            （2）重新进行界面展示
*/


Interface::Interface(/* args */)
{
}

Interface::~Interface()
{
}
/*
    1、平台提示语 √
    2、游戏列表 √
    3、退出按钮 （是否退出的选择）√
*/

void Interface::displayMainWindow(vector<string> &gameNames)
{
    // 配置ncurses的基本内容
    setlocale(LC_ALL,""); // 使中文显示不乱码
    initscr();

    // printw("欢迎使用小开游戏平台");
    // // 如果没有使用刷新 其存在缓存区域 没有放在界面上显示
    // refresh(); // 将缓存区的内容，刷新到物理屏幕上
    // sleep(2);
    // printw("充值666领取尊贵VIP");

    // int ch = getch();
    // if (ch == 'q')
    // {
    //     exit(0);
    // }
    // 窗口系统
    currentWindow = newwin(20,60,0,0);
    box(currentWindow, 0, 0);
    /*
        有关于显示部分的设置 按键设置
    */
    noecho();
    nodelay(currentWindow, TRUE);
    cbreak();
    curs_set(FALSE);

    // 非标准键（功能键）的有效使用
    keypad(currentWindow, TRUE);

    // configMainWindow(currentWindow);
    // 如果不使用&，对于局部变量，采取的是复制的方式
    // &引用方式捕获 
    auto configMainWindow = [&]() {
                // 在指定的窗口位置输出
    mvwprintw(currentWindow, 5, 5, "欢迎使用小开游戏平台，充值888领取尊贵VIP");

    mvwprintw(currentWindow, 8, 5, "使用方向键选择游戏，使用回车键确认");

    for (unsigned int i = 0; i < gameNames.size(); i++)
    {
        mvwprintw(currentWindow, 10 + i, 5, gameNames[i].c_str());
    };

    mvwprintw(currentWindow, 10 + gameNames.size(), 5, "退出平台");
    mvwchgat(currentWindow, 10, 3, 15, A_REVERSE, 1, NULL);
    wrefresh(currentWindow);
    };
    
   configMainWindow();

    int keyInput;
    int currentChoice = 0;
    while (1)
    {
        keyInput = wgetch(currentWindow);
        if (keyInput == KEY_UP)
        {
            currentChoice--;
        }

        if (keyInput == KEY_DOWN)
        {
            currentChoice++;
        }
        
        if (currentChoice < 0)
        {
            currentChoice = 0;
        }
        
        if (currentChoice > gameNames.size())
        {
            currentChoice = gameNames.size();
        }

        // 选择互斥 原先的选择是一种界面留存方式——>去掉留存
        for (int i = 0; i <= gameNames.size(); i++)
        {
            mvwchgat(currentWindow, 10 + i, 3, 15, A_NORMAL, 1, NULL);
        }
        
        mvwchgat(currentWindow, 10 + currentChoice, 3, 15, A_REVERSE, 1, NULL);
        wrefresh(currentWindow);

        if (keyInput == '\r' || keyInput == '\n')
        {
            if (currentChoice == gameNames.size())
            {
                exit(0);
            } else {
                WINDOW *tempWindow = newwin(20,60,0,0);
                mvwprintw(tempWindow, 8, 5, "游戏尚在开发当中，敬请期待");
                wrefresh(tempWindow);
                sleep(2);
                delwin(tempWindow);

                configMainWindow();
            }

        }
    }
}
