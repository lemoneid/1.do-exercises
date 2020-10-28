/*************************************************************************
	> File Name: oj-503.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月31日 星期日 13时21分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 30000

int a[max_n + 5] = {0};

void output(int w, int n) {
    int sum, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(!a[i]) continue;
        sum = a[i];
        for (int j = n - 1; j > i; --j) {
            if (!a[j]) continue;
            if (a[j] + sum <= w) {
                sum += a[j];
                a[j] = 0;
            }   
        }
        ++cnt;
    }
    cout << cnt << endl;
}

int main() {
    int w, n;
    while(cin >> w >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        output(w, n);
    }
}
