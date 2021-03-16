/*************************************************************************
	> File Name: ep-05.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 22时57分15秒
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
using namespace std;
//往回推，假设已知上一层的纪录，回推本层的记录 
int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int ret = ex_gcd(b, a % b, y, x); //下一层 gcd(b, a%b);
    *y -= a / b * (*x);  //本层 gcd(a,b);
    return ret;
}

int main() {
    int a, b, x, y;
    while(~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}
