/*************************************************************************
	> File Name: ball_status.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月01日 星期日 16时45分47秒
 ************************************************************************/

#include "head.h"
extern struct Bpoint ball;
extern struct BallStatus ball_status;
int can_kick(struct Point *loc, int strength){
    //palyer和ball坐标对齐
    //判断palyer和ball的坐标在上下左右2个单位距离内，则可踢球
    //根据player和ball的相对位置，计算球的运动方向，加速度方向，假设球只能在palyer和ball的延长线上运动
    //假设player踢球的接触时间为0.2秒，默认加速度为40，力度增加，加速度也增加
    //可踢返回1，否则返回0
}
