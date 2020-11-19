/*************************************************************************
	> File Name: interface.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月13日 星期五 18时11分31秒
 ************************************************************************/

#include "interface.h"

Interface::Interface() {

}

Interface::~Interface() {

}

void Interface::displayMainWindow() {
    initscr();
    printw("欢迎使用小开游戏平台");
}
