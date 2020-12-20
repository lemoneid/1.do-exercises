/*************************************************************************
	> File Name: shape.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月26日 星期四 11时23分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ncurses.h>
using namespace std;

//统一x表示行，y表示列，非坐标

class Shape {
public:
    int sx, sy; //输出位置起点
    Shape() = default;
    Shape(int x, int y);
    ~Shape() {};
};

class ShapePainter { //纯虚类，打印图形
public:
    virtual void show() = 0;
};

class Triangle: Shape, public ShapePainter {
    int lx, ly; //等腰，左下脚坐标
    int rx, ry;
public:
    Triangle() = default;
    Triangle(int x, int y, int x1, int y1, int x2, int y2);
    Triangle(int x, int y, int x1, int y1);
    ~Triangle() {};
    void show();
};

class Rectangle: Shape, public ShapePainter {
    int length, width;    
public:
    Rectangle() = default;
    Rectangle(int x, int y, int l, int w);
    ~Rectangle() {};
    void show(); 
};


class Circle: Shape, public ShapePainter {
    int radius;
    public:
    Circle() = default;
    Circle(int x, int y, int r);
    ~Circle() {};
    void show(); 
};

Shape::Shape(int x, int y): sx(x), sy(y) {};

Triangle::Triangle(int x, int y, int x1, int y1, int x2, int y2): Shape(x, y) {
    if (x1 <= sx || x2 <= sx) return ;
    if (y1 < y2) {
        lx = x1; ly = y1;
        rx = x2; ry = y2;
    } else {
        rx = x1; ry = y1;
        lx = x2; ly = y2;
    }
}

Triangle::Triangle(int x, int y, int x1, int y1): Shape(x, y) {
    if (x1 <= sx) return ;
    lx = rx = x1;
    if (y1 < sy) {
        ly = y1;
        ry = sy * 2 - y1;
    } else {
        ly = sy * 2 - y1;
        ry = y1;
    }
}
void Triangle::show() {
    for (int i = ly; i <= ry; ++i) {
        mvaddch(lx, i, '*');
    }
    //相似三角形
    double rate = abs(sy - ly) * 1.0 / abs(sx - lx); 
    int len = 0;
    for (int i = 0; i < abs(sx - lx); ++i) {
        len = (int)(rate * abs(i));
        mvaddch(sx + i, sy - len, '*');
        mvaddch(sx + i, sy + len, '*');
    }
}

Rectangle::Rectangle(int x, int y, int l, int w): Shape(x, y) {
    length = l, width = w;
}
void Rectangle:: show() {
    for (int i = 0; i <= width; ++i) {
        mvaddch(sx + i , sy, '*');
        mvaddch(sx + i , sy + length * 2, '*');
    }
    for (int i = 0; i <= length; ++i) {
        mvaddch(sx, sy + i * 2, '*');
        mvaddch(sx + width, sy + i * 2, '*');
    }
}

Circle::Circle(int sx, int sy, int r): Shape(sx, sy) {
    radius = r;
}
void Circle::show() {
    //point = sqrt(r^2 - i^2)
    int point = 0;
    for (int i = 0; i <= radius; ++i) {
        point = sqrt(radius * radius - i * i);
        if (abs(point * point + i * i - radius * radius) > 2) continue;
        mvaddch(sx - i, sy - 2 * point, '*');
        mvaddch(sx - i, sy + 2 * point, '*');
        mvaddch(sx + i, sy - 2 * point, '*');
        mvaddch(sx + i, sy + 2 * point, '*');
    }
}

void init_scr() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    clear();

}

void destroy() {
    
}

void drawHome() {
    ShapePainter *p = nullptr;
    Rectangle rec = Rectangle(10, 10,  20, 20);
    Circle cir = Circle(20, 30 ,5);
    Triangle tri = Triangle(5, 30, 10, 10);
    p = &rec;
    p->show();
    p = &cir;
    p->show();
    p = &tri;
    p->show();
}

int main() {
    init_scr();
    int row, col;
    drawHome();    
    refresh();
    mvaddstr(LINES- 5,  4, "Press any key to quit");
    refresh();
    getch();
    endwin();
    return 0;
}
