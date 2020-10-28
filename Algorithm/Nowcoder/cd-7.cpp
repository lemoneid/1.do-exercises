/*************************************************************************
	> File Name: cd-7.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月14日 星期一 14时25分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

int getAndRemoveLastELe(stack <int>&sta) {
    int res = sta.top();
    sta.pop();
    if (sta.empty()) {
        return res;
    } else {
        int last = getAndRemoveLastELe(sta);
        sta.push(res);
        return last;
    }
}

int reverse(stack <int> &sta) {
    if (sta.empty()) return 0;
    int x = getAndRemoveLastELe(sta);
    reverse(sta);
    sta.push(x);
    return 0;
} 

int main() {
    int n, x;
    stack <int> sta;
    cin >> n;
    while (n--) {
        cin >> x;
        sta.push(x);
    }
    reverse(sta);
    int first = 0;
    while (!sta.empty()) {
        first && cout << " ";
        first = 1;
        cout << sta.top();
        sta.pop();
    }
    return 0;
}
