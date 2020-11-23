/*************************************************************************
	> File Name: cd-94.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 21时23分35秒
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

int process(int upperLim, int col, int left, int right) {
    if (col == upperLim) {
        return 1;
    }
    int pos = 0, mostRightOne = 0, res = 0;
    pos = upperLim &(~(col | left | right));
    while (pos != 0) {
        mostRightOne = pos & (~pos + 1);
        pos = pos - mostRightOne;
        res += process(upperLim, col | mostRightOne, (left | mostRightOne) << 1, (right | mostRightOne) >> 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int upperLim = (n == 32 ? -1 : (1 << n) - 1);
    cout << process(upperLim, 0, 0, 0);

    return 0;
}
