/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 16时18分47秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
#define max_n 1000

int ans[max_n + 5] = {0};

int main() {    
    int m, n;
    cin >> m >> n;
    ans[0] = ans[1] = 1; 
    for (int i = 0 ; i < n; ++i) {
        for (int j = 1; j <= ans[0]; ++j) {
            ans[j] *= m;
        }
        for (int i = 1; i <= ans[0]; ++i) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i > 0; --i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
