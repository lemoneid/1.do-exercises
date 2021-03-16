/*************************************************************************
	> File Name: 28.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 09时45分43秒
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
#include <inttypes.h>
using namespace std;

int main() {
    int32_t sum = 1, len = 3;
    while (len <= 1001) {
        sum += 4 * len * len - 6 * len + 6;
        len += 2;
    }
    printf("%d\n", sum);
    return 0;
}
