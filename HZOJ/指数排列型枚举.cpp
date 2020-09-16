/************************************************************************
> File Name: oj-235.cpp
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月11日 星期二 18时39分29秒
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[15], cnt = 1, cnt_tmp = 1, mark[15], tmp[15];

void p() {
    for (int i = 1; i <= cnt; ++i) {
        i != 1 && cout << " ";
        cout << tmp[i];
    }
    cout << endl;
}


void do_tmp(int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = 1; i <= cnt; ++i) {
        if (mark[i] == 0) {
            mark[i] = 1;
            tmp[cnt_tmp++] = num[i];
            do_tmp(left - 1);
            cnt_tmp--;
            mark[i] = 0;
        }
    }

}

void func(int start) {
    for (int i = start; i <= n; ++i) {
        num[cnt] = i;
        do_tmp(cnt);
        cnt++;
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
