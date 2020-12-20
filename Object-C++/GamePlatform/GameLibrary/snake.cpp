#include "snake.h"
void Snake::InitSnake() {
    snake.push_front(Point(5, 5));
}
void Snake::Move() {
    Point head = snake.front();
    switch (dir) {
        snake.push_front(Point(head.Getx(), head.Gety() - 1));
    }
}
    void NormalMove();
    bool OverEdge();
    bool HitItself();
    bool ChangeDirection();
    bool GetFood(const mZood&);
