/*************************************************************************
	> File Name: oj-236.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月11日 星期二 19时23分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m,num[15], cnt = 1;

void p() {
    for (int i = 1; i <= m; ++i) {
        i != 1 && cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int start, int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = start; i <= n - left + 1; ++i) {
        num[cnt++] = i;
        func(i + 1, left - 1); 
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
