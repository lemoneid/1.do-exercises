/*************************************************************************
	> File Name: oj-537.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 10时46分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int max_n = 25000;
char ch[30];
char ans[30];
int l, c, cnt, yuan_num, fu_num, idx;
int dfs(int s, int left) {
    if (left == 0 && yuan_num >= 1 && fu_num >= 2) {
        if (cnt >= max_n) return -1;
        for (int i = 0; i < l; i++) {
            cout << ans[i];
        }
        cout << endl;
        cnt++;
        return 1;
    }
    if (left == 0) return 0;
    for (int i = s; i < c - left + 1; i++) {
        ans[idx++] = ch[i];
        int flag = 0;
        if (ch[i] == 'a' 
            || ch[i] == 'e' 
            || ch[i] == 'i'
            || ch[i] == 'o'
            || ch[i] == 'u') {
            flag = 1;
            yuan_num++;
        } else {
            fu_num++;
        }
        if (dfs(i + 1, left - 1) == -1)  return -1;
        if (flag) yuan_num--;
        else fu_num--;
        idx--;
    }
    return 0;
}


int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }
    sort(ch, ch + c);
    dfs(0, l);
    return 0;
}
