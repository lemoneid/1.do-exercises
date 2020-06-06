/*************************************************************************
	> File Name: next_permunation.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月02日 星期二 19时12分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 10

int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int main() {
    int x, y, cnt = 1;
    cin >> x >> y;
    do {
        next_permutation(num, num + x);
        ++cnt;
    } while (cnt < y);
    for (int i = 0; i < x; ++i) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
