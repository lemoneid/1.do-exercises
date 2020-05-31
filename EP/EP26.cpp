/*************************************************************************
	> File Name: EP26.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月31日 星期日 20时05分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max_n 1000

int keep[max_n + 5] = {0};

int get_len(int d) {
    memset(keep, 0, sizeof(keep));
    int r = 1, t = 1;
    while (r) {
        keep[r] = t;
        r *= 10;
        r %= d;
        t += 1;
        if (keep[r]) return t - keep[r];
    }
    return 0;
}

int main() {
    int ans = 0, len = 0;
    for (int i = 2; i <= max_n;++i) {
        int temp = get_len(i);
        if (temp > len) {
            ans = i;
            len =  temp;
        }
        //cout << i << " "<< get_len(i) << endl;
    }
    cout << ans << " " << len << endl;
    return 0;
}
