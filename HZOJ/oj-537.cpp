/*************************************************************************
	> File Name: oj-537.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 17时42分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int l, c, cnt, ans_cnt, ycnt, fcnt;
char let[30], ans[30];

int dfs(int s, int left) {
    if (left == 0) {
        if (!(ycnt >= 1 && fcnt >= 2)) return 0;
        for (int i = 0; i < l; ++i) cout << ans[i];
        cout << endl;
        cnt++;
        if (cnt == 25000) return -1;
        return 0;
    }
    for (int i = s; i < c; ++i) {
        ans[ans_cnt++] = let[i];
        int flag = 0;
        if (let[i] == 'a' ||
            let[i] == 'o' ||
            let[i] == 'e' ||
            let[i] == 'i' ||
            let[i] == 'u' ) {
            ycnt++;
        } else {
            fcnt++;
            flag = 1;
        }
        if (dfs(i + 1, left - 1) == -1) return -1;
        flag == 1 ? fcnt-- : ycnt--;
        ans_cnt--;
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; ++i) cin >> let[i];
    sort(let, let + c);
    dfs(0, l);
    return 0;
}
