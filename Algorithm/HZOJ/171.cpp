/*************************************************************************
> File Name: 171.cpp
> Author: wei 
> Mail: 1931248856@qq.com
> Created Time: 2020年11月04日 星期三 12时53分36秒
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

string s, ans;

int isok(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] - s[j]) return 0;
    }
    return 1;
}

int cond1(string s) {
    if (s[0] - '1') return 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] - '0') return 0;
    }
    return 1;
}

int cmp(string s1, string s2) {
    if (s1.size() - s2.size()) return s1.size() > s2.size();
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] - s2[i]) return s1[i] > s2[i];
    }
    return 1; 
}

string calc(string s) {
    int mid = (s.size() + 1) / 2 - 1;
    for (int i = 0, j = s.size() - 1; i <= mid; i++, j--) {
        s[j] = s[i];
    }
    return s;
}

void sub(string num1, string s, string num2) {
    string min_num, max_num;
    min_num = max_num = s;
    for (int i = 0; i < s.size(); ++i) {
        min_num[i] = max_num[i] = '0';
    }
    for (int i =  s.size() - 1; i >= 0; --i) {
        min_num[i] = s[i] - num2[i] + '0';
        max_num[i] = num1[i] - s[i] + '0';
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (min_num[i] < '0') {
            min_num[i] += 10;
            min_num[i - 1] -= 1;
        }
        if (max_num[i] < '0') {
            max_num[i] += 10;
            max_num[i - 1] -= 1;
        }
    }
    if (max_num < min_num) {
        cout << num2 << endl;
    } else {
        cout << num1 << endl;
    }

}

int main() {
    cin >> s;
    if (isok(s)) {
        cout << s << endl;
        return 0;
    }
    if (cond1(s)) {
        for (int i = 0; i < s.size() - 1; ++i) {
            cout << '9';
        }
        cout << endl;
        return 0;
    }
    
    int mid = (s.size() + 1) / 2 - 1;
    string num1 = calc(s);
    string num2 = s;
    int flag = cmp(num1, s);
    if (flag) {
        num2[mid] -= 1;
        for (int i = mid; i >= 0; i--) {
            if (num2[i] >= '0') break;
            num2[i - 1] -= 1;
            num2[i] += 10;
        }
        num2 = calc(num2);
    } else {
        num2[mid] += 1;
        for (int i = mid; i >= 0; i--) {
            if (num2[i] <= '9') break;
            num2[i - 1] += 1;
            num2[i] -= 10;
        }
        num2 = calc(num2);
    }
    if (flag == 1) {
        sub(num2, s, num1);
    } else {
        sub(num1, s, num2);
    }


    return 0;
}
