/*************************************************************************
	> File Name: snake.h
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月03日 星期四 15时47分48秒
 ************************************************************************/

#ifndef _SNAKE_H
#define _SNAKE_H
#include <dequeue>
struct Point {
    int x, y;
    Point() = default;
    Point(int x, int y) : x(x), y(y) {};
    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    int GetX(){ return this->x; }
    int GetY(){ return this->y; }
}

class Snake {
private:
    std::dequeue<Point>  snake;
    int dir;
    friend class Food;
public:
    void InitSnake();
    void Move();
    void NormalMove();
    bool OverEdge();
    bool HitItself();
    bool ChangeDirection();
    bool GetFood(const Food&);
    bool GetBigFood(Food&);
}


#endif
