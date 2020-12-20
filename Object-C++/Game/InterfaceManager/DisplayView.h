/*************************************************************************
	> File Name: DisplayView.h
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月27日 星期五 19时31分11秒
 ************************************************************************/

#ifndef _DISPLAYVIEW_H
#define _DISPLAYVIEW_H
#include <ncurse.h>

class BaseView {

protected:
    WINDOW *currentWindow;

public : 
    virtual void show() = 0;
    virtual void hide() = 0;

    virtual ~BaseView() = default;
    static void GlobleConfig();
}

class LoginView: public BaseView {

protected:
    void backUp();

public:
    void show();
    void hide();
}

#endif
