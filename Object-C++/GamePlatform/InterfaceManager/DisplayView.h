#ifndef _DISPLAY_VIEW_H_
#define _DISPLAY_VIEW_H_
#include <ncurses.h>
#include <functional>
// BaseView
// 	LoginView
// 	GameMenuView
// 	GameView
// 		SnakeView
// 		BoxView
// 	ErrorModelView

// 这个应该是一个接口类
class BaseView
{
protected:
    WINDOW *currentWindow;
    virtual void backUp() = 0;
public:
    virtual void show() = 0;
    virtual void hide() = 0;

    virtual void helpMeShow(std::function<void (WINDOW *)> helpfunc) = 0;

    virtual ~BaseView() = default;

    // static void GlobleConfig();
};

class LoginView: public BaseView
{
protected:
    void backUp();
public:
    void show();
    void hide();

    void helpMeShow(std::function<void (WINDOW *)> helpfunc);
};


#endif /*_DISPLAY_VIEW_H_*/
