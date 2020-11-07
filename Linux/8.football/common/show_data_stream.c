/*************************************************************************
	> File Name: show_data_stream.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月01日 星期日 16时47分00秒
 ************************************************************************/

#include "head.h"
extern char data_stream[20]; //既然是外部变量，那就分别再client.c,server.c中定义吧
extern WINDOW *Help;
extern struct Map court;//该变量用来在函数中定位要输出的位置
//type： 'l','c','k','s','n','e'
//分别表示：login， carry， kick， stop， normal， exit
void show_data_stream(int type) {
    //data_stream数组后移一位，将type加到第一位
    //根据type不同，使用wattron设置Help窗口的颜色
    //在合适位置打印一个空格
   	for (int i = 18; i > 1; i--) {
		data_stream[i] = data_stream[i - 1];
	}
	data_stream[1] = type;
	for (int i = 1; i < 19; i++) {
		switch(data_stream[i]) {
			case 'l':
				wattron(Help, COLOR_PAIR(8));
				break;
			case 'c':
				wattron(Help, COLOR_PAIR(7));
				break;
			case 'k':
				wattron(Help, COLOR_PAIR(8));
				break;
			case 's':
				wattron(Help, COLOR_PAIR(9));
				break;
			case 'n':
				wattron(Help, COLOR_PAIR(10));
				break;
			case 'e':
				wattron(Help, COLOR_PAIR(11));
				break;
			default:
				break;
		}
		mvwprintw(Help, court.height - 1, i, " ");
		wattron(Help, COLOR_PAIR(2));
	} 
}
