/*************************************************************************
	> File Name: oj-235.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月11日 星期二 18时39分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[15], cnt = 1;

void p() {
    for (int i = 1; i < cnt; ++i) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int start) {
    for (int i = start; i <= n; ++i) {
        num[cnt++] = i;
        p();
        func(i + 1);
        cnt--;
    }
    return ;
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
