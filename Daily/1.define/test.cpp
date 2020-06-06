/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月04日 星期四 18时40分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

void func(int);
int add(int, int);

int main() {
    cout << add(3, 5) << endl;
    return 0;
}
void func(int n) {
    if (n == 0) return;
    cout << "func A: " << n << endl;
    
    return ;
}

int add(int a, int b) {
    return a + b;
}

