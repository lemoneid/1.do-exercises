#include "PlatformManager.h"
#include "../InterfaceManager/DisplayView.h"
#include <iostream>
using namespace std;

void PlatformManager::start()
{
    /*
    显示对应界面    管理这些界面之间的关系
    （1）界面显示
    （2）界面隐藏
    */
    //    BaseView::GlobleConfig();
    setlocale(LC_ALL,"");
    BaseView *login = new LoginView();
    login->show();

    // Player *p1 = new Player();

    // 分离式的操作
    // helpMeShow 帮助我显示

    // 代理模式 将某一个行为 -> 给另外一个类进行操作
    login->helpMeShow([&](WINDOW *currentWindow){
        mvwprintw(currentWindow, 5,5, "Please input username: ");
        // swscanf 等待读入 
        // cin >> p1->information.username;
        mvwprintw(currentWindow, 10,5, "Please input password: ");
        // cin >> p1->information.password;
        wrefresh(currentWindow);
    });

    while(1);
}
