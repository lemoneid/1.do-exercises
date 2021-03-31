/*************************************************************************
	> File Name: cout.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月29日 星期一 12时37分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#define BEGINS(x) namespace x {
#define ENDS(x) } // namespace x;
BEGINS(MY)
class ostream {
public :
    ostream &operator<<(int x);
    ostream &operator<<(const char *x);
};

ostream &ostream::operator<<(int x) {
    printf("%d", x);
    return *this;
}
ostream &ostream::operator<<(const char *x) {
    printf("%s", x);
    return *this;
}
ostream cout;
char endl = '\n';
ENDS(MY)

int main() {
    int n = 123, m = 456;
    std::cout << n << " " << m << std::endl;
    MY::cout << n << " " << m << MY::endl;

    return 0;
}
