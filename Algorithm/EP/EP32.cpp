/*************************************************************************
	> File Name: EP32.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月10日 星期日 15时46分53秒
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

int add_to_num(int x, int *num) {
    while ( x ) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}
inline int digit(int x) {
    if (!x) return 1;
    return floor(log10(x)) + 1;
} 

int is_val(int a, int b, int c) {
    if (digit(a) + digit(b) + digit(c) - 9) return 0;
    int num[10] = {0}, flag = 1;
    num[0] = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(c, num);
    return flag;
}
int keep[100000] = {0};
int main() {
    int sum = 0;
    for (int a = 1; a < 100; ++a) {
        for (int b = a + 1; b < 10000; ++b) {
            if ( !is_val(a, b, a * b)) continue;
            printf("%d * %d = %d\n", a, b, a * b);
            if(!keep[a * b])sum += a * b; 
            keep[a * b] = 1;
        }
    }
    int a = 2;
    cout << sum << endl;
    return 0;
}
