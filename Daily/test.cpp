/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 03 May 2020 02:19:28 PM CST
 ************************************************************************/

#include<cstdio>

int gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return 0;
    }
    int xx, yy, ret = gcd(a, b, &xx, &yy);
    
}

int main() {
    
    return 0;
}
