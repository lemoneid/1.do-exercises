/*************************************************************************
	> File Name: oj-265.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 21时06分48秒
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
    map<char, char> mmap = {{')', '('}, {']','['}, {'}', '{'}};
    stack<int> stk;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(i);
            //cout << "push <- " << s[i] << endl;
        } else {
            if (!stk.empty() && mmap[s[i]] == s[stk.top()]) {
                stk.pop();
                //cout << "pop -> " << s[i] << endl;
                int ind = stk.empty() ? -1 : stk.top();
                ans = max(ans, i - ind); 
            } else {
                stk.push(i);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
