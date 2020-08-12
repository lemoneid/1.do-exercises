/*************************************************************************
> File Name: oj-237.cpp
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月11日 星期二 19时42分38秒
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[15], cnt = 1, mark[15];

void p() {
    for (int i = 1; i <= n; ++i) {
        i != 1 && cout << " ";
        cout << num[i];
    }
    cout << endl;
}


void func(int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (mark[i] == 0) {
            mark[i] = 1;
            num[cnt++] = i;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    func(n);
    return 0;
}
