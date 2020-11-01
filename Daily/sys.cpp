/*************************************************************************
	> File Name: sys.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月30日 星期五 18时34分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int calc(int num, int x) {
    int tmp = num, sum = 0;
    while (tmp) {
        sum *= x;
        sum += tmp % x;
        tmp /= x;
    }
//    cout << " sum : " << sum  << "; num : " << num << endl;
    if (sum == num) return 1;
    return 0;
}

int main() {
   int beg = 11;
    while (!(calc(beg, 10) && calc(beg, 8) && calc(beg, 2))) beg += 2;
    cout << beg << endl;

    return 0;
}
