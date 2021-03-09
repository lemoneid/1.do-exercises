/*************************************************************************
	> File Name: oj-265.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 12时52分59秒
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
#include <stack>
using namespace std;

int main() {
    map<char, char> mmap = {{'[',']'}, {'(',')'}, {'{','}'}};
    stack<char> stk;
    int ans = 0, pre = 0;
    string str;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stk.push(str[i]);
            continue;
        }
        if (stk.empty() || mmap[stk.top()] != str[i]) {
            pre = 0;
            while (!stk.empty()) stk.pop();
            continue;
        }
        pre += 2;
        stk.pop();
        ans = max(ans, pre);
    }
    cout << ans << endl;
    return 0;
}
