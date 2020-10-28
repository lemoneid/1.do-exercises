/*************************************************************************
> File Name: oj-588.cpp
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月11日 星期二 20时59分07秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int ans[5000], tmp[5000] = {1, 1};
int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int id = 1, k = 1;
        memset(ans, 0, sizeof(ans));
        while (id <= tmp[0]) {
            int cnt = 0, val = tmp[id];
            while(tmp[id] == val) {
                cnt++;
                id++;
            }
            ans[k++] = cnt;
            ans[k++] = val;
        }
        ans[0] = k - 1;
        memcpy(tmp, ans, sizeof(ans));
    }

    for (int i = 1; i <= ans[0]; ++i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
