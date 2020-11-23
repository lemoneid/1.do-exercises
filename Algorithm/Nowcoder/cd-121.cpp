/*************************************************************************
	> File Name: cd-121.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 10时23分01秒
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
#include <string>
using namespace std;
#define BASE 'a'

int mmap[30], len;
string s, ans;

int main() {
    cin >> s;
    for (int i = 0; s[i]; ++i) {
        mmap[s[i] - BASE]++;
        len++;
    }
    int id = 0, l = 0, r = 0;
    while (r < len) {
        if (mmap[s[r] - BASE] == -1 || --mmap[s[r] - BASE] > 0) {
            r++;
        } else {
            int pick = -1;
            for (int i = l; i <= r; ++i) {
                if (mmap[s[i] - BASE] != -1 && (pick == -1) || s[i] < s[pick]) {
                    pick = i;
                }
            }
            ans.push_back(s[pick]);
            for (int i = pick + 1; i <= r; ++i) {
                if (mmap[s[i - BASE]] != -1) {
                    mmap[s[i] - BASE]++;
                }
            }
            mmap[s[pick] - BASE] = -1;
            l = pick + 1;
            r = l;
        }
    }
    cout << ans << endl;
    return 0;
}
