/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月26日 星期四 11时58分01秒
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
 
int main()
{
  initscr();
  move( 5, 15 );
  printw( "%s", "Hello world" );
  refresh();
  sleep(2);
  endwin();
  exit(EXIT_SUCCESS);

