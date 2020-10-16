/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月15日 星期四 18时57分12秒
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
#define MAX_N 25000
int ans_cnt, ycnt, fcnt, cnt;
int l, c;
char letter[30], ans[30];

int dfs(int s, int left) {
    if (left == 0) {
        if (!(ycnt >= 1 && fcnt >= 2)) return 0;
        for(int i = 0; i < l; ++i) {
            cout << ans[i];
        } 
        cout << endl;
        cnt++;
        if (cnt == MAX_N) return -1;
        return 0;
    }
    for (int i = s; i < c; ++i) {
        ans[ans_cnt++] = letter[i];
        int flag = 1;
        if (letter[i] == 'a' || 
            letter[i] == 'e' ||
            letter[i] == 'i' ||
            letter[i] == 'o' ||
            letter[i] == 'u'
        ) {
            ycnt++; 
        } else {
            fcnt++;
            flag = 0;
        }
        int ret = dfs(i + 1,left - 1);
        if (ret == -1) return -1;
        flag ?  ycnt-- : fcnt--;
        ans_cnt--;
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; ++i) cin >> letter[i];
    sort(letter, letter + c);
    dfs(0, l);
    return 0;
}
